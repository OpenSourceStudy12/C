/*****************************************
*file name:
*function:循环统计输入整数个数
*author:L-R-H
******************************************/
#include<stdio.h>

void main()
{
	int x,i,j,sum = 0;
	float ave;
	char ch,c;
//	printf("请输入多个整数\n");
//	scanf("%d",&x);
//	printf("%d",x);
	do
	{
		i = j = 0;
		printf("请输入多个整数\n");
		scanf("%d",&x);
		while(x)
		{
			sum += x;
			i++;
			scanf("%d",&x);
		}
		while((c = getchar()) != '\n');
		printf("输入整数个数为%d个,平均值为%.2f\n",i,(float)sum/i);
//		getchar();
//		getchar();
		printf("是否继续统计整数?(y or n)\n");
	}while((ch = getchar()) == 'y' || (ch = getchar()) =='Y');

}
