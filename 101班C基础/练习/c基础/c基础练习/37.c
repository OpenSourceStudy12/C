/**********************************
*file name:
*function:编写程序实现：输入一个整数，判断它能否分别被3、5、7整除，并输出以下信息之一：
********（1）能同时被3、5、7整除
********（2）能被其中两个（要指出哪两个）整除
*********(3）能被其中一个（要指出哪个）整除
********（4）不能被3、5、7中任一个整除
*author:L-R-H
***********************************/
#include<stdio.h>
void main()
{	
	int num,flag_3 = 0,flag_5 = 0,flag_7 = 0;
	printf("请输入一个整数:\n");
	scanf("%d",&num);
	if(num % 3 == 0)
		flag_3 = 1;
	if(num % 5 == 0)
		flag_5 = 1;
	if(num % 7 == 0)
		flag_7 = 1;
	if(flag_3 || flag_5 ||flag_7)
	{
		switch(flag_3)
		{
			case 0:
				if(flag_5 == 0)
					printf("该数能被7整除\n");
				else
				{
					if(flag_7)
						printf("该数能被5和7整除\n");
					else
						printf("该数能被5整除\n");
				}
				break;
			case 1:
				switch(flag_5)
				{
					case 0:
						if(flag_7)
							printf("该数能被3和7整除\n");
						else
							printf("该数能被3整除\n");
						break;
					case 1:
						if(flag_7)
							printf("该数能被3,5和7整除\n");
						else
							printf("该数能被3和5整除\n");
				
						break;

				}
				break;

		
		}
	
	}
	else
		printf("该数不能被3,5和7整除\n");
		
}
	
