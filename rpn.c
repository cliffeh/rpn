#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STACKSIZE 2048
#define BUFSIZE 65536

int main(int argc, char *argv[])
{
  int stack[STACKSIZE], sptr, i;
  char buf[BUFSIZE], *p;

  while(fgets(buf, BUFSIZE, stdin) != 0) {
    // reset the stack pointer
    sptr = -1;

    // fprintf(stdout, "DEBUG: parsing: %s", buf);
    p = strtok(buf, ", \t\n");
    while(p != 0) {
      // fprintf(stdout, "DEBUG: token: %s\n", p);
      switch(*p) {

	// integer: assume it's an int, push it onto the stack
	// TODO support floats
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
	{
	  // fprintf(stdout, "DEBUG: pushing: %i; new stack depth will be: %i\n", atoi(p), sptr+2);
	  stack[++sptr] = atoi(p);
	}break;

	// arithmetic operations: pop 2 values off the stack, perform the operation, 
	// and push the result back onto the stack
      case '+': {
	stack[sptr-1] += stack[sptr]; sptr--;
      }break;
      case '-': {
	stack[sptr-1] -= stack[sptr]; sptr--;
      }break;
      case '*': {
	stack[sptr-1] *= stack[sptr]; sptr--;
      }break;
      case '/': {
	stack[sptr-1] /= stack[sptr]; sptr--;
      }break;
      case '%': {
	stack[sptr-1] %= stack[sptr]; sptr--;
      }break;

	// TODO support add'l operations (AVERAGE, SORT, SIN, COS, TAN, ...)

	// spit out an error, clear the buffer, clear the stack
      default: {
	fprintf(stderr, "error: unknown token: %s\n", p);
	for(i = 0; i < BUFSIZE; i++) buf[i] = 0;
	sptr = -1;
      }
      }
      p = strtok(0, ", \t\n");
    }
    
    // output the result
    if(sptr == 0) {
      fprintf(stdout, "%i\n", stack[0]);
    } else {
      fprintf(stderr, "error: expected 1 result on the stack, instead there are %i\n", sptr+1);
    }
  }
}
