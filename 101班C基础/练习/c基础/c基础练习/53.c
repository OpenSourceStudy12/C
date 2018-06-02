/****************************************
*file name:
*function:从键盘输入一行字符序列，统计
*有效字符个数，并将该字符序列存储于数组中输出
*author:
*******************************************/
#include<stdio.h>

void main()
{
	char ch,c[100];
	int n=0,i;
	printf("输入一串字符序列:\n");
	while((ch=getchar()) != '\n')
	{
		c[n] = ch;
		n++;

	}
	for(i=0;i<n;i++)
		printf("%c",c[i]);
	printf("共有%d个有效字符\n",n);

}
