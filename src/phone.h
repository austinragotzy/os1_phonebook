#ifndef PHONE_H
#define PHONE_H

typedef struct t_phone {
	char* number;
	struct pNode* owner;
} phone;

int addphone(char *number, phone **pArray, int i);
int linkphone(phone *num, struct person *per);
phone *searchphone(phone **pArray);
#endif
