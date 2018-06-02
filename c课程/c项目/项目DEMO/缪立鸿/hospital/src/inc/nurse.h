#ifndef _NURSE_H
#define _NURSE_H

//#include "common.h"
#define N_MAX_STRING_LEN	32

typedef struct n_NurseInfo
{
	int		n_NurseID;			//护士ID
	char		n_NurseName[N_MAX_STRING_LEN];		//护士姓名
	char		n_pswd[N_MAX_STRING_LEN];			//密码
	char		n_gender;			//性别
	int		n_room;			//科室
	int		n_level;			//护理级别
	int		n_PatientNum;		//护理的患者人数
	int		n_AdviceNum;		//待执行医嘱个数
	struct n_NurseInfo *next;		//下一个护士链表
}NINFO, *PNINFO;

int n_register_from_input(PNINFO s);
int n_register_nurse(PNINFO *head);
int n_link_getLen(PNINFO head);

//PNINFO n_nurse_search_by_data(PNINFO phead, int data, int option);
PNINFO n_nurse_delete(PNINFO head, PNINFO pp);
void n_one_nurse_print(PNINFO head);
void n_nurse_list_print(PNINFO head);
void n_nurse_print_by_level(PNINFO head, int level);
void n_all_nurse_print(PNINFO head);
int n_write_nurse_to_file(PNINFO head);
int n_read_nurse_from_file(PNINFO *head);
int nmain();

int nurse_self_info_man();
int nurse_patient_list_view();
int nurse_all_unexecuted_advice_view();
int nurse_one_unexecuted_advice_view();
int nurse_execute_advice();

#endif
