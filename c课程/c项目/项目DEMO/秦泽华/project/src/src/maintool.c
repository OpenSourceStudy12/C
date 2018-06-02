#include"common.h"

static PNStation* ptrains = NULL;                 // 所有车次的数组
static PNCustomer pcustomers = NULL;              // 所有用户信息的链表
static PNCustomer pOneCustomer = NULL;            // 该登录用户
static PTicket* ptickets = NULL;                  // 自动生成的所有车票
static PCbuy pcbuys = NULL;                       // 购买了的用户链表
static int trainSize = 0;			  // 有多少班列车
static int bookCount = 0;                         // 一共订票的次数
static int ubookCount = 0;                        // 一共退票的次数
static PQueue *pqs = NULL;
static int queueSize = 0;
void init()
{
	// 初始化函数，首先读取customer，trainnu等DB的信息
	// 通过trainnu自动构建出ticket的链表
	
	trainSize = 0;             // 一共有多少班车次
	
	// 从文件中读取train的信息，是一个train的数组
	ptrains = readTrainnu(&trainSize);
	// 生成所有train的车票
	ptickets = createAllTrainTicket(ptrains, trainSize);	
	// 从文件中读取customer的信息，是一个customer的链表
	pcustomers = readAllCustomer();
	
	pqs = (PQueue *)malloc(sizeof(NQueue)* 20);
	// --------------------读取车票内容------------------------

	// 测试用
	//printAllCustomer(pcustomers);
	//traverseTrainnu(ptrains[2]);
	//
	//PNStation p = createTrainnu();
	//writeTrainnu(p);
	//PNStation p = createTrainnu();
	//writeTrainnu(p);
}


int adminSearchTrainByNu()
{
	title();
	printf("请输入您需要查找的车次号  = ");
	int x = selectIn();
	PNStation psearch = searchTrainByNu(x, ptrains, trainSize);
	
	printf("\n");
	if (NULL == psearch)
	{
		printf("没有您查找的列次.....\n");
		goback();
		return A_T_MENU;
	}
	else
	{
		printf("您查找的车次路程为  :\n");
		traverseTrainnu(psearch);
	}	
	goback();
	return A_T_MENU;

}
int adminSearchAllTrain()
{
	title();
	printf("\n");
	printf("所有车次如下....\n");
	traverseAllTrainnu(ptrains, trainSize);
	goback();
	return A_T_MENU;
	
}
int adminAddTrain()
{
	title();
	PNStation pnew = createTrainnu();
	writeTrainnu(pnew);
	ptrains = readTrainnu(&trainSize);
	ptickets = createAllTrainTicket(ptrains, trainSize);	
	goback();
	return A_T_MENU;

}
int adminDelTrain()
{
	title();
	printf("\n");
	printf("所有车次如下....\n");
	traverseAllTrainnu(ptrains, trainSize);
	printf("请输入您需要删除的车次号  = ");
	int x = selectIn();
	delOneTrain(ptrains, trainSize, x);
	writeAllTrainnu(ptrains, trainSize);

	ptrains = readTrainnu(&trainSize);
	ptickets = createAllTrainTicket(ptrains, trainSize);	
	
	
	goback();
	return A_T_MENU;

}
int adminUpdate()
{
	title();
	goback();
	return A_T_MENU;


}

int adminSearchByName()
{
	title();
	char name[10];
	int size = 0;
	int i = 0;
	printf("请输入您希望查询的用户姓名\n");
	scanf("%s", name);
	PNCustomer *parr = searchByName(name, pcustomers, &size);
	if (0 == size)
	{
		printf("没有您所要查找的用户\n");
	}
	else
	{
		for (i = 0; i < size; i++)
		{
			printOneCustomer(parr[i]);
		}
	}
	goback();
	free(parr);
	return A_C_MENU;
}

int adminSearchAll()
{
	title();
	printf("所有用户信息.......\n");
	printAllCustomer(pcustomers);
	goback();
	return A_C_MENU;
}

