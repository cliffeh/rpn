CFLAGS=-g
YFLAGS=--defines=symbols.h

rpn: main.o lexer.o parser.o
	$(CC) -ll $(CFLAGS) -o $@ $^

main.o: main.c

parser.o: parser.c

parser.c: parser.y

symbols.h: parser.c

lexer.o: symbols.h lexer.c

lexer.c: lexer.l

clean:
	rm -f *.o lexer.c parser.c symbols.h

realclean: clean
	rm -f rpn
