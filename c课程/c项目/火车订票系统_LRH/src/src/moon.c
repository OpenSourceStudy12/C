/*
*版权归某某公司所有
*文件名：
*功能：
*作者：
*日期：
*修改记录：新建
       who  why  where     what time
*/


/***********************头文件包含******************************/

#include "menu.h"

/***********************头文件包含******************************/

/***********************结构体定义 宏定义************************/

#define MAIN_MENU 1
#define ADMIN_MAIN_MENU 11
#define ADMIN_LOOK_INFO 111
#define ADMIN_MODIFY_PASWORD 112
#define ADMIN_MANAMGE_STU 113
#define TEA_MAIN_MENU  12
#define STU_MAIN_MENU 13
#define EXIT_MENU 999
/***********************结构体定义 宏定义************************/

/***********************全局变量的定义**************************/

/***********************全局变量的定义**************************/


/***********************局部函数的申明**************************/
void print_head()
{
	printf("************************\n");
	printf("*  欢迎登录学生管理系统    *\n");
	printf("************************\n");
}
int  print_main_menu(int state)
{
	print_head();
	printf("1.admin load \n");
	printf("2.tea load \n");
	printf("3.stu load \n");
	printf("4.exit \n");
	printf("input your choice:\n");
	int choice;
	
	scanf("%d",&choice);
	if(choice>=1&&choice<=3)
		return state*10+choice;
	else if(choice == 4)
		return EXIT_MENU;
	else 
		return state;
}
int print_admin_menu(int state )
{
	print_head();
	printf("1.查看自己的信息\n");
	printf("2.修改密码\n");
	printf("3.管理学生\n");
	printf("4.返回生意层\n");
	printf("5.tuichu\n");

	printf("input your choice:\n");
	int choice;
	
	scanf("%d",&choice);
	if(choice>=1&&choice<=3)
		return state*10+choice;
	else if(choice==4)
		return state/10;
	else if(choice == 5)
		return EXIT_MENU;
	else 
		return state;



}
void print_menu()
{
	int menu_state = MAIN_MENU;
	int flag = 0;
	while(1)
	{
		system("clear");
		switch(menu_state)
		{
			//所有界面状态的罗列，有界面，先打印界面，获取用户选择，改变状态值，进入下一阶界面
			//没有界面，直接打印信息， 任意键继续，不改变状态值
			case MAIN_MENU:   
				menu_state = print_main_menu_a(menu_state);
				break;
			case ADMIN_MAIN_MENU:
				menu_state = print_admin_menu_a(menu_state);
				break;
			case ADMIN_LOOK_INFO:
				break;
			case ADMIN_MODIFY_PASWORD:
				break;
			case TEA_MAIN_MENU:
				
				break;
			case STU_MAIN_MENU:
				break;
			case EXIT_MENU:
				flag = 1;
				break;
		}
		if(flag)
			break;
	}
}

void print_main_menu()
{
	
	print_menu();
}

int main()
{
	print_main_menu();
}




