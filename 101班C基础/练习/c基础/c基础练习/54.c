/*******************************************
*file name:
*function:从键盘输入一行字符序列，统计'a'-'z'
*每个字符出现的次数，并且存储与数组b[26]
*author:
********************************************/
#include<stdio.h>

void main()
{
	int num[26]={0},k;
	printf("请输入一串字符\n");
	char ch;
	scanf("%c",&ch);
	while(ch != '\n')
	{
		if('a' < ch < 'z')
		{
			k = ch - 'a';
			num[k] += 1;
		}
		scanf("%c",&ch);
	
	}
	printf("字符个数:\n");
	for(k=0;k<26;k++)
	{
		putchar('a'+k);
		printf(" ");
	
	}
	putchar('\n');
	for(k=0;k<26;k++)
	{
		printf("%d ",num[k]);
	
	}
	putchar('\n');


}
