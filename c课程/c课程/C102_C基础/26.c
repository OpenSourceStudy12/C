
#include <stdio.h>

void fun(char *tt,int pp[]);
int fun4(int x,int pp[],int *n);
int main()
{
#if 0
	int num[26]={0},i;
	char str[100]={0};
	char *p=str;
	while(1)
	{
		*p=getchar();
		if(*p == '\n')
			break;
		p++;
	}
	fun(str,num);
	for(i=0;i<26;i++)
	{
		if(num[i]!=0)
			printf("%c:%d\n",'a'+i,num[i]);
	}
#endif

	int x,i;
	int arr[100]={0};
	int n=0;
	int value;
	scanf("%d",&x);
	value=fun4(x,arr,&n);
	if(value != 0)
	{
		printf("调用失败");
	}
	else
	{
		for(i=0;i<n;i++)
			printf("%d\n",arr[i]);
	}
}

void fun(char tt[],int pp[])
{
	char *p=tt;
	while(*p != '\n')
	{
		pp[*p-'a']++;
		p++;
	}
}
/*
*函数名：fun4
*入参：x 小于100大于－100的整数, pp可以被x整除的数的数*       组; n:可以被整除数的个数的指针
*返回值：－1：执行失败，0：成功
*其他说明：
*/
int fun4(int x,int pp[],int *n)
{
	int index;
	int *p_p=pp;
	if(x<-10000||x>10000)//入参检查，健壮性
	{
		printf("param error!\n");
		return -1;
	}
	for(index=1;index<x;index++)
	{
		if((x%index==0)&&(index%2!=0))
		{
			*p_p=index;
			(*n)++;
			p_p++;
		}
	}
	return 0;	
}
