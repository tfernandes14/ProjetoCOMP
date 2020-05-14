#include "symbol_table.h"

table_element * global_table = NULL;

// Cria o no da classe (primeiro no da tabela de simbolos)
table_element *insert_class(char *id, int line, int column){
	table_element *new = (table_element*) malloc(sizeof(table_element));

	new->decl_type = class;

	new->id = (char*) malloc(strlen(id) * sizeof(char)+1);
	strcpy(new->id, id);

	new->line = (int) malloc(sizeof(int));
	new->line = line;
	
	new->column = (int) malloc(sizeof(int));
	new->column = column;
	new->repetido = 0;

	new->next = NULL;

	return insert_element(new, &global_table);
}

// Cria o no das variaveis globais das tabelas
table_element * insert_fielddecl(char *id, char * type, char * param, int line, int column){
	
	table_element * new = (table_element*) malloc(sizeof(table_element));

	new->decl_type = fielddecl;

	new->id = (char*) malloc((strlen(id)+1) * sizeof(char));
	strcpy(new->id, id);

	new->line = (int) malloc(sizeof(int));
	new->line = line;
	
	new->column = (int) malloc(sizeof(int));
	new->column = column;

	new->repetido = 0;

	new->next = NULL;
	new->vardecl = (vardecl *) malloc(sizeof(vardecl));

	new->vardecl->type = (char*) malloc((strlen(type)+1) * sizeof(char));

	if (strcmp(type, "bool") == 0){
		strcpy(new->vardecl->type, "boolean");
	}
	else if (strcmp(type,"stringArray") == 0){
		strcpy(new->vardecl->type, "String[]");
	}
	else{
		strcpy(new->vardecl->type, type);
	}

	new->vardecl->param = (char*)malloc((strlen(param)+1)*sizeof(char));
	strcpy(new->vardecl->param, param);

	
	return new;
}

// Cria o no das variaveis locais das funcoes das tabelas
table_element * insert_vardecl(char * id, char * type, char * param, table_element ** table, int line, int column) {
	
	table_element * new = (table_element*) malloc(sizeof(table_element));

	new->decl_type = var;

	new->id = (char*)malloc((strlen(id)+1)*sizeof(char));
	strcpy(new->id, id);
    
	new->next = NULL;

	new->line = (int) malloc(sizeof(int));
	new->line = line;
	
	new->column = (int) malloc(sizeof(int));
	new->column = column;
	new->repetido = 0;

	new->vardecl = (vardecl *) malloc(sizeof(vardecl));
	
	new->vardecl->type = (char*)malloc(strlen(type)*sizeof(char) + 1);
	if (strcmp(type, "bool") == 0){
		strcpy(new->vardecl->type, "boolean");
	}
	else if (strcmp(type,"stringArray") == 0){
		strcpy(new->vardecl->type, "String[]");
	}
	else{
		strcpy(new->vardecl->type, type);
	}

	new->vardecl->param = (char*)malloc(strlen(param)*sizeof(char) + 1);
	strcpy(new->vardecl->param, param);

	return insert_element(new, table);
}

// Cria o no das funcoes das tabelas
table_element * create_funcdecl(char * id, char * type, int line, int column) {

	table_element * new = (table_element*) malloc(sizeof(table_element));

	new->decl_type = func;

	new->id = (char*) malloc((strlen(id)+1) * sizeof(char));
	strcpy(new->id, id);

	new->line = (int) malloc(sizeof(int));
	new->line = line;
	
	new->column = (int) malloc(sizeof(int));
	new->column = column;
	new->repetido = 0;


	new->next = NULL;

	new->funcdecl = (funcdecl *) malloc(sizeof(funcdecl));

	new->funcdecl->n_params = 0;
	new->funcdecl->n_params_header = 0;
	new->funcdecl->parametros_iguais_todos = 0;

	new->funcdecl->type_return = (char*) malloc(strlen(type) * sizeof(char) + 1);
	if (strcmp(type, "bool") == 0){
		strcpy(new->funcdecl->type_return, "boolean");
	}
	else{
		strcpy(new->funcdecl->type_return, type);
	}

	new->funcdecl->vars = NULL;
	return new;
}

