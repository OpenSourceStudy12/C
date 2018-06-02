
#include <stdio.h>

/*选择排序*/
void select_sort(int a[],int n)
{
	int i,k,j,temp;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i;j<n;j++)
		{
			if(a[k]>a[j])
				k = j;
		}
		if(i!=k)
		{
			temp = a[i];
			a[i]=a[k];
			a[k]=temp;	
		}
	}
}

/*冒泡排序*/
void bubble_sort(int a[],int n)
{
	int change = 0,temp,i,j;
	for(i=0;i<n-1;i++)
	{
		change = 0;
		
		//如果有交换change = 1;
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])//相邻两个元素比较
			{
				temp = a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				change = 1;
			}
		}
		if(change == 0)
		{
			printf("cishu= %d\n",i+1);
			break;
		}
	}
	if(i==n-1)
	{
		printf("cishu=%d\n",i);
	}
}

void swap(int v[],int i,int j)
{
	int temp;
	temp = v[i];
	v[i]=v[j];
	v[j]=temp;
}

/*快速排序*/
void qsort(int v[],int left,int right)
{
	int high = right;
	int last=0;
	int low=left
	if(left>=right)//递归函数出口
		return;
	while(left<right)
	{
		if(v[left]>v[right])
		{
			swap(v,left,right);
			
			last = ~last;
			
		}
		if(last==0)
			right--;
		else
			left++;
	}
	qsort(v,low,left-1);
	qsort(v,left+1,high);
}

int main()
{
	int i;
	int arr[]={9,8,7,6,5,4,3,2,1,0};
	 qsort(arr,0,9);
	for(i=0;i<sizeof(arr)/sizeof(int);i++)
		printf("%d   ",arr[i]);
}
