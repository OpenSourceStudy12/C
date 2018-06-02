/*文件名：menu
*功能：管理员管理
*作者：
*日期：
*修改记录：新建
*/


/***********************头文件包含******************************/

#include "menu.h"
#include "admin.h"
#include "train.h"

/***********************头文件包含******************************/

/***********************结构体定义 宏定义************************/
#define MAIN_MENU 1
#define ADMIN_MENU 11
#define MODIFY_TRAIN_MENU 111
#define ADMIN_TRAIN_SEARCH_MENU 1111
#define TRAIN_SEARCH_BYTRAIN 11111
#define TRAIN_SEARCH_BYDES 11112
#define ADMIN_PRINT_ALL 1112
#define TRAIN_INSERT 1113
#define TRAIN_DEL 1114
#define TRAIN_MODIFY 1115
#define MODIFY_USER_MENUE 112
#define USER_SEARCH 1121
#define USER_PRINT_ALL 1122
#define USER_INSERT 1123
#define USER_DEL 1124
#define USER_MODIFY 1125
#define USER_MENU 12
#define USER_TRAIN_SEARCH_MENU 121
#define USER_TRAIN_SEARCH_BYTRAIN 1211
#define USER_TRAIN_SEARCH_BYDES 1212
#define TRAIN_ORDER 122
#define TRAIN_UNDO 123
#define USER_PSWD_MODIFY 124
#define REGISTER_MENU 13
#define USERINFO_PRINT 125
#define EXIT 14
#define ADMIN -1
#define USER -2


/***********************结构体定义 宏定义************************/

/***********************全局变量的申明**************************/


	PUser Uhead;
	int login=0;
	PAdmin superadmin;
	char name[20]={};
	Admin admin={"admin","12345678"};
	PTr head;
/***********************全局变量的申明**************************/

/***********************局部函数的申明**************************/
int print_main_menu(int state)
{
	int temp;
	static int  n=3;	
	if(login==ADMIN)
	{
		return state*10+1;
	}
	if(login==USER)
	{
		return state*10+2;
	}
	printf("          >1.管理员登录.\n");
	printf("          >2.普通用户登录.\n");
	printf("          >3.新用户注册.\n");
	printf("          >4.退出系统.\n");
	while(!scanf("%d",&temp)||temp<1||temp>4)
	{
		while(getchar()!='\n');
		printf("        请输入1-4之间的整数.\n");
	}	
	while(getchar()!='\n');
	if(temp==1&&n>0)
	{
		char a[20],b[20];
		do
		{
			printf("请输入管理员用户名\n");
			scanf("%s",a);
			while(getchar()!='\n');
			printf("请输入管理员密码.\n");
			scanf("%s",b);
			while(getchar()!='\n');
			if(n<=0&&admin_match(admin,a,b)<0)
			{
				printf("你已累计输错三次,请退出系统后再重试\n系统自动退出\n");
				printf("输入回车退出.");
				while(getchar()!='\n');
				return EXIT;
			}
			if(n>0&&admin_match(admin,a,b)<0)
			{
				n--;
				printf("用户名或密码错误,请重新输入.\n");
			}
			else 
			{
				login=ADMIN;
				return state*10+temp;
			}
		}while(1);
	}
	else if(temp==2&&n>0)
	{
		char a[20],b[20];
		do
		{
			printf("请输入用户名\n");
			scanf("%s",a);
			strcpy(name,a);
			while(getchar()!='\n');
			printf("请输入密码.\n");
			scanf("%s",b);
			while(getchar()!='\n');
			if(n<=0&&user_match(Uhead,a,b)<0)
			{
				printf("你的次数已用尽,请退出系统后再重试\n系统自动退出\n");
				printf("输入回车退出.");
				while(getchar()!='\n');
				return EXIT;
			}
			if(n>0&&user_match(Uhead,a,b)<0)
			{
				n--;
				printf("用户名或密码错误,请重新输入.\n");
			}
			else 
			{
				login=USER;
				n=3;
				return state*10+temp;
			}
		}while(1);

	}
		else if(temp>2)
			return state*10+temp;
}

int print_admin_menu(int state)
{
	int temp;
	printf("          >1.车次管理.\n");
	printf("          >2.用户管理.\n");
	printf("          >3.注销登录.\n");
	printf("          >4.退出.\n");
	while(!scanf("%d",&temp)||temp<1||temp>4)
	{
		while(getchar()!='\n');
		printf("        请输入1-4之间的整数.\n");
	}
	while(getchar()!='\n');
	if(temp>=1&&temp<=2)
		return state*10+temp;
	else if(temp==3)
	{
		login=0;
		return state/10;
	}
	else if(temp==4)return EXIT;
	else return state;
}

