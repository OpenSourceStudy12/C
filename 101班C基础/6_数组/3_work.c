/*
1,定义一个double[4][5]  ,分别打印外层数组每个元素的地址、内层数组每个元素的地址、以及打印每个元素对应的数据


2，定义一个数组存储3个学生两个学期的成绩，数据动态输入，输出每个学生两个学期的成绩并求出每个学生的平均成绩


3,定义一组存储2010-2014年的每月降水量，分别输出每年的总降水量、年平均降水量、月平均降水量


4,定义数组存储10个学生的成绩，输出前三名和后三名
*/

#include <stdio.h>
#define YEAR  5
#define MONTH 12
/*
int main()
{
		float a[10]={67,5,7,78,87,76,90,91,100,99};
		int i,j,temp;
		for(i=0;i<9;i++)
		{
				for(j=0;j<10-i-1;j++)
				{
						if(a[j]<a[j+1])
						{
                                temp=a[j];
								a[j]=a[j+1];
								a[j+1]=temp;
						}
				}
		}

		printf("前三名：\n");
	    for(i=0;i<3;i++)
		{
				printf("%.2f ",a[i]);
		}
		printf("\n");
}
*/

/*
int main()
{
	 float  total=0,ave_total=0;
     float  rain[YEAR][MONTH]={
			 {1.1,2.2,3,4.5,5,6.7,8,8.9,0,0.1,3,5},
			 {1.1,2.6,3,4.5,4,6.7,8,8.9,3,0.1,3,5},
			 {1.6,2.2,4.4,4.5,6.7,6.7,8,8.9,0,2.5,3,5},
			 {7.7,2.2,3,9.0,5,6.7,4.7,8.9,5.6,0.1,6.7,5},
			 {2.3,0,1.2,4.5,5,0,8,8.9,0,0.1,3,5}
	 };
	 int i,j;
	 printf("每年的总降水量:\n");
	 printf("年\t降水量\n");
	 for(i=0;i<YEAR;i++)
	 {
			 for(total=0,j=0;j<MONTH;j++)
			 {
                  total += rain[i][j];
			 }
			 ave_total += total;
			 printf("%d\t%.2f\n",2010+i,total);
	 }
	 printf("年平均降水量：%.2f\n",ave_total/YEAR);
	 printf("一月\t二月\t三月\t四月\t五月\t六月\t七月\t八月\t九月\t十月\t十一\t十二\n");
     for(i=0;i<MONTH;i++)
	 {
			 for(total=0,j=0;j<YEAR;j++)
			 {
                   total+=rain[j][i];
			 }
			 printf("%.2f\t",total/YEAR);
	 }
	 printf("\n");
     
}

*/
/*
int main()
{
		float a[3][2];
		int i,j;
		float ave=0;
		for(i=0;i<3;i++)
		{
				printf("请输入第%d个学生的成绩:\n",i+1);
				for(j=0;j<2;j++)
				{
						scanf("%f",&a[i][j]);
				}
		}
        printf("学号\t第一学期\t第二学期\t平均成绩\n");
		for(i=0;i<3;i++)
		{
				printf("%d\t",i+1);
				for(ave=0,j=0;j<2;j++)
				{ 
                     ave += a[i][j];
                     printf("%.2f\t\t",a[i][j]);
				}
				printf("%.2f\n",ave/2);
		}
}
*/
/*
int main()
{
	double a[4][5];
	int i,j;
	for(i=0;i<4;i++)
	{
			printf("a+%d=%p\n",i,a+i);
	}
	for(i=0;i<4;i++)
	{
			printf("&a[%d]=%p\n",i,&a[i]);
	}
	for(i=0;i<4;i++)
	{
			for(j=0;j<5;j++)
			{
					printf("a[%d]+%d=%p\n",i,j,a[i]+j);
			}
	}
	for(i=0;i<4;i++)
	{
			for(j=0;j<5;j++)
			{
					printf("&a[%d][%d]=%p\n",i,j,&a[i][j]);
			}
	}
//	a[i][j]
}
*/
