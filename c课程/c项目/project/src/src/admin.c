/*
*版权  学生管理系统
*文件名：admin.c
*作者：wxh
*日期：2013/02/22
*修改：新建
**/

/**************头文件包含**************/
#include "stu.h"
#include "tea.h"
#include "menu.h"
/**************头文件包含**************/


/**************结构定义 宏定义*********/

/**************结构定义 宏定义*********/

/**************全局变量定义************/

/**************全局变量定义************/

/***************局部函数申明***********/

/***************局部函数申明***********/

/***************函数实现******************/


int admin_op(int state)
{
	int num;
	print_admin_main_menu();
	scanf("%d",&num);
	if(num>0&&num<5)
		return state=state*10+num;
	else if(num == 5)
		return state;
	else
	{
		printf("error , 任意键继续.....\n ");
		getchar();
		return state;
	}
	
}
/*读管理员信息并打印*/
int printAdminInfo()
{
	//读取成功，打印，任意键继续
	//读取失败，提示失败，任意键继续
	return ADMIN_MAIN_MENU;
}






