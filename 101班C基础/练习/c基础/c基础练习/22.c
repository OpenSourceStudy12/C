/*************************************
*file name:
*function:
*author:L-R-H
**************************************/
#include<stdio.h>

void main()
{
	int n = 1;
	while(n <= 100)
	{
		printf("%4d",n);
	        if(n%8 == 0)
                	putchar('\n');
	        n++;
	}
        putchar('\n');

}
