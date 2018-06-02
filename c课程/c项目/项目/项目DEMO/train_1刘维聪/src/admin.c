#include "admin.h"
#include "main.h"
#include "common.h"
#include "user.h"
int admin()//管理员主控函数
{
	//先初始化管理员链表文件
	FILE *fp_admin = fopen("admin","ab+");//以附加的方式打开保存admin信息的文件
	PADM admin_head = (PADM)my_malloc(sizeof(ADM));//分配一段内存，供保存admin文件中的信息
	size_t size_admin = fread(admin_head,sizeof(ADM),1,fp_admin);//将已打开文件中的内容读到分配的内存中??从文件中读内容用哪个函数？
	if(0==size_admin)//管理员第一次登陆时，提醒修改密码
	{
		printf("管理员密码为初始密码，为了系统的安全建议及早修改密码\n");
		strcpy(admin_head->name,"admin");//先定义admin的密码为admin，待后段完善
		strcpy(admin_head->passwd,"admin");//先定义admin的密码为admin，待后段完善
		fwrite(admin_head,sizeof(ADM),1,fp_admin);//初始化管理员的密码并保存到admin文件中
	}
	fclose(fp_admin);//要记得关闭打开的文件
	//管理员登陆检查
	int admin_log_flag=admin_log(admin_head);
	if(-2==admin_log_flag)
	{
		return -2;
	}
	//登录成功后初始化用户和火车票链表
	PTRA train_head = init_train();
	//初始化火车票链表后再初始化用户链表
	PUSE user_head = init_user();

	int admin_choice_flag = 0;
	while(1)
	{	
		switch(admin_choice_flag)
		{
			case 0:admin_choice_flag = admin_menu();break;//子菜单正常执行完毕后退出则返回本菜单
			case 1:admin_choice_flag = admin_manage_train_choice(&train_head);break;//子菜单：管理车次信息
			case 2:admin_choice_flag = admin_manage_user_choice(&train_head,&user_head);break;//子菜单：管理用户信息
			case 3:admin_choice_flag = change_admin(admin_head);break;//管理员信息修改
			case 4:save_train(train_head);save_user(user_head);return -2;//退出程序：退出前保存用户和管理员信息
			case 5:save_train(train_head);save_user(user_head);return 0;
			//返回-2表示在子菜单中直接退出程序
			case -2:admin_choice_flag = 4;break;
			default:printf("return error\n");return -2;//说明子菜单返回有误	
		}
	}
	return 0;
}

PTRA init_train()//初始化火车链表，先读火车节点的信息，然后读该车次的所以站点信息，然后读该车次所有排队者的信息
{
	PTRA train_head = NULL;//指向火车链表头结点的指针
	PTRA p_train = NULL;//辅助火车的每一个节点互联
	int i = 0;
	FILE *fp_train = fopen("train","ab+");//先打开要读取的文件
	fseek(fp_train,0,SEEK_SET);//将文件指针移动到文件的起始位置
	while(1)//外循环移动指向车次的指针
	{
		PTRA n_train = (PTRA)my_malloc(sizeof(TRA));
		if(0==i)
		{
			size_t size_train = fread(n_train,sizeof(TRA),1,fp_train);//读文件
			if(1!=size_train)//表示无任何火车信息
			{
				free(n_train);//当无火车信息的时候，释放未使用的内存空间
				return train_head;
			}
			train_head = n_train;//保存火车链表头结点的地址
			p_train = n_train;//用于后面火车与火车相连
		}
		else
		{
			fread(n_train,sizeof(TRA),1,fp_train);//读文件
			p_train->next = n_train;//前一个节点的next指向本节点
			p_train = n_train;//辅助指针移动指向本节点
		}
		//读每一个站的信息
		int j = 0;
		PSTA pp_station = NULL;//辅助火车的每一个站互联
		while(j<p_train->count)//内循环移动指向车站的指针，读每一个站点的信息
		{
			PSTA n_station = (PSTA)my_malloc(sizeof(STA));//为保存站点分配内存空间
			fread(n_station,sizeof(STA),1,fp_train);//读取文件中每一趟火车的站点信息
			if(0==j)
			{
				n_train->my_station = n_station;//使车次指针指向站点节点
				pp_station = n_train->my_station;
			}
			else//站站相连
			{
				pp_station->next = n_station;
				pp_station = n_station;
			}
			n_station->next = NULL;//将每一个新读出的站点的NEXT指向为空
			j++;
		}
		//读每一个排队者的信息
		int k = 0;
		PWAI waiter_head = n_train->my_waiter;
		PWAI p_waiter = NULL;
		while(1)//读排队者的信息
		{
			if(NULL!=waiter_head)//判断有无排队者
			{
				PWAI new_waiter = (PWAI)my_malloc(sizeof(WAI));
				fread(new_waiter,sizeof(WAI),1,fp_train);
				if(0==k)
				{
					n_train->my_waiter = new_waiter;
				}
				else
				{
					p_waiter->next = new_waiter;
				}
				p_waiter = new_waiter;
				if(NULL==new_waiter->next)break;//当该趟火车的所以排队者信息读完，跳出本循环体
				new_waiter->next = NULL;
				k++;
			}
			else
			{
				break;
			}
		}
		if(NULL==n_train->next)break;//读到最后一趟火车跳出循环
		n_train->next = NULL;//每读一个节点都将其NEXT指向空
		i++;
	}
	fclose(fp_train);
	return train_head;
}

