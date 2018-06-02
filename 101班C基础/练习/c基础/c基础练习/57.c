/********************************************
*file name:
*function:有一个4行5列的二维数组，通过键盘输入赋初值，
*找出该数组中的靶点，即该位置上的元素在该行上最大、
*在该列上最小。也可能没有靶点
*author:
*********************************************/
#include<stdio.h>
void main()
{
	int a[4][5],h[4],l[5];	
	int i,j,k,flag=0;
	for(i=0;i<4;i++)
	{
		printf("请输入第%d行五个数:",i+1);
		for(j=0;j<5;j++)
			scanf("%d",a[i]+j);
	
	}
	for(i=0;i<4;i++)
	{
		for(j=1,k=0;j<5;j++)
		{
			if(a[i][k]<a[i][j])
			{
				k=j;
		//		h[i]=k;
			}	
		}
		h[i]=k;
	
	}
	for(j=0;j<5;j++)
	{
		for(i=1,k=0;i<4;i++)
		{
			if(a[k][j]>a[i][j])
			{
				k=i;
	//			l[j]=k;
			}	
		}
		l[j]=k;
	
	}
	for(i=0;i<4;i++)
	{
		if(i == l[(h[i])])
		{
			flag = 1;
			printf("靶点为 a[%d][%d] = %d\n",i,h[i],a[i][(h[i])]);
		}
	
	}
	if(!flag)
		printf("无靶点\n");


}















