#include "semantics_ast.h"
//#define DEBUG

void create_symbol_table(struct node *head) {
	for (int i = 0; i < head->index_childs; i++) {
		struct node *child = head->childs[i];

		if (strcmp(child->type, "Id") == 0){
			check_class(child);
		}

		if (strcmp(child->type, "MethodDecl") == 0) {
			check_func_decl(child);
		}

		else if (strcmp(child->type, "FieldDecl") == 0) {
			check_field_decl(child);
		}
	}	
}

void check_class(struct node *node){
	char * id = (char *) malloc(strlen(node->type) * sizeof(char));
	strcpy(id, node->value);

	insert_class(id, 0, 0);
	/*table_element * novo = insert_class(id);
    if(novo == NULL){
        printf("Symbol already defined!");
    }*/
}

void check_field_decl(struct node *node) {

	char * type = (char*) malloc(strlen(node->childs[0]->type) * sizeof(char));
	strcpy(type, node->childs[0]->type);
	*type = tolower(*type);

	char * value = (char*) malloc(strlen(node->childs[1]->value) * sizeof(char));
	strcpy(value, node->childs[1]->value);

	insert_fielddecl(value, type, "null", node->childs[1]->line, node->childs[1]->column);
    /*table_element * novo = insert_vardecl(value, type, "null", symtab);
    if(novo == NULL){
        printf("Symbol already defined!");
    }*/
}

void check_func_decl(struct node * node) {
	char * return_name;

	// Entra no MethodHeader
	struct node *methodHeader = node->childs[0];

	return_name = (char *) malloc(strlen(methodHeader->childs[0]->type) * sizeof(char));
	strcpy(return_name, methodHeader->childs[0]->type);
	*return_name = tolower(*return_name);
	
	char * id_function = (char *) malloc(strlen(methodHeader->childs[1]->value) * sizeof(char));
	strcpy(id_function, methodHeader->childs[1]->value);
	//primeiro filho = tipo de return
	//printf("PETRA PETRA (%s) 	(%s)\n", return_name, id_function);

	table_element * new_symbol = create_funcdecl(id_function, return_name, methodHeader->childs[1]->line, methodHeader->childs[1]->column); //recebemos o novo no criado
	//Parametros do methodHeader e adicionar os parametros ao no
	struct node *methodParams = methodHeader->childs[2];
	for(int i = 0 ; i < methodParams->index_childs; i++){
		(new_symbol->funcdecl->n_params)++;
		//FormalParams = pai; 2 filhos ( 1 type) ( 2 value(id))
		struct node *params = methodParams->childs[i];
		char * var = (char *) malloc(strlen(params->childs[0]->type) * sizeof(char));
		strcpy(var, params->childs[0]->type);
		*var = tolower(*var);
		insert_vardecl(params->childs[1]->value, var, "param", &(new_symbol->funcdecl->vars), params->childs[1]->line, params->childs[1]->column);

		free(var);
	}
 	//fazer comparacao para se ja existe
	table_element * aux = global_table;
	int flag = 0;

	while(aux != NULL){
		table_element * no = search_element(id_function, aux);
		if(no != NULL){
			// Os nos sao do mesmo tipo
			if (no->decl_type == new_symbol->decl_type){
				// Os nos sao do mesmo tipo (class, funcdecl,...)
				if(strcmp(no->funcdecl->type_return, new_symbol->funcdecl->type_return) == 0){
					// Os nos retornam o mesmo tipo
					if(no->funcdecl->n_params == new_symbol->funcdecl->n_params){
						// O nr de parametros e o mesmo
						table_element *var_no = no->funcdecl->vars;
						table_element *var_aux = new_symbol->funcdecl->vars;

						int parametros_iguais = 0;
						for (int i = 0; i < no->funcdecl->n_params; i++){
							if (strcmp(var_no->vardecl->type, var_aux->vardecl->type) == 0){
								parametros_iguais++;
							}
							var_no = var_no->next;
							var_aux = var_aux->next;
						}

						if (parametros_iguais == no->funcdecl->n_params){
							// NAO TEMOS AQUI UM ERRO EHEHEH XD
							flag = 1;
							break;
						}
					}
				}
			}
		}
		aux = aux->next;
	}


	if(flag == 0){
		insert_function(new_symbol, &global_table);
		//printf("adicionei o %s \n", new_symbol->id);
	}

	//Parametros do Body
	struct node *methodBody = node->childs[1];
	for(int i = 0 ; i < methodBody->index_childs; i++){
		if(strcmp(methodBody->childs[i]->type, "VarDecl") == 0){ 
			//VarDecl = pai, 2 filhos (type) e (value)>type, "VarDecl") == 0){
			(new_symbol->funcdecl->n_params)++;
			char * var = (char *) malloc(strlen(methodBody->childs[i]->childs[0]->type) * sizeof(char));
			strcpy(var, methodBody->childs[i]->childs[0]->type);
			*var = tolower(*var);

			insert_vardecl(methodBody->childs[i]->childs[1]->value, var, "null", &(new_symbol->funcdecl->vars), methodBody->childs[i]->childs[1]->line, methodBody->childs[i]->childs[1]->column);
			free(var);
		}
		else if (strcmp(methodBody->childs[i]->type, "Call")==0){
			continue;
		}
		else if (strcmp(methodBody->childs[i]->type, "If")==0){
			continue;
		}else if (strcmp(methodBody->childs[i]->type, "While")==0){
			continue;
		}else if (strcmp(methodBody->childs[i]->type, "Block")==0){
			continue;
		}
	}
	//printf("CHEGUEI AQUI\n");
}


