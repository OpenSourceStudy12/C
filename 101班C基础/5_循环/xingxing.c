#include <stdio.h>
int main()
{
		int n,i,j,k;
		printf("请输入星星的大小:\n");
		while(1)
		{
				scanf("%d",&n);
				if(n%2==0)
				{
						printf("输入数据不合法，请重新输入:\n");
				}
				else
				{
						break;
				}
		}
		for(i=1;i<=n/2+1;i++)//控制行数
		{
				for(j=1;j<=n/2+1-i;j++)//控制空格
				{
						printf(" ");
				}
				for(k=1;k<=2*i-1;k++)
				{
						printf("*");
				}
				printf("\n");
		}
		for(i=1;i<=n/2;i++)
		{
				for(j=1;j<=i;j++)
				{
						printf(" ");
				}
				for(k=1;k<=n-2*i;k++)
				{
						printf("*");
				}
				printf("\n");
		}

}
