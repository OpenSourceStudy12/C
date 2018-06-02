/******************************************************
*file name:
*function:
*author:
********************************************************/
#include<stdio.h>
#include<string.h>

void fun(char *p,int n);
void main()
{
	char s[20];
	printf("请输入一串字符序列:\n");
	gets(s);
	fun(s,strlen(s));
	puts(s);
}	

void fun(char *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i%2 != 0)
			*(p+i) = ' ';
	
	}

}
