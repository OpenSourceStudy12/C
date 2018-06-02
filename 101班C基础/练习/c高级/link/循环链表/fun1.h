#ifndef _fun1_H
#define _fun1_H

#include<stdlib.h>
//#include<string.h>
#define SIZEMAX 20

//struct  link
//{
//	PNODE head;
//	PNODE tail;
//}

typedef struct node
{
	int num;
	char name[SIZEMAX];
	float score;
	struct node *next;
}NODE,*PNODE;

PNODE linkcreat();
void link_display(PNODE L);
#endif