struct node *create_node(char *type, char* value, int line, int column){
    struct node *new = (struct node *) malloc(sizeof( node));

    if (new == NULL){
        return NULL;
    }
    new->type = type;
    new->value = value;
    new->index_childs = 0;
    new->dad = NULL;
    new->bros = NULL;
	new->line = line;
	new->column = column;
    return new;
}

struct node *add_child(struct node *dad, struct node *child){
    // Verifica se algum dos struct nodes fornecidos esta a NULL ou nao
    if (dad == NULL || child == NULL){
        return NULL;
    }

    // Faz a associacao entre o pai e o filho recebido
    dad->childs[dad->index_childs] = child;
    dad->index_childs++;
    child->dad = dad;

    struct node *aux = child->bros;

    // Percorre os irmaos e diz que tem novo pai
    while (aux != NULL){
        aux->dad = dad;
        dad->childs[dad->index_childs] = aux;
        dad->index_childs++;
        aux = aux->bros;
    }

    return dad;
}

struct node *add_bro(struct node * s1, struct node * s2){
	struct node *aux = s1;

	if (aux != NULL) {
		while (aux->bros != NULL) {
			aux = aux->bros;
		}
		aux->bros = s2;
	}
	return s1;
}

void print_tree(struct node *head, int depth){
    if (head == NULL){
        return;
    }

    for (int i = 0; i < depth; i++){
        printf("..");
    }

    if (strcmp(head->value, "") == 0){
        //printf("%s\n", head->type);
		printf("%s -------------------- Line %d  -  Column %d\n", head->type, head->line, head->column);
    }
    else{
        //printf("%s(%s)\n", head->type, head->value);
		printf("%s(%s) -------------------- Line %d  -  Column %d\n", head->type, head->value, head->line, head->column);
    }

    for (int j = 0; j < head->index_childs; j++){
        print_tree(head->childs[j], depth + 1);
    }

    free(head);
}

void print_tree_annotated(struct node *head, int depth){
    if (head == NULL){
        return;
    }

    for (int i = 0; i < depth; i++){
        printf("..");
    }

    if (strcmp(head->value, "") == 0){
		if (head->annotation != NULL){
        	printf("%s - %s\n", head->type, head->annotation);
		}
		else{
        	printf("%s\n", head->type);
		}
    }
    else{
		if (head->annotation != NULL){
        	printf("%s(%s) - %s\n", head->type, head->value, head->annotation);
		}
		else{
        	printf("%s(%s)\n", head->type, head->value);
		}
    }

    for (int j = 0; j < head->index_childs; j++){
        print_tree_annotated(head->childs[j], depth + 1);
    }

    free(head);
}

void add_annotation(struct node *node, char *annotation){
	node->annotation = (char *) malloc(sizeof(char) * strlen(annotation));
	strcpy(node->annotation, annotation);
	//printf("Inseri anotacao %s -- %s\n", node->type, node->annotation);
}

