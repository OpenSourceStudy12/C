#include <stdio.h>
#include <math.h>
double fun(double a[]);
int main()
{
	int i;
	double a[10],bzc;
	printf("请输入10个数；");
	for(i=0;i<10;i++)
	{
	scanf("%d",&a[i]);	
	}
	
	bzc=fun(a);
	printf("标准差：%4.2lf\n",bzc);
	return 0;
}
double fun(double a[])
{
	double bzc,averg,sum=0,b[10],sum2=0;
	int i;
	for(i=0;i<10;i++)
	{
		sum+=a[i];
	}
	averg=sum/10;
	for(i=0;i<10;i++)
	{
		b[i]=pow((a[i]-averg),2);
		sum2+=b[i];
	}
	bzc=sqrt(sum2);
	return bzc;
}
