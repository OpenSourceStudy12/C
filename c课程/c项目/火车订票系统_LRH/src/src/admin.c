/*************************************************************************
*file name:admin.c
*func:管理员用户的操作函数
*authorL-R-H
*date:
*新建
*************************************************************************/
//头文件
#include"admin.h"
//#include"train.h"

/*************************************************
*func:malloc_full_train
*describtion:判断车次结构体空间是否已满
*************************************************/
static int malloc_full_train()
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

/*************************************************
*func:malloc_full_station
*describtion:判断车站结构体空间是否已满
*************************************************/
static int malloc_full_station(int n)
{
	PUser head = NULL;
	head = (PUser)malloc(sizeof(User)*n);
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
		return 1;
	}

}



/***********************************************
*func:admin_init
*describtion:设定管理员信息(账户和密码)
************************************************/
void admin_init(PAdmin *admin)
{
	*admin = (PAdmin)malloc(sizeof(Admin));
	strcpy((*admin)->name,ADMIN_NAME);
	strcpy((*admin)->passward,ADMIN_PASSWARD);
}

/************************************************
*func:admin_login
*describtion:管理员登录检测
*帐号密码匹配返回0,密码错误返回1,帐号错误返回-1
*************************************************/
int admin_login(PAdmin admin,char *name,char *passward)
{
	if(!strcmp(admin->name,name) && 
			!strcmp(admin->passward,passward))
		return 0;
	else if(!strcmp(admin->name,name) && 
			strcmp(admin->passward,passward))
		return 1;
	else
		return -1;
}

//管理员信息查看
/***********************************************************************
*func:admin_info_look
*describtion:查看管理员的信息(帐号、密码)
************************************************************************/
void admin_info_look(PAdmin admin)
{
	system("clear");
	printf("\n\t\t\t\t************管 理 员 信 息 查 看**************\n\n");
	printf("\n账户名:%s\n\n密  码:%s\n",admin->name,admin->passward);
	//printf("管理员信息查询\n");
	//printf("\n按任意键继续\n");
	while(getchar() != '\n');
	//sleep(1);
}


//管理员信息修改
/*****************************************************************************
*func:admin_info_change
*describtion:修改管理员的信息(帐号、密码)
******************************************************************************/
void admin_info_change(PAdmin head_admin)
{
	system("clear");
	printf("\n\t\t\t\t***************管 理 员 信 息 修 改******************\n\n");
	char name[NAME_SIZE],passward1[PASS_NUM],passward2[PASS_NUM];
	printf("\n请输入原密码:");
	scanf("%s",passward1);
	while(getchar() != '\n');
	if(!strcmp(head_admin->passward,passward1))
	{
		printf("\n请输入管理员账户名:");
		scanf("%s",name);
		while(1)
		{
			printf("\n请输入密码:");
			scanf("%s",passward1);

			printf("\n请再次输入密码:");
			scanf("%s",passward2);

			if(!strcmp(passward1,passward2))
				break;
			else
				printf("\n两次输入的密码不匹配\n");
		}
		strcpy(head_admin->name,name);
		strcpy(head_admin->passward,passward1);
		printf("\n信息修改成功\n");
		printf("\n账户名:%s\n\n密  码:%s\n",head_admin->name,head_admin->passward);
		//printf("管理员信息修改\n");
		sleep(2);
	}
	else
	{
		printf("\n原密码输入不正确,信息修改失败\n");
		sleep(1);
	}
}


//管理员车次查看
/****************************************************************
*func:train_look
*describtion:查看所有车次信息
*****************************************************************/
void train_look(PTra head_train)
{
	//printf("车次信息查看\n");
	//sleep(1);
	system("clear");
	printf("\n\t\t\t\t***************车   次   查   看******************\n\n");
	if(head_train == NULL)
	{
		printf("\n暂无车次信息\n");
		sleep(1);
		return;
	}
	
	PTra p = head_train;
	int i = 0;
	printf("\n所有列车车次:\n\n");
	while( p != NULL)
	{
		i++;
		printf("%s\t",p->train_num);
		if(i%5 == 0)
			putchar('\n');
		//route_map_print(p);
		p = p->next;
	}
	char ch[TRA_NUM];
	int flag;
	printf("\n\n请选择想要查看的车次:");
	//scanf("%s",ch);
	//while(getchar() != '\n');
	while(1)
	{
		flag = 0;
		p = head_train;
		scanf("%s",ch);
		while(getchar() != '\n');
	
		while(p != NULL)
		{
			if(!strcmp(p->train_num,ch))
			{
				route_map_print(p);
				flag = 1;
				break;
			}
			p = p->next;
		}
		if(flag)
			break;
		else
		{
			printf("\n输入的车次不存在，请重新选择..\n");
		}
	}

	//printf("\n\n输入任意键继续\n");
	while(getchar() != '\n');
}