int adminAddUser()
{
	title();
	printf("请输入您要输入的用户信息\n");
	PNCustomer pcnew = createCustomer();
	writeOneCustomer(pcnew);
	insertCustomer(pcustomers, pcnew);
	printf("用户添加成功.......\n");	
	goback();
	return A_C_MENU;
}

int adminDeleteUser()
{
	title();
	int id = 0;
	int i = 0;
	int isSuccess = FAILURE;
	printf("所有用户信息.......\n");
	printAllCustomer(pcustomers);
	printf("请根据用户id对用户进行删除\n");
	printf("请输入id = ");
	id = selectIn();	
	pcustomers = deleteCustomer(pcustomers, id, &isSuccess);
	if (FAILURE == isSuccess )
	{
		printf("没有您输入的id号\n");
	}
	else
	{
		printf("用户删除成功!!!!!");
		printf("是否写入文件中？(1 写入 / 0 不写入)\n");
		i = selectIn();
		while (i != 1 && i != 0)
		{
			printf("请输入1或0\n");
			i = selectIn();
		}
		if (1 == i)
		{
			writeAllCustomer(pcustomers);
			printf("已经写入文件\n");
		}
		else
		{
			printf("未写入文件，下次启动时用户依然存在\n");
		}
	}
	goback();
	return A_C_MENU;
	
}

int adminUpdateUser()
{
	title();
	int sid = 0;
	int isSuccess = FAILURE;
	printf("所有用户信息.......\n");
	printAllCustomer(pcustomers);
	printf("请根据用户id对用户进行修改\n");
	printf("请输入id = ");
	sid = selectIn();	
	pcustomers = updateCustomer(pcustomers, sid, &isSuccess);
	if (FAILURE == isSuccess )
	{
		printf("没有您输入的id号\n");
		
	}
	else
	{
		printf("更新成功,写入文件.....");
		writeAllCustomer(pcustomers);
	}
	goback();
	return A_C_MENU;

}


PBticket* selectTrain(int *ticketCounts)
{
	int i = 0;
	PBticket *pbtickets = NULL;
	char start[10];
	char end[10];
	PNStation ptemp = NULL;
	printf("请输入您的起始站\n");
	scanf("%s", start);
	printf("请输入您的终点站\n");
	scanf("%s", end);
	pbtickets = searchAllBticket(start, end, ptickets, trainSize);
	printf("\n");
	printf("满足您希望的列车信息.....\n");
	*ticketCounts = printAllPBticket(pbtickets, trainSize);
	if (0 == (*ticketCounts))
	{
		printf("没有符合您列车的信息..\n");
	}
	else
	{
		printf("\n");
		printf("所有车次如下....\n");
		traverseAllTrainnu(ptrains, trainSize);
	
	}
	return pbtickets;
}

int selfBookTrain()
{
	title();
	printf("\n");
	printf("请输入您车票的起始站，终点站，系统将帮您查找车票\n");
	int ticketCounts = 0;
	PBticket *pbtickets = selectTrain(&ticketCounts);
	PBticket pb = NULL;
	if (ticketCounts == 0)
	{
		goback();
		return CUSTOMER_MENU;
	}
	printf("\n");
	printf("请选择您要预订的车票的编号[ ]\n");
	int select = selectIn();
	while (select >= ticketCounts || select < 0)
	{
		printf("请输入准确的编号\n");
		select = selectIn();
	}
	// 实际选择的与真正存在链表中的顺序进行转换
	pb = selectToRealPBticket(pbtickets, select, trainSize);
	if (pcbuys == NULL)
	{
		bookTicket(pb);
		pcbuys = createOneCbuy(pOneCustomer, pb);
		pcbuys = createBuyLink(pcbuys);
		printf("\n");
		printf("您购买的票的信息为.....\n");
		traverseBuyLink(pcbuys);

		printf("\n");
		printf("恭喜您订票成功!!!!\n");
		bookCount ++;
	}
	else
	{
		if (FAILURE == judgeHadBuy(pcbuys, pOneCustomer))
		{
			printf("每个人只能购买一张票\n");
		}
		else
		{
			if (FAILURE == bookTicket(pb))
			{
				printf("该票已经被购买.....\n");
				PCbuy pnew = createOneCbuy(pOneCustomer, pb);
				isInsertInQueues(pb, pnew, trainSize);
			}
			else
			{
				PCbuy pnew = NULL;
				pnew = createOneCbuy(pOneCustomer, pb);
				pcbuys = insertBuyLink(pcbuys, pnew);
				printf("\n");
				printf("您购买的票的信息为.....\n");
				printOneCbuy(pnew);
				printf("恭喜您订票成功!!!!\n");
				bookCount ++;
				bookTicket(pb);
			}
		}

	}	
	goback();
	return CUSTOMER_MENU;
	
}