PUSE init_user()//初始用户链表，先读用户节点信息，再读用户已购票的信息
{
	int i = 0;
	PUSE p_user = NULL;//用于之后用户节点相互连接
	FILE *fp_user = fopen("user","ab+");//以附加的方式打开文件
	fseek(fp_user,0,SEEK_SET);//将文件指针移动到文件的起始位置
	PUSE user_head = NULL;//给用户链表头分配空间
	while(1)
	{
		PUSE new_user = (PUSE)my_malloc(sizeof(USE));//给用户信息分配空间
		size_t user_size = fread(new_user,sizeof(USE),1,fp_user);//读文件内容到内存中
		if(1!=user_size)
		{
			free(new_user);//文件为空的时候，释放未使用的内存
			return user_head;
		}
		//文件不为空时，将用户信息挨个读出，并且生成一个链表
		new_user->next = NULL;
		if(0==i)
		{
			user_head = new_user;//head指向第一个节点
		}
		else
		{
			p_user->next = new_user;		
		}
		p_user = new_user;
		//读已购车票的信息
		int j = 0;
		PTIK n_ticket = NULL;
		while(1)
		{
			if(NULL!=new_user->my_ticket)
			{
				PTIK new_ticket = (PTIK)my_malloc(sizeof(TIK));//为用户的已购票分配空间
				fread(new_ticket,sizeof(TIK),1,fp_user);//读购票信息
				if(j>0)
				{
					n_ticket->next = new_ticket;
					n_ticket = new_ticket;
				}
				else
				{	
					n_ticket = new_ticket;
					new_user->my_ticket = new_ticket;
				}
				if(NULL==new_ticket->next)break;//用户购票信息读完则退出本重循环
				new_ticket->next = NULL;//将每一张新读出来的车票信息的NEXT指向为空
				j++;
			}
			else
			{
				break;
			}			
		}
		i++;
	}
	fclose(fp_user);//关闭文件
	return user_head;
}

int admin_log(PADM admin_head)//管理员密码检查
{
	int i=0,j=0;
	char check_name[20];//分配一段空间用来保存输入的账号
	char check_passwd[10];//分配一段空间用来保存输入的密码
	printf("请输入账号\n");
	scanf("%s",check_name);//录入账号
	my_getchar();
	while(0!=strcmp(admin_head->name,check_name))//检查输入的账号
	{
		j++;
		if(j>3)
		{
			printf("警告！！！错误次数过多,请稍后再试。\n");
			return -2;
		}
		printf("你输入的账号错误，请重试\n");
		scanf("%s",check_name);
		my_getchar();
	}
	hide_password(check_passwd);//以不回显的方式录入密码
	while(0!=strcmp(check_passwd,admin_head->passwd))//检查输入的密码
	{
		i++;
		if(i>3)
		{
			printf("警告！！！密码错误的次数超过三次,请稍后再试。\n");
			return -2;
		}
		printf("密码错误,请重试\n");
		hide_password(check_passwd);
	}
	return 0;
}

