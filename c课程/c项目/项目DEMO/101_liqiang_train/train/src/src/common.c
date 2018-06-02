/*文件名：common.c
*功能：管理员管理
*作者：
*日期：
*修改记录：新建
*/


/***********************头文件包含******************************/

#include "common.h"
#include "train.h"
/***********************头文件包含******************************/

/***********************结构体定义 宏定义************************/



/***********************结构体定义 宏定义************************/

/***********************全局变量的申明**************************/



/***********************全局变量的申明**************************/

/***********************函数的申明**************************/
void Train_Link_Write(PTr head)//车票信息链表保存到文件
{
	PTr L=head;
	int ret;
	FILE *fp = NULL;
	fp = fopen("train","wb+");
	if(fp==NULL)	return ;
	while(L!=NULL)
	{
		ret=fwrite(L,sizeof(Tr),1,fp);
		if(ret<1)
		{
			printf("写入失败.\n");
			return ;
		}
		PSta s=L->sta_head;
		while(s!=NULL)
		{
			ret=fwrite(s,sizeof(Sta),1,fp);
			if(ret<1)
			{
				printf("写入失败.\n");
				return;
			}
			s=s->next;
		}
		PWait t=L->wait_head;//排队队列首地址
		if(L->wait_head!=NULL)
		{
			while(t!=NULL)
			{
				ret=fwrite(t,sizeof(Wait),1,fp);
				if(ret<1)
				{
					printf("写入失败.\n");
					return;
				}
				t=t->next;
			}
		}
		L=L->next;
	}
	fclose(fp);
}


PTr Train_Link_Read()//列车链表 信息从文件读入
{
	FILE *fp=NULL;
	PTr head=NULL;
	fp=fopen("train","rb");
	if(fp==NULL)	return NULL;
	PTr s=NULL;
	while(1)
	{
		 s=malloc(sizeof(Tr));
		int ret=fread(s,sizeof(Tr),1,fp);
		if(ret!=0)
		{
			if(head==NULL)
			{
				s->next=NULL;
				head=s;
			}
			else
			{
				PTr p=head;
				while(p->next!=NULL)
				{
					p=p->next;
				}
				s->next=NULL;
				p->next=s;

					
			}
			PSta t=NULL;
			PSta p=s->sta_head=NULL;
			int i=s->des_num;
			while(i>0)
			{
				t=malloc(sizeof(Sta));
				int ret1=fread(t,sizeof(Sta),1,fp);
				if(ret1!=0)
				{
					if(s->sta_head==NULL)
					{
						t->next=NULL;
						s->sta_head=t;
					}
					else
					{
						PSta tail = NULL;
						p = s->sta_head;
						while(p!=NULL)
						{
							tail=p;
							p=p->next;
						}
						t->next = NULL;
						tail->next = t;
					}
				}
				i--;
			}
		//	free(t);
			if(s->wait_head!=NULL)
			{
				PWait m=s->wait_head=NULL;
				while(1)
				{
					m=malloc(sizeof(Wait));
					int ret=fread(m,sizeof(Wait),1,fp);
						PWait p=m->next;
					if(ret!=0)
					{
						if(s->wait_head==NULL)
						{
							m->next=NULL;
							s->wait_head=m;
						}
						else
						{
							PWait tail=NULL;
							PWait t=s->wait_head;
							while(t!=NULL)
							{
								tail=t;
								t=t->next;
							}
							m->next=NULL;
							tail->next=m;
						}
					}
					if(p==NULL)break;
				}
			//	free(m);
			}
		}
		if(ret==0)break;
	}
	free(s);
	fclose(fp);
	return head;
}

