/***************************************************
*file name:
*function:设有一个数列，包含10个数，已按升序排好。现要求编写程序，把从指定位置开始的n个数按逆序重新排列并输出新的完整数列。进行逆序处理时要求使用指针方法。试编程。（例如：原数列为2,4,6,8,10,12,14,16,18,20，若要求把从第4个数开始的5个数按逆序重新排列，则得到新数列2,4,6,16,14,12,10,8,18,20）
*author:
***************************************************/
#include<stdio.h>
void sort(int a[],int n);
void c_sort(int *p,int m,int n);

void main()
{
	int a[10],i=0,m,n;
	printf("请输入10个数:\n");
	while(i<10)
	{
		scanf("%d",&a[i++]);
	
	}
	sort(a,10);
	printf("排序后数组为:\n");
	for(i=0;i<10;i++)
		printf(" %d ",a[i]);
	printf("\n将第m个数开始的n个数重排:\n");
	scanf("%d%d",&m,&n);
	c_sort(a,m,n);
	printf("重新排序后数组为:\n");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	putchar('\n');


}



void sort(int a[],int n)
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

void c_sort(int *p,int m,int n)
{
	int *p1,*p2,temp;
	for(p1=p+m-1,p2=p1+n-1;p1 < p2;p1++,p2--)
	{
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}

}














