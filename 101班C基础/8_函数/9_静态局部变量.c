#include <stdio.h>
/*
作用域                        生存期
定义的函数内部                变量定义-------》程序结束
*/
void  fun()
{
	    static int a=10;//静态局部变量
		a++;
		printf("a=%d\n",a);
}

int main()
{
		int i;
		for(i=0;i<5;i++)
				fun();
		printf("a=%d\n",a);
		return 0;
}
