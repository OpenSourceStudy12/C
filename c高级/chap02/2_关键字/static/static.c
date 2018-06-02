#include <stdio.h>


void  func()
{
	static int a=0;
	a++;
	printf("a=%d\n",a);
}

int main()
{
	func();
	func();
	return 0;
}
