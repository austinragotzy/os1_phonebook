#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nNode.h"
#include "person.h"
#include "phone.h"
#include "pNode.h"

int main(int argc, char * argv[]){
	person **perArray = malloc(sizeof(person)*100);
	addperson("austin", "ragotzy", "frost", perArray, 0);
	printf("%s\n", perArray[0]->nick);
	return 0;
}
