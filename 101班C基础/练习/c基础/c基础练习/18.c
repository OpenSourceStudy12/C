/**
*file name:
*function:
*author:L-R-H
*
*/

#include<stdio.h>
void main()
{
	int arr[10],i;
	int *ptr = arr;
	printf("请输入十个整数:\n");
	for(i=0;i<=9;i++)
		scanf("%d",arr[i]);
	for(i = 0;i < 10;i++)
	{
		printf("%d",arr[i]);
	}
	putchar('\n');
	for(i = 0;i < 10;i++)
	{
		printf("%d",ptr[i]);
	}
	putchar('\n');

}
