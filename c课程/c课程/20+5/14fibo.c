#include <stdio.h>
int fun(int t);
int main()
{
	int t,min;
	printf("请输入一个正整数：");
	scanf("%d",&t);
	min=fun(t);
	printf("min=%d\n",min);
	return 0;
}

int fun(int t)
{
	int i,min,b[100]={0,1};
	for(i=2;;i++)
	{
		b[i]=b[i-1]+b[i-2];
		if(b[i]>t)
		{
			min=b[i];
			break;
		}
	}
	return min;
}
