#include <stdio.h>
void  func(int a[],int size)
{
		int i;
		printf("sizeof(a)=%d\n",sizeof(a));
		for(i=0;i<size;i++)
		{
				a[i] += 5;
		}
}


void  func1(int *a,int size)
{
		int i;
		for(i=0;i<size;i++)
		{
				//a[i]+=5;
				*(a+i)+=5;
		}
}
int main()
{
		int i;
		int a[5]={1,2,3,4,5};
     //   func(a,sizeof(a)/sizeof(int));//传数组至少要传两个参数：数组首元素起始地址和数组大小
       func1(a,5);
	    for(i=0;i<5;i++)
		{
				printf("a[%d]=%d\n",i,a[i]);
		}
}