// Insere a funcao/class/variavel global na tabela global 
table_element * insert_function(table_element * new, table_element **table){
	table_element * aux = *table;
	table_element * previous;
	if (aux != NULL) {
		while (aux != NULL) {

			previous = aux;
			aux = aux->next;

		}
		previous->next = new;
	}

	else {
		*table = new;
	}

	return new;
}

// Insere o no das variaveis locais na sua tabela local 
table_element * insert_element(table_element * new, table_element ** table) {
	table_element * aux = *table;
	table_element * previous;
	
	if (aux != NULL) {
		while (aux != NULL) {
			previous = aux;
			aux = aux->next;
		}
		previous->next = new;
	}

	else {
		*table = new;
	}

	return new;
}

// Procura os elementos pelo nome
table_element * search_element(char * id, table_element * table) {

	table_element * aux = table;

	while (aux != NULL) {
		
		if (strcmp(aux->id, id) == 0) return aux;
		aux = aux->next;
	}

	return NULL;
}

// Imprime todas as tabelas
void show_table(){
	table_element * aux = global_table;
	table_element * aux2 = global_table;

	printf("===== Class %s Symbol Table =====\n", aux->id);
	
	while (aux != NULL){ // Tabela da class
		if (aux->decl_type == fielddecl && aux->repetido == 0){
			// Variaveis da classe
			printf("%s\t\t%s\n", aux->id, aux->vardecl->type);
		}

		else if (aux->decl_type == func && aux->repetido == 0){
			// Funcoes
			if (aux->funcdecl->n_params == 0){
				printf("%s\t()\t%s\n", aux->id, aux->funcdecl->type_return);
			}
			else{
				printf("%s\t(", aux->id);

				table_element *param = aux->funcdecl->vars;

				if(strcmp(param->vardecl->param, "param") == 0){
					printf("%s", param->vardecl->type);
					param = param->next;
				}

				for (int i = 1; i < aux->funcdecl->n_params; i++){
					if(strcmp(param->vardecl->param, "param") == 0){
						printf(",%s", param->vardecl->type);
					}
					param = param->next;
				}

				printf(")\t%s\n", aux->funcdecl->type_return);
			}
		}
		aux = aux->next;
	}
	printf("\n");

	while (aux2 != NULL){ // Tabelas de cada funcao e suas variaveis
		if(aux2->decl_type == func){
			table_element *func_param = aux2->funcdecl->vars;
			printf("===== Method %s(", aux2->id);
			

			if(aux2->funcdecl->n_params > 0){
				if(strcmp(func_param->vardecl->param, "param") == 0){
					printf("%s", func_param->vardecl->type);
					func_param = func_param->next;
				}
			}

			// Parametros da funcao
			for(int i = 1; i < aux2->funcdecl->n_params; i++){
				if(strcmp(func_param->vardecl->param, "param") == 0){
					if (i == aux2->funcdecl->n_params - 1){
						printf(",%s", func_param->vardecl->type);
					}
					else{
						printf(",%s", func_param->vardecl->type);
					}
				}
				func_param = func_param->next;
			}
			printf(") Symbol Table =====\n");
			
			// Variaveis da funcao
			table_element *print_params = aux2->funcdecl->vars;
			printf("return\t\t%s\n",aux2->funcdecl->type_return);
			
			for(int i = 0; i < aux2->funcdecl->n_params; i++){
				if(strcmp(print_params->vardecl->param, "param") == 0){
					printf("%s\t\t%s\tparam\n",print_params->id, print_params->vardecl->type);	
				}
				else if(strcmp(print_params->vardecl->param, "null") == 0){
					printf("%s\t\t%s\n",print_params->id, print_params->vardecl->type);
				}
				print_params = print_params->next;
			}
			printf("\n");
		}
		aux2 = aux2->next;
	}
}