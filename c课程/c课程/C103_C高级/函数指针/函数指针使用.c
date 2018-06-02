#include <stdio.h>
//函数指针

float (*pfun)(int,int);
float operation(int a,int b);

int main()
{
}
int fun1()
{
	float result;
	if(condition1)
		{
			pfun=operation;
		}
		else if(condition2)
			{
				pfun=operation1;
			}
			else
			{
					pfun=operation2;
			}
}
float funtion()
{
	pfun(2,3);
}
float operation(int a,int b)
{
	float c;
 	c=1.0/a+1.0/b;
	return c;
}
float operation1(int a,int b)
{
	float c;
 	c=1.0/a;
	return c;
}
float operation2(int a,int b)
{
	float c;
 	c=1.0/b;
	return c;
}
float operation3(int a,int b)
{
	float c;
 	c=1.0/(a*a)+1.0/(b*b);
	return c;
}