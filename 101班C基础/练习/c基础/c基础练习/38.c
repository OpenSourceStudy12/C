/***************************************
*file name:
*function:
*每个苹果0.8元，第一天买2个苹果；从第二天开始，
*每天买前一天的2倍，直至购买的苹果个数达到不超
*过100个的最大值，编写程序求每天平均花多少钱
*author:L-R-H
***************************************/
#include<stdio.h>

void main()
{
	int num = 2,s = 2,i = 0;
	float price;
	while(num <= 100)
	{
		i++;
		s *= 2;
		num += s;
	}
	price = 0.8 * (num - s) / i;
	printf("每天平均花%.2f元\n",price);

}
