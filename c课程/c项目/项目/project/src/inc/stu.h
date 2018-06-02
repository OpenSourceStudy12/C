/*
*版权  学生管理系统
*文件名：stu.h
*作者：wxh
*日期：2013/02/22
*修改：新建
**/
#ifndef _STU_H
#define _STU_H
/**************头文件包含**************/
#include "common.h"
/**************头文件包含**************/

/**************结构定义 宏定义*********/
typedef struct student 
{
	int num;
	char name[20];
	int age;
	float chinese;
	float c_score;
	float math;
	struct student *next;
}STU,*stu_list;
/**************结构定义 宏定义*********/

#endif
