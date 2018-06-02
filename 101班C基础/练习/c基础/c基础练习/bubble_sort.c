/*******************************************
*file name:
*function:冒泡排序算法
*author:
********************************************/
#include<stdio.h>

void bubble_sort(int a[],int n);
void main()
{
	int n,i;
	printf("请输入一个整数个数:");
	scanf("%d",&n);
	int a[n];
	for(i=0;i < n;i++)
	{
		printf("请输入一个整数:");
		scanf("%d",&a[i]);
	//	bubble_sort(a,n);
	}
	bubble_sort(a,n);
	for(i=0;i<n;i++)
		printf(" %d ",a[i]);
	printf("\n");

}



void bubble_sort(int a[],int n)
{
	int i,j,temp;
	for(i=0;i < n-1;i++)
	{
		for(j=0;j < n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			
			}
		
		}
	
	}

}
