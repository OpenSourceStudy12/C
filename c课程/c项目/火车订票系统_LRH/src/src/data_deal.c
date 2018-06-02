#include"data_deal.h"

/*************************************
*func:user_data_read
*describtion:从文件里读取用户数据
*************************************/
PUser user_data_read()
{
	PUser head_user = NULL;
	PUser s = NULL,p = NULL;
	PU_i_t t = NULL,q = NULL;
	FILE *fp = NULL;
	int re,i;
	fp = fopen("userdata","rb");
	if(fp == NULL)
	{
		printf("file open fail..\n");
		return head_user;	
	}	
	while(1)
	{
		s = (PUser)malloc(sizeof(User));
		s->next = NULL;
		re = fread(s,sizeof(User),1,fp);//读用户信息
		if(re < 1)
			break;
		if(head_user == NULL)
			head_user = s;
		else
			p->next = s;
		p = s;

		/**/
/*		for(i=0;i<s->ticket_num;i++)
		{
			t = (PU_i_t)malloc(sizeof(U_i_t));
			t->next = NULL;
			fread(t,sizeof(U_i_t),1,fp);//读订票信息
			if(s->pu_i_t == NULL)
				s->pu_i_t = t;
			else
				q->next = t;
			q = t;
		}		
*/		
		if(s->pu_i_t != NULL)
		{
			s->pu_i_t = NULL;
			while(1)
			{
				t = (PU_i_t)malloc(sizeof(U_i_t));
				//t->next = NULL;
				fread(t,sizeof(U_i_t),1,fp);//读订票信息
				//if(t->next == NULL)
				//	break;
				if(s->pu_i_t == NULL)
					s->pu_i_t = t;
				else
					q->next = t;
				q = t;
				if(t->next == NULL)
					break;
			}
		}  
	}
	free(s);
	//p->next = NULL;
	fclose(fp);
	return head_user;

}

/*************************************
*func:train_data_read
*describtion:从文件里读取车次数据数据
*************************************/
PTra train_data_read()
{
	PTra head_train = NULL;
	PTra s = NULL,p = NULL;
	PSta t = NULL,q = NULL;
	PQueue pq = NULL,ps = NULL;
	FILE *fp = NULL;
	int re,i;
	fp = fopen("traindata","rb");
	if(fp == NULL)
	{
		printf("file open fail..\n");
		return NULL;	
	}	
	while(1)
	{
		s = (PTra)malloc(sizeof(Tra));
		s->next = NULL;
		re = fread(s,sizeof(Tra),1,fp);//读车次信息
		if(re < 1)
			break;
		if(head_train == NULL)
			head_train = s;
		else
			p->next = s;
		p = s;
		s->pst = NULL;
	
		for(i=0;i<s->station_num;i++)
		{
			t = (PSta)malloc(sizeof(Sta));
			t->next = NULL;
			fread(t,sizeof(Sta),1,fp);//读车站信息
			if(s->pst == NULL)
				s->pst = t;
			else
				q->next = t;
			q = t;
		}
		//t->next = NULL;
		if(s->pqueue != NULL)
		{
			s->pqueue = NULL;
			while(1)
			{
				pq = (PQueue)malloc(sizeof(Queue));
				//pq->next = NULL;
				fread(pq,sizeof(Queue),1,fp);
				if(s->pqueue == NULL)
					s->pqueue = pq;
				else
					ps->next = pq;
				ps = pq;
				if(pq->next == NULL)
					break;
			}
		}
	}
	free(s);
	//p->next = NULL;
	fclose(fp);
	return head_train;
}

/*******************************************
*func:user_data_save
*describtion:保存用户数据
********************************************/
int user_data_save(PUser head_user)
{
	PUser p = head_user;
	PU_i_t q = NULL;
	FILE *fp = NULL;
	int re;
	fp = fopen("userdata","wb+");//清空原有数据
	if(fp == NULL)
	{
		printf("写入文件失败..\n");
		return -1;
	}
	while(p != NULL)
	{
		re = fwrite(p,sizeof(User),1,fp);
		if(re < 1)
			return -1;
		q = p->pu_i_t;
		while(q != NULL)
		{
			re = fwrite(q,sizeof(U_i_t),1,fp);
			if(re < 1)
				return -1;
			q = q->next;
		}
		p = p->next;
	}
	fclose(fp);
	return 0;
}


/*******************************************
*func:train_data_save
*describtion:保存车次数据
********************************************/
int train_data_save(PTra head_train)
{
	PTra p = head_train;
	PSta q = NULL;
	PQueue m = NULL;
	FILE *fp = NULL;
	int re;
	fp = fopen("traindata","wb+");//清空原有数据
	if(fp == NULL)
	{
		printf("打开文件失败..\n");
		return -1;
	}
	while(p != NULL)
	{
		re = fwrite(p,sizeof(Tra),1,fp);
		if(re < 1)
			return -1;
		q = p->pst;
		while(q != NULL)
		{
			re = fwrite(q,sizeof(Sta),1,fp);
			if(re < 1)
				return -1;
			q = q->next;
		}
		
		m = p->pqueue;
		while(m != NULL)
		{
			re = fwrite(m,sizeof(Queue),1,fp);
			if(re < 1)
				return -1;
			m = m->next;
		}
		p = p->next;
	}
	fclose(fp);
	return 0;
}
