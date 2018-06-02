/*******************************************
*file name:
*function:求 2/1 3/2 5/3 8/5 13/8 21/13 前20项之和
*author:L-R-H
********************************************/
#include<stdio.h>

void main()
{
	int i,m,n,t;
	float sum = 0;
	for(i = 1;i <= 20;i++)	
	{
		m = 2,n = 1;
		sum += (float)m/n;
		t = n;
		n = m;
		m = n+t;
	}
	printf("2/1 + 3/2 + 5/3 +... = %.2f\n",sum);

}

