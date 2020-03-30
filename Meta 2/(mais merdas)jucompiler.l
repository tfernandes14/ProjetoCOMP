%{
    /* 
        António Lopes - 2017262466;
        Tiago Fernandes - 2017242428;
    */  
    #include <string.h>
    #include "y.tab.h"
    int imprime, erros, return_flag; // Definidas no jucompiler.y
    int num_linhas = 1;
    int num_colunas = 1;
    int parse_error = 0;
    extern int error_tag;
    int errorline = 1, errorcol = 1;    // Erros nas STRLIT e BLOCKCOMMENT
    int commentline, commentcol;        // Erros nas STRLIT e BLOCKCOMMENT
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
%X AUX_STATE

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

{INTLIT}                {
                            if(imprime==1){
                                printf("INTLIT(%s)\n", yytext);
                            }
                            num_colunas += yyleng;
                            BEGIN AUX_STATE;
                            yylval.str = (char *) strdup(yytext);
                            if(return_flag == 1){
                                //printf("INTLIT\n");
                                return INTLIT;
                            }
                        }
                        
{REALLIT}               {
                            if(imprime==1){
                                printf("REALLIT(%s)\n", yytext);
                            }
                            num_colunas += yyleng;
                            BEGIN AUX_STATE;
                            yylval.str = (char *) strdup(yytext);
                            if(return_flag == 1){
                                //printf("REALLIT\n");
                                return REALLIT;
                            }
                        }
                        
{NEWLINE}               {
                            num_linhas++;
                            num_colunas = 1;
                        }
                        
{BOOLLIT}               {
                            if(imprime==1){
                                printf("BOOLLIT(%s)\n", yytext);
                            }
                            num_colunas += yyleng;
                            yylval.str = (char *) strdup(yytext);
                            if(return_flag == 1){
                                //printf("BOOLLIT\n");
                                return BOOLLIT;
                            }
                        }
                        
"&&"                    {
                            if(imprime==1){
                                printf("AND\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("AND\n");
                                return AND;
                            }
                        }
                        
"="                     {
                            if(imprime==1){
                                printf("ASSIGN\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("ASSIGN\n");
                                return ASSIGN;
                            }
                        }
                        
"*"                     {
                            if(imprime==1){
                                printf("STAR\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("STAR\n");
                                return STAR;
                            }
                        }
                            
","    	                {
                            if(imprime==1){
                                printf("COMMA\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("COMMA\n");
                                return COMMA;
                            }
                        }
                            
"/"                     {
                            if(imprime==1){
                                printf("DIV\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("DIV\n");
                                return DIV;
                            }
                        }

"=="                    {
                            if(imprime==1){
                                printf("EQ\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("EQ\n");
                                return EQ;
                            }
                        }
                            
">="                    {
                            if(imprime==1){
                                printf("GE\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("GE\n");
                                return GE;
                            }
                        }
                            
">"                     {
                            if(imprime==1){
                                printf("GT\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("GT\n");
                                return GT;
                            }
                        }
                            
"if"                    {
                            if(imprime==1){
                                printf("IF\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("IF\n");
                                return IF;
                            }
                        }

"{"                     {
                            if(imprime==1){
                                printf("LBRACE\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("LBRACE\n");
                                return LBRACE;
                            }
                        }

"<="                    {
                            if(imprime==1){
                                printf("LE\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("LE\n");
                                return LE;
                            }
                        }
                            
"("                     {
                            if(imprime==1){
                                printf("LPAR\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("LPAR\n");
                                return LPAR;
                            }
                        }

"["                     {
                            if(imprime==1){
                                printf("LSQ\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("LSQ\n");
                                return LSQ;
                            }
                        }

"<"                     {
                            if(imprime==1){
                                printf("LT\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("LT\n");
                                return LT;
                            }
                        }
                            
"-"                     {
                            if(imprime==1){
                                printf("MINUS\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("MINUS\n");
                                return MINUS;
                            }
                        }

"%"                     {
                            if(imprime==1){
                                printf("MOD\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("MOD\n");
                                return MOD;
                            }
                        }

"!="                    {
                            if(imprime==1){
                                printf("NE\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("NE\n");
                                return NE;
                            }
                        }
                            
"!"                     {
                            if(imprime==1){
                                printf("NOT\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("NOT\n");
                                return NOT;
                            }
                        }
                            
"||"                    {
                            if(imprime==1){
                                printf("OR\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("OR\n");
                                return OR;
                            }
                        }
                            
"+"                     {
                            if(imprime==1){
                                printf("PLUS\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("PLUS\n");
                                return PLUS;
                            }
                        }
                        
"}"                     {
                            if(imprime==1){
                                printf("RBRACE\n");
                            }
                            num_colunas += yyleng;
                            BEGIN AUX_STATE;
                            if(return_flag == 1){
                                //printf("RBRACE\n");
                                return RBRACE;
                            }
                        }
                        
")"                     {
                            if(imprime==1){
                                printf("RPAR\n");
                            }
                            num_colunas += yyleng;
                            BEGIN AUX_STATE;
                            if(return_flag == 1){
                                //printf("RPAR\n");
                                return RPAR;
                            }
                        }
                            
"]"                     {
                            if(imprime==1){
                                printf("RSQ\n");
                            }
                            num_colunas += yyleng;
                            BEGIN AUX_STATE;
                            if(return_flag == 1){
                                //printf("RSQ\n");
                                return RSQ;
                            }
                        }
                            
";"                     {
                            if(imprime==1){
                                printf("SEMICOLON\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("SEMICOLON\n");
                                return SEMICOLON;
                            }
                        }

"->"                    {
                            if(imprime==1){
                                printf("ARROW\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("ARROW\n");
                                return ARROW;
                            }
                        }

"<<"                    {
                            if(imprime==1){
                                printf("LSHIFT\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("LSHIFT\n");
                                return LSHIFT;
                            }
                        }
                            
">>"                    {
                            if(imprime==1){
                                printf("RSHIFT\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("RSHIFT\n");
                                return RSHIFT;
                            }
                        }

"^"                     {
                            if(imprime==1){
                                printf("XOR\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("XOR\n");
                                return XOR;
                            }
                        }
                            
"boolean"               {
                            if(imprime==1){
                                printf("BOOL\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("BOOL\n");
                                return BOOL;
                            }
                        }
                            
"class"                 {
                            if(imprime==1){
                                printf("CLASS\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("CLASS\n");
                                return CLASS;
                            }
                        }

".length"               {
                            if(imprime==1){
                                printf("DOTLENGTH\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("DOTLENGTH\n");
                                return DOTLENGTH;
                            }
                        }

"double"                {
                            if(imprime==1){
                                printf("DOUBLE\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("DOUBLE\n");
                                return DOUBLE;
                            }
                        }

"else"                  {
                            if(imprime==1){
                                printf("ELSE\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("ELSE\n");
                                return ELSE;
                            }
                        }

"int"                   {
                            if(imprime==1){
                                printf("INT\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("INT\n");
                                return INT;
                            }
                        }

                            
"System.out.print"      {
                            if(imprime==1){
                                printf("PRINT\n");
                            }
                            num_colunas += yyleng; 
                            if(return_flag == 1){
                                //printf("PRINT\n");
                                return PRINT;
                            }
                        }

"Integer.parseInt"      {
                            if(imprime==1){
                                printf("PARSEINT\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("PARSEINT\n");
                                return PARSEINT;
                            }
                        }

"public"                {
                            if(imprime==1){
                                printf("PUBLIC\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){ 
                                //printf("PUBLIC\n");
                                return PUBLIC;
                            }
                        }

"return"                {
                            if(imprime==1){
                                printf("RETURN\n");
                            }
                            num_colunas += yyleng;
                            BEGIN AUX_STATE;
                            if(return_flag == 1){ 
                                //printf("RETURN\n");
                                return RETURN;
                            }
                        }

"static"                {
                            if(imprime==1){
                                printf("STATIC\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){ 
                                //printf("STATIC\n");
                                return STATIC;
                            }
                        }

"String"                {
                            if(imprime==1){
                                printf("STRING\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){ 
                                //printf("STRING\n");
                                return STRING;
                            }
                        }

"void"                  {
                            if(imprime==1){
                                printf("VOID\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){ 
                                //printf("VOID\n");
                                return VOID;
                            }
                        }

"while"                 {
                            if(imprime==1){
                                printf("WHILE\n");
                            }
                            num_colunas += yyleng;
                            if(return_flag == 1){
                                //printf("WHILE\n");
                                return WHILE;
                            }
                        }
                        
{WHITESPACE}            {
                            num_colunas += yyleng;
                        }
                        
{RESERVED}              {
                            if(imprime==1){
                                printf("RESERVED(%s)\n", yytext);
                            } 
                            yylval.str = (char *) strdup(yytext);
                            num_colunas += yyleng;
                            if(return_flag == 1){ 
                                //printf("RESERVED\n");
                                return RESERVED;
                            }
                        }

{ID}                    {
                            if(imprime==1){
                                printf("ID(%s)\n", yytext);
                            } 
                            num_colunas += yyleng;
                            BEGIN AUX_STATE;
                            yylval.str = (char *) strdup(yytext);
                            if(return_flag == 1){ 
                                //printf("ID\n");
                                return ID;
                            }
                        }
                        

"//"                        {
                                BEGIN LINECOMMENT;
                            }

<LINECOMMENT>{NEWLINE}      {
                                num_linhas++;
                                num_colunas = 1;
                                BEGIN 0;
                            }

<LINECOMMENT>.              {;}


"/*"                    {
                            parse_error = 0; 
                            BEGIN BLOCKCOMMENT; 
                            commentline = num_linhas; 
                            commentcol = num_colunas; 
                            num_colunas += yyleng;
                        }

<BLOCKCOMMENT>{NEWLINE} {
                            parse_error = 0; 
                            num_linhas++; 
                            num_colunas = 1;
                        }

<BLOCKCOMMENT><<EOF>>   {
                            parse_error = 0; 
                            if(imprime == 1 || erros == 1){
                                parse_error = 1; 
                                printf("Line %d, col %d: unterminated comment\n", commentline, commentcol);
                            } 
                            return 0;
                        }
                        
<BLOCKCOMMENT>.         {
                            parse_error = 0; 
                            num_colunas += yyleng;
                        }

<BLOCKCOMMENT>"*/"      {
                            parse_error = 0; 
                            BEGIN 0; 
                            num_colunas += yyleng;
                        }


\"                           {
                                BEGIN STRINGLIT; 
                                strcpy(string,"\""); 
                                erro = 0; 
                                errorcol = num_colunas; 
                                errorline = num_linhas; 
                                num_colunas += yyleng;
                            }

<STRINGLIT>\"               {
                                strcat(string, "\""); 
                                if(erro == 0){
                                    printString(string); 
                                    BEGIN AUX_STATE;
                                    num_colunas += yyleng;
                                    yytext = string;
                                    yylval.str = (char *) strdup(string); 
                                    if(return_flag == 1){
                                        //printf("STRINGLIT\n");
                                        return STRLIT;
                                    }
                                }
                                else{
                                    BEGIN 0; 
                                    num_colunas += yyleng;
                                }
                            }
                            
<STRINGLIT>{NEWLINE}        {
                                //parse_error = 0;
                                if (imprime == 1 || erros == 1){
                                    printf("Line %d, col %d: unterminated string literal\n", errorline, errorcol);
                                }
                                num_linhas++; 
                                num_colunas = 1; 
                                BEGIN 0;
                            }

<STRINGLIT><<EOF>>          {
                                //parse_error = 0;
                                if (imprime == 1 || erros == 1){
                                    printf("Line %d, col %d: unterminated string literal\n", errorline, errorcol);
                                } 
                                BEGIN 0;
                                return 0;
                            }

<STRINGLIT>{Invalidesc}     {
                                if (imprime == 1 || erros == 1){
                                    printf("Line %d, col %d: invalid escape sequence (%s)\n", errorline, num_colunas, yytext);
                                } 
                                num_colunas += yyleng; 
                                erro = 1;
                            }

<STRINGLIT>{validesc}       {
                                //parse_error = 0; 
                                strcat(string, yytext); 
                                num_colunas += yyleng;
                            }
                            
<STRINGLIT>{STRLIT}         {
                                //parse_error = 0; 
                                strcat(string, yytext); 
                                num_colunas += yyleng;
                            }

<STRINGLIT>.                {
                                //parse_error = 0; 
                                strcat(string, yytext); 
                                num_colunas += yyleng;
                            }


<AUX_STATE>{WHITESPACE}       {
                                        parse_error = 0;
                                        num_colunas += yyleng;
                                    }

<AUX_STATE>";"                {
                                        parse_error = 0;
                                        num_colunas += yyleng;
                                        BEGIN 0;
                                        if (return_flag == 1){
                                            //printf("SEMICOLON");
                                            return SEMICOLON;
                                        }
                                    }

<AUX_STATE>{NEWLINE}          {
                                        parse_error = 1;
                                        num_linhas++;
                                        num_colunas = 1;
                                        BEGIN 0;
                                        if (return_flag == 1){
                                            //printf("SEMICOLON\n");
                                            return SEMICOLON;
                                        }
                                    }

<AUX_STATE>"//"               {
                                        parse_error = 0;
                                        BEGIN LINECOMMENT;
                                        if (return_flag == 1){
                                            //printf("SEMICOLON\n");
                                            return SEMICOLON;
                                        }
                                    }

<AUX_STATE>"/*"               {
                                        parse_error = 0; 
                                        BEGIN BLOCKCOMMENT; 
                                        commentline = num_linhas; 
                                        commentcol = num_colunas; 
                                        if (return_flag == 1){
                                            //printf("SEMICOLON\n");
                                            return SEMICOLON;
                                        }
                                    }

<AUX_STATE>""/.                     {
                                        parse_error = 0;
                                        BEGIN 0;
                                    }
                                    
<AUX_STATE><<EOF>>                  {
                                        parse_error = 0;
                                        BEGIN 0;
                                        parse_error = 1;
                                        if (return_flag == 1){
                                            //printf("SEMICOLON\n");
                                            return SEMICOLON;
                                        }
                                    }
                                    

<<EOF>>         {
                    num_colunas += 1; 
                    parse_error = 1;    
                    return 0;
                }

.               {
                    if(imprime == 1 || erros == 1){
                        printf("Line %d, col %d: illegal character (%s)\n", num_linhas, num_colunas, yytext);
                    } 
                    num_colunas += yyleng;
                }

%%

void printString(char * string){
    if (erro == 0){
        if(imprime == 1){
            printf("STRLIT(%s)\n", string);
        }
    }
}

void yyerror(char *s){
    error_tag = 1;
    if (parse_error){
        printf("Line %d, col %d: %s: %s\n", num_linhas, num_colunas, s, yytext);
    }
    else{
        printf("Line %d, col %d: %s: %s\n", num_linhas, (int)(num_colunas - strlen(yytext)), s, yytext);
    }
}

int yywrap(){
    return 1;
}
