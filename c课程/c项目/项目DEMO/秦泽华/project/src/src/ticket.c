#include"common.h"

static int startTime = 1000;
static int up = 20;
static int money = 1;

#if 0
int main()
{
#if 0
	int size = 0;
	PNStation* p = NULL;
	p = readTrainnu(&size);
	printf("%d\n", size);

	PNStation start = createTrainnu();
	writeTrainnu(start);
	int x;
	scanf("%d", &x);
#endif
	int size = 0;
	PNStation* p = NULL;
	p = readTrainnu(&size);
	PTicket t = createOneTicket(p[2]);
	traverseOneTicket(t);
	char start[10];
	char end[10];
	scanf("%s", start);
	scanf("%s", end);
	PBticket pb = searchBticket(start, end, t);
	if (pb == NULL)
	{
		printf("ddd\n");
		return;
	}
	bookTicket(pb);
	printOnePBticket(pb);
	PNCustomer pnew = createCustomer();
	PCbuy phead = createOneCbuy(pnew, pb);
	PCbuy pc = createOneCbuy(pnew, pb);
	phead = createBuyLink(phead);
	insertBuyLink(phead, pc);
	traverseBuyLink(phead);
		
}
#endif
static void resetMoney()
{
	money = 1;
}	

static void resetTime(int i)
{
	startTime = 1000;
	startTime = startTime + 20 * i;
}


void printOnePBticket(PBticket pb)
{
	printf("起始站为 = %s, 终点站为 = %s, 车次为 = %d, 到达时间为 = %d, 价格 = %d ,是否已经购票 = %d\n", \
			pb->b_sstation, pb->b_tstation, pb->b_trainnu, pb->b_time, pb->b_money, *(pb->isBuy));
}

int printAllPBticket(PBticket *pb, int trainSize)
{
	int i = 0;
	int y = 0;
	for (i = 0; i < trainSize; i++)
	{
		if (NULL != pb[i])
		{
			printf("[ %d ] .", y);	
			printOnePBticket(pb[i]);
			y ++;
		}
	}
	return y;
}

PBticket selectToRealPBticket(PBticket *pb, int select, int trainSize)
{
	int i = 0;
	int y = 0;
	PBticket pbReal = NULL;
	for (i = 0; i < trainSize; i++)
	{
		pbReal = pb[i];
		if (NULL != pb[i])
		{
			if (y == select)
			{
				return pbReal;
			}
			y ++;
		}
	}
	return pbReal;
}


int bookTicket(PBticket pb)
{
	if (*(pb->isBuy) == 0)
	{
		*(pb->isBuy) = 1;
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}
}
int ubookTicket(PCbuy pcb)
{
	if (*(pcb->b_isbuy) == 1)
	{
		*(pcb->b_isbuy) = 0;
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}
}


PBticket* searchAllBticket(const char *start, const char *end, PTicket *pstart, int ticketSize)
{
	int i = 0;
	PBticket *p = (PBticket *)malloc(sizeof (PBticket) * ticketSize);
	for (i = 0; i < ticketSize; i++)
	{
		p[i] = searchBticket(start, end ,pstart[i]);
	}
	return p;

}

PBticket searchBticket(const char *start, const char *end, PTicket phead)
{
	PBticket pb = NULL;
	PTicket ptemp = phead;
	PTStation pThead = NULL;
	int judgeS = 1;
	int judgeE = 1;
	while (ptemp != NULL)
	{
		judgeS = strcmp(start, ptemp->t_fStation);
		pThead = ptemp->t_pTStation;
		if (0 == judgeS)
		{
			PTStation pTtemp = pThead;	
			while (pTtemp != NULL)
			{
				judgeE = strcmp(end, pTtemp->tsta_name);
				if (0 == judgeE)
				{
					pb = (PBticket)malloc(sizeof(NBticket));
					strcpy(pb->b_sstation, ptemp->t_fStation);
					strcpy(pb->b_tstation, pTtemp->tsta_name);
					pb->b_trainnu = ptemp->t_trainnu;
					pb->b_money = pTtemp->tsta_money;
					pb->b_time = pTtemp->tsta_time;		
					pb->isBuy = &(pTtemp->tsta_mark);
				}
				pTtemp = pTtemp->next;

			}
		}
		ptemp = ptemp->t_next;

	}
	return pb;
}



