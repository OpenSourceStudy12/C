#include"func.h"
//#include<stdio.h>

void print_binary(int x)
{
	int b[32];
	int i=0,j;
	while(x)
	{ 
		b[i++]=x % 2;			         x /= 2;
	}

	for(j=i-1;j>=0;j--)
		printf("%-2d",b[j]);

	putchar('\n');

/*
        b[0] = x % 2;
	while(x)
	{ 
		x /= 2;
		b[i++]=x % 2;			
	}
*/

}
