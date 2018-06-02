#include<stdio.h>
#include<stdlib.h>
#include"sort.h"


/************************************************
*func:选择排序
*describtion:
共有n个数进行选择排序
循环趟数:n-1
每趟比较次数:n-1-i
总共比较次数:n(n-1)/2
从小到大排序为例
每次从数据中选择最小的数据放到剩余数据的首地址
 ************************************************/
void select_sort(int *p,int n)
{
	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		k = i;
		for(j=i+1;j<n;j++)
		{
			if(p[j]<p[k])
				k = j;
		}
		if(k != i)
		{
			int temp;
			temp = p[i];
			p[i] = p[k];
			p[k] = temp;
		}
	}
}


/*************************************************
*func:冒泡排序
*describtion:
总共有n个数
趟数:n-1
每趟循环次数:n-1-i
以从小到大排序为例
每趟依次将相邻两个数进行比较，将较大的数放在后边，
**************************************************/
void bubble_sort(int *p,int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		int flag = 0;
		for(j=0;j<n-1-i;j++)
		{
			if(p[j]>p[j+1])
			{
				flag = 1;
				int temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
		if(!flag)
			break;
	}
}


/********************************************
*func:直接插入排序
*describtion
共有n个数
从第二个数开始，依次与前边的有序序列进行比较
从前边序列中找到该数的位置，并为该数腾出位置
趟数n-1
每趟最大比较次数:1,2,3....n-1
*********************************************/
void insert_sort(int t[],int n)
{
	int i,j,temp;
	for(i=1;i<n-1;i++)
	{
		temp = t[i];
		for(j=i;j>0;j--)
		{
			if(temp < t[j-1]) 
				t[j] = t[j-1];
			else
				break;
		}
		t[j] = temp;
	}
}

/*********************************************
*func:快速排序
*describtion:
**********************************************/
void q_sort(int t[],int low,int high)
{
	int left = low,right = high;
	int flag=0,temp;
	if(left>=right)
		return;
	while(left < right)
	{
		//flag = 0;
		if(t[left]>t[right])
		{
			temp = t[left];
			t[left] = t[right];
			t[right] = temp;
			flag = ~flag;
		}
		if(flag)
			left++;
		else
			right--;
	}
	q_sort(t,low,left-1);
	q_sort(t,left+1,high);
}

/********************************************
*func:二分法查找(查找有序序例)
*describtion: 
*********************************************/
/*循环算法*/
int dichotomy_search(int t[],int low,int high,int key)
{
	int left = low;right = high;
	int mid;
	while(left < right)
	{
		mid = left + (right-left)>>1;
		if(key == t[mid])
			return mid;
		else if(key < t[mid])
			right = mid-1;
		else
			left = mid+1;
	}
	return -1;
}

/*递归算法*/
int dichotomy_search(int t[],int low,int high,int key)
{
	//int left = 0,right = high;
	int mid;
	if(left >= right)
		return -1;
	else
	{
		mid = left + (right-left)>>1;
		if(key == t[mid])
			return mid;
		else if(key < t[mid])
			return dichotomy(t,left,mid-1,key);
		else
			return dichotomy(t,mid+1,right);
	}

}



