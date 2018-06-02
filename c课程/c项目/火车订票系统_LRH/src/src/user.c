#include"user.h"

//PUser Head_user = NULL;

/*判断用户信息链表链表是否已满 是返回0 否返回-1*/
static int malloc_full_user()
{
	PUser head = NULL;
	head = (PUser)malloc(sizeof(User));
	if(head == NULL)
	{
		free(head);
		head = NULL;
		return 0;
	}
	else
	{
		free(head);
		head = NULL;
		return -1;
	}
}


/*判断用户车次链表是否已满 是返回0 否返回-1*/
static int malloc_full_user_info_train()
{
	PU_i_t head = NULL;
	head = (PU_i_t)malloc(sizeof(U_i_t));
	if(head == NULL)
	{
		free(head);
		head = NULL;
		return 0;
	}
	else
	{
		free(head);
		head = NULL;
		return -1;
	}
}

/*************尾插法建立用户信息链表*************/
/*
PUser user_link_creat()
{
	PUser user_head = NULL,p = NULL,q = NULL;
	char name[NAME_SIZE];
	scanf("%s",name);	
	while(*name != ' ')
	{
		if(!malloc_full_user())
		{
			printf("malloc error..");
			printf("%s",__FILE__);
			printf("%s",__func__);
			printf("%d",__LINE__);
			return NULL;
		}
		else
		{
			p = (PUser)malloc(sizeof(User));
			strcpy(p->name,name);
			if(user_head == NULL)
				user_head = p;
			else
			{
				q->next = p;
				p->next = NULL;
			}
			q = p;
			//printf("请输入用户性别、年龄、证件号\n");
			//scanf("%s%s%s",p->sex,&p->old,p->ID);
			printf("请输入密码:\n");
			scanf("%s",p->passward);
			printf("请输入用户名:\n");
			scanf("%s",name);
		}
	}
	return user_head;
}
*/

/****************************************************
*func:user_name_check
*describtion:检查用户名是否已经注册
*已经注册返回 0  没注册返回1
*****************************************************/
int user_name_check(PUser head_user,char *name)
{
	PUser p = head_user;
	if(head_user == NULL)
		return 1;
	while(p != NULL)
	{
		if(!strcmp(p->name,name))
			return 0;
		p = p->next;
	}
	return 1;
}


/****************************************************************************
*新用户注册
*func:new_user_login
*function:新用户登陆时，添加注册信息到用户信息链表中
**************************** ************************************************/
PUser new_user_login(PUser head_user)
{
	new_user_menu_print();
	static int ID =101;
	PUser p = NULL,q = NULL;
	if(malloc_full_user())
	{
		char user_name[NAME_SIZE];
		char passward1[PASS_MAX],passward2[PASS_MAX];
		while(1)
		{
			printf("\n请输入用户名:");
			scanf("%s",user_name);
			while(getchar() != '\n');
			if(!user_name_check(head_user,user_name))
				printf("\n该用户名已注册，请重新输入用户名:\n");
			else
				break;
		}

		p = (PUser)malloc(sizeof(User));
		strcpy(p->name,user_name);
		
		/*检验密码输入格式*/
		while(1)
		{
			printf("\n请输入6位数密码:");
			//检查第一次密码是否符合要求
			while(1)
			{
				scanf("%s",passward1);
				while(getchar() != '\n');
				if(strlen(passward1) == PASS_NUM - 1)
					break;
				else
				{
					printf("\n密码长度不符,请重新输入\n");
				}
			}

			printf("\n请再次输入密码:");
			//检验第二次密码是否符合要求
			while(1)
			{
				scanf("%s",passward2);
				while(getchar() != '\n');	
				if(strlen(passward2) == PASS_NUM - 1)
					break;
				else
				{
					printf("\n密码长度不符,请重新输入\n");
				}
			}
			//检验两次输入的密码是否匹配
			if(strcmp(passward1,passward2))
			{
				printf("\n两次输入的密码不一致，请重新输入:\n");
			}
			else
				break; 
		}
		/**************/

		/*用户注册信息录入*/
		strcpy(p->passward,passward1);
		p->ID = ID++;
		p->ticket_num = 0;
		p->next = NULL;
		p->pu_i_t = NULL;
		if(head_user == NULL)
			head_user = p;
		else
		{	
			q = head_user;
			while(q->next != NULL)//查找用户信息链表的最后一个结点
				q = q->next;
			q->next = p;
		}
		printf("\n注册成功,请登录\n");
		sleep(1);
		return head_user;
	}
	else
	{	
			printf("\n注册失败，请重试..\n");
			sleep(1);
	}
	return head_user;
}

