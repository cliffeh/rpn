#ifndef _OPS_H
#define _OPS_H 1
#include "expr.h"

expr_t *expr_add(expr_t *e1, expr_t *e2);
expr_t *expr_sub(expr_t *e1, expr_t *e2);
expr_t *expr_mul(expr_t *e1, expr_t *e2);
expr_t *expr_div(expr_t *e1, expr_t *e2);
expr_t *expr_mod(expr_t *e1, expr_t *e2);

void sort(int *arr, int start, int end);
void reverse(int *arr, int start, int end);
int average(int *arr, int start, int end);

#endif
