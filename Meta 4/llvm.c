#include "llvm.h"

int label_incrementa = 1;
int while_incrementa = 1;
int incrementa;
int string_valor;
int main_contador = 0;
int entry = 0;


void iterate_class(struct node *node, table_element *table){
      //printf("Entrei Class\n");
    if(strcmp(node->type, "Program") == 0){
        string_valor = 0;
        create_field(node);
        table_element * aux  = table;
        aux = aux->next;
        for(int i = 1; i < node->index_childs; i++){
            iterate_class(node->childs[i],aux);
            aux = aux->next;
        }
        if(entry == 1){
            create_entry();
        }
        if(main_contador == 0){
            create_main();
        }
    }
    else if((strcmp(node->type, "MethodDecl") == 0)){ //filhos MethodHeader(params) and MethodBody(variaveis)
        create_func(node->childs[0]);//methodHeader cria func
        incrementa = 1;
        if(table->funcdecl->n_params != 0){
            create_methodbody(node->childs[1], table->funcdecl->vars);//preenche a func
        }else{
            create_methodbody(node->childs[1], global_table);
        }
        create_return(node->childs[0]);
        printf("}\n");
    } 
}

void create_main(){
    /*
        define i32 @main(i32,i8** %.args){
        %args = alloca i8**
        store i8** %.args, i8*** %args
        ret i32 0
        }
    */
    printf("define i32 @main(i32,i8** %%.args){\n");
    printf("%%args = alloca i8**\n");
    printf("store i8** %%.args, i8*** %%args\n");
    printf("ret i32 0\n");
    printf("}\n");
}

void create_entry(){
    printf("define i32 @main(i32 %%.size,i8** %%.args){\n");
    printf("call void @main.entry(i32 %%.size, i8** %%.args)\n");
    printf("ret i32 0\n");
    printf("}\n");
}

void create_field(struct node *node){ //recebe a class, cria as variaveis globais
    //printf("Entrei field\n");
    for (int i = 1; i < node->index_childs; i++){
        if (strcmp(node->childs[i]->type, "FieldDecl") == 0){
            if (strcmp(node->childs[i]->childs[0]->type, "Int") == 0){
                //printf("@%s = common global i32 0\n", node->childs[i]->childs[1]->value);
                printf("@%s",node->childs[i]->childs[1]->value);
                printf("_int = common global i32 0\n");
            }
            else if (strcmp(node->childs[i]->childs[0]->type, "Bool") == 0){
                //printf("@%s = common global i1 0\n", node->childs[i]->childs[1]->value);
                printf("@%s",node->childs[i]->childs[1]->value);
                printf("_bool = common global i1 0\n");
            }
            else if (strcmp(node->childs[i]->childs[0]->type, "Double") == 0){
                //printf("@%s = common global double 0.0\n", node->childs[i]->childs[1]->value);
                printf("@%s",node->childs[i]->childs[1]->value);
                printf("_double = common global double 0.0\n");
            }
        }
    }
}

void create_func(struct node *node){
      //printf("Entrei func\n");
      //0 type, 1 id, 2 methodsparams-> filhos sao paramdecls->childs0-type childs1id
    int main_found = 0;
    if(strcmp(node->childs[0]->type, "Int") == 0){
        if(strcmp(node->childs[1]->value, "main") == 0){
            printf("define i32 @%s", node->childs[1]->value);
        }
        else{
            printf("define i32 @method_%s_int",node->childs[1]->value);
        }
    }

    else if(strcmp(node->childs[0]->type, "Bool") == 0){
        if(strcmp(node->childs[1]->value, "main") == 0){
            printf("define i1 @%s", node->childs[1]->value);
        }
        else{
            printf("define i1 @method_%s_bool", node->childs[1]->value);
        }
    }

    else if(strcmp(node->childs[0]->type, "Double") == 0){
        if(strcmp(node->childs[1]->value, "main") == 0){
            printf("define double @%s", node->childs[1]->value);
        }else{
            printf("define double @method_%s_double", node->childs[1]->value);
        }
    }

    else if(strcmp(node->childs[0]->type, "Void") == 0){
        if(strcmp(node->childs[1]->value, "main") == 0){
            printf("define void @%s.entry", node->childs[1]->value);
            entry = 1;
        }else{
            printf("define void @method_%s_void", node->childs[1]->value);
        }
    }
    if(strcmp(node->childs[1]->value, "main") == 0) {
        main_contador = 1;
        main_found = 1;
    }
    struct node *methodparams = node->childs[2];
    if(main_found == 0){
        for(int i = 0 ; i < methodparams->index_childs;i++){
            struct node * param_decl = methodparams->childs[i];
            //printf("_%s",param_decl->childs[0]->type);
            if(strcmp(param_decl->childs[0]->type, "Int") == 0){
                printf("_int");
            }
            else if(strcmp(param_decl->childs[0]->type, "Bool") == 0){
                printf("_bool");
            }
            else if(strcmp(param_decl->childs[0]->type, "Double") == 0){
                printf("_double");
            }
            else if(strcmp(param_decl->childs[0]->type, "StringArray") == 0){
                printf("_string");
            }
        }
    }
    printf("(");
    for(int i = 0 ; i < methodparams->index_childs;i++){
        struct node *param_decl = methodparams->childs[i];
        if(strcmp(param_decl->childs[0]->type, "Int") == 0){
            printf("i32 %%.%s", param_decl->childs[1]->value);
        }
        else if(strcmp(param_decl->childs[0]->type, "Bool") == 0){
            printf("i1 %%.%s", param_decl->childs[1]->value);
        }
        else if(strcmp(param_decl->childs[0]->type, "Double") == 0){
            printf("double %%.%s", param_decl->childs[1]->value);
        }
        else if(strcmp(param_decl->childs[0]->type, "StringArray") == 0){
            printf("i32 %%.size.,i8** %%.%s", param_decl->childs[1]->value);
        }
        if(i < methodparams->index_childs - 1){
            printf(",");
        }
    }
    printf(") {\n");
    for(int i = 0 ; i < methodparams->index_childs;i++){
        struct node *param_decl = methodparams->childs[i];//childs o->type, childs1->id
        if(strcmp(param_decl->childs[0]->type, "Int") == 0){
            printf("%%%s = alloca i32\n", param_decl->childs[1]->value);
            printf("store i32 %%.%s, i32* %%%s\n",param_decl->childs[1]->value,param_decl->childs[1]->value);
            /*%input = alloca i32
            store i32 %.input, i32* %input*/
        }
        else if(strcmp(param_decl->childs[0]->type, "Bool") == 0){
            //printf("i1 %%.%s", node->childs[1]->value);
            //%i = alloca i1
            printf("%%%s = alloca i1\n",param_decl->childs[1]->value);
        }
        else if(strcmp(param_decl->childs[0]->type, "Double") == 0){
            printf("%%%s = alloca double\n", param_decl->childs[1]->value);
            printf("store double %%.%s, double* %%%s\n",param_decl->childs[1]->value,param_decl->childs[1]->value);
            /*
            %n = alloca double
            store double %.n, double* %n
            */
        }
        else if(strcmp(param_decl->childs[0]->type, "StringArray") == 0){
            printf("%%size. = alloca i32\n");
            printf("store i32 %%.size., i32* %%size.");
            printf("%%%s = alloca i8**\n", param_decl->childs[1]->value);
            printf("store i8** %%.%s, i8*** %%%s\n",param_decl->childs[1]->value,param_decl->childs[1]->value);
            /*
            %args = alloca i8**
            store i8** %.args, i8*** %args
            */
        }
    }
}

