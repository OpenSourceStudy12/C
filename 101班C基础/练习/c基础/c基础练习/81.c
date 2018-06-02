/************************************************
*file name:
*function:设计一个函数，将s指向的字符串的所有下标为偶数的字符改成'*'
*author:
**************************************************/
#include<stdio.h>
void fun(char *ch);

int main()
{
	char s[100];
	printf("请输入一行字符串:\n");
	gets(s);
	fun(s);
	puts(s);

	return 0;
}

void fun(char *ch)
{
	int i;
	for(i=0;*(ch+i) != '\0';i++)
	{
		if(i%2 == 0)
			*(ch+i)='*';
	
	}

}
