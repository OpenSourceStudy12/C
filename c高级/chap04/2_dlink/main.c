#include <stdio.h>
#include "dlink.h"

int main()
{
	PNode head;
	int cnt;
	head = dLinkCreat();
	dLinkPrint(head);
#if 1
	cnt = dLinkLength(head);
	printf("the length is :%d\n",cnt);
#endif


	return 0;
}