int print_modify_train_menu(int state)
{
	int temp;
	printf("          >1.查询车次.\n");
	printf("          >2.车次列表信息显示.\n");
	printf("          >3.车次增加.\n");
	printf("          >4.车次删除.\n");
	printf("          >5.车次修改.\n");
	printf("          >6.返回上一级.\n");
	printf("          >7.退出.\n");
	while(!scanf("%d",&temp)||temp<1||temp>7)
	{
		while(getchar()!='\n');
		printf("        请输入1-7之间的整数.\n");
	}
	while(getchar()!='\n');
	if(temp>=1&&temp<=5)
		return state*10+temp;
	else if(temp==6)
		return state/10;
	else if(temp==7)return EXIT;
	else return state;
}

int print_modify_user_menu(int state)
{
	int temp;
	printf("          >1.旅客用户查询.\n");
	printf("          >2.旅客列表信息显示.\n");
	printf("          >3.旅客用户增加.\n");
	printf("          >4.旅客用户删除.\n");
	printf("          >5.旅客用户修改.\n");
	printf("          >6.返回上一级.\n");
	printf("          >7.退出.\n");
	while(!scanf("%d",&temp)||temp<1||temp>7)
	{
		while(getchar()!='\n');
		printf("         请输入1-7之间的整数.\n");
	}
	while(getchar()!='\n');
	if(temp>=1&&temp<=5)
		return state*10+temp;
	else if(temp==6)
		return state/10;
	else if(temp==7)return EXIT;
	else return state;
}

int print_user_menu(int state)
{
	int temp,m;
	static int flag=0;
	printf("          >1.查询车票.\n");
	printf("          >2.订购车票.\n");
	printf("          >3.退订车票.\n");
	printf("          >4.用户密码修改.\n");
	printf("          >5.个人信息查看.\n");
	printf("          >6.注销登录.\n");
	printf("          >7.退出.\n");
	if(flag==0)
	{
		m=user_waittrain_check(head,Uhead,name);
		if(m!=0)
		{
			User_data_write(Uhead);
			Train_Link_Write(head);
			flag=~flag;
			printf("输入回车继续.\n");
			while(getchar()!='\n');
			return state;
		}
	}
	while(!scanf("%d",&temp)||temp<1||temp>7)
	{
		while(getchar()!='\n');
		printf("        请输入1-7之间的整数.\n");
	}
	while(getchar()!='\n');
	if(temp>=1&&temp<=5)
		return state*10+temp;
	else if(temp==6)
	{
		login=0;
		flag=0;
		return state/10;
	}
	else if(temp==7)return EXIT;
	else return state;
}

int train_search(int state)
{
	int temp;
	printf("          >1.通过车次查询.\n");
	printf("          >2.通过区间查询.\n");
	printf("          >3.返回上一级.\n");
	printf("          >4.退出.\n");
	while(!scanf("%d",&temp)||temp<1||temp>4)
	{
		while(getchar()!='\n');
		printf("        请输入1-4之间的整数.\n");
	}
	while(getchar()!='\n');
	if(temp>=1&&temp<=2)
		return state*10+temp;
	else if(temp==3)
		return state/10;
	else if(temp==4)return EXIT;
	else return state;
}


/***********************局部函数的申明**************************/