void isInsertInQueues(PBticket pb, PCbuy pcb, int trainSize)
{
        printf("是否要排队(1 是/0 不是)? \n");
        int select = selectIn();
        while (select != 1 &&  select != 0)
        {
                printf("没有您输入的选项\n");
                select = selectIn();
        }
        if (select == 1)
        {
                PTicket pt = searchTicketByNu(ptickets, pb->b_trainnu, trainSize);
                int num = searchNumToQueue(pb->b_sstation, pb->b_tstation, pt);
                int i = 0;
                PQueue pq = isQueueExist(pqs, num , queueSize, &i);
                if (pq != NULL)
                {
                        pqs[i] = inCbuyQueue(pq, pcb);
                }
                else
                {
                        PQueue p = createQueue(pcb, num);
                        pqs[queueSize ++] = p;
                }
		printf("如果有人退票，系统将第一时间通知您..........\n");
        }
        else if (select == 0)
        {
                printf("您没有排队....\n");
        }
        // 找到用户应该存放的队列
        // 通过车次找到车次，通过起始终点找到位置
        // 把 用户放入队列中

        //如果存在，加入
}



void hideMenu(PNCustomer p)
{
	PQueue pq = searchQueuesByPCbuy(pqs, p, queueSize); 	
	if (pq != NULL && pq->isUbook == 1)
	{
		hideWelcome();
		setUbookTo0(pq);
		outCbuyQueue(pq);
	}

}


int selfUBookTrain()
{
	title();
	PCbuy pcb = searchCbuyByName(pOneCustomer, pcbuys);
	if (NULL == pcb)
	{
		printf("您并没有购买票\n");
	}
	else
	{
		printf("您定的票的信息为\n");
		printOneCbuy(pcb);
		printf("您确定退票吗？(否为999,其余任何数字都默认为确定)  :");
		int x = selectIn();
		if (x != 999)
		{
                	PTicket pt = searchTicketByNu(ptickets, pcb->b_trainnu, trainSize);
                	int num = searchNumToQueue(pcb->b_sstation, pcb->b_tstation, pt);
			int pos = 0; 
			PQueue pq = isQueueExist(pqs, num, queueSize, &pos);
			if (pq != NULL)
			{	
				setUbookTo1(pq);
			}

			ubookTicket(pcb);
			pcbuys = delOneCbuy(pcbuys, pcb);
			printf("退票成功\n");
			ubookCount ++;
		}
		else
		{
			printf("没有退票\n");
		}
	}
	goback();
	return CUSTOMER_MENU;
}








int selfSelectTrain()
{
	title();
	int ticketCounts = 0;
	selectTrain(&ticketCounts);	
	goback();
	return CUSTOMER_MENU;
}



int selfCustomerInforamtion()
{
	title();
	printf("您的信息如下......\n");
	printOneCustomer(pOneCustomer);
	goback();
	return CUSTOMER_MENU;
}

int count()
{
	title();
	printf("一共订票 %d 次 \n", bookCount);
	printf("一共退票 %d 次 \n", ubookCount);
	goback();
	return ADMIN_MENU;
}

