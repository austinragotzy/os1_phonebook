#ifndef NNODE_H
#define NNODE_H
#include "first.h"
struct t_nNode {
	struct t_phone* number;
	place type;
	int primary;
	struct t_nNode* next;
};
int queuenum(nNode *n, person *per);
int dequeueallnum(nNode *node);

#endif
