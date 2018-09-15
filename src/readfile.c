#include "all.h"

int readfile(char *file, person **pArray, phone **nArray){

	FILE *fp = fopen(file, "r");
	char *buf = malloc(512);
	char *temp = malloc(64);
	char *number = malloc(16);
	place type;
	int primary;
	char *first = malloc(32);
	char *middle = malloc(32);
	char *last = malloc(32);
	char *nick = malloc(32);
	int pindex = 0;
	int exindex;
	int nindex = 0;

	while(fgets(buf, 512, fp)){
		if(*buf=='<'){
			// dont do anything with what you have go to the next line
		}else{
			strsep(&buf, "	");
			if(*buf=='('){//when the line is a phone number
				strncpy(number, buf, 14);
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
				strsep(&buf, " ");
				if(strncmp(buf, "tru", 3)==0){
					primary = 1;
				}else if(strncmp(buf, "fal", 3)==0){
					primary = 0;
				}
				if((exindex = addphone(number, nArray, nindex))<0){//if the number isnt there
					linkphone(nArray[nindex], pArray[pindex-1]);
					linkperson(pArray[pindex-1], nArray[nindex], type, primary);
				}else{//if the number is there already
					linkphone(nArray[exindex], pArray[pindex-1]);
					linkperson(pArray[pindex-1], nArray[exindex], type, primary);
				}
				nindex++;
			}else{//when the line is a name
				//parce that line and put it into the struct and stuff
				temp = strsep(&buf, ", ");
				strncpy(last, temp, 32);
				strsep(&buf, " ");
				temp = strsep(&buf, ", ");
				strncpy(middle, temp, 32);
				strsep(&buf, " ");
				temp = strsep(&buf, ", ");
				strncpy(first, temp, 32);
				strsep(&buf, " ");
				strncpy(nick, buf, 32);
				strncpy(nick+strlen(nick)-1, "\0", 2);
				addperson(first, middle, last, nick, pArray, pindex);

				pindex++;
			}
		}
	}
	return 0;
}
