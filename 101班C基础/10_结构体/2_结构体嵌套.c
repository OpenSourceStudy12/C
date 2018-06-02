#include <stdio.h>
#include <string.h>

struct date
{
		int year;
		int month;
		int day;
};

struct product
{
		char name[32];
		float price;
		struct date d;
};

int main()
{
		struct product p1;
		printf("请输入商品名称：");
		scanf("%s",p1.name);
		printf("请输入商品价格：");
		scanf("%f",&p1.price);
		printf("请输入商品的生产日期：\n");
		scanf("%d-%d-%d",&p1.d.year,&p1.d.month,&p1.d.day);
		printf("p1.name=%s\n",p1.name);
		printf("p1.price=%.2f\n",p1.price);
		printf("日期:%d-%d-%d\n",p1.d.year,p1.d.month,p1.d.day);
}

