%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include "symtab.h"
    #define NSYMS 100

    symtab tab[NSYMS];

    symtab *symlook(char *varname);
    void print_tabelita();
    float powerzito(float a, float b);
    int yylex(void);
    void yyerror (const char *s);
%}

%union{
    char *str;
    struct node *node;
}

%token AND ASSIGN STAR COMMA DIV EQ GE GT IF LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ
%token SEMICOLON ARROW LSHIFT RSHIFT XOR BOOL CLASS DOTLENGTH DOUBLE ELSE INT PRINT PARSEINT PUBLIC RETURN 
%token STATIC STRING VOID WHILE

%token <str> INTLIT REALLIT BOOLLIT RESERVED ID

%type <node> 

%left '+' '-'
%left '*' '/'
%left '^'
%left '(' ')'
%right '='

%%

Program:    CLASS ID LBRACE ProgramOpt RBRACE   {}
    ;

ProgramOpt: MethodDecl ProgramOpt   {}
    |       FieldDecl ProgramOpt    {}
    |       SEMICOLON ProgramOpt    {}
    |                               {$$ = NULL;}
    ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody   {}
    ;

FieldDecl:  PUBLIC STATIC Type ID FieldDeclOpt SEMICOLON    {}
    ;
    
FieldDeclOpt:   COMMA ID FieldDeclOpt   {}
    |                                   {$$ = NULL;}
    ;

Type:       BOOL | INT | DOUBLE     {}
    ;

MethodHeader:   MethodHeaderOpt ID LPAR MethodHeaderOpt2 RPAR   {}
    ;
    
MethodHeaderOpt:    Type        {}
    |               VOID        {}
    ;

MethodHeaderOpt2:   FormalParams     {}
    |                               {$$ = NULL;}
    ;

FormalParams:   Type ID FormalParamsOpt     {}
    |           STRING LSQ RSQ ID           {}
    ;

FormalParamsOpt:    COMMA Type ID FormalParamsOpt       {}
    |                                                   {$$ = NULL;}
    ;

MethodBody:     LBRACE MethodBody2 RBRACE   {}
    ;

MethodBody2:    Statement MethodBody2       {}
    |           VarDecl MethodBody2         {}
    |                                       {$$ = NULL;}
    ;

VarDecl:    Type ID VarDeclOpt SEMICOLON  {}
    ;

VarDeclOpt: COMMA ID VarDeclOpt     {}
    |                               {$$ = NULL;}
    ;

Statement:  LBRACE StatementOpt RBRACE                                  {}
    |       IF LPAR Expr RPAR Statement StatementOpt2                   {}
    |       WHILE LPAR Expr RPAR Statement                              {}
    |       RETURN StatementOpt3 SEMICOLON                              {}
    |       StatementOpt4 SEMICOLON                                     {}
    |       PRINT LPAR StatementOpt5 RPAR SEMICOLON                     {}
    ;

StatementOpt:   Statement StatementOpt      {}
    |                                       {$$ = NULL;}
    ;

StatementOpt2:  ELSE Statement              {}
    |                                       {$$ = NULL;}
    ;

StatementOpt3:  Expr        {}
    |                       {$$ = NULL;}
    ;

StatementOpt4:  MethodInvocation        {}
    |           Assignment              {}
    |           ParseArgs               {}
    |                                   {$$ = NULL;}
    ;

StatementOpt5:  Expr                     {}
    |           STRLIT                   {}
    ;

MethodInvocation:   ID LPAR MethodInvocationOpt RPAR        {}
    ;

MethodInvocationOpt:    Expr MethodHeaderOpt2       {}
    |                                               {$$ = NULL;}
    ;

MethodInvocationOpt2:   COMMA Expr MethodInvocationOpt2     {}
    |                                                       {$$ = NULL;}
    ;

Assignment: ID ASSIGN Expr      {
                                    struct node *assign = create_node("Assign", "");
                                    add_child(assign, create_node("Id", $1));
                                    if ($3 != NULL){
                                        $$ = add_child(assign, $3);
                                    }
                                    else{
                                        $$ = NULL;
                                    }
                                    
                                }
    ;

ParseArgs:  PARSEINT LPAR ID LSQ Expr RSQ LPAR      {}
    ;

