/*
1,求1-10之间所有整型的平方根和立方，并输出结果

2,产生7个1-31之间的随机数，并且不能重复，输出结果

3,从键盘输入一个整数，求出他的绝对值


4,从键盘输入一个浮点数，求出他的绝对值
*/
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
int main()
{
		double a,re;
		printf("请输入一个浮点型数据：");
		scanf("%lf",&a);
		re=fabs(a);
		printf("%lf的绝对值是:%lf\n",a,re);
		return 0;
}
/*
int main()
{
		int num;
		printf("请输入一个整数：");
		scanf("%d",&num);
		printf("%d的绝对值为：%d\n",num,abs(num));
		return 0;
}

*/
/*
int main()
{
		int i,j;
		int a[7];
		srand(time(NULL));
		for(i=0;i<7;i++)
		{
				a[i]=rand()%31+1;
				for(j=0;j<i;j++)
				{
						if(a[i]==a[j])
						{
                            a[i]=rand()%31+1;
							j=-1;
						}
				}

		}
        for(i=0;i<7;i++)
		{
				printf("%d ",a[i]);
		}
		printf("\n");
		return 0;
}
*/
/*
int main()
{
		int i;
		for(i=1;i<=10;i++)
		{
              printf("%d的平方跟：%.2lf,立方：%.2lf\n",i,sqrt(i),pow(i,3));
		}
		return 0;
}
*/
