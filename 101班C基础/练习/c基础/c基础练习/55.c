/****************************************
*file name:
*function:从键盘输入一个字符序列，输出该字符序列的倒置
*author:
*****************************************/
#include<stdio.h>
#include<string.h>
void main()
{
	char c[100],ch;
	int i,k=0;
	printf("请输入一串字符序列:\n");
/*	while((ch=getchar()) != '\n') 
	{
		c[k++] = ch;
		
	}
*/	gets(c);
	putchar('\n');
	for(i=strlen(c)-1;i>=0;i--)
	{
		printf("%c",c[i]);
	
	}
	putchar('\n');
	

}
