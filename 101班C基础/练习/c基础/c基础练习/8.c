#include<stdio.h>

int main()
{
	float num1,num2;
	int num3,num4;
	printf("请输入四个操作数:\n");
	scanf("%f%f%d%d",&num1,&num2,&num3,&num4);
	printf("%.2f+%.2f= %.2f%.2f-%.2f= %.2f,%.2f*%.2f= %.2f,%.2f/%.2f= %.2f,%d%%%d= %d\n",
			num1,num2,num1+num2,num1,num2,num1-num2,
			num1,num2,num1*num2,num1,num2,num1/num2,
			num3,num4,num3%num4);
//	printf("请输入一个小写字符：\n");
//	printf("其对应大写字符是：%c\n",getchar()-32);
//	printf("其对应大写字符是：");
//	ch = getchar()-32;
	printf("%f/%f= %f",5.0,6.7,5.0/6.7);
	putchar(7);
	putchar('\n');
	
	return 1;

}
