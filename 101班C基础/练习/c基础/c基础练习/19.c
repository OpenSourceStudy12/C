/*
*file name:
*function:计算器
*author:
*/
#include<stdio.h>

void main()
{
	int a,b,result;
	char option;
	int flag = 0;
	printf("请输入两个数字\n");
	scanf("%d%d",&a,&b);
	getchar();
	printf("请输入运算符:\n");
	scanf("%c",&option);
	switch(option)
	{
		case '+' : 
			result = a + b;
		//	printf("result is %.3f",result);
			break;
		case '-' : 
			result = a - b;
		//	printf("result is %.3f",result);
			break;
		case '*' : 
			result = a * b;
		//	printf("result is %.3f",result);
			break;
		case '/' : 
			result = a / b;
		//	printf("result is %.3f",result);
			break;
		case '%' : 
			result = a % b;
        	//	printf("result is %.3f",result);
			break;
		default : 
	        //	printf("result is error",);
			flag = 1;
			break;
	
	
	}

	if(flag == 0)
		printf("result is %d\n",result);
	else
		printf("error\n");
}
