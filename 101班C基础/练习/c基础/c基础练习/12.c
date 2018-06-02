#include<stdio.h>

void main()
{
	char ch;
	printf("请输入一个字符:\n");
	scanf("%c",&ch);
	if(ch>='a'&&ch<='z')
		printf("该字符是小写字母\n");
	else
		printf("该字符不是小写字母\n");


}
