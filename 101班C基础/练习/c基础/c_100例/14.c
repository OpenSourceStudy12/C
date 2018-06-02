/*********************************************
*file name:
*function:将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5
*author:
**********************************************/

#include<stdio.h>
#include<math.h>

int zy(int x)
{
	int k,i,flag=0;
	k = sqrt(x+1);
	for(i=2;i<x;i++)
	{
		if(x%i == 0)
		{	
			flag = 1;
			break;
		}
	}
	if(flag)
		return i;
	else
		return 0;
}

void main()
{
	int x,y,i=0,a[10]={0};
	printf("请输入一个正整数:\n");
	scanf("%d",&x);
	y = x;
	while(zy(x))
	{
		a[i] = zy(x);
	        x = x / zy(x);
		i++;
	}
	a[i] = x;
	printf("\n%d = ",y);
	for(i=0;i<10;i++)
	{
		if(!a[i] == 0 && !a[i+1] == 0)
			printf("%d*",a[i]);
		else
		{
			printf("%d",a[i]);
			break;
		}
	}
	printf("\n");

}















