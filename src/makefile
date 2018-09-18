CC = gcc

CFLAGS = -g -Wall -pedantic
#CFLAGS = -O -Wall -pedantic
main: person.o pNode.o phone.o readfile.o ui.o nNode.o first.h

person.o phone.o readfile.o ui.o nNode.o pNode.o: all.h

all.h: first.h person.h phone.h pNode.h nNode.h readfile.h ui.h
	touch all.h

clean:
	rm -f *.o core main

run: main
	./main input.html

debug:
	gdb ./main

valgrind:
	valgrind ./main