/*********************************************************************
*func:user_login
*describtion:用户登录检查 登录成功返回0 失败返回-1和当前用户的地址
**********************************************************************/
int user_login(PUser user_head,PUser *user)
{
	//system("clear");
	PUser p = user_head;
	if(user_head == NULL)
	{	
		*user = NULL;
		return -1;
	}
	char name[NAME_SIZE],passward[PASS_NUM];
	int flag = 0;

	//system("clear");
	user_log_print();

	printf("\n用户名:");
	scanf("%s",name);
	while(getchar() != '\n');

	while(p != NULL)
	{
		if(!strcmp(p->name,name))
		{
			flag = 1;
			break;
		}
		p = p->next;
	}
	if(flag)
	{
		int n = 3;
		//flag = 0;
		printf("\n密  码:");
		while(n)
		{
			scanf("%s",passward);
			while(getchar() != '\n');
			if(strcmp(p->passward,passward))
			{
				n--;
				if(n)
					printf("\n密码不正确,还剩%d次机会\n",n);
			}
			else
			{
				//flag = 1;
				break;
			}
		}
		if(n)
		{
			*user = p;
			printf("\n登录成功\n");
			sleep(1);
			return 0;
		}
		else
		{
			*user = NULL;
			printf("\n输入错误密码次数过多，请稍候稍后重试\n");
			sleep(1);
			return -1;
		}
	}
	else
	{
		*user = NULL;
		printf("\n此用户尚未注册，请注册后在登录..\n");
		sleep(1);
		return -1;
	}
}


/********************************************************************************
*func:user_info_search
*describtion:查看用户订票信息
********************************************************************************/
void user_info_search(const PUser head)
{
	//printf("用户名:\n");
	system("clear");
	printf("\n\t\t\t\t***************用 户 信 息 查 看******************\n\n");
	//printf("用户名:%s\n",head->name);

	user_tic_sort_date(head);
	PU_i_t p = head->pu_i_t;
	if(p == NULL)
	{	
		printf("您暂无订票信息..\n");
		sleep(1);
		return;
	}
	else
	{
		printf("\n订票信息:\n\n");
		printf("乘车日期\t车次\t出发站\t到站\t发车时间\t旅程时间\n");
		while( p != NULL)
		{
			printf("%d-%2d-%2d\t%s\t%s\t%s\t%2d:%2d\t\t%2d小时%2d分\n",p->date.year,
				p->date.month,p->date.day,p->train_num,p->start_name,p->end_name,
				p->depart_hour,p->depart_minute,p->run_hour,p->run_minute);
			p = p->next;
		}
		//printf("\n\n请输入任意键继续..\n");
		while(getchar() != '\n');
	}
}

