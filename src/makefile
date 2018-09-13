CC = gcc

CFLAGS = -g -Wall -pedantic
#CFLAGS = -O -Wall -pedantic
main : person.o pNode.h phone.o nNode.h first.h

person.o phone.o : all.h

all.h: first.h person.h phone.h pNode.h nNode.h
	touch all.h

clean:
	rm -f *.o core main

run: main
	./main

debug:
	gdb ./debug
