#ifndef PERSON_H
#define PERSON_H

struct t_person {
	char* first;
	char* middle;
	char* last;
	char* nick;
	nNode* number;
};

int addperson(char *first, char *middle, char *last, char *nick, person **pArray, int i);
int linkperson(person *per, phone *num, place type, int primary);
int searchperson(char *ftarget, char *ltarget, person **pArray);
int deleteperson(person **perArray);
int deletennode(nNode *node);

#endif
