#include "semantics_ast.h"

// Percorre elementos da arvore e chama a respetiva funcao de insercao na tabela de simbolos para criar a arvore anotada
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

// Insere na tabela de simbolos a class
void check_class(struct node *node){
	char * id = (char *) malloc(sizeof(char) * (strlen(node->type)+1));
	strcpy(id, node->value);

	insert_class(id, 0, 0);
	free(id);
}
//Insere na tabela de simbolos a variavel global da class
void check_field_decl(struct node *node) {

	char * type = (char*) malloc(sizeof(char) * (strlen(node->childs[0]->type)+1));
	strcpy(type, node->childs[0]->type);
	*type = tolower(*type);

	char * value = (char*) malloc(sizeof(char) * (strlen(node->childs[1]->value)+1));
	strcpy(value, node->childs[1]->value);

	table_element * new_symbol = insert_fielddecl(value, type, "null", node->childs[1]->line, node->childs[1]->column);

	table_element * aux = global_table;
	//verificar se ja existe uma variavel global com o mesmo nome
	while(aux != NULL){
		table_element * no = search_element(new_symbol->id, aux);
		if(no != NULL){
			// Se o no existe na tabela global, indicar que e repetido , de modo a evitar da print da varavel
			if(no->decl_type == new_symbol->decl_type) {
				if(strcmp(no->id, new_symbol->id) == 0){
					/*if(strcmp(new_symbol->id, "_") == 0){
						new_symbol->repetido = 1;
						printf("Line %d, col %d: Symbol %s is reserved\n",node->childs[1]->line, node->childs[1]->column, node->childs[1]->value);
						break;
					}*/
					new_symbol->repetido = 1;
					//printf("Line %d, col %d: Symbol %s already defined\n",node->childs[1]->line, node->childs[1]->column, node->childs[1]->value);
					break;
				}
			}
		}
		aux = aux->next;
	}

	if(strcmp(new_symbol->id, "_") == 0 && new_symbol->repetido == 0){
		new_symbol->repetido = 1;
		//printf("Line %d, col %d: Symbol %s is reserved\n",new_symbol->line, new_symbol->column, new_symbol->id);
	}
	insert_function(new_symbol, &global_table);
	free(type);
	free(value);
}
//Insere na tabela de simbolos a funcao
void check_func_decl(struct node * node) {
	char * return_name;

	// Entra no MethodHeader
	struct node *methodHeader = node->childs[0];

	return_name = (char *) malloc(sizeof(char) * (strlen(methodHeader->childs[0]->type)+1));
	strcpy(return_name, methodHeader->childs[0]->type);
	*return_name = tolower(*return_name);
	
	char * id_function = (char *) malloc(sizeof(char) * (strlen(methodHeader->childs[1]->value)+1));
	strcpy(id_function, methodHeader->childs[1]->value);
	//cria no da funcao
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
 	//Verificar se ja existe uma variavel funcao com o mesmo nome, mesmo tipo, e mesmos parametros
	table_element * aux = global_table;

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
							new_symbol->repetido = 1; 	// Diz que e repetido os parametros de entrada, e assim evitar dar print
							break;
						}
					}
				}
			}
			if(no->decl_type == 3){
				if(strcmp(new_symbol->id, no->id) == 0){
					if(strcmp(new_symbol->id, "_") == 0){
						new_symbol->repetido = 1;
						/*printf("Line %d, col %d: Symbol %s(",new_symbol->line, new_symbol->column, new_symbol->id);
						table_element *var_aux = new_symbol->funcdecl->vars;
						for(int i = 0 ; i < new_symbol->funcdecl->n_params_header; i++){
							printf("%s", var_aux->vardecl->type);
							if(i == new_symbol->funcdecl->n_params_header - 1){
								printf(",");
							}
							var_aux = var_aux->next;
						}
						printf(") already defined\n");*/
						break;
					}	
				}	
			}
		}
		aux = aux->next;
	}
	
	insert_function(new_symbol, &global_table);	

	//Adiciona os parametros do Body
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

// Cria o no da arvore normal
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
	new->annotation = NULL;
    return new;
}

// Adiciona um filho ao no pai
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

// Adiciona um irmao
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

// Imprime a arvore normal
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

