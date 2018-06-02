/*
*
*
* file name:
* author:L-R-H
* functiion:判断三角形类型
*
*
*/
#include<stdio.h>

void main()
{
	int a,b,c;
	printf("请输入三角形三条边长:\n");
	scanf("%d%d%d",&a,&b,&c);
	if(a+b > c && a+c >b && b+c >a)
	{
		if(a == b || a == c || b == c)
		{	
			if(a == b && b == c)
			{
				printf("该三角形是等边三角形\n");
			}
			else if(a == b && a*a + b*b == c*c || 
					a == c && a*a + c*c == b*b 
					||c == b && c*c + b*b == a*a)
			{
				printf("该三角形是等腰直角三角形\n");
		
			}
			else
				printf("该三角形是等腰三角形\n");	
		}	
		else if(a*a + b*b == c*c || 
			a*a + c*c == b*b 
			||c*c + b*b == a*a)
		{
			printf("该三角形是直角三角形\n");
		
		}
		else 
			printf("该三角形是普通三角形\n");
	}
	else 
		printf("不是三角形\n");


}








