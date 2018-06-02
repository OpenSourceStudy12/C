/********************************************************
*file name:
*function:请编写一个函数void fun(int tt[M][N],int pp[N]),
**********tt指向一个M行N列的二维函数组，求出二维函数组每列中
**********最小元素，并依次放入pp所指定一维数组中。二维数组中
**********的数已在主函数中赋予       
*author:
*********************************************************/
#include<stdio.h>

#define M 4 
#define N 3

void fun(int (*p)[N],int *q);

int main()
{
	int i;
	int tt[M][N]={
	              {30,10,3},
		      {2,4,2},
		      {4,7,9},
	              {4,7,34}
                         	};

	int pp[N];
	fun(tt,pp);
	for(i=0;i<N;i++)
	{
		printf("pp[%d]=%d\n",i,pp[i]);
	}
	return 0;
}

void fun(int (*p)[N],int *q)
{
	int i,j;
	for(i=0;i<N;i++,q++)
	{
		*q = *(*p+i);
		for(j=0;j<M;j++)
		{
			if(*(*(p+j)+i) < *q)
				*q = *(*(p+j)+i);
		
		}
	}

}






















