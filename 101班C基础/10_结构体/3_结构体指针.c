#include <stdio.h>
#include <string.h>
/*
1,结构体指针变量的定义：
struct 结构体名称  *指针变量名;

2,->    访问结构体成员
结构体指针变量->成员名


*/




struct stu
{
    int num;
	char name[32];
};

int main()
{
	struct stu  s1={1001,"xiaoqi"};
	struct stu  *p=NULL;
	p= &s1;
	(*p).num=1010;
	strcpy((*p).name,"laowang");
	printf("s1.num=%d,s1.name=%s\n",s1.num,s1.name);
	printf("p->num=%d,p->name=%s\n",p->num,p->name);
	return 0;
}
