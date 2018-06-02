#ifndef _TREE_BROTHER_H
#define _TREE_BROTHER_H

#include<stdlib.h>

typedef struct treenode
{
	char ch;
	struct treenode *child;
	struct treenode *brother;
}TN,*PTN;


PTN tree_b_c_creat(int n);

#endif
