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
void function(float arr[],int num,float *max,int *max_i)
{
	float max_value;
	int i;
	max_value=arr[0];
	*max_i=0;
	for(i=1;i<num;i++)
	{
		if(arr[i]>max_value)
		{
			max_value=arr[i];
			*max_i=i;
		}
	}
	*max=max_value;
}

int main()
{
	float score[STU_NUM]={1,2,3,4,5,16,7,8,9,10};
	float max;
	int flag;
	function(score,STU_NUM,&max,&flag);
	printf("max=%f, xiaobiao=%d\n",max,flag);
}
