/*文件名：admin.c
*功能：管理员管理
*作者：
*日期：
*修改记录：新建
*/

/***********************头文件包含******************************/

#include "user.h"
#include "admin.h"
#include "common.h"

/***********************头文件包含******************************/

/***********************结构体定义 宏定义************************/



/***********************结构体定义 宏定义************************/

/***********************变量的申明**************************/



/***********************变量的申明**************************/

/***********************函数的申明**************************/

PUser User_Add(PUser head)//用户添加
{
	char a[20],b[20];
	PUser s=NULL;
	int flag=0;
	s=(PUser)malloc(sizeof(User));
	if(s==NULL)
	{
		printf("malloc error\n");
		return NULL;
	}
	do
	{
		flag=0;
		s->train_head=NULL;//用户所等待列车链表头置为空
		s->buytrain_head=NULL;//用户已购车票链表头置为空
		printf("请输入用户名\n");
		scanf("%s",s->name);
		while(getchar()!='\n');
		PUser p=head;
		while(p!=NULL)
		{
			if(strcmp(p->name,s->name)==0)
			{
				printf("已经有该用户名,请重新输入其他用户名.\n");
				flag=~flag;
				break;
			}
			p=p->next;
		}
	}while(flag);
	do
	{
		flag=0;
		printf("请输入用户的身份证号码.\n");
		scanf("%s",s->ID);
		while(getchar()!='\n');
		PUser L=head;
		while(L!=NULL)
		{
			if(strcmp(L->ID,s->ID)==0)
			{
				printf("已有该用户,请输入其他身份证号码.\n");
				flag=1;
				break;
			}
			L=L->next;
		}
	}while(flag);
	do
	{
		printf("请输入密码\n");
		scanf("%s",a);
		while(getchar()!='\n');
		printf("请再输入一次\n");
		scanf("%s",b);
		while(getchar()!='\n');
		if(strcmp(a,b)==0)
		{
			strcpy(s->pswd,a);
		}
		else
		{
			printf("两次密码输入不一致,请重新输入.\n");
		}
	}while(strcmp(a,b));
	if(head==NULL)
	{
		s->next=NULL;
		head=s;
	}
	else
	{
		s->next=head;
		head=s;
	}
	return head;
}

void User_print(PUser head)//所有用户信息显示
{
	PUser L=head;
	if(head==NULL)
	{
		printf("没有用户数据可以显示.\n");
		return;
	}
	else
	{
		printf("用户名\t    身份证号码\t\t密码\n");
		while(L!=NULL)
		{
			printf(" %s\t%s\t%s\n",L->name,L->ID,L->pswd);
			L=L->next;
		}
		return ;
	}
}


PAdmin admin_pswd_modify(PAdmin superadmin)//管理员密码修改
{
	static int i=0;
	char choice;
	char a[20]={},b[20]={};
	while(1)	
	{
		printf("请输入旧管理员密码.\n");
		scanf("%s",a);
	//	printf("a=%s\n",a);
	//	printf("superadmin->pswd=%s\n",superadmin->pswd);
		if(strcmp(a,superadmin->pswd)==0)
		{	
			while(getchar()!='\n');
			int flag=0;
			do
			{
				printf("请输入新的密码.\n");
				scanf("%s",a);
				while(getchar()!='\n');
				printf("请再输入一次.\n");
				scanf("%s",b);
				while(getchar()!='\n');
				if(strcmp(a,b)==0)
				{
					strcpy(superadmin->pswd,a);
					printf("密码更改成功.\n");
					break;
				}
				else 
				{
					flag=~flag;
					printf("两次密码输入不一致,请重新输入.\n\n");
	
				}
			}while(flag);
			break;
		}
		else
			printf("密码错误,请重新输入.\n\n");
			i++;
			if(i<3)
			{
				printf("输入Q/q结束输入,其他任意字符继续尝试.\n");
				while(getchar()!='\n');
				scanf("%c",&choice);
				while(getchar()!='\n');
				if(choice=='Q'||choice=='q')break;
			}
			else
			{
				printf("错误的次数太多,请退出后重新尝试.\n");
				break;
			}
	}
	return superadmin;

}


int admin_match(Admin head,char *name,char *pswd)//管理员身份匹配返回0成功,返回-1失败
{
	Admin L=head;
/*	if(head==NULL)
	{
		return -1;
	}
	else
	{*/
			if(strcmp(head.name,name)==0&&strcmp(head.pswd,pswd)==0)
			{
				return 0;
			}
			else
				return -1;
//	}
}



