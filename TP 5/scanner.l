%{
    #include "parser.tab.h"
%}
%option noyywrap
%%
if              {return IF;}
int             {return INT;}
else            {return ELSE;}
while           {return WHILE;}
float           {return FLOAT;}
[.+;()=>!]|-    {return *yytext;}            
\|\|            {return OPOR;}
==              {return OPCOMPARATIVO;}
&&              {return OPAND;}
[0-9]           {return DIGITO;}
[A-Z]           {return MAYUSCULA;}
[a-z]           {return MINUSCULA;}
.|\n            ;
%%
