%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "expr.h"
#include "ops.h"

  extern char *yytext;
  extern FILE *yyin; // , *yyout;
  int yylex();
  int yyerror();

  int sptr;
  int finished;

  %}

// %define api.pure
%pure-parser

%parse-param { expr_t *stack[] }

%initial-action
{
  sptr = -1;
  finished = 0;
  // yyin = p->in;
  // yyout = out;
}

%token PLUS DASH STAR FSLASH MODULO COMMA NL EOFTOK
%token INTLIT FLOATLIT

%token SORT REVERSE AVERAGE

%start exprlist

%%

exprlist: /* empty */
| EOFTOK { finished = 1; YYACCEPT; }
| NL { YYACCEPT; }
| expr EOFTOK { finished = 1; YYACCEPT; }
| expr NL { YYACCEPT; }
| expr COMMA exprlist
;

expr: INTLIT { stack[++sptr] = __int(atoi(yytext)); }
| FLOATLIT { stack[++sptr] = __float(atof(yytext)); }
| op
;

op: PLUS { expr_t *result = expr_add(stack[sptr-1], stack[sptr]); free(stack[sptr-1]); free(stack[sptr]); stack[--sptr] = result; }
| DASH { expr_t *result = expr_sub(stack[sptr-1], stack[sptr]); free(stack[sptr-1]); free(stack[sptr]); stack[--sptr] = result; }
| STAR { expr_t *result = expr_mul(stack[sptr-1], stack[sptr]); free(stack[sptr-1]); free(stack[sptr]); stack[--sptr] = result; }
| FSLASH { expr_t *result = expr_div(stack[sptr-1], stack[sptr]); free(stack[sptr-1]); free(stack[sptr]); stack[--sptr] = result; }
/*
| MODULO { stack[sptr-1] %= stack[sptr]; sptr--; }
| SORT { sort(stack, 0, sptr); }
| REVERSE { reverse(stack, 0, sptr); }
| AVERAGE { stack[0] = average(stack, 0, sptr); sptr = 0; }
*/
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


int rpn_read(expr_t *stack[])
{
  yyparse(stack);
  return sptr;
}

int yywrap()
{
  return(1);
}

