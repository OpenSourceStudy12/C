/*
*��Ȩ  ѧ������ϵͳ
*�ļ�����stu.h
*���ߣ�wxh
*���ڣ�2013/02/22
*�޸ģ��½�
**/
#ifndef _STU_H
#define _STU_H
/**************ͷ�ļ�����**************/
#include "common.h"
/**************ͷ�ļ�����**************/

/**************�ṹ���� �궨��*********/
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
/**************�ṹ���� �궨��*********/

#endif
