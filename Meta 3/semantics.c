#include "semantics.h"
//#define DEBUG

void create_symbol_table(struct node *head) {
	for (int i = 0; i < head->index_childs; i++) {
		struct node *child = head->childs[i];

		if (strcmp(child->type, "MethodDecl") == 0) {
			check_func_decl(child);
		}

		else if (strcmp(child->type, "FieldDecl") == 0) {
			check_field_decl(child, &global_table);
		}
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
