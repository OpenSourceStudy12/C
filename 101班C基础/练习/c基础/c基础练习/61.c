/**********************************************
*file name:
*function:
*author:
************************************************/
#include<stdio.h>
void main()
{
	char s[100];
	char *p,*q,ch;
	int i=0,flag = 0;
	printf("请输入一串字符序列:\n");
	while(1)
	{
		if((ch=getchar()) != '\n')
			s[i++] = ch;
		else
			break;	
	
	}
	for(p=s,q=s+i-1;p < q;p++,q--)
	{
		if(*p != *q)
		{
			flag =1;
			break;
		}
	
	}
	if(flag)
		printf("不是回文序列\n");
	else
		printf("是回文序列\n");

}
