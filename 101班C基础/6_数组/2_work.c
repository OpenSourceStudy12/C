/*
1定义double a[5],打印每个元素的起始地址及数据
 a    a+1   a+2    a+n
&a[0]  &a[1]
a[0]
&a    &a+1


2,int a[6],按照从小到大的顺序输出数据

*/
#include <stdio.h>
int main()
{
		int a[6]={12,34,6,90,0,7};
		int i,j,temp;
		for(i=0;i<5;i++)
		{
           for(j=0;j<6-i-1;j++)
		   {
				   if(a[j]>a[j+1])
				   {
					   temp=a[j];
					   a[j]=a[j+1];
					   a[j+1]=temp;   
				   }
		   }
		}
		printf("sorted:\n");
		for(i=0;i<6;i++)
		{
				printf("%d ",a[i]);
		}
		printf("\n");
}
