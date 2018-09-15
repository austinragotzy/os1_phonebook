
#include "all.h"

int main(int argc, char * argv[]){
	person **perArray = malloc(sizeof(person)*100);
	phone **numArray = malloc(sizeof(phone)*100);
	readfile(argv[1], perArray, numArray);
	deleteperson(perArray);
	deletephone(numArray);
	free(perArray);
	free(numArray);
	return 0;
}
