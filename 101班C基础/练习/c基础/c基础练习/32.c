/***************************************
*file name:
*function:学生管理系统
*author:L-R-H
***************************************/

#include<stdio.h>

void main()
{	
	char ch;
	printf("\t\t\t   学生管理系统\n\n");
	printf("\t\t学生登录0 老师登录1 管理员登录2 退出3\n");
	printf("请选择操作\n\n");
	ch = getchar();
	while(1)
	{	
		if(ch =='0') 
		{	
		   	   printf("\n\n\t\t\t--------------------------\n");
			   printf("\t\t\t学生登录成功\n");
			   printf("\t\t\t\t请选择操作:\n\n");
			   while(1)
		  	  {
		        	  if((ch = getchar()) == '3')
	               		  	  break;
			   }	
		}
		if(ch =='1') 
		{	
		         printf("\n\n\\t\t\t--------------------------\n");
		  	 printf("\t\t\t老师登录成功\n");
		  	 printf("\t\t\t请选择操作:\n\n");
		  	 while(1)
		  	 {
				   if((ch = getchar()) == '3')
					   break;
			  }
		}
		if(ch =='2')
		{
			printf("\n\n\t\t\t--------------------------\n");
		        printf("\t\t\t管理员登录成功\n");
		        printf("\t\t\t请选择操作:\n\n");
		        while(1)
		  	 {
				   if((ch = getchar()) == '3')
					   break;
			 }
		}
		printf("\n\n\t\t\t--------------------------\n");
		printf("\t\t\t   学生管理系统\n");
		printf("\t\t学生登录0 老师登录1 管理员登录2 退出3\n");
		printf("请选择操作\n\n");
		ch = getchar();
		if(ch == '3')
		{
	       		printf("\t\t\t--------------------------\n");
			printf("\n\t\t\t\t已退出\n\n");
		  	break;
		 }
	}
}

