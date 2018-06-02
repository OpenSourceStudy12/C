/***********************************
*file name:
*function:求最大公约数，最小公倍数
*author:L-R-H
************************************/
#include<stdio.h>

void main()
{
	int x,y,m,n,t;
	printf("请输入两个整数m,n\n");
	scanf("%d%d",&m,&n);
	if(m<n)
	{
		t = m;
		m = n;
	        n = t;	
	}
	x = m;
	y = n;
	while(m%n != 0)
	{
		t = m;
		m = n;
		n = t%n;
	}
	printf("%d,%d的最大公约数是%d,最小公倍数是%d\n",x,y,n,n*(x/n)*(y/n));

}
