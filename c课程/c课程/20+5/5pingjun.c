#include <stdio.h>
#define N 50
double fun(int arrow[],int number);
int main()
{
	int i,number;
	printf("请输入数组的个数:\n");
	scanf("%d",&number);
	int arrow[N];
	double averg;
	printf("请输入数组元素:\n");
	for(i=0;i<number;i++)
	{
		scanf("%d",&arrow[i]);
	}
	averg=fun(arrow,number);
	printf("arrow数组的平均值是：%lf",averg);
	return 0;
}
double fun(int arrow[],int number)
{
	int i,sum=0;
	double averg;
	for(i=0;i<number;i++)
	{
		sum=sum+arrow[i];
	}
	averg=(double)sum/number;
	return averg;
}