// Imprime a arvore anotada
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
			free(head->annotation);
		}
		else{
        	printf("%s\n", head->type);
		}
    }
    else{
		if (head->annotation != NULL){
        	printf("%s(%s) - %s\n", head->type, head->value, head->annotation);
			free(head->annotation);
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

// Adiciona uma anotacao ao elemento
void add_annotation(struct node *node, char *annotation){
	node->annotation = (char *) malloc(sizeof(char) * strlen(annotation) + 1);
	node->annotation = strdup(annotation);
}

int global_return = 0;
// Cria a arvore anotada
void create_ast(struct node *node, table_element *table, int numero){
	if(strcmp(node->type, "Add") == 0){
		// Add, Sub, Mul, Div, Mod
		create_ast(node->childs[0], table, numero);
		create_ast(node->childs[1], table, numero);

		if(node->childs[0]->annotation == NULL){
			// Se a parte da esquerda da igualdade for NULL
			printf("Line %d, col %d: Operator + cannot be applied to types none, %s\n", node->line, node->column, node->childs[1]->annotation);
			add_annotation(node, "undef");
		}
		else if(node->childs[1]->annotation == NULL){
			// Se a parte da direita da igualdade for NULL
			printf("Line %d, col %d: Operator + cannot be applied to types %s, none\n", node->line, node->column, node->childs[0]->annotation);
			add_annotation(node, "undef");
		}
		else if((strcmp(node->childs[0]->annotation, "int") == 0 && strcmp(node->childs[1]->annotation, "double") == 0) || (strcmp(node->childs[0]->annotation, "double") == 0 && strcmp(node->childs[1]->annotation, "int") == 0)){
			// Se for "int" / "double" ou "double" / "int"
			add_annotation(node, "double");
		}
		else if((strcmp(node->childs[0]->annotation, "boolean") == 0 || strcmp(node->childs[1]->annotation, "boolean") == 0)){
			// Se forem os 2 "boolean"
			printf("Line %d, col %d: Operator + cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			add_annotation(node, "undef");
		}
		else if((strcmp(node->childs[0]->annotation, "undef") == 0 || strcmp(node->childs[1]->annotation, "undef") == 0)){
			// Se forem os 2 "undef"
			printf("Line %d, col %d: Operator + cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			add_annotation(node, "undef");
		}
		else if(strcmp(node->childs[0]->annotation, node->childs[1]->annotation) == 0){
			// Se forem os 2 iguais (exceto o caso anterior)
			add_annotation(node, node->childs[0]->annotation);
		}
		else{
			printf("Line %d, col %d: Operator + cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			add_annotation(node, "undef");
		}
	}

	else if(strcmp(node->type, "Sub") == 0){
		// Add, Sub, Mul, Div, Mod
		create_ast(node->childs[0], table, numero);
		create_ast(node->childs[1], table, numero);

		if(node->childs[0]->annotation == NULL){
			// Se a parte da esquerda da igualdade for NULL
			printf("Line %d, col %d: Operator - cannot be applied to types none, %s\n", node->line, node->column, node->childs[1]->annotation);
			add_annotation(node, "undef");
		}
		else if(node->childs[1]->annotation == NULL){
			// Se a parte da direita da igualdade for NULL
			printf("Line %d, col %d: Operator - cannot be applied to types %s, none\n", node->line, node->column, node->childs[0]->annotation);
			add_annotation(node, "undef");
		}
		else if((strcmp(node->childs[0]->annotation, "int") == 0 && strcmp(node->childs[1]->annotation, "double") == 0) || (strcmp(node->childs[0]->annotation, "double") == 0 && strcmp(node->childs[1]->annotation, "int") == 0)){
			// Se for "int" / "double" ou "double" / "int"
			add_annotation(node, "double");
		}
		else if((strcmp(node->childs[0]->annotation, "boolean") == 0 || strcmp(node->childs[1]->annotation, "boolean") == 0)){
			// Se forem os 2 "boolean"
			printf("Line %d, col %d: Operator - cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			add_annotation(node, "undef");
		}
		else if((strcmp(node->childs[0]->annotation, "undef") == 0 || strcmp(node->childs[1]->annotation, "undef") == 0)){
			// Se forem os 2 "undef"
			printf("Line %d, col %d: Operator - cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			add_annotation(node, "undef");
		}
		else if(strcmp(node->childs[0]->annotation, node->childs[1]->annotation) == 0){
			// Se forem os 2 iguais (exceto o caso anterior)
			add_annotation(node, node->childs[0]->annotation);
		}
		else{
			printf("Line %d, col %d: Operator - cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			add_annotation(node, "undef");
		}
	}

	else if(strcmp(node->type, "Mul") == 0){
		// Add, Sub, Mul, Div, Mod
		create_ast(node->childs[0], table, numero);
		create_ast(node->childs[1], table, numero);

		if(node->childs[0]->annotation == NULL){
			// Se a parte da esquerda da igualdade for NULL
			printf("Line %d, col %d: Operator * cannot be applied to types none, %s\n", node->line, node->column, node->childs[1]->annotation);
			add_annotation(node, "undef");
		}
		else if(node->childs[1]->annotation == NULL){
			// Se a parte da direita da igualdade for NULL
			printf("Line %d, col %d: Operator * cannot be applied to types %s, none\n", node->line, node->column, node->childs[0]->annotation);
			add_annotation(node, "undef");
		}
		else if((strcmp(node->childs[0]->annotation, "int") == 0 && strcmp(node->childs[1]->annotation, "double") == 0) || (strcmp(node->childs[0]->annotation, "double") == 0 && strcmp(node->childs[1]->annotation, "int") == 0)){
			// Se for "int" / "double" ou "double" / "int"
			add_annotation(node, "double");
		}
		else if((strcmp(node->childs[0]->annotation, "boolean") == 0 || strcmp(node->childs[1]->annotation, "boolean") == 0)){
			// Se forem os 2 "boolean"
			printf("Line %d, col %d: Operator * cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			add_annotation(node, "undef");
		}
		else if((strcmp(node->childs[0]->annotation, "undef") == 0 || strcmp(node->childs[1]->annotation, "undef") == 0)){
			// Se forem os 2 "undef"
			printf("Line %d, col %d: Operator * cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			add_annotation(node, "undef");
		}
		else if(strcmp(node->childs[0]->annotation, node->childs[1]->annotation) == 0){
			// Se forem os 2 iguais (exceto o caso anterior)
			add_annotation(node, node->childs[0]->annotation);
		}
		else{
			printf("Line %d, col %d: Operator * cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			add_annotation(node, "undef");
		}
	}

	else if(strcmp(node->type, "Div") == 0){
		// Add, Sub, Mul, Div, Mod
		create_ast(node->childs[0], table, numero);
		create_ast(node->childs[1], table, numero);

		if(node->childs[0]->annotation == NULL){
			// Se a parte da esquerda da igualdade for NULL
			printf("Line %d, col %d: Operator / cannot be applied to types none, %s\n", node->line, node->column, node->childs[1]->annotation);
			add_annotation(node, "undef");
		}
		else if(node->childs[1]->annotation == NULL){
			// Se a parte da direita da igualdade for NULL
			printf("Line %d, col %d: Operator / cannot be applied to types %s, none\n", node->line, node->column, node->childs[0]->annotation);
			add_annotation(node, "undef");
		}
		else if((strcmp(node->childs[0]->annotation, "int") == 0 && strcmp(node->childs[1]->annotation, "double") == 0) || (strcmp(node->childs[0]->annotation, "double") == 0 && strcmp(node->childs[1]->annotation, "int") == 0)){
			// Se for "int" / "double" ou "double" / "int"
			add_annotation(node, "double");
		}
		else if((strcmp(node->childs[0]->annotation, "boolean") == 0 || strcmp(node->childs[1]->annotation, "boolean") == 0)){
			// Se forem os 2 "boolean"
			printf("Line %d, col %d: Operator / cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			add_annotation(node, "undef");
		}
		else if((strcmp(node->childs[0]->annotation, "undef") == 0 || strcmp(node->childs[1]->annotation, "undef") == 0)){
			// Se forem os 2 "undef"
			printf("Line %d, col %d: Operator / cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			add_annotation(node, "undef");
		}
		else if(strcmp(node->childs[0]->annotation, node->childs[1]->annotation) == 0){
			// Se forem os 2 iguais (exceto o caso anterior)
			add_annotation(node, node->childs[0]->annotation);
		}
		else{
			printf("Line %d, col %d: Operator / cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			add_annotation(node, "undef");
		}
	}

	else if(strcmp(node->type, "Mod") == 0){
		// Add, Sub, Mul, Div, Mod
		create_ast(node->childs[0], table, numero);
		create_ast(node->childs[1], table, numero);

		if(node->childs[0]->annotation == NULL){
			// Se a parte da esquerda da igualdade for NULL
			printf("Line %d, col %d: Operator %% cannot be applied to types none, %s\n", node->line, node->column, node->childs[1]->annotation);
			add_annotation(node, "undef");
		}
		else if(node->childs[1]->annotation == NULL){
			// Se a parte da direita da igualdade for NULL
			printf("Line %d, col %d: Operator %% cannot be applied to types %s, none\n", node->line, node->column, node->childs[0]->annotation);
			add_annotation(node, "undef");
		}
		else if((strcmp(node->childs[0]->annotation, "int") == 0 && strcmp(node->childs[1]->annotation, "double") == 0) || (strcmp(node->childs[0]->annotation, "double") == 0 && strcmp(node->childs[1]->annotation, "int") == 0)){
			// Se for "int" / "double" ou "double" / "int"
			add_annotation(node, "double");
		}
		else if((strcmp(node->childs[0]->annotation, "boolean") == 0 || strcmp(node->childs[1]->annotation, "boolean") == 0)){
			// Se forem os 2 "boolean"
			printf("Line %d, col %d: Operator %% cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			add_annotation(node, "undef");
		}
		else if((strcmp(node->childs[0]->annotation, "undef") == 0 || strcmp(node->childs[1]->annotation, "undef") == 0)){
			// Se forem os 2 "undef"
			printf("Line %d, col %d: Operator %% cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			add_annotation(node, "undef");
		}
		else if(strcmp(node->childs[0]->annotation, node->childs[1]->annotation) == 0){
			// Se forem os 2 iguais (exceto o caso anterior)
			add_annotation(node, node->childs[0]->annotation);
		}
		else{
			printf("Line %d, col %d: Operator %% cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			add_annotation(node, "undef");
		}
	}
	
	else if (strcmp(node->type, "Assign") == 0){
		create_ast(node->childs[0], table, numero);
		create_ast(node->childs[1], table, numero);

		if (node->childs[1]->annotation == NULL){
			// Se a parte da direita da igualdade for NULL
			printf("Line %d, col %d: Operator = cannot be applied to types %s, none\n", node->line, node->column, node->childs[0]->annotation);
			add_annotation(node, node->childs[0]->annotation);
		}
		else if (node->childs[0]->annotation == NULL){
			// Se a parte da esquerda da igualdade for NULL
			printf("Line %d, col %d: Operator = cannot be applied to types none, %s\n", node->line, node->column, node->childs[1]->annotation);
			add_annotation(node, node->childs[1]->annotation);
		}
		else if(strcmp(node->childs[0]->annotation, node->childs[1]->annotation) == 0){
			// Se a parte da esquerda e direita da igualdade forem iguais
			add_annotation(node, node->childs[0]->annotation);
		}
		else if(strcmp(node->childs[1]->annotation, "undef") == 0){
			// Se a parte da direita da igualdade for "undef"
			printf("Line %d, col %d: Operator = cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			add_annotation(node, node->childs[0]->annotation);
		}
		else if(strcmp(node->childs[0]->annotation, "double") == 0 && strcmp(node->childs[1]->annotation, "int") == 0){
			add_annotation(node, "double");
		}
		else if(strcmp(node->childs[0]->annotation, node->childs[1]->annotation) != 0){
			printf("Line %d, col %d: Operator = cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			add_annotation(node, "undef");
		}
		else{
			add_annotation(node, node->childs[0]->annotation);
		}
	}

	else if(strcmp(node->type, "And") == 0 || strcmp(node->type, "Or") == 0 || strcmp(node->type, "Xor") == 0 || strcmp(node->type, "Eq") == 0 || strcmp(node->type, "Ge") == 0 || strcmp(node->type, "Gt") == 0 || strcmp(node->type, "Le") == 0 || strcmp(node->type, "Lt") == 0 || strcmp(node->type, "Ne") == 0){
		// And, Or, Xor, Eq, Ge, Gt, Le, Lt, Ne
		create_ast(node->childs[0], table, numero);
		create_ast(node->childs[1], table, numero);

		if (node->childs[0]->annotation == NULL){
			if (strcmp(node->type, "And") == 0){
				printf("Line %d, col %d: Operator && cannot be applied to types none, %s\n", node->line, node->column, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Or") == 0){
				printf("Line %d, col %d: Operator || cannot be applied to types none, %s\n", node->line, node->column, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Xor") == 0){
				printf("Line %d, col %d: Operator ^ cannot be applied to types none, %s\n", node->line, node->column, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Eq") == 0){
				printf("Line %d, col %d: Operator == cannot be applied to types none, %s\n", node->line, node->column, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Ge") == 0){
				printf("Line %d, col %d: Operator >= cannot be applied to types none, %s\n", node->line, node->column, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Gt") == 0){
				printf("Line %d, col %d: Operator > cannot be applied to types none, %s\n", node->line, node->column, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Le") == 0){
				printf("Line %d, col %d: Operator <= cannot be applied to types none, %s\n", node->line, node->column, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Lt") == 0){
				printf("Line %d, col %d: Operator < cannot be applied to types none, %s\n", node->line, node->column, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Ne") == 0){
				printf("Line %d, col %d: Operator != cannot be applied to types none, %s\n", node->line, node->column, node->childs[1]->annotation);
			}
		}
		else if (node->childs[1]->annotation == NULL){
			if (strcmp(node->type, "And") == 0){
				printf("Line %d, col %d: Operator && cannot be applied to types %s, none\n", node->line, node->column, node->childs[0]->annotation);
			}
			else if (strcmp(node->type, "Or") == 0){
				printf("Line %d, col %d: Operator || cannot be applied to types %s, none\n", node->line, node->column, node->childs[0]->annotation);
			}
			else if (strcmp(node->type, "Xor") == 0){
				printf("Line %d, col %d: Operator ^ cannot be applied to types %s, none\n", node->line, node->column, node->childs[0]->annotation);
			}
			else if (strcmp(node->type, "Eq") == 0){
				printf("Line %d, col %d: Operator == cannot be applied to types %s, none\n", node->line, node->column, node->childs[0]->annotation);
			}
			else if (strcmp(node->type, "Ge") == 0){
				printf("Line %d, col %d: Operator >= cannot be applied to types %s, none\n", node->line, node->column, node->childs[0]->annotation);
			}
			else if (strcmp(node->type, "Gt") == 0){
				printf("Line %d, col %d: Operator > cannot be applied to types %s, none\n", node->line, node->column, node->childs[0]->annotation);
			}
			else if (strcmp(node->type, "Le") == 0){
				printf("Line %d, col %d: Operator <= cannot be applied to types %s, none\n", node->line, node->column, node->childs[0]->annotation);
			}
			else if (strcmp(node->type, "Lt") == 0){
				printf("Line %d, col %d: Operator < cannot be applied to types %s, none\n", node->line, node->column, node->childs[0]->annotation);
			}
			else if (strcmp(node->type, "Ne") == 0){
				printf("Line %d, col %d: Operator != cannot be applied to types %s, none\n", node->line, node->column, node->childs[0]->annotation);
			}
		}
		else if (strcmp(node->childs[0]->annotation, "undef") == 0){
			if (strcmp(node->type, "And") == 0){
				printf("Line %d, col %d: Operator && cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Or") == 0){
				printf("Line %d, col %d: Operator || cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Xor") == 0){
				printf("Line %d, col %d: Operator ^ cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Eq") == 0){
				printf("Line %d, col %d: Operator == cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Ge") == 0){
				printf("Line %d, col %d: Operator >= cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Gt") == 0){
				printf("Line %d, col %d: Operator > cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Le") == 0){
				printf("Line %d, col %d: Operator <= cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Lt") == 0){
				printf("Line %d, col %d: Operator < cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Ne") == 0){
				printf("Line %d, col %d: Operator != cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			}
		}
		else if (strcmp(node->childs[1]->annotation, "undef") == 0){
			if (strcmp(node->type, "And") == 0){
				printf("Line %d, col %d: Operator && cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Or") == 0){
				printf("Line %d, col %d: Operator || cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Xor") == 0){
				printf("Line %d, col %d: Operator ^ cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Eq") == 0){
				printf("Line %d, col %d: Operator == cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Ge") == 0){
				printf("Line %d, col %d: Operator >= cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Gt") == 0){
				printf("Line %d, col %d: Operator > cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Le") == 0){
				printf("Line %d, col %d: Operator <= cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Lt") == 0){
				printf("Line %d, col %d: Operator < cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			}
			else if (strcmp(node->type, "Ne") == 0){
				printf("Line %d, col %d: Operator != cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
			}
		}
		
		add_annotation(node, "boolean");
	}

	else if(strcmp(node->type, "Not") == 0){
		create_ast(node->childs[0], table,numero);
		if (strcmp(node->childs[0]->annotation, "boolean") == 0){
			add_annotation(node, node->childs[0]->annotation);
		}
		else{
			printf("Line %d, col %d: Operator ! cannot be applied to type %s\n", node->line, node->column, node->childs[0]->annotation);
			add_annotation(node, "undef");
		}
	}

	else if(strcmp(node->type, "Minus") == 0 || strcmp(node->type, "Plus") == 0){
		create_ast(node->childs[0], table,numero);
		if (strcmp(node->childs[0]->annotation, "boolean") == 0){
			if (strcmp(node->type, "Minus") == 0){
				printf("Line %d, col %d: Operator - cannot be applied to type %s\n", node->line, node->column, node->childs[0]->annotation);
			}
			else if (strcmp(node->type, "Plus") == 0){
				printf("Line %d, col %d: Operator + cannot be applied to type %s\n", node->line, node->column, node->childs[0]->annotation);
			}
			add_annotation(node, "undef");
		}
		else{
			add_annotation(node, node->childs[0]->annotation);
		}
	}

	else if (strcmp(node->type, "ParseArgs") == 0){
		//manda correr os filhos, e adiciona anotacao int
		create_ast(node->childs[0], table, numero);
		create_ast(node->childs[1], table, numero);
		if (strcmp(node->childs[0]->annotation, "String[]") != 0 || strcmp(node->childs[1]->annotation, "int") != 0){
			printf("Line %d, col %d: Operator Integer.parseInt cannot be applied to types %s, %s\n", node->line, node->column, node->childs[0]->annotation, node->childs[1]->annotation);
		}
		add_annotation(node, "int");
	}

	else if(strcmp(node->type, "Id") == 0){
		/*
			id - nome_funcao (X), nome_variavel
			nome_variavel -> global ou local (X)
		*/
		table_element * procura_id = NULL;
		if(table != global_table){
			procura_id = search_element(node->value, table);
		}
		if (procura_id == NULL){
			//no caso da tabela recebida ser a tabela global, procurar se existe um parametros global com o mesmo id e adicionar o tipo, caso contrario e undef
			table_element *tabela_searching = global_table;
			while (1){
				table_element *procura_id_global = search_element(node->value, tabela_searching);
				if(procura_id_global == NULL){
					printf("Line %d, col %d: Cannot find symbol %s\n", node->line, node->column, node->value);
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
					printf("Line %d, col %d: Cannot find symbol %s\n", node->line, node->column, node->value);
					add_annotation(node, "undef");
					break;
				}
			}
		}
		else{
			//Caso a tabela recebida seja uma tabela com parametros de funcoes, verifica se o parametros e inicializado antes na tabela, caso contrario procura na tabela global
			if (procura_id->line <= node->line){
				// Menor que a linha
				add_annotation(node, procura_id->vardecl->type);
			}

			else{
				table_element *tabela_searching = global_table;
				while (1){
					table_element *procura_id_global = search_element(node->value, tabela_searching);
					if(procura_id_global == NULL){
						printf("Line %d, col %d: Cannot find symbol %s\n", node->line, node->column, node->value);
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
						printf("Line %d, col %d: Cannot find symbol %s\n", node->line, node->column, node->value);
						add_annotation(node, "undef");
						break;
					}
				}
			}
		}
	}

	else if(strcmp(node->type, "Return") == 0){
		// Falta ver se a funcao retornar um int e dps nao retornar nada
		if(node->index_childs == 0 && global_return != 4){
			printf("Line %d, col %d: Incompatible type void in return statement\n", node->line, node->column);
		}

		if (node->index_childs != 0){
			create_ast(node->childs[0], table, numero);
			if(global_return == 4){
				printf("Line %d, col %d: Incompatible type %s in return statement\n", node->childs[0]->line, node->childs[0]->column, node->childs[0]->annotation);
			}
			else if(strcmp(node->childs[0]->annotation, "int") == 0 && global_return != 2){
				printf("Line %d, col %d: Incompatible type %s in return statement\n", node->childs[0]->line, node->childs[0]->column, node->childs[0]->annotation);
			}
			else if(strcmp(node->childs[0]->annotation, "double") == 0 && (global_return == 4 || global_return == 1)){
				printf("Line %d, col %d: Incompatible type %s in return statement\n", node->childs[0]->line, node->childs[0]->column, node->childs[0]->annotation);				
			}
			else if(strcmp(node->childs[0]->annotation, "boolean") == 0 && global_return != 1){
				printf("Line %d, col %d: Incompatible type %s in return statement\n", node->childs[0]->line, node->childs[0]->column, node->childs[0]->annotation);
			}
		}
		else{
			return;
		}
	}

	else if(strcmp(node->type, "Length") == 0){
		create_ast(node->childs[0], table, numero);
		if (strcmp(node->childs[0]->annotation, "String[]") != 0){
			printf("Line %d, col %d: Operator .length cannot be applied to type %s\n", node->line, node->column, node->childs[0]->annotation);
		}
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
				flag_primeira = 1;
				break;
			}
			else{
				if(aux->decl_type == 1){
					// Funcao
					if(node->index_childs - 1 == aux->funcdecl->n_params_header){
						// Se o nr de filhos - 1 (ou seja, sem o nome da funcao) = nr de parametros da funcao
						table_element * param = aux->funcdecl->vars;
						int contador = 0;
						for(int i = 1 ; i < node->index_childs; i++){ //verifica se os parametros da funcao sao iguais aos usados no call
							if (strcmp(node->childs[i]->annotation, param->vardecl->type) == 0){
								contador++;
							}
							param = param->next;
						}
						if(contador == aux->funcdecl->n_params_header){
							// Verifica se todas as variaveis sao do mesmo tipo
							table_element * param2 = aux->funcdecl->vars;

							if (aux->funcdecl->n_params_header == 0){
								// Se nao tiver parametros adiciona anotacao "()"
								add_annotation(node->childs[0], "()");
								add_annotation(node, aux->funcdecl->type_return);
							}
							else{
								char * aux_string = (char *) calloc((2), sizeof(char *)); //Inicializa o array a 2 de modo a que caiba ( e \0
								int size_anterior = 2;
								strcpy(aux_string, "(");
								for (int i = 0; i < aux->funcdecl->n_params_header; i++){
									if (i == aux->funcdecl->n_params_header - 1){
										// Aumentar o tamanho do char* para adicionar o tipo e os ultimos caracteres
										size_anterior += strlen(param2->vardecl->type)+3;
										aux_string = (char *)realloc(aux_string, size_anterior);
										strcat(aux_string, param2->vardecl->type);
									}
									else{ // Aumentar o tamanho do char* para adicionar o tipo e a ,
										size_anterior += strlen(param2->vardecl->type)+1;
										aux_string = (char *)realloc(aux_string, size_anterior);
										strcat(aux_string, param2->vardecl->type);
										strcat(aux_string, ",");
									}
									param2 = param2->next;
								}
								strcat(aux_string, ")"); 
								add_annotation(node->childs[0], aux_string);
								add_annotation(node, aux->funcdecl->type_return);
								free(aux_string);
							}
							break;
						}
					}
				}
			}
			tabela_searching = aux->next;
			if(tabela_searching == NULL){
				flag_primeira = 1;
				break;
			}
		}


		if (flag_primeira == 1){ // Volta a correr tudo outra vez para ver se encontra alguma coisa parecida
			table_element *tabela_searching_v2 = global_table;
			
			while(1){ // Corre todos os elementos com mesmo nome a procura da funcao com os mesmos parametros
				table_element *aux = search_element(node->childs[0]->value, tabela_searching_v2);
				if(aux == NULL){
					printf("Line %d, col %d: Cannot find symbol %s(", node->line, node->column, node->childs[0]->value);
					for (int u = 1; u < node->index_childs; u++){
						printf("%s", node->childs[u]->annotation);
						if( u < node->index_childs - 1){
							printf(",");
						}
					}
					printf(")\n");
					add_annotation(node->childs[0], "undef");
					add_annotation(node, "undef");
					break;
				}
				else{
					if(aux->decl_type == 1){
						// Funcao
						if(node->index_childs - 1 == aux->funcdecl->n_params_header){
							// Se o nr de filhos - 1 (ou seja, sem o nome da funcao) = nr de parametros da funcao
							table_element * param = aux->funcdecl->vars;
							int contador = 0;
							for(int i = 1 ; i < node->index_childs; i++){ //verifica se os parametros da funcao sao iguais aos usados no call
								if (strcmp(node->childs[i]->annotation, param->vardecl->type) == 0){
									contador++;
								}
								else if (strcmp(node->childs[i]->annotation, "int") == 0 && strcmp(param->vardecl->type, "double") == 0){ //os ints podem ser usados em funcoes que tem doubles como parametros
									contador++;
								}
								param = param->next;
							}
							if(contador == aux->funcdecl->n_params_header){
								// Verifica se todas as variaveis sao do mesmo tipo
								table_element * param2 = aux->funcdecl->vars;
								if (aux->funcdecl->n_params_header == 0){
									add_annotation(node->childs[0], "()");
									add_annotation(node, aux->funcdecl->type_return);
								}
								else{
									char * aux_string = (char *) calloc(2, sizeof(char *));
									int size_anterior = 2;
									strcpy(aux_string, "(");
									for (int i = 0; i < aux->funcdecl->n_params_header; i++){
										if (i == aux->funcdecl->n_params_header - 1){
											size_anterior += strlen(param2->vardecl->type)+3;
											aux_string = (char *)realloc(aux_string, size_anterior);//tamanho + \0 + ) + ultimo espaço para /0
											strcat(aux_string, param2->vardecl->type);
										}
										else{
											size_anterior += strlen(param2->vardecl->type)+2;
											aux_string = (char *)realloc(aux_string, size_anterior);//tamanho +  (+2 porque ele da add /0) + ,
											strcat(aux_string, param2->vardecl->type);
											strcat(aux_string, ",");
										}
										param2 = param2->next;
									}
									strcat(aux_string, ")");
									add_annotation(node->childs[0], aux_string);
									add_annotation(node, aux->funcdecl->type_return);
									free(aux_string);
								}
								break;
							}
						}
					}
				}	
				tabela_searching_v2 = aux->next;
				if(tabela_searching_v2 == NULL){
					printf("Line %d, col %d: Cannot find symbol %s()\n", node->line, node->column, node->childs[0]->value);
					for (int u = 1; u < node->index_childs; u++){
						printf("%s", node->childs[u]->annotation);
						if( u < node->index_childs - 1){
							printf(",");
						}
					}
					printf(")\n");
					add_annotation(node->childs[0], "undef");
					add_annotation(node, "undef");
					break;
				}
			}
		}
	}

	else if(strcmp(node->type, "Lshift") == 0 || strcmp(node->type, "Rshift") == 0 || strcmp(node->type, "ParamDecl") == 0 || strcmp(node->type, "VarDecl") == 0 || strcmp(node->type, "FieldDecl") == 0){
		// Lshift, Rshift, ParamDecl, VarDecl, FieldDecl
		return;
	}
	
	else if(strcmp(node->type, "MethodDecl")== 0){
		if(strcmp(node->childs[0]->childs[0]->type,"Bool") == 0){
			global_return = 1;
		}
		else if(strcmp(node->childs[0]->childs[0]->type,"Int") == 0){
			global_return = 2;
		}
		else if(strcmp(node->childs[0]->childs[0]->type,"Double") == 0){
			global_return = 3;
		}
		else if(strcmp(node->childs[0]->childs[0]->type,"Void") == 0){
			global_return = 4;
		}
		//printf("%d\n",global_return);
		struct node *methodBody = node->childs[1];	
		table_element *no_tabela = global_table;
		//da skip na tabela global ate encontrar o seu no correspondente
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
				//no caso de possuir parametros de entrada e/ou parametros no corpo, envia a sua tabela aos filhos
				table_element * var_no = no_tabela->funcdecl->vars;
				create_ast(methodBody, var_no, numero);
			}
			else{
				//caso seja uma funcao sem parametros proprios/ usa variaveis globais, manda a tabela global aos filhos
				create_ast(methodBody, global_table, numero);
			}
		}
	}

	else if (strcmp(node->type, "Print") == 0){
		for(int i = 0; i < node->index_childs; i++){
			create_ast(node->childs[i], table, numero);
		}
		if (strcmp(node->childs[0]->annotation, "undef") == 0){
			printf("Line %d, col %d: Incompatible type %s in System.out.print statement\n", node->line, node->column, node->childs[0]->annotation);
		}
	}

	else if(strcmp(node->type, "Program") == 0){
		// Correr os casos todos da arvore normal
		for(int i = 1; i < node->index_childs; i++){
			create_ast(node->childs[i], table, i);
		}
	}

	else{
		// Correr os casos dos ifs, whiles, blocks, ou seja os restantes casos nao definidos em cima
		for(int i = 0; i < node->index_childs; i++){
			create_ast(node->childs[i], table, numero);
		}
	}
}