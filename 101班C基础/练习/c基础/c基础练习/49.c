/**********************************************
*file name:
*function:
*author:L-R-H
***********************************************/
#include<stdio.h>

void main()
{
	int i;
	float sum = 0,s = 100;
	for(i = 1;i <= 10;i++)
	{
		s /= 2;
		sum += 2*s;	
	}
	sum = sum -2*s +100;
	printf("共经过%.2f米,第十次反弹%.2f米\n",sum,s);
}
