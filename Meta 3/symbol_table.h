#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum {var, func, class, fielddecl} func_type;

typedef struct _t1 {
	char * type;
	char * param;
} vardecl;

typedef struct _t2 {
	char * type_return;
	struct table_element * vars;
	int n_params;					// Nr total de parametros de uma funcao
	int n_params_header;			// Nr total dos parametros de entrada (MethodHeader)
	int parametros_iguais_todos; 	//flag se esta tabela dos methods (1) ou nao (0) mexida no final do check_func_decl
} funcdecl;

typedef struct table_element {
	func_type decl_type;
	char * id;
	funcdecl * funcdecl;
    vardecl * vardecl;
	struct table_element * next;
	int line;
	int column;
	int repetido;		// Flag se esta repetido na tabela class (1) ou nao (0) , mexida no check_funcdecl e no check_fielddecl
} table_element;

table_element *insert_class(char *id, int line, int column);
table_element * insert_fielddecl(char *id, char * type, char * param, int line, int column);
table_element * insert_vardecl(char * id, char * type, char * param, table_element ** table, int line, int column);
table_element * create_funcdecl(char * id, char * type, int line, int column);
table_element *insert_func(table_element *new, table_element **table);
table_element * insert_function(table_element * new, table_element **table);
table_element * insert_element(table_element * new_symbol, table_element ** table);
table_element * search_element(char * identifier, table_element * table);

void show_table();
void free_table(table_element * table);

extern table_element * global_table;

