#ifndef _PATIENT_H
#define _PATIENT_H

//#include "common.h"
#include "doctor.h"
#define P_MAX_STRING_LEN	32
#define A_MAX_STRING_LEN	64
#define D_MAX_STRING_LEN	32
#define N_MAX_STRING_LEN	32

typedef struct p_PatientInfo		//患者信息结构
{
	int		p_PatID;								//患者ID
	char		p_PatName[P_MAX_STRING_LEN];		//患者姓名
	char		p_pswd[P_MAX_STRING_LEN];			//密码
	char		p_gender;								//性别
	int		p_age;								//年龄
	char		p_DocName[D_MAX_STRING_LEN];		//主治医生
	char		p_NurseName[N_MAX_STRING_LEN];		//护理护士
	char		p_EnterTime[P_MAX_STRING_LEN];		//入院时间
	char		p_PreDiagnose[P_MAX_STRING_LEN];	//初步诊断
	int		a_AdviceNum;							//病人下属的医嘱数
	struct a_Advice *a_FirstAdvice;					//第一个医嘱链表
	struct p_PatientInfo *next;						//下一个患者链表
}PINFO, *PPINFO;		

typedef struct a_Advice
{
	int	a_AdviceID;							//医嘱ID
	char	a_AdviceInfo[A_MAX_STRING_LEN];		//药品医嘱,治疗,输液,其他
	char	a_DocName[A_MAX_STRING_LEN];		//开具医嘱的医生ID
	char	a_NurseName[A_MAX_STRING_LEN];		//执行护士ID
	int	a_mark;								//是否为已执行医嘱
	struct a_Advice *next;						//下一个医嘱链表
}AINFO,*PAINFO;

int p_register_from_input(PPINFO s);
int p_register_patient(PPINFO *head);
int p_patient_getLen(PPINFO head);
PPINFO p_patient_search_by_data(PPINFO phead, int index, int option);
PPINFO p_patient_insert(PPINFO head, int index, int data);
PPINFO p_patient_delete(PPINFO head, PPINFO pp);
int p_advice_print(PPINFO head, int option);
int p_add_advice_from_input(PAINFO head);
int p_add_advice(PPINFO head, PDINFO pd);
PAINFO p_advice_search_by_index(PAINFO phead,int index);
void p_one_patient_print(PPINFO phead);
void p_all_patient_print(PPINFO head);
int p_write_patient_to_file(PPINFO head);
int p_read_patient_from_file(PPINFO *head);
int pmain();

int patient_login();
int patient_info_view();
int patient_info_modify();
int patient_all_advice_view();
int patient_one_advice_view();
int p_all_patient_advice_view();

#endif