int admin_menu()//管理员登录界面
{
	system("clear");
	int admin_flag=0;
	printf("-------------------------------------------\n");
	printf("\n");
	printf("****************欢迎管理员登录*************\n");
	printf("\t请选择：\n");
	printf("\t\t1  管理车次信息\n");
	printf("\t\t2  管理用户信息\n");
	printf("\t\t3  管理员信息修改\n");
	printf("\t\t4  退出系统\n");
	printf("\n");
	printf("-------------------------------------------\n");
	scanf("%d",&admin_flag);
	my_getchar();
	while(admin_flag>4||admin_flag<1)
	{
		printf("输入错误，请重试\n");
		scanf("%d",&admin_flag);
		my_getchar();
	}
	return admin_flag;
}

int admin_manage_train_choice(PTRA *train_head)//管理火车信息选择入口
{
	int admin_manage_train_flag = 0;
	while(1)
	{
		switch(admin_manage_train_flag)
		{
			case 0:admin_manage_train_flag = admin_manage_train_menu();break;//admin_manage_train_menu(train_head,user_head);break;//子菜单返回
			case 1:admin_manage_train_flag = add_train(train_head);break;
			case 2:admin_manage_train_flag = del_one_train(train_head);break;
			case 3:admin_manage_train_flag = print_train(*train_head);break;
			case 4:return 0;
			case 5:return 5;//注销登录
		}
	}
	return 0;
}

int admin_manage_train_menu()//管理火车信息选择菜单
{
	system("clear");
	int admin_manage_train_flag = 0;
	printf("-------------------------------------------\n");
	printf("\n");
	printf("*********欢迎进入车次信息管理菜单**********\n");
	printf("\t请选择：\n");
	printf("\t\t1  添加车次信息\n");
	printf("\t\t2  删除车次信息\n");
	printf("\t\t3  查看所有车次信息\n");
	printf("\t\t4  返回上一级\n");
	printf("\t\t5  注销登录\n");
	printf("\n");
	printf("-------------------------------------------\n");
	scanf("%d",&admin_manage_train_flag);
	my_getchar();
	while(admin_manage_train_flag>5||admin_manage_train_flag<1)
	{
		printf("输入错误，请重试\n");
		scanf("%d",&admin_manage_train_flag);
		my_getchar();
	}
	//int choice_flag = admin_manage_train_choice(admin_manage_train_flag,train_head,user_head);
	return admin_manage_train_flag;
}

int admin_manage_user_choice(PTRA *train_head,PUSE *user_head)//管理用户信息选择入口
{
	int admin_manage_user_flag = 0;
	while(1)
	{
		switch(admin_manage_user_flag)
		{
			case 0:admin_manage_user_flag = admin_manage_user_menu();break;//admin_manage_user_menu(train_head,user_head);break;//子菜单返回
			case 1:admin_manage_user_flag = print_user(*user_head);break;//查看所有用户信息
			case 2:admin_manage_user_flag = admin_del_user(*train_head,user_head);break;
			case 3:admin_manage_user_flag = change_user(user_head);break;//更改用户信息
			case 4:admin_manage_user_flag = admin_cancel_user_ticket(*train_head,*user_head);break;
			case 5:return 0;
			case 6:return 5;
		}
	}
	return 0;
}

int admin_manage_user_menu()//管理用户信息选择菜单
{
	system("clear");
	int admin_manage_user_flag = 0;
	printf("-------------------------------------------\n");
	printf("\n");
	printf("*********欢迎进入用户信息管理菜单**********\n");
	printf("\t请选择：\n");
	printf("\t\t1  查看所用户信息\n");
	printf("\t\t2  删除用户账号\n");
	printf("\t\t3  修改用户个人信息\n");
	printf("\t\t4  用户退票\n");
	printf("\t\t5  返回上一级\n");
	printf("\t\t6  注销登录\n");
	printf("\n");
	printf("-------------------------------------------\n");
	scanf("%d",&admin_manage_user_flag);
	my_getchar();
	while(admin_manage_user_flag>6||admin_manage_user_flag<1)
	{
		printf("输入错误，请重试\n");
		scanf("%d",&admin_manage_user_flag);
		my_getchar();
	}
	//int choice_flag = admin_manage_user_choice(admin_manage_user_flag,train_head,user_head);
	return admin_manage_user_flag;
}

