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
	char * id = (char *) malloc(sizeof(char) * (strlen(node->type)+1));
	strcpy(id, node->value);

	insert_class(id, 0, 0);
	/*table_element * novo = insert_class(id);
    if(novo == NULL){
        printf("S
		ymbol already defined!");
    }*/
	free(id);
}

void check_field_decl(struct node *node) {

	char * type = (char*) malloc(sizeof(char) * (strlen(node->childs[0]->type)+1));
	strcpy(type, node->childs[0]->type);
	*type = tolower(*type);

	char * value = (char*) malloc(sizeof(char) * (strlen(node->childs[1]->value)+1));
	strcpy(value, node->childs[1]->value);

	table_element * new_symbol = insert_fielddecl(value, type, "null", node->childs[1]->line, node->childs[1]->column);

	table_element * aux = global_table;

	while(aux != NULL){
		table_element * no = search_element(new_symbol->id, aux);
		if(no != NULL){
			// Se o no existe na tabela global
			if(no->decl_type == new_symbol->decl_type)
				if (strcmp(no->id, new_symbol->id) == 0){
					new_symbol->repetido = 1;
					break;
				}
		}
		aux = aux->next;
	}

	insert_function(new_symbol, &global_table);
    /*table_element * novo = insert_vardecl(value, type, "null", symtab);
    if(novo == NULL){
        printf("Symbol already defined!");
    }*/
	free(type);
	free(value);
}

