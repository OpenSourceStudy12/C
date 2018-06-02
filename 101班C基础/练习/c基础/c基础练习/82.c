/*******************************************************
*file name:
*function:设计一个函数，将一个字符串插入到另一个字符串的最大字符后面
*author:
*********************************************************/
#include<stdio.h>
#include<string.h>
void fun(char *t,char *s);

int main()
{
	char s[50],t[200];
	printf("请输入源字符串:\n");
	gets(s);
	printf("请输入目标字符串:\n");
	gets(t);
	fun(t,s);
	puts(t);

}

void fun(char *t,char *s)
{
	int i,n=0,max,len;
	for(i=0,max=0;*(t+i) != '\0';i++) //求t的最大字符下标和长度不包括'\0'
	{
		if(t[max] <= t[i])
			max=i;
	}
	len=strlen(s);
	//	while(s[n++] != '\0');//计算s的长度 包括'\0'
	for(;i>=max+1;i--)      //t后移s的长度，不包括'\0'
		t[i+len]=t[i];
	for(i=0;i<len;i++)  //将s插入到t中
	{
		t[++max]=*s++;
	
	}
	
}
