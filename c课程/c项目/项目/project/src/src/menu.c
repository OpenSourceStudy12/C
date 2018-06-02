/*
*版权  学生管理系统
*文件名：menu.c
*作者：wxh
*日期：2013/02/22
*修改：新建
**/

/**************头文件包含**************/

/**************头文件包含**************/
#include "menu.h"
#include "stu.h"
#include "tea.h"
/**************头文件包含**************/




/**************结构定义 宏定义*********/

/**************结构定义 宏定义*********/

/**************全局变量定义************/

/**************全局变量定义************/

/***************局部函数申明***********/

/***************局部函数申明***********/

/***************函数实现******************/

int print_main_menu()
{
	system("clear");
	printSysHead();
	printf("\t\t\t1.administator\n");	
	printf("\t\t\t2.stu \n");
	printf("\t\t\t3.teacher \n");
	printf("\t\t\t4.exit\n");
}
int print_admin_main_menu()
{
	system("clear");
	printSysHead();
	printf("\t\t\t1.查看个人信息");
	printf("\t\t\t2.修改密码\n");
	printf("\t\t\t3.管理老师\n");
	printf("\t\t\t4.管理学生\n");
	printf("\t\t\t5.返回上一层\n");
}
void mangae_stu_menu()
{
	system("clear");
	printSysHead();
	printf("\t\t\t1.添加学生\n");
	printf("\t\t\t2.修改学生\n");
	printf("\t\t\t3.查找学生\n");
	printf("\t\t\t4.删除学生\n");
	printf("\t\t\t5.打印学生信息\n");
	printf("\t\t\t6.·返回上一层\n");
}
int check_admin_log()
{
	char name[32]={0};
	char passwd[32]={0};
	printf("input the username:\n");
	scanf("%s",name);
	printf("input the password:\n");
	scanf("%s",passwd);
	if((strcmp(name,"admin")==0)&&(strcmp(passwd,"123456")==0))
		return 0;
	else 
		return -1;	
}
int main_menu_op(int state,stu_list *pstu,tea_list *ptea)
{
	char ch;
	print_main_menu();
	
	while((ch=getchar())=='\n');
	getchar();
	switch(ch)
	{
		case '1':
		{
			int login =check_admin_log();
			if(login == 0)
			{
				state = ADMIN_MAIN_MENU;
				//
				read_stu(pstu);
				read_tea(ptea);
			}
			else
			{
				 printf("error try again ......\n");
				getchar();
			}
		break;
		}
		case '2':
				
		break;
		case '3':
			
		break;
		case '4':
			state = EXIT_MENU;
		break;
		default:
		break;
	}
	
	return state;
}
int sysMenu()
{
	int menu_state= MAIN_MENU;
	int exit_flag = 0;
	stu_list  stu_head= NULL;
	tea_list  tea_head = NULL;
	while(1)
	{
		switch(menu_state)
		{
			case MAIN_MENU:
				menu_state = main_menu_op(menu_state,&stu_head,&tea_head);
			break;
			case ADMIN_MAIN_MENU:
				menu_state=admin_op(menu_state);
			
			break;
			case ADMIN_INFO_MENU:
				menu_state=printAdminInfo();
			break;
			case STU_MANAGER_MENU:
				menu_state=stu_op(menu_state);
			break;
			case ADD_STU:
				menu_state=addStuInfo(menu_state,&stu_head);
			break;	
			case EXIT_MENU://退出菜单
				exit_flag = 1;
			break;
			default:
				printf("error,please try again!\n");
		}
	
		if(exit_flag == 1)
		{
			//保存学生信息
			save_stu(stu_head);
			//保存教师信息
			save_tea(tea_head);
			//释放内存
			destoryStuLink(stu_head);
			destoryTeaLink(tea_head);
			break;
		}
	}
	return 0;
}







