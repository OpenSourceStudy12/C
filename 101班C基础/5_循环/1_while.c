/*
while(条件表达式)
{
		循环体;
}
注意事项：
1,在执行循环之前一定要初始化循环变量

2,在循环体内一定要改变循环变量的值,一般在循环体最后改变循环变量的值

3,不要在条件表达式后面加分号

4,break:(1)跳出switch    (2)跳出循环

1+2+3+...+10
*/

#include <stdio.h>
int main()
{
		int sum=0,i=1;
		while(i<=10)
		{
				sum += i;//sum=sum +i
				i ++;
		}
		printf("sum=%d,i=%d\n",sum,i);
		return 0;
}
/*
int main()
{
		int i=1;
		while(1)
		{
				if(i>5)
				{
					break;
				}
				printf("hehe\n");
		        i  ++;
		}
		printf("xunhuanwanbi\n");
}
*/

/*
int main()
{
		int i=1;
		while(i<=3);
		{
				printf("hehe\n");
				i ++;
		}
}
*/
