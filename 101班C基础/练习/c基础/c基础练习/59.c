/**************************************************
*file name:
*function:定义一个数组存储10个学生的成绩，找出最高分和最低分
*author:
****************************************************/
#include<stdio.h>
void main()
{
	float gre[10],*p_g = &gre[0],*p;
	int i;
	float max,min;
	printf("输入10个学生的成绩:\n");
	for(i=0;i<10;i++)
	{
		scanf("%f",p_g+i);
	
	}
	for(p=p_g,max = *p_g,min = *p_g;p < p_g+i;p++)
	{
		if(max < *p)
			max = *p;
	       else if(min > *p)
			min = *p;
	}
	printf("max= %.2f min = %.2f\n",max,min);
	
}