int add_train(PTRA *train_head)//添加车次信息
{
	PTRA p_train = *train_head;//定义一个指针指向火车链表的表头
	PTRA new_train = (PTRA)my_malloc(sizeof(TRA));//定义新火车的节点，并分配内存
	if(NULL==p_train)//排除无火车票信息的可能
	{
		*train_head = p_train = new_train;//将新火车链接到火车链表上
		new_train->next=NULL;//新火车的后面没有别的车次
	}
	else
	{
		while(NULL!=p_train->next)//先将指针移动到车次链表的尾节点
		{
			p_train=p_train->next;
		}
		p_train->next=new_train;//将新火车链接到火车链表上
		new_train->next=NULL;//新火车的后面没有别的车次
	}
	new_train->tickets = TOTAL_TICKETS;//初始化每趟火车余票
	printf("请输入新车次号\n");
	scanf("%s",new_train->name);//定义新车次名,有时间可扩展检查不与之前的车次重名
	my_getchar();//取走回车符
	printf("请输入该车经过的总站点数\n");
	scanf("%d",&new_train->count);//录入该火车经过站点的总数
	my_getchar();
	while(new_train->count<2||new_train->count>50)
	{
		printf("输入错误，请重试\n");
		scanf("%d",&new_train->count);//录入该火车经过站点的总数
		my_getchar();
	}
	int i;
	PSTA p_station=NULL;//定义一个指向车站的指针，用于连接各个站点
	for(i=1;i<=new_train->count;i++)//录入所有站点信息
	{
		PSTA new_station = (PSTA)my_malloc(sizeof(STA));
		if(1==i)
		{
			new_train->my_station=new_station;//连接火车和站点构成半十字链表
		}
		else
		{
			p_station->next=new_station;//连接前后两个站点

		}
		p_station=new_station;//结合上一句
		new_station->next=NULL;//防止野指针
		new_station->price = (i-1)*PRICE;//从起始站到本站的价格
		printf("请输入第%d站名\n",i);
		scanf("%s",new_station->name);
		my_getchar();
		printf("请输入路过%s站的时间\n",new_station->name);
		scanf("%s",new_station->s_time);
		my_getchar();
	}
	PSTA pp_station=new_train->my_station;
	printf("新增的车次信息为:\n");
	for(i=0;i<new_train->count;i++)//输出新火车的所有站点信息
	{
		printf("%s站[%s]->",pp_station->name,pp_station->s_time);
		pp_station = pp_station->next;//指针从第一个站一直移动到最后一个站
	}
	printf("\n");
	printf("确认(y/n)?\n");//确认录入的信息是否正确
	char ch = my_getchar();
	while(1)
	{
		if(ch=='y'||ch=='Y')
		{
			return 0;
		}
		else//如果发现录入的信息错误询问是否重新录入
		{
			if(p_train==*train_head&&*train_head==new_train)*train_head=NULL;//如果相等说明是在定义第一个火车信息，如果不保存置火车头结点为空
			else p_train->next = NULL;
			del_the_train(new_train);
			free(new_train);//***删除新增的火车节点
			break;
		}
	}
	return 0;
}

void save_train(PTRA train_head)//保存已经添加的火车信息
{
	FILE *fp_train = fopen("train","wb+");//以附加的方式打开保存train信息的文件
	while(train_head!=NULL)
	{
		fwrite(train_head,sizeof(TRA),1,fp_train);//写入车次信息
		PSTA station_head = train_head->my_station;
		while(NULL!=station_head)//写入站点信息
		{
			size_t a=fwrite(station_head,sizeof(STA),1,fp_train);
			if(1==a)
			station_head = station_head->next;
		}
		PWAI waiter_head = train_head->my_waiter;
		while(NULL!=waiter_head)//写入排队者信息
		{
			size_t a=fwrite(waiter_head,sizeof(WAI),1,fp_train);
			if(1==a)
			waiter_head = waiter_head->next;
		}
		train_head = train_head->next;
	}
	fclose(fp_train);//要记得关闭打开的文件
}

int del_one_train(PTRA *train_head)//删除火车车次信息
{
	PTRA train_hhead = *train_head;//保存头结点的地址
	if(NULL==train_hhead)
	{
		printf("无任何车次信息\n");
		system("sleep 1.5");
		return 0;
	}
	char name[10];
	printf("请输入要删除的车次\n");
	scanf("%s",name);
	my_getchar();
	PTRA p_train = NULL;
	int i = 0;

	while(0!=strcmp(name,train_hhead->name))//查找要删除的车次
	{
		i++;
		if(NULL==train_hhead->next)
		{
			printf("你输入的车次不存在\n");
			system("sleep 1");
			return 0;
		}
		p_train = train_hhead;//保存前一个车次的地址
		train_hhead = train_hhead->next;
	}

	
	if(del_the_train(train_hhead))//删除指定的车次信息
	{
		return 0;
	}
	if(NULL==p_train)
	{
		*train_head = (*train_head)->next;
	}
	else 
	{
		free(p_train->next);	
		p_train->next = train_hhead;	
	}
	if(0==i)//i为0说明要删除的火车是第一节点上的
	{
		*train_head = train_hhead->next;//在车次节点删除前，先将其前后两个节点相连
	}
	else
	{
		p_train->next = train_hhead->next;//适用于不是删除非第一个节点的情况
	}
	//free(train_hhead);//删除该火车的站点信息后再删除该火车
	printf("车次信息删除成功\n");
	system("sleep 1.5");
	save_train(*train_head);
	return 0;
}

