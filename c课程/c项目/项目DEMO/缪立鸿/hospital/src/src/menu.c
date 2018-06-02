/**************************************************************
File Name:		main.c
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
#include "menu.h"
#include "patient.h"
#include "doctor.h"
#include "nurse.h"
#include "admin.h"
#include "shared.h"
#include "tooler.h"

#define MAX_TRIAL_TIMES	3


/*****************************************************************
int welcome_msg()
*****************************************************************/
int welcome_msg(){
	int input;
	system("clear");
	printf("欢迎登录护理诊疗系统\n");
	printf("请选择用户登录\n");
	printf("\t1. 患者登录\n");
	printf("\t2. 医务人员登录\n");
	printf("\t3. 管理员登录\n");
	printf("\t4. 退出系统\n");
	input = input_num_check(1,4);
	return MAIN_MENU + input;
}

/*****************************************************************
int patient_menu()
*****************************************************************/
int patient_menu()
{
	int input;
	PPINFO pp = s_get_named_patient_head();
	system("clear");
	printf("%s你好\n",pp->p_PatName);
	printf("患者选项\n");
	printf("\t1.个人信息查看\n");
	printf("\t2.个人信息修改\n");
	printf("\t3.查看所有医嘱\n");
	printf("\t4.注销登录\n");
	input = input_num_check(1,5);
	return P_MENU + input;
}

/*****************************************************************
int doctor_menu
*****************************************************************/
int doctor_menu()
{
	int input;
	PDINFO pd = s_get_named_doc_head();
	system("clear");
	printf("%s医生你好\n",pd->d_DocName);
	printf("医生选项\n");
	printf("\t1.个人信息维护\n");
	printf("\t2.查看患者列表\n");
	printf("\t3.查询患者医嘱列表\n");
	printf("\t4.医嘱更改\n");
	printf("\t5.诊断开出医嘱\n");
	printf("\t6.注销登录\n");
	input = input_num_check(1,7);
	return D_MENU + input;
}

/*****************************************************************
int nurse_menu
*****************************************************************/
int nurse_menu()
{
	int input;
	PNINFO pn = s_get_named_nurse_head();
	system("clear");
	printf("%s护士你好\n",pn->n_NurseName);
	printf("护士选项\n");
	printf("\t1.个人信息维护\n");
	printf("\t2.查看患者列表\n");
	printf("\t3.查询所有待执行医嘱列表\n");
	printf("\t4.查看某患者待执行医嘱列表\n");
	printf("\t5.执行医嘱\n");
	printf("\t6.注销登录\n");
	input = input_num_check(1,7);
	return N_MENU + input;
}
/*****************************************************************
int admin_menu()
*****************************************************************/
int admin_menu()
{
	int input;
	PADINFO pad  = s_get_named_admin_head();
	system("clear");
	printf("%s管理员你好\n",pad->ad_name);
	printf("管理员选项\n");
	printf("\t1.个人信息维护\n");
	printf("\t2.患者挂号\n");
	printf("\t3.患者信息维护\n");
	printf("\t4.医生信息维护\n");
	printf("\t5.护士信息维护\n");
	printf("\t6.注销登录\n");
	input = input_num_check(1,6);
	return A_MENU + input;
}

/*****************************************************************
void system_exit()
*****************************************************************/
void system_exit()
{
	s_destroy_all();		//回收所有malloc的空间
	exit(0);
}

/*****************************************************************
int confirm_exit(int status)
*****************************************************************/
void confirm_exit(void)
{
	char input;
	printf("确认退出?[y/n]\n");
	setbuf(stdin,NULL);
	scanf("%c",&input);
	setbuf(stdin,NULL);
	if(input == 'y')
	{
		system_exit();		//exit
	}
}

/*****************************************************************
int select_from_menu(int status)
*****************************************************************/
int select_from_menu(int status)
{
	static int previous_status = 0;
	switch (status)
	{
		case MAIN_MENU: status = welcome_msg(); break;
		case PATIENT_LOGIN: status = patient_menu(); break;			//login complete
		case P_MENU: status = patient_menu(); break;			//login complete
		case D_MENU: status = doctor_menu(); break;				
		case N_MENU: status = nurse_menu(); break;
		case A_MENU: status = admin_menu(); break;
		case EXIT_PROGRAM: confirm_exit();	break;		//should not enter here
		default: break;
	}
	previous_status = status;
	return status;
}

