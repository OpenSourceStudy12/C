#include <stdio.h>
/*
指针的注意事项：
1,定义一个指针变量一定要初始化

2,指针变量一定要与指向的变量类型匹配，不然的话，存储变量的地址一点问题都没有，但是在读取数据时会存在错误

3,所有指针变量在内存中都占4个字节
*/

int main()
{
		int a=20;
		int *p=&a;
		int **p_a=&p;
		printf("a=%d,*p=%d,**p_a=%d\n",a,*p,**p_a);
		printf("&a=%p,p=%p,*p_a=%p\n",&a,p,*p_a);
		printf("p=%p,*p_a=%p\n",p,*p_a);
		printf("&p=%p,p_a=%p\n",&p,p_a);
		printf("&p_a=%p\n",&p_a);
}




/*
int main()
{
      printf("sizeof(int *)=%d,sizeof(double *)=%d,sizeof(char *)=%d\n",sizeof(int *),sizeof(double *),sizeof(char *));

     int a=0x11223344;
	 char *p=&a;
	 int  *p_a=&a;
	 printf("p=%p,&a=%p,p_a=%p\n",p,&a,p_a);
	 printf("*p=%#x,a=%#x,*p_a=%#x\n",*p,a,*p_a);
	 printf("&p=%p,&p_a=%p\n",&p,&p_a);

}
*/




/*
int main()
{
		int a;
		int *p=NULL;
		p=60;//不能将整数赋值给指针变量
		*p=40;

}
*/




/*
int main()
{
		int a=20;
		int *p=&a;//  *标识符，，标志p指针变量
		printf("a=%d,*p=%d\n",a,*p);  //  *指针指向的变量内容
		printf("&a=%p,p=%p\n",&a,p);
		printf("&p=%p\n",&p);
        float  b=3.45;
		float *p_b;
		p_b=&b;
		*p_b=90.3;
		printf("b=%.2f,*p_b=%.2f\n",b,*p_b);
		printf("&b=%p,p_b=%p\n",&b,p_b);
		printf("&p_b=%p\n",&p_b);
}
*/
