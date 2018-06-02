/*
存储区：

#include<stdio.h>

int a = 0;//初始化数据
char *p1; //未初始化数据区

int main()
{
	int b;//栈
	char[] = "abc";//栈，字符串"abc"在常量区
	char *p2;//栈
	char *p3 = "1234567";//栈,字符串"1234567"在常量区
	static int c;//全局区
	p1 = (char *)malloc(10);//p1指向堆
	p2 = (char *)malloc(20);//p2指向堆
	strcpy(p1,"12345");//将字符串 "12345" 复制到p1所指的堆
}


*/
