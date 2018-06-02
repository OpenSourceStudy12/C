/************************************
*file name:
*function:判断素数
*author:L-R-H
************************************/
#include<stdio.h>

void main()
{
	int i,d,flag = 0;
	printf("请输入一个整数:\n");
	scanf("%d",&d);
	if(d>1)
	{	
		for(i = 2;i < d;i++)
		{
			if(d%i == 0)
			{
				flag = 1;
				break;
			}
		}
		if(flag)
			printf("质数\n");
		else 
			printf("素数\n");
	}
	else
		printf("质数\n");
} 
