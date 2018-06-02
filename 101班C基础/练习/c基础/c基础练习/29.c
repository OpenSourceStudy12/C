/***********************************
*file name:
*function:
*author:L-R-H
************************************/
#include<stdio.h>
void main()
{
	int num,sum = 0,i = 1;
	printf("请输入一个整数:\n");
	scanf("%d",&num);
/*	while(i <= num)
	{
		sum += i;
		i++;		       		
	}*/

	do
	{
		sum += i;
		i++;
	}while(i<= num);

	printf("result is %d\n",sum);	
}
