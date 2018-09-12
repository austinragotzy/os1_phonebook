
#include "person.h"

int addperson(char *first, char *last, char *nick, person **pArray, int i){
	pArray[i] = malloc(sizeof(person));
	pArray[i]->first = malloc(strlen(first)+1);
	pArray[i]->last = malloc(strlen(last)+1);
	pArray[i]->nick = malloc(strlen(nick)+1);
	strcpy(pArray[i]->first, first);
	strcpy(pArray[i]->last, last);
	strcpy(pArray[i]->nick, nick);
	return 0;
}
