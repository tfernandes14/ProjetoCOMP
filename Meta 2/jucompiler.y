%{
    // yacc -d jucompiler.y ---> Gerar o "y.tab.c" e o respetivo header
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include "structures.h"

    struct node *head = NULL;

    int yylex(void);
    int yylex_destroy();
    void yyerror(const char *s);

    int error_tag = 0, imprime = 0, erros = 0;
%}

%union{
    char *str;
    struct node *node;
}

%token AND ASSIGN STAR COMMA DIV EQ GE GT IF LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ
%token SEMICOLON ARROW LSHIFT RSHIFT XOR BOOL CLASS DOTLENGTH DOUBLE ELSE INT PRINT PARSEINT PUBLIC RETURN 
%token STATIC STRING VOID WHILE UN

%token <str> INTLIT REALLIT BOOLLIT RESERVED ID STRLIT

%type <node> Program ProgramOpt MethodDecl FieldDecl FieldDeclOpt Type MethodHeader MethodHeaderOpt2 FormalParams
%type <node> FormalParamsOpt MethodBody MethodBody2 VarDecl VarDeclOpt Statement StatementOpt StatementOpt3
%type <node> StatementOpt4 StatementOpt5 MethodInvocation MethodInvocationOpt MethodInvocationOpt2
%type <node> Assignment ParseArgs Expr DotLengthOpt

%left COMMA
%right ASSIGN
%left OR
%left AND
%left LSHIFT RSHIFT XOR
%left GE LE LT GT EQ NE NOT
%left PLUS MINUS
%left STAR DIV MOD
%left UN
%left LPAR RPAR LSQ RSQ LBRACE RBRACE

%nonassoc IF
%nonassoc ELSE

%%

Program:    CLASS ID LBRACE ProgramOpt RBRACE   {}
    ;

ProgramOpt: MethodDecl ProgramOpt   {}
                                    
    |       FieldDecl ProgramOpt    {
                                    
                                    }

    |       SEMICOLON ProgramOpt    {}

    |                               {}
    ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody   {
                                                        
                                                    }
    ;

FieldDecl:  PUBLIC STATIC Type ID FieldDeclOpt SEMICOLON    {
                                                                    
                                                            }
    ;
    
FieldDeclOpt:   COMMA ID FieldDeclOpt      {
                                               
                                            }
    |                                       {}
    ;

Type:       BOOL            {}
    |       INT             {}
    |       DOUBLE          {}
    ;

MethodHeader:   Type ID LPAR MethodHeaderOpt2 RPAR      {
                                                           
                                                        }
    |           VOID ID LPAR MethodHeaderOpt2 RPAR      {
                                                      
                                                        }
    ;
    
MethodHeaderOpt2:   FormalParams        {
                                            
                                        }
    |                                   {}
    ;

FormalParams:   Type ID FormalParamsOpt     {
                                               
                                            }
    |           STRING LSQ RSQ ID           {
                                                
                                            }
    ;

FormalParamsOpt:    COMMA Type ID FormalParamsOpt       {
                                                           
                                                        }
    |                                                   {}
    ;

MethodBody:     LBRACE MethodBody2 RBRACE   {
                                                    
                                            }
    ;

MethodBody2:    Statement MethodBody2       {
                                               
                                            }
    |           VarDecl MethodBody2         {
                                              
                                                
                                            }
    |                                       {}
    ;

VarDecl:    Type ID VarDeclOpt SEMICOLON    {
                                                
                                            }
    ;

VarDeclOpt: COMMA ID VarDeclOpt     {
                                       
                                    }
    |                               {}
    ;

Statement:  LBRACE StatementOpt RBRACE                  {}
    |       IF LPAR Expr RPAR Statement                 {}
    |       IF LPAR Expr RPAR Statement ELSE Statement  {}
    |       WHILE LPAR Expr RPAR Statement              {}
    |       RETURN StatementOpt3 SEMICOLON              {}
    |       StatementOpt4 SEMICOLON                     {}
    |       PRINT LPAR StatementOpt5 RPAR SEMICOLON     {}
    ;

StatementOpt:   Statement StatementOpt      {}

    |                                       {}
    ;

StatementOpt3:  Expr        {}
    |                       {}
    ;

StatementOpt4:  MethodInvocation        {
                                        }
                                        
    |           Assignment              {
                                        }

    |           ParseArgs               {
                                        }
                                        
    |                                   {}
    ;

StatementOpt5:  Expr                    {
                                        }

    |           STRLIT                  {
                                        }
    ;

MethodInvocation:   ID LPAR MethodInvocationOpt RPAR        {
                                                            }
    ;

MethodInvocationOpt:    Expr MethodInvocationOpt2       {
                                                        }

    |                                               {}
    ;

MethodInvocationOpt2:   COMMA Expr MethodInvocationOpt2     {
                                                            }

    |                                                       {}
    ;

Assignment: ID ASSIGN Expr      {
                                }
    ;

ParseArgs:  PARSEINT LPAR ID LSQ Expr RSQ LPAR      {
                                                    }
    ;

Expr: LPAR Expr RPAR            {
                                }

    | Expr PLUS Expr            {
                                }

    | Expr MINUS Expr           {
                                }

    | Expr STAR Expr            {
                                }

    | Expr DIV Expr             {
                                }

    | Expr MOD Expr             {
                                }

    | Expr AND Expr             {
                                }

    | Expr OR  Expr             {
                                }

    | Expr XOR Expr             {
                                }

    | Expr LSHIFT Expr          {
                                }

    | Expr RSHIFT Expr          {
                                }

    | Expr EQ Expr              {
                                }

    | Expr GE Expr              {
                                }   

    | Expr GT Expr              {
                                }

    | Expr LE Expr              {
                                } 

    | Expr LT Expr              {
                                }

    | Expr NE Expr              {
                                }

    | MINUS Expr %prec UN       {
                                }

    | NOT Expr %prec UN         {
                                }
                                 
    | PLUS Expr %prec UN        {
                                }
                             
    | MethodInvocation          {
                                }

    | Assignment                {
                                }
                                
    | ParseArgs                 {
                                }
                                
    | ID DotLengthOpt           {
                                }
                                
    | INTLIT                    {
                                }
                                
    | REALLIT                   {
                                }
                                
    | BOOLLIT                   {
                                }
    ;

DotLengthOpt:  DOTLENGTH    {}
|                           {}
    ;
%%

int main(int argc, char **argv){
    if (argc > 1){
        if (strcmp(argv[1], "-l") == 0){
            //-l ou -e1 deverá apenas realizar a análise lexical emitir o resultado para o stdout (erros lexicais e no caso da opção -l também os tokens encontrados)
            imprime = 1;
            erros = 1;
            yylex();
        }

        else if (strcmp(argv[1], "-t") == 0){
            // IMPRIMIR ARVORE
        }

        else if (strcmp(argv[1], "-e2") == 0){
            // Erros da segunda meta
        }

        else if (strcmp(argv[1], "-e1") == 0){
            // Erros da primeira meta
            erros = 1;
            yylex();
            yyparse();
        }

        else{
            return 0;
        }
    }
    if (argc == 1){
        erros = 1;
        yylex();
    }
    return 0;
}