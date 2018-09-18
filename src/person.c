
#include "all.h"

int addperson(char *first, char *middle, char *last, char *nick, person **pArray, int i){
	pArray[i] = malloc(sizeof(person));
	pArray[i]->first = malloc(strlen(first)+1);
	pArray[i]->middle = malloc(strlen(middle)+1);
	pArray[i]->last = malloc(strlen(last)+1);
	pArray[i]->nick = malloc(strlen(nick)+1);
	strcpy(pArray[i]->first, first);
	strcpy(pArray[i]->middle, middle);
	strcpy(pArray[i]->last, last);
	strcpy(pArray[i]->nick, nick);
	return 0;
}

int linkperson(person *per, phone *num, place type, int primary){
	// make a nNode to insert in the list
	nNode *n = malloc(sizeof(nNode));
	n->number = num;
	n->type = type;
	n->primary = primary;
	n->next = NULL;

	queuenum(n, per);

	return 0;
}

int searchperson(char *ftarget, char *ltarget, person **pArray){
	int i = 0;
	int index = -1;
	int trigger = 1;

	while(pArray[i]&&trigger){
		if(strncmp(pArray[i]->first, ftarget, 32)==0){
			if(strncmp(pArray[i]->last, ltarget, 32)==0){
				index = i;
				trigger = 0;
			}
		}

		i++;
	}
	i=0;
	while(pArray[i]&&trigger){
		if(strncmp(pArray[i]->nick, ftarget, 32)==0){
			index = i;
			trigger = 0;
		}
		i++;
	}

	return index;
}

int deleteperson(person **perArray){
	int i=0;
	while(perArray[i]){
		if(perArray[i]->number){
			dequeueallnum(perArray[i]->number);
		}
		free(perArray[i]->first);
		free(perArray[i]->middle);
		free(perArray[i]->last);
		free(perArray[i]->nick);
		free(perArray[i]);
		i++;
	}
	return 0;
}
