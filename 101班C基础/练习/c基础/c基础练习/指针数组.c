/*******************************************
*file name:
*function:
*author:
*********************************************/
#include<stdio.h>
void main()
{
	int a[5];
	int *p[5];
	int i=0;
	while(i<5)
	{
		scanf("%d",a+i);//&a[i]
	
	}
	
	for(i=0;i<5;i++)
	{
		p[i] = &a[i];
	
	}
	for(i=0;i<5;i++)
	{
		printf("a+%d = %p\n",i,a+i);
		printf("&a[%d] = %p\n",i,&a[i]);
		printf("");
	
	}
}
