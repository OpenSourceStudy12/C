/*
1,从键盘输入一个整数n,求1————n之间所有的整数之和（while  do_while）


2,求1--100之间所有的偶数之和(while)


3,从键盘输入一个整数，输出该整数的反转（while do_while）
123------>321

4,学生管理系统
1------->学生登录
2-------》老师登录
3------》管理员登录
4------》退出


5,输入一行字符系列统计字符的个数（while  do_while）


6,求1--100之间所有的奇数之和，除了个位数为5的（do _while   while）

*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
		int i=1,sum=0;
		while(i<=100)
		{
				if(i%10==5)
				{
			        	i +=2;
						continue;
				}
				sum += i;
			    i += 2;
		}
		printf("sum=%d,i=%d\n",sum,i);
		return 0;
}
/*
int main()
{
		int i=1,sum=0;
		while(i<=100)
		{
            if(i%2!=0&&i%10!=5)
			{
					sum+=i;
			}
			i ++;
		}
		printf("sum=%d,i=%d\n",sum,i);
		return 0;
}
*/
/*
int main()
{
		char ch;
		int count=0;
		ch=getchar();
		do
		{ 
			    if(ch=='\n')
						break;
				count ++;

		}while((ch=getchar())!='\n');
		printf("count =%d\n",count);
}
*/
/*
int main()
{
		char ch;
		int count = 0;
		do
		{
				ch=getchar();
				if(ch=='\n')
						break;
			    count ++;
		}while(1);
		printf("count =%d\n",count);
		return 0;
}
*/
/*
int main()
{
		char ch;
		int count=0;
		while((ch=getchar())!='\n')
		{
				count ++;
		}
		printf("count=%d\n",count);
		return 0;
}
*/
/*
int main()
{
		int select;
		int flag=1;
		do
		{
				system("clear");
				printf("\t\t学生管理系统\n");
				printf("\t\t1,学生登录\n");
				printf("\t\t2,老师登录\n");
				printf("\t\t3,管理员登录\n");
				printf("\t\t4,退出\n");
				printf("请输入你的选择:\n");
				scanf("%d",&select);
				switch(select)
				{
						case 1:
								printf("学生登录成功\n");
								sleep(2);
								break;
						case 2:
								printf("老师登录成功\n");
								sleep(2);
								break;
						case 3:
								printf("管理员登录成功\n");
								sleep(2);
								break;
						case 4:
								flag=0;
								printf("我要退出喽！\n");
								sleep(2);
								break;
						default:
								printf("输入有误，请重新输入！\n");
								sleep(2);
								break;
				}
		}while(flag);
}
*/

/*
int main()
{
		int num,value=0;
		scanf("%d",&num);
		do
		{
				value=num%10;
				printf("%d",value);
				num/=10;
		}while(num!=0);
		printf("\n");
}
*/
/*
int main()
{
		int num,y;
		printf("请输入一个整数:\n");
		scanf("%d",&num);
		while(num!=0)
		{
				y=num%10;
				printf("%d",y);
				num=num/10;
		}
        printf("\n");
		return 0;

}
*/
/*
int main()
{
		int i=1,sum=0;
		do
		{
				if(i%2!=0)
				{
						i ++;
						continue;
				}
				sum += i;
				i ++;
		}while(i<=100);
		printf("sum=%d,i=%d\n",sum,i);
		return 0;
}
*/
/*
int main()
{
		int i=1,sum=0;
		do
		{
				if(i%2==0)
				{
						sum += i;
				}
				i ++;
		}while(i<=100);
		printf("i=%d,sum=%d\n",i,sum);
		return 0;
}
*/

/*
int main()
{
		int num,sum=0,i=1;
		printf("please input data:\n");
		scanf("%d",&num);
		do
		{
				sum += i;
				i ++;
		}while(i<=num);
		printf("i=%d,sum=%d,num=%d\n",i,sum,num);
		return 0;
}
*/

/*
int main()
{
		int num,i=1,sum=0;
		printf("请输入一个整数:\n");
		scanf("%d",&num);
		while(i<=num)
		{
				sum += i;
				i ++;
		}
		printf("sum=%d,i=%d,num=%d\n",sum,i,num);
		return 0;
}
*/


