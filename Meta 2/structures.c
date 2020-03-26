#include "structures.h"

/*typedef struct node{
    char* type;
    char* value;
    struct node *dad;
    struct node *bros;
    struct node *childs[MAX_CHILD];
    int index_childs;
}node;*/


node *create_node(char *type, char* value){
    node *new = (node *) malloc(sizeof(node));

    if (new == NULL){
        return NULL;
    }
    new->type = type;
    new->value = value;
    new->index_childs = 0;
    new->dad = NULL;
    new->bros = NULL;
    return new;
}

node *add_child(node *dad, node *child){
    // Verifica se algum dos nodes fornecidos esta a NULL ou nao
    if (dad == NULL || child == NULL){
        return NULL;
    }

    // Faz a associacao entre o pai e o filho recebido
    dad->childs[dad->index_childs] = child;
    dad->index_childs++;
    child->dad = dad;

    node *aux = child->bros;

    // Percorre os irmaos e diz que tem novo pai
    while (aux != NULL){
        aux->dad = dad;
        dad->childs[dad->index_childs] = aux;
        dad->index_childs++;
        aux = aux->bros;
    }

    return dad;
}


void print_tree(node *head, int depth){
    char *points = "";

    if (head == NULL){
        return;
    }

    for (int i = 0; i < depth; i++){
        printf("..");
    }

    if (strcmp(head->value, "") == 0){
        print("%s\n", head->type);
    }
    else{
        printf("%s(%s)\n", head->type, head->value);
    }

    for (int j = 0; j < head->index_childs; j++){
        print_tree(head->childs[j], depth++);
    }

    free(head);
}