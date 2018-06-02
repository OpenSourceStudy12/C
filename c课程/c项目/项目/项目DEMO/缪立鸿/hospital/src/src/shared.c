/**************************************************************
File Name:		shared.c
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
#include "shared.h"
#include "patient.h"
#include "doctor.h"
#include "nurse.h"
#include "admin.h"
#include "tooler.h"

//static PPINFO pphead = NULL;				
static PPINFO pp = NULL;					//通过用户名查找到的患者链表地址做全局变量
static PPINFO ppf = NULL;					//读取文件后所有患者的半十字链表
//static PAINFO padvice = NULL;				//医嘱列表
static PDINFO pd = NULL;					//通过用户名查找到的医生链表地址做全局变量
static PDINFO pdf = NULL;					//读取文件后所有医生的链表
static PNINFO pn = NULL;					//通过用户名查找到的护士链表地址做全局变量
static PNINFO pnf = NULL;					//读取文件后所有护士的链表
static PADINFO pad = NULL;					//通过用户名查找到的管理员链表地址做全局变量
static PADINFO padf = NULL;				//读取文件后所有管理员的链表

/*********************************************************
void intit()
*********************************************************/
void init(){
	int status;
	status = p_read_patient_from_file(&ppf);
	status = d_read_doc_from_file(&pdf);
	status = n_read_nurse_from_file(&pnf);
	status = ad_read_admin_from_file(&padf);
	pp = ppf;
	pd = pdf;
	pn = pnf;
	pad = padf;
}


/*********************************************************
PPINFO s_update_all_patient_head(PPINFO phead)	
//为了解决删除头结点后全局指针改变的问题
*********************************************************/
PPINFO s_update_all_patient_head(PPINFO phead){ppf = phead;return phead;}
PDINFO s_update_all_doc_head(PDINFO phead){pdf = phead;return phead;}
PNINFO s_update_all_nurse_head(PNINFO phead){pnf = phead;return phead;}
PADINFO s_update_all_admin_head(PADINFO phead){padf = phead;return phead;}


PPINFO s_get_all_patient_head(){return ppf;}
PDINFO s_get_all_doc_head(){return pdf;}
PNINFO s_get_all_nurse_head(){return pnf;}
PADINFO s_get_all_admin_head(){return padf;}

PPINFO s_get_named_patient_head(){return pp;}
PDINFO s_get_named_doc_head(){return pd;}
PNINFO s_get_named_nurse_head(){return pn;}
PADINFO s_get_named_admin_head(){return pad;}

/*********************************************************
option = 1: 找ID号
option = 2: 未做
*********************************************************/
PPINFO p_patient_search_by_data(PPINFO phead,int data, int option)
{
	PPINFO p=phead;
	//入参检查
	if(phead == NULL)
		return NULL;
	switch(option){
		case 1:						//按ID号查找
		{
			while(p!=NULL)
			{
				if(p->p_PatID == data)
				{
					break;
				}
				p= p->next;
			}
			break;
		}
		default: printf("按患者ID查找患者时选项错误\n"); t_pause(); return phead;
	}
	pp = p;
	return p;
}

/*********************************************************
option = 1: 找ID号
option = 2: 找护理等级
*********************************************************/
PNINFO n_nurse_search_by_data(PNINFO phead,int data, int option)
{
	PNINFO p=phead;
	//入参检查
	if(phead == NULL)
		return NULL;
	switch(option){
		case 1:						//按ID号查找
		{
			while(p!=NULL)
			{
				if(p->n_NurseID == data)
				{
					break;
				}
				p= p->next;
			}
			break;
		}
		case 2:						//按科室查找
		{
			while(p!=NULL)
			{
				if(p->n_level == data)
				{
					break;
				}
				p= p->next;
			}
			break;
		}
		default: printf("按护士信息查找护士时选项错误\n"); t_pause(); return phead;
	}
	pn = p;
	return p;
}


