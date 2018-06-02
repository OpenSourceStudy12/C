/**************************************************************
File Name:		doctor.c
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
#include "doctor.h"
#include "patient.h"
#include "shared.h"
#include "tooler.h"

/*******************************************************
函数名:	int d_register_from_input(PDINFO s)
功能:	挂号时用户输入信息赋值给结构体指针s
输入:	malloc分配的指针s
返回值:	成功返回0,失败返回-1
*******************************************************/
int d_register_from_input(PDINFO s)
{
	char str[D_MAX_STRING_LEN];
	printf("医生姓名\n");
	scanf("%s",str);
	strncpy(s->d_DocName,str,D_MAX_STRING_LEN);
	printf("性别:1:男,2,女\n");
	s->d_gender = (input_num_check(1,2)==1) ? 'm':'f';
	printf("科室\n");
	scanf("%d",&s->d_room);
	printf("主治项目\n");
	scanf("%s",str);
	strncpy(s->d_MainClass,str,D_MAX_STRING_LEN);
	s->d_PatientNum = 0;		//默认创建时患者个数为零
	return 0;
}

/*********************************************************
int d_register_doc(PDINFO *head)
*********************************************************/
int d_register_doc(PDINFO *head)
{
	PDINFO s=NULL,tail = NULL,p = NULL; 
	char input;
	char tempstr[D_MAX_STRING_LEN];
	int ret;

	s=(PDINFO)malloc(sizeof(DINFO));
	if(s==NULL)
	{
		printf("malloc error file:%s line:%d\n",__FILE__,__LINE__);
		return -1;
	}
	
	d_register_from_input(s);		//人工输入
	s->next = NULL;
	if(*head == NULL)		//添加第一个节点
	{
		s->d_DocID = 1;
		*head = s;
		s_update_all_doc_head(s);
	}
	else					//添加其他节点
	{
		p = *head;
		while(NULL != p){
			tail = p;
			p=p->next;
		}
		s->d_DocID = tail->d_DocID +1;
		tail->next = s;
	}
	sprintf(tempstr,"%d",s->d_DocID);
	strcpy(s->d_pswd,tempstr);
	printf("创建成功!是否写入文件?[y/n]\n");
	setbuf(stdin,NULL);
	scanf("%c",&input);
	if(input == 'y')
	{
		ret = d_write_doc_to_file(*head);
		if(ret == 0){
			printf("写入文件成功!按回车键继续\n");
			t_pause();
		}
	}
	
	return 0;
}

/*********************************************************

*********************************************************/
int d_link_getLen(PDINFO head)
{
	int len=0;
	PDINFO p=head;
	while(p!=NULL)
	{
		len++;
		p = p->next;
	}
	return len;

}

/*********************************************************

*********************************************************/
PDINFO d_doc_delete(PDINFO head, PDINFO pd)
{
	PDINFO q=NULL,ptail = NULL;
	PDINFO p = head;

	if(NULL == head || NULL == pd){
		printf("删除存在空指针\n");
	}
	if(head == pd)//删除第一个节点
	{
		q=head;
		head=head->next;
		free(q);
	}
	else{
		while(p != pd && p != NULL)	//防止链表断裂后死循环
		{
			ptail = p;
			p = p->next;
		}
		if(ptail != NULL)
		{
			q = ptail->next;
			ptail->next = q->next;
			free(q);
		}
	}
	return head;
}

/*********************************************************
void d_one_doc_print(PDINFO phead)
*********************************************************/
void d_one_doc_print(PDINFO phead)
{
	PDINFO p = phead;
	if(phead==NULL)
	{
		printf("没有医生信息\n");
	}
	
	printf("%d\t%s\t%c\t%d\t%s\t%d\n",p->d_DocID,p->d_DocName,p->d_gender,p->d_room,p->d_MainClass,p->d_PatientNum);
}

/*********************************************************
void d_doc_list_print(PDINFO phead)
*********************************************************/
void d_doc_list_print(PDINFO phead)
{
	PDINFO p = phead;
	if(phead==NULL)
	{
		printf("没有医生信息\n");
	}
	else
	{
		//system("clear");
		while(NULL != p)
		{
			printf("%d\t%s\n",p->d_DocID,p->d_DocName);
			p = p->next;
		}
	}
}

