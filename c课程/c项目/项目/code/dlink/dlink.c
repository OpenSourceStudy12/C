/*
*corporation:
*fileName:dlink.c
*author:
*date:
*modify:   who why date
*/
/*including files*/
#include "dlink.h"
/*global variable declare*/

/*local function declare*/
static void aaa();


/*
*Function: the main entry
*param: none
*return value:0 :success,-1:fail
*instruction:
*/
int main()
{
       pDlink phead=NULL;
	aaa();
	dlink_create(&phead);
	print_dlink(phead);
	return 0;
}
static void aaa()
{
	printf("the main beginning\n");
}
/*
*Function: create the double link
*param: the address of the head pointer
*return value:0 :success,-1:fail
*instruction:
*/
int dlink_create(pDlink *phead)
{
	pDlink p=NULL;
	int temp=0;
	
	scanf("%d",&temp);
	while(1)
	{
		if(temp == 999)
		{
		   break;
		}
		p=(pDlink)malloc(sizeof(DNode));
		if(p==NULL)
		{
		   printf("the momery error!");
		   return -1;
		}
		p->data=temp;
		if(*phead!=NULL)/*the other node*/
		{
		   (*phead)->pri=p;
		}
	
		p->next=*phead;
		p->pri=NULL;
		(*phead)=p;
		scanf("%d",&temp);
		
	}
	return 0;
}
int print_dlink(pDlink phead)
{
	pDlink p,pTail;
	printf("print the data from BEGINNING to END\n");
	p = phead;
	while(p)
	{
	   printf("[%d]->",p->data);
	   pTail=p;
	   p=p->next;
	}
	printf("\n");
	printf("print the data from END to BEGIN\n");
	while(pTail!=NULL)
	{
	    printf("[%d]->",pTail->data);
	    pTail=pTail->pri;
	}
	printf("\n");
	return 0;
}
