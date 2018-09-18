
#include "all.h"

int queuenum(nNode *n, person *per){
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

int dequeueallnum(nNode *node){
	if(node->next){
		dequeueallnum(node->next);
	}
	free(node);
	return 0;
}
