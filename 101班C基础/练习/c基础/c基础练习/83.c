/******************************************************
*file name:
*function:
*author:
******************************************************/
#include<stdio.h>

struct stu
{
	int num;
	char name[20];
	char sex[5];
	char dep[10];
};

int main()
{
	struct stu worker;
	printf("请输入员工信息:工号、姓名、性别、部门\n");
	scanf("%d%s%s%s",&worker.num,worker.name,worker.sex,worker.dep);
	printf("工号\t姓名\t性别\t部门\n");
	printf("%d\t%s\t%s\t%s\n",worker.num,worker.name,worker.sex,worker.dep);


}
