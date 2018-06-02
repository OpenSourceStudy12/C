#include<stdio.h>

void main()
{
	float price1,price2,price3;
	float p,sum;
	printf("请输入三种商品价格:\n");
	scanf("%f%f%f",&price1,&price2,&price3);
	p = price1 + price2 + price3;
	if((price1>50)||(price2>50)||(price3>50)||(p>100))
	{
		sum = p * 0.97;
		printf("折扣率3%%的总价是:%.2f\n",sum);
	
	}
	else 
	{
		sum = p;
		printf("总价是:%.2f\n",sum);
	}
}


