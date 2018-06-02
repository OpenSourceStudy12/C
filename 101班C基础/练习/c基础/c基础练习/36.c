/**********************************
*file name:
*function:
*author:L-R-H
***********************************/
#include<stdio.h>
void main()
{
	int m,n,i,result = 1;
	printf("请输入两个整数:\n");
	scanf("%d%d",&m,&n);
	for(i = 1;i <= n;i++)
	{
		result *= m;
	
	}
	printf("%d ^ %d = %d\n",m,n,result);
 
}