/*********************************************************
option = 1:找ID号
option = 2:找科室
*********************************************************/
PDINFO d_doc_search_by_data(PDINFO phead, int data, int option)
{
	PDINFO p=phead;
	//入参检查
	if(phead == NULL)
		return NULL;
	switch(option){
		case 1:						//按ID号查找
		{
			while(p!=NULL)
			{
				if(p->d_DocID == data)
				{
					break;
				}
				p= p->next;
			}
			break;
		}
		case 2:						//按科室查找
		{
			while(p!=NULL)
			{
				if(p->d_room == data)
				{
					break;
				}
				p= p->next;
			}
			break;
		}
		default: printf("按医生信息查找医生时选项错误\n"); t_pause(); return phead;
	}
	pd = p;
	return p;
}

/*********************************************************
PPINFO s_search_patient_by_name(PPINFO phead, char *str)
*********************************************************/
PPINFO s_search_patient_by_name(PPINFO phead, char *str)
{
	PPINFO p=phead;
	//入参检查
	if(phead == NULL)
		return NULL;
	while(p!=NULL)
	{
		if(!strcmp(p->p_PatName,str))		//文件中找到输入的用户名
		{
			break;
		}
		p= p->next;
	}
	pp = p;							//通过姓名查找到的链表地址做全局变量
	return p;
}

/*********************************************************
PDINFO s_search_doc_by_name(PDINFO phead, char *str)
*********************************************************/
PDINFO s_search_doc_by_name(PDINFO phead, char *str)
{
	PDINFO p = phead;
	//入参检查
	if(phead == NULL)
		return NULL;
	while(p != NULL)
	{
		if(!strcmp(p->d_DocName,str))		//文件中找到输入的用户名
		{
			break;
		}
		p= p->next;
	}
	pd = p;							//通过姓名查找到的链表地址做全局变量
	return p;
}

/*********************************************************
PNINFO s_search_nurse_by_name(PNINFO phead, char *str)
*********************************************************/
PNINFO s_search_nurse_by_name(PNINFO phead, char *str)
{
	PNINFO p = phead;
	//入参检查
	if(phead == NULL)
		return NULL;
	while(p != NULL)
	{
		if(!strcmp(p->n_NurseName,str))		//文件中找到输入的用户名
		{
			break;
		}
		p= p->next;
	}
	pn = p;							//通过姓名查找到的链表地址做全局变量
	return p;
}
/*********************************************************
PADINFO s_search_admin_by_name(PADINFO phead, char *str)
*********************************************************/
PADINFO s_search_admin_by_name(PADINFO phead, char *str)
{
	PADINFO p = padf;
	//入参检查
	if(phead == NULL)
		return NULL;
	while(p != NULL)
	{
		if(!strcmp(p->ad_name,str))		//文件中找到输入的用户名
		{
			break;
		}
		p= p->next;
	}
	pad = p;							//通过姓名查找到的链表地址做全局变量
	return p;
}

/*********************************************************
PPINFO p_patient_destroy(PPINFO head)
*********************************************************/
PPINFO p_patient_destroy(PPINFO head)
{
	PPINFO q = NULL;
	PAINFO pa = NULL;
	PAINFO qa = NULL;

	while(NULL != head)
	{
		q = head;
		pa = q->a_FirstAdvice;
		while(NULL != pa)
		{
			qa = pa;
			pa = pa->next;
			free(qa);
		}
		head = head->next;
		free(q);
	}
	return head;
}

/*********************************************************

*********************************************************/
PDINFO d_doc_destroy(PDINFO head)
{
	PDINFO q=NULL;
	while(head!=NULL)
	{
		q=head;
		head=head->next;
		free(q);
	}
	return head;
}

/*********************************************************

*********************************************************/
PNINFO n_nurse_destroy(PNINFO head)
{
	PNINFO q=NULL;
	while(head!=NULL)
	{
		q=head;
		head=head->next;
		free(q);
	}
	return head;
}

/*********************************************************

*********************************************************/
PADINFO ad_admin_destroy(PADINFO head)
{
	PADINFO q=NULL;
	while(head!=NULL)
	{
		q=head;
		head=head->next;
		free(q);
	}
	return head;
}
/*********************************************************
void destroy_all()
*********************************************************/
void s_destroy_all()
{
	ppf = p_patient_destroy(ppf);
	pdf = d_doc_destroy(pdf);
	pnf = n_nurse_destroy(pnf);
	padf = ad_admin_destroy(padf);
}
