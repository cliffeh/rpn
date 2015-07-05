CFLAGS=-g
YFLAGS=--defines=symbols.h
TESTS=$(patsubst %.in, %, $(wildcard test/*.in))

rpn: main.o lexer.o parser.o ops.o
	$(CC) -ll $(CFLAGS) -o $@ $^

main.o: main.c

parser.o: parser.c

parser.c: parser.y

symbols.h: parser.c

lexer.o: symbols.h lexer.c

lexer.c: lexer.l

ops.o: ops.c

run-tests: rpn
	for file in $(TESTS); do ./rpn < $$file.in | diff $$file.output -; done

clean:
	rm -f *.o lexer.c parser.c symbols.h

realclean: clean
	rm -f rpn
