%{
    #include<stdio.h>
    #define YYERROR_VERBOSE
    void yyerror(const char *);
%}
%token MAYUSCULA
%token MINUSCULA
%token DIGITO
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
                sentencia
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
variable : identificador
            |
            identificador inicial
            ;
inicial : '=' constante
        |
        '=' identificador
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
expPrimaria : identificador
            |
            constante
            |
            '(' expresion ')'
            ;
identificador : MAYUSCULA caracteres
                ;
caracteres : MAYUSCULA caracteres
            |
            MINUSCULA caracteres
            |  
            DIGITO caracteres
            |
            ;
constante : signo constEntera
            |
            signo constReal
            ;
constEntera : DIGITO
            |
            constEntera DIGITO 
            ;
constReal : constEntera '.' mantisa
            |
            '.' constEntera
            ;
mantisa : constEntera
        |
        ;
signo : '+'
        |
        '-'
        |
        ;
%%

int main () {
        return yyparse();
}

void yyerror(const char * s) {
        puts(s);
}