


#include"manager_stu.h"


/*主菜单上的头部分*/
void print_stu_head()
{
      printf("\t\t***************************************\n");
      printf("\t\t***************************************\n");
      printf("\t\t***********学生管理系统欢迎*************\n");
      printf("\t\t***************************************\n");
      printf("\t\t***************************************\n");
}
//char *str="//2222//student//src//data//stu";
char  *str="../data/stu";  
void print_stu_main()
{
   int flag=0;
   char ch;
   while(1)
   {
      system("clear");
	  print_stu_head();
      printf("\n\n\t\t\t请选择你要的操作\n");
      printf("\t\t1.创建并初始化学生信息\n");
      printf("\t\t2.添加学生信息\n");
      printf("\t\t3.删除学生信息\n");
      printf("\t\t4.查询学生信息\n");
      printf("\t\t5.修改学生信息\n");
      printf("\t\t6.打印学生信息\n");
      printf("\t\t7.返回上一层 \n");
      printf("\t\t8.退出\n");
      printf("\n\t\t");
   
	  flag=-1;
      scanf("%d",&flag);
   
      switch(flag)
      {
        case 1:
                creat_stu_info();
                break;
        case 2:
                 add_stu_info();
                 break;
        case 3:
                 delete_stu_info();
                 break;
        case 4:  
                 select_stu_info();
                 break;
        case 5:  
                 change_stu_info();
                 break;
        case 6:  
                 show_stu_sort_main();
                 break;
        case 7:  
                 break;          
        case 8: 
                 exit(0);
                 break;
        default:
                 printf("你选择的操作不存在，请从新选择\n");
				 printf("\n按任意键继续........\n");
				 getchar();
				 scanf("%c",&ch);
                 break;
       }  
       if(flag==7)
          return ;
    }
}

void show_stu_sort_main()
{
      //system("clear");
      int flag=-1;
	  char ch;
      while(1)
      {
		  system("clear");
		  print_stu_head();
         printf("\n\n\t\t\t请选择你要的操作\n");
         printf("\t\t0.打印学生信息 \n");
         printf("\t\t1.按低到高的顺序显示c语言成绩 \n");
         printf("\t\t2.按低到高的顺序显示数学成绩 \n");
         printf("\t\t3.按低到高的顺序显示中文成绩\n");
         printf("\t\t4.按低到高的顺序显示名次\n");
         printf("\t\t5.返回上一层\n");
         printf("\t\t6.退出\n");
         printf("\n\t\t");

		 flag=-1;
         scanf("%d",&flag);
     
         switch(flag)
         {
           case 0:
                  print_stu_info();
                  break;
           case 1:
                print_stu_clanguage_info();
                break;
           case 2:
                print_stu_math_info();
                break;
           case 3:
                print_stu_chinese_info();
                break;
           case 4:  
                print_stu_repute_info();
                break;
           case 5:  
                
                break;
           case 6: 
                 exit(0);
                 break;
           default:
                 printf("\n\t\t你选择的操作不存在，请从新选择\n");
				 printf("\n按任意键继续........\n");
				 getchar();
				 scanf("%c",&ch);
                 break;
        }  
       if(flag==5)
          return ;
    }


}

