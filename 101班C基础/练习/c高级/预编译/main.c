#include<stdio.h>
#include"fun.h"

int main()
{
	char *p,a[100],b[100];
	printf("请输入一行字符串\n");
	gets(a);
	str_deal(a,b);
	printf("变换后字符串为:\n");
	puts(b);
	
	return 0;
}
