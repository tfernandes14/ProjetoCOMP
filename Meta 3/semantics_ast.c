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
			check_field_decl(child, &global_table);
		}
	}	
}

void check_class(struct node *node){
	char * id = (char *) malloc(strlen(node->type) * sizeof(char));
	strcpy(id, node->value);

	table_element * novo = insert_class(id);
    if(novo == NULL){
        printf("Symbol already defined!");
    }
}

void check_field_decl(struct node *node, table_element **symtab) {

	char * type = (char*) malloc(strlen(node->childs[0]->type) * sizeof(char));
	strcpy(type, node->childs[0]->type);
	*type = tolower(*type);

	char * value = (char*) malloc(strlen(node->childs[1]->value) * sizeof(char));
	strcpy(value, node->childs[1]->value);

    table_element * novo = insert_vardecl(value, type, "null", symtab);
    if(novo == NULL){
        printf("Symbol already defined!");
    }
}

void check_func_decl(struct node * node) {
	
	char * return_name;

	// Entra no MethodHeader
	struct node *methodHeader = node->childs[0];

	//primeiro filho = tipo de return
	return_name = (char *) malloc(strlen(methodHeader->childs[0]->type) * sizeof(char));
	strcpy(return_name, methodHeader->childs[0]->type);
	*return_name = tolower(*return_name);
	char * id_function = (char *) malloc(strlen(methodHeader->childs[1]->value) * sizeof(char));
	strcpy(id_function, methodHeader->childs[1]->value);

	table_element * new_symbol = insert_funcdecl(id_function, return_name);
	//Parametros do methodHeader
	struct node *methodParams = methodHeader->childs[2];
	for(int i = 0 ; i < methodParams->index_childs; i++){
		(new_symbol->funcdecl->n_params)++;
		//FormalParams = pai; 2 filhos ( 1 type) ( 2 value(id))
		struct node *params = methodParams->childs[i];
		char * var = (char *) malloc(strlen(params->childs[0]->type) * sizeof(char));
		strcpy(var, params->childs[0]->type);
		*var = tolower(*var);
		insert_vardecl(params->childs[1]->value, var, "param", &(new_symbol->funcdecl->vars));

		free(var);
	}
	//Parametros do Body
	struct node *methodBody = node->childs[1];

	for(int i = 0 ; i < methodBody->index_childs; i++){
		//VarDecl = pai, 2 filhos (type) e (value)
		if(strcmp(methodBody->childs[i]->type, "VarDecl") == 0){
			(new_symbol->funcdecl->n_params)++;
			char * var = (char *) malloc(strlen(methodBody->childs[i]->childs[0]->type) * sizeof(char));
			strcpy(var, methodBody->childs[i]->childs[0]->type);
			*var = tolower(*var);

			insert_vardecl(methodBody->childs[i]->childs[1]->value, var, "null", &(new_symbol->funcdecl->vars));

			free(var);
		}
	}

}

struct node *create_node(char *type, char* value){
    struct node *new = (struct node *) malloc(sizeof( node));

    if (new == NULL){
        return NULL;
    }
    new->type = type;
    new->value = value;
    new->index_childs = 0;
    new->dad = NULL;
    new->bros = NULL;
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
	node->annotation = (char *) malloc(sizeof(char) * strlen(annotation));
	strcpy(node->annotation, annotation);
	printf("ENTREI %s -- %s\n", node->type, node->annotation);
}

void create_ast(struct node *node){
	if(strcmp(node->type, "Add") == 0 || strcmp(node->type, "Sub") == 0 || strcmp(node->type, "Mul") == 0 || strcmp(node->type, "Div") == 0 || strcmp(node->type, "Mod") == 0 || strcmp(node->type, "Assign") == 0){
		/*
			aqui, mandar correr o filho0, filho1(...), verificar se anotacao dos filhos e igual
			se for igual adicionar anotacao do filho ao pai
			se nao for e undef
		*/
		printf("1\n");
		create_ast(node->childs[0]);
		printf("bacalhau\n");
		create_ast(node->childs[1]);
		printf("a bras\n");

		if(strcmp(node->childs[0]->annotation, node->childs[1]->annotation) == 0){
			add_annotation(node, node->childs[0]->annotation);
		}
		else{
			add_annotation(node, "undef");
		}
	}	

	else if(strcmp(node->type, "And") == 0 || strcmp(node->type, "Or") == 0 || strcmp(node->type, "Xor") == 0 || strcmp(node->type, "Eq") == 0 || strcmp(node->type, "Ge") == 0 || strcmp(node->type, "Gt") == 0 || strcmp(node->type, "Le") == 0 || strcmp(node->type, "Lt") == 0 || strcmp(node->type, "Ne") == 0){
		// corre filho 0 e filho 1, e dizer que o pai vai ser boolean
		printf("2\n");
		create_ast(node->childs[0]);
		create_ast(node->childs[1]);
		add_annotation(node, "boolean");
	}

	else if(strcmp(node->type, "Not") == 0 || strcmp(node->type, "Minus") == 0 || strcmp(node->type, "Plus") == 0){
		 //manda correr o filho e adicionar o tipo do filho
		 printf("3\n"); 
		create_ast(node->childs[0]);
		add_annotation(node, node->childs[0]->annotation);
	}
	else if(strcmp(node->type, "Id") == 0){
		/*
			se o id for uma funcao, meter "(tipo)""
			se nao, meter "tipo"
			se a funcao nao existir, meter "undef"
		*/
		printf("[ID] Ainda nao fui tratado\n");
		add_annotation(node, "null");
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
		printf("[CALL] Ainda n fui tratado\n");
		add_annotation(node, "null");
	}

	/*else if(strcmp(node->type, "Lshift") == 0){

	}
	else if(strcmp(node->type, "Rshift") == 0){

	}*/
	else{
		for(int i = 0; i < node->index_childs; i++){
			printf("LOOOPING %s\n",node->childs[i]->type);
			create_ast(node->childs[i]);
		}
	}
}