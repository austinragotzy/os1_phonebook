#include "all.h"


int addphone(char *number, phone **pArray, int i){
	pArray[i] = malloc(sizeof(phone));
	pArray[i]->number = malloc(strlen(number)+1);
	strcpy(pArray[i]->number, number);
	return 0;
}

int linkphone(phone *num, person *per){
	// make a pNode to insert into the list
	pNode *p = malloc(sizeof(pNode));
	p->person = per;

	if(!num->owner){// if no pNodes are attached add to head
		num->owner = p;

	}else{// if already has owners put it on the tail
		pNode *stepper = num->owner;// stepper is to itterate through the list
		while(stepper->next){// step through the list
			stepper = stepper->next;
		}

		stepper->next = p;//once we reach the current last element put one after it
	}

	return 0;
}
