/**************************************
*file name:
*function:
*author:
***************************************/
#include<stdio.h>
#include<math.h>
double sqrt(double x);

void main()
{
	int i,n=0,x,y;
	for(i=1;i<= 65535;i++)
	{	
		x = sqrt(i+100);
		if(x*x != i+100)
			continue;
	
		else
		{
			y = sqrt(i+268);
			if(y*y != i+268)
				continue;
			else
			{	
				printf("%6d",i);
				n++;
			}
		
		}	
	}
	printf("\n共有%d\n个",n);
}


