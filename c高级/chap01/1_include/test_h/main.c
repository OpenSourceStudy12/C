#include <stdio.h>
//#include "stu.h"

void print_stu(struct student);

int main()
{
	struct student stu1;
	stu1.num=10;
	print_stu(stu1);
}