void create_ast(struct node *node, table_element *table){
	//printf("ENTREI AQUI %s   %s\n",node->type, node->value);
	if(strcmp(node->type, "Add") == 0 || strcmp(node->type, "Sub") == 0 || strcmp(node->type, "Mul") == 0 || strcmp(node->type, "Div") == 0 || strcmp(node->type, "Mod") == 0){
		/*
			aqui, mandar correr o filho0, filho1(...), verificar se anotacao dos filhos e igual
			se for igual adicionar anotacao do filho ao pai
			se nao for e undef
		*/
		create_ast(node->childs[0], table);
		create_ast(node->childs[1], table);

		if(strcmp(node->childs[0]->annotation, node->childs[1]->annotation) == 0){
			add_annotation(node, node->childs[0]->annotation);
		}
		else{
			add_annotation(node, "undef");
		}
	}
	else if (strcmp(node->type, "Assign") == 0){
		create_ast(node->childs[0], table);
		create_ast(node->childs[1], table);

		if(strcmp(node->childs[0]->annotation, node->childs[1]->annotation) == 0){
			add_annotation(node, node->childs[0]->annotation);
		}
		else if(strcmp(node->childs[1]->annotation, "undef") == 0){
			add_annotation(node, node->childs[0]->annotation);
		}
		else{
			add_annotation(node, "undef");
		}
	}

	else if(strcmp(node->type, "And") == 0 || strcmp(node->type, "Or") == 0 || strcmp(node->type, "Xor") == 0 || strcmp(node->type, "Eq") == 0 || strcmp(node->type, "Ge") == 0 || strcmp(node->type, "Gt") == 0 || strcmp(node->type, "Le") == 0 || strcmp(node->type, "Lt") == 0 || strcmp(node->type, "Ne") == 0){
		// corre filho 0 e filho 1, e dizer que o pai vai ser boolean
		//printf("2\n");
		create_ast(node->childs[0], table);
		create_ast(node->childs[1], table);
		add_annotation(node, "boolean");
	}

	else if(strcmp(node->type, "Not") == 0 || strcmp(node->type, "Minus") == 0 || strcmp(node->type, "Plus") == 0){
		 //manda correr o filho e adicionar o tipo do filho
		 //printf("3\n"); 
		create_ast(node->childs[0], table);
		add_annotation(node, node->childs[0]->annotation);
	}

	else if (strcmp(node->type, "ParseArgs") == 0){
		create_ast(node->childs[0], table);
		create_ast(node->childs[1], table);
		add_annotation(node, "int");
	}

	else if(strcmp(node->type, "Id") == 0){
		/*
			se o id for uma funcao, meter "(tipo)""
			se nao, meter "tipo"
			se a funcao nao existir, meter "undef"
		*/
		table_element * procura_id = search_element(node->value, table);
		if (procura_id == NULL){
			table_element *procura_id_global = search_element(node->value, global_table);
			if (procura_id_global != NULL){
				int tipo = procura_id_global->decl_type;
				if (tipo == 1){
					// Tipo func;
					char * aux = (char *) malloc((strlen(procura_id_global->funcdecl->type_return) + 2) * sizeof(char));
					strcat(aux, "(");
					strcat(aux, procura_id_global->funcdecl->type_return);
					strcat(aux, ")");
					add_annotation(node, aux);
				}
				else if (tipo == 3){
					// Tipo fielddecl
					add_annotation(node, procura_id_global->vardecl->type);
				}
			}
			else{
				// else - ERRO
				add_annotation(node, "undef");
			}
		}
		else{
			if (procura_id->line <= node->line){ // ver da historia das linhas :) 
				// Menor que a linha
				add_annotation(node, procura_id->vardecl->type);
			}

			else{
				// Ser maior que a linha aqui tem de dar undef
				add_annotation(node, "undef");
			}
			//add_annotation(node, "undef");
		}
	}

	else if(strcmp(node->type, "DecLit") == 0 || strcmp(node->type, "Length") == 0 || strcmp(node->type, "ParseArgs") == 0){
		add_annotation(node, "int");
	}

	else if(strcmp(node->type, "RealLit") == 0){
		add_annotation(node, "double");
	}

	else if(strcmp(node->type, "BoolLit") == 0){
		add_annotation(node, "boolean");
	}

	else if(strcmp(node->type, "Call") == 0){
		//printf("SOU A FUNCAO %s e FILHOS %d\n", node->childs[0]->value,node->index_childs);
		table_element *procura_id = search_element(node->childs[0]->value, global_table);
		if(procura_id != NULL) {
			table_element *auxiliar_id = procura_id;
			while(auxiliar_id != NULL){
				if (auxiliar_id->decl_type == 1){
					// Tipo func
					table_element * param = auxiliar_id->funcdecl->vars;
					int contador = 0;
					if(node->index_childs - 1 == auxiliar_id->funcdecl->n_params){
						for (int i = 1; i < node->index_childs; i++){
							create_ast(node->childs[i], table);
							if (strcmp(node->childs[i]->annotation, param->vardecl->type) == 0){
								contador++;
							}
							param = param->next;
						}
						//printf("entrei contador %d e funcao encontrada tem %d\n", contador, auxiliar_id->funcdecl->n_params);
						if(contador == auxiliar_id->funcdecl->n_params){
							//criamos anotacao para o id aqui tambem
							table_element * param2 = auxiliar_id->funcdecl->vars;
							char * aux = (char *) malloc(256 * sizeof(char));
							//printf("[BACALHAU] %s\n", auxiliar_id->funcdecl->type_return);
							if (auxiliar_id->funcdecl->n_params == 0){
								strcat(aux, "()");
							}
							else{
								strcat(aux, "(");
								for (int i = 0; i < auxiliar_id->funcdecl->n_params; i++){
									if (i == auxiliar_id->funcdecl->n_params - 1){
										strcat(aux, param2->vardecl->type);
									}
									else{
										char *meh = (char *) malloc(sizeof(char) * (strlen(param2->vardecl->type) + 1));
										
										strcat(meh, param2->vardecl->type);
										
										strcat(meh, ",");
										strcat(aux, meh);
										free(meh);
										//free(meh);
									}
									param2 = param2->next;
								}
								strcat(aux, ")");
							}
							add_annotation(node->childs[0], aux);
							add_annotation(node, auxiliar_id->funcdecl->type_return);
							free(aux);
							break;
						}
					}
					auxiliar_id = auxiliar_id->next;
					if(auxiliar_id == NULL){
						add_annotation(node->childs[0], "undef");
						add_annotation(node, "undef");
					}else{
						auxiliar_id = search_element(node->childs[0]->value, auxiliar_id);
					}
				}
				else{
					auxiliar_id = auxiliar_id->next;
					if(auxiliar_id == NULL){
						add_annotation(node->childs[0], "undef");
						add_annotation(node, "undef");
					}else{
						auxiliar_id = search_element(node->childs[0]->value, auxiliar_id);
					}
				}
			}
		}
		else{
			add_annotation(node->childs[0], "undef");
			add_annotation(node, "undef");
		}
	}

	/*else if(strcmp(node->type, "Lshift") == 0){

	}
	else if(strcmp(node->type, "Rshift") == 0){
			temos de ver com cuidado quais os sitios onde temos o loop mas nao estamos a por
	}*/
	else if (strcmp(node->type, "ParamDecl") == 0){
		return;
	}

	else if (strcmp(node->type, "VarDecl") == 0){
		return;
	}

	else if(strcmp(node->type, "MethodDecl")== 0){
		struct node * methodHeader = node->childs[0];
		struct node * methodBody = node->childs[1];
		table_element * no_tabela = search_element(methodHeader->childs[1]->value, global_table);
		//printf("YEAH ENTREI %s \n", methodHeader->childs[1]->value);
		if(no_tabela != NULL){
			table_element * vars_no = no_tabela->funcdecl->vars;
			create_ast(methodBody, vars_no);
		}
	}
	else if(strcmp(node->type, "Program") == 0){
		for(int i = 1; i < node->index_childs; i++){
			create_ast(node->childs[i], table);
		}
	}

	else{
		for(int i = 0; i < node->index_childs; i++){
			//printf("LOOOPING %s\n",node->childs[i]->type);
			create_ast(node->childs[i], table);
		}
	}
}