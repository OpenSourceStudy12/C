/***********************************************************
*file name:
*function:
*author:
*************************************************************/
#include<stdio.h>

typedef struct stu
{
	int num;
	char name[15];
	float score;
}STU;

int main()
{
	int i;
	STU stu[5];
	for(i=0;i<5;i++)
	{
		printf("请输入第个%d学生信息,学号、姓名、成绩:\n",i+1);
		scanf("%d%s%f",&stu[i].num,stu[i].name,&stu[i].score);
	}
	printf("学号\t姓名\t成绩:\n");
	for(i=0;i<5;i++)
	{
		printf("%d\t%s\t%.2f\n",stu[i].num,stu[i].name,stu[i].score);
	
	}
	return 0;

}
