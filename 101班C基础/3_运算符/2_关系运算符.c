#include <stdio.h>
/*
注意赋值运算符‘=’和关系运算符“==”
*/
int main()
{
		int a=3;
		if(a==1)
		{
				printf("1,a等于1\n");
		}
		if(a=1)
		{
				printf("2,a等于1\n");
		}
		return 0;
}
/*
int main()
{
		int a;
		printf("请输入一个数：\n");
		scanf("%d",&a);
//		if(a%2==0)
//		{
//				printf("能被2整除\n");
//		}
        if(a%2==0)
		{
				printf("能被2整除\n");
		}
		else
		{
				printf("不能被2整除\n");
		}
		printf("判断结束\n");
		return 0;
}
*/


/*
int main()
{
		int a=1,b=2;
		printf("a>b=%d\n",a>b);
		printf("a!=b=%d\n",a!=b);
		return 0;
		
}
*/
