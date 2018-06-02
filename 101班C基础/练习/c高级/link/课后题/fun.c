/****************************************************************
*file name:
*function:创建一个学生信息链表，每个节点包含数据：学号,姓名，数学成绩．
*１用头插法创建一个该链表并打印链表的数据
*２通过学生姓名找到学生信息并打印．
*３将数学成绩处于７０－９０范围内的学生信息打印到屏幕上
*其他：使用尾插法创建链表
*author:
*****************************************************************/

#include<stdio.h>
#include"fun.h"

/*头插法创建链表*/
PStu Listcreat_from_end()
{
	PStu head = NULL,L;
	int num;
	printf("请输入学生学号:\n");
	scanf("%d",&num);
	while(num)
	{
		L = (PStu)malloc(sizeof(STU));
		L->next = head;
		head = L;
		L->num = num;
		printf("请输入姓名和数学成绩:\n");
		scanf("%s%f",L->name,&L->score);
		printf("请输入学生学号:\n");
		scanf("%d",&num);
	}
	return head;
}

/*尾插法创建链表*/
PStu Listcreat_from_head()
{
	PStu head = NULL,L,P;
	int num;
	printf("请输入学生学号:\n");
	scanf("%d",&num);
	while(num)
	{
		L = (PStu)malloc(sizeof(STU));
		if(head == NULL)
		{
			head = L; 
			P = head;
		}
		else
		{
			P->next = L;
			L->next = NULL;
			P = L;	
		}
//		L->next = head;
//		L->num = num;
		printf("请输入学生姓名和数学成绩:\n");
		scanf("%s%f",L->name,&L->score);
		printf("请输入学生学号:\n");
		scanf("%d",&num);
	}
	return head;
}


void Listprint(PStu head)
{
	PStu L = head;
	if(L == NULL)
		printf("The List is null\n");
	else
	{
		printf("学号\t姓名\t\t数学成绩:\n");
		while(L != NULL)
		{
			printf("%d\t%s\t\t%.2f\n",L->num,L->name,L->score);
			L = L->next;
		}
	}
}

void Listsh_name(PStu head,char *sh)
{
	PStu L = head;
	int flag = 1;
	while(L != NULL)
	{
		if(!strcmp(L->name,sh))
		{
			printf("%d\t%s\t%.2f\n",L->num,L->name,L->score);
		//	L = L->next;
			flag = 0;
		//	break;
		}
		L = L->next;
	}
	if(flag)
		printf("no that student\n");
}


void Listsh_rate(PStu head,float a,float b)
{
	PStu L = head;
	int cnt = 0;
	while(L != NULL)
	{
		if(L->score >= a && L->score <= b)
		{
			printf("%d\t%s\t%.2f\n",L->num,L->name,L->score);
			cnt++;
		}
		L = L->next;
	}
	printf("The students matching the condition is %d\n",cnt);
	if(!cnt)
		printf("no student match the condition\n");

}















