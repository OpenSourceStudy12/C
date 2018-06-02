#include<stdio.h>
struct stu
{
	int num;
	char name[20];
	char sex[5];
	char department[10];
};

int main()
{
	struct stu student[3],*ps;
	ps=student;
	int i;
//	printf("请输入学生的信息:\n");
	for(i=0;i<3;i++)
	{
		printf("请输入第%d个学生的学号、姓名、性别、部门:\n",i+1);
		scanf("%d",&ps[i].num);
		scanf("%s%s%s",ps[i].name,ps[i].sex,ps[i].department);
	
	}
	//ps=student+1;
	printf("学号\t姓名\t性别\t部门\n");
	for(i=0;i<3;i++)
	{
		printf("%d\t",ps[i].num);
		printf("%s\t",ps[i].name);
		printf("%s\t",ps[i].sex);
		printf("%s\t\n",ps[i].department);
	}


}



































