/**************************************************************
File Name:		patient.c
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
#include "patient.h"
#include "shared.h"
#include "tooler.h"
#define P_MAX_TRIAL_TIMES	3

/*******************************************************
函数名:	int p_register_from_input(PPINFO s)
功能:	挂号时用户输入信息赋值给结构体指针s
输入:	malloc分配的指针s
返回值:	成功返回0,失败返回-1
*******************************************************/
int p_register_from_input(PPINFO s)
{
	printf("患者姓名\n");
	scanf("%s",s->p_PatName);
	printf("性别:1:男,2,女\n");
	s->p_gender = (input_num_check(1,2)==1) ? 'm':'f';
	printf("年龄\n");
	if((s->p_age = input_num_check(1,130))==0) return -1;;
	//if(input_doc_name(s) != 0){return -1;}
	//if(input_nurse_name(s) != 0){return -1;}
	memset(s->p_DocName,0,D_MAX_STRING_LEN);
	memset(s->p_NurseName,0,N_MAX_STRING_LEN);
	printf("入院时间\n");
	//可以使用系统时间代替输入
	scanf("%s",s->p_EnterTime);
	printf("初步诊断\n");
	scanf("%s",s->p_PreDiagnose);
	s->a_AdviceNum = 0;		//挂号时默认尚未开具医嘱
	return 0;
}

/*********************************************************

*********************************************************/
int p_register_patient(PPINFO *head)
{
	PPINFO s=NULL,tail = NULL,p = NULL; 
	//PINFO pat[4] = {{1,"zhangsan","111",'f',18,1,1,"1200","kesou",0,NULL,NULL},{2,"lisi","222",'m',19,2,2,"1230","fashao",0,NULL,NULL},{3,"wangwu","333",'f',20,3,3,"1300","ganmao",0,NULL,NULL}};
	//PPINFO ppat = pat;
	char input;
	char tempstr[P_MAX_STRING_LEN];
	int ret;

	s=(PPINFO)malloc(sizeof(PINFO));
	if(s==NULL)
	{
		printf("malloc error file:%s line:%d\n",__FILE__,__LINE__);
		return -1;
	}
	
	if(p_register_from_input(s)) return -1;		//人工输入			
	//memcpy(s,&pat[i],sizeof(PINFO));	//自动赋值
	s->next = NULL;
	if(NULL == *head)//添加第一个节点
	{
		s->p_PatID = 1;
		*head = s;
		s_update_all_patient_head(s);
	}
	else//添加其他节点
	{
		p = *head;
		while(NULL != p){
			tail = p;
			p=p->next;
		}
		s->p_PatID = tail->p_PatID +1;
		tail->next = s;
	}
	sprintf(tempstr,"%d",s->p_PatID);
	strcpy(s->p_pswd,tempstr);		//创建时密码默认为用户ID

	printf("创建成功!是否写入文件?[y/n]\n");
	setbuf(stdin,NULL);
	scanf("%c",&input);
	if(input == 'y')
	{
		ret = p_write_patient_to_file(*head);
	}
	if(ret == 0){
		printf("写入文件成功!按回车键继续\n");
		t_pause();
	}else{
		printf("写入文件失败,按回车键继续\n");
		t_pause();
	}
	return 0;
}