int del_the_train(PTRA the_train)//删除本次列车的所有信息
{
	//删除指定车次的所有站点信息
	if(the_train->tickets<TOTAL_TICKETS)
	{
		printf("尚有用户已预订此次列车的车票，请重试。\n");
		system("sleep 1.5");
		return 1;
	}
	PSTA p_station = the_train->my_station;//每次移动前，将指针指向第一个站
	the_train->my_station = NULL;
	PSTA pp_station = NULL;//用于后面保存当前节点的地址
	while(NULL!=p_station)//
	{
		pp_station = p_station->next;//保存当前节点的next
		free(p_station);
		p_station = pp_station;//将指针指向next
	}	
	//删除指定车次的排队者信息
	//************************删除一串链表的典型办法************
	PWAI p_waiter = the_train->my_waiter;//每次移动前，将指针指向第一个排队者
	the_train->my_waiter = NULL;
	PWAI pp_waiter = NULL;//用于后面保存前一个节点的地址
	while(NULL!=p_waiter)
	{
		pp_waiter = p_waiter->next;
		free(p_waiter);
		p_waiter = pp_waiter;
	}
	return 0;
}

int print_train(PTRA train_head)//打印出所有火车的信息
{
	if(NULL==train_head)
		printf("尚无任何火车票信息\n");
	while(train_head!=NULL)
	{
		print_the_train(train_head);
		train_head = train_head->next;
	}
	printf("确定?\n");
	getchar();
	return 0;
}

int print_user(PUSE user_head)//打印所有用户的信息
{
	if(NULL==user_head)
		printf("尚无任何用户信息。\n");
	while(NULL!=user_head)
	{
		print_the_user(user_head);
		user_head = user_head->next;
	}
	printf("确定？\n");
	my_getchar();
	return 0;
}

int change_admin(PADM admin_head)//修改管理员的用户名和密码
{
	int i=0;
	char check_passwd[10];
	char new_name[20];
	char new_passwd[10];
	hide_password(check_passwd);//录入密码
	while(0!=strcmp(check_passwd,admin_head->passwd))
	{
		i++;
		if(i>3)
		{
			printf("错误次数过多，请稍候再试。\n");
			return 0;
		}
		printf("密码错误,请重试。\n");
		scanf("%s",check_passwd);//录入密码
		my_getchar();
	}
	printf("请输入新用户名，不超过19个字符\n");
	scanf("%s",new_name);
	my_getchar();
	get_new_passwd(new_passwd);//两次输入相同的密码，获取新密码
	strcpy(admin_head->name,new_name);
	strcpy(admin_head->passwd,new_passwd);
	FILE *fp_admin = fopen("admin","wb+");//以附加的方式打开保存admin信息的文件
	fwrite(admin_head,sizeof(ADM),1,fp_admin);//将新密码写入文件中
	fclose(fp_admin);//要记得关闭打开的文件
	printf("新密码设置成功，下次登录请使用新密码登录。\n");
	system("sleep 1.5");
	return 0;
}

