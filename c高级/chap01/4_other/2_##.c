#include <stdio.h>

#define FUN(s) func##s

void func1()
{
	printf("this is func1\n");
}
void func2()
{
	printf("this is func2\n");
}
void func3()
{
	printf("this is func3\n");
}


int main()
{
	FUN(2)();//func1();
	return 0;
}
