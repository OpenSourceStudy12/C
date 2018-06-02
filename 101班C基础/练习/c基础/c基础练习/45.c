/*******************************************
*file name:
*function:统计输入字符个数
*author:L-R-H
********************************************/
#include<stdio.h>

void main()
{
/*	int i = 0,k,sum;
	float ave;
	printf("请输入一串整数:\n");
	while(k != 0)
	{
		i++;
		sum += k;
                scanf("%d",&k);
	}
	ave = (float)sum / i;
	printf("sum = %d ave = %.2f",sum,ave);
*/
	int x;
	char i,ans;
	ans = 'y';
	do
	{
		getchar();
		x = 0;
		printf("请输入字符序列:\n");
		do
		{
			i = getchar();
			x++;
		}while(i != '\n');
		printf("输入的字符数是:%d\n",--x);
		printf("是否需要输入更多的字符序列?(y or n)\n");
		ans = getchar();
	}while(ans == 'Y' || ans == 'y');
	
}
