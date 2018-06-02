/***************************************************
*file name:
*function:
*author:
****************************************************/
#include<stdio.h>
#include<string.h>
void fun(char *p,char *q);

void main()
{
	char s[100],t[100];
	printf("请输入一串字符序列:\n");
	gets(s);
	fun(s,t);
	puts(t);
}

void fun(char *p,char *q)
{
	while(*p != '\0')
	{
		if(*p != ' ')
		{
			*q++ = *p;
		}
		p++;
	}
	*q = '\0';
}
