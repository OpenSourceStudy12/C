/*
1,使用嵌套结构体存储学生信息：
姓名、学号、成绩（语文、数学、英语）、出生日期（年、月、日）
要求：
（1）存储5个学生的基本信息
（2）数据动态输入
（3）打印结果

2,定义一个结构体存储5个员工的家庭信息：
姓名、人口数、家庭住址
要求：
（1）数据动态输入
（2）打印结果
（3）以上操作用指针实现
->
*/

#include <stdio.h>
struct emplyee
{
		char name[32];
		int popu_num;
		char adr[64];
};

int main()
{
		struct emplyee a[5];
		struct emplyee *p=a;//p  =&a[0]
        int i=0;
		while(p<a+5)
		{
				printf("请输入第%d个员工的姓名：",i+1);
				scanf("%s",p->name);
				printf("请输入第%d个员工的家庭人数：",i+1);
				scanf("%d",&p->popu_num);
				getchar();
				printf("请输入第%d个员工的地址：",i+1);
				scanf("%s",p->adr);
				p ++;
				i ++;
		}

		for(p=&a[0],i=0;i<5;i++)
		{
             printf("%10s\t%2d\t%10s\n",p[i].name,p[i].popu_num,p[i].adr);
		}
		return 0;

}
/*
struct score
{
		float chinese;
		float math;
		float english;
};

struct date
{
		int year;
		int month;
		int day;
};

struct stu
{
		char name[32];
        int num;
		struct score grade;
		struct date bir;
};

int main()
{
		struct stu s[5];
		int i=0;
		for(i=0;i<5;i++)
		{
				printf("请输入第%d个学生的姓名:\n",i+1);
				scanf("%s",s[i].name);
				printf("请输入第%d个学生的学号:\n",i+1);
				scanf("%d",&s[i].num);
				printf("请输入第%d个学生的成绩(语文、数学、英语):\n",i+1);
				scanf("%f%f%f",&s[i].grade.chinese,&s[i].grade.math,&s[i].grade.english);
				printf("请输入第%d个学生的出生日期:\n",i+1);
				scanf("%d-%d-%d",&s[i].bir.year,&s[i].bir.month,&s[i].bir.day);
		}
		for(i=0;i<5;i++)
		{
				printf("%s\t%d\t%.2f\t%.2f\t%.2f\t%d-%d-%d\n",s[i].name,s[i].num,s[i].grade.chinese,s[i].grade.math,s[i].grade.english,s[i].bir.year,s[i].bir.month,s[i].bir.day);
		}
}

*/


