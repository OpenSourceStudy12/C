

#include"manage_teacher.h"

char  *str_teacher="../data/teacher";

/*UI head*/
void print_teacher_head()
{
	printf("\t\t***************************************\n");
	printf("\t\t***************************************\n");
	printf("\t\t***********学生管理系统欢迎*************\n");
	printf("\t\t***************************************\n");
	printf("\t\t***************************************\n");
}
//char *str="//2222//student//src//data//stu";

void print_teacher_main()
{
	int flag=0;
	char ch;
	while(1)
	{
		system("clear");
		print_teacher_head();
		printf("\n\n\t\t\t请选择你要的操作\n");
		printf("\t\t1.创建并初始化教师信息\n");
		printf("\t\t2.添加教师信息\n");
		printf("\t\t3.删除教师信息\n");
		printf("\t\t4.修改教师信息\n");
		printf("\t\t5.打印教师信息\n");
		printf("\t\t6.返回上一层\n");
		printf("\t\t7.退出\n");
		printf("\n\t\t");
   		flag=-1;
		scanf("%d",&flag);
   
		switch(flag)
		{
			case 1:
				creat_teacher_info();
				break;
			case 2:
				add_teacher_info();
				break;
			case 3:
				delete_teacher_info();
				break;
			case 4:  
				change_teacher_info();
				break;
			case 5:  
				show_teacher_info();
				break;
			case 6:  
				break;
			case 7: 
				exit(0);
				break;
			default:
				printf("\n\t\t你选择的操作不存在，请从新选择\n");
				printf("按任意键继续.........");
				getchar();
				scanf("%c",&ch);
				break;
		}  
		if(flag==6)
			return ;
	}
}

int add_teacher_link(TlinkList plist,const TDataType *value)
{
	TLNode *p=NULL;
	TLNode *phead=plist;
       
	p=(TlinkList)malloc(sizeof(TLNode));
    
	if(p==NULL)
	{
		printf("malloc内存失败\n");
		return 0;
	}
	p->data=*value;
   
	while(phead->next!=NULL)
	{
		if(strncmp((phead->data).number,value->number,8)==0)
		{
			printf("教师号不能相同，添加失败\n");
			free(p);
			return 0;
		}
		phead=phead->next;
	}
	if(strncmp((phead->data).number,value->number,8)==0)
	{
		//printf("\n");
		free(p);
		return 0;
	}

	p->next=phead->next;
	phead->next=p;

	return 1;
}


TlinkList search_teacher_number_link(TlinkList plist,char* number)
{

	TlinkList phead=NULL;
	phead=plist->next;
   
	while(phead!=NULL)
	{
		if(strncmp((phead->data).number,number,8)==0)
		{
			break;  
		}
		phead=phead->next;
	}
	return phead;
}

/*change teacher infomation*/
void change_teacher_info()
{
	system("clear");
	print_teacher_head();
	TlinkList  phead=NULL;
	TlinkList p=NULL;
	TDataType   data;
	char  ch;
   

	printf("\n请输入你要修改的教师号:");
    //getchar();
	get_string(data.number,8);
    
	read_teacher_link(&phead,str_teacher);

	p=search_teacher_number_link(phead,data.number);
	if(p==NULL)
	{
		printf("你输入的教师号不存在");
		getchar();
		return ;
	}

	printf("\t\t\t姓名：");
	get_string(data.name,120);
    //scanf("%s",data.name);

	printf("\t\t\t密码：");
	get_string(data.password,30);
    //scanf("%s",data.password);

	printf("\t\t\t班级：");
	data.classroom=get_number(0,4);
	//scanf("%d",&(data.classroom));
	while(getchar()!='\n');

	p->data=data;
       //printf("\n\t\tadd success\n");
	printf("你是否要保存这次的修改?n/y ");
	ch=getchar();
	if(ch=='y')
	{   
           
		if(save_teacher_info(phead))
		{
			printf("\n保存成功!\n");
			//getchar();          
		}          
	}
	scanf("%c",&ch);
	free_teacher_link(&phead);
 
}
/*add teacher infomation*/
void add_teacher_info()
{
	system("clear");
	print_teacher_head();
	TlinkList  phead=NULL;
	TlinkList p=NULL;
	TDataType   data;
	char  ch;
	
	printf("\t\t清输入你想添加老师的信息\n");
	printf("\n\t\t\t教师序号：");
    //getchar();
	get_string(data.number,8);
	printf("\t\t\t姓名：");
	get_string(data.name,120);
    //scanf("%s",data.name);

	printf("\t\t\t密码：");
	get_string(data.password,30);
    //scanf("%s",data.password);

	printf("\t\t\t班级：");
	data.classroom=get_number(0,4);
	//scanf("%d",&(data.classroom));
	while(getchar()!='\n');
   
	read_teacher_link(&phead,str_teacher);

	if(add_teacher_link(phead,&data))
	{
       //printf("\n\t\tadd success\n");
		printf("是否要保存这次的修改?n/y ");
		ch=getchar();
		if(ch=='y')
		{   
           
			if(save_teacher_info(phead))
			{
				printf("\n保存成功!\n");
				//getchar();
			}
		}    
       
	}
	else
	{
		printf("\n\t\t添加失败\n");
		printf("教师号必须唯一");
	}
	scanf("%c",&ch);
	free_teacher_link(&phead);

}

