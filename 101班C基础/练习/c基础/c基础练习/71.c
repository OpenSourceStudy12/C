/*****************************************************
*file name:
*function:编程实现由主函数输入m，n，按下述公式计算C n m的值。 
*        C n m＝n!/(m!*(n-m)!) 
*author:
*******************************************************/
#include<stdio.h>

int f1(int n);
int combination(int m,int n);

void main()
{
	int m,n,c;
	printf("输入m、n的值:\n");
	scanf("%d%d",&m,&n);
	c = combination(m,n);
	printf("C=%d\n",c);
}

int f1(int n)
{
	int t;
	if(n==1 || n==0)
		return 1;
	else if(n<0)
		return 0;
	else
		t = n*f1(n-1);

	return t;
}
int combination(int m,int n)
{
	int c;
	if(n<=m)
	{
		c = f1(m)/(f1(n)*(f1(m-n)));
		return c;
	}
	else 
	{
		printf("input error!\n");
		return 0;
	}

}