void create_methodbody(struct node *node, table_element *table){
      //printf("Entrei body\n");
    for (int i = 0; i < node->index_childs; i++){
        if (strcmp(node->childs[i]->type, "VarDecl") == 0){
            struct node *aux = node->childs[i];
            if (strcmp(aux->childs[0]->type, "Int") == 0){
                // Ver como se definem variaveis locais;
                printf("%%%s = alloca i32\n",aux->childs[1]->value);
            }
            else if (strcmp(aux->childs[0]->type, "Double") == 0){
                // Ver como se definem variaveis locais
                printf("%%%s = alloca double\n",aux->childs[1]->value);
            }
            else if (strcmp(aux->childs[0]->type, "Bool") == 0){
                // Ver como se definem variaveis locais
                printf("%%%s = alloca i1\n",aux->childs[1]->value);
            }
        }
        else{
            create_statements(node->childs[i], table);
        }
    }
}

void create_statements(struct node *node, table_element *table){
      //printf("Entrei statement\n");
    struct node *aux = node;
    if (strcmp(aux->type, "Assign") == 0){//filho0 = id; filho 1 -> expr 
        create_expressions(aux->childs[1], table);
        //usar a tabela para ver qual tipo do id
        if(strcmp(aux->annotation, "int") == 0){
            //expressions podem ser int, double 
            if(strcmp(aux->childs[1]->annotation, "double")==0){
                printf("%%.%d = fptosi double %%.%d to i32\n",incrementa, incrementa-1);
                incrementa++;
            }
            if(!verifica_local(aux->childs[0], table) && verifica_global(aux->childs[0])){
                printf("store i32 %%.%d, i32* @%s_int\n",incrementa-1,aux->childs[0]->value);
                //incrementa++;
            }else{
                printf("store i32 %%.%d, i32* %%%s\n",incrementa-1,aux->childs[0]->value);
               //incrementa++;
            }
            //printf("store i32 %%.%d, i32* %%%s\n",incrementa-1,aux->childs[0]->value);
            //incrementa++;
            //se filho for global
            //printf("store i32 %%.%d, i32* @%s",incrementa-1,aux->childs[1]->value);
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0){
            /*
                %j = alloca double
                %.2 = add i32 0, 4 //tratado nos statements
                %.3 = sitofp i32 %.2 to double
                store double %.3, double* %j
            */
            //expressions podem ser int, double 
            if(strcmp(aux->childs[1]->annotation, "int")==0){
                printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, incrementa-1);
                incrementa++;
            }
            if(!verifica_local(aux->childs[0], table) && verifica_global(aux->childs[0])){
                printf("store double %%.%d, double* @%s_double\n",incrementa-1,aux->childs[0]->value);
                //incrementa++;
            }else{
                printf("store double %%.%d, double* %%%s\n",incrementa-1,aux->childs[0]->value);
                //incrementa++;
            }
            //printf("store double %%.%d, double* %%%s\n",incrementa-1,aux->childs[0]->value);
            //incrementa++;
            //se filho for global
            //printf("store double %%.%d, double* @%s",incrementa-1,aux->childs[1]->value);
        }
        else if(strcmp(aux->childs[0]->annotation, "boolean") == 0){
            if(!verifica_local(aux->childs[0], table) && verifica_global(aux->childs[0])){
                printf("store i1 %%.%d, i1* @%s_bool\n",incrementa-1,aux->childs[0]->value);
                //incrementa++;
            }else{
                printf("store i1 %%.%d, i1* %%%s\n",incrementa-1,aux->childs[0]->value);
                //incrementa++;
            }
            //printf("store i1 %%.%d, i1* %%%s\n",incrementa-1,aux->childs[0]->value);
        }
    }
    else if (strcmp(aux->type, "Call") == 0){//filho0 =id, restantes filhos sao expr
        //percorrer os filhos para obter o nomecompleto
        /*
            %.1 = add i32 0, 4
            %.2 = sitofp i32 %.1 to double
            %.3 = call double @method_test_0(double %.2)
        */
        if(aux->index_childs > 1){
            int array[aux->index_childs];
            for(int i = 1; i < aux->index_childs;i++){
                create_expressions(aux->childs[i], table);
                int x1 = incrementa - 1;
                array[i-1] = x1;
            }

            int tamanho = strlen(aux->childs[0]->annotation);
            char * aux_string = (char *)malloc((tamanho) * sizeof(char *));
            int conta = 0;
            int array_ind = 1;
            //annotacao (double,int)//memset(&arr[0], 0, sizeof(arr));
            for(int i = 1 ; i < tamanho-1;i++){
                //printf("\n%c\n",aux->childs[0]->annotation[i]);
                if(aux->childs[0]->annotation[i] == ','){
                    //printf("_%s",aux_string);
                    if(aux->childs[array_ind]->annotation == NULL){
                        if(strcmp(aux->childs[array_ind]->type, "DecLit") == 0){
                            if(strcmp(aux_string, "double") == 0){
                                    printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, array[array_ind-1]);
                                    array[array_ind-1] = incrementa;
                                    incrementa++;
                            }
                            array_ind++;
                        }else if(strcmp(aux->childs[array_ind]->type, "RealLit") == 0){
                            if(strcmp(aux_string, "int") == 0){//printf("%%.%d = fptosi double %%.%d to i32\n",incrementa, incrementa-1);
                                printf("%%.%d = fptosi double %%.%d to i32\n",incrementa, array[array_ind-1]);
                                array[array_ind-1] = incrementa;
                                incrementa++;
                            }
                            array_ind++;
                        }
                    }else{
                        if(strcmp(aux->childs[array_ind]->annotation,"int") == 0){
                            if(strcmp(aux_string, "double") == 0){//printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, incrementa-1);
                                printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, array[array_ind-1]);
                                array[array_ind-1] = incrementa;
                                incrementa++;
                            }
                            array_ind++;
                        }else if(strcmp(aux->childs[array_ind]->annotation,"double") == 0){
                            if(strcmp(aux_string, "int") == 0){
                                printf("%%.%d = fptosi double %%.%d to i32\n",incrementa, array[array_ind-1]);
                                array[array_ind-1] = incrementa;
                                incrementa++;
                            }
                            array_ind++;
                        }
                    }
                    conta = 0;
                    memset(&aux_string[0], 0, sizeof(aux_string));
                    //printf("\n\n\n\nACABEI WTF\n\n\n");

                }else{ 
                    aux_string[conta] = aux->childs[0]->annotation[i];
                    conta++;
                }
            }
            //printf("\nWTF KYLE\n %s %s  %s\n\n",aux_string, aux->childs[array_ind]->type, aux->childs[array_ind]->value);
            if(aux->childs[array_ind]->annotation == NULL){
                if(strcmp(aux->childs[array_ind]->type, "DecLit") == 0){
                    if(strcmp(aux_string, "double") == 0){
                        printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, array[array_ind-1]);
                        array[array_ind-1] = incrementa;
                        incrementa++;
                    }
                    array_ind++;
                }else if(strcmp(aux->childs[array_ind]->type, "RealLit") == 0){
                    if(strcmp(aux_string, "int") == 0){//printf("%%.%d = fptosi double %%.%d to i32\n",incrementa, incrementa-1);
                        printf("%%.%d = fptosi double %%.%d to i32\n",incrementa, array[array_ind-1]);
                        array[array_ind-1] = incrementa;
                        incrementa++;
                        }
                        array_ind++;
                    }
            }else{
                if(strcmp(aux->childs[array_ind]->annotation,"int") == 0){
                    if(strcmp(aux_string, "double") == 0){//printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, incrementa-1);
                        printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, array[array_ind-1]);
                        array[array_ind-1] = incrementa;
                        incrementa++;
                    }
                    array_ind++;
                }else if(strcmp(aux->childs[array_ind]->annotation,"double") == 0){
                    if(strcmp(aux_string, "int") == 0){
                        printf("%%.%d = fptosi double %%.%d to i32\n",incrementa, array[array_ind-1]);
                        array[array_ind-1] = incrementa;
                        incrementa++;
                    }
                    array_ind++;
                }
            }
            //printf("\n\nFUCK %s\n\n ",aux->annotation);
            if(strcmp(aux->annotation,"int") == 0){
                printf("%%.%d = call i32 @method_%s_int",incrementa,aux->childs[0]->value);
                incrementa++;
            }else if(strcmp(aux->annotation,"double") == 0){
                printf("%%.%d = call double @method_%s_double",incrementa,aux->childs[0]->value);
                incrementa++;
            }else if(strcmp(aux->annotation, "void") == 0){
                printf("call void @method_%s_void",aux->childs[0]->value);
            }else if(strcmp(aux->annotation, "boolean") == 0){
                printf("%%.%d = call i1 @method_%s_bool",incrementa,aux->childs[0]->value);
                incrementa++;
            }
            //anotacoes
            memset(&aux_string[0], 0, sizeof(aux_string));
            conta = 0;
            for(int i = 1 ; i < tamanho-1;i++){
                //printf("\n%c\n",aux->childs[0]->annotation[i]);
                if(aux->childs[0]->annotation[i] == ','){
                    printf("_%s",aux_string);
                    conta = 0;
                    memset(&aux_string[0], 0, sizeof(aux_string));

                }else{ 
                    aux_string[conta] = aux->childs[0]->annotation[i];
                    conta++;
                }
            }
            printf("_%s",aux_string);
            printf("(");
            memset(&aux_string[0], 0, sizeof(aux_string));
            conta = 0;
            array_ind = 1;
            //ate aqui tudo bem
            for(int i = 1 ; i < tamanho-1;i++){
                if(aux->childs[0]->annotation[i] == ','){
                    if(strcmp(aux_string,"int") == 0){
                        printf("i32 %%.%d",array[array_ind-1]);
                        array_ind++;
                    }else if(strcmp(aux_string,"double") == 0){ 
                        printf("double %%.%d",array[array_ind-1]);
                        array_ind++;
                    }else if(strcmp(aux_string, "boolean") == 0){
                        printf("i1 %%.%d",array[array_ind-1]);
                        array_ind++;
                    }
                    printf(",");
                    conta = 0;
                    memset(&aux_string[0], 0, sizeof(aux_string));
                }else{ 
                    aux_string[conta] = aux->childs[0]->annotation[i];
                    conta++;
                }
            }
            if(strcmp(aux_string,"int") == 0){
                printf("i32 %%.%d",array[array_ind-1]);
                array_ind++;
            }else if(strcmp(aux_string,"double") == 0){
                printf("double %%.%d",array[array_ind-1]);
                array_ind++;
            }else if(strcmp(aux_string, "boolean") == 0){
                printf("i1 %%.%d",array[array_ind-1]);
                array_ind++;            
            }
            free(aux_string);
            printf(")\n");
        }else{
                if(strcmp(aux->annotation,"int") == 0){
                    printf("%%.%d = call i32 @method_%s_int",incrementa,aux->childs[0]->value);
                    incrementa++;
                }else if(strcmp(aux->annotation,"double") == 0){
                    printf("%%.%d = call double @method_%s_double",incrementa,aux->childs[0]->value);
                    incrementa++;
                }else if(strcmp(aux->annotation, "void") == 0){
                    printf("call void @method_%s_void",aux->childs[0]->value);
                }else if(strcmp(aux->annotation, "boolean") == 0){
                    printf("%%.%d = call i1 @method_%s_bool",incrementa,aux->childs[0]->value);
                    incrementa++;
                }
                printf("()\n");
            }
        }
    else if (strcmp(aux->type, "Block") == 0){//tem varias statements
        for(int i = 0 ; i < aux->index_childs;i++){
            create_statements(aux->childs[i], table);
        }
    }
    else if (strcmp(aux->type, "If") == 0){//filho 0->expr, filho1->statement//ou block , [filho2->statement]
        //printf("MANDA OS PUTOS %s\n",aux->childs[0]->type);
        create_expressions(aux->childs[0], table);
        int numero = label_incrementa;
        label_incrementa++;
        printf("br i1 %%.%d, label %%then%d, label %%else%d\n",incrementa-1, numero, numero);
        printf("then%d:\n",numero);
        create_statements(aux->childs[1], table);
        printf("br label %%ifCont%d\n",numero);
        printf("else%d:\n",numero);
        if(aux->index_childs > 2){
            create_statements(aux->childs[2], table);
        }
        printf("br label %%ifCont%d\n",numero);
        printf("ifCont%d:\n",numero);
    }
    else if (strcmp(aux->type, "While") == 0){//filho 0 = expr, filho 1->statement
        /*
        br label %while1
        while1:daqui pa baixo e o que esta dentro do block
        %.2 = load i32, i32* %input
        %.3 = add i32 0, 2
        %.4 = add i32 %.2, %.3
        store i32 %.4, i32* %input
        %.5 = load i32, i32* %i
        %.6 = add i32 0, 1
        %.7 = add i32 %.5, %.6
        store i32 %.7, i32* %i
        %.8 = load i32, i32* %i
        %.9 = add i32 0, 10 expression
        %.10 = icmp slt i32 %.8, %.9 expression
        br i1 %.10, label %while1, label %whileCont1  condicao
        while(i < 10){input = input + 2;i = i + 1}
        whileCont1:
        */
        int numero = while_incrementa;
        while_incrementa++;
        printf("br label %%while%d\n",numero);
        printf("while%d:\n",numero);
        create_statements(aux->childs[1], table);
        create_expressions(aux->childs[0], table);
        printf("br i1 %%.%d, label %%while%d, label %%whileCont%d\n",incrementa-1,numero,numero);
        printf("whileCont%d:\n",numero);
    }
    else if (strcmp(aux->type, "ParseArgs") == 0){//filho 0 ID, filho 1 ->expr
        create_expressions(aux->childs[1], table);
        //ver se o id e global ou local
        if(!verifica_local(aux->childs[0], table) && verifica_global(aux->childs[0])){
            printf("%%.%d = load i8**, i8*** @%s\n",incrementa, aux->childs[0]->value);
            incrementa++;   
        }else{
            printf("%%.%d = load i8**, i8*** %%%s\n",incrementa, aux->childs[0]->value);
            incrementa++;   
        }
        printf("%%.%d = add i32 1, %%.%d\n",incrementa, incrementa-2);
        incrementa++;
        printf("%%.%d = getelementptr i8*, i8** %%.%d, i32 %%.%d\n",incrementa, incrementa-2,incrementa-1);
        incrementa++;
        printf("%%.%d = load i8*, i8** %%.%d\n",incrementa, incrementa-1);
        incrementa++;
        printf("%%.%d = call i32  @atoi(i8* %%.%d)\n",incrementa, incrementa-1);
        incrementa++;
    }
    else if (strcmp(aux->type, "Print") == 0){//filho strlit ou expr
        if(strcmp(aux->childs[0]->type,"StrLit") == 0){
            //%.1 = call i32 (i8*, ...) @printf(i8* getelementptr  ([size x i8], [size x i8]* string, i32 0, i32 0))
            int x = strlen(node->childs[0]->value);
            if(strcmp(node->childs[0]->value, "\n") == 0){
                //printf("@.str.%d = constant [2 x i8] c\"\\0A\\00\"\n",string_valor);
                printf("%%.%d = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.%d, i32 0, i32 0))\n", incrementa,string_valor);
                incrementa++;
                string_valor++;
            }else{
                char * aux_string = (char *)malloc((x + x) * sizeof(char *));
                int j = 0;
                int size = 2;
                int conta = 0;
                for(int i = 1; i < x-1; i++){
                    if(node->childs[0]->value[i] == '\\'){
                        aux_string[j] = node->childs[0]->value[i];
                        j++;
                        if(node->childs[0]->value[i+1] == 'n'){
                            aux_string[j] = '0';
                            j++;
                            aux_string[j] = 'A';
                            j++;
                            i++;
                        }
                        else if(node->childs[0]->value[i+1] == 'f'){
                            aux_string[j] = '0';
                            j++;
                            aux_string[j] = 'C';
                            j++;
                            i++;
                        }
                        else if(node->childs[0]->value[i+1] == 'r'){
                            aux_string[j] = '0';
                            j++;
                            aux_string[j] = 'D';
                            j++;
                            i++;
                        }
                        else if(node->childs[0]->value[i+1] == 't'){
                            aux_string[j] = '0';
                            j++;
                            aux_string[j] = '9';
                            j++;
                            i++;
                        }
                        else if(node->childs[0]->value[i+1] == '\\'){
                            aux_string[j] = '5';
                            j++;
                            aux_string[j] = 'C';
                            j++;
                            i++;
                        }
                        else if(node->childs[0]->value[i+1] == '\"'){
                            aux_string[j] = '2';
                            j++;
                            aux_string[j] = '2';
                            j++;
                            i++;
                        }
                        size++;
                    }else if(node->childs[0]->value[i] == '%'){
                        aux_string[j] = '%';
                        j++;
                        aux_string[j] = '%';
                        j++;
                        conta++;
                    }
                    else{
                        aux_string[j] = node->childs[0]->value[i];
                        j++; 
                    }
                }
                aux_string[j] = '\0';
                j++;
                x = x +1;
                printf("%%.%d = call i32 (i8*, ...) @printf(i8* getelementptr ([%d x i8], [%d x i8]* @.str.%d, i32 0, i32 0))\n", incrementa, (x+conta)-size, (x+conta)-size, string_valor);
                string_valor++;
                incrementa++;
                free(aux_string);
            }
        }else{
            create_expressions(aux->childs[0], table);
            if(strcmp(aux->childs[0]->annotation,"int") == 0){
                printf("%%.%d = call i32 (i8*, ...) @printf(i8* getelementptr ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %%.%d)\n",incrementa,incrementa-1);
                incrementa++;
            }
            else if(strcmp(aux->childs[0]->annotation,"double") == 0){
                printf("%%.%d = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %%.%d)\n",incrementa,incrementa-1);
                incrementa++;
            }
            else if(strcmp(aux->childs[0]->annotation,"boolean") == 0){
                printf("br i1 %%.%d, label %%then%d, label %%else%d\n",incrementa-1,label_incrementa,label_incrementa);
                //incrementa++;
                printf("then%d:\n",label_incrementa);
                printf("%%.%d = call i32 (i8*, ...) @printf(i8* getelementptr ([5 x i8], [5 x i8]* @.str.true, i32 0, i32 0))\n",incrementa);
                incrementa++;
                printf("br label %%ifCont%d\n",label_incrementa);
                printf("else%d:\n",label_incrementa);
                printf("%%.%d = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.false, i32 0, i32 0))\n",incrementa);
                incrementa++;
                printf("br label %%ifCont%d\n",label_incrementa);
                printf("ifCont%d:\n",label_incrementa);
                label_incrementa++;
            }
        }
    }
    else if (strcmp(aux->type, "Return") == 0){//expr ou nada
        if(aux->index_childs > 0){
            create_expressions(aux->childs[0], table);
            if(strcmp(aux->childs[0]->annotation, "int") == 0){
                printf("ret i32 %%.%d\n",incrementa-1);
            }
            else if(strcmp(aux->childs[0]->annotation, "double") == 0){
                printf("ret double %%.%d\n",incrementa-1);
            }
            else if(strcmp(aux->childs[0]->annotation, "boolean") == 0){
                printf("ret i1 %%.%d\n",incrementa-1);
            }
        }
    }
}

