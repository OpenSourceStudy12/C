#include "user.h"
#include "admin.h"
#include "main.h"
int user()//用户的主控函数
{
	int i = 0;
	//用户登录前，初始化用户链表
	PUSE user_head = init_user();
	PUSE now_user = NULL;//用于保存登录用户的节点地址
	if(NULL==user_head)//检查是否有用户存在
	{
		printf("尚无任何用户信息，请先注册。\n");
		system("sleep 1");
		return 0;
	}
	int user_log_flag = user_log(user_head,&now_user);
	while(1)//根据登陆检查的返回值判断下一步
	{
		i++;
		if(i>3)
		{
			printf("错误的次数过多，请稍后再试。\n");
			system("sleep 1");
			return -2;
		}
		if(-1==user_log_flag)
		{
			user_log_flag = user_log(user_head,&now_user);
		}
		else if(-2==user_log_flag)
		{
			return user_log_flag;
		}
		else break;	
	}
	int new_user_log_flag = new_user_log(user_head,now_user);//公用函数，节省代码长度
	if(0!=new_user_log_flag)
	{
		return new_user_log_flag;
	}
	return 0;
}

int user_log(PUSE user_head,PUSE *now_user)//用户登录函数
{
	int i = 0;
	char user_name[20];
	char user_passwd[10];
	printf("请输入用户名\n");
	scanf("%s",user_name);
	while(0!=strcmp(user_name,user_head->name))
	{
		if(NULL==user_head->next)
		{
			printf("你输入的用户不存在，请重试\n");
			return -1;
		}
		user_head = user_head->next;
	}
	*now_user = user_head;//保存当前用户的地址
	hide_password(user_passwd);
	while(0!=strcmp(user_passwd,user_head->passwd))
	{
		i++;
		if(i>3)
		{
			printf("错误的次数过多，请稍后再试。\n");
			system("sleep 1");
			return -2;
		}
		printf("你输入的密码错误，请重新输入。\n");
		hide_password(user_passwd);
	}
	return 0;
}

int user_menu()//用户登录界面
{
	system("clear");
	int user_flag = 0;
	printf("-------------------------------------------\n");
	printf("\n");
	printf("****************欢迎用户登录***************\n");
	printf("\t请选择：\n");
	printf("\t\t1  车次查询\n");
	printf("\t\t2  站站查询\n");
	printf("\t\t3  查看个人信息\n");
	printf("\t\t4  修改个人信息\n");
	printf("\t\t5  退票\n");
	printf("\t\t6  退出系统\n");
	printf("\n");
	printf("-------------------------------------------\n");
	scanf("%d",&user_flag);
	my_getchar();
	while(user_flag>6||user_flag<1)
	{
		printf("输入错误，请重试\n");
		scanf("%d",&user_flag);
		my_getchar();
	}
	return user_flag;
}

int search_train(PTRA train_head,PUSE user_head,PUSE now_user)//按车次查询
{
	PTRA p_train = train_head;
	int search_flag = search_the_train(train_head,&p_train);
	if(0!=search_flag)
	{
		return search_flag;
	}
	printf("你查找的车次信息为：\n始发站:");
	PSTA the_station = p_train->my_station;
	//PSTA check_station = p_train->my_station;
	while(NULL!=the_station)//打印出查找到车次的信息
	{
		printf("%s[%s]->",the_station->name,the_station->s_time);
		the_station = the_station->next;
	}
	if(p_train->tickets>0)
	{
		printf("\n本次列车尚有余票%d张\n",p_train->tickets);
		printf("\t是否预订本次列车车票(Y/N)？\n");
		char ch = my_getchar();
		if('Y'==ch||'y'==ch)
		{
			char start_station[20];
			char aim_station[20];
			printf("请输入出发站:\n");
			scanf("%s",start_station);
			my_getchar();
			printf("请输入目的站:\n");
			scanf("%s",aim_station);
			my_getchar();
			//判断是否有合适的车票,并订票
			book_ticket(now_user,p_train,start_station,aim_station,0);
		}
		else return 0;	
	}
	else
	{
		char start_station[20]="0";
		char aim_station[20]="0";
		wait_ticket(now_user,p_train,start_station,aim_station);
	}
	return 0;
}

