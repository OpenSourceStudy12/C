/******************************************
*file name:
*function:加密字符串
*author:L-R-H
********************************************/
#include<stdio.h>

void main()
{
	char ch;
	printf("请输入一串字符串\n");
//	getchar();
	while((ch = getchar()) != '\n')
	{
		putchar(ch+32);
	}
	putchar('\n');

}

