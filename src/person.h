#ifndef PERSON_H
#define PERSON_H

struct t_person {
	char* first;
	char* last;
	char* nick;
	nNode* number;
};

int addperson(char *first, char *last, char *nick, person **pArray, int i);
int linkperson(person *per, phone *num, place type, int primary);
int searchperson(person **pArray);

#endif
