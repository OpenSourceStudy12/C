/*********************************************************
*file name:
*function:定义一个结构体存储5个员工的家庭信息：
*姓名、人口数、家庭住址
*要求：
*（1）数据动态输入
*（2）打印结果
*（3）以上操作用指针实现
*author:
*********************************************************/
#include<stdio.h>
typedef struct worker
{
//	char name[15];
	char *name;
	int num;
	char add[20];

}WOK;

/*
int main()
{
	int i;
	WOK work[5],*pw;
	pw=work;
	for(i=0;i<5;i++)
	{
		printf("请输入%d个员工信息:姓名、人口数、住址:\n",i+1);
		scanf("%s%d%s",(pw+i)->name,&(pw+i)->num,(pw+i)->add);
	}

	printf("姓名\t\t人口数\t\t住址\n");
	for(;pw<work+5;pw++)
	{
		printf("%s\t\t%d\t\t%s\n",pw->name,pw->num,pw->add);
	}
}
*/

int main()
{
	char ch[20];
	WOK wok,*pw;
	pw=&wok;
	pw->name=ch;
	printf("请输入姓名:\n");
	scanf("%s",(*pw).name);
	printf("%s",pw -> name);
}	





