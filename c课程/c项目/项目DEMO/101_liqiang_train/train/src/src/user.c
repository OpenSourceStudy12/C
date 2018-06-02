/*文件名：user.c
*功能：管理员管理
*作者：
*日期：
*修改记录：新建
*/


/***********************头文件包含******************************/

#include "user.h"
#include "train.h"
#include "admin.h"

/***********************头文件包含******************************/

/***********************结构体定义 宏定义************************/



/***********************结构体定义 宏定义************************/

/***********************全局变量的申明**************************/



/***********************全局变量的申明**************************/

/***********************全局函数的申明**************************/
PUser user_search(PUser head,char *name)//按用户名查找用户
{
	PUser L=head;
	if(head==NULL)
	{
		printf("数据库中没有用户信息\n");
		return NULL;
	}
	else
	{
		while(L!=NULL)
		{
			if(strcmp(L->name,name)==0)
			{
				return L;
			}
			L=L->next;
		}
		printf("未找到用户名为%s的用户.\n",name);
		return NULL;
	}
}

PUser user_del(PUser head,char *name)//用户删除
{
	PUser L=head;
	int i=0;
	if(head==NULL)
	{
		printf("数据库为空.\n");
	}
	else
	{
		if(strcmp(head->name,name)==0)
		{
			i++;
			free(L);
			head=head->next;
			printf("删除成功.\n");
		}
		else
		{
			PUser p=L;
			while(L!=NULL)
			{
				if(strcmp(L->name,name)==0)
				{
					i++;
					p->next=L->next;
					free(L);
					printf("删除成功.\n");
				}
				p=L;
				L=L->next;
			}
			
		}
	}
	if(i==0)printf("未找到用户名为%s的用户.\n",name);
	return head;
}


void user_modify(PUser head,char *name)//用户信息修改
{
	if(head==NULL)	
	{
		printf("数据库为空,无法更改.");
		return ;
	}
	else
	{
		PUser L=user_search(head,name);
		if(L==NULL)
			printf("没有%s的用户信息\n",name);
		else
		{
			printf("请输入新的用户名.\n");
			scanf("%s",L->name);
			while(getchar()!='\n');
			printf("请输入新的身份证号码.\n");
			scanf("%s",L->ID);
			while(getchar()!='\n');
			int flag=0;
			char a[8],b[8];
			do
			{
				flag=0;
				printf("请输入用户密码.\n");
				scanf("%s",a);
				while(getchar()!='\n');
				printf("请再输入一次.\n");
				scanf("%s",b);
				while(getchar()!='\n');
				if(strcmp(a,b)!=0)
				{
					flag=~flag;
					printf("两次密码输入不一致,请重新输入.\n");
				}

			}while(flag);
			strcpy(L->pswd,a);
			printf("修改成功.\n");
		}
		return ;
	}

}



PTr train_order(PTr head,PUser Uhead,char *train,char *name)//订票
{
	PTr L=head;
	char ans;
	if(head==NULL)
	{
		printf("没有列车可以预定\n");
		return head;
	}
	PUser t=user_search(Uhead,name);
	int flag=0;
	PWtrain s=t->buytrain_head,u=t->train_head;
	while(s!=NULL)
	{
		if(strcmp(s->train,train)==0)
		{
			printf("您已购买该车票,请不要重复购买.\n");
			return head;
		}
		s=s->next;
	}
	while(u!=NULL)
	{
		if(strcmp(u->train,train)==0)
		{
			printf("您已排队该车次,请不要重复购买同一个车次.\n");
			return head;
		}
	}
	while(L!=NULL)
	{
		if(strcmp(L->ticket,train)==0)
		{
			if(L->remain >=1)
			{
				char choice;
				station_print(L);
				printf("是否购买?Y/N\n");
				choice=getchar();
				while(getchar()!='\n');
				if(choice=='N'||choice=='n')
				{
					printf("取消购买.\n");
					return head;
				}
				L->remain=L->remain-1;
				user_buytrain_add(Uhead,name,train,L->start,L->des);
				printf("出票成功\n");
				return head;
			}
			else
			{
				station_print(L);
				printf("票数不够,是否排队购买?Y/N\n");//票数不足排队等候
				ans=getchar();
				while(getchar()!='\n');
				if(ans=='y'||ans=='Y')
				{
					PWait s=malloc(sizeof(Wait));
					strcpy(s->train,train);
					strcpy(s->start,L->start);
					strcpy(s->des,L->des);
					strcpy(s->name,name);
					strcpy(s->time,L->des_time);
					user_wait_train_add(Uhead,name,train,L->start,L->des);
					if(L->wait_head==NULL)
					{
						s->next=NULL;
						L->wait_head=s;
					}
					else
					{
						PWait p=L->wait_head,q=NULL;
						while(p!=NULL)
						{
							q=p;
							p=p->next;
						}
						s->next=NULL;
						q->next=s;
					}
					printf("正在排队等候.\n");
				}
				else 
				{
					printf("取消排队\n");
					return head;
				}
			}
			return head;
		}
		L=L->next;
	}
	printf("未找到%s的车次\n",train);
	return head;
	
}


