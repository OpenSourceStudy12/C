/******************************************
*file name:
*function:设计一个函数，将一个字符串反转
*author:
********************************************/
#include<stdio.h>
void fanzhuan(char *ch);

void main()
{
	char ch[100];
	printf("请输入一行字符串:\n");
	gets(ch);
	fanzhuan(ch);
	puts(ch);
}


void fanzhuan(char *ch)
{
	char *sh,temp;
	int n=0;
	while(*(ch+n) != '\0')
	{
		n++;
	}
	for(sh=ch+n-1;ch<sh;ch++,sh--)
	{
		temp=*ch;
		*ch=*sh;
		*sh=temp;
	}
}
