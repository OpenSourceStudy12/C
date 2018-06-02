/*************************************
*file name:
*function:定义一个数组存储6个整数，分别找出最小值和最大值的下标
*author:
***************************************/
#include<stdio.h>
void main()
{
	int num[6],*p = num;
	int i,j,max,min;
	printf("输入六个整数\n");
	for(j=0;j<6;j++)
	{
		scanf("%d",p+j);
	
	}
	for(i=max=min=0;i < j;i++)
	{
		if(p[max] < p[i])	
			max = i;
		else if(p[min] > p[i])
			min = i;
	}
	printf("max = %d min = %d\n",max,min);
}
