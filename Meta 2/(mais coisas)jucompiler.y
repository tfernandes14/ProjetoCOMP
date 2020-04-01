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

    int error_tag = 0;
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
%type <node> Assignment ParseArgs Expr DotLengthOpt /*StatementOpt2*/

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
                                                        struct node *methoddecl = create_node("MethodDecl", "");
                                                        add_child(methoddecl, $3);
                                                        add_child(methoddecl, $4);
                                                        add_bro($3, $4);
                                                        $$ = methoddecl;
                                                    }
    ;

FieldDecl:  PUBLIC STATIC Type ID FieldDeclOpt SEMICOLON    {
                                                                    struct node *fielddecl = create_node("FieldDecl", "");
                                                                    add_child(fielddecl, $3);
                                                                    struct node *id = create_node("Id",$4);
                                                                    add_child(fielddecl, id);
                                                                    add_bro($3, id);
                                                                    if($5 != NULL){
                                                                        add_child(fielddecl, $5);
                                                                        add_bro($3, $5);
                                                                        add_bro(id, $5);
                                                                    }
                                                                    $$ = fielddecl;
                                                            }
    ;
    
FieldDeclOpt:   COMMA ID FieldDeclOpt      {
                                                struct node *id = create_node("Id", $2);
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
                                                            struct node *methodheader = create_node("MethodHeader","");
                                                            struct node *id = create_node("Id",$2);
                                                            add_child(methodheader,id);
                                                            if($4 != NULL){
                                                                add_child(methodheader,$4);
                                                            }
                                                            $$ = methodheader;
                                                        }
    |           VOID ID LPAR MethodHeaderOpt2 RPAR      {
                                                            struct node *methodheader = create_node("MethodHeader","");
                                                            struct node *id = create_node("Id",$2);
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
                                                struct node *parametros = create_node("MethodParams","");
                                                struct node *paramsDecl = create_node("ParamDecl","");
                                                struct node *id = create_node("Id", $2);
                                                add_child(parametros, paramsDecl);
                                                add_child(paramsDecl, $1);
                                                add_child(paramsDecl, id);
                                                add_bro($1, id);
                                                if($3 != NULL){
                                                    add_child(parametros, $3);
                                                    add_bro(idd, $3);
                                                } 
                                                $$ = parametros;
                                            }
    |           STRING LSQ RSQ ID           {
                                                struct node *parametros = create_node("MethodParams","");
                                                struct node *paramsDecl = create_node("ParamDecl","");
                                                struct node *string = create_node("String","");
                                                struct node *id = create_node("id",$4);
                                                add_child(parametros,paramsDecl);
                                                add_child(paramsDecl,string);
                                                add_child(paramsDecl,id);
                                                add_bro(string,id);
                                                $$ = parametros;
                                            }
    ;

FormalParamsOpt:    COMMA Type ID FormalParamsOpt       {
                                                            struct node *paramsDecl = create_node("ParamDecl","");
                                                            struct node *id = create_node("Id",$3);
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
                                                    struct node *methodbody = create_node("MethodBody","");
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
                                                struct node *vardecl = create_node("VarDecl", "");
                                                if ($2 != NULL && $3 != NULL){
                                                    struct node *id = create_node("Id", $2);
                                                    add_child(vardecl, id);
                                                    add_child(vardecl, $3);
                                                    add_bro(id, $3);
                                                }
                                                $$ = vardecl;
                                            }
    ;

VarDeclOpt: COMMA ID VarDeclOpt     {
                                        if ($3 != NULL){
                                            struct node *id = create_node("Id", $2);
                                            $$ = add_bro(id, $3);
                                        }
                                        else{
                                            $$ = NULL;
                                        }
                                    }
    |                               {$$ = NULL;}
    ;

Statement:  LBRACE StatementOpt RBRACE                  {
                                                            if ($2 != NULL && $2->bros != NULL){
                                                                struct node *block = create_node("Block", "");
                                                                add_child(block, $2);
                                                                $$ = block;
                                                            }
                                                            else{
                                                                $$ = $2;
                                                            }
                                                        }

    /*|       IF LPAR Expr RPAR Statement StatementOpt2   {
                                                            struct node *iff = create_node("If", "");
                                                            if ($3 != NULL){
                                                                add_child(iff, $3);
                                                            }

                                                            if ($5 != NULL){
                                                                add_child(iff, $5);
                                                            }
                                                            if($6 != NULL) {
                                                                add_bro(iff, $6);
                                                            }
                                                            else{
                                                                $$ = iff;
                                                            }
                                                        }*/
                                                        
    |       WHILE LPAR Expr RPAR Statement              {
                                                            struct node *whilee = create_node("While", "");
                                                            if ($3 != NULL){
                                                                add_child(whilee, $3);
                                                            }
                                                            struct node *block = create_node("Block", "");
                                                            if ($5 != NULL){
                                                                add_child(block, $5);
                                                            }
                                                            $$ = whilee;
                                                        }

    |       RETURN StatementOpt3 SEMICOLON              {
                                                            struct node *returny = create_node("Return", "");
                                                            if ($2 != NULL){
                                                                add_child(returny, $2);
                                                            }
                                                            $$ = returny;
                                                        }

    |       StatementOpt4 SEMICOLON                     {
                                                            if ($1 != NULL){
                                                                $$ = $1;
                                                            }
                                                            else{
                                                                $$ = NULL;
                                                            }
                                                        }

    |       PRINT LPAR StatementOpt5 RPAR SEMICOLON     {
                                                            struct node *print = create_node("Print", "");
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

/*StatementOpt2:  ELSE Statement   {
                                                    struct node *block = create_node("Block", "");
                                                    if ($2 != NULL){
                                                        add_child(block, $2);
                                                    }
                                                    $$ = block;
                                                }
    |                                           {$$ = NULL;}
    ;*/

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
                                                $$ = create_node("StrLit", $1);
                                            }
                                        }
    ;

