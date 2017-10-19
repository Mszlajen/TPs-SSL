%{
    #include "parser.tab.h"
%}
%option noyywrap
%%
if                  {return IF;}
int                 {return INT;}
else                {return ELSE;}
while               {return WHILE;}
float               {return FLOAT;}
[.+;()=>!]|-        {return yytext[0];}            
\|\|                {return OPOR;}
==                  {return OPCOMPARATIVO;}
&&                  {return OPAND;}
[A-Z][A-Za-z0-9]+   {return ID;}
[0-9]+               {return NUM;}
.|\n                ;
%%