/**********************************************************
*func:train_add
*describtion:添加列车车次车站信息
***********************************************************/
PTra train_add(PTra head_train)
{
	//printf("车次信息添加\n");
	//sleep(1);
	if(malloc_full_train)
	{
		int n,re;
		char train_name[TRA_NUM];
		
		system("clear");
		printf("\n\t\t\t\t***************车   次   添   加******************\n\n");
		/*检查输入的车次名是否已添加*/
		while(1)
		{
			printf("\n请输入车次名称:");
			scanf("%s",train_name);
			while(getchar() != '\n');

			re = train_name_check(head_train,train_name);
			if(!re)
				printf("\n该车次名已添加，请重新输入车次名\n");
			else
				break;
		}
#if 0	
		/*添加车次*/
		PTra s = (PTra)malloc(sizeof(Tra));
		s->next = NULL;
		if(head_train == NULL)
			head_train = s;
		else
		{
			PTra p = head_train;
			while(p->next != NULL)
				p = p->next;
			p->next = s;
		}
		s->pst = NULL;
		s->pqueue = NULL;
		/*为车次添加车站*/
		PSta pre = s->pst,cru = s->pst;
#endif	
		printf("\n请设置%s列车的站点数:",train_name);
		scanf("%d",&n);
		while(getchar() != '\n');
		

		if(malloc_full_station(n))
		{

			/*添加车次保存车次信息*/
			PTra s = (PTra)malloc(sizeof(Tra));
			s->next = NULL;

			if(head_train == NULL)
				head_train = s;
			else
			{
				PTra p = head_train;
				while(p->next != NULL)
					p = p->next;
				p->next = s;
			}
			s->pst = NULL;
			s->pqueue = NULL;
			/*为车次添加车站*/
			PSta pre = s->pst,cru = s->pst;

			s->station_num = n;//记录车次的站点数
			strcpy(s->train_num,train_name);
		/**********************************************/	

			cru = (PSta)malloc(sizeof(Sta)*n);
			int i,hour,minute;
			for(i=0;i<n;i++)
			{
				if(s->pst == NULL)
				{
					s->pst = cru;
					//printf("s-pst = %p\n",s->pst);//
				}
				else
					pre->next = cru;//将当前车站链接到上一个车站
				pre = cru;//保存当前车站地址

				/*添加车站的信息*/
				printf("\n请输入第%d个车站名:",i+1);
				scanf("%s",pre->sta_name);
				while(getchar() != '\n');

				//printf("请输入%s站到站时间:\n",pre->sta_name);
				//printf("请输入站到站时间(中间以:隔开):\n",pre->sta_name);
				while(1)
				{

					printf("\n请输入%s站到站时间(中间以:隔开):",pre->sta_name);
					scanf("%d:%d",&hour,&minute);
					while(getchar() != '\n');
					if(hour <= HOUR && hour >= ZERO && minute <= MINUTE && minute >= ZERO)
						break;
					else
					{
						printf("\n格式不正确，请重新输入..\n");
					}
				}
				pre->arrival_hour = hour;
				pre->arrival_minute = minute;

				
				//根据到站时间设定发车时间
				departure_time_set(pre->arrival_hour,pre->arrival_minute,
						&pre->departure_hour,&pre->departure_minute);
				
				pre->ticket_num = TICKET_NUM;
				
				cru ++;//指向下一个车站	
			}
			pre->next = NULL;//最后一个车站指向NULL
		}
		else
		{
			printf("\n车次添加失败..\n");
			sleep(1);
			return head_train;
		}
	}
	else
	{
		printf("\n车次添加失败..\n");
		sleep(1);
	}
	return head_train;

}
//管理员车次修改
void train_change()
{
	printf("\n车次信息修改\n");
	sleep(1);
}

/*************************************************
*func:train_del
*describtion:删除车次
*************************************************/
PTra train_del(PTra head_train)
{                      
	char train_name[TRA_NUM];
	PTra Train = head_train,p = NULL,q = NULL;
	
	system("clear");
	printf("\n\t\t\t\t***************车   次   删   除******************\n\n");
	if(Train == NULL)
	{
		printf("\n当前无车次，无法删除..\n");
		sleep(1);
		return head_train;
	}
	printf("\n请输入想要删除的列车车次:");
	scanf("%s",train_name);
	while(getchar() != '\n');

	if(!strcmp(Train->train_num,train_name))
	{
		p = Train;
		Train = Train->next;
		//printf("*****************");
		//sleep(5);
		//station_del(p->pst);
		station_del(p);
		//printf("*****************\n");<F2>
		//sleep(5);
		//free(p);
		p = NULL;
		head_train = Train;
		printf("\n%s列车删除成功\n",train_name);
		sleep(1);
		return head_train;
	}
	else
	{
		q = Train;
		while(q->next != NULL)
		{
			if(!strcmp(q->next->train_num,train_name))
			{
				p = q->next;
				q->next = p->next;
				station_del(p);
				//free(p);
				p = NULL;
				//*head_train = Train;
				printf("\n%s列车删除成功\n",train_name);
				sleep(1);
				return head_train;
			}
			q = q->next;
		}
		printf("\n删除车次失败，未查找到该车次..\n");
		sleep(1);
		return head_train;
	}
}


