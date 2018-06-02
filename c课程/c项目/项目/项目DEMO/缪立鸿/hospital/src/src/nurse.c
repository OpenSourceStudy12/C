/**************************************************************
File Name:		nurse.c
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
#include "nurse.h"
#include "patient.h"
#include "shared.h"
#include "tooler.h"
/*******************************************************
函数名:	int n_register_from_input(PNINFO s)
功能:	挂号时用户输入信息赋值给结构体指针s
输入:	malloc分配的指针s
返回值:	成功返回0,失败返回-1
*******************************************************/
int n_register_from_input(PNINFO s)
{
	printf("护士姓名\n");
	scanf("%s",s->n_NurseName);

	printf("性别:1:男,2,女\n");
	s->n_gender = (input_num_check(1,2)==1) ? 'm':'f';
	printf("科室\n");
	scanf("%d",&s->n_room);
	printf("护理级别(1~9)\n");
	if((s->n_level = input_num_check(1,9))==0);
	s->n_PatientNum = 0;		//默认创建时患者个数为零
	s->n_AdviceNum = 0;		//默认创建时没有待执行医嘱
	return 0;
}

/*********************************************************
int n_register_nurse(PNINFO *head)
*********************************************************/
int n_register_nurse(PNINFO *head)
{
	PNINFO s=NULL,tail = NULL,p = NULL; 
	char input;
	char tempstr[N_MAX_STRING_LEN];
	int ret;
	s=(PNINFO)malloc(sizeof(NINFO));
	if(s==NULL)
	{
		printf("malloc error file:%s line:%d\n",__FILE__,__LINE__);
		return -1;
	}
	
	n_register_from_input(s);		//人工输入
	s->next = NULL;
	if(*head == NULL)		//添加第一个节点
	{
		s->n_NurseID = 1;
		*head = s;
		s_update_all_nurse_head(s);
	}
	else					//添加其他节点
	{
		p = *head;
		while(NULL != p){
			tail = p;
			p=p->next;
		}
		s->n_NurseID = tail->n_NurseID +1;
		tail->next = s;
	}
	sprintf(tempstr,"%d",s->n_NurseID);
	strcpy(s->n_pswd,tempstr);

	printf("创建成功!是否写入文件?[y/n]\n");
	setbuf(stdin,NULL);
	scanf("%c",&input);
	if(input == 'y')
	{
		printf("hello\n");
		ret = n_write_nurse_to_file(*head);
		if(ret == 0){
			printf("写入文件成功!按回车键继续\n");
			t_pause();
		}else{
			printf("写入文件失败,按回车键继续\n");
			t_pause();
		}
	}
	
	return 0;
}
/*********************************************************

*********************************************************/
int n_link_getLen(PNINFO head)
{
	int len=0;
	PNINFO p=head;
	while(p!=NULL)
	{
		len++;
		p = p->next;
	}
	return len;

}

