#include <stdio.h>
#include "func.h"

int div(int a, int b)
{
	if(b == 0)
	{
		printf("除数不能为0\n");
		printf("ERROR:file:%s func: %s line:%d\n",__FILE__,__func__,__LINE__);
		return -1;
	}
	return a/b;
}


#line 10086 "cal.c"
int div_2(int a,int b)
{
	if(a == 0)
	{
		printf("除数不能为0\n");
		printf("ERROR:file:%s func: %s line:%d\n",__FILE__,__func__,__LINE__);
		return -1;
	}
	return b/a;
}
