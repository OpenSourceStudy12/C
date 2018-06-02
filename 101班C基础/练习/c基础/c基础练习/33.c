/******************************
*file name:
*function:
*author:L-R-H
******************************/

#include<stdio.h>

void main()
{
	int sum = 0,i;
	for(i = 1;i <= 100;i++)
	{
		if(i%3 == 0 && i%5 == 0)
		{
			sum += i;
			printf("%d ",i);
		}
	}
	printf("\nsum = %d\n",sum);

}
