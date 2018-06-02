#include<stdio.h>
#include<math.h>

float fun(float x);

int main(void)
{
	
	float x0=0.0;
	float result;
	result = fun(x0);
	printf("result=%f\n",result);
	return 0;
}

float fun(float *x0)
{
	float x1=cos(x0);
	if(fabs(x1-x0)<0.000001)
	{
			return x0;
	}
	else
	{
		x0=x1;
		return fun(x0);
		
	}
	
}