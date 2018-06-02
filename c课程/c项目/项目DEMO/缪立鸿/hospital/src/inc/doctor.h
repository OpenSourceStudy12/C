#ifndef _DOCTOR_H
#define _DOCTOR_H

//#include "common.h"

#define D_MAX_STRING_LEN	32

typedef struct d_DocInfo
{
	int		d_DocID;								//医生ID
	char		d_DocName[D_MAX_STRING_LEN];		//医生姓名
	char		d_pswd[D_MAX_STRING_LEN];			//密码
	char		d_gender;								//性别
	int		d_room;								//科室
	char		d_MainClass[D_MAX_STRING_LEN];		//主治项目
	int		d_PatientNum;							//患者个数
	struct d_DocInfo *next;							//下一个医生链表
}DINFO, *PDINFO;

int d_register_from_input(PDINFO s);
int d_register_doc(PDINFO *head);
int d_link_getLen(PDINFO head);

//PDINFO d_doc_search_by_data(PDINFO phead, int data, int option);
PDINFO d_doc_delete(PDINFO head, PDINFO pp);
void d_one_doc_print(PDINFO phead);
void d_doc_list_print(PDINFO phead);
void d_all_doc_print(PDINFO phead);
int d_write_doc_to_file(PDINFO head);
int d_read_doc_from_file(PDINFO *head);
int dmain();
int doctor_self_info_man();
int doctor_patient_list_view();
int doctor_patient_advice_view();
int doctor_patient_advice_modify();
int doctor_patient_create_advice();

int doctor_self_info_man();
int doctor_patient_list_view();
int doctor_patient_advice_view();
int doctor_patient_advice_modify();
int doctor_patient_create_advice();

#endif

