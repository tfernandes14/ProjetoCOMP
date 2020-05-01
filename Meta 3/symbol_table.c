#include "symbol_table.h"

table_element * global_table = NULL;

table_element *insert_class(char *id){
	table_element *new = (table_element*) malloc(sizeof(table_element));

	new->decl_type = class;

	strcpy(new->id, id);

	new->next = NULL;

	return insert_element(new, &global_table);	
}

table_element * insert_fielddecl(char *id, char * type, table_element ** symtab){
	
	table_element * new = (table_element*) malloc(sizeof(table_element));

	new->decl_type = fielddecl;

	strcpy(new->id, id);
    
	new->next = NULL;

	strcpy(new->vardecl->type, type);
	
	return insert_element(new, symtab);
}

table_element * insert_vardecl(char * id, char * type, char * param, table_element ** symtab) {
	
	table_element * new = (table_element*) malloc(sizeof(table_element));

	new->decl_type = var;

	new->id = (char*)malloc(strlen(id)*sizeof(char));
	strcpy(new->id, id);
    
	new->next = NULL;
	new->vardecl = (vardecl *) malloc(sizeof(vardecl));

	new->vardecl->type = (char*)malloc(strlen(type)*sizeof(char));
	strcpy(new->vardecl->type, type);

	new->vardecl->param = (char*)malloc(strlen(param)*sizeof(char));
	strcpy(new->vardecl->param, param);

	return insert_element(new, symtab);
}

table_element * insert_funcdecl(char * id, char * type) {

	table_element * new = (table_element*) malloc(sizeof(table_element));

	new->decl_type = func;

	new->id = (char*) malloc(strlen(id) * sizeof(char));
	strcpy(new->id, id);

	new->next = NULL;

	new->funcdecl = (funcdecl *) malloc(sizeof(funcdecl));


	new->funcdecl->n_params = 0;

	new->funcdecl->type_return = (char*) malloc(strlen(type) * sizeof(char));
	strcpy(new->funcdecl->type_return, type);

	new->funcdecl->vars = NULL;
	return insert_element(new, &global_table);
}

table_element * insert_element(table_element * new, table_element ** symtab) {

	table_element * aux = *symtab;
	table_element * previous;
	if (aux != NULL) {

		do {
			if (strcmp(aux->id, new->id) == 0){
                return NULL;
            }

			previous = aux;
			aux = aux->next;

		} while (aux != NULL);
		previous->next = new;
	}

	else {
		*symtab = new;
	}

	return new;
}

table_element * search_element(char * id, table_element * symtab) {

	table_element * aux = symtab;

	while (aux != NULL) {
		
		if (strcmp(aux->id, id) == 0) return aux; //this is the one we're searching for!
		aux = aux->next;
	}

	return NULL; //element not found
}

void show_table(){
	table_element * aux = global_table;
	// table_element * aux2 = global_table;

	printf("===== Class %s Symbol Table =====\n", aux->id);
	
	while (aux != NULL){
		if (aux->decl_type == fielddecl){
			// Variaveis da classe
			printf("%s\t\t%s\n", aux->id, aux->vardecl->type);
		}

		else if (aux->decl_type == func){
			// Funcao
			if (aux->funcdecl->n_params == 0){
				printf("%s\t\t%s\n", aux->id, aux->funcdecl->type_return);
			}
			else{
				printf("%s\t(", aux->id);

				table_element *param = aux->funcdecl->vars;

				for (int i = 0; i < aux->funcdecl->n_params; i++){
					if(strcmp(param->vardecl->param, "param") == 0){
						if (i == aux->funcdecl->n_params - 1){
							if(strcmp(param->vardecl->type, "stringArray") == 0){
								printf("String[]");
							}
							else{
								printf("%s", param->vardecl->type);
							}
						}else{
							printf("%s, ", param->vardecl->type);
						}
					}
					param = param->next;
				}

				printf(")\t%s\n", aux->funcdecl->type_return);
			}
		}
		aux = aux->next;
	}
}