void check_func_decl(struct node * node) {
	char * return_name;

	// Entra no MethodHeader
	struct node *methodHeader = node->childs[0];

	return_name = (char *) malloc(sizeof(char) * (strlen(methodHeader->childs[0]->type)+1));
	strcpy(return_name, methodHeader->childs[0]->type);
	*return_name = tolower(*return_name);
	
	char * id_function = (char *) malloc(sizeof(char) * (strlen(methodHeader->childs[1]->value)+1));
	strcpy(id_function, methodHeader->childs[1]->value);
	//primeiro filho = tipo de return
	//printf("PETRA PETRA (%s) 	(%s)\n", return_name, id_function);

	table_element * new_symbol = create_funcdecl(id_function, return_name, methodHeader->childs[1]->line, methodHeader->childs[1]->column); //recebemos o novo no criado
	//Parametros do methodHeader e adicionar os parametros ao no
	struct node *methodParams = methodHeader->childs[2];
	for(int i = 0 ; i < methodParams->index_childs; i++){
		(new_symbol->funcdecl->n_params)++;
		(new_symbol->funcdecl->n_params_header)++;
		//FormalParams = pai; 2 filhos ( 1 type) ( 2 value(id))
		struct node *params = methodParams->childs[i];
		char * var = (char *) malloc(sizeof(char) * (strlen(params->childs[0]->type)+1));
		strcpy(var, params->childs[0]->type);
		*var = tolower(*var);
		insert_vardecl(params->childs[1]->value, var, "param", &(new_symbol->funcdecl->vars), params->childs[1]->line, params->childs[1]->column);

		free(var);
	}
 	//fazer comparacao para se ja existe
	table_element * aux = global_table;
	//int flag = 0;

	while(aux != NULL){
		table_element * no = search_element(id_function, aux);
		if(no != NULL){
			// Se o no existe na tabela global
			if (no->decl_type == new_symbol->decl_type){
				// Os nos sao do mesmo tipo (class, funcdecl,...)
				if(strcmp(no->funcdecl->type_return, new_symbol->funcdecl->type_return) == 0){
					// Os nos retornam o mesmo tipo
					if(no->funcdecl->n_params_header == new_symbol->funcdecl->n_params_header){
						// O nr de parametros do header e o mesmo
						table_element *var_no = no->funcdecl->vars;
						table_element *var_aux = new_symbol->funcdecl->vars;

						int parametros_iguais = 0;
						for (int i = 0; i < no->funcdecl->n_params_header; i++){
							if (strcmp(var_no->vardecl->type, var_aux->vardecl->type) == 0){
								parametros_iguais++;
							}
							var_no = var_no->next;
							var_aux = var_aux->next;
						}

						if (parametros_iguais == no->funcdecl->n_params_header){
							new_symbol->repetido = 1; 	// Diz que e repetido os parametros de entrada
							break;
						}
					}
				}
			}
		}
		aux = aux->next;
	}

	
	insert_function(new_symbol, &global_table);
	//printf("adicionei o %s \n", new_symbol->id);
	

	//Parametros do Body
	struct node *methodBody = node->childs[1];
	for(int i = 0 ; i < methodBody->index_childs; i++){
		if(strcmp(methodBody->childs[i]->type, "VarDecl") == 0){ 
			//VarDecl = pai, 2 filhos (type) e (value)>type, "VarDecl") == 0){
			(new_symbol->funcdecl->n_params)++;
			char * var = (char *) malloc(sizeof(char) * (strlen(methodBody->childs[i]->childs[0]->type)+1));
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

	free(id_function);
	free(return_name);
}


struct node *create_node(char *type, char* value, int line, int column){
    struct node *new = (struct node *) malloc(sizeof(node));

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
        printf("%s\n", head->type);
    }
    else{
        printf("%s(%s)\n", head->type, head->value);
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
	node->annotation = (char *) malloc(sizeof(char) * (strlen(annotation) + 1));
	strcpy(node->annotation, annotation);
	//printf("Inseri anotacao %s -- %s\n", annotation, node->annotation);
}

void create_ast(struct node *node, table_element *table, int numero){
	//printf("ENTREI AQUI %s (%d)   (%s)\n", node->type, numero, node->value);
	if(strcmp(node->type, "Add") == 0 || strcmp(node->type, "Sub") == 0 || strcmp(node->type, "Mul") == 0 || strcmp(node->type, "Div") == 0 || strcmp(node->type, "Mod") == 0){
		/*
			aqui, mandar correr o filho0, filho1(...), verificar se anotacao dos filhos e igual
			se for igual adicionar anotacao do filho ao pai
			se nao for e undef
		*/
		create_ast(node->childs[0], table, numero);
		create_ast(node->childs[1], table, numero);
		if(node->childs[0]->annotation == NULL){
			add_annotation(node, "undef");
		}
		else if(node->childs[1]->annotation == NULL){
			add_annotation(node, "undef");
		}
		else if((strcmp(node->childs[0]->annotation, "int") == 0 && strcmp(node->childs[1]->annotation, "double") == 0) || (strcmp(node->childs[0]->annotation, "double") == 0 && strcmp(node->childs[1]->annotation, "int") == 0)){
			add_annotation(node, "double");
		}
		else if((strcmp(node->childs[0]->annotation, "boolean") == 0 || strcmp(node->childs[1]->annotation, "boolean") == 0)){
			add_annotation(node, "undef");
		}
		else if(strcmp(node->childs[0]->annotation, node->childs[1]->annotation) == 0){
			add_annotation(node, node->childs[0]->annotation);
		}
		else{
			add_annotation(node, "undef");
		}
	}
	
	else if (strcmp(node->type, "Assign") == 0){
		create_ast(node->childs[0], table, numero);
		create_ast(node->childs[1], table, numero);

		if (node->childs[1]->annotation == NULL){
			add_annotation(node, node->childs[0]->annotation);
		}
		else if (node->childs[0]->annotation == NULL){
			add_annotation(node, node->childs[1]->annotation);
		}
		else if(strcmp(node->childs[0]->annotation, node->childs[1]->annotation) == 0){
			add_annotation(node, node->childs[0]->annotation);
		}
		else if(strcmp(node->childs[1]->annotation, "undef") == 0){
			add_annotation(node, node->childs[0]->annotation);
		}
		else{
			add_annotation(node, node->childs[0]->annotation);
		}
	}

	else if(strcmp(node->type, "And") == 0 || strcmp(node->type, "Or") == 0 || strcmp(node->type, "Xor") == 0 || strcmp(node->type, "Eq") == 0 || strcmp(node->type, "Ge") == 0 || strcmp(node->type, "Gt") == 0 || strcmp(node->type, "Le") == 0 || strcmp(node->type, "Lt") == 0 || strcmp(node->type, "Ne") == 0){
		// corre filho 0 e filho 1, e dizer que o pai vai ser boolean
		create_ast(node->childs[0], table, numero);
		create_ast(node->childs[1], table, numero);
		add_annotation(node, "boolean");
	}

	else if(strcmp(node->type, "Not") == 0 || strcmp(node->type, "Minus") == 0 || strcmp(node->type, "Plus") == 0){
		 //manda correr o filho e adicionar o tipo do filho
		 //printf("3\n"); 
		create_ast(node->childs[0], table,numero);
		add_annotation(node, node->childs[0]->annotation);
	}

	else if (strcmp(node->type, "ParseArgs") == 0){
		create_ast(node->childs[0], table,numero);
		create_ast(node->childs[1], table,numero);
		add_annotation(node, "int");
	}

	else if(strcmp(node->type, "Id") == 0){ //rever isto
		/*
			id - nome_funcao (X), nome_variavel
			nome_variavel -> global ou local (X)
		*/
		table_element * procura_id = NULL;
		if(table != global_table){
			procura_id = search_element(node->value, table);
		}
		if (procura_id == NULL){
			table_element *tabela_searching = global_table;
			while (1){
				table_element *procura_id_global = search_element(node->value, tabela_searching);
				if(procura_id_global == NULL){
					add_annotation(node, "undef");
					break;
				}

				int tipo = procura_id_global->decl_type;

				if (tipo == 3){
					// Tipo fielddecl
					add_annotation(node, procura_id_global->vardecl->type);
					break;
				}

				tabela_searching = procura_id_global->next;
				if(tabela_searching == NULL){
					add_annotation(node, "undef");
					break;
				}
			}
		}
		else{
			if (procura_id->line <= node->line){ // ver da historia das linhas :) 
				// Menor que a linha
				add_annotation(node, procura_id->vardecl->type);
			}

			else{
				table_element *tabela_searching = global_table;
				while (1){
					table_element *procura_id_global = search_element(node->value, tabela_searching);
					if(procura_id_global == NULL){
						add_annotation(node, "undef");
						break;
					}

					int tipo = procura_id_global->decl_type;

					if (tipo == 3){
						// Tipo fielddecl
						add_annotation(node, procura_id_global->vardecl->type);
						break;
					}		

					tabela_searching = procura_id_global->next;
					if(tabela_searching == NULL){
						add_annotation(node, "undef");
						break;
					}
				}
				// Ser maior que a linha aqui tem de dar undef
				//add_annotation(node, "undef");
			}
		}
	}

	else if(strcmp(node->type, "Return") == 0){
		if (node->index_childs != 0){
			create_ast(node->childs[0], table, numero);
		}
		else{
			return;
		}
	}

	else if(strcmp(node->type, "Length") == 0){
		create_ast(node->childs[0], table, numero);
		add_annotation(node, "int");
	}

	else if(strcmp(node->type, "DecLit") == 0 ){
		add_annotation(node, "int");
	}

	else if(strcmp(node->type, "RealLit") == 0){
		add_annotation(node, "double");
	}

	else if(strcmp(node->type, "BoolLit") == 0){
		add_annotation(node, "boolean");
	}

	else if (strcmp(node->type, "StrLit") == 0){
		add_annotation(node, "String");
	}

	else if(strcmp(node->type, "Call") == 0){
		table_element *tabela_searching = global_table;
		int flag_primeira = 0;
		for(int i = 1; i < node->index_childs; i++){
			create_ast(node->childs[i], table,numero);
		}
		while(1){ //corre todos os elementos com mesmo nome a procura da funcao com os mesmos parametros
			table_element *aux = search_element(node->childs[0]->value, tabela_searching);
			if(aux == NULL){
				/*add_annotation(node->childs[0], "undef");
				add_annotation(node, "undef");*/
				flag_primeira = 1;
				break;
			}
			else{
				if(aux->decl_type == 1){
					// E uma funcao
					if(node->index_childs - 1 == aux->funcdecl->n_params_header){
						// Se o nr de filhos - 1 (ou seja, sem o nome da funcao) = nr de parametros da funcao
						table_element * param = aux->funcdecl->vars;
						int contador = 0;
						for(int i = 1 ; i < node->index_childs; i++){
							if (strcmp(node->childs[i]->annotation, param->vardecl->type) == 0){
								contador++;
							}
							param = param->next;
						}
						if(contador == aux->funcdecl->n_params_header){
							// Verifica se todas as variaveis sao do mesmo tipo
							table_element * param2 = aux->funcdecl->vars;
							int tam = 0;
							int quantos = 0;
							table_element * aux_tamanho = aux->funcdecl->vars;
							for (int i = 0; i < aux->funcdecl->n_params; i++){
								tam += strlen(aux_tamanho->vardecl->type);
								quantos++;
							}

							char * aux_string = (char *) malloc((tam + (1 * quantos)) * sizeof(char));
							if (aux->funcdecl->n_params == 0){
								strcat(aux_string, "()");
							}
							else{
								strcat(aux_string, "(");
								for (int i = 0; i < aux->funcdecl->n_params_header; i++){
									if (i == aux->funcdecl->n_params_header - 1){
										strcat(aux_string, param2->vardecl->type);
									}
									else{
										char *meh = (char *) malloc(sizeof(char) * (strlen(param2->vardecl->type) + 1));
										
										strcat(meh, param2->vardecl->type);
										
										strcat(meh, ",");
										strcat(aux_string, meh);
										free(meh);
									}
									param2 = param2->next;
								}
								strcat(aux_string, ")");
							}
							add_annotation(node->childs[0], aux_string);
							add_annotation(node, aux->funcdecl->type_return);
							free(aux_string);
							break;
						}
					}
				}
			}
			tabela_searching = aux->next;
			if(tabela_searching == NULL){
				/*add_annotation(node->childs[0], "undef");
				add_annotation(node, "undef");*/
				flag_primeira = 1;
				break;
			}
		}//sai do primeio while
		if (flag_primeira == 1){ // Volta a correr tudo outra vez para ver se encontra alguma coisa parecida skrtt
			table_element *tabela_searching_v2 = global_table;
			
			while(1){ //corre todos os elementos com mesmo nome a procura da funcao com os mesmos parametros
				table_element *aux = search_element(node->childs[0]->value, tabela_searching_v2);
				if(aux == NULL){
					add_annotation(node->childs[0], "undef");
					add_annotation(node, "undef");
					break;
				}
				else{
					if(aux->decl_type == 1){
						// E uma funcao
						if(node->index_childs - 1 == aux->funcdecl->n_params_header){
							// Se o nr de filhos - 1 (ou seja, sem o nome da funcao) = nr de parametros da funcao
							table_element * param = aux->funcdecl->vars;
							int contador = 0;
							for(int i = 1 ; i < node->index_childs; i++){
								if (strcmp(node->childs[i]->annotation, param->vardecl->type) == 0){
									contador++;
								}
								else if (strcmp(node->childs[i]->annotation, "int") == 0 && strcmp(param->vardecl->type, "double") == 0){
									contador++;
								}
								param = param->next;
							}
							if(contador == aux->funcdecl->n_params_header){
								// Verifica se todas as variaveis sao do mesmo tipo
								table_element * param2 = aux->funcdecl->vars;
								int tam = 0;
								int quantos = 0;
								table_element * aux_tamanho = aux->funcdecl->vars;
								for (int i = 0; i < aux->funcdecl->n_params; i++){
									tam += strlen(aux_tamanho->vardecl->type);
									quantos++;
								}
								//printf("$$$$$ %d\n", (tam + (quantos - 1) + 2));
								char * aux_string = (char *) malloc(sizeof(char) * (tam  + (1*quantos)));
								if (aux->funcdecl->n_params == 0){
									strcat(aux_string, "()");
								}
								else{
									strcat(aux_string, "(");
									for (int i = 0; i < aux->funcdecl->n_params_header; i++){
										if (i == aux->funcdecl->n_params_header - 1){
											strcat(aux_string, param2->vardecl->type);
										}
										else{
											char *meh = (char *) malloc(sizeof(char) * (strlen(param2->vardecl->type) + 1));

											strcat(meh, param2->vardecl->type);
											
											strcat(meh, ",");
											strcat(aux_string, meh);
											free(meh);
										}
										param2 = param2->next;
									}
									strcat(aux_string, ")");
								}
								add_annotation(node->childs[0], aux_string);
								add_annotation(node, aux->funcdecl->type_return);
								free(aux_string);
								break;
							}
						}
					}
				}	
				tabela_searching_v2 = aux->next;
				if(tabela_searching_v2 == NULL){
					add_annotation(node->childs[0], "undef");
					add_annotation(node, "undef");
					break;
				}
			}//sai do segundo while
		}
	}

	else if(strcmp(node->type, "Lshift") == 0 || strcmp(node->type, "Rshift") == 0){
		return;
	}

	else if (strcmp(node->type, "ParamDecl") == 0){
		return;
	}

	else if (strcmp(node->type, "VarDecl") == 0){
		return;
	}
	
	else if(strcmp(node->type, "FieldDecl") == 0){
		return;
	}
	
	else if(strcmp(node->type, "MethodDecl")== 0){
		struct node *methodBody = node->childs[1];	
		table_element *no_tabela = global_table;
		for(int i = 0; i < numero; i++){
			if(no_tabela == NULL){
				break;
			}
			no_tabela = no_tabela->next;
		}
		if(no_tabela != NULL){
			if(no_tabela->repetido == 1){
				return;
			}
			if(no_tabela->funcdecl->n_params != 0){
				table_element * var_no = no_tabela->funcdecl->vars;
				create_ast(methodBody, var_no, numero);
			}
			else{
				create_ast(methodBody, global_table, numero);
			}
		}
	}

	else if(strcmp(node->type, "Program") == 0){
		//printf("[%%%%%%//1] %s\n", node->childs[2]->childs[0]->childs[1]->value);
		for(int i = 1; i < node->index_childs; i++){
			//printf("the thing goes skraaa (%d)\n", node->index_childs);
			create_ast(node->childs[i], table, i);
			//printf("MANDEI 1\n");
		}
	}

	else{
		//printf("ENTREI MAYBE HERE (%s)\n", node->type);
		for(int i = 0; i < node->index_childs; i++){
			//printf("LOOOPING %s\n",node->childs[i]->type);
			create_ast(node->childs[i], table, numero);
		}
	}
}