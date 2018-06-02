#include <stdio.h>
#include "operation.h"

int main()
{
	int a,b;
	double ret;
	printf("please input two num:\n");
	scanf("%d %d",&a,&b);
	ret = operation(a,b);
	printf("ret = %lf\n",ret);
	return 0;
}