void create_return(struct node *node){
    /*
        ret i32 0 -> int
        ret void -> void
        ret double 0 -> double
    */
    if(strcmp(node->childs[0]->type,"Int") == 0){
        printf("ret i32 0\n");
    }
    else if(strcmp(node->childs[0]->type,"Double") == 0){
        printf("ret double 0.0\n");
    }
    else if(strcmp(node->childs[0]->type,"Bool") == 0){
        printf("ret i1 0\n");
    }
    else if(strcmp(node->childs[0]->type,"Void") == 0){
        printf("ret void\n");
    }/*else{
        printf("ret void 0\n");
    }*/
}

void create_expressions(struct node *node, table_element *table){
      //printf("Entrei expression\n");
    //recebe o pai
    struct node *aux = node;
    if(strcmp(aux->type, "Add") == 0){//2filhos
        /*
            %.4 = load i32, i32* %i
            %.5 = add i32 0, 1
            %.6 = add i32 %.4, %.5
            %.6 = sitofp i32 %.4 to double
            i+1
        */
        create_expressions(aux->childs[0], table);
        int x1 = incrementa;
        create_expressions(aux->childs[1], table);
        int x2 = incrementa;
        //printf("1: %s\n",aux->childs[0]->annotation);
        //printf("2: %s\n",aux->childs[1]->annotation);
        if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x1-1);
            incrementa++;
            printf("%%.%d = fadd double %%.%d, %%.%d\n",incrementa, incrementa-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x2-1);
            incrementa++;
            printf("%%.%d = fadd double %%.%d, %%.%d\n",incrementa, x1-1 , incrementa-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = fadd double %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = add i32 %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
    }
    else if(strcmp(aux->type, "Sub") == 0){//2filhos
        create_expressions(aux->childs[0], table);
        int x1 = incrementa;
        create_expressions(aux->childs[1], table);
        int x2 = incrementa;
        if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x1-1);
            incrementa++;
            printf("%%.%d = fsub double %%.%d, %%.%d\n",incrementa, incrementa-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x2-1);
            incrementa++;
            printf("%%.%d = fsub double %%.%d, %%.%d\n",incrementa, x1-1 , incrementa-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = fsub double %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = sub i32 %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }

    }
    else if(strcmp(aux->type, "Mul") == 0){//2filhos
        create_expressions(aux->childs[0], table);
        int x1 = incrementa;
        create_expressions(aux->childs[1], table);
        int x2 = incrementa;
        if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x1-1);
            incrementa++;
            printf("%%.%d = fmul double %%.%d, %%.%d\n",incrementa, incrementa-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x2-1);
            incrementa++;
            printf("%%.%d = fmul double %%.%d, %%.%d\n",incrementa, x1-1 , incrementa-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = fmul double %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = mul i32 %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }

    }
    else if(strcmp(aux->type, "Div") == 0){//2filhos
        create_expressions(aux->childs[0], table);
        int x1 = incrementa;
        create_expressions(aux->childs[1], table);
        int x2 = incrementa;
        if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x1-1);
            incrementa++;
            printf("%%.%d = fdiv double %%.%d, %%.%d\n",incrementa, incrementa-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x2-1);
            incrementa++;
            printf("%%.%d = fdiv double %%.%d, %%.%d\n",incrementa, x1-1 , incrementa-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = fdiv double %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = sdiv i32 %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }

    }
    else if(strcmp(aux->type, "Mod") == 0){//2filhos
        create_expressions(aux->childs[0], table);
        int x1 = incrementa;
        create_expressions(aux->childs[1], table);
        int x2 = incrementa;
        if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x1-1);
            incrementa++;
            printf("%%.%d = frem double %%.%d, %%.%d\n",incrementa, incrementa-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x2-1);
            incrementa++;
            printf("%%.%d = frem double %%.%d, %%.%d\n",incrementa, x1-1 , incrementa-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = frem double %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = srem i32 %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }

    }
    else if(strcmp(aux->type, "And") == 0){//2filhos
        create_expressions(aux->childs[0], table);
        int x1 = incrementa;
        create_expressions(aux->childs[1], table);
        int x2 = incrementa;
        printf("%%.%d = and i1 %%.%d, %%.%d\n", incrementa, x1-1, x2-1);
        incrementa++;

    }
    else if(strcmp(aux->type, "Or") == 0){//2filhos
        create_expressions(aux->childs[0], table);
        int x1 = incrementa;
        create_expressions(aux->childs[1], table);
        int x2 = incrementa;
        printf("%%.%d = or i1 %%.%d, %%.%d\n", incrementa, x1-1, x2-1);
        incrementa++;

    }
    else if(strcmp(aux->type, "Xor") == 0){//2filhos
        create_expressions(aux->childs[0], table);
        int x1 = incrementa;
        create_expressions(aux->childs[1], table);
        int x2 = incrementa;
        printf("%%.%d = xor i1 %%.%d, %%.%d\n", incrementa, x1-1, x2-1);
        incrementa++;

    }
    else if(strcmp(aux->type, "Lshift") == 0){//2filhos
        create_expressions(aux->childs[0], table);
        int x1 = incrementa;
        create_expressions(aux->childs[1], table);
        int x2 = incrementa;
        if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x1-1);
            incrementa++;
            printf("%%.%d = shl double %%.%d, %%.%d\n",incrementa, incrementa-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x2-1);
            incrementa++;
            printf("%%.%d = shl double %%.%d, %%.%d\n",incrementa, x1-1 , incrementa-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = shl double %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = shl i32 %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
    }
    else if(strcmp(aux->type, "Rshift") == 0){//2filhos
        create_expressions(aux->childs[0], table);
        int x1 = incrementa;
        create_expressions(aux->childs[1], table);
        int x2 = incrementa;
        if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x1-1);
            incrementa++;
            printf("%%.%d = lshr double %%.%d, %%.%d\n",incrementa, incrementa-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x2-1);
            incrementa++;
            printf("%%.%d = lshr double %%.%d, %%.%d\n",incrementa, x1-1 , incrementa-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = lshr double %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = lshr i32 %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
    }
    else if(strcmp(aux->type, "Eq") == 0){//2filhos
        create_expressions(aux->childs[0], table);
          //      printf("FAZE ESTE\n");
        int x1 = incrementa;
        //printf("FAZE ESTE\n");
        create_expressions(aux->childs[1], table);
        int x2 = incrementa;
        if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x1-1);
            incrementa++;
            printf("%%.%d = fcmp oeq double %%.%d, %%.%d\n",incrementa, incrementa-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x2-1);
            incrementa++;
            printf("%%.%d = fcmp oeq double %%.%d, %%.%d\n",incrementa, x1-1 , incrementa-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = fcmp oeq double %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = icmp eq i32 %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
    }
    else if(strcmp(aux->type, "Ge") == 0){//2filhos
        create_expressions(aux->childs[0], table);
        int x1 = incrementa;
        create_expressions(aux->childs[1], table);
        int x2 = incrementa;
        if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x1-1);
            incrementa++;
            printf("%%.%d = fcmp oge double %%.%d, %%.%d\n",incrementa, incrementa-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x2-1);
            incrementa++;
            printf("%%.%d = fcmp oge double %%.%d, %%.%d\n",incrementa, x1-1 , incrementa-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = fcmp oge double %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = icmp sge i32 %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
    }
    else if(strcmp(aux->type, "Gt") == 0){//2filhos
        create_expressions(aux->childs[0], table);
        int x1 = incrementa;
        create_expressions(aux->childs[1], table);
        int x2 = incrementa;
        if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x1-1);
            incrementa++;
            printf("%%.%d = fcmp ogt double %%.%d, %%.%d\n",incrementa, incrementa-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x2-1);
            incrementa++;
            printf("%%.%d = fcmp ogt double %%.%d, %%.%d\n",incrementa, x1-1 , incrementa-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = fcmp ogt double %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = icmp sgt i32 %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
    }
    else if(strcmp(aux->type, "Le") == 0){//2filhos
        create_expressions(aux->childs[0], table);
        int x1 = incrementa;
        create_expressions(aux->childs[1], table);
        int x2 = incrementa;
        if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x1-1);
            incrementa++;
            printf("%%.%d = fcmp ole double %%.%d, %%.%d\n",incrementa, incrementa-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x2-1);
            incrementa++;
            printf("%%.%d = fcmp ole double %%.%d, %%.%d\n",incrementa, x1-1 , incrementa-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = fcmp ole double %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = icmp sle i32 %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
    }
    else if(strcmp(aux->type, "Lt") == 0){//2filhos
        create_expressions(aux->childs[0], table);
        int x1 = incrementa;
        create_expressions(aux->childs[1], table);
        int x2 = incrementa;
        if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x1-1);
            incrementa++;
            printf("%%.%d = fcmp olt double %%.%d, %%.%d\n",incrementa, incrementa-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x2-1);
            incrementa++;
            printf("%%.%d = fcmp olt double %%.%d, %%.%d\n",incrementa, x1-1 , incrementa-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = fcmp olt double %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = icmp slt i32 %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
    }
    else if(strcmp(aux->type, "Ne") == 0){//2filhos
        create_expressions(aux->childs[0], table);
        int x1 = incrementa;
        create_expressions(aux->childs[1], table);
        int x2 = incrementa;
        if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x1-1);
            incrementa++;
            printf("%%.%d = fcmp one double %%.%d, %%.%d\n",incrementa, incrementa-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = sitofp i32 %%.%d to double\n",incrementa, x2-1);
            incrementa++;
            printf("%%.%d = fcmp one double %%.%d, %%.%d\n",incrementa, x1-1 , incrementa-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0 && strcmp(aux->childs[1]->annotation, "double") == 0){
            printf("%%.%d = fcmp one double %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "int") == 0 && strcmp(aux->childs[1]->annotation, "int") == 0){
            printf("%%.%d = icmp ne i32 %%.%d, %%.%d\n",incrementa, x1-1 , x2-1);
            incrementa++;
        }
    }
    else if(strcmp(aux->type, "Not") == 0){//1filho
    /*
    <result> = xor i32 %V, -1          ; yields i32:result = ~%V
    */
    create_expressions(aux->childs[0], table);
    int x1 = incrementa;
    printf("%%.%d = xor i32 %%.%d, -1\n", incrementa, x1-1);
    incrementa++;
    }
    else if(strcmp(aux->type, "Minus") == 0){//1filho
        /*
        <result> = sub i32 0, %val          ; yields i32:result = -%var
        */
        create_expressions(aux->childs[0], table);
        int x1 = incrementa;
        if(strcmp(aux->childs[0]->annotation, "int") == 0){
            printf("%%.%d = sub i32 0, %%.%d\n",incrementa, x1-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0){
            printf("%%.%d = fsub double 0.0, %%.%d\n",incrementa, x1-1);
            incrementa++;
        }
    }
    else if(strcmp(aux->type, "Plus") == 0){//1filho
        /*
        <result> = add i32 0, %val          ; yields i32:result = +%var
        */
        create_expressions(aux->childs[0], table);
        int x1 = incrementa;
        if(strcmp(aux->childs[0]->annotation, "int") == 0){
            printf("%%.%d = add i32 0, %%.%d\n",incrementa, x1-1);
            incrementa++;
        }
        else if(strcmp(aux->childs[0]->annotation, "double") == 0){
            printf("%%.%d = fadd double 0.0, %%.%d\n",incrementa, x1-1);
            incrementa++;
        }


    }
    else if(strcmp(aux->type, "Length") == 0){//1filho
        create_expressions(aux->childs[0], table);
        //int x1 = incrementa;
    }
    else if(strcmp(aux->type, "Id") == 0){//no so
        /*%.4 = load i32, i32* %i
        %.5 = load double, double* %j
        pode ser 2 tipos %nome se for variavel local ou @nome se for variavel global
        */
        if(strcmp(aux->annotation, "int") == 0){
            if(!verifica_local(aux, table) && verifica_global(aux)){
                printf("%%.%d = load i32 , i32* @%s_int\n",incrementa, aux->value);
            }else{
                printf("%%.%d = load i32 , i32* %%%s\n",incrementa, aux->value);
            }
            incrementa++;
        }
        else if(strcmp(aux->annotation, "double") == 0){
            if(!verifica_local(aux, table) && verifica_global(aux)){
                printf("%%.%d = load double , double* @%s_double\n",incrementa, aux->value);
            }
            else{
                printf("%%.%d = load double , double* %%%s\n",incrementa, aux->value);
            }
            incrementa++;
        }
        if(strcmp(aux->annotation, "boolean") == 0){
            if(!verifica_local(aux, table) && verifica_global(aux)){
                printf("%%.%d = load i1 , i1* @%s_bool\n",incrementa, aux->value);
            }
            else{
                printf("%%.%d = load i1 , i1* %%%s\n",incrementa, aux->value);
            }
            incrementa++;
        }
    }
    else if(strcmp(aux->type, "DecLit") == 0){//no so
        // %.5 = add i32 0, 1, pode ser tambem 2_2 = 22
        int x = strlen(aux->value);
        char * aux_string = (char *)malloc((x + x) * sizeof(char *));
        int j = 0;
        // printf("ENTREI %s %d\n", aux->value,x);
        for(int i = 0 ; i < x ; i++){
            if(aux->value[i] == '_'){
                i++;
            }
            else{
                aux_string[j] = aux->value[i];
                j++;
            }
        }
        aux_string[j] = '\0';
        //printf("\n%s\n",aux_string);
        printf("%%.%d = add i32 0, %s\n", incrementa, aux_string);
        free(aux_string);
        incrementa++;
    }
    else if(strcmp(aux->type, "RealLit") == 0){//no so
        // %.5 = add i32 0, 1
        // 11e32= 11mais 32 0. 0000 , cenas com ; else 11.2e12 = 11.20000000
        int x = strlen(aux->value);
        char * aux_string = (char *)malloc((x + x) * sizeof(char *));
        int j = 0;
        if(aux->value[j] == '.'){
            aux_string[j] = '0';
            strcat(aux_string,aux->value);
        }else{
            int adicionaponto = 1;
            for(int i = 0 ; i < x ; i++){
                if(aux->value[i] == '_'){
                    i++;
                }
                else if(aux->value[i] == '.'){
                    aux_string[j] = aux->value[i];
                    adicionaponto = 0;
                    j++;
                }
                else{
                    aux_string[j] = aux->value[i];
                    j++;
                }
            }
            if(adicionaponto == 1){
                aux_string[j] = '.';
                j++;
                aux_string[j] = '0';
                j++;
            }
        }
        aux_string[j] = '\0';
        double n = atof(aux_string);
        printf("%%.%d = fadd double 0.000000, %.16e\n", incrementa, n);
        incrementa++;
        free(aux_string);
    }
    else if(strcmp(aux->type, "BoolLit") == 0){//no so
        //%.1 = or i1 false, true
        printf("%%.%d = or i1 false, true\n",incrementa);
        incrementa++;
    }
    else if(strcmp(aux->type, "Call") == 0){//no so
        create_statements(aux, table);
    }
    else if(strcmp(aux->type, "ParseArgs") == 0){//no so
        create_statements(aux, table);
    }
    else if(strcmp(aux->type, "Assign") == 0){//no so
        create_statements(aux, table);
    }
}

int verifica_global(struct node *node){
      //printf("Entrei verifica\n");
    table_element *tabela_searching = global_table;
    table_element *procura_id_global = search_element(node->value, tabela_searching);
    if(procura_id_global != NULL){
        int tipo = procura_id_global->decl_type;
        if(tipo == 3){
            return 1;
        }
        tabela_searching = procura_id_global->next;
        if(tabela_searching == NULL){
            return 0;
        }
        procura_id_global = search_element(node->value, tabela_searching);
    }
    return 0;
}

int verifica_local(struct node *node, table_element *table){
    table_element *tabela_searching = table;
    if(table == global_table){
        return 0;
    }
    table_element *procura_id_local = search_element(node->value, tabela_searching);
    if(procura_id_local != NULL){
        int tipo = procura_id_local->decl_type;
        if(tipo == 0 && procura_id_local->line <= node->line){
            return 1;
        }
        tabela_searching = procura_id_local->next;
        if(tabela_searching == NULL){
            return 0;
        }
        procura_id_local = search_element(node->value, tabela_searching);
    }
    return 0;
}

void init_produce(struct node *node){
    printf("declare i32 @printf(i8*, ...)\n");
    printf("declare i32 @atoi(i8*)\n");
    printf("@.str.true = constant [5 x i8] c\"true\\00\"\n");
    printf("@.str.false = constant [6 x i8] c\"false\\00\"\n");
    printf("@.str.int = constant [3 x i8] c\"%%d\\00\"\n");
    printf("@.str.double = constant [6 x i8] c\"%%.16e\\00\"\n");
    string_valor = 0;
    print_search_strlits(node);
    //printf("@.str.0 = constant [2 x i8] c\"\\0A\\00\"\n");

}

void print_search_strlits(struct node *node){
    if(strcmp(node->type, "StrLit") == 0){
        int x = strlen(node->value);
        if(strcmp(node->value, "\n") == 0){
            //printf("eu sou o tonito\n");
            printf("@.str.%d = constant [2 x i8] c\"\\0A\\00\"\n",string_valor);
            string_valor++;
        }else{
            char * aux_string = (char *)malloc((x + x) * sizeof(char *));
            int j = 0;
            int size = 2;
            int conta = 0;
            //printf("\n%d\n",x);
            for(int i = 1; i < x-1; i++){//ignora os \"\"
                //printf("%s\n",node->value);
                //printf("%c\n",node->value[i]);
                if(node->value[i] == '\\'){
                    aux_string[j] = node->value[i];
                    j++;
                    if(node->value[i+1] == 'n'){
                        aux_string[j] = '0';
                        j++;
                        aux_string[j] = 'A';
                        j++;
                        i++;
                    }
                    else if(node->value[i+1] == 'f'){
                        aux_string[j] = '0';
                        j++;
                        aux_string[j] = 'C';
                        j++;
                        i++;
                    }
                    else if(node->value[i+1] == 'r'){
                        aux_string[j] = '0';
                        j++;
                        aux_string[j] = 'D';
                        j++;
                        i++;
                    }
                    else if(node->value[i+1] == 't'){
                        aux_string[j] = '0';
                        j++;
                        aux_string[j] = '9';
                        j++;
                        i++;
                    }
                    else if(node->value[i+1] == '\\'){
                        aux_string[j] = '5';
                        j++;
                        aux_string[j] = 'C';
                        j++;
                        i++;
                    }
                    else if(node->value[i+1] == '\"'){
                        aux_string[j] = '2';
                        j++;
                        aux_string[j] = '2';
                        j++;
                        i++;
                    }
                    size++;
                }
                else if(node->value[i] == '%'){
                    aux_string[j] = '%';
                    j++;
                    aux_string[j] = '%';
                    j++;
                    conta++;
                }
                else{
                    aux_string[j] = node->value[i];
                    j++;
                }
            }
            aux_string[j] = '\0';
            j++;
            x = x +1;
            printf("@.str.%d = constant [%d x i8] c\"%s\\00\"\n",string_valor,(x+conta)-size,aux_string);
            string_valor++;
            free(aux_string);
        }
    }else{
        for(int i = 0; i < node->index_childs;i++){
            print_search_strlits(node->childs[i]);
        }
    }
}