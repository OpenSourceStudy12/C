/*
1,输出1——-100之间同时能被3和5整除的所有整数，并求出之和

2,输入一个数，输出其反转后的整数
120  -------》21
123=---------》321

3,输入一个整数n,求 1+1/2+1/3+...1/n之和


4,输入整数m和n,求m的n次方

*/

#include <stdio.h>
int main()
{
		int m,n,i,s=1;
		printf("请输入两个整数(m、n)：\n");
		scanf("%d%d",&m,&n);
		if(n==0)
		{
				s=1;
				//				return 0;
		}
		else
		{
				for(i=1;i<=n;i++)
				{
						s *= m;
				}
		}
		printf("s=%d\n",s);
		return 0;
}

/*
int main()
{
     int n,i;
	 float sum=0;
	 printf("请输入一个整数：\n");
	 scanf("%d",&n);
	 for(i=1;i<=n;i++)
	 {
			 sum +=(float)1/i;
	 }
	 printf("sum=%.2f\n",sum);
	 return 0;
}
*/



/*
int main()
{
		int x,value=0;
		printf("请输入一个整数:\n");
		scanf("%d",&x);
		for(;x!=0;x/=10)
		{
				value=value*10+x%10;
		}
		printf("value=%d\n",value);
		return 0;
}
*/

/*
int main()
{
		int i,sum=0;
		for(i=1;i<=100;i++)
		{
				if(i%3==0&&i%5==0)
				{
						printf("%d ",i);
						sum += i;
				}
		}
		printf("\nsum=%d\n",sum);
		return 0;
		
}
*/
