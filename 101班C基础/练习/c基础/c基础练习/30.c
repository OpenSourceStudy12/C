/****************************************
×file name:
*function:
*author:L-R-H
****************************************/
#include<stdio.h>
void main()
{
	int i = 1,sum = 0;
	while(i <= 100)
	{
		if(i%2 == 0)
			sum +=i;
		i++;
	}
	printf("result is %d\n",sum);
}
