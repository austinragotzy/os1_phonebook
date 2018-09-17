
#include "all.h"

int addphone(char *number, phone **pArray, int i){
	int ret;
	if((ret = searchphone(number, pArray))==-1){// if number is not there
		pArray[i] = malloc(sizeof(phone));
		pArray[i]->number = malloc(strlen(number)+1);
		strcpy(pArray[i]->number, number);
	}

	return ret;
}

int linkphone(phone *num, person *per){
	// make a pNode to insert into the list
	pNode *p = malloc(sizeof(pNode));
	p->person = per;
	p->next = NULL;

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

int searchphone(char *target, phone **pArray){

	int i = 0;
	int index = -1;
	int trigger = 1;

	while(pArray[i]&&trigger){// search for the phone array
		if(strncmp(pArray[i]->number, target, 14)==0){
			index = i;
			trigger = 0;
		}

		i++;
	}

	return index;
}

int deletephone(phone **numArray){
	int i=0;
	while(numArray[i]){
		if(numArray[i]->owner){
			deletepnode(numArray[i]->owner);
		}
		free(numArray[i]->number);
		free(numArray[i]);
		i++;
	}
	return 0;
}

int deletepnode(pNode *node){
	if(node->next){
		deletepnode(node->next);
	}
	free(node);
	return 0;
}
