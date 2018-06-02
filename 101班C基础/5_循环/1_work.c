/*
1,打印1—100之间的所有整数，输出时每行8个数据

2,求1——100之间所有奇数之和
		i  ++;

3,输入一行字符序列(\n)，输出小写字符、大写字符、数字字符、其他字符的个数

4,输出1-1000之间所有水仙花的数
个位数的3次幂+十位数的3次幂+百位数的3次幂=数的本身



5,从键盘输入一个整数，判断是否是素数
素数：只能被1和自己整除的数


6,求框里至少有多少个鸡蛋：
1个1个拿，刚好拿完
2个2个拿，剩一个
3个3个拿，刚好拿完
4个4个拿，剩一个
5个5个拿，差一个
6个6个拿，剩三个
7个7个拿，刚好拿完
8个8个拿，剩一个
9个9个拿，刚好拿完

7,从键盘输入一行字符序列，统计空格的个数
*/
#include <stdio.h>
int main()
{
		int count=0;
        char ch;
		while(1)
		{
				ch=getchar();
				if(ch=='\n')
						break;
			    if(ch==' ')
						count ++;
		}
		printf("count =%d\n",count);
		return 0;
}


/*
int main()
{
		int num=2;
		while(1)
		{
				if(num%2==1&&num%3==0&&num%4==1&&num%5==4&&num%6==3&&num%7==0&&num%8==1&&num%9==0)
						break;
			    num ++;
		}
		printf("num=%d\n",num);
		return 0;
}
*/
/*
int main()
{
		int num,i=2,flag=1;
		printf("请输入一个数:\n");
		scanf("%d",&num);
		if(num==1)
		{
				printf("%d  不是素数\n",num);
				return 0;
		}
		while(i<num)
		{
				if(num%i==0)
				{
						flag=0;
						break;
				}
				i ++;
		}
		if(flag)
		{
            printf("%d 是素数\n",num);
		}
		else
		{
				printf("%d bu是素数\n",num);
		}
		return 0;
}
*/
/*
int  main()
{
		int num,i=2;
		printf("请输入一个数:\n");
		scanf("%d",&num);
        while(i<num)
		{
				if(num%i==0)
				{
						break;
				}
				i ++;
		}
		if(num==1 || i<num)
		{
				printf("%d 不是素数\n",num);
		}
		else
		{
				printf("%d 是素数\n",num);
		}
		return 0;
}
*/
/*
int main()
{
		int i=100,j=1;
		int g=0,s=0,b=0;
		while(i<=1000)
		{
            g=i%10;
			s=i/10%10;
			b=i/100%10;
			if(g*g*g+s*s*s+b*b*b==i)
			{
					printf("%3d ",i);
					if(j%6==0)
					{
							printf("\n");
					}
					j ++;
			}
			i ++;
		}
		return 0;
}
*/
/*
int main()
{
		char ch;
		int a=0,b=0,c=0,d=0;
		while((ch=getchar())!='\n')
		{
//				ch=getchar();
//				if(ch=='\n')
//				{
//						break;
//				}
				if(ch>='0'&&ch<='9')
				{
						a++;
				}
				else if(ch>='a'&&ch <='z')
				{
						b++;
				}
				else if(ch>='A'&&ch<='Z')
				{
						c++;
				}
				else
				{
						d++;
				}
		}
		printf("数字字符：%d,小写字符:%d,大写字符:%d,其他字符:%d\n",a,b,c,d);
		return 0;
}
*/
/*
int main()
{
		int i=1;
		int sum=0;
		while(i<=100)
		{
				sum+=i;
				i+=2;
		}
		printf("sum=%d,i=%d\n",sum,i);
		return 0;
}
*/
/*
int main()
{
    int i=1;
	while(i<=100)
	{
			printf("%3d ",i);
			if(i%8==0)
			{
					printf("\n");
			}
			i ++;
	}
	printf("\n");
}
*/
