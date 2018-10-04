#include "all.h"


int readfile(FILE *fp, person **pArray, phone **nArray){

	char *buf1 = malloc(512);
	char *buf;
	int pindex = 0;
	int nindex = 0;

	while(fgets(buf1, 512, fp)){
		buf = buf1;
		if(*buf=='<'){
			// dont do anything with what you have go to the next line
		}else{
			//strsep(&buf, "	");
			if(*buf=='('){//when the line is a phone number
				if(parceplacePhone(buf, pArray, nArray, pindex, nindex)){
					nindex++;
				}
			}else{//when the line is a name
				parceplacePerson(buf, pArray, pindex);
				pindex++;
			}
		}
	}
	free(buf1);
	return 0;
}

int parceplacePerson(char *buf, person **pArray, int pindex){
	char *first = malloc(32);
	char *middle = malloc(32);
	char *last = malloc(32);
	char *nick = malloc(32);
	char *temp;
	//parce last name
	temp = strsep(&buf, ", ");
	strncpy(last, temp, 32);
	//parce middle name
	strsep(&buf, " ");
	temp = strsep(&buf, ", ");
	strncpy(middle, temp, 32);
	//parce first name
	strsep(&buf, " ");
	temp = strsep(&buf, ", ");
	strncpy(first, temp, 32);
	//parce nickname
	strsep(&buf, " ");
	strncpy(nick, buf, 32);
	strncpy(nick+strlen(nick)-1, "\0", 2);
	//add it to the array
	addperson(first, middle, last, nick, pArray, pindex);
	//free the mem
	free(first);
	free(middle);
	free(last);
	free(nick);
	return 0;
}

int parceplacePhone(char *buf, person **pArray, phone **nArray, int pindex, int nindex){
	char *number = malloc(16);
	place type;
	int primary;
	char *temp;
	int exindex;
	int ret;
	//parce phone number
	strncpy(number, buf, 14);
	//parce phone type
	strsep(&buf, " ");
	strsep(&buf, " ");
	temp = strsep(&buf, ", ");
	if(strncmp(temp, "Ce", 2)==0){
		type = Cell;
	}else if(strncmp(temp, "Sc", 2)==0){
		type = School;
	}else if(strncmp(temp, "Ho", 2)==0){
		type = Home;
	}
	//parce if primary
	strsep(&buf, " ");
	if(strncmp(buf, "tru", 3)==0){
		primary = 1;
	}else if(strncmp(buf, "fal", 3)==0){
		primary = 0;
	}
	//add to the array and link phone to person and person to phone
	if((exindex = addphone(number, nArray, nindex))<0){//if the number isnt there
		linkphone(nArray[nindex], pArray[pindex-1]);
		linkperson(pArray[pindex-1], nArray[nindex], type, primary);
		ret = 1;
	}else{//if the number is there already
		linkphone(nArray[exindex], pArray[pindex-1]);
		linkperson(pArray[pindex-1], nArray[exindex], type, primary);
		ret = 0;
	}
	//free the mem
	free(number);
	return ret;
}
