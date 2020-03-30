%{
    // yacc -d jucompiler.y ---> Gerar o "y.tab.c" e o respetivo header
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    //#include "structures.h"

    //struct node *head = NULL;

    int yylex(void);
    int yylex_destroy();
    void yyerror(char *s);

    int error_tag = 0, imprime = 0, erros = 0, return_flag = 0;
%}

%union{
    char *str;
    struct node *node;
}

%token AND ASSIGN STAR COMMA DIV EQ GE GT IF LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ
%token SEMICOLON ARROW LSHIFT RSHIFT XOR BOOL CLASS DOTLENGTH DOUBLE ELSE INT PRINT PARSEINT PUBLIC RETURN 
%token STATIC STRING VOID WHILE

%token <str> INTLIT REALLIT BOOLLIT RESERVED ID STRLIT

%type <node> Program ProgramOpt MethodDecl FieldDecl FieldDeclOpt Type MethodHeader MethodHeaderOpt2 FormalParams
%type <node> FormalParamsOpt MethodBody MethodBody2 VarDecl VarDeclOpt Statement StatementOpt StatementOpt3
%type <node> StatementOpt4 StatementOpt5 MethodInvocation MethodInvocationOpt MethodInvocationOpt2
%type <node> Assignment ParseArgs Expr

%left ARROW
%left COMMA
%right ASSIGN
%left OR
%left AND
%left XOR
%left GE LE LT GT EQ NE
%left LSHIFT RSHIFT
%left PLUS MINUS
%left STAR DIV MOD
%right NOT
%right LPAR LSQ LBRACE
%left RSQ RBRACE RPAR

%nonassoc IF
%nonassoc ELSE

%%

Program:    CLASS ID LBRACE ProgramOpt RBRACE   {
                                                    
                                                }
    ;

ProgramOpt: MethodDecl ProgramOpt   {
                                        
                                    }
    |       FieldDecl ProgramOpt    {
                                        
                                    }
    |       SEMICOLON ProgramOpt    {
                                        
                                    }
    |                               {
                                       
                                    }
    ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody   {
                                                        
                                                    }
    ;

FieldDecl:  PUBLIC STATIC Type ID FieldDeclOpt SEMICOLON    {}
    |       error SEMICOLON                                 {
                                                            }
    ;
    
FieldDeclOpt:   COMMA ID FieldDeclOpt       {}
    |                                       {}
    ;

Type:       BOOL            {}
    |       INT             {}
    |       DOUBLE          {}
    ;

MethodHeader:   Type ID LPAR MethodHeaderOpt2 RPAR      {}
    |           VOID ID LPAR MethodHeaderOpt2 RPAR      {}
    ;
    
MethodHeaderOpt2:   FormalParams        {}
    |                                   {}
    ;

FormalParams:   Type ID FormalParamsOpt     {}
    |           STRING LSQ RSQ ID           {}
    ;

FormalParamsOpt:    COMMA Type ID FormalParamsOpt       {}
    |                                                   {}
    ;

MethodBody:     LBRACE MethodBody2 RBRACE   {}
    ;

MethodBody2:    Statement MethodBody2       {}
    |           VarDecl MethodBody2         {}
    |                                       {}
    ;

VarDecl:    Type ID VarDeclOpt SEMICOLON    {}
    ;

VarDeclOpt: COMMA ID VarDeclOpt     {}
    |                               {}
    ;

Statement:  LBRACE StatementOpt RBRACE                  {}
    |       IF LPAR Expr RPAR Statement                 {}
    |       IF LPAR Expr RPAR Statement ELSE Statement  {}
    |       WHILE LPAR Expr RPAR Statement              {}
    |       RETURN StatementOpt3 SEMICOLON              {}
    |       StatementOpt4 SEMICOLON                     {}
    |       PRINT LPAR StatementOpt5 RPAR SEMICOLON     {}
    |       error SEMICOLON                             {}
    ;

StatementOpt:   Statement StatementOpt      {}
    |                                       {}
    ;

StatementOpt3:  Expr        {}
    |                       {}
    ;

StatementOpt4:  MethodInvocation        {}
    |           Assignment              {}
    |           ParseArgs               {}
    |                                   {}
    ;

StatementOpt5:  Expr                    {}
    |           STRLIT                  {}
    ;

MethodInvocation:   ID LPAR MethodInvocationOpt RPAR        {}
    |               ID LPAR error RPAR                      {}
    ;

MethodInvocationOpt:    Expr MethodInvocationOpt2       {}
    |                                                   {}
    ;

MethodInvocationOpt2:   COMMA Expr MethodInvocationOpt2     {}
    |                                                       {}
    ;

Assignment: ID ASSIGN Expr      {}
    ;

ParseArgs:  PARSEINT LPAR ID LSQ Expr RSQ RPAR      {}
    |       PARSEINT LPAR error RPAR                {}
    ;

Expr: LPAR Expr RPAR            {}
    | LPAR error RPAR           {}
    | Expr PLUS Expr            {}
    | Expr MINUS Expr           {}
    | Expr STAR Expr            {}
    | Expr DIV Expr             {}
    | Expr MOD Expr             {}
    | Expr AND Expr             {}
    | Expr OR  Expr             {}
    | Expr XOR Expr             {}
    | Expr LSHIFT Expr          {}
    | Expr RSHIFT Expr          {}
    | Expr EQ Expr              {}
    | Expr GE Expr              {}   
    | Expr GT Expr              {}
    | Expr LE Expr              {} 
    | Expr LT Expr              {}
    | Expr NE Expr              {}
    | NOT Expr                  {}
    | MINUS Expr %prec NOT      {}
    | PLUS Expr %prec NOT       {}
    | MethodInvocation          {}
    | Assignment                {}
    | ParseArgs                 {}
    | ID                        {}
    | ID DOTLENGTH              {}
    | INTLIT                    {}
    | REALLIT                   {}
    | BOOLLIT                   {}
    ;

%%

int main(int argc, char **argv){
    if (argc > 1){
        if (strcmp(argv[1], "-l") == 0){
            //imprime so os tokens da primeira; so analise lexical
            imprime = 1;
            erros = 1;
            yylex();
        }

        else if (strcmp(argv[1], "-t") == 0){
            // IMPRIMIR ARVORE, ja temos de dar os returns;
            return_flag = 1;
        }

        else if (strcmp(argv[1], "-e2") == 0){
            // So analise lexical e semantica, erros da segunda meta e primeira meta, ja temos de ter os returns
            erros = 1;
            return_flag = 1;
            yyparse();
        }

        else if (strcmp(argv[1], "-e1") == 0){
            //so analise lexical, erros primeira meta;
            erros = 1;
            yylex();
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