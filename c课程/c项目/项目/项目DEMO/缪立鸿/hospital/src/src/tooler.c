/**************************************************************
File Name:		tooler.c
Created:			Miao Lihong
				All Rights Reserved
Creat Date:		May, 21, 2013
Last Modification:	May, 27, 2013
Latest Version:		0.1.0
Notification: 	This source code is designed for self entertainment and education use only. 
			Do not use this for business purpose.
Description:	This program is a simple project of hospital administration. Admin, patient, 
			doctor and nurse will use this for different purposes.
			If you have any idea to improve this program, pls feel free to email me:	
			lhmiao@gmail.com
**************************************************************/
#include "common.h"
#include "tooler.h"
#include "patient.h"
#include "doctor.h"
#include "nurse.h"
#include "shared.h"
#include <termios.h>
#include <unistd.h>

#define T_MAX_TRIAL_TIMES	3

struct termios stored_settings;

/************************************************
function name	:set_keypress
function		:set terminal single-key input read mode
input parameter	:
return value	:
description	:
*************************************************/
void set_keypress(void)
{
	struct termios new_settings;
	tcgetattr(0,&stored_settings);
	new_settings = stored_settings;

	/*Disable canonical mode, and set buffer size to 1 byte */
	new_settings.c_lflag &= (~ICANON);
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;
	tcsetattr(0,TCSANOW,&new_settings);
}

/***************************************************
function name	:reset_keypress
function		:
input parameter	:
return value	:
description	:(set to default read key mode)function is not used
****************************************************/
void reset_keypress(void)
{
	tcsetattr(0,TCSANOW,&stored_settings);
	return;
}

/***************************************************
function name	:echo_off
function		:
input parameter	:
return value	:
description	:set terminal to no-echo mode(no remapping keyboard)
****************************************************/
void echo_off(void)
{
	struct termios new_settings;
	
	tcgetattr(0,&stored_settings);
	new_settings = stored_settings;
	new_settings.c_lflag &= (~ECHO);
	tcsetattr(0,TCSANOW,&new_settings);

	return;
}

/***************************************************
function name	:echo_on
function		:
input parameter	:
return value	:
description	:set terminal to default display mode
****************************************************/
void echo_on(void)
{
	tcsetattr(0,TCSANOW,&stored_settings);
	return;
}

int t_get_password(char password[])
{
	char ch;
	int count = 0;
	//char password[10] = {0};
	
	char *pstr = password;
	setbuf(stdin,NULL);
	//set_keypress();
	//echo_off();

	while((ch = getchar()) != '\n' && count < P_MAX_STRING_LEN)
	{
	//	putchar('*');
		*pstr++ = ch;
		count++;
	}
	*pstr = '\0';
	//echo_on();
	//reset_keypress();
	setbuf(stdin,NULL);
	setbuf(stdout,NULL);
	return 0;
}

/*****************************************************************
void t_pause()
*****************************************************************/
void t_pause()
{
	setbuf(stdin,NULL);
	getchar();
	setbuf(stdin,NULL);
}
/*****************************************************************
int input_num_check(int min, int max)
*****************************************************************/
int input_num_check(int min, int max)
{
	int i,input;
	for(i = 0; i < T_MAX_TRIAL_TIMES; i++){
		setbuf(stdin,NULL);
		scanf("%d",&input);
		if(input >= min && input <= max)
		{
			break;
		}else{
			printf("输入有误,请重试\n");
		}
	}
	if(i < T_MAX_TRIAL_TIMES){
		return input;
	}else{
		printf("超过最大尝试次数,返回\n");
		t_pause();
		return 0;
	}
}

/*****************************************************************
int input_doc_name(PPINFO s)
*****************************************************************/
int input_doc_name(PPINFO s)
{
	int input;
	PDINFO pd = s_get_all_doc_head();
	d_doc_list_print(pd);
	printf("输入主治医生ID\n");
	scanf("%d",&input);
	pd = d_doc_search_by_data(pd,input,1);
	if(NULL == pd)
	{
		printf("医生ID序号输入错误\n");
		return -1;
	}
	strcpy(s->p_DocName,pd->d_DocName);	//医生姓名直接拷贝到患者信息中
	(pd->d_PatientNum)++;					//医生的下属患者数加1
	return 0;
}

/*****************************************************************
int input_nurse_name(PPINFO s)
*****************************************************************/
int input_nurse_name(PPINFO s)
{
	int input;
	PNINFO pn = s_get_all_nurse_head();
	n_nurse_list_print(pn);
	printf("输入护士ID\n");
	scanf("%d",&input);
	pn = n_nurse_search_by_data(pn,input,1);
	if(NULL == pn)
	{
		printf("医生ID序号输入错误\n");
		return -1;
	}
	strcpy(s->p_NurseName,pn->n_NurseName);		//护士姓名直接拷贝到患者信息中
	(pn->n_PatientNum)++;							//护士的下属患者数加1
	return 0;
}

/*****************************************************************
int input_advice_doc_name(PAINFO s)
*****************************************************************/
int input_advice_doc_name(PAINFO s)
{
	int input;
	PDINFO pd = s_get_all_doc_head();
	d_doc_list_print(pd);
	printf("输入主治医生ID\n");
	scanf("%d",&input);
	pd = d_doc_search_by_data(pd,input,1);
	if(NULL == pd)
	{
		printf("医生ID序号输入错误\n");
		return -1;
	}
	strcpy(s->a_DocName,pd->d_DocName);
	return 0;
}

/*****************************************************************
int input_advice_nurse_name(PAINFO s)
*****************************************************************/
int input_advice_nurse_name(PAINFO s)
{
	int input;
	PNINFO pn = s_get_all_nurse_head();
	n_all_nurse_print(pn);
	printf("输入护士ID\n");
	scanf("%d",&input);
	pn = n_nurse_search_by_data(pn,input,1);
	if(NULL == pn)
	{
		printf("医生ID序号输入错误\n");
		return -1;
	}
	strcpy(s->a_NurseName,pn->n_NurseName);	return 0;
}

/*****************************************************************
char *input_string_check(char *str, int len)
*****************************************************************/
int input_string_check(char *str, int len)
{
	int i;
	char input[P_MAX_STRING_LEN];
	for(i = 0; i < T_MAX_TRIAL_TIMES; i++){
		scanf("%s",input);
		//if(input >= min && input <= max)
		//{
		//	break;
		//}else{
		//	printf("输入有误,请重试\n");
		//}
	}
	if(i < T_MAX_TRIAL_TIMES){
		return 0;
	}else{
		printf("超过最大尝试次数,返回\n");
		t_pause();
		return 0;
	}
}
