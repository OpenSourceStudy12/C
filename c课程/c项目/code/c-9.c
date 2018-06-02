
#include <stdio.h>

struct A
{
	int a;
	char b;
	short c;
};

struct B
{
	char b;
	int a;
	short c;
};

int main()
{
	printf("size of A = %d\n", sizeof(struct A));
	printf("size of B = %d\n", sizeof(struct B));
	return 1;
}