int main()
{
	int state=MAIN_MENU;
	int flag=0,i,num,reflag=0;
	char tra[7],train[20];
	Uhead=User_data_read();;
	PTr Sta=NULL;
	PTr Des_sta[20];
	head=Train_Link_Read();
	PUser undo=NULL;
	//superadmin=&admin;
	//admin_data_write(&admin);
	//superadmin=admin_data_read();
	do
	{
		system("clear");
		if(state!=EXIT)
		{
			printf("*************************************\n");
			printf("*******火车票订票系统欢迎您**********\n");
			printf("*************************************\n");
		}
		switch(state)
		{
			case MAIN_MENU:
				state=print_main_menu(state);
			       break;	
			case ADMIN_MENU:
				state=print_admin_menu(state);
			/*	if(state==113)
				{
					superadmin=admin_pswd_modify(superadmin);
					if(superadmin!=NULL)
					admin_data_write(superadmin);
					printf("输入回车返回.\n");
					while(getchar()!='\n');
					state/=10;
				}*/
			       break;
			case MODIFY_TRAIN_MENU:
			       state=print_modify_train_menu(state);
			       if(state==TRAIN_INSERT)
			       {
				       head=TrainLinkInsert(head);
				       Train_Link_Write(head);
			   		state/=10;    
			       }
			       else if(state==ADMIN_PRINT_ALL)
			       {
				       Train_print(head);
				       printf("\n输入回车结束显示.\n");
				       while(getchar()!='\n');
				       state/=10;
			       }
			       else if(state==TRAIN_DEL)
			       {
				       printf("请输入要删除的车次.\n");
				       scanf("%s",tra);
				       while(getchar()!='\n');
				       head=Train_del(head,tra);
				       Train_Link_Write(head);
				       printf("\n输入回车结束显示.\n");
				       while(getchar()!='\n');
				       state/=10;
			       }
			       else if(state==TRAIN_MODIFY)
			       {
				       Train_modify(head);
				       Train_Link_Write(head);
				       printf("\n输入回车结束显示.\n");
				       while(getchar()!='\n');
				       state/=10;
			       }
			       break;
			case ADMIN_TRAIN_SEARCH_MENU:
				state=train_search(state);
				if(state==TRAIN_SEARCH_BYTRAIN)
				{
					printf("请输入车次\n");
					scanf("%s",tra);
				       	while(getchar()!='\n');
					Sta=Train_searchBytrain(head,tra);
					if(Sta==NULL)
					{
						printf("未找到车次为%s的列车\n\n输入回车返回.\n",tra);
				       		while(getchar()!='\n');
						state/=10;
						break;
					}
					else
					{
						station_print(Sta);
						printf("\n输入回车结束显示.\n");
				       		while(getchar()!='\n');
				       		state/=10;
						Sta=NULL;
					}
				}
				else if(state==TRAIN_SEARCH_BYDES)
				{
					char a[20],b[20];
					printf("请输入出发站点.\n");
					scanf("%s",a);
					while(getchar()!='\n');
					printf("请输入目的地.\n");
					scanf("%s",b);
					while(getchar()!='\n');
					i=0;
					Sta=head;
					while(1)
					{
						Sta=Train_searchByDes(Sta,a,b);
						if(Sta==NULL)break;
						Des_sta[i]=Sta;
						Sta=Sta->next;
						i++;
					}
					if(i==0)
					{
						printf("未找到包含该区间的列车\n\n输入回车返回.\n");
				       		while(getchar()!='\n');
						state/=10;
						break;
					}
					else
					{
						printf("共找到%d趟列车包含该区域.\n",i);
						while(i--)
						{
							station_print(Des_sta[i]);
						}
						printf("\n输入回车结束显示.\n");
				       		while(getchar()!='\n');
				       		state/=10;
						Sta=NULL;
					}

				}
			       break;
			case MODIFY_USER_MENUE:
			       state=print_modify_user_menu(state);
			       if(state==USER_INSERT)
			       {
				       Uhead=User_Add(Uhead);
				       printf("\n添加完成,输入回车返回.\n");
				       User_data_write(Uhead);
				       while(getchar()!='\n');
				       state/=10;
			       }
			       else if(state==USER_PRINT_ALL)
			       {
				       User_print(Uhead);
				       printf("\n输入回车结束显示\n");
				       while(getchar()!='\n');
				       state/=10;
			       }
			       else if(state==USER_SEARCH)
			       {
				       char a[20];
				       printf("请输入需要查找的用户名\n");
				       scanf("%s",a);
				       while(getchar()!='\n');
				       PUser s=user_search(Uhead,a);
				       if(s!=NULL)
				       {       
				       		printf("已找到该用户.\n用户名\t身份证号码\t密码\n");
						printf("%s\t%s\t%s\n",s->name,s->ID,s->pswd);
				       }
				       else
					       printf("未找到用户名为%s的用户\n",a);
				       printf("\n输入回车返回.\n");
				       while(getchar()!='\n');
				       state/=10;
			       }
			       else if(state==USER_DEL)
			       {
				       char a[20];
				       printf("请输入需要删除用户的用户名.\n");
				       scanf("%s",a);
				       while(getchar()!='\n');
				       Uhead=user_del(Uhead,a);
				       User_data_write(Uhead);
				       printf("\n输入回车返回.\n");
				       while(getchar()!='\n');
				       state/=10;
			       }
			       else if(state==USER_MODIFY)
			       {
				       char a[20];
				       printf("请输入需要修改用户的用户名.\n");
				       scanf("%s",a);
				       while(getchar()!='\n');
				       user_modify(Uhead,a);
				       User_data_write(Uhead);
				       printf("\n输入回车返回.\n");
				       while(getchar()!='\n');
				       state/=10;
			       }
			       break;
			case USER_MENU:			       
				state=print_user_menu(state);
			       break;
			case USER_TRAIN_SEARCH_MENU:
			       state=train_search(state);
				if(state==USER_TRAIN_SEARCH_BYTRAIN)
				{
					printf("请输入车次\n");
					scanf("%s",tra);
				       	while(getchar()!='\n');
					Sta=Train_searchBytrain(head,tra);
					if(Sta==NULL)
					{
						printf("未找到车次为%s的列车\n\n输入回车返回.\n",tra);
				       		while(getchar()!='\n');
						state/=10;
						break;
					}
					else
					{
						train_order(head,Uhead,Sta->ticket,name);
						User_data_write(Uhead);
						Train_Link_Write(head);
						printf("\n输入回车结束显示.\n");
				       		while(getchar()!='\n');
				       		state/=10;
						Sta=NULL;
					}
				}
				else if(state==USER_TRAIN_SEARCH_BYDES)
				{
					char a[20],b[20];
					printf("请输入出发站点.\n");
					scanf("%s",a);
					while(getchar()!='\n');
					printf("请输入目的地.\n");
					scanf("%s",b);
					while(getchar()!='\n');
					i=0;
					Sta=head;
					while(1)
					{
						Sta=Train_searchByDes(Sta,a,b);
						if(Sta==NULL)break;
						Des_sta[i]=Sta;
						Sta=Sta->next;
						i++;
					}
					if(i==0)
					{
						printf("未找到包含该区间的列车\n\n输入回车返回.\n");
				       		while(getchar()!='\n');
						state/=10;
						break;
					}
					else
					{
						printf("共找到%d趟列车包含该区域.\n",i);
						int n=i;
						while(i--)
						{
							station_print(Des_sta[i]);
						}
						char ans;
						printf("是否购买?Y/N\n");
						ans=getchar();
						while(getchar()!='\n');
						if(ans=='y'||ans=='Y')
						{
							char t[20];
							int m=n;
							do
							{
								m=n;
								printf("请输入车次.\n");
								scanf("%s",t);
								while(getchar()!='\n');
								while(m--)
								{
									if(strcmp(Des_sta[m]->ticket,t)==0)
									{
										m=-3;
										break;
									}
								}
								if(m==-3)
								{
									train_order(head,Uhead,t,name);
									User_data_write(Uhead);
									Train_Link_Write(head);
									break;
								}
								else
								{
									printf("您输入的车次不在本次搜寻的结果当中.\n\n请重新输入\n");
									
								}
							}while(1);
						}
						else 
						{
							printf("取消购买.\n");
						}
						printf("\n输入回车结束显示.\n");
				       		while(getchar()!='\n');
				       		state/=10;
						Sta=NULL;
					}

				}
			       break;
			case USER_PSWD_MODIFY:
			      Uhead=user_pswd_modify(Uhead,name); 
			      User_data_write(Uhead);
			       printf("\n密码修改成功.输入回车返回\n");
			       while(getchar()!='\n');
				state/=10;
			       break;
			case TRAIN_ORDER:
			      printf("请输入需要购买的车次.\n"); 
			      scanf("%s",train);
			      while(getchar()!='\n');
				head=train_order(head,Uhead,train,name);
			      User_data_write(Uhead);
				Train_Link_Write(head);
				printf("\n输入回车返回.\n");
			      while(getchar()!='\n');
				state/=10;
			       break;
			case REGISTER_MENU:
			       Uhead=User_Add(Uhead);
			       User_data_write(Uhead);
			       printf("\n注册成功.输入回车返回\n");
			       while(getchar()!='\n');
				state/=10;
			       break;
			case USERINFO_PRINT:
			       userinfo_print(Uhead,name);
				printf("\n输入回车返回.\n");
			      while(getchar()!='\n');
				state/=10;
			       break;
			case TRAIN_UNDO:
			        undo=user_search(Uhead,name);
			       if(undo!=NULL&&undo->buytrain_head!=NULL)
			       {
				       PWtrain s=undo->buytrain_head;
				       PWtrain train[20];
				       int i=0;
			       		printf("您已购车票有:\n");
					while(s!=0)
					{
						printf("%s\t",s->train);
						train[i]=s;
						s=s->next;
						i++;
					}
					printf("\n");
					char a[20];
					printf("请输入您需要退订的车次.\n");
					scanf("%s",a);
					while(getchar()!='\n');
					while(i--)
					{
						if(strcmp(train[i]->train,a)==0)
						{
							i=-3;
							break;
						}
					}
					if(i==-3)
					{
						head=train_unorder(head,Uhead,a,name);
			     			User_data_write(Uhead);
						Train_Link_Write(head);
					}
					else
					{
						printf("您输入的车次您并没有购买,无法退票.\n");
					}
			       }
			       else
			       {
				       printf("\n您未购买过车票,无法退订.\n");
			       }
			       printf("\n输入回车返回.\n");
			       while(getchar()!='\n');
			       state/=10;
			       break;
			case EXIT:
			       flag=1;
			       break;

		}
		if(flag==1)break;
	}while(1);
	


	return 0;

}
