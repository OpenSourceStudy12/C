#include<stdio.h>
 
void main()
{
/*	int num,a,b,c,d,e;
	printf("请输入一个整数:\n");
	scanf("%d",&num);
	a = num / 10000;
	b = num % 10000 /1000;
	c = num % 1000 / 100;
	d = num % 100 / 10;
	e = num % 10;
	if((a==e)&&(b==d))
		printf("该数是回文数\n");
	else
		printf("该数不是回文数\n");
*/
	char ch[6];
	printf("请输入一个五位数:\n");
	gets(ch);
	if((ch[0]==ch[4])&&(ch[1]==ch[3]))
		printf("该数是回文数\n");
	else
		printf("该数不是回文数\n");


}
