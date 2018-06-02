#include <stdio.h>
int func(int a,int b);
int main()
{
	int a,b,c;
	printf("请输入一个两位数的整数：");
	scanf("%d",&a);
	printf("请再输入一个两位数的整数：");
	scanf("%d",&b);
	c=func(a,b);
	printf("c=%d\n",c);
	return 0;
}
int func(int a,int b)
{
	int c;
	c=a/10*1000+b/10*100+(a%10)*10+b%10;
	return c;
}