int mainChoose()
{
	welcome();
	int select = selectIn();
	switch(select)
	{
		// 跳转用户登录界面 
		case  LOGIN:
			return LOGIN;  
		// 跳转用户注册界面
		case REGISTER:
			return REGISTER;
		// 用户输入异常需要重新输入
		default :
			selectError();
			return MAIN_MENU;
	}		
} 

int cregister()
{
	int select = 0;
	registerWelcome();

	// 创建一个用户，将用户加入用户链表中并写入文件，成功返回主界面登录
	PNCustomer pcnew = createCustomer();
	writeOneCustomer(pcnew);
	insertCustomer(pcustomers, pcnew);
	
	// 测试
	//printAllCustomer(pcustomers);
	
	printf("用户注册成功!返回主界面....\n");
	printf("请输入任何数字返回主界面....\n");
	select = selectIn();	

	return MAIN_MENU;

}


// 错误返回 0则到主界面，输入正确是用户->11, 是管理员->12 
int login()
{
        loginWelcome();
        char loginName[10];
        char loginPwd[10];
        printf("请输入您的姓名  ");
        scanf("%s", loginName);
        printf("请输入您的密码  ");
        scanf("%s", loginPwd);

        // 比对是否存在该用户，或者管理员
        // 用户：跳转到旅客用户登录后界面,并且保存该用户的用户节点
	// 管理员：跳转到管理员界面
	// 错误返回登录页面重新输入
	if (SUCCESS == loginJudge(loginName, loginPwd, pcustomers, &pOneCustomer))
	{
		return CUSTOMER_MENU;
	}
	if (0 == strcmp(ADMIN, loginName) && 0 == strcmp(PWD, loginPwd))
	{
		return ADMIN_MENU;
	}
	else
	{
		printf("用户名和密码不正确 按任意数字返回登录界面\n");
		selectIn();
		return MAIN_MENU;
	}	

	//return CUSTOMER_MENU;
}


// 错误返回customer_main 11
int customer()
{
	hideMenu(pOneCustomer);
	customerWelcome();
	int select = selectIn();
	select = 110 + select;
	switch(select)
	{
		case C_INFORMATION :
			return C_INFORMATION;	
		case C_SEARCH      :
			return C_SEARCH;
		case C_BOOK :
			return C_BOOK;
		case C_REFUND:
			return C_REFUND;
		case C_LOGOUT:
			return MAIN_MENU;
		default:
			selectError();
			return CUSTOMER_MENU;
	}

}

int admin()
{
	adminWelcome();
	int select = selectIn();
	select = 120 + select;
	switch(select)
	{
		case A_C_MENU:
			return A_C_MENU;
		case A_T_MENU:
			return A_T_MENU;
		case A_STA:
			return A_STA;
		case A_LOGOUT:
			return MAIN_MENU;
		default:
			selectError();
			return ADMIN_MENU;
	}
}

int manCustomer()
{
	manCustomerWelcome();
	int select = selectIn();
	select = 1210 + select;
	
	switch(select)
	{
		case A_C_NAME:
			return A_C_NAME;
		case A_C_ALL:
			return A_C_ALL;
		case A_C_ADD:
			return A_C_ADD;
		case A_C_DEL:
			return A_C_DEL;
		case A_C_UPDATE:
			return A_C_UPDATE;
		case A_C_BACK:
			return ADMIN_MENU;
		default:
			selectError();
			return A_C_MENU;
		
	}

}


int manTrain()
{
	manTrainWelcome();
	int select = selectIn();
	select = 1220 + select;
	
	switch(select)
	{
		case A_T_NU:
			return A_T_NU;
		case A_T_ALL:
			return A_T_ALL;
		case A_T_ADD:
			return A_T_ADD;
		case A_T_DEL:
			return A_T_DEL;
		case A_T_UPDATE:
			return A_T_UPDATE;
		case A_T_BACK:
			return ADMIN_MENU;
		default:
			selectError();
			return A_T_MENU;
	}

}











