/**************************
*****file name:
*****function:
*****author:L-R-H
****************************/

#include<stdio.h>

void main()
{
	int t;
	printf("请输入星期:\n");
	scanf("%d",&t);
	switch(t)
	{
		case 1:
			printf("鱼香肉丝\n");
			break;
		case 2:
			printf("肉模茄子\n");
			break;
		case 3:
			printf("红烧鲫鱼\n");
			break;
		case 4:
			printf("酸辣土豆丝\n");
			break;
		case 5:
			printf("鱼籽拌饭\n");
			break;
		case 6:
			printf("红烧肉\n");
			break;
		case 7:
			printf("佛跳墙\n");
			break;
		default:
			printf("Error!\n");
			break;
	
	}

}
