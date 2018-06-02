#include<stdio.h>
#include"operation.h"
//#include"define.h"

double operation(double a,double b)
{
	double x;

#ifdef COM_A
	x=1/a+1/b;
#endif

#ifdef COM_B
	x=a/b+b/a;
#endif

#ifdef COM_C
	x=a*a/b;
#endif

	return x;

}
