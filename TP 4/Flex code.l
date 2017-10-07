%{
%}
%option noyywrap
%%
i(f|nt)|else|while|float                {printf("%s\t%s\n", yytext, "Palabra Reservada");}
\+|-|=|==|>|&&|\|\|                     {printf("%s\t%s\n", yytext, "Operador");}
;                                       {printf("%s\t%s\n", yytext, "Caracter de Puntuacion");}
[A-Z][A-Za-z0-9]+                       {printf("%s\t%s\n", yytext, "Identificador");}
(\+|-)?([0-9]+|[0-9]*\.[0-9]+|[0-9]+\.) {printf("%s\t%s\n", yytext, "Constante");}
.|\n                                    ;
%%

void main() {
    yylex();
    return;
}