MethodInvocation:   ID LPAR MethodInvocationOpt RPAR        {
                                                                struct node *methodinv = create_node("MethodInvacation", "");
                                                                if ($3 != NULL){
                                                                    add_child(methodinv, $3);
                                                                }
                                                                $$ = methodinv;
                                                            }
    ;

MethodInvocationOpt:    Expr MethodInvocationOpt2       {
                                                        if ($1 != NULL && $2 == NULL){
                                                            $$ = $1;
                                                        }
                                                        else if($1 != NULL && $2 != NULL){
                                                            $$ = add_bro($1, $2);
                                                        }
                                                        else{
                                                            $$ = NULL;
                                                        }
                                                    }

    |                                               {$$ = NULL;}
    ;

MethodInvocationOpt2:   COMMA Expr MethodInvocationOpt2     {
                                                                if ($2 != NULL && $3 == NULL){
                                                                    $$ = $2;
                                                                }
                                                                else if( $2 != NULL && $3 != NULL){
                                                                    $$ = add_bro($2,$3);
                                                                }
                                                                else{
                                                                    $$ = NULL;
                                                                }
                                                            }

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

ParseArgs:  PARSEINT LPAR ID LSQ Expr RSQ LPAR      {
                                                        struct node *parseargs = create_node("ParseArgs", "");
                                                        
                                                        struct node * id = create_node("Id",$3); 
                                                        add_child(parseargs, id);
                                                        
                                                        
                                                        add_child(parseargs, $5);
                                                        add_bro(id, $5);
                                                        
                                                        $$ = parseargs;
                                                    }
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
                                    add_child(xor, $1);
                                    $$ = add_child(xor, $3);
                                }

    | Expr LSHIFT Expr          {
                                    struct node *lshift = create_node("Lshift", "");
                                    add_child(lshift, $1);
                                    $$ = add_child(lshift, $3);
                                }

    | Expr RSHIFT Expr          {
                                    struct node *rshift = create_node("Rshift", "");
                                    add_child(rshift, $1);
                                    $$ = add_child(rshift, $3);
                                }

    | Expr EQ Expr              {
                                    struct node *eq = create_node("Eq", "");
                                    add_child(eq, $1);
                                    $$ = add_child(eq, $3);
                                }

    | Expr GE Expr              {                                    
                                    struct node *ge = create_node("Ge", "");
                                    add_child(ge, $1);
                                    $$ = add_child(ge, $3);
                                }   

    | Expr GT Expr              {
                                    struct node *gt = create_node("Gt", "");
                                    add_child(gt, $1);
                                    $$ = add_child(gt, $3);
                                }

    | Expr LE Expr              {
                                    struct node *le = create_node("Le", "");
                                    add_child(le, $1);
                                    $$ = add_child(le, $3);
                                } 

    | Expr LT Expr              {
                                    struct node *lt = create_node("Lt", "");
                                    add_child(lt, $1);
                                    $$ = add_child(lt, $3);
                                }

    | Expr NE Expr              {
                                    struct node *ne = create_node("Ne", "");
                                    add_child(ne, $1);
                                    $$ = add_child(ne, $3);
                                }

    | MINUS Expr %prec UN     {
                                    struct node *minus = create_node("Minus", "");
                                    $$ = add_child(minus, $2);
                                }

    | NOT Expr %prec UN         {
                                    struct node *not = create_node("Not", "");
                                    $$ = add_child(not, $2);
                                }
                                 
    | PLUS Expr %prec UN        {
                                    struct node *plus = create_node("Plus", "");
                                    $$ = add_child(plus, $2);
                                }
                             
    | MethodInvocation          {
                                    if ($1 != NULL){
                                        $$ = $1;
                                    }
                                    else{
                                        $$ = NULL;
                                    }
                                }

    | Assignment                {
                                    if ($1 != NULL){
                                        $$ = $1;
                                    }
                                    else{
                                        $$ = NULL;
                                    }
                                }
                                
    | ParseArgs                 {
                                    if ($1 != NULL){
                                        $$ = $1;
                                    }
                                    else{
                                        $$ = NULL;
                                    }
                                }
                                
    | ID DotLengthOpt           {
                                    struct node *res = create_node("Id", $1);
                                    $$ = res;
                                }
                                
    | INTLIT                    {
                                    struct node *res = create_node("Int", $1);
                                    $$ = res;
                                }
                                
    | REALLIT                   {
                                    struct node *res = create_node("RealLit", $1);
                                    $$ = res;
                                }
                                
    | BOOLLIT                   {
                                    struct node *res = create_node("BoolLit", $1);
                                    $$ = res;
                                }
    ;

DotLengthOpt:  DOTLENGTH    {
                                struct node *res = create_node("DotLength", "");
                                $$ = res;
                            }
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