Expr: LPAR Expr RPAR            {
                                    $$ = $2;
                                }

    | Expr PLUS Expr            {
                                    struct node *plus = create_node("Add", "");
                                    add_child(plus,$1);
                                    $$ = add_child(plus, $3);
                                }

    | Expr MINUS Expr           {
                                    struct node *minus = create_node("Sub", "");
                                    add_child(minus,$1);
                                    $$ = add_child(minus, $3);
                                }

    | Expr STAR Expr            {   
                                    struct node *star = create_node("Mul", "");
                                    add_child(star,$1);
                                    $$ = add_child(star, $3);
                                }

    | Expr DIV Expr             {
                                    struct node *div = create_node("Div", "");
                                    add_child(div,$1);
                                    $$ = add_child(div, $3);
                                }

    | Expr MOD Expr             {
                                    struct node *mod = create_node("Mod", "");
                                    add_child(mod,$1);
                                    $$ = add_child(mod, $3);
                                }

    | Expr AND Expr             {
                                    struct node *and = create_node("And", "");
                                    add_child(and,$1);
                                    $$ = add_child(and, $3);
                                }

    | Expr OR  Expr             {
                                    struct node *or = create_node("OR","");
                                    add_child(or,$1);
                                    $$ = add_child(or, $3);
                                }

    | Expr XOR Expr             {
                                    struct node *xor = create_node("Xor", "");
                                    add_child(xor,$1);
                                    $$ = add_child(xor, $3);
                                }

    | Expr LSHIFT Expr          {
                                    struct node *lshift = create_node("Lshift", "");
                                    add_child(lshift,$1);
                                    $$ = add_child(lshift, $3);
                                }

    | Expr RSHIFT Expr          {
                                    struct node *rshift = create_node("Rshift", "");
                                    add_child(rshift,$1);
                                    $$ = add_child(rshift, $3);
                                }

    | Expr EQ Expr              {
                                    struct node *eq = create_node("Eq", "");
                                    add_child(eq,$1);
                                    $$ = add_child(eq, $3);
                                }

    | Expr GE Expr              {                                    
                                    struct node *ge = create_node("Ge", "");
                                    add_child(ge,$1);
                                    $$ = add_child(ge, $3);
                                }   

    | Expr GT Expr              {
                                    struct node *gt = create_node("Gt", "");
                                    add_child(gt,$1);
                                    $$ = add_child(gt, $3);
                                }

    | Expr LE Expr              {
                                    struct node *le = create_node("Le", "");
                                    add_child(le,$1);
                                    $$ = add_child(le, $3);
                                } 

    | Expr LT Expr              {
                                    struct node *lt = create_node("Lt", "");
                                    add_child(lt,$1);
                                    $$ = add_child(lt, $3);
                                }

    | Expr NE Expr              {
                                    struct node *ne = create_node("Ne", "");
                                    add_child(ne,$1);
                                    $$ = add_child(ne, $3);
                                }

    | MINUS Expr           {
                                    struct node *minus = create_node("Minus", "");
                                    add_child(minus,$1);
                                    $$ = add_child(minus, $3);
                                }

    | NOT Expr             {
                                    struct node *not = create_node("Not", "");
                                    add_child(div,$1);
                                    $$ = add_child(not, $3);
                                }
                                 
    | PLUS Expr            {
                                struct node *plus = create_node("Plus", "");
                                add_child(plus,$1);
                                $$ = add_child(plus, $3);
                            }
                             
    | MethodInvocation          {
                                    $$ = $1;
                                }

    | Assignment                {
                                    $$ = $1;
                                }
                                
    | ParseArgs                 {
                                    $$ = $1;
                                }
                                
    | ID DotLengthOpcional      {
                                     $$ = create_node("Id",$1);
                                }
                                
    | INTLIT                    {
                                    $$ = create_node("Int",$1);
                                }
                                
    | REALLIT                   {
                                     $$ = create_node("RealLit",$1);
                                }
                                
    | BOOLLIT                   {
                                     $$ = create_node("BoolLit",$1);
                                }
    ;

DotLengthOpcional:  DOTLENGTH   {$$ = $1;}
    |                           {$$ = NULL;}
    ;
%%

void print_tabelita(){
    int i;
    int j = 0;
    for(i=0; i < NSYMS;i++){
        if(tab[i].name){
            j++;
            printf("%s\t%d\n",tab[i].name,tab[i].value);
        }
    }
    if(j==0){
        printf("NAO EXISTE LINDAO\n");
    }
}

float powerzito(float a, float b){
    float res = 1;
    while (b != 0){
        res *= a;
        b--;
    }
    return res;
}

symtab *symlook(char *varname){
    int i;

    for(i=0; i < NSYMS; i++){
        if(tab[i].name && strcmp(varname, tab[i].name)==0)
            return &tab[i];
        if(!tab[i].name){
            tab[i].name=varname;
            return &tab[i];
        }
    }

    yyerror("variaveis a mais...");
    exit(1);
}