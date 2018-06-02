#include <stdio.h>


int main()
{
	const int a=1;
	const int b = 2;
	const int *const p = &a;
	*p = 3;
	printf("a=%d\n",*p);
	return 0;
}
