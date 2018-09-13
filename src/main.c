
#include "all.h"

int main(int argc, char * argv[]){
	person **perArray = malloc(sizeof(person)*100);
	phone **numArray = malloc(sizeof(phone)*100);
	addperson("austin", "ragotzy", "frost", perArray, 0);
	addperson("ebony", "ragotzy", "bossladye", perArray, 1);
	addphone("(234)-213-1923", numArray, 0);
	addphone("(138)-212-3322", numArray, 1);
	place type = Home;
	linkperson(perArray[0], numArray[0], type, 1);
	linkphone(numArray[0], perArray[0]);
	linkphone(numArray[0], perArray[1]);
	place type1 = Cell;
	linkperson(perArray[0], numArray[1], type1, 0);
	printf("%s %d %d\n", perArray[0]->nick, perArray[0]->number->primary, perArray[0]->number->next->primary);
	printf("%s %s %s\n", numArray[0]->number, numArray[0]->owner->person->first, numArray[0]->owner->next->person->nick);
	return 0;
}