void User_data_write(PUser head)//用户信息写入文件
{
	PUser L=head;
	FILE *fp=NULL;
	fp=fopen("user","wb+");
	if(fp==NULL)return;
	while(L!=NULL)
	{
		int ret=fwrite(L,sizeof(User),1,fp);
		if(ret<1)
		{
			printf("写入失败.\n");
			return;
		}
		else
		{
			PWtrain s=L->train_head;
			while(s!=NULL)
			{
				int ret=fwrite(s,sizeof(Wtrain),1,fp);
				if(ret<1)
				{
					printf("写入失败.\n");
					return;
				}
				s=s->next;
			}
			PWtrain p=L->buytrain_head;
			while(p!=NULL)
			{
				int ret=fwrite(p,sizeof(Wtrain),1,fp);
				if(ret<1)
				{
					printf("写入失败.\n");
					return;
				}
				p=p->next;
			}
		}
		L=L->next;
	}
	fclose(fp);

}

PUser User_data_read()//从文件读出用户信息
{
	PUser s,head=NULL;
	FILE *fp=NULL;
	fp=fopen("user","rb");
	if(fp==NULL)return NULL;
	while(1)
	{
		s=malloc(sizeof(User));
		if(s==NULL)
		{
			printf("malloc errer\n");
			fclose(fp);
			return NULL;
		}
		int ret = fread(s,sizeof(User),1,fp);
		if(ret==0)break;
	//	PUser tempuser=s->next;
		s->next=NULL;
		if(head==NULL)
		{
			head=s;
		}
		else
		{
			PUser L=head,p=NULL;
			while(L!=NULL)
			{
				p=L;
				L=L->next;
			}
			p->next=s;
		}
		PWtrain m=NULL,t=s->train_head;
		int ret1;
		if(t!=NULL)
		{
			s->train_head =NULL;
			while(1)
			{

				m=malloc(sizeof(Wtrain));
				if(m==NULL)
				{
					printf("malloc errer\n");
					fclose(fp);
					return NULL;
				}
				ret1=fread(m,sizeof(Wtrain),1,fp);
				PWtrain tmpDone=m->next;
				m->next=NULL;
				if(s->train_head==NULL)
				{
					s->train_head=m;
				//	t = m;
				}
				else
				{
					t=s->train_head;
					PWtrain tail=NULL;
					while(t!=NULL)
					{
						tail=t;
						t=t->next;
					}
					tail->next=m;

				}
				if(tmpDone==NULL)
					break;
			}
		//	free(m);
		}
		PWtrain buytrain=NULL,u=s->buytrain_head;
		int ret2;
		if(u!=NULL)
		{

			s->buytrain_head=NULL;
			while(1)
			{
				buytrain=malloc(sizeof(Wtrain));
				if(buytrain==NULL)
				{
					printf("malloc error\n");
					fclose(fp);
					return NULL;
				}
				ret2=fread(buytrain,sizeof(Wtrain),1,fp);
				PWtrain tmpBuy=buytrain->next;
				buytrain->next=NULL;
				if(s->buytrain_head==NULL)
				{
					s->buytrain_head=buytrain;
				}
				else
				{
					PWtrain tail=NULL;
					u=s->buytrain_head;
					while(u!=NULL)
					{
						tail=u;
						u=u->next;
					}
					tail->next=buytrain;
				}
				if(tmpBuy==NULL)
					break;
			}
		//	free(buytrain);
		}
	//	if(tempuser==NULL)break;
	}
	free(s);
	fclose(fp);
	return head;

}

void admin_data_write(PAdmin head)//管理员数据写入文件
{
	FILE *fp;
	fp=fopen("admin","wb+");
	if(fp==NULL)return;
	int ret=fwrite(head,sizeof(Admin),1,fp);
	if(ret<1)printf("写入失败.\n");
	fclose(fp);
}


PAdmin admin_data_read()//管理员数据从文件读出
{
	FILE *fp;
	fp=fopen("admin","rb");
	if(fp==NULL)return NULL;
	int ret;
	PAdmin s=NULL,L=NULL;
	while(1)
	{
		s=malloc(sizeof(Admin));
		ret=fread(s,sizeof(Admin),1,fp);
			L=s;
		if(ret==0)
		{
			break;
		}
	}
//	free(s);
	fclose(fp);
	return L;
}

/***********************函数的申明**************************/

