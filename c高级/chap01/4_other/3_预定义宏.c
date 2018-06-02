#include <stdio.h>
#include "func.h"


int main()
{
	/*printf("date:%s\n",__DATE__);
	printf("file:%s\n",__FILE__);
	printf("line:%d\n",__LINE__);
	printf("TIME:%s\n",__TIME__);*/

	int a,b,ret;
	scanf("%d %d",&a,&b);
	ret = div_2(a,b);
	printf("ret = %d\n",ret);
	return 0;
}
