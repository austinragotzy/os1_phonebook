#ifndef PHONE_H
#define PHONE_H

struct t_phone {
	char* number;
	pNode* owner;
};

int addphone(char *number, phone **pArray, int i);
int linkphone(phone *num, person *per);
int searchphone(char *target, phone **pArray);
int deletephone(phone **numArray);
int deletepnode(pNode *node);
#endif