/*********************************************************************
*func:user_info_change
*describtion:修改用户密码
*********************************************************************/
void user_info_change(PUser user)
{
	system("clear");
	printf("\n\t\t\t\t***************用 户 信 息 修 改******************\n\n");
	char name[NAME_SIZE],passward1[PASS_NUM],passward2[PASS_NUM];
	printf("\n请输入原密码:");
	scanf("%s",passward1);
	while(getchar() != '\n');
	if(!strcmp(user->passward,passward1))
	{
		printf("\n请输入用户名:");
		scanf("%s",name);
		while(1)
		{
			printf("\n请输入密码:");
			scanf("%s",passward1);
			while(getchar() != '\n');

			printf("\n请再次输入密码:");
			scanf("%s",passward2);
			while(getchar() != '\n');

			if(!strcmp(passward1,passward2))
				break;
			else
				printf("\n两次输入的密码不匹配\n");
		}
		strcpy(user->name,name);
		strcpy(user->passward,passward1);
		printf("\n密码修改成功\n");
		printf("\n用户名:%s\n\n密  码:%s\n",user->name,user->passward);
		//printf("管理员信息修改\n");
		sleep(2);
	}
	else
	{
		printf("\n原密码输入不正确,密码修改失败\n");
		sleep(1);
	}
}
/********************************************************************
*func:user_info_add
*function:
*将用户的订票信息(车次、出发站、到站)链接到用户链表中
*********************************************************************/
void user_train_info_add(PTra train,PUser User,Date date,char *ch,
		char *start,char*end)
{
	PU_i_t p = User->pu_i_t,q = NULL;
	PSta m = NULL, n = NULL;
	//static num;
	if(malloc_full_user_info_train())
	{	
		q = (PU_i_t)malloc(sizeof(U_i_t));
		q->next = NULL;
		if(p == NULL)
		{
			User->pu_i_t = q;
		}
		else
		{
			while(p->next != NULL)
				p = p->next;
			p->next = q;
		}
		/*保存车票信息*/
		//q->num = num++;//车票序号
		q->date = date;//乘车日期
		strcpy(q->train_num,ch);//乘车车次
		strcpy(q->start_name,start);//出发站
		strcpy(q->end_name,end);//目的站
		User->ticket_num++;//用户票数++

		//找到车站地址后，计算车站间经历的时间
		m = sta_address_search(train,start);//出发站地址
		n = sta_address_search(train,end);//到站地址
		int d_h = 0,d_m = 0,r_h = 0,r_m = 0;
		if(m != NULL && n != NULL)
		{
			train_time_count(m,n,&d_h,&d_m,&r_h,&r_m);//计算两站之间的时间
		}
		
		q->depart_hour = d_h;//发车时间(小时)
		q->depart_minute = d_m;//发车时间(分钟)
		q->run_hour = r_h;//运行时间(小时)
		q->run_minute = r_m;//运行时间(分钟)

		//user_tic_sort_date(User);//按乘车日期排序
	}
	return;
}


