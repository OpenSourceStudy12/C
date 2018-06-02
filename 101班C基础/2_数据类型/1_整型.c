#include <stdio.h>
//字符一共128    0-127
//0-31不可见   32-127可见
int main()
{
		char ch='1';//定义一个字符类型的变量  实质在内存申请1个字节空间
        ch = 'a';
		ch = 48;
		ch = '\060'+1;
		ch = '\x30'+2;
	    int num1=23,num2=34;
		
}


/*
int main()
{
		float num=3.14159;//定义一个浮点类型的变量  实质在内存空间申请4字节空间
        num = 1.78e10;
		double GDP=178e30;
}
*/


/*
int main()
{
    int num=10;//   初始化   实质上就是在内存空间申请4个字节空间，num 是该片空间的别名
    num = 20;//赋值
	short int age=18;//实质申请2个字节空间  
    short int x=32768;//注意  ：越界啦
	unsigned short int y=65536;
}
*/