int add_user()//新用户注册
{
	int i = 0;
	char new_passwd[10];
	PUSE user_head = init_user();
	PUSE p_user = user_head;
	if(NULL!=p_user)
	{
		while(NULL!=p_user->next)
		{
			p_user = p_user->next;
		}
	}
	PUSE new_user = (PUSE)my_malloc(sizeof(USE));
	while(1)
	{
		printf("请输入新用户名，不超过19个字符\n");
		scanf("%s",new_user->name);
		my_getchar();
		int rename_flag = check_user_rename(new_user->name,user_head);//避免重名
		for(i=0;rename_flag;i++)
		{
			if(i>2)
			{
				printf("错误的次数过多，请稍候再试。\n");
				system("sleep 1.5");
				return 0;
			}
			printf("请输入新用户名，不超过19个字符\n");
			scanf("%s",new_user->name);
			my_getchar();
			rename_flag = check_user_rename(new_user->name,user_head);
		}
		printf("设置新密码\n");
		hide_password(new_passwd);
		printf("再输入一次\n");
		hide_password(new_user->passwd);
		if(0!=strcmp(new_passwd,new_user->passwd))
		{
			i++;
			if(i>2)
			{
				printf("错误的次数过多，请稍候再试。\n");
				free(new_user);
				system("sleep 1.5");
				return 0;
			}
			printf("两次输入的密码不一致，请重试。\n");
		}
		else
		{
			if(NULL!=p_user)
			{
				p_user->next = new_user;//将新用户添加到用户链表
			}
			else
			{
				user_head = new_user;//当前用户为第一个用户的情况				
			}
			save_user(user_head);//保存新用户信息到文件
			printf("新用户注册成功\n");
			printf("\t\t是否订票(Y/N)？\n");
			char ch = my_getchar();
			//进入用户登录后的界面
			if('Y'==ch||'y'==ch)
			{
				return new_user_log(user_head,new_user);
			}
			else
				return 0;
		}
	}
}

int change_user(PUSE *user_head)//修改用户的信息
{
	if(NULL==*user_head)
	{
		printf("目前无用户信息，是否添加(Y/N)？\n");
		char ch = my_getchar();
		if(ch=='Y'||ch=='y')
		{
			PUSE new_user = (PUSE)my_malloc(sizeof(USE));
			printf("请输入新用户名\n");
			scanf("%s",new_user->name);
			my_getchar();
			printf("请设定新用户的密码\n");
			scanf("%s",new_user->passwd);
			my_getchar();
			//保存新用户信息
			FILE *fp_user = fopen("user","wb+");
			fwrite(new_user,sizeof(USE),1,fp_user);
			fclose(fp_user);
			printf("新用户信息已成功录入。\n确认？");
			my_getchar();
			*user_head = new_user;//
		}
		else
			return 0;
	}
	else
	{
		PUSE p_user = *user_head;
		printf("请输入要修改的用户名\n");
		char user_name[20];
		scanf("%s",user_name);
		my_getchar();
		while(0!=strcmp(user_name,p_user->name))
		{
			if(NULL==p_user->next)
			{
				printf("你输入的用户不存在，请重新输入。\n");
				system("sleep 1.5");
				return 0;
			}
			p_user = p_user->next;
		}
		return personal_change(*user_head,p_user);//直接调修改用户信息的函数
	}
	return 0;
}

void save_user(PUSE user_head)//保存用户信息到文件
{
	FILE *fp_user = fopen("user","wb+");
	while(NULL!=user_head)
	{
		fwrite(user_head,sizeof(USE),1,fp_user);
		PTIK the_ticket = user_head->my_ticket;
		while(NULL!=the_ticket)//save the ticket data of users
		{	
			fwrite(the_ticket,sizeof(TIK),1,fp_user);
			the_ticket = the_ticket->next;
		}
		user_head = user_head->next;
	}
	fclose(fp_user);
}

char my_getchar(void)//自定义getchar
{
	char ch=getchar();
	char value;
	while('\n'!=ch)
	{
		value = ch;
		ch = getchar();
	}
	return value;
}

void print_the_train(PTRA the_train)//打印一趟火车的站点信息
{
	printf("车次:%s 余票:[%d]张\n始发站:",the_train->name,the_train->tickets);
	PSTA station_head = the_train->my_station;
	while(station_head!=NULL)
	{
		printf("%s站[%s]->",station_head->name,station_head->s_time);
		station_head = station_head->next;
	}
	printf("\n");
}

int print_the_user(PUSE the_user)//打印单个用户的信息
{
		printf("姓名:%s 密码:%s",the_user->name,the_user->passwd);
		if(NULL!=the_user->my_ticket&&the_user->tickets>0)
		{

			PTIK the_ticket = the_user->my_ticket;
			printf("  订票信息如下:\n");
			while(NULL!=the_ticket)
			{
				if(0==the_ticket->flag)
				printf("车次:%s 出发站:%s[%s]-->目的站:%s[%s] 票价:[%d]元\n",\
				the_ticket->train_name,the_ticket->start_station,\
				the_ticket->start_time,the_ticket->aim_station,\
				the_ticket->aim_time,the_ticket->ticket_price);
				the_ticket = the_ticket->next;//移动指针指向下一张票
			}
		}
		else
			printf("\t该用户无订票信息\n");
		return 0;
}

