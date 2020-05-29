#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "semantics_ast.h"

void create_main();
void create_entry();
void init_produce(struct node *node);
void print_search_strlits(struct node *node);
void iterate_class(struct node *node, table_element *table);
void create_field(struct node *node);
void create_func(struct node *node);
void create_methodbody(struct node *node, table_element *table);
void create_statements(struct node *node, table_element *table);
void create_return(struct node *node);
void create_expressions(struct node *node, table_element *table);
int verifica_global(struct node *node);
int verifica_local(struct node *node, table_element *table);