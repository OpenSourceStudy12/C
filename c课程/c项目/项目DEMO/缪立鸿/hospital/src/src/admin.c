/**************************************************************
File Name:		admin.c
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
#include "admin.h"
#include "patient.h"
#include "doctor.h"
#include "nurse.h"
#include "shared.h"
#include "tooler.h"

#define D_SEARCH_DOC_ID			1
#define D_SEARCH_DOC_ROOM		2

#define N_SEARCH_NURSE_ID		1
#define N_SEARCH_NURSE_ROOM	2

#define AD_MAX_TRIAL_TIMES		3

/*********************************************************

*********************************************************/
void ad_one_admin_print(PADINFO phead)
{
	PADINFO p = phead;
	if(phead==NULL)
	{
		printf("empty link\n");
	}
	else
	{
		printf("管理员姓名\t密码\n");
		printf("%s\t\t%s\n",p->ad_name,p->ad_password);
	}
	printf("按回车键退出\n");
	setbuf(stdin,NULL);
	getchar();
}

/*********************************************************

*********************************************************/
void ad_all_admin_print(PADINFO phead)
{
	PADINFO p = phead;
	if(phead==NULL)
	{
		printf("empty link\n");
	}
	else
	{
		printf("管理员姓名\t密码\n");
		while(NULL != p){
			printf("%s\t\t%s\n",p->ad_name,p->ad_password);
			p = p->next;
		}
	}
	printf("按回车键退出\n");
	setbuf(stdin,NULL);
	getchar();
}
/*********************************************************

*********************************************************/
void admin_info_view()
{
	PADINFO phead = s_get_named_admin_head();
	if(NULL == phead){
		printf("管理员链表为空\n");
	}
	ad_all_admin_print(phead);
}


