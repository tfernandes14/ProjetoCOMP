#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum {var, func, class, fielddecl} func_type;

typedef struct _t1 {
	char * type;					// Tipo da variavel
	char * param;					// Se e parametro de entrada ou local
} vardecl;

typedef struct _t2 {
	char * type_return;				// Tipo de retorno da funcao
	struct table_element * vars;	// Pointer para as variaveis que a funcao tem
	int n_params;					// Nr total de parametros de uma funcao
	int n_params_header;			// Nr total dos parametros de entrada (MethodHeader)
	int parametros_iguais_todos; 	// Flag se esta tabela dos methods (1) ou nao (0) mexida no final do check_func_decl
} funcdecl;

typedef struct table_element {
	func_type decl_type;			// Diz qual o tipo do elemento em causa
	char * id;						// Nome
	funcdecl * funcdecl;			// Pointer para funcao
    vardecl * vardecl;				// Pointer para variavel
	struct table_element * next;	// Pointer para o proximo no da tabela
	int line;						// Nr da linha (erros - nao estao feitos)
	int column;						// Nr da coluna (erros - nao estao feitos)
	int repetido;					// Flag se esta repetido na tabela class (1) ou nao (0), mexida no check_funcdecl e no check_fielddecl
} table_element;

table_element *insert_class(char *id, int line, int column);
table_element * insert_fielddecl(char *id, char * type, char * param, int line, int column);
table_element * insert_vardecl(char * id, char * type, char * param, table_element ** table, int line, int column);
table_element * create_funcdecl(char * id, char * type, int line, int column);
table_element *insert_func(table_element *new, table_element **table);
table_element * insert_function(table_element * new, table_element **table);
table_element * insert_element(table_element * new_symbol, table_element ** table);
table_element * search_element(char * identifier, table_element * table);
table_element * search_repetidos(char *id , table_element *inicio, int index, int type);
table_element * search_funcao_repetidos(table_element *no , table_element *inicio, int index);

void show_table();
void free_table(table_element * table);
void imprime_erros();

extern table_element * global_table;

