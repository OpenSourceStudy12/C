/*
if(表达式1)
{
		if(表达式2)
		{
		}
		else
		{
		}
}
else
{
		if(表达3)
		{
		}
		else
		{

		}

}
*/

#include <stdio.h>
int main()
{
		float score;
		printf("请输入一个学生的成绩:\n");
		scanf("%f",&score);
		if(score<0||score>100)
		{
				printf("非法数据\n");
		}
		else if(score >=90)
		{
				printf("A\n");
		}
		else if(score>=80&&score<90)
		{
				printf("B\n");
		}
		else if(score>=70&&score<80)
		{
				printf("C\n");
		}
		else if(score>=60&&score<70)
		{
				printf("D\n");
		}
		else
		{
				printf("E\n");
		}

}
