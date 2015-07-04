%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
  extern char *yytext;
  extern FILE *yyin; // , *yyout;
  int yylex();
  int yyerror();

  int sptr;
  int finished;

  %}

// %define api.pure
%pure-parser

%parse-param { int *stack }

%initial-action
{
  sptr = -1;
  finished = 0;
  // yyin = p->in;
  // yyout = out;
}

%token PLUS DASH STAR FSLASH MODULO COMMA NL EOFTOK
%token INTLIT FLOATLIT

%start exprlist

%%

exprlist: /* empty */
| EOFTOK { finished = 1; YYACCEPT; }
| NL { YYACCEPT; }
| expr EOFTOK { finished = 1; YYACCEPT; }
| expr NL { YYACCEPT; }
| expr COMMA exprlist
;

expr:
INTLIT { stack[++sptr] = atoi(yytext); }
| PLUS { stack[sptr-1] += stack[sptr]; sptr--; }
| DASH { stack[sptr-1] -= stack[sptr]; sptr--; }
| STAR { stack[sptr-1] *= stack[sptr]; sptr--; }
| FSLASH { stack[sptr-1] /= stack[sptr]; sptr--; }
| MODULO { stack[sptr-1] %= stack[sptr]; sptr--; }
;

%%
int yyerror(s)
char *s;
{
  /* ignore unknown input */ 
  fprintf(stderr,
	  "error: read: unable to parse '%s'\n", yytext);
  return 1;
}


int rpn_read(int *stack)
{
  yyparse(stack);
  return sptr;
}

int yywrap()
{
  return(1);
}

