#include <stdio.h>
#define STU_NUM 5
#define NAME_LEN 32

typedef struct student
{
	int num;
	char name[NAME_LEN];
	int age;
}STU,*p_stu; 
p_stu findByAge(STU s[],int num)
{
	int i;
	p_stu p=s;
	for(i=0;i<num;i++)
	{
		if(p->age>s[i].age)
			p=&s[i];
	}
	return p;
}
int main()
{	
	struct student *pmin=NULL;
	STU stu[STU_NUM]={{1001,"aaa",45},{1002,"bbb",23},{1003,"ccc",19},{1004,"ddd",19},{1005,"eee",26}};
	pmin=findByAge(stu,STU_NUM);
	printf("年龄最小信息如下:\n");
	printf("学号 %d\t",pmin->num);
	printf("姓名 %s\t",pmin->name);
	printf("年龄 %d\t\n",pmin->age);

}
