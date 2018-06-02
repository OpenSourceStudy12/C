/***************************************************
*file name:
*function:
*author:
*****************************************************/
#include<stdio.h>
void main()
{
	int i,s=1,sum=0;
	for(i=0;i<10;i++)
	{
		sum += s;
		s = 2*(s +1);
	
	}
	printf("sum = %d\n",sum);
}

