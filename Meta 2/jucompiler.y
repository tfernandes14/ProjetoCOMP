%{
    #include <stdio.h>
    int yylex(void);
    void yyerror (const char *s);
%}

%token NUMBER
%left '+' '-'
%left '*' '/'
%left '(' ')'
%right '='

%%

calc: expression                        {printf("%d\n", $1);}

expression: expression '+' expression       {$$=$1+$3;}
    |   expression '-' expression           {$$=$1-$3;}
    |   expression '*' expression           {$$=$1*$3;}
    |   expression '/' expression           {if ($3 != 0){$$=$1/$3;}else{printf("Divide by zero!\n");}}
    |   '(' expression '+' expression ')'   {$$=$2+$4;}
    |   '(' expression '-' expression ')'   {$$=$2-$4;}
    |   '(' expression '*' expression ')'   {$$=$2*$4;}
    |   '(' expression '/' expression ')'   {$$=$2/$4;}
    |   NUMBER                              {$$=$1;}
    ;
%%

int main() {
    yyparse();
    return 0;
}