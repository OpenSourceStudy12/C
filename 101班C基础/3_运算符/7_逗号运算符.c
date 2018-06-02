#include <stdio.h>
int main()
{
		int a,b;
		a=0,b=2;
		a=(a=2,a++,b=3,++a);
		printf("a=%d,b=%d\n",a,b);
		return 0;
}