/***************************************************************************
*func:ticket_reservation
*function:用户订票函数
*****************************************************************************/
void ticket_reservation(PUser user_head,const PTra head_train)
{
	PTr tr_head = NULL;
	char start[STA_NAME],end[STA_NAME];
	Date date;
	//printf("请输入您的出发站和到站\n");
	system("clear");
	printf("\n\t\t\t\t***************用   户   订   票******************\n\n");
	while(1)
	{
		printf("\n请选择出行日期(year-month-day):");
		scanf("%d-%d-%d",&date.year,&date.month,&date.day);
		while(getchar() != '\n');

		if(date_check(date.year,date.month,date.day))
			printf("\n日期格式不正确，请重新输入..\n");
		else
			break;
	}
	printf("\n请输入您的出发站:");
	scanf("%s",start);
	while(getchar() != '\n');
	printf("\n请输入您的到站:");
	scanf("%s",end);
	while(getchar() != '\n');
	
	//站站查询
	tr_head = station_search(head_train,start,end);

	
	if(tr_head == NULL)
	{
		printf("\n抱歉,无%s到%s的直达列车,请转车..\n",start,end);
		sleep(1);
		return;
	}

	//int reservation_flag = 0;
	char train[STA_NAME],ch;
	int re;
	PTra pt = NULL;
	PSta pta = NULL;
	PTr p = NULL;

	
	while(1)
	{
		system("clear");
		//打印站站查询结果
		printf("\n查询结果:\n");
		print(tr_head,start,end);
		printf("\n请输入要订购列车车次:");
		scanf("%s",train);
		while(getchar() != '\n');
		p = tr_head;
		while(p!= NULL)
		{
			if(!strcmp(p->ptra->train_num,train))
			{
				/*校验余票*/
				if(!ticket_left_inspect(p->ptra,start))
				{
					//system("clear");
					printf("\n%s列车从%s站到%s站的车票已卖完，是否要预订票(y or n)?\n",train,start,end);
					ch = getchar();
					while(getchar() != '\n');
					if(ch != 'y' && ch != 'n')
					{
						while(1)
						{
							printf("\n输入无效，请重新选择..\n");
							ch = getchar();
							while(getchar() != '\n');
							if(ch == 'y' || ch == 'n')
								break;
						}
					}
					if(ch == 'y')
					{
						re = adv_book_ticket(p->ptra,user_head,date,train,start,end);
						if(re)
						{	
							printf("\n预订票成功\n");
							sleep(1);
						}
						else
						{
							printf("\n预订票失败，请重试..\n");
							sleep(1);
						}
						link_del(tr_head);
						return;
					}
					else
					{
						//printf("");
						link_del(tr_head);
						return;
					}
				}
				/*********************/
				
				/*有余票订票*/
				system("clear");
				printf("车次\t出发站\t\t到站\t\t余票\t发车时间\t到站时间\n");
				single_print(p->ptra,start,end);
				printf("\n确认订购该次的列车(y or n)?\n");
				ch = getchar();
				while(getchar() != '\n');
				if(ch != 'y' && ch != 'n')
				{
					while(1)
					{
						printf("\n输入无效，请重新选择..\n");
						ch = getchar();
						while(getchar() != '\n');
						if(ch == 'y' || ch == 'n')
							break;
					}
				}
				if(ch == 'y')
				{
					//ps = tr_head->ptra->pst;   
					//pe = end_station_search(tr_head->ptra);
					user_train_info_add(p->ptra,user_head,date,train,start,end);
					
					/*对应车站的票数--*/
					//查找车次地址
					pt = train_address_search(p->ptra,train);
					pta = pt->pst;
					
					while(pta != NULL)
					{
						if(!strcmp(pta->sta_name,start))
						{
							pta->ticket_num --;
							if(pta->ticket_num <= 0)
								pta->ticket_num = 0;
							break;
						}
						pta = pta->next;
					}
					
					printf("\n订票成功\n");
					sleep(1);
					
					link_del(tr_head);
					return;
					//printf("订票成功\n");
					//reservation_flag = 1;
				}
				//while(getchar() != '\n');
				else
					break;
			}
			p = p->next;
		}
		printf("\n输入的车次不存在，请重新选择..\n");
		sleep(1);
	}
	link_del(tr_head);
}

/**************************************************************
*func:adv_book_ticket
describtion:预订票（建立队列）
***************************************************************/
int adv_book_ticket(PTra train,PUser user,Date date,char *tr,char *st,char *end)
{
	PQueue queue = train->pqueue,s = NULL;	
	s = (PQueue)malloc(sizeof(Queue));
	if(s == NULL)
		return 0;
	strcpy(s->train_num,tr);
	strcpy(s->start_name,st);
	strcpy(s->end_name,end);
	s->date = date;
	strcpy(s->name,user->name);
	if(queue == NULL)
		train->pqueue = s;
	else
	{
		while(queue->next != NULL)
			queue = queue->next;
		queue->next = s;
	}
	s->next = NULL;
	return 1;
}