//管理员查看用户
void user_look(const PUser head_user)
{
	//printf("用户信息查看\n");
	//sleep(1);
	int i = 0;
	PUser User = head_user;
	PU_i_t User_tr;
	
	system("clear");
	printf("\n\t\t\t\t***************用   户   查   看******************\n\n");

	if(head_user == NULL)
	{
		printf("\n当前无用户信息\n");
		sleep(1);
		return;
	}
	/*显示所有用户名*/
	char name[NAME_SIZE];
	printf("\n所有用户:\n\n");
	while(User != NULL)
	{
		i++;
		printf("%s\t",User->name);
		if(i%5 == 0)
			putchar('\n');
		User = User->next;
	}
	/*查看某一个用户的信息*/
	while(1)
	{
		printf("\n\n请输入想要查看的用户:\n");
		scanf("%s",name);
		while(getchar() != '\n');
		User = user_search(head_user,name);
		if(User == NULL)
		{
			printf("\n未找到该用户,检查是否输入有误..\n");
		}
		else
			break;
	}
	system("clear");

	user_tic_sort_date(User);
	printf("\n%s的订票信息为:\n\n",User->name);
	printf("乘车日期\t车次\t出发站\t\t到站\t出发时间\t旅程时间\n");
	User_tr = User->pu_i_t;
	/*查看用户订票信息*/
	//i = 0;
	while(User_tr != NULL)
	{
	//	if(i == 0)
			printf("%d-%2d-%2d\t%s\t%s\t\t%s\t%2d:%2d\t\t%2d小时%2d分\n",User_tr->date.year,User_tr->date.month,
					User_tr->date.day,User_tr->train_num,
					User_tr->start_name,User_tr->end_name,
					User_tr->depart_hour,User_tr->depart_minute,
					User_tr->run_hour,User_tr->run_minute);
#if 0
		else
		printf("\t%d-%d-%d\t%s\t%s\t\t%s\t%2d:%2d\t\t%2d小时%2d分\n",User_tr->date.year,
					User_tr->date.month,User_tr->date.day,User_tr->train_num,
					User_tr->start_name,User_tr->end_name,
					User_tr->depart_hour,User_tr->depart_minute,
					User_tr->run_hour,User_tr->run_minute);

		i++;
#endif
		User_tr = User_tr->next;
	}
#if 0
	while(User != NULL)
	{
		i = 0;
		printf("%d\t%s\t\t",User->ID,User->name);
		User_tr = User->pu_i_t;
		if(User_tr == NULL)
			putchar('\n');
		while(User_tr != NULL)
		{
			if(i == 0)
				printf("%s\t%s\t%s\t%s\t%d\t%d\n",User_tr->ppra->train_num,
					User_tr->start_psta->sta_name,User_tr->end_psta->sta_name,
				User_tr->date,User_tr->left_time,User_tr->arrival_time);
			else

				printf("\t\t\t%s\t%s\t%s\t%s\t%d\t%d\n",User_tr->ppra->train_num,
					User_tr->start_psta->sta_name,User_tr->end_psta->sta_name,
				User_tr->date,User_tr->left_time,User_tr->arrival_time);
			i++;
			User_tr = User_tr->next;
		}
		User = User->next;
	}
#endif
	//printf("\n\n请输入任意键继续\n");
	while(getchar() != '\n');
}

//管理员修改用户
void user_change()
{
	printf("\n用户信息修改\n");
	sleep(1);
}