/*********************************************************
PNINFO n_nurse_delete(PNINFO head, PNINFO pp)
PNINFO head: 整个护士链表头指针
PNINFO pp:	定位的结点头指针
*********************************************************/
PNINFO n_nurse_delete(PNINFO head, PNINFO pp)
{
	PNINFO p = head, q=NULL;
	PNINFO ptail = head;
	if(NULL == head || NULL == pp){
		printf("删除存在空指针\n");
	}
	if(head == pp)//删除第一个节点
	{
		q=head;
		head=head->next;
		free(q);
	}
	else{
		while(p != pp)
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

*********************************************************/
void n_one_nurse_print(PNINFO head)
{
	PNINFO p = head;
	if(head==NULL)
	{
		printf("找不到护士信息\n");
	}
	else
	{
		//printf("ID 姓名\t性别\t科室 护理级别 患者个数 待执行医嘱数\n");
		printf("%d\t%s\t%c\t%d\t%d\t%d\t%d\n",p->n_NurseID,p->n_NurseName,p->n_gender,p->n_room,p->n_level,p->n_PatientNum,p->n_AdviceNum);
		printf("\n");
	}
}
/*********************************************************

*********************************************************/
void n_nurse_list_print(PNINFO head)
{
	PNINFO p = head;
	if(head==NULL)
	{
		printf("护士列表为空\n");
	}
	else
	{
		printf("护士ID\t姓名\n");
		while(p!=NULL)
		{
			printf("%d\t%s\n",p->n_NurseID,p->n_NurseName);
			p = p->next;
		}
		printf("\n");
	}
}

/*********************************************************

*********************************************************/
void n_nurse_print_by_level(PNINFO head, int level)
{
	PNINFO p = head;
	if(head==NULL)
	{
		printf("护士列表为空\n");
	}
	else
	{
		printf("护士ID 姓名\t性别\t科室 护理级别 患者个数 待执行医嘱数\n");
		while(p!=NULL)
		{
			if(p->n_level == level)
			{
				printf("%d\t%s\t%c\t%d\t%d\t%d\t%d\n",p->n_NurseID,p->n_NurseName,p->n_gender,p->n_room,p->n_level,p->n_PatientNum,p->n_AdviceNum);
			}
			p = p->next;
		}
		printf("\n");
	}
}

/*********************************************************

*********************************************************/
void n_all_nurse_print(PNINFO head)
{
	PNINFO p = head;
	if(head==NULL)
	{
		printf("护士列表为空\n");
	}
	else
	{
		printf("护士ID 姓名\t性别\t科室 护理级别 患者个数 待执行医嘱数\n");
		while(p!=NULL)
		{
			printf("%d\t%s\t%c\t%d\t%d\t%d\t%d\n",p->n_NurseID,p->n_NurseName,p->n_gender,p->n_room,p->n_level,p->n_PatientNum,p->n_AdviceNum);
			p = p->next;
		}
		printf("\n");
	}
}

/*********************************************************

*********************************************************/
int n_write_nurse_to_file(PNINFO head)
{
	FILE *fp = NULL;
	PNINFO p = head;
	int ret;

	fp = fopen("../data/nurse","wb");
	if(NULL == fp){
		printf("open file error\n");
		return -1;
	}
	while(NULL != p){
		ret = fwrite(p,sizeof(NINFO),1,fp);
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
int n_read_nurse_from_file(PNINFO *head)
{
	int ret = 1;
	PNINFO p = NULL,ptail = NULL;
	FILE *fp = NULL;
	
	fp = fopen("../data/nurse","rb");
	if(NULL == fp){
		printf("open file error\n");
		return -1;
	}
	//do not use feof
	while(1)
	{
		p = (PNINFO)malloc(sizeof(NINFO));
		assert(p != NULL);
		ret = fread(p,sizeof(NINFO),1,fp);
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
int nurse_self_info_man(){
	int input;
	char ch;
	PNINFO phead = s_get_all_nurse_head();
	PNINFO pn = s_get_named_nurse_head();
	
	n_one_nurse_print(pn);
	printf("0:全部修改,1:护士姓名,2:密码,3:性别,4:科室5:护理级别,99:退出\n");
	scanf("%d",&input);
	switch(input)
	{
		case 1: printf("输入姓名\n"); scanf("%s",pn->n_NurseName); break;
		case 2: printf("输入密码\n"); t_get_password(pn->n_pswd);break;
		case 3: printf("输入性别\n"); scanf("%c",&pn->n_gender); break;
		case 4: printf("输入科室\n"); scanf("%d",&pn->n_room); break;
		case 5: printf("输入护理级别(1~9)\n"); if((pn->n_level=input_num_check(1,9))==0) return -1; break;
		case 0:
		{
			printf("输入护士ID\n"); scanf("%d",&pn->n_NurseID);
			printf("输入姓名\n"); scanf("%s",pn->n_NurseName);
			printf("输入密码\n"); t_get_password(pn->n_pswd);//scanf("%s",pn->n_pswd);
			setbuf(stdin,NULL);
			printf("输入性别\n"); scanf("%c",&pn->n_gender);
			printf("输入科室\n"); scanf("%d",&pn->n_room);
			printf("输入护理级别(1~9)\n"); if((pn->n_level=input_num_check(1,9))==0) return -1;
			printf("输入护理的患者人数\n"); scanf("%d",&pn->n_PatientNum);
			printf("输入待执行医嘱个数\n"); scanf("%d",&pn->n_AdviceNum);
			break;
		}
		case 99: return N_MENU;
		default: break;
	}
	printf("确认写入文件?[y/n]\n");
	setbuf(stdin,NULL);
	if((ch = getchar()) == 'y')
	{
		n_write_nurse_to_file(phead);
	}
	else if(input == 99){
		return N_MENU;
	}
	return N_MENU;
}

/*********************************************************

*********************************************************/
int nurse_patient_list_view(){
	PPINFO phead = s_get_all_patient_head();
	p_all_patient_print(phead);
	t_pause();
	return N_MENU;
}

/*********************************************************

*********************************************************/
int n_all_patient_advice_print(){
	int anum1 = 0;		//未执行医嘱个数
	int anum2 = 0;		//已执行医嘱个数
	PPINFO phead = s_get_all_patient_head();
	PPINFO pp = phead;
	PNINFO pn = s_get_named_nurse_head();

	if(NULL == phead){
		printf("患者链表为空\n");
	}else{
		printf("医嘱号\t医嘱内容  医生ID  执行护士ID  医嘱状态\n");
	}
	printf("未执行医嘱:\n");
	while(NULL != pp){
		if(!strcmp(pp->p_NurseName,pn->n_NurseName)){	//患者属于该护士
			printf("患者 %s:\n",pp->p_PatName);
			anum1 += p_advice_print(pp,1);
		}
		pp = pp->next;
	}
	printf("已执行医嘱:\n");
	pp = phead;
	while(NULL != pp){
		if(!strcmp(pp->p_NurseName,pn->n_NurseName)){	//患者属于该护士
			printf("患者 %s:\n",pp->p_PatName);
			anum2 += p_advice_print(pp,2);
		}
		pp = pp->next;
	}
	printf("未执行医嘱个数:%d, 已执行医嘱个数:%d\n",anum1,anum2);
	t_pause();
	return P_MENU;		//返回患者选择菜单
}

/*********************************************************

*********************************************************/
int n_one_patient_advice_print(){
	int anum = 0;		//医嘱个数
	PPINFO phead = s_get_named_patient_head();
	PNINFO pn = s_get_named_nurse_head();
	if(NULL == phead){
		printf("患者链表为空\n");
	}
	if(strcmp(phead->p_NurseName,pn->n_NurseName))
	{
		printf("该患者不属于您\n");
		return P_MENU;
	}else{
		printf("患者 %s:\n",phead->p_PatName);
		anum = p_advice_print(phead,0);
	}
	return P_MENU;		//返回患者选择菜单
}

/*********************************************************

*********************************************************/
int nurse_all_unexecuted_advice_view(){
	int status;
	
	status = n_all_patient_advice_print();
	return N_MENU;
}

/*********************************************************

*********************************************************/
int nurse_one_unexecuted_advice_view(){
	int status;
	int input;
	PPINFO phead = s_get_all_patient_head();
	PPINFO pp = NULL;
	PAINFO pahead = NULL;
	PAINFO pa = NULL;
	PNINFO pn = s_get_named_nurse_head();
	
	p_all_patient_print(phead);
	printf("请输入需要查看医嘱的患者编号,输入99退出\n");
	scanf("%d",&input);
	if(input == 99)
	{
		return N_MENU;
	}
	pp = p_patient_search_by_data(phead,input,1);
	if(NULL == pp)
	{
		printf("没有找到该患者\n");
		t_pause();
		return N_MENU;
	}
	pahead = pp->a_FirstAdvice;
	pa = pahead;
	if(NULL == pa){
		printf("该患者没有医嘱\n");
		t_pause();
		return N_MENU;
	}
	if(strcmp(pn->n_NurseName,pa->a_NurseName)){
		printf("该患者不属于您\n");
		t_pause();
		return N_MENU;
	}
	status = n_one_patient_advice_print(pp);
	t_pause();
	return N_MENU;
}

/*********************************************************

*********************************************************/
int nurse_execute_advice(){
	int status;
	int input;
	PPINFO phead = s_get_all_patient_head();
	PPINFO pp = NULL;
	PNINFO pnhead = s_get_all_nurse_head();
	PNINFO pn = s_get_named_nurse_head();
	PAINFO pahead = NULL;
	PAINFO pa = NULL;
	char ch;
	
	p_all_patient_print(phead);
	printf("请输入需要执行医嘱的患者编号,输入99退出\n");
	scanf("%d",&input);
	if(input == 99)
	{
		return N_MENU;
	}
	pp = p_patient_search_by_data(phead,input,1);
	if(NULL == pp)
	{
		printf("没有找到该患者\n");
		t_pause();
		return N_MENU;
	}
	status = p_advice_print(pp,0);
	printf("输入执行的医嘱序号\n");
	scanf("%d",&input);
	pahead = pp->a_FirstAdvice;
	pa = p_advice_search_by_index(pahead,input);
	printf("1.执行该医嘱2.取消并返回\n");
	scanf("%d",&input);
	if(input == 1){
		pa->a_mark = 1;					//执行了医嘱
		pn->n_AdviceNum--;				//护士的待执行医嘱数-1
		printf("确认写入文件?[y/n]\n");
		setbuf(stdin,NULL);
		if((ch = getchar()) == 'y')
		{
			p_write_patient_to_file(phead);
			n_write_nurse_to_file(pnhead);
		}
	}
	
	return N_MENU;
}
