#ifndef NNODE_H
#define NNODE_H

typedef struct t_nNode {
	struct phone* number;
	enum place {Home, Cell, School} type;
	int primary;
	struct t_nNode* next;
} nNode;

#endif
