/*
*
*
*/
/*头文件包含*/
#include <stdio.h>
#include <assert.h>
/*宏定义 结构定义*/
#define STU_NUM 10
/*全局变量申明*/
/*函数申明，函数原型*/


/*函数的实现*/
void below_arv(float score[],float below[],int arr_num,int *num)
{
	float sum=0,arv;
	int i,below_j=0;
	float *p=score;
	*num =0;
	for(i=0;i<arr_num;i++)
		sum+=*p++;
	arv=sum/arr_num;
	p=score;
	while(p<score+arr_num)
	{
		if(*p<arv)
		{
			below[*num]=*p;
			(*num)++;
		}
		p++;
	}
//	*num=below_j;
}

int main()
{
	float score[STU_NUM]={1,2,3,4,5,6,7,8,9,10};
	float below[STU_NUM]={0};
	int num,i;
	below_arv(score,below,STU_NUM,&num);
	for(i=0;i<num;i++)
	{
		printf("below[%d]=%f\n",i,below[i]);
	}
}
