#include <stdlib.h>
#include "ops.h"

static int comp(const void *a, const void *b) {
  return ( *(int*)a - *(int*)b );
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