/*************************************************************
*func:ticket_left_inspect
*describtion:查看要订购的车票是否还有余票，有返回1 无返回0
*************************************************************/
int ticket_left_inspect(PTra head_train,char *sta)
{
	if(head_train != NULL)
	{
		PSta p = head_train->pst;
		while(p != NULL)
		{
			if(!strcmp(p->sta_name,sta))
			{
				if(!p->ticket_num)
					return 0;
				else
					return 1;
			}
			p = p->next;
		}
	}
	return 0;
}
/*************************************************************
*func:adv_book_deal
*describtion:用户登录后选择是否需要预定的车票
**************************************************************/
void adv_book_deal(PTra head_train,PUser user)
{
	PTra pt = head_train;
	PQueue queue  = NULL,p = NULL;
	PSta pa = NULL;
	char ch;
	while(pt != NULL)
	{
		if(pt->pqueue != NULL)
		{
			queue = pt->pqueue;
			if(!strcmp(queue->name,user->name))
			{
				pa = pt->pst;
				while(pa != NULL)
				{
					if(!strcmp(pa->sta_name,queue->start_name))
						if(pa->ticket_num)
						{
							//user_menu_print(user);//用户菜单页面
							system("clear");
							printf("\n您预订购的从%s到%s的%s列车已有余票,是否订购(y or n)?",queue->start_name,queue->end_name,queue->train_num);
							while(1)
							{
								ch = getchar();
								while(getchar() != '\n');
								if(ch != 'y' && ch != 'n')
								{
									printf("\n输入无效，请重新输入..\n");
								}
								else
								{
									if(ch == 'n')
									{
										p = queue;
										pt->pqueue = p->next;
										free(p);
										p = NULL;
										return;
									}
									else
									{
										user_train_info_add(pt,user,queue->date,pt->train_num,queue->start_name,queue->end_name);
										pa->ticket_num--;
										if(pa->ticket_num < 0)	
												pa->ticket_num = 0;
										printf("\n订票成功\n");
										sleep(1);
										p = queue;
										pt->pqueue = p->next;
										free(p);
										p = NULL;
										return;
									
									}
								
								}
							}
						
						}
					pa = pa->next;
				}			
			}
		}
		pt = pt->next;
	}
}

/*************************火车票退订*************************/
void ticket_refund(PUser head,PTra train_head)
{
	PU_i_t p = head->pu_i_t,q = NULL;
	PTra pt = NULL;
	PSta pta = NULL;
	char ch[STA_NAME];
	system("clear");
	printf("\n\t\t\t\t***************用   户   退   票******************\n\n");
	if(p == NULL)
	{
		printf("\n您暂无订票信息，不能退票..\n");
		sleep(1);
		return;
	}
#if 0	
	Date date;
	printf("请输入乘车日期:\n");
	scanf("%d-%d-%d",&date.year,&date.month,&date.day);
	while(getchar() != '\n');

	printf("请输入想要退订的车次:\n");
	scanf("%s",ch);
	while(getchar() != '\n');
#endif	

	//用户订票数减1
	head->ticket_num--;
	if(head->ticket_num < 0)
		head->ticket_num = 0;
	int n;
	while(1)
	{	
		system("clear");
		printf("\n\t\t\t\t***************用   户   退   票******************\n\n");
		//将用户的订票信息打印出来用户 便于用户选择退票车次
		ticket_refund_search(head);
		printf("\n请输入你想要退订的车票序号:");
		scanf("%d",&n);
		while(getchar() != '\n');
		p = head->pu_i_t;

		//第一张车票
		if(p->num == n)
		{      
			pt = train_address_search(train_head,p->train_num);
			if(pt != NULL)
			{
				pta = pt->pst;
				/*退票后对应车站的票数++*/
				while(pta != NULL)
				{
					if(!strcmp(pta->sta_name,p->start_name))
					{
						pta->ticket_num++;
						if(pta->ticket_num >= 2)
							pta->ticket_num = 2;
						break;
					}
					pta = pta->next;
				}
				//删除对应的车票
				head->pu_i_t = p->next;
				free(p);
				p = NULL;

				printf("\n退票成功\n");
				sleep(1);
				return;
			}
			else
			{
				printf("\n退票失败,请重试..\n");
				sleep(1);
			}

		}
		else
		{	//遍历车票
			while(p->next != NULL)
			{
				if(p->next->num == n)
				{
					pt = train_address_search(train_head,p->next->train_num);
					if(pt != NULL)
					{
						pta = pt->pst;
						/*退票后对应车站的票数++*/
						while(pta != NULL)
						{
							if(!strcmp(pta->sta_name,p->next->start_name))
							{
								pta->ticket_num++;
								if(pta->ticket_num >= 2)
									pta->ticket_num = 2;
								break;
							}
							pta = pta->next;
						}
					}
					else
					{
						printf("\n退票失败,请重试..\n");
						sleep(1);
						break;
					}

					q = p->next;
					p->next = q->next;
					free(q);
					q = NULL;				
					printf("\n退票成功\n");
					sleep(1);
					return;
				}
				p = p->next;
			}
			printf("\n选择的车票不存在，请重新选择\n");
			sleep(1);
		}
	}
}

