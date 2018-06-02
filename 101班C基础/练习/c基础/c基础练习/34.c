/************************************
*file name:
*function:输入一个数，输出其反转后的整数
*author:L-R-H
*************************************/

#include<stdio.h>

void main()
{
	int x,m,i = 0,j = 0;
	printf("请输入一个整数:\n");
	scanf("%d",&x);
	for(;x;)
	{
		i++;
		m = x%10;
	        x = x/10;	
		if(m == 0)
			j++;
		if(i == j)
			continue;

		printf("%d",m);
	}
	putchar('\n');
}
