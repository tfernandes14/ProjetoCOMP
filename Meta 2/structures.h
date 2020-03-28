#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILD 1000

typedef struct node{
    char* type;
    char* value;
    struct node *dad;
    struct node *bros;
    struct node *childs[MAX_CHILD];
    int index_childs;
}node;

// Nomes das funcoes usadas abaixos
struct node *create_node(char *type, char* value);
struct node *add_child(node *dad, node *child);
struct node *add_bro(node * s1, node * s2);
//void print_tree(node *head, int depth);