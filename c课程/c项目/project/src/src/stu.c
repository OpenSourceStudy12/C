/*
*��Ȩ  ѧ������ϵͳ
*�ļ�����main.c
*���ߣ�wxh
*���ڣ�2013/02/22
*�޸ģ��½�
**/

/**************ͷ�ļ�����**************/
#include "stu.h"
#include <stdio.h>
/**************ͷ�ļ�����**************/


/**************�ṹ���� �궨��*********/

/**************�ṹ���� �궨��*********/

/**************ȫ�ֱ�������************/

/**************ȫ�ֱ�������************/

/***************�ֲ���������***********/

/***************�ֲ���������***********/

/***************����ʵ��******************/
int getchoice()
{
	int num;
	scanf("%d",&num);
	return num;
}
int checkChoice(int num,int xian)
{
	if(num>0&&num<=xian)
		return 0;
	else
		return -1;
}

int stu_op(int state)
{
	int choice;
	int flag;
	mangae_stu_menu();
	choice=getchoice();
	flag=checkChoice(choice,6);
	if(flag != 0)
	{
		printErr();
		return state/10;
	}
	state =state*10+ choice;
	return state;
}

int addStuInfo(int state ,stu_list *head)
{
	//��ӳɹ� ��ӡ��ӳɹ� ���������
	//��ӳɹ� ��ӡ���ʧ�� ���������
	printf("��ӳɹ�\n");
	return state/10;
}

void destoryStuLink(stu_list head)
{
}