/******************************************************
*func:退票查询
*describtion: 
*打印用户订票信息
********************************************************/

void ticket_refund_search(const PUser head)
{
	//ticket_scort(head);
	PU_i_t p = head->pu_i_t;
	int num = 0;
	//system("clear");
	if(p != NULL)
	{
		printf("订票信息:\n");
		printf("序号\t乘车日期\t\t车次\t出发站\t\t到站\t\t发车时间\t运行时间\n");
		while( p != NULL)
		{
			p->num = num++;			
			printf("%d\t%d-%d-%d\t\t%s\t%s\t\t%s\t\t%d:%d\t\t%d小时%d分钟\n",p->num,p->date.year,
				p->date.month,p->date.day,p->train_num,p->start_name,p->end_name,
				p->depart_hour,p->depart_minute,p->run_hour,p->run_minute);
			p = p->next;
		}

		//sleep(5);
	}
}


/***********************************************
*func:date_check
*describtion:校验日期是否正确
************************************************/
int date_check(int year,int month,int day)
{
	int error = 0;
	if(month <= ZERO || month > MONTH)
		error = 1;
	else
	{
		switch(month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if(day > 31)
					error = 1;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if(day > 30)
					error = 1;
				break;
			case 2:
				if(year%4==0 && year%100!=0 || year%400==0)
					if(day > 29)
						error = 1;
				else 
					if(day > 28)
						error = 1;
				break;
		}
	}
	return error;
}

/*****************************************************
*func:date_compare
*describtion:比较日期是否相等
******************************************************/
int date_compare(PU_i_t p,Date date)
{
	if( p != NULL)
	{
		if(p->date.year == date.year && 
			p->date.month == date.month &&
			p->date.day == date.day)
			return 0;
	}
	return -1;

}

/*************************************************************
*func:user_tic_sort_date
*describtion:将用户的订票信息按乘车日期排序
**************************************************************/
void user_tic_sort_date(PUser User)
{
	if(User  == NULL)
		return;
	PU_i_t tic = User->pu_i_t,pmax = NULL,head = NULL;
	while(tic != NULL)
	{
		pmax = pmax_search(tic);
		tic = pmax_remove(tic,pmax);
		head = new_sort(head,pmax);
		//tic = tic->next;	
	}
	User->pu_i_t = head;
}

/*************************************************************
*func:pmax_search
*describtion:查找用户车票中最晚乘车日期的车票的指针
**************************************************************/
PU_i_t pmax_search(PU_i_t head_tic)
{
	PU_i_t pmax = head_tic;
	if(head_tic != NULL)
	{	
		//PU_i_t pmax = head_tic;
		while(head_tic!= NULL)
		{
			if((pmax->date.month < head_tic->date.month)
			   || (pmax->date.month == head_tic->date.month)
			      && (pmax->date.day < head_tic->date.day))
				pmax = head_tic;
			head_tic = head_tic->next;
		}
	}
	return pmax;
}

/**************************************************************
*func:pmax_remove
*describtion:移除车票中最后日期的车票
***************************************************************/
PU_i_t pmax_remove(PU_i_t head_tic,PU_i_t pmax)
{
	PU_i_t p = head_tic;
	if(head_tic == pmax)
		head_tic = pmax->next;
	else
	{
		while(p->next != pmax)
			p = p->next;
		p->next = pmax->next;
	}
	//p->next = pmax->next;
	pmax->next = NULL;
	return head_tic;
}

/**************************************************************
*func:new_user_sort
*describtion:将最晚日期的车票添加到新链表中
**************************************************************/
PU_i_t new_sort(PU_i_t new_head,PU_i_t pmax)
{
	pmax->next = new_head;
	new_head = pmax;
	return new_head;
}

