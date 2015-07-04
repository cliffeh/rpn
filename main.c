#include <stdio.h>

// extern int yyparse();
extern int rpn_read();
extern int finished;

#define STACKSIZE 2048

int main() {
  int stack[STACKSIZE], sptr;

  while(finished != 1) {
    sptr = rpn_read(stack);

    // pop everything off the stack and output it
    for(; sptr >= 0; sptr--) {
      fprintf(stdout, "%i\n", stack[sptr]);
    }
  }
}