int search_station(PTRA train_head,PUSE user_head,PUSE now_user)//站站查询
{
	int i = 1;
	PTRA real_train_head = train_head;//保存火车链表的头节点的地址
	char start_station[20];
	char aim_station[20];
	printf("请输入出发站:\n");
	scanf("%s",start_station);//录入出发站点
	my_getchar();
	printf("请输入目的站:\n");
	scanf("%s",aim_station);//录入出发站点
	my_getchar();	
	while(NULL!=train_head)
	{
		PSTA p_station = train_head->my_station;
		while(NULL!=p_station)
		{
			if(0==strcmp(start_station,p_station->name))
			{
				while(NULL!=p_station)
				{
					if(0==strcmp(aim_station,p_station->name))
					{
						printf("符合要求的第%d趟车为:",i);
						print_the_train(train_head);
						printf("\n");
						i++;
					}
					p_station = p_station->next;
				}
				if(NULL==p_station)
					break;
			}
			p_station = p_station->next;			
		}
		train_head = train_head->next;
	}
	if(NULL==train_head&&1==i)
	{
		printf("没有符合你要求的车次，请重试。");
		return 2;
	}
	else
	{
		printf("是否订票(Y/N)\n");
		char ch = my_getchar();
		if('y'==ch||'Y'==ch)
		{
			PTRA p_train = real_train_head;
			int search_flag = search_the_train(real_train_head,&p_train);
			if(p_train->tickets<=0)//如果当前车次没有余票则进入排队函数
			{
				int a = wait_ticket(now_user,p_train,start_station,aim_station);
				return a;
			}
			if(0!=search_flag)return search_flag;
			int book_flag = book_ticket(now_user,p_train,start_station,aim_station,0);
			if(0!=book_flag)return book_flag;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}

int new_user_log(PUSE user_head,PUSE now_user)//新用户注册函数
{
	//用户登录后，初始化火车票链表
	PTRA train_head = init_train();
	if(NULL==train_head)//检查初始化之后的火车链表是否存在
	{
		printf("尚无火车票信息，请与管理员联系。\n");
		system("sleep 1.5");
		return -1;
	}
	//检查是否有排队信息
	if(0<now_user->waiting_tickets)//如果用户有超过0个排队票数
	{
		//先找出排队票的车次
		//找出自己在该次火车的排队位置
		//再检查该车次是否有退票
		//如果有则提示是否订票
		//是则订票
		//否则提示是否继续排队
		//是则退出
		//否则退出排队
		PTIK the_ticket = now_user->my_ticket;
		while(NULL!=the_ticket)
		{	
			int flag1 = 1;
			PTIK p_the_ticket = the_ticket;//保存这张票的前一个节点的地址
 			if(1==the_ticket->flag)//当这张票是排队票时，同时
			{						//是第一个排队的则可以去预订已退车票
				PTRA p_train = train_head;
				while(NULL!=p_train)
				{
					if(NULL==p_train->my_waiter||0!=strcmp(now_user->name,p_train->my_waiter->name))
					{//当本用户和火车链表排队者第一个名字相同时则可预订已退车票
				/*		if(NULL==p_train->next)
						{
							//i++;
							printf("你排队的车次不存在。\n\t\
								系统错误，请与管理员联系。");
							break;
						}*/
						p_train = p_train->next;
					}
					else if(p_train->cancel_ticket>0)
					{
						printf("你排队的车次:%s已有余票，是否预订(Y/N)\n",the_ticket->train_name);
						char ch = my_getchar();
						if('y'==ch||'Y'==ch)
						{
							p_train->cancel_ticket--;//退票数减1
							the_ticket->flag = 0;//将排队票改为正常票
							now_user->waiting_tickets--;//该用户的排队票数减少1
							now_user->tickets++;//正常票加1
							PWAI p_waiter = p_train->my_waiter;//保存要删除节点的地址
							free(p_waiter);//释放空间
							p_train->waiters--;//该火车的排队人数减少
							p_train->my_waiter = p_train->my_waiter->next;
							p_waiter = p_train->my_waiter;
							while(NULL!=p_waiter)
							{
								p_waiter->count_flag--;
								p_waiter = p_waiter->next;
							}
							printf("订票成功,订票信息可在个人信息中查询\n\t确定？");
							my_getchar();
						}
						else
						{
							printf("是否继续排队(Y/N)?\n");
							char ch = my_getchar();
							if('y'==ch||'Y'==ch)
							{
								break;
							}
							else
							{
								flag1 = 0;
								p_train->waiters--;//该火车的排队人数减少
								if(p_train->waiters<p_train->cancel_ticket)
								{//当退票数量大于排队人数时,所退票直接转为正常票
									p_train->cancel_ticket--;//退票数减1							
									p_train->tickets++;//将已票改为正常票
								}
								//先删除火车链表上的排队者，然后删除用户的排队票
								now_user->waiting_tickets--;//该用户的排队票数减少1
								PWAI p_waiter = p_train->my_waiter;//保存要删除节点的地址
								free(p_waiter);//释放空间
								p_train->my_waiter = p_train->my_waiter->next;
								p_waiter = p_train->my_waiter;
								while(NULL!=p_waiter)
								{
									p_waiter->count_flag--;
									p_waiter = p_waiter->next;
								}
								//删除用户的排队票
								if(p_the_ticket==now_user->my_ticket)
								{//如果取消的票为第一张票
									the_ticket = now_user->my_ticket->next;
									now_user->my_ticket = p_the_ticket->next;				
								}
								else
								{//如果取消的票为其他票
									p_the_ticket->next = the_ticket->next;
								}
								free(the_ticket);//释放该张票的空间
								break;
							}
						}
					}
					else// if(0==p_train->cancel_ticket)//如果没有退票则返回上一级循环
					{
						break;
					}
				}
			}
			if(flag1)
			the_ticket = the_ticket->next;
		}
	}
	int user_flag = 0;//返回用户选择项user_flag
	while(1)
	{
		switch(user_flag)
		{
			case 0:user_flag = user_menu();break;//查询正常完成后自动跳转的自身主菜单
			case 1:user_flag = search_train(train_head,user_head,now_user);break;//车次查询
			case 2:user_flag = search_station(train_head,user_head,now_user);break;//站站查询
			case 3:user_flag = print_the_user(now_user);printf("\t确定?\n");my_getchar();break;//查看个人信息
			case 4:user_flag = personal_change(user_head,now_user);break;//修改个人信息
			case 5:user_flag = cancel_ticket(now_user,train_head);break;//退票
			case 6:save_user(user_head);save_train(train_head);return -2;//退出系统
			case -2:user_flag = 6;break;
			case -1:user_flag = 0;break;
			default:printf("return error\n");return -2;//提示错误信息
		}
	}
	return 0;
}

int personal_change(PUSE user_head,PUSE p_user)//修改用户信息
{
	while(1)
	{
		system("clear");
		int change_user_flag;
		printf("-------------------------------------------\n");
		printf("\n\t请选择要修改的信息：\n");
		printf("\t\t1  修改用户名\n");
		printf("\t\t2  修改用户密码\n");
		printf("\t\t3  返回上一级\n");
		printf("\t\t4  退出系统\n");
		printf("\n");
		printf("-------------------------------------------\n");
		scanf("%d",&change_user_flag);
		my_getchar();
		while(change_user_flag>4||change_user_flag<1)
		{
			printf("输入错误，请重试\n");
			scanf("%d",&change_user_flag);
			my_getchar();
		}
		char new_passwd[10];
		char new_name[20];
		switch(change_user_flag)
		{
			case 1:
					printf("请输入新用户名\n");
					scanf("%s",new_name);
					my_getchar();
					int check_flag = check_user_rename(new_name,user_head);
					if(check_flag)
					{
						change_user_flag = 1;break;
					}
					else
					{
						strcpy(p_user->name,new_name);
					}	
					printf("用户名修改成功\n\t确定？");
					my_getchar();
					return 0;
			case 2:					
					get_new_passwd(new_passwd);
					strcpy(p_user->passwd,new_passwd);//将新密码赋值
					printf("用户密码修改成功\n\t确定？");
					my_getchar();
					return 0;
			case 3:return 0;//返回上一级
			case 4:return -2;//退出系统
			default:printf("return error\n");return -2;
		}
	}
}

int cancel_ticket(PUSE now_user,PTRA train_head)//退票
{
	if(0==now_user->tickets)
	{
		printf("未曾订票，请先预定车票\n");
		system("sleep 1.5");
		return 0;
	}
	PTIK the_ticket = now_user->my_ticket;
	printf("订票信息如下:\n");
	while(NULL!=the_ticket)
	{
		if(0==the_ticket->flag)
		printf("车次:%s 出发站:%s[%s]-->目的站:%s[%s] 票价:[%d]元\n",\
		the_ticket->train_name,the_ticket->start_station,\
		the_ticket->start_time,the_ticket->aim_station,\
		the_ticket->aim_time,the_ticket->ticket_price);
		the_ticket = the_ticket->next;//移动指针指向下一张票
	}
	printf("是否退票(Y/N)？");
	char ch = my_getchar();
	if('y'==ch||'Y'==ch)
	{
		char the_train[10];
		while(1)
		{	
			int i = 0;
			printf("请输入要退票的车次。\n");
			scanf("%s",the_train);//录入输入的车次
			my_getchar();
			PTIK the_ticket = now_user->my_ticket;
			PTIK pri_the_ticket = NULL;
			while(NULL!=the_ticket)
			{
				
				if(0==strcmp(the_ticket->train_name,the_train))
				{
					i++;
					break;
				}	
				pri_the_ticket = the_ticket;//保存前一个节点的地址
				the_ticket = the_ticket->next;
			}
			if(1==i)
			{	//查找输入的车次所在的节点
				while(NULL!=train_head)
				{
					if(0==strcmp(the_train,train_head->name))
					{
						if(train_head->waiters>train_head->cancel_ticket)//如果该趟列车排队者数大于退票数则将退票计入退票数中
						train_head->cancel_ticket++;//火车余票自增1
						else//如果该趟列车排队者数小于退票数则将退票计入余票数中
							train_head->tickets++;
						//删除用户的订票信息
						now_user->tickets--;//当前用户的正常票数减1
						if(now_user->my_ticket==the_ticket)//当删除的车票信息是第一张票时
						{	
							now_user->my_ticket = the_ticket->next;
						}
						else
						{
							pri_the_ticket->next = the_ticket->next;
						}
						free(the_ticket);
						printf("退票成功，按回车键返回。\n");
						my_getchar();
						return 0;
					}
					train_head = train_head->next;
				}
				if(NULL==train_head)
				{
					printf("系统错误，请与管理员联系。\n");
					return 6;
				}
			}
		}
	}
	return 0;
}

int book_ticket(PUSE now_user,PTRA p_train,char start_station[],char aim_station[],int book_way)//订票
{
	PSTA order_station = p_train->my_station;
	while(NULL!=order_station)
	{
		if(0!=strcmp(start_station,order_station->name))
		{
			order_station = order_station->next;
		}
		else
		{
			PSTA price_start_station = order_station;
			while(NULL!=order_station)
			{
				if(0!=strcmp(aim_station,order_station->name))
				{
					order_station = order_station->next;
				}
				else
				{
					char ch1;
					if(0==book_way)
					{
						printf("确定订票(Y/N)？\n");
						ch1 = my_getchar();
					}
					else
						ch1 = 'y';
					if('y'==ch1||'Y'==ch1)
					{
						//更改该车次的余票信息
						if(0==book_way)//如果是正常订票则余票减1
						p_train->tickets--;//余票减一
						//保存订票信息到用户信息中
						PTIK new_ticket = (PTIK)my_malloc(sizeof(TIK));
						new_ticket->next = NULL;
						if(NULL==now_user->my_ticket)//当该用户没订过票时
						{
							now_user->my_ticket = new_ticket;//连接新的订票信息节点
						}
						else
						{
							PTIK p_ticket = now_user->my_ticket;
							while(NULL!=p_ticket->next)
							{
								p_ticket = p_ticket->next;
							}
							p_ticket->next = new_ticket;
						}
						strcpy(new_ticket->train_name,p_train->name);
						strcpy(new_ticket->start_station,start_station);
						strcpy(new_ticket->start_time,price_start_station->s_time);
						strcpy(new_ticket->aim_station,aim_station);
						strcpy(new_ticket->aim_time,order_station->s_time);
						new_ticket->ticket_price = order_station->price - price_start_station->price;
						if(0==book_way)
						{
							printf("你的订票信息如下，也可到个人信息中查询。\n");
							printf("车次:[%s] 出发站:%s[%s]-->目的站:%s[%s] \n票价:[%d] 元\n",\
							 new_ticket->train_name,new_ticket->start_station,new_ticket->start_time,\
							 new_ticket->aim_station,new_ticket->aim_time,new_ticket->ticket_price);
							now_user->tickets++;//正常票数加1
							printf("\t确定？\n");
							my_getchar();
						}
						else//标记该票为排队票
						{
							new_ticket->flag = 1;//标记该票为排队票
							now_user->waiting_tickets++;//排队的票数加1
						}
						//save_train(train_head);
						//save_user(user_head);
						return 0;
					}
					else return -1;
				}
			}
		}
	}
	if(NULL==order_station)
	{
		printf("你输入的信息有误，请重试\n");
		system("sleep 1.5");
		return 1;
	}
	return 0;
}

int search_the_train(PTRA train_head,PTRA *pp_train)//查找指定车次的火车，用*pp_train保存其值
{
	PTRA p_train = train_head;//定义一个指向火车链表表头的指针
	static int i = 0;
	char train_name[10];
	printf("请输入车次\n");
	scanf("%s",train_name);
	my_getchar();
	while(0!=strcmp(train_name,p_train->name))
	{
		if(i>2)
		{
			printf("错误的次数过多，请稍后再试。\n");
			system("sleep 1.5");
			i = 0;
			return -1;
		}
		if(NULL==p_train->next)
		{
			i++;
			printf("你要输入的车次不存在,");
			return 1;
		}
		p_train = p_train->next;
	}
	*pp_train = p_train;//将查找到的值赋值给要用到的变量
	return 0;
}

int wait_ticket(PUSE now_user,PTRA p_train,char start_station[],char aim_station[])//排队函数
{
	printf("本次列车已无余票，是否排队等候(Y/N)\n");
		char ch = my_getchar();
		if('Y'==ch||'y'==ch)
		{
			if(0==strcmp(start_station,aim_station))
			{
				printf("请输入出发站:\n");
				scanf("%s",start_station);
				my_getchar();
				printf("请输入目的站:\n");
				scanf("%s",aim_station);
				my_getchar();
			}
			int book_flag = book_ticket(now_user,p_train,start_station,aim_station,1);
			if(0!=book_flag)return book_flag;//如果订票函数没有正常退出则终止本函数并返回其返回值
			p_train->waiters++;//排队人数加1
			PWAI p_waiter = p_train->my_waiter;
			now_user->waiting_tickets++;//当前票中排队票的张数加1
			PWAI new_waiter = (PWAI)my_malloc(sizeof(WAI));
			new_waiter->next = NULL;
			strcpy(new_waiter->name,now_user->name);//赋值新排队者的名字
			new_waiter->count_flag = p_train->waiters;//新排队者的排队位置等于排队者的个数
			if(NULL==p_train->my_waiter)
			{
				p_train->my_waiter = new_waiter;
			}
			else
			{
				while(NULL!=p_waiter->next)
				{
					p_waiter = p_waiter->next;
				}
				p_waiter->next = new_waiter;
			}
			printf("信息已经录入，如有余票，下次登录通知您\n");
		}
		else
		{
			printf("谢谢使用。\n");
			return 6;
		}
		system("sleep 1.5");
		return 0;
}