/*****************************************************************
int personnel_login()
*****************************************************************/
int personnel_login()
{
	char UserName[P_MAX_STRING_LEN];
	char password[P_MAX_STRING_LEN];
	PDINFO dhead = NULL;
	PDINFO pd = NULL;
	PNINFO nhead = NULL;
	PNINFO pn = NULL;
	int i;

	system("clear");
	printf("医务人员登录\n");
	printf("请输入用户名\n");
	
	dhead = s_get_all_doc_head();
	nhead = s_get_all_nurse_head();
	for(i = 0; i < MAX_TRIAL_TIMES; i++){
		scanf("%s",UserName);
		pd = s_search_doc_by_name(dhead,UserName);
		pn = s_search_nurse_by_name(nhead,UserName);
		if(NULL == pd && NULL == pn)	//找不到用户名
		{
			printf("用户名不存在,请重试\n");
		}else{
			break;
		}
	}
	if(i >= MAX_TRIAL_TIMES)
	{
		printf("超过最大输入次数,返回\n");
		t_pause();
		return MAIN_MENU;
	}
	setbuf(stdin,NULL);
	printf("请输入密码\n");
	if(NULL != pd){
		for(i = 0; i < MAX_TRIAL_TIMES; i++)
		{
			//scanf("%s",password);
			t_get_password(password);
			if(strcmp(password,pd->d_pswd)){
				printf("密码错误,请重试\n");
			}else{
				break;
			}
		}
		if(i < MAX_TRIAL_TIMES){
			return D_MENU;
		}
	}else if(NULL != pn){
		for(i = 0; i < MAX_TRIAL_TIMES; i++)
		{
			//scanf("%s",password);
			t_get_password(password);
			if(strcmp(password,pn->n_pswd)){
				printf("密码错误,请重试\n");
			}else{
				break;
			}
		}
		if(i < MAX_TRIAL_TIMES){
			return N_MENU;
		}
	}
	return MAIN_MENU;
}

int patient_menu_back(){return MAIN_MENU;}
int doctor_menu_back(){return MAIN_MENU;}
int nurse_menu_back(){return MAIN_MENU;}
int admin_menu_back(){return MAIN_MENU;}
/*****************************************************************
int select_from_menu(cmd)
*****************************************************************/
int dispatch_from_cmd(int status)
{
	static int previous_status = 0;
	//printf("previous_status = %d\n",previous_status);
	switch(status)
	{
		case MAIN_MENU:	 break;							//should not enter here
		case PATIENT_LOGIN:	 status = patient_login(); break;
		case PERSONNEL_LOGIN:	 status = personnel_login(); break;
		case ADMIN_LOGIN:	 status = admin_login(); break;
		case EXIT_PROGRAM:	 confirm_exit(); status = previous_status; break;

		case P_P_VIEW:	 status = patient_info_view(); break;
		case P_P_MODIFY:	 status = patient_info_modify(); break;
		case P_A_VIEW:	 status = patient_one_advice_view(); break;
		case P_MENU_BACK	:	 status = patient_menu_back(); break;

		case D_D_MODIFY:	 status = doctor_self_info_man(); break;
		case D_P_VIEW:	 status = doctor_patient_list_view(); break;
		case D_A_VIEW:	 status = doctor_patient_advice_view(); break;
		case D_A_MODIFY: status = doctor_patient_advice_modify(); break;
		case D_A_CREATE: status = doctor_patient_create_advice(); break;
		case D_MENU_BACK: status = doctor_menu_back(); break;

		case N_N_MODIFY: status = nurse_self_info_man(); break;
		case N__P_VIEW: status = nurse_patient_list_view(); break;
		case N_UA_VIEW: status = nurse_all_unexecuted_advice_view(); break;
		case N_EA_VIEW: status = nurse_one_unexecuted_advice_view(); break;
		case N_A_EXE: status = nurse_execute_advice(); break;
		case N_MENU_BACK: status = nurse_menu_back(); break;

		case A_A_MODIFY:  status = admin_self_info_man(); break;
		case A_P_REG:  status = admin_patient_register(); break;
		case A_P_MODIFY:  status = admin_patient_info_man(); break;
		case A_D_MODIFY:  status = admin_doc_info_man(); break;
		case A_N_MODIFY:  status = admin_nurse_info_man(); break;
		case A_MENU_BACK:	 status = admin_menu_back(); break;

		case -1:	 status = previous_status; break;		//出错后转入这里,方便用户返回到上一级菜单
		default: printf("无法识别的菜单号\n"); t_pause(); break;
	}
	previous_status = status;
	return status;
}