PTr train_unorder(PTr head,PUser Uhead,char *train,char *name)//退票
{
	PTr L=Train_searchBytrain(head,train);
	if(L!=NULL)
	{
			L->remain=L->remain+1;
			user_buytrain_del(Uhead,name,train);
		//	user_waittrain_del(Uhead,name,train);
		//	train_wait_del(head,name,train);
			printf("退票成功.\n");
			return head;
	}
	printf("未找到该车次.\n");
}


int user_match(PUser head,char *name,char *pswd)//用户身份匹配返回0成功,返回-1失败
{
	PUser L=head;
	if(head==NULL)
	{
		return -1;
	}
	else
	{
		L=user_search(head,name);
		if(L!=NULL)
		{
			if(strcmp(L->pswd,pswd)==0)
			{
				return 0;
			}
		}
	 return -1;
	}

}

PUser user_pswd_modify(PUser head,char *name)//用户密码修改
{
	PUser L=NULL;
	if(head==NULL)
	{
		printf("没有用户信息.\n");
		return head;
	}
	else
	{
		L=user_search(head,name);
		char t[20]={};
		static int n=3;
		do
		{
			printf("请输入旧的用户密码\n");
			scanf("%s",t);
			while(getchar()!='\n');
			if(strcmp(t,L->pswd)==0)break;
			else if(n>0)
			{
				printf("密码错误,请重新输入.\n");
			}
			else if(n<=0)
			{
				printf("密码输入错误次数太多,程序返回.\n");
				return head;
			}
		}while(strcmp(t,L->pswd));
		int flag=0;
		char a[8],b[8];
		do
		{
			flag=0;
			printf("请输入用户密码.\n");
			scanf("%s",a);
			while(getchar()!='\n');
			printf("请再输入一次.\n");
			scanf("%s",b);
			while(getchar()!='\n');
			if(strcmp(a,b)!=0)
			{
				flag=~flag;
				printf("两次密码输入不一致,请重新输入.\n");
			}
		}while(flag);
		strcpy(L->pswd,a);
		return head;
	}
		
}


PUser user_wait_train_add(PUser head,char *name,char *train,char *start,char *des)
	//用户排队链表创建
{
	PUser L=NULL;
	L=user_search(head,name);
	PWtrain s=NULL;
	s=malloc(sizeof(Wtrain));
	if(s==NULL)
	{
		printf("malloc error\n");
		return head;
	}
	s->next=NULL;
	strcpy(s->train,train);
	strcpy(s->sta,start);
	strcpy(s->des,des);
	PWtrain t=L->train_head;
	if(t==NULL)
	{
		L->train_head=s;
	}
	else
	{
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=s;
	}
	return head;
}

PUser user_buytrain_add(PUser head,char *name,char *train,char *start,char *des)//用户已购票链表创建
{
	PUser L=NULL;
	L=user_search(head,name);
	PWtrain s=NULL;
	s=malloc(sizeof(Wtrain));
	if(s==NULL)
	{
		printf("malloc error\n");
		return head;
	}
	s->next=NULL;
	strcpy(s->train,train);
	strcpy(s->sta,start);
	strcpy(s->des,des);
	PWtrain t=L->buytrain_head;
	if(t==NULL)
	{
		L->buytrain_head=s;
	}
	else
	{
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=s;
	}
	return head;

}


