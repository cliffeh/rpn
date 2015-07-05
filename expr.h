#ifndef _EXPR_H
#define _EXPR_H 1
#include <stdlib.h>
#include <stdio.h>

#define INT_T    (1<<0)
#define FLOAT_T  (1<<1)
#define STRING_T (1<<2)

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

void __print(FILE *fp, expr_t *e);

#endif
