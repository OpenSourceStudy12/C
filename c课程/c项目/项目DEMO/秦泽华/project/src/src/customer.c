#include"common.h"

static int customer_id = 1;

static void resetID()
{
        customer_id = 1;
}

PNCustomer deleteCustomer(PNCustomer phead, int sid, int *isSuccess)
{
	PNCustomer ptemp = phead;
	PNCustomer pri  = NULL;
	PNCustomer pnext = NULL;
	if (sid < 1)
	{
		*isSuccess = FAILURE;
		return phead;
	}
	while(ptemp->c_id != sid)
	{

		pri = ptemp;
		if (pri->next == NULL)
		{
			*isSuccess = FAILURE;
			return phead;
		}

		ptemp = ptemp->next;
		pnext = ptemp->next;
	}
	if (ptemp == phead)
	{
		phead = ptemp->next;
		free(ptemp);
	}	
	else if(pnext == NULL)
	{
		pri->next = NULL;
		free(ptemp);
	} 
	else
	{
		pri->next = pnext;
		free(ptemp);

	}
	*isSuccess = SUCCESS;
	return phead;
	        
}


PNCustomer updateCustomer(PNCustomer phead, int sid, int *isSuccess)
{
	if (sid < 1)
	{
		*isSuccess = FAILURE;
		return phead;

	}
	PNCustomer ptemp = phead;
	while(ptemp != NULL && ptemp->c_id != sid)
	{
		ptemp = ptemp->next;
	}

	if (ptemp == NULL)
	{
		*isSuccess = FAILURE; 
		return phead;
	}

	printf("请输入您要更改的信息\n");
	printf("姓名 = ");
	scanf("%s", ptemp->c_name);
	printf("性别 = ");
	scanf("%s", ptemp->c_sex);
	printf("年龄 = ");
	scanf("%d", &ptemp->c_age);
	printf("电话 = ");
	scanf("%d", &ptemp->c_phone);
	
	*isSuccess = SUCCESS;
	return phead;	

}

PNCustomer * searchByName(char *name , PNCustomer phead, int *size)
{
	PNCustomer* parr = NULL;
	PNCustomer ptemp = phead;
	int i = 0;
	int j = 0;
	while (ptemp != NULL)
	{
		if (0 == strcmp(name, ptemp->c_name))
		{
			i ++;	
		}
		ptemp = ptemp->next;
	}
	ptemp = phead;
	parr = (PNCustomer *)malloc(sizeof(PNCustomer) * i);
	while (ptemp != NULL)
	{
		if (0 == strcmp(name, ptemp->c_name))
		{
			parr[j] = ptemp;
			j ++;
		}
		ptemp = ptemp->next;
	}
	*size = j;
	return parr;

}



void printAllCustomer(PNCustomer phead)
{
	while (phead != NULL)
	{
		printOneCustomer(phead);
		phead = phead->next;
	}

}

PNCustomer insertCustomer(PNCustomer phead, PNCustomer pnew)
{	
	PNCustomer ptemp = phead;
	while (ptemp->next != NULL)
	{
		ptemp = ptemp->next;	
	}
	ptemp->next = pnew;
	return phead;

}


void printOneCustomer(PNCustomer pcu)
{	
	printf("ID = %d, 姓名 = %s, 性别 = %s, 年龄 = %d, 联系方式 = %d\n"\
		,pcu->c_id, pcu->c_name, pcu->c_sex, pcu->c_age, pcu->c_phone);
}



PNCustomer createCustomer()
{
	
	PNCustomer new = NULL;
	int i = 0;
	new = (PNCustomer)malloc(sizeof(NCustomer));

	new->c_id = (customer_id ++);
	
	printf("请输入您的姓名\n");
	scanf("%s", new->c_name);
	//fgets(new->c_name, 10, stdin);
	//getchar();

	printf("请输入您的密码\n");     //缺少密码隐藏
	scanf("%s", new->c_pwd);
	//fgets(new->c_pwd, 10, stdin);
	//getchar();
	printf("请输入您的性别\n");
	scanf("%s", new->c_sex);

	printf("请输入您的年龄\n");
	scanf("%d", &new->c_age);

	printf("请输入您的电话\n");
	scanf("%d", &new->c_phone);
	//fgets(new->c_name, 10, stdin);
	//getchar();
	new->next = NULL;
	return new;
}
void writeOneCustomer(PNCustomer pcu)
{
	FILE *f_customer;
	f_customer = fopen(CUSTOMER_DB, "a+");
	int result = fwrite(pcu, sizeof(NCustomer), 1, f_customer);	
	
	if (1 != result)
	{
		printf("用户写入文件失败\n");
		return;
	}
	
	fclose(f_customer);
}

void writeAllCustomer(PNCustomer phead)
{
	FILE *f_customer;
	PNCustomer ptemp = phead;
	f_customer = fopen(CUSTOMER_DB, "w+");
	
	while (ptemp != NULL)
	{
		fwrite(ptemp, sizeof(NCustomer), 1, f_customer);
		ptemp = ptemp->next;
	}	
	
	fclose(f_customer);
}

PNCustomer readAllCustomer()
{
	PNCustomer temp = NULL;
	PNCustomer last = NULL;
	PNCustomer start = NULL;
	
	resetID();              // 将id赋值为1
	FILE *f_customer = fopen(CUSTOMER_DB, "a+");
	start = (PNCustomer)malloc(sizeof(NCustomer));
	last = (PNCustomer)malloc(sizeof(NCustomer));
	int size = 1;
	size = fread(start, sizeof(NCustomer), 1, f_customer);  // 缺少对第一次的判断
	last = start;	
	start->c_id = (customer_id ++);
	while(size)
	{
		temp = (PNCustomer)malloc(sizeof(NCustomer));
		
		size = fread(temp, sizeof(NCustomer), 1, f_customer);
		if (size != 1)
		{
			free(temp);
			break;
		}
		temp->c_id = (customer_id ++);
		last->next = temp;
		last = temp;	

	}
	
	fclose(f_customer);
	return start;
}

int loginJudge(char *name, char *pwd, PNCustomer phead, PNCustomer *ppOne)
{
	PNCustomer ptemp = phead;
	
	while (ptemp != NULL)
	{
		if (0 == strcmp(ptemp->c_name, name)&& 0 == strcmp(ptemp->c_pwd, pwd))
		{
			*ppOne = ptemp;  
			return SUCCESS;
		}
		ptemp = ptemp->next;
	}
	
	return FAILURE;
}










