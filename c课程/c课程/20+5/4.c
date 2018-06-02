#include<stdio.h>
#include<math.h>

double fun();

int main(void)
{
	printf("the result of cos x = x is %f\n", fun());

	return 0;
}

double fun()
{
	double x1 = 0.0, x0;
	double between = 0.0;
	do
	{
		x0 = x1;
		x1 = cos(x0);
		between = fabs(x1 - x0);	

	}while (between >= 0.000001);
	
	return x0;
	
}