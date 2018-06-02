/********************************************************************
*file name:
*function:循环链表的操作(建立，显示)
*author:
*********************************************************************/
#include<stdio.h>
#include"fun1.h"

/*建立循环链表*/
PNODE linkcreat()
{
	PNODE L = NULL,p = NULL,temp = NULL;
	int num;
	printf("please input a num:\n");
	scanf("%d",&num);
	while(num)
	{
		if((L = (PNODE)malloc(sizeof(NODE))) != NULL)
			L->num = num;
		else 
			return NULL;

		if(temp == NULL)
			temp = L;
		else 
			p->next = L;
		p = L;
		printf("请输入姓名和成绩:\n");
		scanf("%s%f",L->name,&L->score);
		printf("请输入学号:\n");
		scanf("%d",&num);
	}
	L->next = temp;
	return L;
}

/*显示循环链表*/
void link_display(PNODE L)
{
	PNODE p = L;
	printf("学号\t姓名\t\t成绩\n");
//	printf("%d\t%s\t\t%.2f\n",L->num,L->name,L->score);
	do
	{
		printf("%d\t%s\t\t%.2f\n",L->num,L->name,L->score);
		L = L->next;
	}while(L != p);
}