int get_new_passwd(char new_passwd[])//获取新密码，确认两个密码一致
{
	int j = 0;
	char new_passwd1[10];
	char new_passwd2[10];
	printf("设置新密码\n\t");
	hide_password(new_passwd1);//获取新密码
	hide_password(new_passwd2);//获取新密码
	while(0!=strcmp(new_passwd1,new_passwd2))
	{
		j++;
		if(j>3)
		{
			printf("错误的次数过多，请稍候再试。\n");
			return -2;
		}
		printf("两次输入的密码不一致，请重试。\n");
		hide_password(new_passwd1);//获取新密码
		hide_password(new_passwd2);//获取新密码
	}
	strcpy(new_passwd,new_passwd2);//将新密码复制个调用函数
	return 0;
}

void *my_malloc(size_t size)//自定义malloc 并置空，pnext==NULL?
{
	void * p=malloc(size);
	memset(p,0,size);
	return p;
}

void del_station(PSTA *station_head,PSTA the_station)//利用二级指针删除链表上的节点
{
//************************************************精妙的代码*******************************//
//****************************可不必考虑是否为头指针的情况的****************
	PSTA *pp_station = NULL;
	for(pp_station = station_head;*pp_station;)
	{
		PSTA p_now = *pp_station;
		if(0!=strcmp(p_now->name,the_station->name))
		{
			*pp_station = p_now->next;
			free(p_now);
		}
		else 
		{
			pp_station = &p_now->next;
		}
	}
}

int admin_del_user(PTRA train_head,PUSE *user_head)//删除用户
{//删除用户的步骤
	//找到用户
	//先退订用户所有订票包括排队票---->
	//再删除用户所在的节点
	if(NULL==*user_head)
	{
		printf("无任何用户信息\n");//返回上一级
		system("sleep 1.5");
		return 0;
	}
	char del_user[20];
	printf("请输入要删除的用户名:\n");
	scanf("%s",del_user);
	my_getchar();
	PUSE *the_user = user_head;
	int i = 0;
	for(;*the_user;i++)
	{
		PUSE now_user = *the_user;
		if(strcmp(del_user,now_user->name));
		else//当找到该用户时,退订该用户所有车票
		{
			PTIK del_ticket = now_user->my_ticket;
			PTIK p_del_ticket  = del_ticket;
			for(;del_ticket;del_ticket = p_del_ticket)
			{
				p_del_ticket = del_ticket->next;
				//************
				PTRA the_train = train_head;
				while(the_train)//如果该用户有正常票，则相应的火车的正常票加1
				{
					if(0==strcmp(the_train->name,del_ticket->train_name))
					{
						if(!del_ticket->flag)
						{
							if(the_train->cancel_ticket>=the_train->waiters)
							the_train->tickets++;
							else
								the_train->cancel_ticket++;
							break;
						}
					}
					the_train = the_train->next;
				}
				free(del_ticket);
			}
			*the_user = now_user->next;
			free(now_user);
		}
		the_user = &now_user->next;
	}
	if(NULL==*the_user&&0==i)//指针走到最后，未查到用户
	{
		printf("你输入的用户不存在，请重新输入。\n");
		system("sleep 1.5");
		return 0;		
	}
	return 0;
}

int admin_cancel_user_ticket(PTRA train_head,PUSE user_head)//取消用户订票
{
	char cancel_user[20];
	printf("请输入要退票的用户名:\n");
	scanf("%s",cancel_user);
	my_getchar();
	PUSE now_user = user_head;
	while(NULL!=now_user)
	{
		if(0!=strcmp(now_user->name,cancel_user))
		{
			now_user = now_user->next;
		}
		else
		{
			int cancel_flag = cancel_ticket(now_user,train_head);
			return cancel_flag;
		}
	}
	if(NULL==now_user)
	{
		printf("输入的用户名不存在\n");
		system("sleep 1.5");
		return 0;
	}
	return 0;
}

int check_user_rename(char name[],PUSE head)
{
	while(head)
	{
		if(0==strcmp(name,head->name))
		{
			printf("该用户名已存在，请重试。\n");
			system("sleep 1.5");
			return -1;
		}
		head = head->next;
	}
	return 0;
}
