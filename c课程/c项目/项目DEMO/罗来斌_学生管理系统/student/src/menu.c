

#include "menu.h"
void print_menu_head()
{
	printf("\t\t***************************************\n");
	printf("\t\t***************************************\n");
	printf("\t\t***********学生管理系统欢迎*************\n");
	printf("\t\t***************************************\n");
	printf("\t\t***************************************\n");
}


void print_menu()
{
	int flag=0;
	char ch;
	while(1)
	{
		system("clear");
		print_menu_head();
		printf("\t\t\t1.管理员登录 \n");
		printf("\t\t\t2.教师登录\n");
		printf("\t\t\t3.学生登录\n");
		printf("\t\t\t4.退出\n");
		printf("\n\t\t");
        flag=-1;
		scanf("%d",&flag);
   
		switch(flag)
		{
			case 1:
				load_adm();
				break;
			case 2:
				load_teacher();
				break;
			case 3:
				load_stu();
				break;
			case 4:  
				exit(0);
				break;
			default:
				printf("\n\t你选择的操作不存\n");
				printf("\n按任意键继续......\n");
				getchar();
			    scanf("%c",&ch);
				break;
		}

	}
}

void load_adm()
{
	char number[10];
	char password[10];
	Adm adm;

	char ch;
	
	printf("\t\t\t管理员帐号: ");
	get_string( number,10);
	printf("\n\t\t\t管理员密码: ");
	get_password(password,10);
	
	read_adm_info(&adm);

	if(strncmp(adm.number,number,8)==0&&strncmp(adm.password,password,8)==0)
	{
		print_adm_main();
	}
	else
	{
		printf("\n\t\t密码或帐号不正确\n");
		scanf("%c",&ch);
		return ;
	}

}

void load_stu()
{
	char number[10];
	char password[10];
	linkList phead=NULL;
	linkList p=NULL;
	char ch;
	
	printf("\t\t\t学生帐号: ");
	get_string(number,8);
	printf("\n\t\t\t学生密码: ");
	get_password(password,10);
	
	read_link(&phead,"../data/stu");
	p=search_number_link(phead,number);
	
	if(p!=NULL&&strncmp((p->data).password,password,8)==0)
	{
		stu_main(number);
	}
	else
	{
		printf("\n\t\t密码或帐号不正确\n");
		scanf("%c",&ch);
		free_link(&phead);
		return ;
	}
	free_link(&phead);
}



void load_teacher()
{
	char number[10];
	char password[10];
	TlinkList phead=NULL;
	TlinkList p=NULL;
	char ch;
	
	printf("\t\t\t老师帐号: ");
	get_string( number,10);
	printf("\t\t\t老师密码: ");
	get_password(password,10);
	
	read_teacher_link(&phead,"../data/student");
	p=search_teacher_number_link(phead,number);
	if(p!=NULL&&strncmp((p->data).password,password,8)==0)
	{
		print_teacher_person_main(number);
	}
	else
	{
		printf("\n\t\t密码或帐号不正确\n");
		scanf("%c",&ch);
		free_teacher_link(&phead);
		return ;
	}
	free_teacher_link(&phead);
}


int main()
{
	print_menu();
	return 0;
}
