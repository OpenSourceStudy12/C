/*****************************************
*file name:
*function:二位数组地址
*author:
******************************************/
#include<stdio.h>
#define M 4
#define N 2
void main()
{
	double a[M][N];
	int i,j;
	for(i=0;i<M;i++)  //外层 a+1
	{
		printf("a+%d=%p\n",i,a+i);
	}
	putchar('\n');	
	for(i=0;i<M;i++)  //外层 &a[i]
		printf("&a[%d] = %p\n",i,&a[i]);
	putchar('\n');
	for(i=0;i<M;i++) // 内层 a[i]
	{
		printf("a[%d] = %p\n",i,a[i]);
	
	}
	putchar('\n');
	for(i=0;i<M;i++) //内层 &a[i][j]
	{
		for(j=0;j<N;j++)
		{
			printf("&a[%d][%d] = %p\n",i,j,&a[i][j]);
		
		}
	
	}
	putchar('\n');
	for(i=0;i<M;i++)  //内层 a[i] + j 
	{
		for(j=0;j<N;j++)
		{
			printf("a[%d]+%d = %p\n",i,j,a[i]+j);
		
		}	
	}
	putchar('\n');
	for(i=0;i<M;i++)  //内层 &a[i] + j 
	{
		for(j=0;j<N;j++)
		{
			printf("&a[%d]+%d = %p\n",i,j,&a[i]+j);
		
		}	
	}
	putchar('\n');
	
}