void print_stu_repute_info()
{
	char  ch;
	system("clear");
	print_stu_head();

	linkList phead=NULL;     
	linkList pre=NULL;
	linkList p=NULL;
	linkList q=NULL;
//read data from file
	read_link(&phead,str);
	
	p=phead->next;
	if(p!=NULL)
	{
		q=p->next;
	}
	p->next=NULL;
	/*sort math begin*/ 
	while(q!=NULL)
	{
		pre=phead;
		p=phead->next; //每次都从开头比较 
		//寻找比较的位置
		while(p!=NULL&&(q->data).score.repute>(p->data).score.repute)
		{
			pre=p;
			p=p->next;
		}
		p=q;
		q=q->next;
			
		p->next=pre->next;
		pre->next=p; 
	}
	/*sort math end*/
	print_link(phead);
	getchar();
	scanf("%c",&ch);
	free_link(&phead);


}
void print_stu_chinese_info()
{
	char  ch;
	system("clear");
	print_stu_head();

	linkList phead=NULL;     
	linkList pre=NULL;
	linkList p=NULL;
	linkList q=NULL;
//read data from file
	read_link(&phead,str);
	
	p=phead->next;
	if(p!=NULL)
	{
		q=p->next;
	}
	p->next=NULL;
	/*sort math begin*/ 
	while(q!=NULL)
	{
		pre=phead;
		p=phead->next; //每次都从开头比较 
		//寻找比较的位置
		while(p!=NULL&&(q->data).score.chinese>(p->data).score.chinese)
		{
			pre=p;
			p=p->next;
		}
		p=q;
		q=q->next;
			
		p->next=pre->next;
		pre->next=p; 
	}
	/*sort math end*/
	print_link(phead);
	getchar();
	scanf("%c",&ch);
	free_link(&phead);
}
void print_stu_clanguage_info()
{
	char  ch;
	system("clear");
	print_stu_head();

	linkList phead=NULL;     
	linkList pre=NULL;
	linkList p=NULL;
	linkList q=NULL;
//read data from file
	read_link(&phead,str);
	
	p=phead->next;
	if(p!=NULL)
	{
		q=p->next;
	}
	p->next=NULL;
	/*sort math begin*/ 
	while(q!=NULL)
	{
		pre=phead;
		p=phead->next; //每次都从开头比较 
		//寻找比较的位置
		while(p!=NULL&&(q->data).score.c_language>(p->data).score.c_language)
		{
			pre=p;
			p=p->next;
		}
		p=q;
		q=q->next;
			
		p->next=pre->next;
		pre->next=p; 
	}
	/*sort math end*/
	print_link(phead);
	getchar();
	scanf("%c",&ch);
	free_link(&phead);



}

void print_stu_math_info()
{
    char  ch;
    system("clear");
	print_stu_head();

    linkList phead=NULL;     
    linkList pre=NULL;
    linkList p=NULL;
    linkList q=NULL;
//read data from file
    read_link(&phead,str);
	
	p=phead->next;
	if(p!=NULL)
	{
		q=p->next;
	}
	p->next=NULL;
/*sort math begin*/ 
    while(q!=NULL)
    {
		pre=phead;
		p=phead->next; //每次都从开头比较 
		//寻找比较的位置
        while(p!=NULL&&(q->data).score.math>(p->data).score.math)
		{
            pre=p;
            p=p->next;
        }
		p=q;
		q=q->next;
			
		p->next=pre->next;
		pre->next=p; 
    }
/*sort math end*/
    print_link(phead);
    getchar();
    scanf("%c",&ch);
    free_link(&phead);

}


void change_stu_info()
{
    system("clear");
	print_stu_head();
    linkList  phead=NULL;
    linkList p=NULL;
    DataType   data;
    char  ch;
   

    printf("\n输入你要修改的学生号：");
    //getchar();
    get_string(data.number,8);
    
	read_link(&phead,str);

    p=search_number_link(phead,data.number);
    if(p==NULL)
    {
       printf("\n你输入的学生号不存在 ");
       getchar();
       return ;
    }

    printf("\t\t\t姓名：");
    get_string(data.name,120);
    //scanf("%s",data.name);

    printf("\t\t\t密码：");
    get_string(data.password,30);
    //scanf("%s",data.password);

    printf("\t\t\t年龄：");
	data.age=get_number(15,26);
    //scanf("%d",&(data.age));
    while(getchar()!='\n');

    printf("\t\t\t班级：");
	data.classroom=get_number(0,4);
    //scanf("%d",&(data.classroom));
    while(getchar()!='\n');

    printf("\t\t\t数学成绩：");
	data.score.math=get_number(0,100);
    //scanf("%d",&(data.score.math));
    while(getchar()!='\n');

    printf("\t\t\tC语言成绩：");
	data.score.c_language=get_number(0,100);
    //scanf("%d",&(data.score.c_language));
    while(getchar()!='\n');

    printf("\t\t\t中文成绩：");
	data.score.chinese=get_number(0,100);
    //scanf("%d",&(data.score.chinese));
    while(getchar()!='\n');

    printf("\t\t\t名次：");
	data.score.repute=get_number(1,50);
    //scanf("%d",&(data.score.repute));
    while(getchar()!='\n');

    p->data=data;
       //printf("\n\t\tadd success\n");
    printf("是否要保存这次的修改?n/y ");
    ch=getchar();
    if(ch=='y')
    {   
           
        if(save_link(phead))
        {
            printf("\n保存成功!\n");
            //getchar();          
       }          
    }
    scanf("%c",&ch);
	free_link(&phead);
}

