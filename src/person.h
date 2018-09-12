#ifndef PERSON_H
#define PERSON_H
#include <string.h>
#include <stdlib.h>
typedef struct t_person {
	char* first;
	char* last;
	char* nick;
	struct nNode* number;
} person;

int addperson(char *first, char *last, char *nick, person **pArray, int i);
int linkperson(person *per, struct phone *num);
int searchperson(person **pArray);

#endif
