#include <stdio.h>
struct stu
{
		int num;
		char name[32];
};

struct stu  get_stu_info()
{
		struct stu temp;
		printf("请输入学生学号：\n");
		scanf("%d",&temp.num);
		printf("请输入学生姓名:\n");
		scanf("%s",temp.name);
		return temp;
};


void pri_stu_info(struct stu s)
{
		printf("学号\t\t姓名\n");
		printf("%4d\t%10s\n",s.num,s.name);
}

void mod_stu_info(struct stu *s)
{
		printf("请输入修改学号：");
		scanf("%d",&s->num);
		printf("请输入修改姓名:");
		scanf("%s",s->name);
}

int main()
{
		struct stu s1={1001,"xiaoqi"};
		struct stu s2;
		s2=s1;
//		s2=get_stu_info();
        mod_stu_info(&s1);
		pri_stu_info(s1);
//		printf("s2.num=%d,s2.name=%s\n",s2.num,s2.name);
}
