#ifndef PNODE_H
#define PNODE_H

struct t_pNode {
	struct t_person* person;
	struct t_pNode* next;
};

#endif
