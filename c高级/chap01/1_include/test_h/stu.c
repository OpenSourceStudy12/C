#include <stdio.h>

struct student
{
	int num;
};

void print_stu(struct student stu)
{
	printf("num = %d\n",stu.num);
}
