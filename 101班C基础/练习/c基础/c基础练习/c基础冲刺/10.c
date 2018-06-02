/*********************************************************
*file name:
*function:
*dauthor:
**********************************************************/
#include<stdio.h>

typedef struct stu
{
	int num;
	char name[15];
	float score;
}STU;

void get_data(STU *pt,int n);
float analyze_data(STU *pt,int a,int b[],int *p);
void pri_data(STU *pt,int n,float ave);
void over_ave_data(STU *pt,int count,int b[]);

int main()
{
	STU st[5];
	int num[5];
	int count;
	float ave;
	get_data(st,5);
//	pri_data(st,5);
	ave = analyze_data(st,5,num,&count);
	pri_data(st,5,ave);
	over_ave_data(st,count,num);
	return 0;

} 

void get_data(STU *pt,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("请输入第%d个学生的学号、姓名、成绩:\n",i+1);
		scanf("%d%s%f",&(pt+i)->num,(pt+i)->name,&(pt+i)->score);
	}

}

float analyze_data(STU *pt,int a,int b[],int *p)
{
	int i;
	float ave=0;
	*p=0;
	for(i=0;i<5;i++)
		ave += pt[i].score;
	ave /= 5;
	for(i=0;i<5;i++)
	{
		if(pt[i].score >= ave)
		{	
			b[(*p)++]=pt[i].num;
//			(*p)++;
		}
	}
	return ave;
}

void pri_data(STU *pt,int n,float ave)
{
	int i;
	printf("学号\t姓名\t成绩\n");
	for(i=0;i<n;i++)
		printf("%d\t%s\t%.2f\n",(pt+i)->num,(pt+i)->name,(pt+i)->score);
	printf("平均成绩为:%.2f\n",ave);
}

void over_ave_data(STU *pt,int count,int b[])
{
	int i;
	printf("超过平均成绩的学生的信息:\n");
	printf("学号\t姓名\t成绩\n");
	for(i=0;i<count;i++)
	{
		printf("%d\t%s\t%.2f\n",(pt+b[i]-1)->num,(pt+b[i]-1)->name,(pt+b[i]-1)->score);
	}


}













