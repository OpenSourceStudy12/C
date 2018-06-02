/************************************
*file name:
*function:输入一个整数n,求 1+1/2+1/3+...1/n之和
*author:L-R-H
************************************/
#include<stdio.h>

void main()
{
	int n,i;
	float sum = 0,k;
	printf("请输入一个整数:\n");
	scanf("%d",&n);
	for(i = 1;i <= n;i++)
	{

		sum += 1.0 / (float)i;	
	}
	printf("1+1/2+1/3+....+1/%d = %.2f\n",n,sum);
}
