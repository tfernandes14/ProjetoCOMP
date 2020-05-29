%{
    // yacc -d jucompiler.y ---> Gerar o "y.tab.c" e o respetivo header
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include <unistd.h>
    #include "llvm.h"

    struct node *head = NULL;

    extern table_element * global_table;
    int error_tag = 0, imprime = 0, erros = 0, return_flag = 0, recursao = 0;
    char *tipo;
    int contador = 0;
    int yylex();
    void yyerror(const char *s);
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
%type <node> Assignment ParseArgs Expr Expr1

%left ARROW
%left COMMA
%right ASSIGN
%left OR
%left AND
%left XOR
%left NE EQ
%left GE LE LT GT
%left LSHIFT RSHIFT
%left PLUS MINUS
%left STAR DIV MOD
%right NOT
%left RSQ LSQ RPAR LPAR

%nonassoc IF
%nonassoc ELSE

%%

Program:    CLASS ID LBRACE ProgramOpt RBRACE   {
                                                    head = create_node("Program", "", 0, 0);
                                                    struct node *idd = create_node("Id", $2, @2.first_line, @2.first_column);
                                                    add_child(head, idd);
                                                    if ($4 != NULL){
                                                        add_bro(idd,$4);
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
    |       SEMICOLON ProgramOpt    {
                                        if ($2 != NULL){
                                            $$ = $2;
                                        }
                                        else{
                                            $$ = NULL;
                                        }
                                    }
    |       /* vazio */             {$$ = NULL;}
    ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody   {
                                                        struct node *methoddecl = create_node("MethodDecl", "", 0, 0);
                                                        add_child(methoddecl, $3);
                                                        add_child(methoddecl, $4);
                                                        add_bro($3, $4);
                                                        $$ = methoddecl;
                                                    }
    ;

FieldDecl:  PUBLIC STATIC Type ID FieldDeclOpt SEMICOLON    {
                                                                struct node *fielddecl = create_node("FieldDecl", "", 0, 0);
                                                                struct node *idd = create_node("Id", $4, @4.first_line, @4.first_column);
                                                                add_child(fielddecl, $3);
                                                                add_child(fielddecl, idd);
                                                                add_bro($3, idd);
                                                                if ($5 != NULL){
                                                                    add_bro(fielddecl, $5);
                                                                }
                                                                $$ = fielddecl;
                                                            }
    |       error SEMICOLON                                 {$$ = NULL;}
    ;
    
FieldDeclOpt:   COMMA ID FieldDeclOpt       {
                                                struct node *fielddecl = create_node("FieldDecl", "", 0, 0);
                                                struct node *typ = create_node(tipo, "", 0, 0);
                                                struct node *idd = create_node("Id", $2, @2.first_line, @2.first_column);
                                                add_child(fielddecl, typ);
                                                add_child(fielddecl, idd);
                                                add_bro(typ, idd);
                                                if ($3 != NULL){
                                                    add_bro(fielddecl, $3);
                                                }
                                                $$ = fielddecl;
                                                
                                            }
    |           /* vazio */                 {$$ = NULL;}
    ;

Type:       BOOL            {
                                struct node *booly = create_node("Bool", "", @1.first_line, @1.first_column);
                                tipo = "Bool";
                                $$ = booly;
                            }
    |       INT             {
                                struct node *inty = create_node("Int", "", @1.first_line, @1.first_column);
                                tipo = "Int";
                                $$ = inty;
                            }
    |       DOUBLE          {
                                struct node *doubley = create_node("Double", "", @1.first_line, @1.first_column);
                                tipo = "Double";
                                $$ = doubley;
                            }
    ;

MethodHeader:   Type ID LPAR MethodHeaderOpt2 RPAR      {
                                                            struct node *methodheader = create_node("MethodHeader", "", @1.first_line, @1.first_column);
                                                            struct node *parametros = create_node("MethodParams","", @2.first_line, @2.first_column);
                                                            struct node *idd = create_node("Id", $2, @2.first_line, @2.first_column);
                                                            add_child(methodheader, $1);
                                                            add_child(methodheader, idd);
                                                            add_child(methodheader, parametros);
                                                            add_child(parametros, $4);
                                                            add_bro($1, idd);
                                                            add_bro(idd, parametros);
                                                            $$ = methodheader;
                                                        }
    |           VOID ID LPAR MethodHeaderOpt2 RPAR      {
                                                            struct node *methodheader = create_node("MethodHeader", "", @1.first_line, @1.first_column);
                                                            struct node *parametros = create_node("MethodParams","", @2.first_line, @2.first_column);
                                                            struct node *voidy = create_node("Void", "", @1.first_line, @1.first_column);
                                                            struct node *idd = create_node("Id", $2, @2.first_line, @2.first_column);
                                                            add_child(methodheader, voidy);
                                                            add_child(methodheader, idd);
                                                            add_child(methodheader, parametros);
                                                            add_child(parametros, $4);
                                                            add_bro(voidy, idd);
                                                            add_bro(idd, parametros);
                                                            $$ = methodheader;
                                                        }
    ;
    
MethodHeaderOpt2:   FormalParams                    {
                                                        $$ = $1;
                                                    }
    |           /* funcao nao tem argumentos */     {$$ = NULL;}
    ;

FormalParams:   Type ID FormalParamsOpt     {
                                                struct node *paramsDecl = create_node("ParamDecl","", @1.first_line, @1.first_column);
                                                struct node *idd = create_node("Id", $2, @2.first_line, @2.first_column);
                                                add_child(paramsDecl, $1);
                                                add_child(paramsDecl, idd);
                                                add_bro($1, idd);
                                                if($3 != NULL){
                                                    add_bro(paramsDecl, $3);
                                                } 
                                                $$ = paramsDecl;
                                            }
    |           STRING LSQ RSQ ID           {
                                                struct node *paramsDecl = create_node("ParamDecl", "", @1.first_line, @1.first_column);
                                                struct node *string = create_node("StringArray", "", @1.first_line, @1.first_column);
                                                struct node *idd = create_node("Id",$4, @4.first_line, @4.first_column);
                                                add_child(paramsDecl, string);
                                                add_child(paramsDecl, idd);
                                                add_bro(string, idd);
                                                $$ = paramsDecl;
                                            }
    ;

FormalParamsOpt:    COMMA Type ID FormalParamsOpt       {
                                                            struct node *paramdecl = create_node("ParamDecl", "", @2.first_line, @2.first_column);
                                                            struct node *idd = create_node("Id", $3, @3.first_line, @3.first_column);
                                                            add_child(paramdecl, $2);
                                                            add_child(paramdecl, idd);
                                                            add_bro($2, idd);
                                                            if ($4 != NULL){
                                                                add_bro(paramdecl,$4);
                                                            }
                                                            $$ = paramdecl;
                                                            
                                                        }
    |                /* a funcao so tem um argumento */ {$$ = NULL;}
    ;

MethodBody:     LBRACE MethodBody2 RBRACE   {
                                                struct node *methodbody = create_node("MethodBody", "", @1.first_line, @1.first_column);
                                                if ($2 != NULL){
                                                    add_child(methodbody, $2);
                                                }
                                                $$ = methodbody;
                                            }
    ;

MethodBody2:    Statement MethodBody2       {
                                                if ($1 == NULL && $2 == NULL){
                                                    $$ = NULL;
                                                }
                                                else if ($1 == NULL){
                                                    $$ = $2;
                                                }
                                                else if ($2 == NULL){
                                                    $$ = $1;
                                                }
                                                else{
                                                    $$ = add_bro($1, $2);
                                                }

                                            }
    |           VarDecl MethodBody2         {
                                                if ($2 != NULL){
                                                    add_bro($1, $2);
                                                }
                                                $$ = $1;
                                            }
    |           /* vazio */                 {$$ = NULL;}
    ;

VarDecl:    Type ID VarDeclOpt SEMICOLON    {
                                                struct node *vardecl = create_node("VarDecl", "", @1.first_line, @1.first_column);
                                                struct node *idd = create_node("Id", $2, @2.first_line, @2.first_column);
                                                add_child(vardecl, $1);
                                                add_child(vardecl, idd);
                                                add_bro($1, idd);
                                                if($3 != NULL){
                                                    add_bro(vardecl, $3);
                                                }
                                                $$ = vardecl;
                                            }
    ;

VarDeclOpt: COMMA ID VarDeclOpt                     {
                                                        struct node *vardecl = create_node("VarDecl", "", @2.first_line, @2.first_column);
                                                        struct node *idd = create_node("Id", $2, @2.first_line, @2.first_column);
                                                        struct node *ty = create_node(tipo,"", 0, 0);
                                                        add_child(vardecl, ty);
                                                        add_child(vardecl, idd);
                                                        add_bro(ty, idd);
                                                        if ($3 != NULL){
                                                            add_bro(vardecl, $3);
                                                        }
                                                        $$ = vardecl;
                                                    }
    |       /* so tem um parametro definido */      {$$ = NULL;}
    ;

Statement:  LBRACE StatementOpt RBRACE                  {
                                                            if ($2 != NULL && $2->bros != NULL){
                                                                struct node *block = create_node("Block", "", @2.first_line, @2.first_column);
                                                                add_child(block, $2);
                                                                $$ = block;
                                                            }
                                                            else{
                                                                $$ = $2;
                                                            }
                                                        }
    |       IF LPAR Expr RPAR Statement                 {
                                                            struct node *if1 = create_node("If","", @1.first_line, @1.first_column);
                                                            add_child(if1, $3);
                                                            if($5 != NULL){
                                                                add_child(if1, $5);
                                                                struct node *block = create_node("Block", "", @5.first_line, @5.first_column);
                                                                add_child(if1, block);
                                                                add_bro($3, $5);
                                                                add_bro($5, block);
                                                                $$ = if1;
                                                            }
                                                            else{
                                                                struct node *block1 = create_node("Block","", 0, 0);
                                                                add_child(if1, block1);
                                                                struct node *block2 = create_node("Block", "", 0, 0);
                                                                add_child(if1, block2);
                                                                add_bro($3, block1);
                                                                add_bro(block1, block2);
                                                                $$ = if1;
                                                            }
                                                        }
    |       IF LPAR Expr RPAR Statement ELSE Statement  {
                                                            struct node *if2 = create_node("If", "", @1.first_line, @1.first_column);
                                                            add_child(if2, $3);
                                                            if($5 != NULL){
                                                                add_child(if2, $5);
                                                                add_bro($3, $5);
                                                                if($7 != NULL){
                                                                    add_child(if2, $7);
                                                                    add_bro($5, $7);
                                                                    $$ = if2;
                                                                }else{
                                                                    struct node *block2 = create_node("Block", "", @7.first_line, @7.first_column);
                                                                    add_child(if2, block2);
                                                                    add_bro($5, block2);
                                                                    $$ = if2;
                                                                }
                                                            }else{
                                                                struct node *block = create_node("Block", "", @5.first_line, @5.first_column);
                                                                add_child(if2, block);
                                                                add_bro($3, block);
                                                                if($7 != NULL){
                                                                    add_child(if2, $7);
                                                                    add_bro(block, $7);
                                                                    $$ = if2;
                                                                }else{
                                                                    struct node *block2 = create_node("Block", "", @7.first_line, @7.first_column);
                                                                    add_child(if2, block2);
                                                                    add_bro(block, block2);
                                                                    $$ = if2;
                                                                }
                                                            }
                                                        }
    |       WHILE LPAR Expr RPAR Statement              {
                                                            struct node *whi = create_node("While", "", @1.first_line, @1.first_column);
                                                            add_child(whi, $3);
                                                            if($5 != NULL){
                                                                add_child(whi, $5);
                                                                add_bro($3, $5);
                                                                $$ = whi;
                                                            }
                                                            else{
                                                                struct node *block = create_node("Block", "", @5.first_line, @5.first_column);
                                                                add_child(whi, block);
                                                                add_bro($3, block);
                                                                $$ = whi;
                                                            }
                                                        }
    |       RETURN StatementOpt3 SEMICOLON              {
                                                            struct node *ret = create_node("Return","", @1.first_line, @1.first_column);
                                                            add_child(ret,$2);
                                                            $$ = ret;
                                                        }
    |       StatementOpt4 SEMICOLON                     {                                                 
                                                            $$ = $1;                                                 
                                                        }
    |       PRINT LPAR StatementOpt5 RPAR SEMICOLON     {
                                                            struct node *pri = create_node("Print","", @1.first_line, @1.first_column);
                                                            add_child(pri, $3);
                                                            $$ = pri;
                                                        }
    |       error SEMICOLON                             {$$ = NULL;}
    ;

StatementOpt:   Statement StatementOpt      {
                                                if ($1 == NULL && $2 == NULL){
                                                    $$ = NULL;
                                                }
                                                else if ($1 == NULL){
                                                    $$ = $2;
                                                }
                                                else if ($2 == NULL){
                                                    $$ = $1;
                                                }
                                                else{
                                                    $$ = add_bro($1, $2);
                                                }
                                            }
    |           /* vazio */                 {$$ = NULL;}
    ;

StatementOpt3:  Expr        {$$ = $1;}
    |           /* vazio */ {$$ = NULL;}
    ;

StatementOpt4:  MethodInvocation        {$$ = $1;}
    |           Assignment              {$$ = $1;}
    |           ParseArgs               {$$ = $1;}
    |           /* vazio */             {$$ = NULL;}
    ;

StatementOpt5:  Expr                    {$$ = $1;}
    |           STRLIT                  {
                                            struct node *itslit = create_node("StrLit", $1, @1.first_line, @1.first_column);
                                            $$ = itslit;
                                        }
    ;

MethodInvocation:   ID LPAR MethodInvocationOpt RPAR        {
                                                                struct node *call = create_node("Call", "", @1.first_line, @1.first_column);
                                                                struct node *idd = create_node("Id", $1, @1.first_line, @1.first_column);
                                                                add_child(call, idd);
                                                                add_child(call, $3);
                                                                add_bro(idd, $3);
                                                                $$ = call;
                                                            }
    |               ID LPAR error RPAR                      {$$ = NULL;}
    ;

MethodInvocationOpt:    Expr MethodInvocationOpt2       {
                                                                if($2 != NULL){
                                                                    add_bro($1, $2);
                                                                }
                                                                $$ = $1;
                                                        }
    |                   /* vazio */                     {$$ = NULL;}
    ;

MethodInvocationOpt2:   COMMA Expr MethodInvocationOpt2     {
                                                                if ($2 != NULL){
                                                                    add_bro($2, $3);
                                                                }
                                                                $$ = $2;
                                                            }
    |                   /* vazio */                         {$$ = NULL;}
    ;

Assignment: ID ASSIGN Expr      {
                                    struct node *assign = create_node("Assign", "", @2.first_line, @2.first_column);
                                    struct node *idd = create_node("Id", $1, @1.first_line, @1.first_column);
                                    add_child(assign, idd);
                                    add_child(assign, $3);
                                    add_bro(idd, $3);
                                    $$ = assign;
                                }
    ;

ParseArgs:  PARSEINT LPAR ID LSQ Expr RSQ RPAR      {
                                                        struct node *parseargs = create_node("ParseArgs","", @1.first_line, @1.first_column);
                                                        struct node *id = create_node("Id",$3, @3.first_line, @3.first_column);
                                                        add_child(parseargs,id);
                                                        add_child(parseargs,$5);
                                                        $$ = parseargs;
                                                    }
    |       PARSEINT LPAR error RPAR                {$$ = NULL;}
    ;

Expr: Expr1         {$$ = $1;}
    | Assignment    {$$ = $1;}
    ;

Expr1: LPAR Expr RPAR           {
                                    $$ = $2;
                                }
    | LPAR error RPAR           {$$ = NULL;}
    | Expr1 PLUS Expr1            {
                                    struct node *add = create_node("Add","", @2.first_line, @2.first_column);
                                    add_child(add,$1);
                                    add_child(add,$3);
                                    add_bro($1,$3);
                                    $$ = add;
                                }
    | Expr1 MINUS Expr1           {
                                    struct node *sub = create_node("Sub","", @2.first_line, @2.first_column);
                                    add_child(sub,$1);
                                    add_child(sub,$3);
                                    add_bro($1,$3);
                                    $$ = sub;
                                }
    | Expr1 STAR Expr1            {
                                    struct node *star = create_node("Mul","", @2.first_line, @2.first_column);
                                    add_child(star,$1);
                                    add_child(star,$3);
                                    add_bro($1,$3);
                                    $$ = star;
                                }
    | Expr1 DIV Expr1             {
                                    struct node *div = create_node("Div","", @2.first_line, @2.first_column);
                                    add_child(div,$1);
                                    add_child(div,$3);
                                    add_bro($1,$3);
                                    $$ = div;
                                }
    | Expr1 MOD Expr1             {
                                    struct node *mod = create_node("Mod","", @2.first_line, @2.first_column);
                                    add_child(mod,$1);
                                    add_child(mod,$3);
                                    add_bro($1,$3);
                                    $$ = mod;
                                }
    | Expr1 AND Expr1             {
                                    struct node *and = create_node("And","", @2.first_line, @2.first_column);
                                    add_child(and,$1);
                                    add_child(and,$3);
                                    add_bro($1,$3);
                                    $$ = and;
                                }
    | Expr1 OR  Expr1             {
                                    struct node *or = create_node("Or","", @2.first_line, @2.first_column);
                                    add_child(or,$1);
                                    add_child(or,$3);
                                    add_bro($1,$3);
                                    $$ = or;
                                }
    | Expr1 XOR Expr1             {
                                    struct node *xor = create_node("Xor","", @2.first_line, @2.first_column);
                                    add_child(xor,$1);
                                    add_child(xor,$3);
                                    add_bro($1,$3);
                                    $$ = xor;
                                }
    | Expr1 LSHIFT Expr1          {
                                    struct node *lshift = create_node("Lshift","", @2.first_line, @2.first_column);
                                    add_child(lshift,$1);
                                    add_child(lshift,$3);
                                    add_bro($1,$3);
                                    $$ = lshift;
                                }
    | Expr1 RSHIFT Expr1          {
                                    struct node *rshift = create_node("Rshift","", @2.first_line, @2.first_column);
                                    add_child(rshift,$1);
                                    add_child(rshift,$3);
                                    add_bro($1,$3);
                                    $$ = rshift;
                                }
    | Expr1 EQ Expr1              {
                                    struct node *eq = create_node("Eq","", @2.first_line, @2.first_column);
                                    add_child(eq,$1);
                                    add_child(eq,$3);
                                    add_bro($1,$3);
                                    $$ = eq;
                                }
    | Expr1 GE Expr1              {
                                    struct node *ge = create_node("Ge","", @2.first_line, @2.first_column);
                                    add_child(ge,$1);
                                    add_child(ge,$3);
                                    add_bro($1,$3);
                                    $$ = ge;
                                }   
    | Expr1 GT Expr1              {
                                    struct node *gt = create_node("Gt","", @2.first_line, @2.first_column);
                                    add_child(gt,$1);
                                    add_child(gt,$3);
                                    add_bro($1,$3);
                                    $$ = gt;
                                }
    | Expr1 LE Expr1              {
                                    struct node *le = create_node("Le","", @2.first_line, @2.first_column);
                                    add_child(le,$1);
                                    add_child(le,$3);
                                    add_bro($1,$3);
                                    $$ = le;
                                } 
    | Expr1 LT Expr1              {
                                    struct node *lt = create_node("Lt","", @2.first_line, @2.first_column);
                                    add_child(lt,$1);
                                    add_child(lt,$3);
                                    add_bro($1,$3);
                                    $$ = lt;
                                }
    | Expr1 NE Expr1              {
                                    struct node *ne = create_node("Ne","", @2.first_line, @2.first_column);
                                    add_child(ne,$1);
                                    add_child(ne,$3);
                                    add_bro($1,$3);
                                    $$ = ne;
                                }
    | NOT Expr1                  {
                                    struct node *not = create_node("Not","", @1.first_line, @1.first_column);
                                    $$ = add_child(not,$2);
                                }
    | MINUS Expr1 %prec NOT      {
                                    struct node *minus = create_node("Minus","", @1.first_line, @1.first_column);
                                    $$ = add_child(minus,$2);
                                }
    | PLUS Expr1 %prec NOT       {
                                    struct node *plus = create_node("Plus","", @1.first_line, @1.first_column);
                                    $$ = add_child(plus,$2);
                                }
    | MethodInvocation          {
                                    $$ = $1;
                                }
    | ParseArgs                 {
                                    $$ = $1;
                                }
    | ID                        {
                                    $$ = create_node("Id",$1, @1.first_line, @1.first_column);
                                }
    | ID DOTLENGTH              {
                                   struct node *lengthy = create_node("Length", "", @2.first_line, @2.first_column);
                                   struct node *id = create_node("Id", $1, @1.first_line, @1.first_column);
                                   $$ = add_child(lengthy, id);
                                }
    | INTLIT                    {
                                    $$ = create_node("DecLit", $1, @1.first_line, @1.first_column);
                                }
    | REALLIT                   {
                                    $$ = create_node("RealLit", $1, @1.first_line, @1.first_column);
                                }
    | BOOLLIT                   { 
                                    $$ = create_node("BoolLit", $1, @1.first_line, @1.first_column);
                                }
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
            erros = 1;
            return_flag = 1;
            yyparse();
            if(error_tag == 0){
                print_tree(head, 0);
            }
        }

        else if (strcmp(argv[1], "-s") == 0){
            // Analise semantica - META 3
            return_flag = 1;
            yyparse();
            create_symbol_table(head);
            imprime_erros();
            create_ast(head, global_table, 0);
            show_table();
            print_tree_annotated(head, 0);
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
        return_flag = 1;
        yyparse();
        //gera tabela analise lexical
        create_symbol_table(head);
        //gera analise semantica
        create_ast(head, global_table, 0);
        //gera codigo
        if(error_tag == 0){
            init_produce(head);
            iterate_class(head, global_table);
        }
    }
    return 0;
}