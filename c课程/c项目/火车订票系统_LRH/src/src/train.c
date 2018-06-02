#include"train.h"


/*********************************************************************
*func:train_num_search
*describtion:车次查询(查新列车的运行路线信息)
*********************************************************************/
void train_num_search(const PTra head)
{
	system("clear");
	printf("\n\t\t\t\t***************车   次   查   询******************\n\n");
	PTra p = head;
	if(p == NULL)
	{
		system("clear");
		printf("\n无列车信息\n");
		sleep(1);
		return;
	}
	else
	{
		char name_num[TRA_NUM];
		printf("\n请输入想要查询的车次:");
		scanf("%s",name_num);
		while(getchar() != '\n');
		while(p != NULL)
		{
			if(!strcmp(p->train_num,name_num))
			{
				route_map_print(p);
				//printf("\n输入任意键继续\n");
				while(getchar() != '\n');
				return;
			}
			p = p->next;
		}
		printf("\n无%s车次信息\n",name_num);
		sleep(1);	
	}

}


/**********************************************************
*func:route_map_print
*describtion:输入车次结构体地址，打印车次的运行路线
***********************************************************/
void route_map_print(const PTra head)
{
	PSta p = head->pst;
	int i;
	if( p == NULL)
	{
		printf("\n暂无%s路线信息\n",head->train_num);
		return;
	}
	printf("\n%s:\n\n",head->train_num);
	for(i=1;i<=head->station_num;i++)
	{
		if(i == 0)
			printf("始:%s[%d:%d][%d]",p->sta_name,p->arrival_hour,
				p->arrival_minute,p->ticket_num);
		else if(i == head->station_num)
			printf("%s[%d:%d]:终",p->sta_name,p->arrival_hour,
				p->arrival_minute);
		else

			printf("%s[%d:%d,%d:%d][%d]",p->sta_name,p->arrival_hour,
			p->arrival_minute,p->departure_hour,p->departure_minute,p->ticket_num);
		if(i < head->station_num)
			printf(" --> ");
		if(i%5==0)
			printf("\n\n");
		p = p->next;
	}
	putchar('\n');
	putchar('\n');
	//printf("\b\b\b\n");
}

/*************************************************************
*func:站站查询
*function:
*将满足站站查询条件的车次重新组建链表
*返回链表首地址
 *************************************************************/
PTr station_search(const PTra head,char *start,char * end)
{
	PTr tr_head = NULL;
	if(head == NULL)
	{
		printf("\n暂无列车信息\n");
		sleep(1);
		return NULL;
	}
	else
	{
		//char start[STA_NAME],end[STA_NAME];
		//printf("请输入想要查询的出发站和到站:\n");
		//scanf("%s%s",start,end);
		//while(getchar() != '\n');
		//printf("车次\t\t始发站\t\t终点站\n");
		PTra p = head;
		PSta q = NULL,y = NULL,tail = NULL;
		while(p != NULL)//遍历车次
		{
			q = p->pst;
			while(q != NULL)//遍历列车路线
			{
				if(!strcmp(q->sta_name,start))//查找出发站
				{
					y = q->next;
					while(y != NULL)
					{
						if(!strcmp(y->sta_name,end))//查找到站
						{
							tr_head = node_add(tr_head,p);//将符合站站查询条件的车次保存到新的链表中
							//while(y->next != NULL)
								//y = y->next;
							//printf("%s\t\t%s\t\t%s\n",p->train_num,p->pst->sta_name,y->sta_name);
							//route_map_print(p->pst);
							break;
						}
						y = y->next;
					}
					break;
				}
				q = q->next;
			}
			p = p->next;
		}
	}
	return tr_head;
}


/********删除链表********/
void link_del(PTr head)
{
	PTr p = head;
	while(p != NULL)
	{
		head = head->next;
		free(p);
		p = head;
	}
	//printf("**************");
	//sleep(5);
}



/*建立链表(满足站站查询的车次链表)*/
PTr node_add(PTr head,PTra ch)
{
	//static int cnt;
	PTr p = head,q = NULL;

	q = (PTr)malloc(sizeof(Tr));
	q->ptra = ch;
	//q->cnt = cnt++;
	q->next = NULL;
	
	if(head == NULL)
		head = q;
	else
	{	while(p->next != NULL)
			p = p->next;
		p->next = q;
	}
	return head;
}

