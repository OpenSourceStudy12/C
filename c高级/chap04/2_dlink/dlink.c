#include <stdio.h>
#include "dlink.h"
#include <stdlib.h>
//用头插法创建一个双向链表
//返回值：双向链表的头结点地址
PNode dLinkCreat()
{
	PNode head=NULL,s;
	int x;
	scanf("%d",&x);
	while(x != 0)
	{
		s = (PNode)malloc(sizeof(Node));
		if(s == NULL)
		{
			printf("malloc error!..\n");
			break;
		}
		s->data=x;
		if(head == NULL)
		{
			head = s;
			head->next = NULL;
			head->pri = NULL;
		}
		else
		{
			s->pri = NULL;
			s->next = head;
			head->pri = s;
			head = s;
		}
		scanf("%d",&x);
	}
	return head;
}

void dLinkPrint(PNode head)
{
	PNode p=head,tail;
	if (head == NULL)
	{
		printf("dlink is null..\n");
		return;
	}
	printf("print from begin to end:\n");
	while(p!=NULL)
	{
		printf("data:%d\n",p->data);
		tail = p;
		p = p->next;
	}
	printf("print from end to bengin:\n");
	while(tail != NULL)
	{
		printf("data:%d\n",tail->data);
		tail = tail->pri;
	}
}

int dLinkLength(PNode head)
{
	PNode p=head;
	int i=0;
	while(p!=NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}
