/*********************************************************
*file name:
*function:链表接口函数，链表操作的的实现函数
*author:
**********************************************************/

#include"fun.h"

/*list_init用于初始化链表*/
void list_init(List *L)
{
	*L = NULL;
}

/*Listempty判断链表是否为空*/
/*为空返回TRUE 否则返回FLASE*/
int list_empty(List L)
{
	if(L == NULL)
		return TRUE;
	else
		return FLASE;
}

/*list_full判断链表是否已满*/
/*即系统是否还能为链表分配存储空间*/
/*成功返回TRUE 失败返回FLASE*/
static int list_full()
{
	F_node *p,*q;
	p = (F_node *)malloc(sizeof(F_node));
	q=p;
	free(q);
	if(p == NULL)
		return FLASE;
	else 
		return TRUE;
}

/*list_add在链表末尾添加新的节点*/
/*添加成功返回TRUE 失败返回FLASE*/
int list_add(List *L,F_node node)
{
	List *p = L;
	F_node *q;
//	if(*p = NULL)
//	{
//		q = (F_node *)malloc(sizeof(F_node));
//		(*L)->next = q;
//	}
//	else
	while(*p != NULL)
	{
		*p = (*p)->next;
	}

	if(list_full())
	{
		q = (F_node *)malloc(sizeof(F_node));
		*p = q;
		(*p)->next = NULL;
		strcpy((*p)->name,node.name);
		(*p)->rate = node.rate;
		return TRUE;
	}
	else 
		return FLASE;
}

/*list_display显示链表内容*/
void list_display(const List L)
{
	int i=0;
	F_node *p = L;
	printf("电影信息:\n");
	printf("序号\t片名\t\t评价\n");
	while(p != NULL)
	{
		printf("%d\t%s\t\t%d\n",i++,p->name,p->rate);
		p = p->next;
	}
}

/*list_del删除链表末尾的节点*/
void list_del(List L)
{
	F_node *p = L,*q;
	while(p != NULL)
	{
		q = p;
		p = p->next;
	}
	free(q);
	q = NULL;
}













































































