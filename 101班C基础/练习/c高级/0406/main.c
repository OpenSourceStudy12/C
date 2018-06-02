#include<stdio.h>
#include"operation.h"
//#include"define.h"

int main()
{
	double a,b;
	printf("please input two number\n");
	scanf("%lf%lf",&a,&b);

#ifdef COM_A
	printf("1/a+1/b=%.2lf\n",operation(a,b));
#endif

#ifdef COM_B
	printf("a/b+b/a=%.2lf\n",operation(a,b));
#endif

#ifdef COM_C
	printf("a*a/b=%.2lf\n",operation(a,b));
#endif

	return 0;

}
