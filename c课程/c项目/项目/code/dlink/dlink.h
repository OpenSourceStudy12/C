#ifndef _DLINK_H
#define _DLINK_H
/*including files*/
#include <stdio.h>
#include <stdlib.h>
/*global variable declare*/
typedef struct node
{
	int data;
	struct node *pri,*next;
}DNode,*pDlink;
/*global function declare*/
int dlink_create(pDlink *phead);
int print_dlink(pDlink phead);



#endif
