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
	int n_params;
} funcdecl;

typedef struct table_element {
	func_type decl_type;
	char * id;
	funcdecl * funcdecl;
    vardecl * vardecl;
	struct table_element * next;
} table_element;

table_element * insert_class(char * identifier);
table_element * insert_fielddecl(char *id, char * type, table_element ** symtab);
table_element * insert_vardecl(char * identifier, char * type,char * param, table_element ** symtab);
table_element * insert_funcdecl(char * identifier, char * return_type);
table_element * insert_element(table_element * new_symbol, table_element ** symtab);

table_element * search_element(char * identifier, table_element * symtab);

void show_table();
void free_table(table_element * symtab);

extern table_element * global_table;