void traverseOneTrainTicket(PTicket phead)
{
	PTicket ptemp = phead;
	while (ptemp != NULL)
	{
	
		printf("车票\n");
		printf("车次 = %d  ", ptemp->t_trainnu);
		printf("出发时间 = %d  ", ptemp->t_time);
		printf("站点为 = %s  ", ptemp->t_fStation);
		printf("\n");
		PTStation pThead = ptemp->t_pTStation;

		PTStation pTtemp = pThead;
		while (pTtemp != NULL)
		{
			printf("下一站点为=%s  ", pTtemp->tsta_name);
			printf("车票价格=%d  ", pTtemp->tsta_money);
			printf("到达时间=%d  ", pTtemp->tsta_time);
			printf("是否已经有订票=%d  ", pTtemp->tsta_mark);
			pTtemp = pTtemp->next;
		}
		printf("\n");
		ptemp = ptemp->t_next;

	}

}

PTicket* createAllTrainTicket(PNStation* pShead, int trainSize)
{
	PTicket *tickets = (PTicket*)malloc(sizeof(PTicket) * trainSize);
	int i = 0;
	for (i = 0; i < trainSize; i++)
	{
		tickets[i] = createOneTrainTicket(pShead[i]);
	}
	return tickets;
}


PTicket createOneTrainTicket(PNStation pShead)
{
	PTicket pThead = NULL;
	PTicket pTtail = NULL;
	PTStation pTStation = NULL;
	PNStation pStemp = pShead;
	PNStation pStemp2 = NULL;
	int i = 1;

	while (pStemp->next != NULL)
	{

		PTicket pTnew  = (PTicket)malloc(sizeof(NTicket));

		pTnew->t_trainnu = pStemp->train_nu;
		pTnew->t_time = startTime;
		startTime += up;
		strcpy(pTnew->t_fStation, pStemp->station_name);
		pTnew->t_next = NULL;

		pStemp2 = pStemp->next;
		pTStation = createPTStationLink(pStemp2);
		pTnew->t_pTStation = pTStation;
		
		if (pThead == NULL)
		{
			pThead = pTnew;
			pTtail = pThead;	
		}
		else
		{
			pTtail->t_next = pTnew;
			pTtail = pTnew;
		}
		pStemp = pStemp->next;
		resetMoney();
		resetTime(i);
		i ++;
	}
	return pThead;
}
PTStation createPTStationLink(PNStation pStemp2)
{
	PTStation ptail = NULL;
	PTStation ptemp = NULL;
	PTStation phead = NULL;
	phead = (PTStation)malloc(sizeof(NTStation));
	
	strcpy(phead->tsta_name, (pStemp2)->station_name);
        phead->tsta_time = startTime;
       	startTime += up;
      	phead->tsta_mark = 0;
      	phead->tsta_money = money ++;
        phead->next = NULL;
	ptail = phead;
	
      	pStemp2 = pStemp2->next;
	
	while (pStemp2 != NULL)
	{
		
		ptemp = (PTStation)malloc(sizeof(NTStation));

       	 	strcpy(ptemp->tsta_name, (pStemp2)->station_name);
        	ptemp->tsta_time = startTime;
        	startTime += up;
        	ptemp->tsta_mark = 0;
        	ptemp->tsta_money = money ++;
        	ptemp->next = NULL;
		ptail->next = ptemp;
		ptail = ptemp;
		pStemp2 = pStemp2->next;

	}
	
	return phead;
}
