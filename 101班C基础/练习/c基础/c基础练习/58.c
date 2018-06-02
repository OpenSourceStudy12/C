/***************************************************
*file name:
*function:定义一个数组存储5种商品的价格，数据从键盘输入，
*输出每种商品的价格
*author:
****************************************************/
#include<stdio.h>

void main()
{
	float price[5];
	float *p = price;
	int i,j=0;
	printf("输入五种商品价格\n");
	for(i=0;i<5;i++)
	{
		scanf("%f",p+i);
	}
	printf("五种价格为:\n");
	while(j<5)
	{
		printf("%.2f\n",p[j]);
		j++;	
	}

}
