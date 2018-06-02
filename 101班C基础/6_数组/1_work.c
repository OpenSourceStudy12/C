/*
1，定义一个数组存储10个学生的成绩，数据初始化进去，打印每个学生的成绩，并求出平均数


2,定义数组存储5中商品的价格，数据动态输入，输出每种商品的价格


3，定义数组存储6个不同整数，分别求出最大值和最小值


4,定义数组存储6个不同整数，分别求出最大值和最小值下标
*/
#include <stdio.h>
#define SIZE 5
int main()
{
	int a[6]={12,3,0,99,67,6};
	int max_index=0,min_index=0;
	int i;
	for(i=0;i<6;i++)
	{
			if(a[max_index]<a[i])
			{
					max_index=i;
			}
			if(a[min_index]>a[i])
			{
					min_index=i;
			}

	}
			printf("max_index:%d,min_index:%d\n",max_index,min_index);

}
/*
int main()
{
		int a[6]={12,3,0,99,67,6};
		int max=a[0],min=a[0];
		int i;
		for(i=0;i<6;i++)
		{
				if(max<a[i])
				{
						max=a[i];
				}
				if(min>a[i])
				{
						min=a[i];
				}
		}
		printf("max:%d,min:%d\n",max,min);
		return 0;
}
*/
/*
int main()
{
    float price[SIZE];
	int i;
	for(i=0;i<SIZE;i++)
	{
	        printf("请输入第%d个商品的价格:",i+1);
			scanf("%f",&price[i]);
	}
	for(i=0;i<SIZE;i++)
	{
			printf("price[%d]=%.2f\n",i,price[i]);
	}
}

*/

/*
int main()
{
		float a[10]={12.3,56.7,67.8,78.9,89.0,99,67,78,88,6};
		int i;
		float ave=0;
		for(i=0;i<10;i++)
		{
				ave += a[i];
				printf("%.2f ",a[i]);
		}
		printf("\nave=%.2f\n",ave/10);
		return 0;
}
*/


