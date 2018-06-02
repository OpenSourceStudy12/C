/*************************************************
*file name:
*function:请编写一个函数void fun(char a[],char[],int n),
**********其功能是：删除以各字符串中指定下标的字符。其中，
**********a指向原字符串，删除后的字符串存放在b所指的数组中，
**********n中存放指定的下标
*author:
**************************************************/
#include<stdio.h>
#include<string.h>
void fun(char a[],char b[],int n);

int main()
{
	char a[50],b[20];
	int n;
	printf("请输入一行字符串:\n");
	gets(a);
	printf("请输入整数:\n");
	scanf("%d",&n);
	fun(a,b,n);
	puts(b);
}

void fun(char a[],char b[],int n)
{
	int i,j,x;
	x = strlen(a);
//	y = strlen(b);
	for(i=0,j=0;i<x;i++)
	{
		if(i!=n)
			b[j++]=a[i];
	}
	b[j]='\0';
}
