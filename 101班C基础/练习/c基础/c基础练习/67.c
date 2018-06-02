/**********************************************
*file name:
*function:产生1--31之间的随机数
*author:
**********************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int x[7],i,j;
	srand(time(NULL));
	for(i=0;i<7;i++)
	{
		x[i] = rand()%31+1;
		for(j=0;j<i;j++)	
		{
			if(x[i] == x[j])
			{	
				x[i] = rand()%31+1;
				j=-1;

			}
		}
	}
	for(i=0;i<7;i++)
		printf("%d\n",x[i]);
	putchar('\n');

}
