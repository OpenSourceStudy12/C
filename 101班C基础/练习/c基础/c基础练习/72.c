/********************************************************
*file name:
*function:
*athor:
********************************************************/
#include<stdio.h>
int fun(float *p,float *q,int k);

void main()
{
	float a[10],b[10];
	int n,i;
	printf("请输入十个学生的成绩:\n");
	for(i=0;i<10;i++)
	{
		scanf("%f",a+i);
	
	}
	n=fun(a,b,i);
	printf("不及格人数为%d\n其成绩为:\n",n);
	for(i=0;i<n;i++)
	{
		printf("%.2f\n",b[i]);
	
	}
}

int fun(float *p,float *q,int k)
{
	int i,n=0;
	for(i=0;i<k;i++,p++)
	{
		if(*p < 60)
		{
			*q++ = *p;
			n++;
//			q++;
		}	
	
	}
	return n;
}