/*********************************************************

*********************************************************/
int ad_write_admin_to_file(PADINFO head)
{
	FILE *fp = NULL;
	PADINFO p = head;
	int ret;
	fp = fopen("../data/admin","wb");
	if(NULL == fp){
		printf("open file error\n");
		return -1;
	}
	while(NULL != p){
		ret = fwrite(p,sizeof(ADINFO),1,fp);
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
int ad_read_admin_from_file(PADINFO *head)
{
	int ret = 1;
	PADINFO p = NULL,ptail = NULL;
	FILE *fp = NULL;
	
	fp = fopen("../data/admin","rb");
	if(NULL == fp){
		printf("open file error\n");
		return -1;
	}
	while(1)
	{
		p = (PADINFO)malloc(sizeof(ADINFO));
		assert(p != NULL);
		ret = fread(p,sizeof(ADINFO),1,fp);
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
	free(p);
	//printf("p_read_from_file: ret = %d\n",ret);
	fclose(fp);
	return ret;
}

/*********************************************************

*********************************************************/
int ad_admin_getLen(PADINFO head)
{
	int len=0;
	PADINFO p=head;
	while(p!=NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

/*********************************************************
PADINFO ad_admin_delete(PADINFO head, PADINFO pp)
*********************************************************/
PADINFO ad_admin_delete(PADINFO head, PADINFO pp)
{
	PADINFO p = head, q=NULL;
	PADINFO ptail = head;
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

/*******************************************************
函数名:	int ad_register_from_input(PPINFO s)
功能:	注册时管理员信息赋值给结构体指针s
输入:	malloc分配的指针s
返回值:	成功返回0,失败返回-1
*******************************************************/
int ad_register_from_input(PADINFO s)
{
	int i;
	char temppswd1[AD_MAX_STRING_LEN];
	char temppswd2[AD_MAX_STRING_LEN];
	
	printf("输入管理员姓名\n");
	scanf("%s",s->ad_name);
	setbuf(stdin,NULL);
	for(i = 0; i < AD_MAX_TRIAL_TIMES; i++){
		printf("输入密码\n");
		//scanf("%s",temppswd1);
		t_get_password(temppswd1);
		printf("重新输入密码\n");
		t_get_password(temppswd2);
		if(strcmp(temppswd1,temppswd2)){
			printf("密码不一致,请重试\n");
		}else{
			break;
		}
	}
	if(i >= AD_MAX_TRIAL_TIMES)		//连续三次错误
	{
		printf("达到最大错误次数,创建失败\n");
		return -1;
	}else{
		strcpy(s->ad_password,temppswd1);
	}
	return 0;
}

/*********************************************************

*********************************************************/
int ad_register_admin(PADINFO *head)
{
	PADINFO p = *head, s=NULL,tail = NULL; 
	//ADINFO padmin[2] = {{"admin","password",NULL},{"admin","admin",NULL}};
	//PADINFO ppadmin = NULL;
	int ret;
	char input;
	
	s=(PADINFO)malloc(sizeof(ADINFO));
	if(s==NULL)
	{
		printf("malloc error file:%s line:%d\n",__FILE__,__LINE__);
		return -1;
	}

	ad_register_from_input(s);		//人工输入			
	//memcpy(s,&ppadmin[i],sizeof(ADINFO));	//自动赋值

	s->next = NULL;
	if(NULL == *head)//添加第一个节点
	{
		*head = s;
		s_update_all_admin_head(s);
	}
	else//添加其他节点
	{
		while(NULL != p)
		{
			tail = p;
			p = p->next;
		}
		tail->next = s;
	}
	printf("创建成功!是否写入文件?[y/n]\n");
	setbuf(stdin,NULL);
	scanf("%c",&input);
	if(input == 'y')
	{
		ret = ad_write_admin_to_file(*head);
	}
	if(ret == 0){
		printf("写入文件成功!按回车键继续\n");
		t_pause();
	}
	return 0;
}



/*********************************************************

*********************************************************/

int admin_login(){
	char UserName[P_MAX_STRING_LEN];
	char password[P_MAX_STRING_LEN];
	PADINFO head = NULL;
	PADINFO pad = NULL;
	char input;
	int i;
	head = s_get_all_admin_head();
	if(NULL == head)
	{
		printf("尚无管理员,是否创建?[y/n]\n");
		setbuf(stdin,NULL);
		scanf("%c",&input);
		if(input=='y')
		{
			//head = s_get_all_admin_head(head);
			ad_register_admin(&head);
		}else{
			return MAIN_MENU;
		}
	}
	system("clear");
	setbuf(stdin,NULL);
	printf("管理员登录\n");
	printf("请输入用户名\n");
	for(i = 0; i< AD_MAX_TRIAL_TIMES;i++){
		scanf("%s",UserName);
		pad = s_search_admin_by_name(head,UserName);
		if(NULL == pad)	//找不到用户名
		{
			printf("用户名不存在\n");
		}else{
			break;
		}
	}
	if(i >= AD_MAX_TRIAL_TIMES)
	{
		printf("超过最大输入次数,返回\n");
		t_pause();
		return MAIN_MENU;
	}
	printf("请输入密码\n");
	for(i = 0; i < AD_MAX_TRIAL_TIMES; i++)
	{
		setbuf(stdin,NULL);
		t_get_password(password);
		//scanf("%s",password);
		if(strcmp(password,pad->ad_password)){
			printf("密码错误,请重试\n");
		}else{
			break;
		}
	}
	if(i < AD_MAX_TRIAL_TIMES){
		return A_MENU;
	}else{
		printf("超过最大输入次数,返回\n");
		getchar();
		getchar();
		setbuf(stdin,NULL);
		return MAIN_MENU;
	}
}


/*********************************************************

*********************************************************/
int admin_self_info_man(){
	int input;
	int status;
	char ch;
	PADINFO phead = s_get_named_admin_head();
	PADINFO padf = s_get_all_admin_head();
	PADINFO pad = NULL;

	if(NULL == phead){
		return A_MENU;
	}
	admin_info_view();
	printf("0:全部修改,1:修改用户名,2:修改密码,3:创建新管理员4.删除本管理员,99:退出\n");
	scanf("%d",&input);
	switch(input)
	{
		case 1: printf("输入姓名\n"); scanf("%s",phead->ad_name); break;
		case 2: printf("输入密码\n"); t_get_password(phead->ad_password); break;
		case 3: 
		{
			pad = s_get_all_admin_head();
			status = ad_register_admin(&padf);
			return A_MENU;
		}
		case 4: 
		{
			padf = ad_admin_delete(padf,phead);
			padf = s_update_all_admin_head(padf);
			break;
		}
		case 0:
		{
			printf("输入姓名\n"); scanf("%s",phead->ad_name);
			printf("输入密码\n"); t_get_password(phead->ad_password);
			break;
		}
		case 99: return A_MENU;
		default: break;
	}
	printf("确认写入文件?[y/n]\n");
	setbuf(stdin,NULL);
	if((ch = getchar()) == 'y')
	{
		ad_write_admin_to_file(padf);
		
	}
	return A_MENU;
}
/*********************************************************

*********************************************************/
int admin_patient_register()
{
	int status;
	PPINFO pad = s_get_all_patient_head();
	status = p_register_patient(&pad);
	return A_MENU;
}
/*********************************************************

*********************************************************/
int admin_patient_info_man(){
	int input;
	PPINFO phead = s_get_all_patient_head();
	PPINFO pp = NULL;
	char ch;
	
	p_all_patient_print(phead);
	printf("1.患者修改2.患者删除99.退出\n");
	scanf("%d",&input);
	if(input == 1){
		printf("请输入需要维护的患者编号,输入99退出\n");
		scanf("%d",&input);
		if(input == 99)
		{
			return A_MENU;
		}
		pp = p_patient_search_by_data(phead,input,1);
		if(NULL == pp)
		{
			printf("没有找到该患者\n");
			return A_MENU;
		}
		printf("0:全部修改,1:患者姓名,2:密码,3:性别,4:年龄5:主治医生6:护理护士7:入院时间8:初步诊断,99:退出\n");
		scanf("%d",&input);
		switch(input)
		{
			case 1: printf("输入姓名\n"); scanf("%s",pp->p_PatName); break;
			case 2: printf("输入密码\n"); t_get_password(pp->p_pswd); break;
			case 3: printf("性别:1:男,2,女\n"); pp->p_gender = (input_num_check(1,2)==1) ? 'm':'f';break;
			case 4: printf("输入年龄\n"); scanf("%d",&pp->p_age); break;
			case 5: if(input_doc_name(pp)!=0){return 0;}break;
			case 6: if(input_nurse_name(pp)!=0){return 0;}break;
			case 7: printf("输入入院时间\n"); scanf("%s",pp->p_EnterTime); break;
			case 8: printf("输入初步诊断\n"); scanf("%s",pp->p_PreDiagnose); break;
			case 0:
			{
				printf("输入患者ID\n"); scanf("%d",&pp->p_PatID);
				printf("输入姓名\n"); scanf("%s",pp->p_PatName);
				printf("输入密码\n"); t_get_password(pp->p_pswd);
				printf("性别:1:男,2,女\n");
					pp->p_gender = (input_num_check(1,2)==1) ? 'm':'f';
				printf("输入年龄\n"); scanf("%d",&pp->p_age);
				if(input_doc_name(pp) != 0) {return 0;}
				if(input_nurse_name(pp) != 0){return 0;}
				printf("输入入院时间\n"); scanf("%s",pp->p_EnterTime);
				printf("输入初步诊断\n"); scanf("%s",pp->p_PreDiagnose);
				break;
			}
			case 99: return A_MENU;
			default: break;
		}
	}else if(input == 2){
		printf("请输入需要删除的患者编号,输入99退出\n");
		scanf("%d",&input);
		if(input == 99)
		{
			return A_MENU;
		}
		pp = p_patient_search_by_data(phead,input,1);
		if(NULL == pp)
		{
			printf("没有找到该患者\n");
			return A_MENU;
		}
		phead = p_patient_delete(phead,pp);
		phead = s_update_all_patient_head(phead);//为了解决删除头结点后表头指针全局变量改变的问题
		p_all_patient_print(phead);
	}else{
		return A_MENU;
	}
	printf("确认写入文件?[y/n]\n");
	setbuf(stdin,NULL);
	if((ch = getchar()) == 'y')
	{
		p_write_patient_to_file(phead);
	}
	return A_MENU;
}

/*********************************************************

*********************************************************/
int admin_doc_info_man(){
	int input,status;
	PDINFO phead = s_get_all_doc_head();
	PDINFO pd = NULL;
	PDINFO ps = phead;
	char ch;
	
	d_all_doc_print(phead);
	printf("1.按科室查看医生2.医生修改3.医生添加4.医生删除99.退出\n");
	scanf("%d",&input);
	if(input == 1){
		printf("请输入科室号");
		scanf("%d",&input);
		printf("医生ID 姓名\t性别\t科室 主治项目 患者个数\n");
		while(NULL != ps){
			ps = d_doc_search_by_data(ps,input,D_SEARCH_DOC_ROOM);
			d_one_doc_print(ps);
			ps = ps->next;
		}
		t_pause();
		return A_MENU;
	}else if(input == 2){
		printf("请输入需要维护的医生编号,输入99退出\n");
		scanf("%d",&input);
		if(input == 99)
		{
			return A_MENU;
		}
		pd = d_doc_search_by_data(phead,input,D_SEARCH_DOC_ID);
		if(NULL == pd)
		{
			printf("没有找到该医生\n");
			return A_MENU;
		}
		printf("0:全部修改,1:医生姓名,2:密码,3:性别,4:科室5:主治项目6:患者个数,99:退出\n");
		scanf("%d",&input);
		switch(input)
		{
			case 1: printf("输入姓名\n"); scanf("%s",pd->d_DocName); break;
			case 2: printf("输入密码\n"); t_get_password(pd->d_pswd); break;
			case 3: printf("输入性别\n"); printf("性别:1:男,2,女\n"); pd->d_gender = (input_num_check(1,2)==1) ? 'm':'f'; break;
			case 4: printf("输入科室\n"); scanf("%d",&pd->d_room); break;
			case 5: printf("输入主治项目\n"); scanf("%s",pd->d_MainClass); break;
			case 6: printf("输入患者个数\n"); scanf("%d",&pd->d_PatientNum); break;
			case 0:
			{
				printf("输入医生ID\n"); scanf("%d",&pd->d_DocID);
				printf("输入姓名\n"); scanf("%s",pd->d_DocName);
				printf("输入密码\n"); t_get_password(pd->d_pswd);
				printf("性别:1:男,2,女\n");
					pd->d_gender = (input_num_check(1,2)==1) ? 'm':'f';
				printf("输入科室\n"); scanf("%d",&pd->d_room);
				printf("输入主治项目\n"); scanf("%s",pd->d_MainClass);
				printf("输入患者个数\n"); scanf("%d",&pd->d_PatientNum);
				break;
			}
			case 99: return A_MENU;
			default: break;
		}
		
	}else if(input == 3){
		status = d_register_doc(&phead);
		return A_MENU;
	}else if(input ==4){
		printf("请输入需要删除的医生编号,输入99退出\n");
		scanf("%d",&input);
		if(input == 99)
		{
			return A_MENU;
		}
		pd = d_doc_search_by_data(phead,input,D_SEARCH_DOC_ID);
		if(NULL == pd)
		{
			printf("没有找到该医生\n");
			return A_MENU;
		}
		phead = d_doc_delete(phead,pd);
		phead = s_update_all_doc_head(phead);	//为了解决删除头结点后表头指针全局变量改变的问题
		d_all_doc_print(phead);
		t_pause();
	}else{
		return A_MENU;
	}
	printf("确认写入文件?[y/n]\n");
	setbuf(stdin,NULL);
	if((ch = getchar()) == 'y')
	{
		d_write_doc_to_file(phead);
	}
	return A_MENU;
}

/*********************************************************

*********************************************************/
int admin_nurse_info_man(){
	int status;
	int input;
	PNINFO phead = s_get_all_nurse_head();
	PNINFO pn = NULL;
	char ch;
	
	n_all_nurse_print(phead);
	printf("1.按护理等级查看护士2.护士修改3.护士添加4.护士删除99.退出\n");
	scanf("%d",&input);
	if (input == 1){
		printf("输入要查看的护理等级\n");
		if((input = input_num_check(1,9))==0) return A_MENU;
		n_nurse_print_by_level(phead, input);
		t_pause();
		return A_MENU;
	}
	else if(input == 2){
		printf("请输入需要维护的护士编号,输入99退出\n");
		scanf("%d",&input);
		if(input == 99)
		{
			return A_MENU;
		}
		pn = n_nurse_search_by_data(phead,input,N_SEARCH_NURSE_ID);
		if(NULL == pn)
		{
			printf("没有找到该护士\n");
			t_pause();
			return A_MENU;
		}
		printf("0:全部修改,1:护士姓名,2:密码,3:性别,4:科室5:护理级别6:患者个数7.待执行医嘱数,99:退出\n");
		scanf("%d",&input);
		switch(input)
		{
			case 1: printf("输入姓名\n"); scanf("%s",pn->n_NurseName); break;
			case 2: printf("输入密码\n"); t_get_password(pn->n_pswd); break;
			case 3: printf("输入性别\n"); printf("性别:1:男,2,女\n"); pn->n_gender = (input_num_check(1,2)==1) ? 'm':'f'; break;
			case 4: printf("输入科室\n"); scanf("%d",&pn->n_room); break;
			case 5: printf("输入护理级别\n"); scanf("%d",&pn->n_level); break;
			case 6: printf("输入患者人数\n"); scanf("%d",&pn->n_PatientNum); break;
			case 7: printf("输入待执行医嘱数\n"); scanf("%d",&pn->n_AdviceNum); break;
			case 0:
			{
				printf("输入患者ID\n"); scanf("%d",&pn->n_NurseID);
				printf("输入姓名\n"); scanf("%s",pn->n_NurseName);
				printf("输入密码\n"); t_get_password(pn->n_pswd);
				printf("性别:1:男,2,女\n");pn->n_gender = (input_num_check(1,2)==1) ? 'm':'f';
				printf("输入科室\n"); scanf("%d",&pn->n_room);
				printf("输入护理级别\n"); scanf("%d",&pn->n_level);
				printf("输入患者人数\n"); scanf("%d",&pn->n_PatientNum);
				printf("输入待执行医嘱数\n"); scanf("%d",&pn->n_AdviceNum);
				break;
			}
			case 99: return A_MENU;
			default: break;
		}
		
	}else if(input == 3){
		status = n_register_nurse(&phead);
		return A_MENU;
	}else if(input == 4){
		printf("请输入需要删除的护士编号,输入99退出\n");
		scanf("%d",&input);
		if(input == 99)
		{
			return A_MENU;
		}
		pn = n_nurse_search_by_data(phead,input,N_SEARCH_NURSE_ID);
		if(NULL == pn)
		{
			printf("没有找到该医生\n");
			return A_MENU;
		}
		phead = n_nurse_delete(phead,pn);
		phead = s_update_all_nurse_head(phead);
		n_all_nurse_print(phead);
	}else{
		return A_MENU;
	}
	printf("确认写入文件?[y/n]\n");
		setbuf(stdin,NULL);
		if((ch = getchar()) == 'y')
		{
			n_write_nurse_to_file(phead);
		}
	return A_MENU;
}
