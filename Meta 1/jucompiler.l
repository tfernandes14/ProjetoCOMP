%{
    /* 
        António Lopes - 2017262466;
        Tiago Fernandes - 2017242428;
    */  
    #include <string.h>
    int imprime = 0;
    int erros = 0;
    int num_linhas = 1;
    int num_colunas = 1;
    int errorline, errorcol;
    int commentline, commentcol;
    char string[1024] = "";
    void printString(char * string);
    int erro = 0;
%}

/* Contador de linhas do lex */
%option yylineno

%X LINECOMMENT
%X BLOCKCOMMENT
%X STRINGLIT
%X TERMINATOR

sinais          [+|-]
letras          [A-Za-z_$]
alfanumericas   [A-Za-z_$0-9]
digitos         [0-9]
numeros         [0-9_]
NEWLINE         \r|\n|\r\n
validesc        (\\f)|(\\n)|(\\r)|(\\t)|(\\\\)|(\\\")
Invalidesc      \\[^fnrt\"\\\n]|\\
exc             {NEWLINE}|\"
BOOLLIT         "true"|"false"
RESERVED        "abstract"|"assert"|"break"|"byte"|"case"|"catch"|"char"|"const"|"continue"|"default"|"do"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"goto"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throw"|"throws"|"transient"|"try"|"volatile"|"++"|"--"|"Integer"|"System"|"null"
ID              {letras}{alfanumericas}*
STRLIT          [^exc]
INTLIT          0|[1-9]{numeros}*[0-9]|[1-9]
realdigitos     0|[0-9]{numeros}*{digitos}|[1-9]|0["_"][1-9]{numeros}*
REALLIT         {realdigitos}"."{realdigitos}?{exponente}?|"."{realdigitos}{exponente}?|{realdigitos}{exponente}
exponente       [eE]{sinais}?{realdigitos}+
WHITESPACE      \f|\t|" "

%%

{INTLIT}                {if(imprime==1){printf("INTLIT(%s)\n", yytext);} num_colunas += yyleng;}
{REALLIT}               {if(imprime==1){printf("REALLIT(%s)\n", yytext);} num_colunas += yyleng;}
{NEWLINE}               {num_linhas++;num_colunas = 1;}
{BOOLLIT}               {if(imprime==1){printf("BOOLLIT(%s)\n", yytext);} num_colunas += yyleng;}
"&&"                    {if(imprime==1){printf("AND\n");} num_colunas += yyleng;}
"="                     {if(imprime==1){printf("ASSIGN\n");}num_colunas += yyleng;}
"*"                     {if(imprime==1){printf("STAR\n");}num_colunas += yyleng;}
","    	                {if(imprime==1){printf("COMMA\n");}num_colunas += yyleng;}
"/"                     {if(imprime==1){printf("DIV\n");}num_colunas += yyleng;}
"=="                    {if(imprime==1){printf("EQ\n");}num_colunas += yyleng;}
">="                    {if(imprime==1){printf("GE\n");}num_colunas += yyleng;}
">"                     {if(imprime==1){printf("GT\n");}num_colunas += yyleng;}
"if"                    {if(imprime==1){printf("IF\n");}num_colunas += yyleng;}
"{"                     {if(imprime==1){printf("LBRACE\n");}num_colunas += yyleng;}
"<="                    {if(imprime==1){printf("LE\n");}num_colunas += yyleng;}
"("                     {if(imprime==1){printf("LPAR\n");}num_colunas += yyleng;}
"["                     {if(imprime==1){printf("LSQ\n");}num_colunas += yyleng;}
"<"                     {if(imprime==1){printf("LT\n");}num_colunas += yyleng;}
"-"                     {if(imprime==1){printf("MINUS\n");}num_colunas += yyleng;}
"%"                     {if(imprime==1){printf("MOD\n");}num_colunas += yyleng;}
"!="                    {if(imprime==1){printf("NE\n");}num_colunas += yyleng;}
"!"                     {if(imprime==1){printf("NOT\n");}num_colunas += yyleng;}
"||"                    {if(imprime==1){printf("OR\n");}num_colunas += yyleng;}
"+"                     {if(imprime==1){printf("PLUS\n");}num_colunas += yyleng;}
"}"                     {if(imprime==1){printf("RBRACE\n");}num_colunas += yyleng;}
")"                     {if(imprime==1){printf("RPAR\n");}num_colunas += yyleng;}
"]"                     {if(imprime==1){printf("RSQ\n");}num_colunas += yyleng;}
";"                     {if(imprime==1){printf("SEMICOLON\n");}num_colunas += yyleng;}
"->"                    {if(imprime==1){printf("ARROW\n");}num_colunas += yyleng;}
"<<"                    {if(imprime==1){printf("LSHIFT\n");}num_colunas += yyleng;}
">>"                    {if(imprime==1){printf("RSHIFT\n");}num_colunas += yyleng;}
"^"                     {if(imprime==1){printf("XOR\n");}num_colunas += yyleng;}
"boolean"               {if(imprime==1){printf("BOOL\n");}num_colunas += yyleng;}
"class"                 {if(imprime==1){printf("CLASS\n");}num_colunas += yyleng;}
".length"               {if(imprime==1){printf("DOTLENGTH\n");}num_colunas += yyleng;}
"double"                {if(imprime==1){printf("DOUBLE\n");}num_colunas += yyleng;}
"else"                  {if(imprime==1){printf("ELSE\n");}num_colunas += yyleng;}
"int"                   {if(imprime==1){printf("INT\n");}num_colunas += yyleng;}
"System.out.print"      {if(imprime==1){printf("PRINT\n");}num_colunas += yyleng;}
"Integer.parseInt"      {if(imprime==1){printf("PARSEINT\n");}num_colunas += yyleng;}
"public"                {if(imprime==1){printf("PUBLIC\n");}num_colunas += yyleng;}
"return"                {if(imprime==1){printf("RETURN\n");}num_colunas += yyleng;}
"static"                {if(imprime==1){printf("STATIC\n");}num_colunas += yyleng;}
"String"                {if(imprime==1){printf("STRING\n");}num_colunas += yyleng;}
"void"                  {if(imprime==1){printf("VOID\n");}num_colunas += yyleng;}
"while"                 {if(imprime==1){printf("WHILE\n");}num_colunas += yyleng;}
{WHITESPACE}            {num_colunas += yyleng;}
{RESERVED}              {if(imprime==1){printf("RESERVED(%s)\n", yytext);} num_colunas += yyleng;}
{ID}                    {if(imprime==1){printf("ID(%s)\n", yytext);} num_colunas += yyleng;}


"//"                        {BEGIN LINECOMMENT;}
<LINECOMMENT>{NEWLINE}      {num_linhas++; num_colunas = 1; BEGIN 0;}
<LINECOMMENT>.              {;}

"/*"                    {BEGIN BLOCKCOMMENT; commentline = num_linhas; commentcol = num_colunas; num_colunas += yyleng;}
<BLOCKCOMMENT>{NEWLINE} {num_linhas++; num_colunas = 1;}
<BLOCKCOMMENT><<EOF>>   {if(imprime == 1 || erros == 1){printf("Line %d, col %d: unterminated comment\n", commentline, commentcol);} return 0;}
<BLOCKCOMMENT>.         {num_colunas += yyleng;}
<BLOCKCOMMENT>"*/"      {BEGIN 0; num_colunas += yyleng;}

\"                           {BEGIN STRINGLIT; strcpy(string,"\""); erro = 0; errorcol = num_colunas; errorline=num_linhas; num_colunas += yyleng;}
<STRINGLIT>\"                {strcat(string, "\""); if(erro == 0){printString(string);BEGIN 0; num_colunas += yyleng;} else {BEGIN 0; num_colunas += yyleng;}}
<STRINGLIT>{NEWLINE}         {if (imprime == 1 || erros == 1){printf("Line %d, col %d: unterminated string literal\n", errorline, errorcol);} num_linhas++; num_colunas = 1; BEGIN 0;}
<STRINGLIT><<EOF>>           {if (imprime == 1 || erros == 1){printf("Line %d, col %d: unterminated string literal\n", errorline, errorcol);} BEGIN 0;}
<STRINGLIT>{Invalidesc}      {if (imprime == 1 || erros == 1){printf("Line %d, col %d: invalid escape sequence (%s)\n", errorline, num_colunas, yytext);} num_colunas += yyleng; erro = 1;}
<STRINGLIT>{validesc}        {strcat(string, yytext); num_colunas += yyleng;}
<STRINGLIT>{STRLIT}          {strcat(string, yytext); num_colunas += yyleng;}
<STRINGLIT>.                 {strcat(string, yytext); num_colunas += yyleng;}

<<EOF>>         {num_colunas += 1; return 0;}
.               {if(imprime == 1 || erros == 1){printf("Line %d, col %d: illegal character (%s)\n", num_linhas, num_colunas, yytext);} num_colunas += yyleng;}

%%

void printString(char * string){
    if (erro == 0){
        if(imprime == 1){
            printf("STRLIT(%s)\n", string);
        }
    }
}

int main(int argc, char *argv[]){
    if (argc > 1){
        if (strcmp(argv[1], "-l") == 0){
            imprime = 1;
            erros = 1;
        }
        else if (strcmp(argv[1], "-e1") == 0){
            erros = 1;
        }
        else{
            return 0;
        }
    }
    if (argc == 1){
        erros = 1;
    }
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}