#include <stdio.h>

#define SCORE 90
/*
   条件编译：决定哪些代码参与编译　哪些代码不参与编译
   */
int main()
{
#ifndef SCORE
	printf("hello world\n");
#endif
	printf("hello zhimeng\n");
	return 0;
}

#undef SCORE
