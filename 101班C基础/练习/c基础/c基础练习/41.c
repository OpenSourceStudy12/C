/****************************
*file name:
*function:打印菱形
*author:L-R-H
*****************************/
#include<stdio.h>

void main()
{
	int i,j,n;
	printf("请输入一个奇数:\n");
	scanf("%d",&n);
	for(i = 1;i <= n;i++)
	{
		if(i <= (n+1)/2)
		{
			for(j = 1;j <= (n+1)/2-i;j++)
				printf(" ");
			for(j = 1;j <= 2*i-1;j++)
				printf("*");
//			for(j = 1;j <= (n+1)/2-i;j++)
//				printf(" ");
		}
		else
		{
			for(j = 1;j <= i-(n+1)/2;j++)
				printf(" ");
			for(j = 1;j <= 2*(n-i)+1;j++)
				printf("*");
//			for(j = 1;j <= i-(n+1)/2;j++)
//				printf(" ");

		
		}
		putchar('\n');
	}
	

}
