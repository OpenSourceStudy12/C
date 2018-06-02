#include <stdio.h>
int main()
{
		int a[4][2]={12,4,5,6,23,45,8,9};
		int i,j;
		for(i=0;i<4;i++)//外层数组每个元素的起始地址
		{
				printf("a+%d=%p\n",i,a+i);
		}
	    for(i=0;i<4;i++)
		{
				printf("&a[%d]=%p\n",i,&a[i]);
		}

		for(i=0;i<4;i++)//内层每个元素的起始地址
		{
				for(j=0;j<2;j++)
				{
						printf("a[%d]+%d=%p\n",i,j,a[i]+j);
				}
		}
        for(i=0;i<4;i++)
		{
				for(j=0;j<2;j++)
				{
						printf("&a[%d][%d]=%p\n",i,j,&a[i][j]);
				}
		}

		for(i=0;i<4;i++)
		{
				for(j=0;j<2;j++)
				{
						printf("%d ",a[i][j]);
				}
				printf("\n");
		}
}

/*
int main()
{
		int a[4][2]={12,4,5,6,8,90,6,34};
		int i,j;
		for(i=0;i<4;i++)
		{
				for(j=0;j<2;j++)
				{
						printf("&a[%d][%d]=%p\n",i,j,&a[i][j]);
				}
		}

		for(i=0;i<4;i++)
		{
				for(j=0;j<2;j++)
				{
						printf("a[%d][%d]=%d\n",i,j,a[i][j]);
				}
		}
}
*/