void userinfo_print(PUser head,char *name)//打印用户个人信息
{
	PUser L=user_search(head,name);
	printf("用户名\tID\n");
	printf("%s\t%s\n",L->name,L->ID);
	PWtrain s=L->buytrain_head,t=L->train_head;
	printf("已购票:\n");
	while(s!=NULL)
	{
		printf("%s\t",s->train);
		s=s->next;
	}
	printf("\n");
	printf("正排队的票:\n");
	while(t!=NULL)
	{
		printf("%s\t",t->train);
		t=t->next;
	}
	printf("\n");
	
}

int user_waittrain_check(PTr head,PUser Uhead,char *name)//查找已登录用户排队的车次是否有余票
{
	if(Uhead==NULL)return 0;
	PUser L=Uhead;
	int flag=0;
	while(L!=NULL)
	{
		if(strcmp(L->name,name)==0)
		{
			if(L->train_head==NULL)return 0;
			PTr s=head;
			PWtrain t=L->train_head;
			while(s!=NULL)
			{
				if(strcmp(s->ticket,t->train)==0)
				{
					if(s->wait_head!=NULL)
					{
						if(strcmp(s->wait_head->name,name)==0)
						{
							if(s->remain>=1)
							{
								char ans;
								printf("\n您预定的%s车次已有余票,是否购买?\n  输入Y购买,其他任意字符取消\n",t->train);
								ans=getchar();
								while(getchar()!='\n');
								if(ans=='Y'||ans=='y')
								{
									s->remain=s->remain-1;
									user_buytrain_add(Uhead,name,t->train,t->sta,t->des);	
									user_waittrain_del(Uhead,name,t->train);
									train_wait_del(head,name,t->train);
									flag=1;
									printf("购票成功.\n");
								}
								else
								{
									printf("是否取消排队?输入Y取消排队\n其他任意字符保留排队信息\n");
									char choice=getchar();
									while(getchar()!='\n');
									if(choice=='Y'||choice=='y')
									{
										train_wait_del(head,name,t->train);
										user_waittrain_del(Uhead,name,t->train);
										printf("您已取消购买,您的排队信息将被删除.\n");
									}
									else
									{
										printf("您已取消购买,您的排队信息将被保留.\n");
									}
									flag=1;
								}
							}
						}
					}
				}
				s=s->next;
			}
		}
		L=L->next;
	}
	if(L==NULL&&flag!=0)  return 1;
	else return 0;

}


PUser user_waittrain_del(PUser head,char *name,char *train)//用户排队等候车票删除
{
	PUser L=user_search(head,name);
	if(head==NULL)return head;
	PWtrain s=L->train_head,t=s;
	if(L->train_head!=NULL)
	{
		while(s!=NULL)
		{
			if(strcmp(L->train_head->train,train)==0)
			{
				L->train_head=L->train_head->next;
				break;
			}
			else if(strcmp(s->train,train)==0)
			{	
				t->next=s->next;
				break;
			}
			t=s;
			s=s->next;
		}
	}


}


PUser user_buytrain_del(PUser head,char *name,char *train)//用户已购票删除
{
	PUser L=user_search(head,name);
	if(head==NULL)return head;
	PWtrain s=L->buytrain_head,t=s;
	if(L->buytrain_head!=NULL)
	{
		while(s!=NULL)
		{
			if(strcmp(L->buytrain_head->train,train)==0)
			{
				L->buytrain_head=L->buytrain_head->next;
				break;
			}
			else if(strcmp(s->train,train)==0)
			{
				t->next=s->next;
				break;
			}
			t=s;
			s=s->next;
		}
	}
}


PTr train_wait_del(PTr head,char *name,char *train)//车票所挂排队用户删除
{
	PTr L=Train_searchBytrain(head,train);
	PWait s=L->wait_head,t=s;
	if(L->wait_head==NULL)
		return head;
	else
	{
		if(strcmp(s->name,name)==0)
			L->wait_head=L->wait_head->next;
	}

}
/***********************全局函数的申明**************************/

