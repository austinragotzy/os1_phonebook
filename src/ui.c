
#include "all.h"

int uistart(){
	char *buf = malloc(4);
	printf("to search by person enter: 1 \n");
	printf("to search by phone enter:  2 \n");
	printf("to exit enter:             3 \n");
	fgets(buf, 3, stdin);
	int mode = atoi(buf);

	free(buf);
	//if its not the right number use recursion untill the right number is input
	if(mode!=1&&mode!=2&&mode!=3){
		mode = uistart();
	}
	return mode;
}

int uisearch(int mode, person **perArray, phone **numArray){
	char *first = malloc(32);
	char *last = malloc(32);
	char *number = malloc(17);
	int index;

	if(mode==1){//get person and search then report
		printf("enter the first or nickname name: \n");
		fgets(first, 30, stdin);
		strncpy(first+strlen(first)-1, "\0", 2);
		printf("enter the last name or if you entered nickname enter \"nick\": \n");
		fgets(last, 30, stdin);
		strncpy(last+strlen(last)-1, "\0", 2);
		index = searchperson(first, last, perArray);
		if(index > -1){
			uireportper(index, perArray);
		}else{
			printf("person was not found\n");
		}
	}else{//get number then search and report
		printf("enter the phone number (XXX) XXX-XXXX: \n");
		fgets(number, 16, stdin);
		strncpy(number+strlen(number)-1, "\0", 2);
		index = searchphone(number, numArray);
		if(index > -1){
			uireportnum(index, numArray);
		}else{
			printf("number was not found\n");
		}
	}

	free(first);
	free(last);
	free(number);
	return 0;
}

int uireportper(int index, person **perArray){
	person *p = perArray[index];
	char *place = malloc(16);
	char *prim = malloc(8);
	printf("%s %s %s aka %s\n", p->first, p->middle, p->last, p->nick);
	nNode *numbers;
	if(p->number){
		numbers = p->number;
		while(numbers){
			if(numbers->type==0){
				strcpy(place, "Home");
			}else if(numbers->type==1){
				strcpy(place, "Cell");
			}else{
				strcpy(place, "School");
			}
			if(numbers->primary==0){
				strcpy(prim, "false");
			}else{
				strcpy(prim, "true");
			}
			printf("%s Type: %s Primary: %s\n", numbers->number->number, place, prim);
			numbers = numbers->next;
		}

	}
	printf("\n");
	free(place);
	free(prim);
	return 0;
}

int uireportnum(int index, phone **numArray){
	phone *p = numArray[index];
	char *place = malloc(16);
	char *prim = malloc(8);
	pNode *people;
	person *owner;
	nNode *ninfo;
	if(p->owner){
		people = p->owner;
		while(people){
			owner = people->person;
			ninfo = owner->number;
			//find the node that matches the number we are reporting
			while(strcmp(ninfo->number->number, p->number)!=0){
				//this loop is a little dangerous
				ninfo = ninfo->next;
			}
			if(ninfo->type==0){
				strcpy(place, "Home");
			}else if(ninfo->type==1){
				strcpy(place, "Cell");
			}else{
				strcpy(place, "School");
			}
			if(ninfo->primary==0){
				strcpy(prim, "false");
			}else{
				strcpy(prim, "true");
			}
			printf("%s %s, Phone Type: %s, Primary: %s\n",
			owner->first, owner->last, place, prim);
			people = people->next;
		}
	}
	printf("\n");
	free(place);
	free(prim);
	return 0;
}
