/*文件名：train.c
*功能：管理员管理
*作者：
*日期：
*修改记录：新建
*/


/***********************头文件包含******************************/

#include "train.h"

/***********************头文件包含******************************/

/***********************局部变量的申明**************************/



/***********************局部变量的申明**************************/

/***********************局部函数的申明**************************/
PSta StationCreat()//车次信息的增加
{
	PSta s,head=NULL;
	int choice=1;
	int i=0,n=0;
	do
	{
		i++,n++;
		s=(PSta)malloc(sizeof(Sta));
		if(s==NULL)
		{
			printf("malloc error.\n");
			assert(0);
		}
		s->next=NULL;
		printf("请输入第%d站的站点名称.\n",i);	
		scanf("%s",s->sta);
		while(getchar()!='\n');
		printf("请输入到达该站的时间．\n");
		scanf("%s",s->time);
		while(getchar()!='\n');
		if(head==NULL)
		{
			head=s;
		}
		else
		{
			PSta L=head;
			while(L->next!=NULL)
			{
				L=L->next;
			}
			L->next=s;
		}
		printf("输入0结束输入,其他任意字符继续.\n");
		scanf("%d",&choice);
		if(n<2&&choice==0)
		{
			printf("站点数必须大于等于2,请至少再输入一个站点.\n");
			choice=1;
		}
		while(getchar()!='\n');
	}while(choice);
	return head;
}

PTr TrainLinkInsert(PTr head)//车次的增加
{
	PTr s;
	int i;
	char choice;
	do
	{
		s=(PTr)malloc(sizeof(Tr));
		if(s==NULL)
		{
			printf("malloc error.\n");
			assert(0);
		}
		printf("请输入车次.\n");
		scanf("%s",s->ticket);
		s->wait_head=NULL;
		s->sta_head=NULL;
		while(getchar()!='\n');
		printf("请输入余票数量.\n");
		while(!scanf("%d",&s->remain)||s->remain<0)
		{
			while(getchar()!='\n');
			printf("请输入正整数.\n");;
		}
		while(getchar()!='\n');
		s->sta_head=StationCreat();
		PSta L=s->sta_head;
		strcpy(s->start,L->sta);
		strcpy(s->start_time,L->time);
		PSta p=L;
		i=0;
		while(L!=NULL)
		{
			p=L;
			i++;
			L=L->next;
		}
		s->des_num=i;
		strcpy(s->des,p->sta);
		strcpy(s->des_time,p->time);	
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
		printf("是否继续输入车次?输入Q/q退出,其他任意字符继续.\n");
		choice=getchar();
	}while(choice!='Q'&&choice!='q');
	return head;
}
void Train_modify(PTr head)//车次修改
{
	char sta[7];
	int i;
	PTr train=NULL;
	if(head==NULL)
	{
		printf("数据库中没有数据.\n");
		return ;
	}
	else
	{
		printf("请输入需要修改的车次名称.\n");
		scanf("%s",sta);
		while(getchar()!='\n');
		train=Train_searchBytrain(head,sta);
		if(train!=NULL)
		{
			printf("已找到该车次,请输入新的车次名称.原值为:%s\n",train->ticket);
			scanf("%s",train->ticket);
			while(getchar()!='\n');
			printf("请输入余票数量.原值为:%d\n",train->remain);
			while(!scanf("%d",&train->remain)||train->remain<0)
			{
				while(getchar()!='\n');
				printf("请输入正整数.\n");;
			}
			while(getchar()!='\n');
			train->sta_head=StationCreat();
			PSta L=train->sta_head;
			strcpy(train->start,L->sta);
			strcpy(train->start_time,L->time);
			PSta p=L;
			i=0;
			while(L!=NULL)
			{
				p=L;
				i++;
				L=L->next;
			}
			train->des_num=i;
			strcpy(train->des,p->sta);
			strcpy(train->des_time,p->time);
		}
	}
}

PTr Train_del(PTr head,char *train)//删除车次
{
	if(head==NULL)
		printf("数据中没有车次信息可以删除.\n");
	else if(strcmp(train,head->ticket)==0)
	{
		head=head->next;
	}
	else
	{
		PTr L=head,s=head;
		while(L!=NULL)
		{
			if(strcmp(train,L->ticket)==0)
			{
				s->next=L->next;
				printf("删除成功.\n");
				break;	
			}
			s=L;
			L=L->next;

		}
		if(L==NULL)
			printf("未找到车次为%s的列车.\n",train);
	}
	return head;
	
}

void Train_print(PTr head)//打印所有车票信息
{
	if(head==NULL)
	{
		printf("没有车票信息.\n");
	}
	else
	{
		printf("车次\t余票\t起点\t终点\t发车时间\t到达时间\n");
		PTr L=head;
		while(L!=NULL)
		{
			printf("%s\t%d\t%s\t%s\t  %s\t\t  %s\n",L->ticket,L->remain,L->start,L->des,L->start_time,L->des_time);
			L=L->next;
		}
	}
}


void station_print(PTr head)//列车信息打印
{
	PSta s=head->sta_head,p=head->sta_head;
	if(head==NULL)
	{
		printf("没有信息可以显示.\n");
		return;
	}
	else
	{
		if(head->sta_head!=NULL)
		{
			printf("%s尚有余票%d张,票价为%d元.路线为:\n",head->ticket,head->remain,32*(head->des_num-1));
			while(s!=NULL)
			{
				if(s->next!=NULL)
					printf("%s->\t",s->sta);
				else
					printf("%s\t",s->sta);
				s=s->next;
			}
			printf("\n");
			while(p!=NULL)
			{
				if(p->next!=NULL)
					printf("%s->\t",p->time);
				else
					printf("%s\t",p->time);
				p=p->next;
			}
			printf("\n");
		}
	}
}

PTr Train_searchBytrain(PTr head,char *train)//通过车次查找列车信息
{
	if(head==NULL)
	{
		printf("数据库中没有列车信息.\n");
		return NULL;
	}
	else 
	{
		PTr L=head;
		while(L!=NULL)//遍历车次链表
		{
			if(strcmp(train,L->ticket)==0)
			{
				return L;
				break;
			}
			L=L->next;
		}
		if(L==NULL)
		{
			//printf("未找到车次为%s的列车.\n",train);
			return NULL;
		}

	}
}


PTr Train_searchByDes(PTr head,char *sta,char *des)//通过站点查找列车
{
	if(head==NULL)
	{
		//printf("数据库为空,无法查找.\n");
		return NULL;
	}
	else
	{
		PTr L=head;
		if(L->sta_head!=NULL)
		{
			PSta s=L->sta_head;
			while(L!=NULL)//遍历
			{
				s=L->sta_head;
				while(s!=NULL)
				{
					if(strcmp(sta,s->sta)==0)
					{
						PSta p=s->next;
						while(p!=NULL)
						{
							if(strcmp(des,p->sta)==0)
							return L;
							p=p->next;
						}	
					}
					s=s->next;
				}
				L=L->next;
			}
			if(L==NULL)
			{
			//	printf("未找到包含该区间的列车.\n");
				return NULL;
			}
		}
	}

}
/***********************局部函数的申明**************************/

