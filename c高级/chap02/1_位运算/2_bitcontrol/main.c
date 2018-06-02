#include <stdio.h>
#include "bitControl.h"


int main()
{
	int num,ret,x;
	printf("please input a num:");
	scanf("%d",&num);
	printf("please input controling bit:");
	scanf("%d",&x);
	printf("old num is:\n");
	printf_binary(num);
	ret = bitSet_f(num,x,2);
	printf("new num is:\n");
	printf_binary(ret);
	//printf("ret = %d\n",ret);
	return 0;
}


