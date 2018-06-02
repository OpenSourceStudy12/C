#include <stdio.h>
/*
作用域：变量的可访问性
生存期：变量定义----》系统回收

局部变量：定义在函数内部的变量,包括形参
作用域                 生存期
定义的函数内部         变量定义----》函数结束

*/
void fun(int x)
{
		int a;
		a=10;
		printf("a=%d\n",a);
}

int main()
{
		int num=100;
		int i;
		for(i=0;i<5;i++)
             fun(num);
}
