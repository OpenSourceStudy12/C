#include<stdio.h>

void main()
{
	int num;
	printf("请输入一个整数:\n");
	scanf("%d",&num);
	if((num%3==0)&&(num%5==0))
		printf("该数能被3和5整除\n");
	else
		printf("该数不能被3和5整除\n");

}
