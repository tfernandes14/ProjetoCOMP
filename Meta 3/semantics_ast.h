#include "symbol_table.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_CHILD 1000

typedef struct node node;

struct node{
    char* type;         // Tipo da variavel (boolean, int, double)
    char* value;        // Valor da variavel
    struct node *dad;
    struct node *bros;
    struct node *childs[MAX_CHILD];
    int index_childs;
    char* annotation;
    int line;
    int column;
};

void create_symbol_table(struct node * head);
void check_class(struct node *node);
void check_field_decl(struct node *node);
void check_func_decl(struct node * node);
struct node *create_node(char *type, char* value, int line, int column);
struct node *add_child(struct node *dad, struct node *child);
struct node *add_bro(struct node * s1, struct node * s2);
void print_tree(struct node *head, int depth);
void print_tree_annotated(struct node *head, int depth);
void add_annotation(struct node *node, char *annotation);
void create_ast(struct node *node, table_element *table);