/*********************************************************

*********************************************************/
int p_patient_getLen(PPINFO head)
{
	int len=0;
	PPINFO p=head;
	while(p!=NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

/*********************************************************
PPINFO p_patient_delete(PPINFO head, PPINFO pp)
PPINFO head: 整个患者链表头指针
PPINFO pp:	定位的结点头指针
*********************************************************/
PPINFO p_patient_delete(PPINFO head, PPINFO pp)
{
	PPINFO p = head,q=NULL;
	PPINFO ptail = head;
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
int p_advice_print(PPINFO head,int option)
*********************************************************/
int p_advice_print(PPINFO head,int option)
{
	int i = 0;
	PAINFO p = head->a_FirstAdvice;
	//PNINFO pn = s_get_named_nurse_head();
	if(NULL == p)
	{
		printf("该病人尚未有医嘱\n");
		return 0;
	}else{
		//printf("医嘱号\t医嘱内容  医生ID  执行护士ID  医嘱状态\n");
	}
	switch (option)
	{
		case 0:				//全部打印
		{
			while(NULL != p)
			{
				//if(!strcmp(p->a_NurseName,pn->n_NurseName)){
					printf("%d\t%s\t\t%s\t%s\t%d\n",p->a_AdviceID,p->a_AdviceInfo,p->a_DocName,p->a_NurseName,p->a_mark);
					i++;
					printf("\n");
				//}
				p = p->next;
			}
			break;
		}
		case 1:				//打印未执行医嘱
		{
			while(NULL != p)
			{
				if(p->a_mark == 0)
				{
					//if(!strcmp(p->a_NurseName,pn->n_NurseName)){
						printf("%d\t%s\t\t%s\t%s\t%d\n",p->a_AdviceID,p->a_AdviceInfo,p->a_DocName,p->a_NurseName,p->a_mark);
						i++;
						printf("\n");
					//}
				}
				p = p->next;
			}
			break;
		}
		case 2:			//打印已执行医嘱
		{
			while(NULL != p)
			{
				if(p->a_mark != 0)
				{
					//if(!strcmp(p->a_NurseName,pn->n_NurseName)){
						printf("%d\t%s\t\t%s\t%s\t%d\n",p->a_AdviceID,p->a_AdviceInfo,p->a_DocName,p->a_NurseName,p->a_mark);
						i++;
						printf("\n");
					//}
				}
				p = p->next;
			}
			break;
		}
		default: printf("打印患者医嘱列表的选项错误: option = %d\n",option); break;
	}
	return i;
}

/*********************************************************
int p_add_advice_from_input(PAINFO head)
*********************************************************/
int p_add_advice_from_input(PAINFO head)
{
	if(NULL == head){
		printf("head is null %s,%d\n",__FILE__,__LINE__);
		return -1;
	}
	
	printf("输入医嘱信息\n");
	scanf("%s",head->a_AdviceInfo);
	setbuf(stdin,NULL);
	//printf("输入医生ID\n");
	//scanf("%d",&head->a_DocID);
	//head->a_DocID =((PDINFO) s_get_named_doc_head())->d_DocID;
	//printf("输入执行护士ID\n");
	//scanf("%d",&head->a_NurseID);
	//head->a_NurseID = ((PNINFO) s_get_named_nurse_head())->n_NurseID;
	
	//if(input_advice_doc_name(head) != 0){return 0;}
	if(input_advice_nurse_name(head) != 0){return 0;}//shared.c的全局变量pn指向选中的护士结点

	head->a_mark = 0;			//创建时默认为未执行医嘱
	return 0;
}

/*********************************************************
int p_add_advice(PPINFO head)
*********************************************************/
int p_add_advice(PPINFO head,PDINFO pd)
{
	int panum = 0;
	PAINFO pa = NULL;
	PAINFO tail = NULL;
	PAINFO s = (PAINFO) malloc(sizeof(AINFO));
	PNINFO pn = NULL;
	assert(s != NULL);

	pa = head->a_FirstAdvice;
	while(pa != NULL)
	{
		tail = pa;
		pa = pa->next;
		panum++;
	}
	
	if(panum != head->a_AdviceNum)		//综向医嘱列表与横向记录列表数不符
	{
		printf("Advice num not compatible with link number,%s,%d\n",__FILE__,__LINE__);
	}
	p_add_advice_from_input(s);	//人工输入
	strcpy(s->a_DocName,pd->d_DocName);	//医嘱的医生名为创建医嘱的医生姓名,无需人工输入
	
	s->next  = NULL;
	if(!panum){
		s->a_AdviceID = 1;
		head->a_FirstAdvice = s;
	}else{
		s->a_AdviceID = tail->a_AdviceID +1;
		tail->next = s;
	}
	tail = s;
	(head->a_AdviceNum)++; 			//病人医嘱数+1
	pn = s_get_named_nurse_head();	//shared.c的全局变量pn已指向选中的护士结点
	(pn->n_AdviceNum)++;			//指定的护士待执行医嘱自动+1
	return 0;
}

/*********************************************************

*********************************************************/
int p_advice_getLen(PAINFO head)
{
	int len=0;
	PAINFO p=head;
	while(p!=NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

/*********************************************************

*********************************************************/
PAINFO p_advice_search_by_index(PAINFO phead,int index)
{
	PAINFO p=phead;
	//入参检查
	int i;
	if(index <1 || index > p_advice_getLen(phead)||phead==NULL)
	{
		printf("无效的链表序号\n");
		return NULL;
	}
	//查找自己实现，返回找到节点的地址
	for(i=1; i<index ;i++)
	{
		p=p->next;
	}
	return p;
}
/*********************************************************
void p_one_patient_print(PPINFO phead)		//患者结点指针,非链表头指针
*********************************************************/
void p_one_patient_print(PPINFO phead)
{
	PPINFO p = phead;
	if(phead==NULL)
	{
		printf("empty link\n");
	}
	else
	{
		printf("ID 姓名\t性别\t年龄 主治医生 护理护士 入院时间\t初步诊断 医嘱数\n");
		printf("%d\t%s\t%c\t%d\t%s\t%s\t%s\t%s\t%d\n",p->p_PatID,p->p_PatName,p->p_gender,p->p_age,p->p_DocName,p->p_NurseName,p->p_EnterTime,p->p_PreDiagnose,p->a_AdviceNum);
	}
}

/*********************************************************
void p_all_patient_print(PPINFO head)
*********************************************************/
void p_all_patient_print(PPINFO head)
{
	int i = 0;
	PPINFO p = head;
	if(head==NULL)
	{
		printf("病人记录为空\n");
	}
	else
	{
		system("clear");
		printf("患者ID 姓名\t性别\t年龄 主治医生 护理护士 入院时间\t初步诊断 医嘱数\n");
		while(NULL != p)
		{
			printf("%d\t%s\t%c\t%d\t%s\t%s\t%s\t%s\t%d\n",p->p_PatID,p->p_PatName,p->p_gender,p->p_age,p->p_DocName,p->p_NurseName,p->p_EnterTime,p->p_PreDiagnose,p->a_AdviceNum);
			p = p->next;
			i++;
			printf("\n");
		}
	}
	printf("一共有%d个患者\n",i);
}

/*********************************************************

*********************************************************/
int p_write_patient_to_file(PPINFO head)
{
	FILE *fp = NULL;
	PPINFO p = head;
	PAINFO pa = NULL;
	int ret;

	fp = fopen("../data/patient","wb");
	if(NULL == fp){
		printf("open file error\n");
		return -1;
	}
	while(NULL != p){
		ret = fwrite(p,sizeof(PINFO),1,fp);
		if(ret < 0)
		{
			printf("write file error\n");
			return -1;
		}
		//write advice linklist into file
		pa = p->a_FirstAdvice;
		while(NULL != pa)
		{
			ret = fwrite(pa,sizeof(AINFO),1,fp);
			if(ret < 0)
			{
				printf("write file error\n");
				return -1;
			}
			pa = pa->next;
		}
		p = p->next;
	}

	//printf("write_to_file: ret = %d\n",ret);
	fclose(fp);
	return ret;
}

/*********************************************************

*********************************************************/
int p_read_patient_from_file(PPINFO *head)
{
	int ret = 1;
	int i,AdviceNum;
	PPINFO p = NULL,ptail = NULL;
	PAINFO pa = NULL, patail = NULL;
	FILE *fp = NULL;
	
	fp = fopen("../data/patient","rb");
	if(NULL == fp){
		printf("open file error\n");
		return -1;
	}
	//do not use feof
	while(1)
	{
		p = (PPINFO)malloc(sizeof(PINFO));
		assert(p != NULL);
		ret = fread(p,sizeof(PINFO),1,fp);
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
		
		AdviceNum = p->a_AdviceNum;
		for(i = 0; i < AdviceNum; i++){
			pa = (PAINFO)malloc(sizeof(AINFO));
			assert(p != NULL);
			ret = fread(pa,sizeof(AINFO),1,fp);
			if(ret == 0){
				return ret;
			}else if(ret < 0){
				printf("read error\n");
				return -1;
			}
			
			pa->next = NULL;		
			if(i == 0)
			{
				p->a_FirstAdvice = pa;
			}else{
				patail->next = pa;
			}
			patail = pa;
		}
	}
	if(NULL != p)		//文件为空
	{
		free(p);
	}
	printf("p_read_from_file: ret = %d\n",ret);
	fclose(fp);
	return ret;
}
/*********************************************************

*********************************************************/
#if 0
int pmain()
{
	PPINFO head = NULL;
	//PPINFO p = NULL;
	PPINFO pf = NULL;
	int p_fstate = 0;
	
	p_register_patient(&head);
	p_all_patient_print(head);

	p_add_advice(head);
	p_add_advice(head);
	p_advice_print(head);
	p_all_patient_print(head);

	p_fstate = p_write_patient_to_file(head);
	p_fstate = p_read_patient_from_file(&pf);
	p_all_patient_print(pf);
	p_advice_print(pf);
/*	
	p = p_link_searchBydata(head,1);
	if(p!=NULL)
	{
		printf("%d\n",p->data);
	}
	else
	{
		printf("not founded\n");
	}
*/
	//head = p_link_insert(head,5,333);
	//p_all_patient_print(head);
	//head = p_link_delete(head,1);
	//p_all_patient_print(head);
	
	head = p_link_destory(head);
}

#endif

/*********************************************************

*********************************************************/
int patient_login()
{
	char UserName[P_MAX_STRING_LEN];
	char password[P_MAX_STRING_LEN];
	PPINFO head = NULL;
	PPINFO pp = NULL;
	int i;

	system("clear");
	setbuf(stdin,NULL);
	printf("患者登录\n");
	printf("请输入用户名\n");
	
	head = s_get_all_patient_head();
	for(i = 0; i < P_MAX_TRIAL_TIMES; i++){
		scanf("%s",UserName);
		pp = s_search_patient_by_name(head,UserName);
		if(NULL == pp)	//找不到用户名
		{
			printf("用户名不存在,请重试\n");
		}else{
			break;
		}
	}
	if(i>=P_MAX_TRIAL_TIMES)
	{
		printf("超过最大输入次数,返回\n");
		t_pause();
		return MAIN_MENU;
	}
	printf("请输入密码\n");

	for(i = 0; i < P_MAX_TRIAL_TIMES; i++)
	{
		//scanf("%s",password);
		t_get_password(password);
		if(strcmp(password,pp->p_pswd)){
			if(i < P_MAX_TRIAL_TIMES-1){
				printf("密码错误\n");			//最后一次不用输出此语句
			}
		}else{
			break;
		}
	}
	if(i < P_MAX_TRIAL_TIMES){
		//printf("登录成功\n");
		//t_pause();
		return PATIENT_LOGIN;		
	}
	printf("密码错误超过三次,退出\n");
	t_pause();
	return MAIN_MENU;
}

/*********************************************************

*********************************************************/
int patient_info_view(){
	PPINFO phead = s_get_named_patient_head();
	if(NULL == phead){
		printf("患者链表为空\n");
	}
	p_one_patient_print(phead);
	printf("按回车键退出\n");
	t_pause();
	return P_MENU;				//返回患者选择菜单
}

/*********************************************************

*********************************************************/
int patient_info_modify(){
	int input;
	char ch;
	char str[P_MAX_STRING_LEN];
	PPINFO pp = s_get_named_patient_head();
	PPINFO pphead = s_get_all_patient_head();
	
	if(NULL == pp){
		printf("患者链表为空\n");
		return P_MENU;
	}
	p_one_patient_print(pp);
	printf("0:全部修改,1:患者姓名,2:密码,3:性别,4:年龄,99:退出\n");
	scanf("%d",&input);
	switch(input)
	{
		case 1: printf("输入姓名\n"); scanf("%s",str); strncpy(pp->p_PatName,str,P_MAX_STRING_LEN);break;
		case 2: printf("输入密码\n"); scanf("%s",pp->p_pswd); break;
		case 3: printf("性别:1:男,2,女\n"); pp->p_gender = (input_num_check(1,2)==1) ? 'm':'f';break;
		case 4: printf("输入年龄\n"); scanf("%d",&pp->p_age); break;
		case 0:
		{
			printf("输入姓名\n"); scanf("%s",pp->p_PatName);
			printf("输入密码\n"); scanf("%s",pp->p_pswd);
			printf("性别:1:男,2,女\n");pp->p_gender = (input_num_check(1,2)==1) ? 'm':'f';
			printf("输入年龄\n"); scanf("%d",&pp->p_age);
			break;
		}
		case 99: return P_MENU;
		default: return P_MENU;
	}
	printf("确认写入文件?[y/n]\n");
	setbuf(stdin,NULL);
	if((ch = getchar()) == 'y')
	{
		p_write_patient_to_file(pphead);
	}
	return P_MENU;
}

/*********************************************************

*********************************************************/
int p_all_patient_advice_view(){
	int anum = 0;		//医嘱个数
	PPINFO phead = s_get_all_patient_head();
	if(NULL == phead){
		printf("患者链表为空\n");
	}
	system("clear");
	while(NULL != phead){
		printf("患者 %s:\n",phead->p_PatName);
		anum = p_advice_print(phead,0);
		phead = phead->next;
	}
	//t_pause();
	return P_MENU;		//返回患者选择菜单
}

/*********************************************************

*********************************************************/
int patient_one_advice_view(){
	int anum = 0;		//医嘱个数
	PPINFO phead = s_get_named_patient_head();
	if(NULL == phead){
		printf("患者链表为空\n");
	}
	printf("患者 %s:\n",phead->p_PatName);
	anum = p_advice_print(phead,0);
	t_pause();
	return P_MENU;		//返回患者选择菜单
}
