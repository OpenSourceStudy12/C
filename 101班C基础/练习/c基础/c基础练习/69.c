/*************************************************
*file name:
*function:
*author:
****************************************************/
#include<stdio.h>
int my_pow(int x,int y);

void main()
{

	int x,y;
	printf("请输入两个整数\n");
	scanf("%d%d",&x,&y);
	printf("%d^%d = %d\n",x,y,my_pow(x,y));

}

int my_pow(int x,int y)
{
	int i,result=1;
	for(i=0;i<y;i++)
	{
		result *= x;
	
	}
	return result;

}
