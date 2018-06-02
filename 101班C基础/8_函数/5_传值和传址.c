#include <stdio.h>
void fun(int a,float b,float* re)
{
     *re=a+b;
}

int main()
{
		int a;
		float b,re;
		scanf("%d%f",&a,&b);
		fun(a,b,&re);
		printf("re=%f\n",re);
}
/*
void func(int* a)
{
		*a=10;
}

int main()
{
		int a=0;
		func(&a);
		printf("a=%d\n",a);
		return 0;

}
*/
