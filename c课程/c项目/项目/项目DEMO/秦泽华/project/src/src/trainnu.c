#include"common.h"

#if 0
int main()
{
	//PNStation p = createTrainnu();
	//writeTrainnu(p);
	int arr_size = 0;
	int *parr_size = &arr_size;
	PNStation *arr_start = NULL;
	arr_start = readTrainnu(parr_size);

	
	traverseAllTrainnu(arr_start, arr_size - 1);
}
#endif

static int trainNumber = 0;


void traverseAllTrainnu(PNStation *arr_start, int arr_size)
{
	int i = 0;
	PNStation temp = NULL;
	for (i = 0; i < arr_size; i++)
	{
		temp = arr_start[i];	
		traverseTrainnu(temp);
	}
	
}

void delOneTrain(PNStation *arr_start, int arr_size, int nu)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < arr_size; i ++)
	{
		if (nu == arr_start[i]->train_nu)
		{
			dropTrain(&(arr_start[i]));
		}
	}
}



void dropTrain(PNStation *phead)
{
	PNStation ptemp = *phead;
	if (ptemp == NULL)
	{
		return;
	}
	while(*phead != NULL)
	{
		ptemp = *phead;
		*phead = (*phead)->next;
		free(ptemp);
	}
	
	*phead == NULL;

}

void writeAllTrainnu(PNStation* arr_start, int arr_size)
{
	FILE *f_trainnu;
	f_trainnu = fopen(TRAIN_DB, "w+");
	int i = 0;
	for (i = 0; i < arr_size; i++)
	{
		if (NULL != arr_start[i])
		{
			PNStation temp = arr_start[i];
			while (temp != NULL)
			{	
				int result = fwrite(temp, sizeof(NStation), 1, f_trainnu);
				if (1 != result)
				{
					printf("车次链表数据存在写入失败\n");
				}
				temp = temp->next;
			}

		}

	}
	fclose(f_trainnu);

}

PNStation searchTrainByNu(int num, PNStation *arr_start, int arr_size)
{
	PNStation p = NULL;
	int i = 0;
	for (i = 0; i < arr_size; i ++)
	{
		if (num == (arr_start[i]->train_nu))
		{
			p = arr_start[i];
			return p;
		}
	}
	return p;
}


/*
        函数作用：从文件中读取车次链表
        返回值  ：指向车次链表首地址的指针数组

*/
PNStation* readTrainnu(int *arr_size)
{
	int i = 0;
	int size = 1;              // 判断数据读出的长度是否为1
	PNStation start = NULL;
	PNStation temp = NULL;
	PNStation temp2 = NULL;

	FILE *f_trainnu = fopen(TRAIN_DB, "r+");
	PNStation *trainnu_arr = (PNStation *)malloc(sizeof(PNStation) * MAX_ARR_TRAINNU);  //         没有free
	
	// 实际的arr_size应该减去1
	while(1 == size)
	{
		temp = (PNStation)malloc(sizeof(NStation));           
		start = (PNStation)malloc(sizeof(NStation));           
		// 先读第一条作为车次链表的首地址,                                                      缺判断
		size = fread(start, sizeof(NStation), 1, f_trainnu);
		start->train_nu = i;
		temp = start;
		trainnu_arr[i] = start;
		while(temp->next != NULL)
		{
			temp2 = (PNStation)malloc(sizeof(NStation));           
			size = fread(temp2, sizeof(NStation), 1, f_trainnu);
			temp2->train_nu = i;
			temp->next = temp2;
			temp = temp2;	
		}
		trainNumber ++;
		i ++;
	}
	*arr_size = i - 1;
	fclose(f_trainnu);
	return trainnu_arr;
}

void writeTrainnu(PNStation start)
{
	FILE *f_trainnu;
	PNStation temp = start;
	f_trainnu = fopen(TRAIN_DB, "a+");
	while (temp != NULL)
	{	
		int result = fwrite(temp, sizeof(NStation), 1, f_trainnu);
		if (1 != result)
		{
			printf("车次链表数据存在写入失败\n");
		}
		temp = temp->next;
	}

	fclose(f_trainnu);
}

/*
        函数作用：创建车次链表
        返回值  ：指向车次链表首地址的指针
PNStation creatTrainnu();
*/
PNStation createTrainnu()
{
	PNStation start = NULL; //起始站
	PNStation final = NULL;
	PNStation temp = NULL;
	int i = 1;

	while(1)
	{
		
		PNStation temp = (PNStation)malloc(sizeof(NStation));   // 空间未被释放
		//temp->station_name = (char *)malloc(sizeof(char) * MAX_NAME); // 空间未被释放
		printf("请输入 %d 号车次%d站点(输入999结束) = ", trainNumber - 1, i);
		scanf("%s", temp->station_name);
		if (0 == strcmp("999", temp->station_name))
		{
			free(temp);
			break;
		}	
						
		temp->train_nu = trainNumber;
		// 创建起点
		if (NULL == start)
		{
			temp->next = NULL;
			start = temp;
			final = start;
		}
		else
		{
			temp->next = NULL;
			final->next = temp;
			final = temp;	
		}
		i ++;
	}
	
	return start;
}

/*
        函数作用：查看车次链表
        参数    ：车次链表头指针
*/
void traverseTrainnu(PNStation start)
{
	PNStation temp = start;
	printf("车次 %d 的路线为\n", start->train_nu);
	while (temp != NULL)
	{
		printf("[  %s   ]  ", temp->station_name);
		temp = temp->next;
	}
	printf("\n");
}


