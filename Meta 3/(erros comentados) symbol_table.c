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

table_element * search_repetidos(char *id , table_element *inicio, int index, int type){
	table_element * aux = inicio;

	for(int i = 0 ; i < index; i++){
		if(strcmp(aux->id, id) == 0 && aux->decl_type == type) return aux;
		aux = aux->next;
	}
	return NULL;
}

table_element * search_funcao_repetidos(table_element *no , table_element *inicio, int index){
	table_element * aux = inicio;

	for(int i = 0 ; i < index; i++){
	//	printf("%s search\n", aux->id);
		if(aux->decl_type == 1){
			if(strcmp(aux->funcdecl->type_return, no->funcdecl->type_return) == 0 && strcmp(aux->id, no->id) == 0){
				if(aux->funcdecl->n_params_header == no->funcdecl->n_params_header){
					int conta = 0;

					table_element *var_no = no->funcdecl->vars;
					table_element *var_aux = aux->funcdecl->vars;

					for (int i = 0; i < no->funcdecl->n_params_header; i++){
						if (strcmp(var_no->vardecl->type, var_aux->vardecl->type) == 0){
							conta++;
						}
						var_no = var_no->next;
						var_aux = var_aux->next;
					}
					if(conta == no->funcdecl->n_params_header){
						//printf("YEAH %d\n",i);
						return aux;
					}
				}
			}
		}
		aux = aux->next;
	}
	return NULL;
}


void imprime_erros(){
	table_element * aux = global_table;
	table_element * aux2 = global_table;
	int k = 0;
	//int conta = 0;

	while(aux != NULL){
		if(aux->decl_type == func){
			table_element *tabela = aux->funcdecl->vars;
			table_element *vars_table = aux->funcdecl->vars;
			for(int i = 0 ; i < aux->funcdecl->n_params_header; i++){
				table_element *procura_var = search_repetidos(vars_table->id, tabela, i, 0);
				if(procura_var != NULL){
					if(strcmp(procura_var->id, "_") == 0){
						//printf("Line %d, col %d: Symbol _ is reserved\n",vars_table->line, vars_table->column);
					}
					else{
						//printf("Line %d, col %d: Symbol %s already defined\n",vars_table->line, vars_table->column, vars_table->id);
					}
				}
				else{
					if(strcmp(vars_table->id, "_") == 0){
						//printf("Line %d, col %d: Symbol _ is reserved\n",vars_table->line, vars_table->column);
					}
				}
				vars_table = vars_table->next;
			}
			table_element *procura = search_funcao_repetidos(aux, global_table, k);
			if(procura != NULL){
				/* printf("Line %d, col %d: Symbol %s(",aux->line, aux->column, aux->id);
				table_element *var_aux = aux->funcdecl->vars;
				for(int i = 0 ; i < aux->funcdecl->n_params_header; i++){
					printf("%s", var_aux->vardecl->type);
					if(i < aux->funcdecl->n_params_header - 1){
						printf(",");
					}
					var_aux = var_aux->next;
				}
				printf(") already defined\n");*/
			}
		}
		else if(aux->decl_type == fielddecl){
			table_element *procura_field = search_repetidos(aux->id, global_table, k, 3);
			if(procura_field != NULL){
				if(strcmp(procura_field->id, "_") == 0){
					//printf("Line %d, col %d: Symbol _ is reserved\n",aux->line, aux->column);
				}
				else{
					//printf("Line %d, col %d: Symbol %s already defined\n",aux->line, aux->column, aux->id);
				}
			}
			else{
				if(strcmp(aux->id, "_") == 0){
					//printf("Line %d, col %d: Symbol _ is reserved\n",aux->line, aux->column);
				}
			}
		}
		aux = aux->next;
		k++;
	}

	while(aux2 != NULL){
		if(aux2->decl_type == func){
			table_element * table_vars = aux2->funcdecl->vars;
			table_element * vars = aux2->funcdecl->vars;
			int search = aux2->funcdecl->n_params;
			int numero = aux2->funcdecl->n_params_header;
			for(int i = 0 ; i < search ; i++){
				table_element *procura_var = search_repetidos(vars->id, table_vars, i, 0);
				if(i > numero){
					if(procura_var != NULL){
						if(strcmp(procura_var->id, "_") == 0){
							//printf("Line %d, col %d: Symbol _ is reserved\n",vars->line, vars->column);
						}
						else{
							//printf("Line %d, col %d: Symbol %s already defined\n",vars->line, vars->column, vars->id);
						}
					}
				}
				vars = vars->next;
			}
		}
		aux2 = aux2->next;
	}
}//falta so casos de _

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