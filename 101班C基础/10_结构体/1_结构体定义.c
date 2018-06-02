/*
1,结构体类型的定义：
struct 结构体名称
{
		数据类型   成员1;
		数据类型   成员2;
		...
		数据类型   成员n;
};


2,结构体变量的定义：
struct  结构体名称  变量名;


3,.    结构体成员访问运算符
结构体变量.成员名
*/
#include <stdio.h>

struct stu
{
		int num;//学号
		char name[20];//姓名
		float  score;//成绩
}s,s5={1002};  //定义结构体类型    不申请空间



struct 
{
		int num;
		char name[20];

}ss1,ss3;

int main()
{
		struct stu s2[5];
		int i=0;
		for(i=0;i<5;i++)
		{
				printf("请输入第%d个学生的信息：\n",i+1);
				scanf("%d%s%f",&s2[i].num,s2[i].name,&s2[i].score);
		}
		printf("学号\t姓名\t成绩\n");
		for(i=0;i<5;i++)
		{
				printf("%d\t%s\t%.2f\n",s2[i].num,s2[i].name,s2[i].score);
		}
}
/*
int main()
{
		struct stu  s1;
		scanf("%d%s%f",&s1.num,s1.name,&s1.score);
		printf("s1.num=%d,s1.name=%s,s1.score=%.2f\n",s1.num,s1.name,s1.score);
}
*/
/*
int  main()
{
		struct stu  s1;//定义结构体变量   申请空间
        struct stu  s2={1001,"xiaoqi",99.9};//结构体变量的初始化
	   // struct  stu  s3={1001};
	//	struct stu s4={};
	    s2.num=1002;
		printf("s2.num=%d,s2.name=%s,s2.score=%.2f\n",s2.num,s2.name,s2.score); 
		printf("szieof(s1)=%d\n",sizeof(s1));
}
*/


