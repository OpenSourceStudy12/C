#include<stdio.h>
#include"fun.h"

/*头插法创建链表*/
PNode linkcreat_from_end()
{
	PNode head = NULL;
	PNode p;
	int x;
	printf("please input a num:\n");
	scanf("%d",&x);
	while(x)
	{
		
		if(link_full())
			return NULL;
		else
		{
			p = (PNode)malloc(sizeof(Node));
			p->num = x;
			p->next = head;
			head = p;
			printf("please input a num again:\n");
			scanf("%d",&x);
		}
	}
	return head;
}

/*尾插法创建链表*/
PNode linkcreat_from_head()
{
	PNode head = NULL,L = NULL,p = NULL;
	int x;
	printf("请输入学号:\n");
	scanf("%d",&x);
	while(x)
	{

		//L = (PNode)malloc(sizeof(Node));
		//if(L == NULL)
		//	return NULL;
		if(link_full());
			return NULL;
		else
		{
			L = (PNode)malloc(sizeof(Node));
			L->num = x;
			if(head == NULL)
				head = L;
			else
				p->next = L;
			p = L;
			L->next = NULL;
			printf("请输入姓名、成绩:\n");
			scanf("%s%f",L->name,&L->score);
			printf("请输入学号:\n");
			scanf("%d",&x);

		}
	}
	return head;
}

/*判断链表是否已满，已满返回1,未满返回0*/
static int link_full()
{
	PNode L;
	if((L = (PNode)malloc(Node)) != NULL)
	{
		free(L);
		L = NULL
		return 0;
	}
	else 
	{
		free(L);
		L = NULL;
		return 1;
	}
}



/*打印链表*/
void linkprint(const PNode head)
{
	PNode p = head;
	if(p == NULL)
		printf("The link is null\n");
	else
	{
		printf("学号\t姓名\t\t成绩:\n");
		while(p != NULL)
		{
			printf("%d\t%s\t\t%.2f\n",p->num,p->name,p->score);
			p = p->next;
		}
	}
}

/*计算链表长度*/ //序号
int linklen(PNode head)
{
	int cnt = 0;
	PNode L = head;
/*	while(L != NULL)
	{
		cnt++;
		L = L->next;
	}
	if(!cnt)
		printf("The link is null:\n");
*/
	while(L->next != NULL)
	{
		cnt++;
		L = L->next;
	}
	if(!cnt)
		printf("The link is null:\n");
	return cnt;
}

/*查找序号为t的链表数据*/ //通过序号
PNode linksearch(PNode head,int t)
{
/*从0开始*/
	
	PNode L = head;
	int i = 0;
	while(L->next != NULL && i<t)
	{
		i++;
		L = L->next;
	}
	if(i==t)
		return L;
	else
		return NULL;

	
/*从1开始*/
/*
	PNode L = head;
	int i=0;
	while(L != NULL && i<t+1)	
	{
		i++;
		L = L->next;
	}
	if(i == t+1)
	{
		 
	}
*/
}

/***************删除节点*******************
首先判断是否为空链表,若不是，则考虑三种情况,
删除第0个节点,删除中间节点，或删除尾结点(包
括节点序号大于链表长度)****************/
PNode nodedel(PNode head,int n)
{
	PNode L,P;
	int len = linklen(head);
	if(head == NULL)
	{	
		printf("The link is null\n");
		return head;
	}
	if(n==0)
	{
		L = head;
		head = head->next;
		free(L);
		L = NULL;
	}
	else if(n < len)
	{
		L = linksearch(head,n-1);
		P = L->next;
		L->next = P->next;
		free(P);
		P = NULL;
	}
	else
	{
		L = linksearch(head,len-1);
		P = L->next;
		L->next = NULL;
		free(P);
		P = NULL;
	}
	return head;

}

/*创建节点*/
static PNode nodecreat()
{
	PNode p = NULL;
	if(!link_full())
	{
		p = (PNode)malloc(sizeof(Node));
		printf("请输入节点数据:\n");
		scanf("%d",&p->num);
		p->next = NULL;
	}
	return p;
}

/*增加节点*/
PNode nodeadd(PNode head,int n)
{
	PNode p=NULL,New=NULL;
	New = nodecreat();
	if(n==0 || head == NULL)
	{
		New->next = head;
		head = New;
	}
	else if(n >= linklen(head))
	{
		p = linksearch(head,linklen(head)-1);
		p->next = New; 
		New->next = NULL;
	}
	else
	{
		p = linksearch(head,n-1);
		New->next = p->next;
		p->next = New;
	}	 
	return head;
}

/*寻找链表最大值*/
PNode link_sh_max(PNode head)
{
	PNode temp = head,p = head;
	while(p != NULL)
	{
		if(p->num > temp->num)
			temp = p;
		p = p->next;
	}
	return temp;
}

/*寻找链表最小值*/
PNode link_sh_min(PNode head)
{
	PNode temp = head,p = head;
	while(p != NULL)
	{
		if(p->num < temp->num)
			temp = p;
		p = p->next;
	}
	return temp;
}

/*删除链表*/
PNode linkdel(PNode head)
{
	PNode p = head;
	while(head !=NULL)
	{
		head = head->next;
		free(p);
		p = head;
	}
	return head;
}

/*寻找链表最大值 返回最大值节点地址*/
static PNode pmaxsearch(PNode head)
{
	PNode p = head->next,pmax = head;
	while(p != NULL)
	{
		if(p->score > pmax->score)
			pmax = p;
		p = p->next;
	}
	return pmax;
}	

/*将某节点从链表移除 返回链表头指针*/
static PNode node_del(PNode head,PNode pmax)
{
	PNode p = head;
	if(pmax == head)
	{
		head = head->next;
	}
	else
	{
		while(p->next != NULL)
		{
			if(p->next == pmax)
			{
				p->next = pmax->next;
				break;
			}	
			p = p->next;
		}
	}
	return head;
}

/*以头插法将节点插入到新链表中*/
static PNode node_add(PNode headnew,PNode pmax)
{
	pmax->next = headnew;
	headnew = pmax;
	return headnew;
}
/*对链表进行升序排序*/
PNode linksort(PNode head)
{
	PNode pmax = NULL,headnew = NULL;
	while(head != NULL)
	{
		pmax = pmaxsearch(head);
		head = node_del(head,pmax);
		headnew = node_add(headnew,pmax);
	}
	return headnew;
}