/***********************************************
*查找列车最后一个站
*describtion:
*返回列车最后一个站的地址
************************************************/
PSta end_station_search(PTra head)
{
	if(head == NULL)
		return NULL;
	PSta tail = head->pst;;
	if(tail == NULL)
		return NULL;
	else
	{
		while(tail->next != NULL)
			tail = tail->next;
	}
	return tail;
}


/***************************************************
*func:链表打印
*describtion:
*打印站站查询的结果(列车的始发站，到站)
****************************************************/
void print(PTr head,char *start,char *end)
{
/*	PSta tail = NULL;
	PSta p = NULL;
	printf("车次\t\t始发站\t\t终点站\n");
	while(head != NULL)
	{
		p = head->ptra->pst;
		tail = end_station_search(head->ptra);
		printf("%s\t\t%s\t\t%s\n",head->ptra->train_num,p->sta_name,tail->sta_name);
		head = head->next;
	}
*/
	if(head == NULL)
		return;
	PTr p = head;
	//system("clear");
	printf("车次\t出发站\t\t到站\t\t余票\t发车时间\t旅程时间\n");
	while(p != NULL)
	{
		single_print(p->ptra,start,end);
		p = p->next;
	}
	return;
}


/************************************************
*func:打印单个站站查询的车次信息
*describtion:  
*************************************************/
void single_print(PTra head,char *start,char *end)
{
	if(head != NULL)
	{
		//printfi("车次\t出发站\t\t到站\t\t余票\t发车时间\t到站时间\n");
		PSta p = head->pst,q = NULL;
		while(p != NULL)
		{
			if(!strcmp(p->sta_name,start))
			{
				q = p->next;
				while(q != NULL)
				{
					if(!strcmp(q->sta_name,end))
					{
						int depart_hour,depart_minute,run_hour,run_minute;
						float price;
						printf("%s\t%s\t\t%s\t\t%d\t",head->train_num,p->sta_name,q->sta_name,p->ticket_num);
						train_time_count(p,q,&depart_hour,&depart_minute,&run_hour,&run_minute);
						printf("%2d:%2d\t\t%2d:%2d\n",depart_hour,depart_minute,run_hour,run_minute);		
						return;
					}
					q = q->next;
				}
				return;
			}
			p = p->next;	
		}
	}
	return;
}

/*******************************************************************************
*func:traiin_time_search
*describtion:计算两站之间的发车时间、运行时间
********************************************************************************/
void train_time_count(PSta pr,PSta pn,int *de_hour,
		int *de_min,int *run_hour,int *run_min)
{
	//int d_h,d_m,r_h,r_m;
	int de_minute,arr_minute;
	int minute = 0,i = 0;;
	PSta p = NULL;
	*de_hour = pr->departure_hour;
	*de_min = pr->departure_minute;
	*run_hour = 0;
	*run_min = 0;
	while(1)
	{
		i++;
		p = pr->next;
		de_minute = pr->departure_hour * MINUTE + pr->departure_minute;
		arr_minute = p->arrival_hour * MINUTE + p->arrival_minute;
		if(arr_minute < de_minute)
			minute += arr_minute - de_minute + HOUR * MINUTE;
		else
			minute += arr_minute - de_minute;
		pr = pr->next;
		if(pr == pn)
			break;
	}
	*run_hour = minute / MINUTE;
	*run_min = minute % MINUTE;
	//*price = PRICE * i;
	return;
}

/***************************************************
*func:
*describtion:
*根据车次查找车次结构体的地址
****************************************************/
PTra train_address_search(const PTra head,char *ch)
{
	PTra tr = head;
	while(tr != NULL)
	{
		if(!strcmp(tr->train_num,ch))
		{
			return tr;
		}
		tr = tr->next;
	}
	return tr;
}

/***************************************************
*func:
*describtion:
*查找车次中车站的地址
****************************************************/
PSta sta_address_search(PTra train,char *ch)
{
	if(train != NULL)
	{
		PSta tr = train->pst;
		while(tr != NULL)
		{
			if(!strcmp(tr->sta_name,ch))
			{
 				return tr;
			}
			tr = tr->next;
		}
		return NULL;
	}
	return NULL;
}

/*****************************************************************
*func:train_address_search
*desceibtion:根据车次名称查找对应的地址
*****************************************************************/
/*
PTra train_address_search(const PTra train_head,char *train_num)
{
	PTra p = train_head;
	if(p == NULL)
		return NULL;
	while( p != NULL)
	{
		if(!strcmp(p->train_num,train_num))
			return p;
	}
	return NULL;
}
*/
