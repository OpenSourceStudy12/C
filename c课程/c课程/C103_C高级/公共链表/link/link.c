/*
*
*
*/
#include "link.h"
#include <stdlib.h>
#include <string.h>
Llink *link_init()
{
	Llink *plink=(Llink *)malloc(sizeof(Llink));
	plink->phead=NULL;
	plink->len = 0;
	return plink;
}
/*默认尾插*/
int link_insert(Llink *plink,void *data)
{
	linklist head=NULL,tail=NULL,s=NULL; 
	if(plink == NULL)
	{
		printf("link description error!\n");
		return -1;
	}
	head = plink->phead;
	s = (linklist)malloc(sizeof(LNode));
	memset(s,0,sizeof(LNode));
	s->data=data;
	s->next = NULL;
	if(head == NULL)
	{
		plink->phead = s;
	}
	else
	{
		while(head!=NULL)
		{
			tail = head;
			head = head->next;
		}
		tail->next = s;
	}
	plink->len++;
	return 0;
}
linklist link_search(Llink *plink , int index)
{
	int len = plink->len;
	int i=0;
	linklist p = plink->phead;
	if((index <1)&&(index>len))
	{
		printf("param error\n");
		return NULL;
	}
	for(i=0;i<index-1;i++)
		p = p->next;
	return p;
}
int link_print(Llink *plink)
{
	linklist head=plink->phead;
	if(plink == NULL)
	{
		printf("link description error!\n");
		return -1;
	}
	if(head == NULL)
	{
		printf("empty link");
	}
	else
	{
		printf("had nodes");
	}
}
