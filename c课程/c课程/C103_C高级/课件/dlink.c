#include <stdio.h>
#include <stdlib.h>


typedef struct dlnode
{
	int data;
	struct dlnode *pri,*next;
}DLnode,*dlinklist;
int dlink_getLength(dlinklist head);
dlinklist dlink_searchByindex(dlinklist head,int index);

dlinklist dlink_create()
{
	dlinklist phead = NULL,s;
	int x;
	scanf("%d",&x);
	while(x!=0)
	{
		s=(dlinklist)malloc(sizeof(DLnode));
		if(s== NULL)
		{
			return phead;
		}
		s->data = x;
		if(phead == NULL)/*the first node*/
		{
			s->pri = NULL;
			s->next = NULL;
			phead = s;
		}
		else/*other node*/
		{
			s->pri = NULL;
			s->next = phead;
			phead->pri = s;
			phead = s;
		}
		scanf("%d",&x);
	}
	return phead;
}
dlinklist dlink_insert(dlinklist head,int data ,int index)
{
	dlinklist s=NULL;
	/*入参检查*/
	if(index < 1)
	{
		printf("param error\n");
		return head;
	}
	/*申请空间*/
	s=(dlinklist)malloc(sizeof(DLnode));
	s->data=data;
	if((head == NULL)||(index == 1))/*前插入*/
	{
		s->next = head;
		s->pri = NULL;
		if(head != NULL)
		{
			head->pri = s;
		}
		head = s;
	}
	else/*中间插入 尾插入*/
	{
		dlinklist p=NULL;
		int len = dlink_getLength(head);
		if(index>len)
			index = len+1;
		p=dlink_searchByindex(head ,index-1);
		if(p!=NULL)
		{
			s->next = p->next;				
			if(index != len+1)/*中间插入*/
			{
				p->next->pri = s;
			}
			p->next = s;
			s->pri = p;
		}
		else
		{
			printf("error!\n");
			free(s);
		}
	}
	return head;
}
int dlink_getLength(dlinklist head)
{
	dlinklist p=head;
	int len=0;
	while(p!=NULL)
	{
		len++;
		p=p->next;
	}
	return len;
}
dlinklist dlink_searchByindex(dlinklist head,int index)
{
	int i;
	dlinklist p=head;
	/*入参检查*/
	if((index<1)||(index>dlink_getLength(head)))
	{
		printf("index param error!\n");
		return NULL;
	}
	for(i=1;i<index;i++)
	{
		p=p->next;
	}
	return p;
}
void dlink_print(dlinklist head)
{
	dlinklist p = head,tail;
	if(head == NULL)
	{
		printf("empty dlink\n");
		return ;
	}
	printf("from begin to end\n");
	while(p!=NULL)
	{
		printf("[%d]->",p->data);
		tail = p;
		p = p->next;
	}
	printf("\nfrom end to begin\n");
	while(tail!=NULL)
	{
		printf("[%d]->",tail->data);
		tail = tail->pri;
	}
	printf("\n");
}

int main()
{
	dlinklist phead= NULL;
	phead=dlink_create();
	dlink_print(phead);
	phead = dlink_insert(phead , 555, 1);
	dlink_print(phead);
	return 0;
}
