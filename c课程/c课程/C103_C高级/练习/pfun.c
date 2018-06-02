#include <stdio.h>

int setbit0(int x,int y);
int setbit1(int x,int y);
int (*pfun)(int x,int y);

int main()
{
	int select;
	int exit_flag=0;
	
	while(1)
	{
		pfun=NULL;
		printf("1.置0\n");
		printf("2.置1\n");
		printf("3.退出\n");
		scanf("%d",&select);
		switch(select)
		{
		case 1:
			pfun=setbit0;
		break;
		case 2:
			pfun=setbit1;
		break;
		case 3:
			printf("exit!\n");
			exit_flag=1;
		break;
		default:
			printf("输入错误，请重新输入!\n");
		break;
		}
		if(exit_flag)
		{
			break;
		}
		if(pfun!=NULL)
		{
			pfun(45,2);
		}
	}
}
int setbit1(int x,int y)
{
	printf("func:%s\n",__func__);
}
int setbit0(int x,int y)
{
	printf("func:%s\n",__func__);
}
