/*******************************************
*file name:
*function:定义一个数组存储3个学生两个学期的成绩，
*数据动态输入，输出每个学生两个学期的成绩并求出每个学生的平均成绩
*author:
*******************************************/
#include<stdio.h>

void main()
{
	int i,j;
	float score[3][2],score_ave[3];
	printf("请输入三个学生的成绩:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("第%d个同学第%d学期成绩：\n",i+1,j+1);
			scanf("%f",score[i]+j);
		}
		score_ave[i] = (score[i][0] + score[i][1])/2;
	
	}
	for(i=0;i<3;i++)
	{
		printf("第%d个同学的成绩是%.2f\n",i+1,score_ave[i]);
	
	}
	



}
