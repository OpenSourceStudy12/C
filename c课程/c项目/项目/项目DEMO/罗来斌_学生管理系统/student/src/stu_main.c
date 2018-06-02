#include "stu_main.h"
#include<string.h>
#include<stdlib.h>

/*主菜单上的头部分*/
void print_head()
{
      printf("\t\t***************************************\n");
      printf("\t\t***************************************\n");
      printf("\t\t**********学生管理系统欢迎同学***********\n");
      printf("\t\t***************************************\n");
      printf("\t\t***************************************\n");
}

/* 学生主菜单*/
void  stu_main(char number[10])
{
   int flag=0;
   char ch;
   while(1)
   {
      system("clear");
      print_head();
      printf("\n\n\t\t\t请选择你要的操作\n");
      printf("\t\t1.修改密码\n");
      printf("\t\t2.查看个人信息\n");
	  printf("\t\t3.返回上一层\n");
      printf("\t\t4.退出系统\n");
      printf("\n\t\t");
   
	  flag=-1;
      scanf("%d",&flag);
   
      switch(flag)
      {
          case 1:
			  set_password(number);
                break;
          case 2:
			  print_student(number);
                 break;
          case 3:
			  return ;
                 break;
		  case 4:
			  exit(0);
        default:
                 printf("\n\t\t你选择的操作不存在，请从新选择\n");
				 printf("\n按任意键继续.......\n");
				 getchar();
				 scanf("%c",&ch);
                 break;
       }  
    }
}


/*修改密码*/
void  set_password(char number[10])
{
	linkList phead=NULL;
	linkList pstu=NULL;
    char password[8];
    char  ch;
    
    system("clear");
    print_head(pstu);
	
	read_link(&phead,"../data/stu");	
	pstu=search_number_link(phead,number);
	
    printf("请输入你的新密码\n");
    scanf("%s",password); 
    getchar();
    
	strcpy((pstu->data).password,password);
	
    printf("你要保存你的更改吗？n/y"); 
	ch=getchar();
    if(ch=='y')
    {
         save_link(phead);
         printf("\n保存更改成功");
    }   
	scanf("%c",&ch);
	free_link(&phead);
}

void print_student(char number[10])
{
	linkList phead=NULL;
	linkList pstu=NULL;
    char  ch;
    system("clear");
    print_head();
	
	read_link(&phead,"../data/stu");	
	pstu=search_number_link(phead,number);
	
    printf("\n");
    printf("\t学号   姓名    密码   数学   C语言   语文   名次\n");
    printf("\t%-7s%-9s%-7s%-8d%-8d%-8d%-8d",
		   (pstu->data).number,(pstu->data).name,(pstu->data).password,(pstu->data).score.math,(pstu->data).score.c_language,(pstu->data).score.chinese,
				   (pstu->data).score.repute);

    printf("\n");
    getchar();
    scanf("%c",&ch);
	free_link(&phead);

}









