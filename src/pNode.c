
#include "all.h"

int queueper(pNode *p, phone *num){
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

int dequeueallper(pNode *node){
	if(node->next){
		dequeueallper(node->next);
	}
	free(node);
	return 0;
}
