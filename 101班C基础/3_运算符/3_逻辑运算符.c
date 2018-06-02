#include <stdio.h>
/*
&&:如果两个操作数都为真返回1,否则返回0

||:如果两个操作数都为假返回0.，否则返回1

!:


*/

int main()
{
		int num;
		scanf("%d",&num);
		if(!(num%5))
		{
				printf("%d  能被5整除\n",num);
		}
		else
		{
				printf("%d  不能被5整除\n",num);
		}
}
/*
int main()
{
		int a=0;
		printf("!a=%d\n",!a);
}
*/
/*
int main()
{
		int a=1,b=2;
		if(a>0||--b)//||:如果第一个操作数为真，第二个操作数就不进行运算
		{
				printf("xixi\n");
		}
		printf("a=%d,b=%d\n",a,b);
		return 0;
}
*/
/*
int main()
{
		int a=1,b=2;
		if(a++<0&&++b)// &&:如果第一个操作数为假，那么第二个操作数不进行运算的
		{
				printf("hehe\n");
		}
		printf("a=%d,b=%d\n",a,b);
		return 0;
}
*/
/*
int main()
{
		int num;
		scanf("%d",&num);
		if(num%2==0 || num%3==0)
		{
				printf("是2或者3的倍数\n");
		}
		else
		{
				printf("不是2和3的倍数\n");
		}
}
*/
/*
int main()
{
    char ch;
	ch=getchar();
	if(ch>='0'&&ch<='9')
	{
			printf("%c  是数字字符\n",ch);
	}
	else
	{
			printf("%c 不是数字字符\n",ch);
	}
}
*/



/*
int main()
{
		int a=1,b=2;
		printf("a==b||a>b=%d\n",a==b||a>b);
		printf("a!=b||a>b=%d\n",a!=b||a>b);
		printf("a==b||a<b=%d\n",a==b||a<b);
		printf("a!=b||a<b=%d\n",a!=b||a<b);
}
*/
/*
int main()
{
		int a=1;
		int b=2;
		printf("a>b&&a==b=%d\n",a>b&&a==b);
		printf("a<b&&a==b=%d\n",a<b&&a==b);
		printf("a>b&&a!=b=%d\n",a>b&&a!=b);
		printf("a<b&&a!=b=%d\n",a<b&&a!=b);
}

*/
