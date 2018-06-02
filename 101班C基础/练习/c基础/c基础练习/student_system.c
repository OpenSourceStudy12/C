/***************************
**file name:
**function:学生管理菜单
**Author:L-R-H
***************************/

#include<stdio.h>

void main()
{
	char ch;
	printf("\t\t\t\t学生管理菜单\n\n");
	printf("\t\t 增加(0) 删除(1) 修改(2) 查询(3) 退出(4)\n");
	printf("请选择操作:\n");
	ch = getchar();
	switch(ch)
	{
		case '0':
			printf("增加成功\n");
			break;
		case '1':
			printf("删除成功\n");
			break;
		case '2':
			printf("修改成功\n");
			break;
		case '3':
			printf("查询成功\n");
			break;
		case '4':
			printf("您已退出\n");
			break;
		default :
			printf("无效的操作\n");
			break;
	
	}
}

