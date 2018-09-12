#ifndef PNODE_H
#define PNODE_H

typedef struct t_pNode {
	struct person* person;
	struct t_pnode* next;
} pNode;

#endif
