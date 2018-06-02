#include <stdio.h>
#include "link.h"

//以头插法创建一个链表
//返回值：头结点的地址
PNode linkCreat()
{
	PNode head = NULL;
	Node *s;
	int x;
	scanf("%d",&x);
	while (x != 0)
	{
		s = (PNode)malloc(sizeof(Node));	
		s->data = x;
		scanf("%s",s->name);
		s->next = head;
		head = s;
		scanf("%d",&x);
	}
	return head;
}

//以尾插法创建一个链表
//返回值：头结点的地址
PNode linkCreat2()
{
	PNode head = NULL,s=NULL,p=NULL;
	int x;
	scanf("%d",&x);
	while(x!=0)
	{
		s = (PNode) malloc(sizeof(struct node));
		if (s == NULL)
		{
			printf("malloc error..\n");
			return NULL;
		}
		s->data = x;
		scanf("%s",s->name);
		if(head == NULL)
			head = s;
		else
			p->next = s;
		p = s;
		scanf("%d",&x);
	}
	if (p != NULL)
		p->next = NULL;
	return head;
}

//打印链表的数据成员
void linkPrint(PNode head)
{
	PNode L=head;
	if(head == NULL)
		printf("link is null..\n");
	while(L != NULL)
	{
		printf("data:%d\tname:%s\n",L->data,L->name);
		L = L->next;
	}
}

//统计一个链表的长度
int linkLength(PNode head)
{
	int cnt=0;
	PNode L = head;
	if(head==NULL)
	{
		printf("link is null`");
	}
	else
	{
		while(L != NULL)
		{
			cnt++;
			L = L->next;
		}
	}
	return cnt;
}

//查找链表的第i个节点，从０开始计数
PNode linkSearchByIndex(PNode head,int i)//i=2
{
	PNode L = head;
	int j = 0;
	while(L->next!=NULL && j<i)
	{
		L = L->next;
		j++;
	}
	if (j==i)
		return L;
	else
		return NULL;
}

//删除链表的第i个结点i,从0开始计数
PNode nodeDelete(PNode head,int i)
{
	PNode s,p;
	int len;
	len = linkLength(head);
	if(head == NULL)
	{
		printf("link is null..\n");
	}
	if (i==0)
	{
		s = head;
		head = head->next;
		free(s);
		s = NULL;
	}
	else if (i<len)
	{
		s = linkSearchByIndex(head,i-1);	
		p = s->next;
		s->next = p->next;
		free(p);
		p = NULL;
	}
	else
	{
		s = linkSearchByIndex(head,len-2);
		p = s->next;
		s->next = p->next;
		free(p);
		p = NULL;
	}
	return head;
}

//创建一个新的结点
PNode nodeCreat()
{
	PNode s = (PNode)malloc(sizeof(Node));
	printf("请输入新结点的数据:\n");
	scanf("%d",&s->data);
	scanf("%s",s->name);
	s->next = NULL;
	return s;
}


//在链表的第i个位置插入一个新结点i,从0开始计数
PNode nodeInsertByIndex(PNode head,int i)
{
	PNode New = NULL,p=NULL;
	New = nodeCreat();

	if(i==0 || head == NULL)
	{
		New->next = head;
		head = New;
	}
	else if(i > linkLength(head)-1)
	{
		p = linkSearchByIndex(head,linkLength(head)-1);
		p->next = New;
		New->next = NULL;
	}
	else
	{
		p = linkSearchByIndex(head,i-1);
		New->next = p->next;
		p->next = New;
	}
	return head;
}


//查找链表里面data值最大的结点
PNode searchMaxByData(PNode head)
{
	PNode temp,p;
	p = head;
	temp = head;
	if(head == NULL)
	{
		printf("link is null..\n");
		return NULL;
	}
	while(p != NULL)
	{
		if (p->data > temp->data)
			temp = p;
		p = p->next;
	}
	return temp;
}

//查找链表里面data值最小的结点
PNode searchMinByData(PNode head)
{
	PNode temp,p;
	p = head;
	temp = head;
	if(head == NULL)
	{
		printf("link is null..\n");
		return NULL;
	}
	while(p != NULL)
	{
		if (p->data < temp->data)
			temp = p;
		p = p->next;
	}
	return temp;
}
//删除链表
PNode linkDelete(PNode head)
{
	PNode p = head;	
	while(head != NULL)
	{
		head = head->next;
		free(p);
		p = head;
	}
	return head;
}

//将某结点从原链表移除
PNode removeFromOld(PNode head,PNode pDes)
{
	if (head == pDes)
	{
		head = head->next;
	}
	else //需要移除的结点是其它位置的结点
	{
		PNode p=head;
		while(p != NULL)
		{
			if(p->next == pDes)
				break;
			p=p->next;
		}
		p->next = pDes->next;
	}
	return head;
}

//用头插法重新组建链表
PNode addToNew(PNode head,PNode pDes)
{
	pDes->next = head;
	head = pDes;
	return head;
}

//链表升序排序
PNode linkSort(PNode head)
{
	PNode pMax=NULL,pNew=NULL;
	while(head != NULL)
	{
		pMax = searchMaxByData(head);
		head = removeFromOld(head,pMax);
		pNew = addToNew(pNew,pMax);
	}
	return pNew;
}

//通过data找到成员，并打印该成员的所有信息
PNode nodeSearchByData(PNode head,int x)
{
	PNode p = head;
	if (p==NULL)
	{
		printf("link is null..\n");
		return NULL;
	}
	while(p!=NULL)
	{
		if(p->data == x)
			break;
		p=p->next;
	}
	return p;
}

//修改制定成员的数据（ｎａｍｅ）
void nodeModify(PNode head,int x)
{
	PNode p = head;
	PNode fNode=NULL;
	fNode = nodeSearchByData(head,x);
	if(fNode == NULL)
	{
		printf("未找到指定成员");
		return;
	}
	else
	{
		printf("成员%d已经找到，请输入新的name:",x);
		scanf("%s",fNode->name);
	}
}










