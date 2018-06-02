/*********************************************
*file name:
*function:存储10个学生的成绩，按照从高到底的顺序输出
*author:
*********************************************/
#include<stdio.h>
 
void main()
{
	float gre[10],*p=gre;
	int i,j;
	float temp;
	printf("请输入10个学生成绩:\n");
	for(i=0;i<10;i++)
	{
		scanf("%f",gre+i);
	
	}
	for(i=0;i<9;i++)
	{
		for(j=0;j<9-i;j++)
		{
			if(p[j] < p[j+1])
			{
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			
			}
		
		}
	
	}
	for(i=0;i<10;i++)
	{
		printf("%.2f\n",p[i]);
	
	}




}
