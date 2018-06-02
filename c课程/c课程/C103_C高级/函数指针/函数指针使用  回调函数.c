#include <stdio.h>
//回调函数
typedef float (*pfun)(int,int);

float operation(int a,int b);
float operation2(int a,int b);
float operation3(int a,int b);


float funtion(pfun p);
int main()
{
	float result = funtion(operation);
	printf("result = %f\n",result);
	return 0;
}




float funtion(pfun p)
{
	return p(2,4);
}





float operation(int a,int b)
{
	float c;
 	c=1.0/a+1.0/b;
	return c;
}
float operation2(int a,int b)
{
	float c;
 	c=1.0/(a*a)+1.0/(b*b);
	return c;
}
float operation3(int a,int b)
{
	float c;
 	c=1.0/(a*b);
	return c;
}
