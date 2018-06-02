/********************************
*file name:
*function:
*aythor:L-R-H
*********************************/
#include<stdio.h>

void main()
{
	int num = 0;
	char ch;
	printf("请输入一个整数:\n");
	scanf("%d",num);
	
/*	while((ch = getchar()) != '\n')
	{	
		num += (int) ch * s;
		s *= 10;
	}
*/
	ch = getchar();
	do
	{
		
	 s *= 10;
	}while((ch = getchar()) != '\n');
	printf("反转数是:%d",num);	
	


}

