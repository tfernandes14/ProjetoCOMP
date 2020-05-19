#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "semantics_ast.h"

/*struct node{
    char* type;                         // Tipo da variavel (boolean, int, double, FuncDecl, MethodDecl......)
    char* value;                        // Valor da variavel
    struct node *dad;                   // Variavel a mais, mas indica o pai
    struct node *bros;                  // Variavel a mais, mas indica os irmaos
    struct node *childs[MAX_CHILD];     // Array com os filhos (usado para dar print)
    int index_childs;                   // Nr Total de Filhos
    char* annotation;                   // Anotacao para a arvore anotada
    int line;                           // Nr da linha (erros - nao estao feitos)
    int column;                         // Nr da coluna (erros - nao estao feitos)
};*/

void iterate_class(struct node *node){
    if(strcmp(node->type, "Program") == 0){
        create_fielddecl(node);
        for(int i = 1; i < node->index_childs; i++){
            iterate_class(node->childs[i]);
        }
    }
    else if((strcmp(node->type, "MethodDecl") == 0)){ //filhos MethodHeader(params) and MethodBody(variaveis)
        create_funcddecl(node->childs[0]);//methodHeader cria func
        create_methodbody(node->childs[1]);//preenche a func
    } 
}

void create_fielddecl(struct node *node){ //recebe a class, cria as variaveis globais
    for (int i = 1; i < node->index_childs; i++){
        if (strcmp(node->childs[i]->type, "FieldDecl") == 0){
            if (strcmp(node->childs[i]->childs[0]->type, "Int") == 0){
                printf("@%s = common global i32 0", node->childs[i]->childs[0]->value);
            }
            else if (strcmp(node->childs[i]->childs[0]->type, "Bool") == 0){
                printf("@%s = common global i1 0", node->childs[i]->childs[0]->value);
            }
            else if (strcmp(node->childs[i]->childs[0]->type, "Double") == 0){
                printf("@%s = common global .16e 0", node->childs[i]->childs[0]->value);
            }
        }
    }
}

void create_funcddecl(struct node *node){
    if(strcmp(node->childs[0]->type, "Int") == 0){
        printf("define i32 @%s",node->childs[1]->value);
    }

    else if(strcmp(node->childs[0]->type, "Bool") == 0){
        printf("define i1 @%s", node->childs[1]->value);
    }

    else if(strcmp(node->childs[0]->type, "Double") == 0){
        printf("define double @%s", node->childs[1]->value);
    }

    else if(strcmp(node->childs[0]->type, "Void") == 0){
        printf("define void @%s", node->childs[1]->value);
    }
    struct node *methodparams = node->childs[2];
    for(int i = 0 ; i < methodparams->index_childs;i++){
        struct node * param_decl = methodparams->childs[i];
        printf("_%s",param_decl->childs[0]->type);
    }
    printf("(");
    for(int i = 0 ; i < methodparams->index_childs;i++){
        struct node *param_decl = methodparams->childs[i];
        if(strcmp(node->childs[0]->type, "Int") == 0){
            printf("i32 %.%s", node->childs[1]->value);
        }
        else if(strcmp(node->childs[0]->type, "Bool") == 0){
            printf("i1 %.%s", node->childs[1]->value);
        }
        else if(strcmp(node->childs[0]->type, "Double") == 0){
            printf("double %.%s", node->childs[1]->value);
        }
        else if(strcmp(node->childs[0]->type, "StringArray") == 0){
            printf("i32,i8** %.%s", node->childs[1]->value);
        }
        if(i < methodparams->index_childs - 1){
            printf(",");
        }
    }
    printf(") {");
}

void create_methodbody(struct node *node){
    for (int i = 0; i < node->index_childs; i++){
        if (strcmp(node->childs[i]->type, "VarDecl") == 0){
            struct node *aux = node->childs[i];
            if (strcmp(aux->childs[0]->type, "Int") == 0){
                // Ver como se definem variaveis locais
            }
            else if (strcmp(aux->childs[0]->type, "Double") == 0){
                // Ver como se definem variaveis locais
            }
            else if (strcmp(aux->childs[0]->type, "Bool") == 0){
                // Ver como se definem variaveis locais
            }
        }
        else{
            create_statements(node->childs[i]);
        }
    }
}


void create_statements(struct node *node){

}

void create_call(struct node *node){

}


void init_produce(struct node *node, int* count_str){
    printf("declare i32 @printf(i8*, ...)\n");
    printf("declare i32 @atoi(i8*)\n");
    printf("@.true = constant [5 x i8] c\"true\\00\"\n");
    printf("@.false = constant [6 x i8] c\"false\\00\"\n");
    printf("@.int = constant [3 x i8] c\"%%d\\00\"\n");
    printf("@.double = constant [6 x i8] c\"%%.16e\\00\"\n");
    printf("@.str.0 = constant [2 x i8] c\"\0A\00\"\n");
    struct node *pointer = (struct node *) malloc(sizeof(node));
    change_str(node, pointer, count_str);
    Str_meta4 *aux = pointer->next;
    while(aux != NULL){
        printf("%s", aux->text);
        aux = aux->next;
    }
}