/****************************************************
*func:user_del
*describtion:删除用户
*****************************************************/
PUser user_del(PUser head_user,PTra train_head)
{
	char user_name[TRA_NUM];
	char ch;
	PUser User = head_user,p = NULL,q = NULL;

	system("clear");
	printf("\n\t\t\t\t***************用   户   删   除******************\n\n");
	if(User == NULL)
	{
		printf("\n当前无用户,无法删除\n");
		sleep(1);
		return head_user;
	}
	printf("\n请输入想要删除的用户:\n");
	scanf("%s",user_name);
	while(getchar() != '\n');
#if 0
	if(!strcmp(User->name,user_name))
	{
		if(User->pu_i_t != NULL)
		{
			printf("当前用户已有订票，是否要继续删除用户(y or n)?");
			ch = getchar();
			while(getchar() != '\n');
			if(ch == 'y')
			{
				user_ticket_refund(User,train_head);
				head_user = user_tr_del(head_user,User);
				return head_user;
			}
			else
			{
				return head_user;
			
			}
		}
		else
		{
			head_user = user_tr_del(head_user,User);
			printf("\n%s用户删除成功\n",user_name);
			sleep(1);
			return head_user;
		}
	}
	else
	{
#endif
		q = User;
		while(q != NULL)
		{
			if(!strcmp(q->name,user_name))
			{
				if(q->pu_i_t != NULL)
				{
					printf("当前用户已有订票，是否要继续删除用户(y or n)?");
					ch = getchar();
					while(getchar() != '\n');
					if(ch == 'y')
					{
						user_ticket_refund(q,train_head);
						head_user = user_tr_del(head_user,q);
						return head_user;
					}
					else
					{
						return head_user;

					}
				}
				else
				{
					head_user = user_tr_del(head_user,q);
					printf("\n%s用户删除成功\n",user_name);
					sleep(1);
					return head_user;
				}
			}
			q = q->next;
		}
		printf("\n删除用户失败，未查找到该用户..\n");
		sleep(1);
		return head_user;
//	}
}



/********************************************************************
*func:departure_time_set
*describtion:根据到站时间计算发车时间(发车时间到站时间晚(TIME_LENTH))
*********************************************************************/
void departure_time_set(int hour,int minute,int *l_hour,int * l_minute)
{
	if(minute + TIME_LENTH >= MINUTE)
	{
		*l_minute = minute + TIME_LENTH - MINUTE;
	        if(hour + 1 >= 24)
			*l_hour = hour + 1 - HOUR;
		else
			*l_hour = hour + 1;
	}
	else
	{
		*l_minute = minute + TIME_LENTH;
		*l_hour = hour;
	}
}

/*****************************************************
*func:train_num_check
*desvribtion:检查输入的车次是否已添加
*已添加则返回0 没有添加则返回1   
******************************************************/
int train_name_check(PTra head_train,char *name)
{
	PTra p = head_train;
	if(head_train == NULL)
	{
		return 1;
	}
	while(p != NULL)
	{
		if(!strcmp(p->train_num,name))
			return 0;
		p = p->next;
	}
	return 1;
}

/********************************
*func:station_del
*describtion:删除车次的车站
*********************************/
void station_del(PTra Train)
{
	PSta Sta = Train->pst;
	free(Train);
	Train = NULL;
	//printf("****************\n");
	//sleep(1);

	if(Sta == NULL)
		return;
	free(Sta);
	Sta = NULL;
	/*while(p != NULL)
	{
		printf("Sta = %p\n",Sta);
		printf("p = %p\n",p);
		sleep(1);
		Sta = Sta->next;
		printf("Sta = %p\n",Sta);
		free(p);
		printf("****************\n");
		sleep(2);
		p = Sta;
	}*/

}

/*************************************************
*func:user_del
*describtion:删除用户
**************************************************/
PUser user_tr_del(PUser head_user,PUser User)
{
	PUser p = head_user;
	if(head_user == User)
	{
		head_user = head_user->next;
		free(User);
		User = NULL;
		return head_user;
	}
	else
	{
	//	if()
		while(p->next != User)
		{
		//	if(p->next == User)
		//	{
		//		p->next = User->next;
		//		free(User);
		//		User = NULL;
		//	}
			p = p->next;
		}
		p->next = User->next;
		free(User);
		return head_user;
	}
}  
 
/*****************************************************
*func:user_search
*describtion:根据用户名查找用户地
******************************************************/
PUser user_search(const PUser user_head,char *name)
{
	PUser User = user_head;
	if(User == NULL)
		return NULL;
	while(User != NULL)
	{
		if(!strcmp(User->name,name))
			return User;
		User = User->next;
	}
	return NULL;

}

/*************************火车票退订*************************/
void user_ticket_refund(PUser head,PTra train_head)
{
	PU_i_t p = head->pu_i_t,q = NULL;
	PTra pt = NULL;
	PSta pta = NULL;
	
	/*管理员强制退票*/
	while(p != NULL)
	{
		
		pt = train_address_search(train_head,p->train_num);
		if(pt != NULL)
		{
			pta = pt->pst;
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
		}
		p = p->next;
	}
	
	/*删除用户和车票*/
	p = head->pu_i_t;
	//free(head);
	//head = NULL;
	while(p != NULL)
	{
		q = p;
		p = p->next; 
		free(q);
		q = NULL;
	}
	return;
}
