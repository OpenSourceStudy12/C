/**************************************
*file name:
*function:1 2 3 4可以组成多少个互不相同
*且无重复数字的三位数?
*author:
***************************************/
#include<stdio.h>

void main()
{
	int i,j,k,n=0;
	for(i = 1;i <= 4;i++)
	{
		for(j = 1;j <= 4;j++)
		{
			if(j == i)
				continue;
			for(k = 1;k <= 4;k++)
			{
				if(k == i || k == j)
					continue;
				n++;
				printf("%4d",i*100 + j*10 + k);

			}

		
		}
	
	}
	printf("\n共有%d种组合\n",n);
	

}
