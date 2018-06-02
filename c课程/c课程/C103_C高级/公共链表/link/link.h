#include <stdio.h>


typedef struct node
{
	void *data;
	struct node *next;
}LNode,*linklist;


typedef struct link
{
	linklist phead;
	int len;
}Llink;

Llink *link_init();
int link_insert(Llink *plink,void *data);
linklist link_search(Llink *plink , int index);
