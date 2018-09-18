
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
	queueper(p, num);
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
			dequeueallper(numArray[i]->owner);
		}
		free(numArray[i]->number);
		free(numArray[i]);
		i++;
	}
	return 0;
}
