
#include "all.h"

int main(int argc, char * argv[]){
	person **perArray = malloc(sizeof(person)*100);
	phone **numArray = malloc(sizeof(phone)*100);
	int mode;
	char *buf = malloc(64);

	if(argc!=2){
		printf("enter the file:\n");
		fgets(buf, 64, stdin);
		strncpy(buf+strlen(buf)-1, "\0", 2);
	}else{
		strncpy(buf, argv[1], 64);
	}
	FILE *fp;
	while(!(fp = fopen(buf, "r"))){
		printf("file not found renter the file:\n");
		fgets(buf, 64, stdin);
		strncpy(buf+strlen(buf)-1, "\0", 2);
	}
	readfile(fp, perArray, numArray);
	while((mode = uistart())<3){
		uisearch(mode, perArray, numArray);
	}

	deleteperson(perArray);
	deletephone(numArray);
	free(perArray);
	free(numArray);
	free(buf);
	return 0;
}
