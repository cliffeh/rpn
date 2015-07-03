rpn: rpn.o
	$(CC) $(CFLAGS) -o $@ $^

rpn.o: rpn.c

clean:
	rm -f *.o

realclean: clean
	rm rpn
