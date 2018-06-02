/*
全局变量：定义在函数外部的变量
作用域                    生存期
程序开始---》程序结束     程序开始------》程序结束
所有.c文件

*/

#include <stdio.h>
//int num=10;//全局变量
extern  int num;//全局变量的声明   不申请空间的
extern void fun1();//外部函数的声明
int i=30;

void  fun()
{
		num=99;
		printf("fun:%d\n",num);
}
int num;  //申请空间
int main()
{
		int i;
		fun();
		for(i=0;i<5;i++)
		fun1();
		num=100;

		printf("main:%d\n",num);
		return 0;
}
