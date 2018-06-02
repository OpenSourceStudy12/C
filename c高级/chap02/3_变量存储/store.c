#include <stdio.h>

int a = 0;//初始化的数据区
char *p1;//未初始化的数据区

int main()
{
	int b;//栈
	char s[] = "abc";//栈
	char *p2;//栈
	char *p3 = "1234567";//栈
	static int c;//数据区
	p1 = (char *)malloc(10);
	p2 = (char *)malloc(20);
	strcpy(p1,"12345");
	return 0;
}
