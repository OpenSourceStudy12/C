/*********************************************************
*file name:
*function:位操作
*author:
***********************************************************/
#include<stdio.h>
#include"func.h"

int main()
{
	int x,y,k,n;
	printf("please input three num:\n");
	scanf("%d%d%d",&x,&y,&n);
	printf("before:x = %#x\n",x);

#ifdef SET0
	k=setBit0(x,y);
	printf("set0:x = %#x\n",k);
#endif

#ifdef SET1
	k=setBit1(x,y);
	printf("set1:x = %#x\n",k);
#endif

#ifdef RET
	k=setBit_f(x,y,n);
	printf("ret:x = %#x\n",k);
#endif
	return 0;
}
