#include <stdio.h>
/*
作用域       生存期
本.c文件     程序开始------》程序结束
*/



static int num;//静态全局变量
extern void fun1();
void fun()
{
		num=99;
		printf("fun:%d\n",num);
}

 int main()
 {
		 fun();
		 fun1();
		 num=100;
		 printf("main:%d\n",num);
		 return 0;
 }

