#include <stdio.h>
/*
结构体对齐规则：
1,结构体成员按照自己的字节数对齐

2,结构体成员的最大对齐数取决于系统（32位：4字节      64位：8字节）

3，结构体最后的字节数一定是该结构体成员最大字节数的倍数
*/



struct s1
{
		char a;
		short int b;
		double c;
		char d;
		char e;
};


struct s2
{
		char a;
		double c;
		short int b;
};

int main()
{
		struct s1 *p=NULL;
		struct s1 s;
		p=&s;
		printf("sizeof(p)=%d,sizeof(s)=%d,sizeof(*p)=%d\n",sizeof(p),sizeof(s),sizeof(*p));
		printf("sizeof(struct s1)=%d\n",sizeof(struct s1));
		printf("sizeof(struct s2)=%d\n",sizeof(struct s2));
}
