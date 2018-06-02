/*
*file name:
*function:判断月份的天数
*author:L-R-H
*/
#include<stdio.h>

void main()
{
	int year,month;
	int runnian = 0;
	printf("请输入年份和月份:\n");
	scanf("%d%d",&year,&month);	
	if(year%4 == 0 && year%100 != 0 ||year%400 == 0)
		runnian = 1;
	switch(month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			printf("该月31天\n");
		        break;
		case 4:
		case 6:
		case 9:
		case 11:
			printf("该月30天\n");
			break;
		case 2:
			if(runnian)
				printf("该月有29天\n");
			else
				printf("该月有28天\n");
			break;
		default:
			printf("输入错误\n");
	}

}
