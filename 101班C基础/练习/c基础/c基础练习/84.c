/**********************************************************
*file name:
*function:
*author:
************************************************************/
#include<stdio.h>
typedef struct stu
{
	char name[15];
	float price;
	int date;
}STU;


int main()
{
	STU as;
	printf("请输入商品信息:名称、价格、生产日期\n");	
	scanf("%s%f%d",as.name,&as.price,&as.date);
	printf("商品名称\t价格\t生产日期:\n");
	printf("%s\t\t%.2f\t%d\n",as.name,as.price,as.date);
	return 0;

}
