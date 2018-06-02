/*********************************************************************************************
file Name: a system of booking tickets
describtion:
author:L-R-H
date:2017-4-23
**********************************************************************************************/

#include"include.h"
#include"data_deal.h"
#include"train.h"
#include"user.h"
#include"menu.h"
#include"admin.h"

int main()
{
	/*变量初始化*/
	Info info = {NULL,NULL,NULL};
	//info.Head_user = NULL;
	//info.Head_train = NULL;
	//info.Head_admin = NULL;

	/*变量定义*/
	int a,exit_flag = 0;
	char ch;//作为选项选择对应的操作
	//PUser puser = NULL;//当前用户信息结构体地址

	//函数初始化
	admin_init(&info.Head_admin);
	info.Head_user = user_data_read();
	info.Head_train = train_data_read();
	/*************************/
	main_menu_print();
	ch = getchar();
	while(getchar() != '\n');
	while(1)
	{
		switch(ch)//主菜单
		{
			case '1'://新用户处理
				info.Head_user = new_user_deal(info.Head_user);
				break;
			case '2'://用户登录处理
				exit_flag = user_login_deal(&info);
				break;
			case '3'://管理员登录处理
				exit_flag = admin_login_deal(&info);
				break;
			case '0':
				exit_flag = 1;
				break;
			default :
				printf("\n无效的输入，请重新输入\n");
				sleep(1);
				break;
		}
		if(exit_flag)
		{
			//flag = 0;
			break;
		}
		
		main_menu_print();
		ch = getchar();
		while(getchar() != '\n');
	}
	user_data_save(info.Head_user);
	train_data_save(info.Head_train);
	return 0;
}

