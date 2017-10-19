%{
    #include<stdio.h>
    #define YYERROR_VERBOSE
    void yyerror(const char *);
%}
%token ID
%token NUM
%token IF
%token ELSE
%token INT
%token FLOAT
%token WHILE
%token OPCOMPARATIVO
%token OPOR
%token OPAND
%left '+' '-'


%%
listaSentencias : listaSentencias sentencia
                |
                ;
sentencia : sentExpresion
            |
            sentSeleccion
            |
            sentIteracion
            |
            sentDeclaracion
            ;
sentDeclaracion : declaracionVariable ';'
                  ;
sentExpresion : expresion ';'
                ;
sentSeleccion : IF '(' expresion ')' sentencia
                |
                IF '(' expresion ')' sentencia ELSE sentencia
                ;
sentIteracion : WHILE '(' expresion ')' sentencia
                ;
declaracionVariable : tipoDato variable 
                    ;
tipoDato : INT
            |
            FLOAT
            ;
variable : ID inicial
            ;
inicial : '=' valor
        |
        ;
valor : ID
        |
        constante
        ;
expresion : expOr
            |
            expPrimaria '=' expresion
            ;
expOr : expAnd
        |
        expOr OPOR expAnd
        ;
expAnd : expIgualdad
        |
        expAnd OPAND expIgualdad
        ;
expIgualdad : expRelacion
            |
            expIgualdad OPCOMPARATIVO expRelacion
            ;
expRelacion : expAditiva
            |
            expRelacion '>' expAditiva
            ;
expAditiva : expNegacion
            |
            expAditiva operadorAditivo expNegacion
            ;
operadorAditivo : '+'
                |
                '-'
                ;
expNegacion : expPrimaria
            |
            '!' expPrimaria
            ;
expPrimaria : ID
            |
            constante
            |
            '(' expresion ')'
            ;
constante : signo constEntera
            |
            signo constReal
            ;
constEntera : NUM
            ;
constReal : NUM '.' mantisa
            |
            '.' NUM
            ;
mantisa : NUM
        |
        ;
signo : '+'
        |
        '-'
        |
        ;
%%

int main () {
        int resultado = yyparse();
        if(!resultado)
                puts("No Sintax Error.");
        return resultado;
}

void yyerror(const char * s) {
        puts(s);
}