#include "expr.h"

static expr_t *__new() {
  return malloc(sizeof(expr_t));
}

expr_t *__int(int val)
{
  expr_t *e = __new();
  e->type = INT_T;
  e->i = val;
  return e;
}

expr_t *__float(float val)
{
  expr_t *e = __new();
  e->type = FLOAT_T;
  e->f = val;
  return e;
}

void __print(FILE *fp, expr_t *e)
{
  switch(e->type) {
  case INT_T: { fprintf(fp, "%i\n", e->i); } break;
  case FLOAT_T: { fprintf(fp, "%f\n", e->f); } break;
  }
}
