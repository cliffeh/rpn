#include "expr.h"

static expr_t *__new() {
  return malloc(sizeof(expr_t));
}

expr_t *__int(int val)
{
  expr_t *e = __new();
  e->type = INTLIT;
  e->i = val;
  return e;
}

expr_t *__float(float val)
{
  expr_t *e = __new();
  e->type = FLOATLIT;
  e->f = val;
  return e;
}
