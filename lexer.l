%{
#include <stdio.h>
#include "symbols.h" // symbol table

// int yywrap() { return 1; }
%}

%%

[\+\-]?[0-9]+ {
  return(INTLIT);
}

[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)? {
  return(FLOATLIT);
}

"+" { return(PLUS); }
"-" { return(DASH); }
"*" { return(STAR); }
"/" { return(FSLASH); }
"%" { return(MODULO); }

"," { return(COMMA); }

"SORT" { return(SORT); }

[ \t]+   /* ignore whitespace */

\n { return(NL); }
<<EOF>> { return(EOFTOK); }

%%
