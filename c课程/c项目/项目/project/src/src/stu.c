/*
*版权  学生管理系统
*文件名：main.c
*作者：wxh
*日期：2013/02/22
*修改：新建
**/

/**************头文件包含**************/
#include "stu.h"
#include <stdio.h>
/**************头文件包含**************/


/**************结构定义 宏定义*********/

/**************结构定义 宏定义*********/

/**************全局变量定义************/

/**************全局变量定义************/

/***************局部函数申明***********/

/***************局部函数申明***********/

/***************函数实现******************/
int getchoice()
{
	int num;
	scanf("%d",&num);
	return num;
}
int checkChoice(int num,int xian)
{
	if(num>0&&num<=xian)
		return 0;
	else
		return -1;
}

int stu_op(int state)
{
	int choice;
	int flag;
	mangae_stu_menu();
	choice=getchoice();
	flag=checkChoice(choice,6);
	if(flag != 0)
	{
		printErr();
		return state/10;
	}
	state =state*10+ choice;
	return state;
}

int addStuInfo(int state ,stu_list *head)
{
	//添加成功 打印添加成功 任意键继续
	//添加成功 打印添加失败 任意键继续
	printf("添加成功\n");
	return state/10;
}

void destoryStuLink(stu_list head)
{
}