void add_stu_info()
{

    system("clear");
	print_stu_head();
    linkList  phead=NULL;
    DataType   data;
    char  ch;
   

    printf("\n\t\t\t学号：");
    //getchar();
    get_string(data.number,8);

    printf("\t\t\t姓名：");
    get_string(data.name,120);
    //scanf("%s",data.name);

    printf("\t\t\t密码：");
    get_string(data.password,30);
    //scanf("%s",data.password);

    printf("\t\t\t年龄：");
    data.age=get_number(15,26);
    //printf("\n");
	while(getchar()!='\n');

    printf("\t\t\t班级：");
	data.classroom=get_number(0,4);
    //printf("\n");
	while(getchar()!='\n');

    printf("\t\t\t数学成绩：");
	data.score.math=get_number(0,100);
	//printf("\n");
    // scanf("%d",&(data.score.math));
    while(getchar()!='\n');

    printf("\t\t\tC语言成绩：");
	data.score.c_language=get_number(0,100);
	//printf("\n");
    //scanf("%d",&(data.score.c_language));
    while(getchar()!='\n');

    printf("\t\t\t中文成绩：");
	data.score.chinese=get_number(0,100);
	//printf("\n");
    //scanf("%d",&(data.score.chinese));
    while(getchar()!='\n');

    printf("\t\t\t名次：");
	data.score.repute=get_number(1,50);
	//printf("\n");
    //scanf("%d",&(data.score.repute));
    while(getchar()!='\n');

    read_link(&phead,str);

    if(add_link(phead,&data))
    {
       //printf("\n\t\tadd success\n");
      printf("是否保存本次的修改?n/y ");
      ch=getchar();
      if(ch=='y')
      {   
           
           if(save_link(phead))
           {
                printf("\n保存成功!\n");
                //getchar();
           }
       }    
       
    }
    else
    {
       printf("\n\t\t添加失败\n");
       printf("学号必须唯一");
     }
    scanf("%c",&ch);
    free_link(&phead);

}


void select_stu_info()
{
    system("clear");
	print_stu_head();
    linkList  pstu=NULL;
    linkList  phead=NULL;
    char name[20];
    char ch;

    printf("请输入学生的姓名：\n");
    printf("\t\t\t");
    get_string(name,20);
    
//read data from file
    read_link(&phead,str);

    pstu=search_name_link(phead,name);
    if(pstu==NULL)
    {
        printf("\n你输入的姓名不存在");
        getchar();
        return ;
     }
    printf("\t学号    姓名    密码    数学    C语言   语文   名次\n");
    printf("\t%-8s%-10s%-10s%-8d%-8d%-8d%-8d",
           (pstu->data).number,(pstu->data).name,(pstu->data).password,
		   (pstu ->data).score.math, (pstu->data).score.c_language,
		   (pstu->data).score.chinese  ,(pstu->data).score.repute);
   
   scanf("%c",&ch);
   free_link(&phead);

}

void creat_stu_info()
{
      char ch;
      linkList  phead=NULL;
      system("clear");
	  print_stu_head();
      creat_link(&phead);
     
      printf("是要保存这次的修改，之前的数据会被删除?n/y ");
      ch=getchar();
      if(ch=='y')
      {   
           
           if(save_link(phead))
           {
                printf("\n保存成功!");
                //getchar();
           }
       }    
     scanf("%c",&ch);
     free_link(&phead);
}
  
void  print_stu_info()
{
     char  ch;
     system("clear");
	 print_stu_head();
     linkList  phead=NULL;
//read data from file
     read_link(&phead,str);

     //printf("phead=%x,*phead=%d\n",phead,*phead);

     print_link(phead);
     getchar();
     scanf("%c",&ch);
     free_link(&phead);
}

void delete_stu_info()
{
    system("clear");
	print_stu_head();
    linkList  pstu=NULL;
    linkList  phead=NULL;
    char number[6];
    char ch;

    printf("输入你要删除的学号:\n");
    printf("\t\t\t");
    get_string(number,6);
    
//read data from file
    read_link(&phead,str);

    if(delete_link(phead,number)==0)
    {
        printf("\n\n没有你输入的学号");
		scanf("%c",&ch);
        return ;
     }
 
           
     printf("删除成功\n");
     printf("是否要保存本次的操作?y/n ");
     
     ch=getchar();
     if(ch=='y')
      {   
           
           if(save_link(phead))
           {
                printf("\n\t\t保存成功!");
                //getchar();
           }
       }    
     scanf("%c",&ch);
     free_link(&phead);
}


