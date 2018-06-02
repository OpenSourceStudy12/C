/************************************************
*file name:
*function:从键盘输入一行字符序列，反转该字符序列并输出
*author:
**************************************************/
#include<stdio.h>
 void main()
{
	char s[100],*p,ch;
	int i=0;
	printf("请输入一串字符序列:\n");
	while(1)
	{
		if((ch=getchar()) != '\n')
			s[i++] = ch;
		else 
			break;
	}
	for(p = s,i -= 1;i >= 0;i--)
		printf("%c",p[i]);
	putchar('\n');


}
