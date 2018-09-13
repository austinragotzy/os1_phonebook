
#include "all.h"

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

int linkperson(person *per, phone *num, place type, int primary){
	// make a nNode to insert in the list
	nNode *n = malloc(sizeof(nNode));
	n->number = num;
	n->type = type;
	n->primary = primary;

	if(!per->number){// if no number nodes attatched add a head
		per->number = n;

	}else{// if numbers are there already attatch it to the tail
		nNode *stepper = per->number;// stepper is to iterate through the list
		while(stepper->next){// steps through the list
			stepper = stepper->next;
		}

		stepper->next = n;//once we reach the current last element put one after it
	}

	return 0;
}
