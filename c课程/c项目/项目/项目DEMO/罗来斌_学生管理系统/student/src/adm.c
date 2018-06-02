
#include"adm.h"

void print_adm_head()
{
	printf("\t\t***************************************\n");
	printf("\t\t***************************************\n");
	printf("\t\t***********学生管理系统欢迎*************\n");
	printf("\t\t***************************************\n");
	printf("\t\t***************************************\n");
}


void print_adm_main()
{
	int flag=0;
	char ch;
	while(1)
	{
		system("clear");
		print_adm_head();

		printf("\n\n\t请选择你要的操作\n");
		printf("\t\t\t1.查看个人信息\n");
		printf("\t\t\t2.修改密码\n");
		printf("\t\t\t3.管理老师信息\n");
		printf("\t\t\t4.管理学生信息\n");
		printf("\t\t\t5.返回上一层 \n");
		printf("\t\t\t6.退出\n");
		printf("\n\t\t");

   		flag=-1;
		scanf("%d",&flag);
   
		switch(flag)
		{
			case 1:
				show_adm_info();
				break;
			case 2:
				change_adm_password();
				break;
			case 3:
				print_teacher_main();
				break;
			case 4:  
				print_stu_main();
				break;
			case 5:  
				break;
			case 6:  
				exit(0);
				break;
			default:
				printf("\t你选择的操作不存在，请从新选择\n");
				printf("\n按任意键继续.........");
				getchar();
				scanf("%c",&ch);
				break;
		}  
		if(flag==5)
			return ;
	}
}

void change_adm_password()
{
	Adm adm;
	system("clear");
	print_adm_head();
	char ch;
	
	read_adm_info(&adm);
	printf("\n\n\n\t\t输入你的新密码: \n");
	printf("\t\t\t");
	get_string(adm.password,10);
	
	printf("是否保存这次的修改?n/y ");
	ch=getchar();
	if(ch=='y')
	{
		scanf("%c",&ch);
		save_adm_info(&adm);
		printf("\t\t\t保存成功");
	}
	scanf("%c",&ch);
}

void read_adm_info(Adm *adm)
{
	FILE *fp;
	if((fp=fopen("../data/adm","r"))==NULL)
    {
		printf("文件打开失败!\n");
		return ;
    }
	fread(adm,sizeof(struct adm_node),1,fp);
	fclose(fp);
}
void save_adm_info(Adm *adm)
{
	FILE *fp;
  //open file 
	if((fp=fopen("../data/adm","w"))==NULL)
	{
		printf("文件打开失败!\n");
		return ;
	}
  //write student data to stu_list


	if((fwrite(adm,sizeof(struct adm_node),1,fp))!=1)
	{
		printf("数据写人文件失败!\n");
	}
	fclose(fp);
}

void show_adm_info()
{
	Adm adm;
	system("clear");
	print_adm_head();
	char ch;
	
	read_adm_info(&adm);
	
	printf("\n\n\t\t姓名       教师号      密码\n");
	printf("\t\t%-12s%-10s%-12s\n",adm.name,adm.number,adm.password);
	getchar();
	scanf("%c",&ch);
}
/*int main()
{
	print_adm_main();
}*/

