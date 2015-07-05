#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include "expr.h"

extern int rpn_read();
extern int finished;

#define STACKSIZE 2048

int main() {
  expr_t *stack[STACKSIZE];
  int sptr;

  while(finished != 1) {
    sptr = rpn_read(stack);

    // pop everything off the stack and output it
    for(; sptr >= 0; sptr--) {
      __print(stdout, stack[sptr]);
    }
  }
}
