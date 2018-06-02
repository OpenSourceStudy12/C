#include <stdio.h>
int sum(int a,int b)
{
     return a+b;
}
int sub(int a,int b)
{
		return a-b;
}
int mul(int a,int b)
{
		return a*b;
}
int div(int a,int b)
{
		return a/b;
}

int main()
{
		int select ,re;
		int (*p)(int,int)=NULL;
		while(1)
		{
				printf("1,加法\n");
				printf("2,减法\n");
				printf("3,乘法\n");
				printf("4,除法\n");
				printf("5,退出\n");
				printf("请输入选择：\n");
				scanf("%d",&select);
				if(select == 1)
				{
				//	re=sum(2,3)	;
				    p=sum;
				}
				else if(select==2)
				{
				//	re=sub(2,3);
				     p=sub;
				}
				else if(select==3)
				{
					//	re=mul(2,3);
					p=mul;
				}
				else if(select == 4)
				{
					//	re=div(2,3);
					p=div;
				}
				else if(select==5)
				{
						break;
				}
				else
				{
						printf("输入不正确！\n");
						continue;
				}
				re=p(2,3);//统一入口
				printf("re=%d\n",re);
		}
}








/*
int main()
{
		int re=sum(2,3);
		int (*p)(int,int)=NULL;//函数指针的定义
		p = sum;//函数指针的赋值
		re=p(4,5);//函数指针调用函数
		printf("%d\n",re);
		return 0;
}
*/