/*********************************************************

*********************************************************/
void d_doc_print_by_room(PDINFO head, int room)
{
	PDINFO p = head;
	if(head==NULL)
	{
		printf("护士列表为空\n");
	}
	else
	{
		printf("医生ID 姓名\t性别\t科室 主治项目 患者个数\n");
		while(p!=NULL)
		{
			if(p->d_room == room)
			{
				printf("%d\t%s\t%c\t%d\t%s\t%d\n",p->d_DocID,p->d_DocName,p->d_gender,p->d_room,p->d_MainClass,p->d_PatientNum);
			}
			p = p->next;
		}
		printf("\n");
	}
}
/*********************************************************
void d_all_doc_print(PDINFO phead)
*********************************************************/
void d_all_doc_print(PDINFO phead)
{
	PDINFO p = phead;
	if(phead==NULL)
	{
		printf("没有医生信息\n");
	}
	else
	{
		printf("医生ID 姓名\t性别\t科室 主治项目 患者个数\n");
		while(NULL != p)
		{
			printf("%d\t%s\t%c\t%d\t%s\t%d\n",p->d_DocID,p->d_DocName,p->d_gender,p->d_room,p->d_MainClass,p->d_PatientNum);
			p = p->next;
		}
	}
}

/*********************************************************

*********************************************************/
int d_write_doc_to_file(PDINFO head)
{
	FILE *fp = NULL;
	PDINFO p = head;
	int ret;

	fp = fopen("../data/doctor","wb");
	if(NULL == fp){
		printf("open file error\n");
		return -1;
	}
	while(NULL != p){
		ret = fwrite(p,sizeof(DINFO),1,fp);
		if(ret < 0)
		{
			printf("write file error\n");
			return -1;
		}
		p = p->next;
	}

	//printf("write_to_file: ret = %d\n",ret);
	fclose(fp);
	return ret;
}

/*********************************************************

*********************************************************/
int d_read_doc_from_file(PDINFO *head)
{
	int ret = 1;
	PDINFO p = NULL,ptail = NULL;
	FILE *fp = NULL;
	
	fp = fopen("../data/doctor","rb");
	if(NULL == fp){
		printf("open file error\n");
		return -1;
	}
	//do not use feof
	while(1)
	{
		p = (PDINFO)malloc(sizeof(DINFO));
		assert(p != NULL);
		ret = fread(p,sizeof(DINFO),1,fp);
		if(ret == 0){
			return ret;
		}else if(ret < 0){
			printf("read error\n");
			return -1;
		}

		p->next = NULL;		
		if(NULL == *head)
		{
			*head = p;
		}else{
			ptail->next = p;
		}
		ptail = p;
	}
	if(NULL != p)		//文件为空
	{
		free(p);
	}
	//printf("p_read_from_file: ret = %d\n",ret);
	fclose(fp);
	return ret;
}

/*********************************************************

*********************************************************/
int doctor_self_info_man()
{
	int input;
	PDINFO phead = s_get_all_doc_head();
	PDINFO pd = s_get_named_doc_head();
	char ch;
	printf("医生ID 姓名\t性别\t科室 主治项目 患者个数\n");
	d_one_doc_print(pd);
	printf("0:全部修改,1:医生姓名,2:密码,3:性别,4:科室5:主治项目6:患者个数99:退出\n");
	scanf("%d",&input);
	switch(input)
	{
		case 1: printf("输入姓名\n"); scanf("%s",pd->d_DocName); break;
		case 2: printf("输入密码\n"); scanf("%s",pd->d_pswd); break;
		case 3: printf("输入性别\n"); printf("性别:1:男,2,女\n");pd->d_gender = (input_num_check(1,2)==1) ? 'm':'f';break;
		case 4: printf("输入科室\n"); scanf("%d",&pd->d_room); break;
		case 5: printf("输入主治项目\n"); scanf("%s",pd->d_MainClass); break;
		case 6: printf("输入患者个数\n"); scanf("%d",&pd->d_PatientNum); break;
		case 0:
		{
			printf("输入医生ID\n"); scanf("%d",&pd->d_DocID);
			printf("输入姓名\n"); scanf("%s",pd->d_DocName);
			printf("输入密码\n"); scanf("%s",pd->d_pswd);
			printf("性别:1:男,2,女\n");
				pd->d_gender = (input_num_check(1,2)==1) ? 'm':'f';
			printf("输入科室\n"); scanf("%d",&pd->d_room);
			printf("输入主治项目\n"); scanf("%s",pd->d_MainClass);
			printf("输入患者个数\n"); scanf("%d",&pd->d_PatientNum);
			break;
		}
		case 99: return D_MENU;
		default: break;
	}
	printf("确认写入文件?[y/n]\n");
	setbuf(stdin,NULL);
	if((ch = getchar()) == 'y')
	{
		d_write_doc_to_file(phead);
	}else if(input == 2){
		phead = d_doc_delete(phead,pd);
	}else if(input == 99){
		return D_MENU;
	}
	return D_MENU;
}

