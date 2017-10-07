%{
#include <stdio>
%}

%%
i(f|nt)|else|while|float                {printf("%s\t%s", yytext, "Palabra Reservada");}
+|-|=|==|>|&&|\|\|                      {printf("%s\t%s", yytext, "Operador");}
;                                       {printf("%s\t%s", yytext, "Caracter de Puntuacion");}
[A-Z][A-Za-z0-9]+                       {printf("%s\t%s", yytext, "Identificador");}
(\+|-)?([0-9]+|[0-9]*\.[0-9]+|[0-9]+\.) {printf("%s\t%s", yytext, "Constante");}
%%

void main() {
    yylex();
    return;
}