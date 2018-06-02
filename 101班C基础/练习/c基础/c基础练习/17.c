/*
*file name:
*function :判断三个,输入三个整数，找出其中的最大值，并输出所有的最大值
×author: L-R-H
*
*/

#include<stdio.h>

void main()
{
	int a,b,c,max;
	printf("请输入三个整数:\n");
	scanf("%d%d%d",&a,&b,&c);
	max = a>b ? a:b;
	max = a>c ? a:c;
	printf("max = ");
	if(max == a)
		printf("a = ");	
	if(max == b)
		printf("b = "); 
	if(max == c)	
		printf("c = ");
	printf("%d\n",max);

}
