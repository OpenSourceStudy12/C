#include<stdio.h>

int main()
{
	float banna,m_guo;
	int b=3,m=2;
	float price;
	printf("请输入香蕉和芒果的单价:\n");
	scanf("%f %f",&banna,&m_guo);
	price = b * banna + m * m_guo;
	printf("总价是:%.2f\n",price);
	printf("变量地址是:%p\n",price);
	printf("总价是:%e\n",price);
	return 1;
}
