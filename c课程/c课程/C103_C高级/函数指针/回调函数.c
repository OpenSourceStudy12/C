#include <stdio.h>
//»Øµ÷º¯Êı
typedef struct student
{
	int num
	char name[20];
}stu;
typedef float (*pfun)(int,int);
float operation(int a,int b);



float funtion(pfun p)
{
	p(2,3);
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