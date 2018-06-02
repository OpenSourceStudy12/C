/*********************************
*file name:
*function:
*author:L-R-H
*********************************/

#include<stdio.h>

void main()
{
	int n,i=0;
	for(n = 0;n <= 100;n++)
	{
		if(n%2 != 0)
		{
			printf("%4d",n);
	                i++;
		}
		if(i%8 == 0)
			putchar('\n');
	}
	putchar('\n');
}
