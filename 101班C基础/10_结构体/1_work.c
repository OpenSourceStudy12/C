/*
1,定义一个结构体存储一个员工的基本信息：所属部门、工号、姓名、性别
并打印结果



2,定义一个结构体存储一个商品的信息：商品名称、价格、生厂日期
并打印结果


4,定义一个结构体类型表示学生信息，信息内容：学号、姓名、成绩
要求：
（1）存储20个学生信息
（2）学号：1,2,3,。。。20
（3）姓名：no name
（4）成绩：0.00


*/
#include <string.h>
#include <stdio.h>
struct stu
{
		int num;
		char name[32];
//        char *p;
		float score;
};
int main()
{
		struct stu a[20];
		int i=0;
		for(i=0;i<20;i++)
		{
				a[i].num = i+1;
				strcpy(a[i].name,"no name");
				a[i].score=0.00;
		}
		printf("学号\t姓名\t\t成绩\n");
		for(i=0;i<20;i++)
		{
				printf("%d\t%s\t\t%.2f\n",a[i].num,a[i].name,a[i].score);
		}
        return 0;
}
/*
struct product
{
		char name[32];
		float price;
		int year;
		int month;
		int day;
};

int main()
{
		struct product p;
		scanf("%s%f%d%d%d",p.name,&p.price,&p.year,&p.month,&p.day);
		printf("商品名称：%s\n",p.name);
		printf("商品价格：%.2f\n",p.price);
		printf("生产日期:%d-%d-%d\n",p.year,p.month,p.day);
		return 0;
}
*/
/*
struct employee
{
		char part[32];
		int num;
		char name[32];
		char sex;
};

int main()
{
		struct employee  e1;
		scanf("%s%d%s",e1.part,&e1.num,e1.name);
		getchar();
		scanf("%c",&e1.sex);
		printf("e1.part=%s,e1.num=%d,e1.name=%s,e1.sex=%c\n",e1.part,e1.num,e1.name,e1.sex);
		return 0;
}
*/
