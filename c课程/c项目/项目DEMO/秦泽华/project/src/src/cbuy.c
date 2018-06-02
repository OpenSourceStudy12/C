#include"common.h"

PCbuy createOneCbuy(PNCustomer pc, PBticket pt)
{
	PCbuy pb = (PCbuy)malloc(sizeof(NCbuy));
	strcpy(pb->b_cname, pc->c_name);
	strcpy(pb->b_sstation, pt->b_sstation);
	strcpy(pb->b_tstation, pt->b_tstation);
	pb->b_trainnu = pt->b_trainnu;
	pb->b_time = pt->b_time;
	pb->b_isbuy =(pt->isBuy);
	pb->next = NULL;

}

PCbuy createBuyLink(PCbuy phead)
{
	return phead;
}

PCbuy searchCbuyByName(PNCustomer pnc, PCbuy phead)
{
	PCbuy ptemp = phead;
	while (ptemp != NULL)
	{
		if (0 == strcmp(ptemp->b_cname, pnc->c_name))
		{
			return ptemp;
		}
		ptemp = ptemp->next;
	}
	return ptemp;
}

PCbuy delOneCbuy(PCbuy phead, PCbuy pdel)
{
	PCbuy pri = phead;
	if (phead == pdel)
	{
		phead = pdel->next;
		free(phead);
	}
	
	else
	{
		while (pri != NULL && pri->next != pdel)
		{
			pri = pri->next;
		}
	
		pri->next = pdel->next;
		free(pdel);
	}
	return phead;
	
}


PCbuy insertBuyLink(PCbuy phead, PCbuy pnew)
{
	PCbuy ptemp = NULL;
	PCbuy ptail = NULL;
	// 链表中没有数据，第一次创建链表
	// 链表中只有一条数据
	if (phead->next == NULL)
	{
		phead->next = pnew;
		return phead;
	}
	else
	{
		while(ptemp->next != NULL)
		{
			ptemp = ptemp->next;
		}
		ptemp->next = pnew;
		return phead;
	}
}
void traverseBuyLink(PCbuy phead)
{
	PCbuy ptemp = phead;
	int i = 0; 
	while (ptemp != NULL)
	{
		printf("用户名=%s ", ptemp->b_cname);
		printf("起始站=%s ", ptemp->b_sstation);
		printf("终点站=%s ", ptemp->b_tstation);
		printf("车次=%d ", ptemp->b_trainnu);
		printf("达到时间=%d", ptemp->b_time);
		printf("\n");
		ptemp = ptemp->next; 
	}

}

void printOneCbuy(PCbuy ptemp)
{
	printf("用户名=%s ", ptemp->b_cname);
       	printf("起始站=%s ", ptemp->b_sstation);
        printf("终点站=%s ", ptemp->b_tstation);
        printf("车次=%d ", ptemp->b_trainnu);
       	printf("达到时间=%d", ptemp->b_time);
        printf("\n");

}

int judgeHadBuy(PCbuy phead, PNCustomer pc)
{
	PCbuy ptemp = phead;
	while (ptemp != NULL)
	{
		if (0 == strcmp(ptemp->b_cname, pc->c_name))
		{
			return FAILURE;
		}

		ptemp = ptemp->next;
	}

	return SUCCESS;
}

PCbuy  readAllPCbuy()
{
	PCbuy phead = NULL;
	PCbuy ptemp = NULL;
	PCbuy ptail = NULL;
	
	FILE *f = NULL;
	f = fopen(CBUY_DB, "r+");
	phead = (PCbuy)malloc(sizeof(NCbuy));
	ptail = phead;
	 	
	int size = fread(phead, sizeof(NCbuy), 1, f);
	
	while (size)
	{
		
		ptemp = (PCbuy)malloc(sizeof(NCbuy));
		
		size = fread(ptemp, sizeof(NCbuy), 1, f);
		if (size != 1)
		{
			free(ptemp);
			break;
		}
		
		ptail->next = ptemp;
		ptail = ptemp;

	}

	fclose(f);
	return phead;
}

void writeAllPCbuy(PCbuy phead)
{
	PCbuy ptemp = phead;
	FILE *f = NULL;
	f = fopen(CBUY_DB, "w+"); 
	while (ptemp != NULL)
	{
		fwrite(ptemp, sizeof(NCbuy), 1, f);
		ptemp = ptemp->next;
	}
	fclose(f);
}









PQueue createQueue(PCbuy pcb, int num)
{
	PQueue phead = (PQueue)malloc(sizeof(NQueue));
	phead->number =  num;
	phead->isUbook = 0;
	phead->pfront = pcb;
	return phead;
}



PQueue isQueueExist(PQueue* p, int num, int arr_size, int *pos)
{
	int i = 0;
	for (i = 0; i < arr_size; i++)
	{
		if (p[i]->number == num)
		{
			*pos = i;
			return p[i];
		}
		
	}
	return NULL;
}


PTicket searchTicketByNu(PTicket *pstart, int num, int arr_size)
{
	int i = 0;
	for (i = 0; i < arr_size; i++)
	{
		if (pstart[i]->t_trainnu == num)
		{
			return pstart[i];
		}
	}
	return NULL;
}

int searchNumToQueue(const char *start, const char *end, PTicket phead)
{
	int i = 0, j = 0;
	int x = 0, y = 0;
	int sum = 0;
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
			x = i;
                        PTStation pTtemp = pThead;
                        while (pTtemp != NULL)
                        {
                                judgeE = strcmp(end, pTtemp->tsta_name);
                                if (0 == judgeE)
                                {
					y = j;
                                }
                                pTtemp = pTtemp->next;
				j ++;
                        }
                }
                ptemp = ptemp->t_next;
		j = 0;
		i ++;
        }

	sum = x * 10 + y;
	return sum;
}

PQueue inCbuyQueue(PQueue pq, PCbuy prear)
{
	if (pq->pfront == NULL)
	{
		pq->pfront = prear;
		return pq;
	}
	else
	{
		PCbuy ptemp = pq->pfront;
		while (ptemp->next != NULL)
		{
			ptemp = ptemp->next;
		}
		ptemp->next = prear;
		prear->next = NULL;
	}
	return pq;
}
void outCbuyQueue(PQueue pq)
{
	PCbuy ptemp = NULL;
	if (pq->pfront->next != NULL)
	{
		ptemp = pq->pfront;
		pq->pfront = pq->pfront->next;

		free(ptemp);
	}
	else
	{
		free(pq->pfront);
	}


}

PQueue searchQueuesByPCbuy(PQueue *pq, PNCustomer pnc, int queueSize)
{
	int i = 0;
	for (i = 0; i < queueSize; i++)
	{
		if (0 == strcmp(pq[i]->pfront->b_cname, pnc->c_name))
		{
			return pq[i];
		}
	}

	return NULL;
}

void setUbookTo1(PQueue pq)
{
	pq->isUbook = 1;
}

void setUbookTo0(PQueue pq)
{
	pq->isUbook = 0;
}


void test(PQueue *p, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("djkaj = %d, dj= %d",p[i]->number,p[i]->isUbook);
	}
}

