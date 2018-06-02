#include<stdio.h>

int main()
{
	int a,b;
	printf("请输入一个整数:\n");
	scanf("%d",&a);
	b = a % 10;
	if(b == 3)
		printf("该数个位数是3\n");
	else
		printf("该数个位不数是3\n");

	return 1;
}
