
#include "all.h"

int main(int argc, char * argv[]){
	person **perArray = malloc(sizeof(person)*100);
	phone **numArray = malloc(sizeof(phone)*100);
	int mode;
	int percount = 0;
	int phocount = 0;

	FILE *fp;
	openfile(argc, argv, &fp);
	readfile(fp, perArray, &percount, numArray, &phocount);
	fclose(fp);
	while((mode = uistart())<3){
		uisearch(mode, perArray, numArray);
	}

	deleteperson(perArray);
	deletephone(numArray);
	free(perArray);
	free(numArray);

	return 0;
}
