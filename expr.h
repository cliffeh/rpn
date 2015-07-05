#ifndef _EXPR_H
#define _EXPR_H 1
#include <stdlib.h>
#include "symbols.h"

typedef struct expr_t {
  int type;
  union {
    int i;
    double f;
    char *s;
  };
} expr_t;

expr_t *__int(int val);
expr_t *__float(float val);
// TODO implement for char *

#endif
