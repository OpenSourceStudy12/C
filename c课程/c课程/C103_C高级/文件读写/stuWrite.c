#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	int num;
	char name[20];
	char sex;
	float score;
}STU;


int writeData(STU *pstu)
{
	FILE *fp = NULL;
	fp = fopen("stuData","wb");
	if(fp == NULL)
	{
		printf("打开文件失败\n");
		return -1;
	}
	int ret = fwrite(pstu,sizeof(STU),1,fp);
	if(ret <1)
	{
		printf("写入失败\n");
		return -1;
	}
	fclose(fp);
}

STU *readStu()
{
	FILE *fp = NULL;
	fp = fopen("stuData","rb");
	if(fp == NULL)
	{
		printf("打开文件失败\n");
		return NULL;
	}
	int ret;
	STU *s=NULL;
	
	s= malloc(sizeof(STU));
	ret = fread(s,sizeof(STU),1,fp);
		
	if(ret <1)
		printf("读书据失败\n");
	
	fclose(fp);
	return s;
}
int main()
{
	//STU s = {1001,"tony",'M',99};
	//writeData(&s);
	STU *p = readStu();
	printf("%d %s %c %f\n",p->num,p->name,p->sex,p->score);
	free(p);
}

