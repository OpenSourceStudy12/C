#include <stdio.h>
/*
1,结束本函数
2,return 只能返回一个值
3,返回值一定要与返回值类型匹配
*/
int  fun()
{
		float i=3.4;
		return  i;
}

int main()
{
		int a,b;
		a=2,b=3;
		printf("%d",fun());
		printf("a=%d,b=%d\n",a,b);
		return 0;
		a++;
		b++;
		printf("a=%d,b=%d\n",a,b);
		return 0;
}
