#include <stdlib.h>
#include "ops.h"

static int comp(const void *a, const void *b) {
  return ( *(int*)a - *(int*)b );
}

expr_t *expr_add(expr_t *e1, expr_t *e2)
{
  expr_t *result;
  switch(e1->type | e2->type) {
  case INT_T: { // both ints
    result = __int(e1->i+e2->i);
  }break;
  case FLOAT_T: { // both floats
    result = __float(e1->f+e2->f);
  }break;
  case (INT_T|FLOAT_T): {
    result = __float( ((e1->type == INT_T) ? ((double)e1->i) : e1->f) + ((e2->type == INT_T) ? ((double)e2->i) : e1->f) );
  }break;
  default: {
    // TODO print unimplemented error
  }
  }
  return result;
}

expr_t *expr_sub(expr_t *e1, expr_t *e2)
{
  expr_t *result;
  switch(e1->type | e2->type) {
  case INT_T: { // both ints
    result = __int(e1->i-e2->i);
  }break;
  case FLOAT_T: { // both floats
    result = __float(e1->f-e2->f);
  }break;
  case (INT_T|FLOAT_T): {
    result = __float( ((e1->type == INT_T) ? ((double)e1->i) : e1->f) - ((e2->type == INT_T) ? ((double)e2->i) : e1->f) );
  }break;
  default: {
    // TODO print unimplemented error
  }
  }
  return result;
}

expr_t *expr_mul(expr_t *e1, expr_t *e2)
{
  expr_t *result;
  switch(e1->type | e2->type) {
  case INT_T: { // both ints
    result = __int(e1->i*e2->i);
  }break;
  case FLOAT_T: { // both floats
    result = __float(e1->f*e2->f);
  }break;
  case (INT_T|FLOAT_T): {
    result = __float( ((e1->type == INT_T) ? ((double)e1->i) : e1->f) * ((e2->type == INT_T) ? ((double)e2->i) : e1->f) );
  }break;
  default: {
    // TODO print unimplemented error
  }
  }
  return result;
}

expr_t *expr_div(expr_t *e1, expr_t *e2)
{
  expr_t *result;
  switch(e1->type | e2->type) {
  case INT_T: { // both ints
    result = __int(e1->i/e2->i);
  }break;
  case FLOAT_T: { // both floats
    result = __float(e1->f/e2->f);
  }break;
  case (INT_T|FLOAT_T): {
    result = __float( ((e1->type == INT_T) ? ((double)e1->i) : e1->f) / ((e2->type == INT_T) ? ((double)e2->i) : e1->f) );
  }break;
  default: {
    // TODO print unimplemented error
  }
  }
  return result;
}

expr_t *expr_mod(expr_t *e1, expr_t *e2)
{
  expr_t *result;
  // TODO IMPLEMENT
  return result;
}

void sort(int *arr, int start, int end)
{
  qsort (arr, end+1, sizeof (int), comp);
}

void reverse(int *arr, int start, int end)
{
  int a,b,c;
  for(a = start, b = end; a < b; a++, b--) {
    c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
  }
}

int average(int *arr, int start, int end)
{
  int i, numer=0, denom=0;
  for(i = start; i <= end; i++) {
    numer += arr[i];
    denom++;
  }
  return (numer/denom);
}
