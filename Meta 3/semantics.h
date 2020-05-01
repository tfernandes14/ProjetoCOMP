#include "symbol_table.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_CHILD 1000

typedef struct node node;

struct node{
    char* type;
    char* value;
    struct node *dad;
    struct node *bros;
    struct node *childs[MAX_CHILD];
    int index_childs;
};

void create_symbol_table(struct node * head);
void check_field_decl(struct node *node, table_element **symtab);
void check_func_decl(struct node * node);