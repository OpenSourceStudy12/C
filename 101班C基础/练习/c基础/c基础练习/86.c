/***************************************************
*file name:
*function:使用嵌套结构体存储学生信息：
*姓名、学号、成绩（语文、数学、英语）、出生日期（年、月、日）
*要求：
*（1）存储5个学生的基本信息
*（2）数据动态输入
*（3）打印结果
*author:
*****************************************************/
#include<stdio.h>
typedef struct date
{
	int year;
	int month;
	int day;
}DATA;

typedef struct score
{
	float chinese;
	float math;
	float English;
}SCORE;

typedef struct stu
{
	int num;
	char name[15];
	SCORE grade;
	DATA time;
}STU;

int main()
{
	int i;
	STU st[5];

	for(i=0;i<5;i++)
	{
		printf("请输入第%d个学生信息学号、姓名、成绩、出生日期:\n",i+1);
		scanf("%d%s%f-%f-%f%d-%d-%d",&st[i].num,st[i].name,&st[i].grade.chinese,&st[i].grade.math,&st[i].grade.English,&st[i].time.year,&st[i].time.month,&st[i].time.day);
	
	}

	printf("学号\t姓名\t语文成绩\t数学成绩\t英语成绩\t出生日期\n");
	for(i=0;i<5;i++)
	{
		printf("%d\t%s\t%.2f\t\t%.2f\t\t%.2f\t\t%d-%d-%d\n",st[i].num,st[i].name,st[i].grade.chinese,st[i].grade.math,st[i].grade.English,st[i].time.year,st[i].time.month,st[i].time.day);
	
	}

	return 0;

}














