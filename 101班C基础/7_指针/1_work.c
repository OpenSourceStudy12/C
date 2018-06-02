/*
1,定义一个double类型的变量和指针，通过两种方式访问变量内容和地址并打印


2,定义两个变量a,b,通过指针交换两个变量的数据



*/
#include <stdio.h>
int main()
{
		float a=1.23,b=3.45;
		float *p1=&a,*p2=&b,temp;
		printf("before:a=%.2f,b=%.2f\n",a,b);
		temp=*p1;
		*p1=*p2;
		*p2=temp;
		printf("after:a=%.2f,b=%.2f\n",a,b);
}


/*
int main()
{
		double d=8.99;
		double *p=NULL;
		p=&d;
		printf("d=%.2lf,*p=%.2lf\n",d,*p);
		printf("&d=%p,p=%p\n",&d,p);
		printf("&p=%p\n",&p);
}
*/
