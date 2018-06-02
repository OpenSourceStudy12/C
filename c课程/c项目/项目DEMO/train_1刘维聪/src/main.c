/*火车票订票系统 0.9版
*作者：刘维聪
*最后修改日期：2013年02月26日
*初始管理员和密码为admin
*/
#include "main.h"
#include "admin.h"
#include "user.h"
int main()
{
	int flag = login();
	while(1)
	{
		switch(flag)
		{
			//0表示子菜单的程序全部正常退出，保存之前修改的信息，再重新登陆。
			case 0:flag = login();break;
			case 1:flag = user();break;//进入用户登陆界面
			case 2:flag = add_user();break;//进入新用户注册界面
			case 3:flag = admin();break;//管理员登陆界面
			case 4:return 0;
			case -2:return 0;//子菜单直接退出程序
			case -1:flag = 0;break;
			default:printf("error menu return message\n");return 0;
		}
	}
	return 0;
}
int login()
{
	int log_flag = 0;
	system("clear");
	printf("-------------------------------------------\n");
	printf("\n");
	printf("*******欢迎使用火车票订票系统 0.9版********\n");
	printf("\n");
	printf("\t请选择\n");
	printf("\t\t1  用户登录\n");
	printf("\t\t2  新用户注册\n");
	printf("\t\t3  管理员登录\n");
	printf("\t\t4  退出\n");
	printf("\n");
	printf("----------------中国铁道部-----------------\n");
	printf("---------如有任何疑问请拨12306垂询---------\n");
	printf("\n");
	scanf("%d",&log_flag);
	my_getchar();
	while(log_flag>4||log_flag<1)
	{
		printf("输入错误，请重试。\n");
		scanf("%d",&log_flag);	
		my_getchar();
	}
	return log_flag;
}

int hide_password(char passwd[])//输入密码，并不回显
{
	printf("\t请输入密码\n");
	char ch;
	int i = 0;
	setbuf(stdin,NULL);
	system("stty -echo raw");
	while(1)//输入密码
	{
		
		ch=getchar();
		putchar('*');
		passwd[i] = ch;
		if('\r'==ch)
		{
			break;
		}
		i++;
	}
	system("stty echo -raw");
	passwd[i] = '\0';
	return 0;
}

/*int hide_password(char secret[])//输入密码，并不回显
{
	printf("\t请输入密码\n");
	char ch;
	int i=0;
	setbuf(stdin,NULL);
	while(1)//输入密码
	{
		system("stty -echo");
		ch=getchar();
		system("stty echo");
		secret[i]=ch;
		if('\n'==ch)
		{
			break;
		}
		i++;
	}
	secret[i]='\0';
	return 0;
}
*/