/*********************************************************

*********************************************************/
int doctor_patient_list_view()
{
	PPINFO phead = s_get_all_patient_head();
	
	p_all_patient_print(phead);
	t_pause();
	
	return D_MENU;
}

/*********************************************************

*********************************************************/
int doctor_patient_advice_view()
{
	int input;
	PPINFO phead  = NULL;
	PPINFO pp = NULL;
	int anum;

	phead = s_get_all_patient_head();
	p_all_patient_print(phead);
	printf("1:查看单个病人医嘱,2.查看所有病人医嘱99:退出\n");
	scanf("%d",&input);
	if(input == 1){
		printf("输入需要查看的病人序号\n");
		scanf("%d",&input);
		system("clear");
		pp = p_patient_search_by_data(phead,input,1);
		if(NULL == pp)
		{
			printf("没有找到该患者\n");
			t_pause();
			return N_MENU;
		}
		printf("患者 %s:\n",pp->p_PatName);
		anum = p_advice_print(pp,0);
		t_pause();
	}else if(input == 2){
		p_all_patient_advice_view();
		t_pause();
	}
	return D_MENU;
}

/*********************************************************

*********************************************************/
int doctor_patient_advice_modify()
{
	int status;
	int input;
	PPINFO phead = s_get_all_patient_head();
	PPINFO pp = NULL;
	PAINFO pahead = NULL;
	PAINFO pa = NULL;
	char ch;
	
	status = p_all_patient_advice_view();
	printf("请输入需要维护的患者编号,输入99退出\n");
	setbuf(stdin,NULL);
	scanf("%d",&input);
	if(input == 99)
	{
		return D_MENU;
	}
	pp = p_patient_search_by_data(phead,input,1);
	if(NULL == pp)
	{
		printf("没有找到该患者\n");
		t_pause();
		return D_MENU;
	}
	pahead = pp->a_FirstAdvice;
	if(NULL == pahead){
		printf("该患者没有医嘱,请先创建医嘱\n");
		t_pause();
		return D_MENU;
	}
	system("clear");
	status = p_advice_print(pp,0);
	printf("输入需要修改的医嘱号\n");
	scanf("%d",&input);
	pa = p_advice_search_by_index(pahead,input);
	if(NULL == pa)
	{
		printf("没有找到该医嘱\n");
		t_pause();
		return D_MENU;
	}
	if(pa->a_mark != 0)			//状态为已执行医嘱
	{
		printf("该医嘱已被执行,不可更改\n");
		t_pause();
		return D_MENU;
	}
	printf("0.全部修改,1:医嘱信息,2:执行护士,99:退出\n");
	scanf("%d",&input);
	switch(input)
	{
		case 1: printf("输入医嘱\n"); scanf("%s",pa->a_AdviceInfo); break;
		case 2: input_advice_nurse_name(pa); break;
		case 0:
		{
			printf("输入医嘱\n"); scanf("%s",pa->a_AdviceInfo);
			input_advice_nurse_name(pa); break;
			break;
		}
		case 99: return D_MENU;
		default: break;
	}
	printf("确认写入文件?[y/n]\n");
	setbuf(stdin,NULL);
	if((ch = getchar()) == 'y')
	{
		p_write_patient_to_file(phead);
	}
	setbuf(stdin,NULL);
	return D_MENU;
}

/*********************************************************

*********************************************************/
int doctor_patient_create_advice()
{
	int status;
	int input;
	PPINFO phead = s_get_all_patient_head();
	PPINFO pp = NULL;
	PDINFO pd = s_get_named_doc_head();
	char ch;
	
	p_all_patient_print(phead);
	printf("请输入需要创建医嘱的患者编号,输入99退出\n");
	scanf("%d",&input);
	if(input == 99)
	{
		return D_MENU;
	}
	pp = p_patient_search_by_data(phead,input,1);
	if(NULL == pp)
	{
		printf("没有找到该患者\n");
		return D_MENU;
	}
	status = p_add_advice(pp,pd);
	strcpy(pp->p_DocName,pd->d_DocName);		//挂号时才将医生姓名赋值给患者信息
	strcpy(pp->p_NurseName,s_get_named_nurse_head()->n_NurseName);	//挂号时才将护士姓名赋值给患者信息
	printf("确认写入文件?[y/n]\n");
	setbuf(stdin,NULL);
	if((ch = getchar()) == 'y')
	{
		p_write_patient_to_file(phead);
	}
	return D_MENU;
}
