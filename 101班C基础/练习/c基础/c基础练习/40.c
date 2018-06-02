/**********************************
*file name:
*function:
*
*author:L-R-H
************************************/
#include<stdio.h>

void main()
{
	int i,j;
	for(i = 1;i <= 5;i++)
	{
		for(j = 1;j <= 5-i;j++)
			printf(" ");
		for(j = 1;j <= i;j++)
			printf("*");
		putchar('\n');
	}	

	for(i = 1;i <= 5;i++)
	{
		for(j = 1;j <= i-1;j++)
			printf(" ");
		for(j = 1;j <= 6-i;j++)
			printf("*");
		putchar('\n');
	}	

}
