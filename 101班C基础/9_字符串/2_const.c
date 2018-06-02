#include <stdio.h>
int main()
{
		int a=20;
		int b=30;
//		const int *p=&a;//指针指向的内容不能改变
//        int const *p=&a;
       int *const p=&a;//指针的指向不能改变
	   int const *const p=&a;//指针的指向以及指针指向的内容都不能改变
//		*p=40;
        p =&b;
}
/*
int main()
{
//	 const	int a=10;
     int const a=20;
	 a=20;
	 printf("%d",a);
	 return 0;
}
*/
