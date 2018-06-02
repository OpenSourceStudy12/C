/*****************************************
*file name:
*function:数组a包含10个整数，把a中所有的后项除
*以前项之商取整后存入数组b，并按每行3个元素的格式输出数组b
*author:
******************************************/
#include<stdio.h>

void main()
{
	int a[10],b[9];
	int i;
	printf("请输入十个整数:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",a+i);
	
	}
	for(i=0;i<9;i++)
	{
		b[i] = a[i+1]/a[i];
		printf(" %d ",b[i]);
	}
	printf("\n");

}
