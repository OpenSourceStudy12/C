/*
for(表达式1;表达式2;表达式3)
{
		循环体;
}

工作原理：
1,执行表达式1,初始化循环变量
2，执行表达式2,表达式2是条件判断，若为真，执行循环体，执行完循环体后在执行表达式3,表达式3是用来改变循环变量的值，再执行表达式2,若表达式2为假直接跳出循环

注意事项：
1,表达式1可以省略，但在循环之前一定要初始化
2,若省略表达式2,条件一直为真
3,表达式3可以省略，但必须在循环体内改变循环变量的值
4,for后面尽量不要加分号，除非特殊处理

*/
#include <stdio.h>
int main()
{
		int i=1;
		for(;;)//死循环
		{
                if(i>5)
				{
						break;
				}
				printf("hehe\n");
				i ++;
		}
		return 0;
}


/*
int main()
{
		int i=1,sum=0;
		for(i=1;i<=10;i++);
		{
				sum += i;
				printf("i=%d\n",i);
		}
		printf("sum=%d,i=%d\n",sum,i);
		return 0;

}
*/
