CC = gcc

CFLAGS = -g -Wall -pedantic
#CFLAGS = -O -Wall -pedantic
main : person.o pNode.h phone.o nNode.h

person.o phone.o : person.h phone.h

clean:
	rm -f *.o core main
