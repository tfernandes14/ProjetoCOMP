%{
    // yacc -d jucompiler.y ---> Gerar o "y.tab.c" e o respetivo header
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include "structures.h"
    #define NSYMS 100

    symtab tab[NSYMS];

    node *head = NULL;

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

%token <str> INTLIT REALLIT BOOLLIT RESERVED ID STRLIT

%type <node> Program ProgramOpt MethodDecl FieldDecl FieldDeclOpt Type MethodHeader MethodHeaderOpt2 FormalParams
%type <node> FormalParamsOpt MethodBody MethodBody2 VarDecl VarDeclOpt Statement StatementOpt StatementOpt2 StatementOpt3
%type <node> StatementOpt4 StatementOpt5 MethodInvocation MethodInvocationOpt MethodInvocationOpt2
%type <node> Assignment ParseArgs Expr DotLengthOpt

%%

Program:    CLASS ID LBRACE ProgramOpt RBRACE   {
                                                    head = create_node("Program", "");
                                                    if ($4 != NULL){
                                                        add_child(head, $4);
                                                    }
                                                    $$ = head;
                                                }
    ;

ProgramOpt: MethodDecl ProgramOpt   {
                                        if ($2 != NULL){
                                            add_bro($1, $2);
                                        }
                                        $$ = $1;
                                    }
                                    
    |       FieldDecl ProgramOpt    {
                                        if ($2 != NULL){
                                            add_bro($1, $2);
                                        }
                                        $$ = $1;
                                    }

    |       SEMICOLON ProgramOpt    {}

    |                               {$$ = NULL;}
    ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody   {
                                                        node *methoddecl = create_node("MethodDecl", "");
                                                        add_child(methoddecl, $3);
                                                        add_child(methoddecl, $4);
                                                        add_bro($3, $4);
                                                        $$ = methoddecl;
                                                    }
    ;

FieldDecl:  PUBLIC STATIC Type ID FieldDeclOpt SEMICOLON    {
                                                                    node *fielddecl = create_node("FieldDecl", "");
                                                                    add_child(fielddecl, $3);
                                                                    add_child(fielddecl, $4);
                                                                    add_bro($3, $4);
                                                                    if($5 != NULL){
                                                                        add_child(fielddecl, $5);
                                                                        add_bro($3, $5);
                                                                        add_bro($4, $5);
                                                                    }
                                                                    $$ = fielddecl;
                                                            }
    ;
    
FieldDeclOpt:   COMMA ID FieldDeclOpt      {
                                                node *id = create_node("Id", $2);
                                                if($3 != NULL){
                                                    $$ = add_bro(id, $3);
                                                }
                                                else{
                                                    $$ = id;
                                                }
                                            }
    |                                       {$$ = NULL;}
    ;

Type:       BOOL            {$$ = create_node("Bool", "");}
    |       INT             {$$ = create_node("Int", "");}
    |       DOUBLE          {$$ = create_node("Double", "");}
    ;

MethodHeader:   Type ID LPAR MethodHeaderOpt2 RPAR      {
                                                            node *methodheader = create_node("MethodHeader","");
                                                            node *id = create_node("Id",$2);
                                                            add_child(methodheader,id);
                                                            if($4 != NULL){
                                                                add_child(methodheader,$4);
                                                            }
                                                            $$ = methodheader;
                                                        }
    |           VOID ID LPAR MethodHeaderOpt2 RPAR      {
                                                            node *methodheader = create_node("MethodHeader","");
                                                            node *id = create_node("Id",$2);
                                                            add_child(methodheader,id);
                                                            if($4 != NULL){
                                                                add_child(methodheader,$4);
                                                            }
                                                            $$ = methodheader;
                                                        }
    ;
    
MethodHeaderOpt2:   FormalParams        {
                                            if($1 != NULL){
                                                $$ = $1;
                                            }
                                            else{
                                                $$ = NULL;
                                            }
                                        }
    |                                   {$$ = NULL;}
    ;

FormalParams:   Type ID FormalParamsOpt     {
                                                node *parametros = create_node("MethodParams","");
                                                node *paramsDecl = create_node("ParamDecl","");
                                                node *id = create_node("Id",$2);
                                                add_child(parametros,paramsDecl);
                                                add_child(paramsDecl,$1);
                                                add_child(paramsDecl,id);
                                                add_bro($1,$2);
                                                if($3 != NULL){
                                                    add_child(parametros,$3);
                                                    add_bro(paramsDecl,$3);
                                                } 
                                                $$ = parametros;
                                            }
    |           STRING LSQ RSQ ID           {
                                                node *parametros = create_node("MethodParams","");
                                                node *paramsDecl = create_node("ParamDecl","");
                                                node *string = create_node("String","");
                                                node *id = create_node("id",$4);
                                                add_child(parametros,paramsDecl);
                                                add_child(paramsDecl,string);
                                                add_child(paramsDecl,id);
                                                add_bro(string,id);
                                                $$ = parametros;
                                            }
    ;

FormalParamsOpt:    COMMA Type ID FormalParamsOpt       {
                                                            node *paramsDecl = create_node("ParamDecl","");
                                                            node *id = create_node("Id",$3);
                                                            add_child(paramsDecl,$2);
                                                            add_child(paramsDecl, id);
                                                            add_bro($2,id);
                                                            if($4 != NULL){
                                                                $$ = add_bro(paramsDecl, $4);               
                                                            }
                                                            else{
                                                                $$ = paramsDecl;
                                                            }               
                                                        }
    |                                                   {$$ = NULL;}
    ;

MethodBody:     LBRACE MethodBody2 RBRACE   {
                                                    node *methodbody = create_node("MethodBody","");
                                                    if($2 != NULL){
                                                        add_child(methodbody,$2);
                                                    }
                                                    $$ = methodbody;
                                            }
    ;

MethodBody2:    Statement MethodBody2       {
                                                if($2 != NULL){
                                                    $$ = add_bro($1, $2);
                                                }
                                                else{
                                                    $$ = $1;
                                                }
                                            }
    |           VarDecl MethodBody2         {
                                                if($2 != NULL){
                                                    $$ = add_bro($1, $2);
                                                }
                                                else{
                                                    $$ = $1;
                                                }
                                                
                                            }
    |                                       {$$ = NULL;}
    ;

VarDecl:    Type ID VarDeclOpt SEMICOLON    {
                                                node *vardecl = create_node("VarDecl", "");
                                                if ($2 != NULL && $3 != NULL){
                                                    add_child(vardecl, $2);
                                                    add_child(vardecl, $3);
                                                    add_bro($2, $3);
                                                }
                                                $$ = vardecl;
                                            }
    ;

VarDeclOpt: COMMA ID VarDeclOpt     {
                                        if ($3 != NULL){
                                            $$ = add_bro($2, $3);
                                        }
                                        else{
                                            $$ = NULL;
                                        }
                                    }
    |                               {$$ = NULL;}
    ;

Statement:  LBRACE StatementOpt RBRACE                  {
                                                            if ($2 != NULL && $2->bro != NULL){
                                                                node *block = create_node("Block", "");
                                                                add_child(block, $2);
                                                                $$ = block;
                                                            }
                                                            else{
                                                                $$ = $2;
                                                            }
                                                        }

    |       IF LPAR Expr RPAR Statement StatementOpt2   {
                                                            node *iff = create_node("If", "");
                                                            if ($3 != NULL){
                                                                add_child(iff, $3);
                                                            }
                                                            node *block = create_node("Block", "");
                                                            if ($5 != NULL){
                                                                add_child(block, $5);
                                                            }
                                                            if ($6 != NULL){
                                                                add_bro(if, $6);
                                                            }
                                                            $$ = iff;
                                                        }
                                                        
    |       WHILE LPAR Expr RPAR Statement              {
                                                            node *whilee = create_node("While", "");
                                                            if ($3 != NULL){
                                                                add_child(whilee, $3);
                                                            }
                                                            node *block = create_node("Block", "");
                                                            if ($5 != NULL){
                                                                add_child(block, $5);
                                                            }
                                                            $$ = whilee;
                                                        }

    |       RETURN StatementOpt3 SEMICOLON              {
                                                            node *return = create_node("Return", "");
                                                            if ($2 != NULL){
                                                                add_child(return, $2);
                                                            }
                                                            $$ = return;
                                                        }

    |       StatementOpt4 SEMICOLON                     {
                                                            if ($1 != NULL){
                                                                $$ = $1;
                                                            }
                                                        }

    |       PRINT LPAR StatementOpt5 RPAR SEMICOLON     {
                                                            node *print = create_node("Print", "");
                                                            if ($3 != NULL){
                                                                add_child(print, $3);
                                                            }
                                                            $$ = print;
                                                        }
    ;

StatementOpt:   Statement StatementOpt      {
                                                if ($2 != NULL){
                                                    $$ = $1;
                                                }
                                                else{
                                                    $$ = NULL;
                                                }
                                            }

    |                                       {$$ = NULL;}
    ;

StatementOpt2:  ELSE Statement              {
                                                node *elsee = create_node("Else", "");
                                                if ($2 != NULL){
                                                    add_child(elsee, $2);
                                                }
                                                $$ = elsee;
                                            }
    |                                       {$$ = NULL;}
    ;

StatementOpt3:  Expr        {
                                if ($1 != NULL){
                                    $$ = $1;
                                }
                            }
    |                       {$$ = NULL;}
    ;

StatementOpt4:  MethodInvocation        {
                                            if ($1 != NULL){
                                                $$ = $1;
                                            }
                                        }
                                        
    |           Assignment              {
                                            if ($1 != NULL){
                                                $$ = $1;
                                            }
                                        }

    |           ParseArgs               {
                                            if ($1 != NULL){
                                                $$ = $1;
                                            }
                                        }
                                        
    |                                   {$$ = NULL;}
    ;

StatementOpt5:  Expr                    {
                                            if ($1 != NULL){
                                                $$ = $1;
                                            }
                                        }

    |           STRLIT                  {
                                            if ($1 != NULL){
                                                $$ = $1;
                                            }
                                        }
    ;

MethodInvocation:   ID LPAR MethodInvocationOpt RPAR        {
                                                                /* ns o que fazer aqui */
                                                            }
    ;

MethodInvocationOpt:    Expr MethodHeaderOpt2       {
                                                        /* ns o que fazer aqui */
                                                        if ($2 != NULL){
                                                            $$ = $2;
                                                        }
                                                        else{
                                                            $$ = NULL;
                                                        }
                                                    }
    |                                               {$$ = NULL;}
    ;

MethodInvocationOpt2:   COMMA Expr MethodInvocationOpt2     {
                                                                /* ns o que fazer aqui */
                                                                if ($3 != NULL){
                                                                    $$ = $3;
                                                                }
                                                                else{
                                                                    $$ = NULL;
                                                                }
                                                            }
    |                                                       {$$ = NULL;}
    ;

Assignment: ID ASSIGN Expr      {
                                    node *assign = create_node("Assign", "");
                                    add_child(assign, create_node("Id", $1));
                                    if ($3 != NULL){
                                        $$ = add_child(assign, $3);
                                    }
                                    else{
                                        $$ = NULL;
                                    }
                                }
    ;

ParseArgs:  PARSEINT LPAR ID LSQ Expr RSQ LPAR      {
                                                        node *parseargs = create_node("ParseArgs", "");
                                                        if ($3 != NULL){
                                                            add_child(parseargs, $3);
                                                        }
                                                        if ($5 != NULL){
                                                            add_child(parseargs, $5);
                                                            add_bro($3, $5);
                                                        }
                                                        $$ = parseargs;
                                                    }
    ;

Expr: LPAR Expr RPAR            {
                                    $$ = $2;
                                }

    | Expr PLUS Expr            {
                                    node *plus = create_node("Add", "");
                                    add_child(plus,$1);
                                    $$ = add_child(plus, $3);
                                }

    | Expr MINUS Expr           {
                                    node *minus = create_node("Sub", "");
                                    add_child(minus,$1);
                                    $$ = add_child(minus, $3);
                                }

    | Expr STAR Expr            {   
                                    node *star = create_node("Mul", "");
                                    add_child(star,$1);
                                    $$ = add_child(star, $3);
                                }

    | Expr DIV Expr             {
                                    node *div = create_node("Div", "");
                                    add_child(div,$1);
                                    $$ = add_child(div, $3);
                                }

    | Expr MOD Expr             {
                                    node *mod = create_node("Mod", "");
                                    add_child(mod,$1);
                                    $$ = add_child(mod, $3);
                                }

    | Expr AND Expr             {
                                    node *and = create_node("And", "");
                                    add_child(and,$1);
                                    $$ = add_child(and, $3);
                                }

    | Expr OR  Expr             {
                                    node *or = create_node("OR","");
                                    add_child(or,$1);
                                    $$ = add_child(or, $3);
                                }

    | Expr XOR Expr             {
                                    node *xor = create_node("Xor", "");
                                    add_child(xor, $1);
                                    $$ = add_child(xor, $3);
                                }

    | Expr LSHIFT Expr          {
                                    node *lshift = create_node("Lshift", "");
                                    add_child(lshift, $1);
                                    $$ = add_child(lshift, $3);
                                }

    | Expr RSHIFT Expr          {
                                    node *rshift = create_node("Rshift", "");
                                    add_child(rshift, $1);
                                    $$ = add_child(rshift, $3);
                                }

    | Expr EQ Expr              {
                                    node *eq = create_node("Eq", "");
                                    add_child(eq, $1);
                                    $$ = add_child(eq, $3);
                                }

    | Expr GE Expr              {                                    
                                    node *ge = create_node("Ge", "");
                                    add_child(ge, $1);
                                    $$ = add_child(ge, $3);
                                }   

    | Expr GT Expr              {
                                    node *gt = create_node("Gt", "");
                                    add_child(gt, $1);
                                    $$ = add_child(gt, $3);
                                }

    | Expr LE Expr              {
                                    node *le = create_node("Le", "");
                                    add_child(le, $1);
                                    $$ = add_child(le, $3);
                                } 

    | Expr LT Expr              {
                                    node *lt = create_node("Lt", "");
                                    add_child(lt, $1);
                                    $$ = add_child(lt, $3);
                                }

    | Expr NE Expr              {
                                    node *ne = create_node("Ne", "");
                                    add_child(ne, $1);
                                    $$ = add_child(ne, $3);
                                }

    | MINUS Expr                {
                                    node *minus = create_node("Minus", "");
                                    add_child(minus, minus);
                                    $$ = add_child(minus, $2);
                                }

    | NOT Expr                  {
                                    node *not = create_node("Not", "");
                                    add_child(div, not);
                                    $$ = add_child(not, $2);
                                }
                                 
    | PLUS Expr             {
                                node *plus = create_node("Plus", "");
                                add_child(plus, plus);
                                $$ = add_child(plus, $2);
                            }
                             
    | MethodInvocation          {
                                    if ($1 != NULL){
                                        $$ = $1;
                                    }
                                }

    | Assignment                {
                                    if ($1 != NULL){
                                        $$ = $1;
                                    }
                                }
                                
    | ParseArgs                 {
                                    if ($1 != NULL){
                                        $$ = $1;
                                    }
                                }
                                
    | ID DotLengthOpt      {
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

DotLengthOpt:  DOTLENGTH    {$$ = create_node("DotLength", "");}
|                           {$$ = NULL;}
    ;
%%

int main(int argc, char **argv){
    if (argc > 1){
        if (strcmp(argv[1], "-l") == 0){
            yylex();
        }

        if (strcmp(argv[1], "-t") == 0){
            yyparse();
            print_tree(head, 0);
        }

        if (strcmp(argv[1], "-debug") == 0){
            yyparse();    
        }
    }
    else{
        yyparse();
    }
    yylex_destroy();
    return 0;
}