/*delete teacher infomation*/
void delete_teacher_info()
{
	
	system("clear");
	print_teacher_head();
	TlinkList  p=NULL;
	TlinkList  phead=NULL;
	TlinkList  pre=NULL;
	char number[6];
	char ch;

	printf("输入你要删除教师的教师号:\n");
	printf("\t\t\t");
	get_string(number,6);
    
//read data from file
	read_teacher_link(&phead,str_teacher);

	p=phead->next;
	pre=phead;   

	while(p!=NULL && (strncmp((p->data).number,number,6)!=0))
	{
		pre=p;
		p=p->next;
	}

	if(p==NULL)
	{
		printf("你输入的教师号不存在\n");
		scanf("%c",&ch);
		return ;
	}
    
	pre->next=p->next;
	free(p);      
	printf("删除成功!\n");
	printf("是否要保存这次的修改?y/n ");    
	
	ch=getchar();
	if(ch=='y')
	{        
		if(save_teacher_info(phead))
		{
			printf("\n保存成功!\n");
			//getchar();
		}
	}    
	scanf("%c",&ch);
	free_teacher_link(&phead);
}

/*show teacher infomation*/
void show_teacher_info()
{
	char  ch;
	system("clear");
	print_teacher_head();
	TlinkList  phead=NULL;
//read data from file
	read_teacher_link(&phead,str_teacher);

	print_teacher_link(phead);
	getchar();
	scanf("%c",&ch);
	free_teacher_link(&phead);
	
}

void print_teacher_link(TlinkList plist)
{
	TlinkList pstu=NULL;
	pstu=plist->next;
  
	printf("\n\n\t\t教师序号    姓名      密码    班级\n");
	while(pstu!=NULL)
	{
		printf("\t\t%-12s%-10s%-8s%-8d",
			   (pstu->data).number,(pstu->data).name,
			   (pstu->data).password,
			   (pstu->data).classroom);
 
		pstu=pstu->next;
		printf("\n");
	}

	printf("\n");
} 


/*creat and initaion teacher infomation*/
void creat_teacher_info()
{  
	TlinkList  phead=NULL;
	TLNode *p=NULL;
	TDataType data;
	char ch;
  
	phead=(TlinkList)malloc(sizeof(TLNode));
	if(phead==NULL)
	{
		printf("memrroy false\n");
		return ;
	}

	(phead->data).number[0]='\0';
	(phead->data).name[0]='\0';
	(phead->data).password[0]='\0';	
	(phead->data).classroom=-1;
	phead->next=NULL;

	printf("\n\t\t以教师序号0结束: \n");

	printf("\t\t\t教师序号：");
	get_string(data.number,8);

	while(strncmp(data.number,"0",8)!=0)
	{
		p=(TlinkList)malloc(sizeof(TLNode));
		if(p==NULL)
		{
			return ;
		}

		printf("\t\t\t姓名：");
		get_string(data.name,120);
    //scanf("%s",data.name);

		printf("\t\t\t密码：");
		get_string(data.password,30);
    //scanf("%s",data.password);

		printf("\t\t\t班级：");
		scanf("%d",&(data.classroom));
		while(getchar()!='\n');

		p->data=data;
		p->next=phead->next;
		phead->next=p;
   
		printf("\n\t\t\t教师序号：");
    //getchar();
		get_string(data.number,8);
	}
	printf("\n");
	printf("你想保存这次的修改吗?n/y ");
	ch=getchar();
	if(ch=='y')
	{   
           
		if(save_teacher_info(phead))
		{
			printf("\n保存成功!\n");
			//getchar();
		}
	}    
	scanf("%c",&ch);
	free_teacher_link(&phead);
	
}

int read_teacher_link(TlinkList *phead,char *str)
{
	FILE *fp=NULL;
	TLNode *p=NULL;
    //DLNode *q=NULL;
	*phead=(TlinkList)malloc(sizeof(TLNode));
	if(*phead==NULL)
	{
		//printf("memrroy false\n");
		return ;
	}
	((*phead)->data).number[0]='\0';
	((*phead)->data).name[0]='\0';
	((*phead)->data).password[0]='\0';	
	((*phead)->data).classroom=-1;
	(*phead)->next=NULL;
   
    //q=(*plist)->next;
	if((fp=fopen(str_teacher,"r"))==NULL) 
	{
		//printf("open file i!\n");
		return 0;
	}
   
	while(!feof(fp))
	{
		p=(TlinkList)malloc(sizeof(TLNode));
		if(p==NULL)
		{
			//printf("memrroy false\n");
			return ;
		}

		if(fread(p,sizeof(TDataType),1,fp)!=1)
		{
           //printf("read error\n");
			free(p);
			return ;
		}
        //printf("p=%d,p->name=%s\n",p,(p->data).name);
		p->next=(*phead)->next;
		(*phead)->next=p;
	}
	fclose(fp);
	return 1;
}


/*save teacher infomation*/
int save_teacher_info(const TlinkList plist)
{
	FILE *fpw=NULL;
	TLNode *p=NULL;

	if((fpw=fopen(str_teacher,"w"))==NULL) 
	{
		//printf("open file is false!\n");
		return 0;
	}

	p=plist->next;
	while(p!=NULL)
	{
		if(fwrite(&(p->data),sizeof(TDataType),1,fpw)!=1)
		{
         //printf("write error\n");
			return 0;
		}
		p=p->next;
	}

	fclose(fpw);
	return 1;
}  


void free_teacher_link(TlinkList *plist)
{
	TLNode *p=NULL;
	TLNode *q=NULL;
	p=*plist;

	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
}














