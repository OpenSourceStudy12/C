/*
*    Filename       :link.c
*    Author         :luolaibin
*    Create Data    :2012-3-15
*    Histroy Data   :2012-3-16
*/
#include"link.h"


int creat_link(linkList *plist)
{
  //have head node
  DLNode *p,*q;
  DataType data;
  
  *plist=(struct node*)malloc(sizeof(DLNode));
  if(*plist==NULL)
  {
     printf("memrroy false\n");
     return 0;
  }

  ((*plist)->data).number[0]='\0';
  ((*plist)->data).name[0]='\0';
  ((*plist)->data).password[0]='\0';
  ((*plist)->data).age=0;
  ((*plist)->data).classroom=-1;
  ((*plist)->data).score.math=0;
  ((*plist)->data).score.c_language=0;
  ((*plist)->data).score.chinese=0;
  ((*plist)->data).score.repute=0; 
  (*plist)->next=NULL;

  printf("\n\t\t以学号0结束: \n");

  printf("\t\t\t学号：");
  get_string(data.number,8);
  /*do
  {
     while(get_char(data.number,8)==0);
   }while(strncmp(data.number,"",8)==0);
*/
  while(strncmp(data.number,"0",8)!=0)
  {
    p=(struct node*)malloc(sizeof(DLNode));
    if(p==NULL)
    {
        return 0;
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
    p->next=(*plist)->next;
    (*plist)->next=p;
   
    printf("\n\t\t\t学号：");
    //getchar();
    get_string(data.number,8);
  }
  printf("\n");

  return 1;
}


void free_link(linkList *plist)
{
   DLNode *p=NULL;
   DLNode *q=NULL;
   p=*plist;

   while(p!=NULL)
   {
     q=p;
     p=p->next;
     free(q);
   }
}

/*linkList find_link(const linkList plist,const DataType *value,DLNode *pre)
{   
    printf("find_link\n");
    DLNode *p=NULL;
    p=plist->next;
    pre=plist;

    while((*value<p->data)&&(p!=NULL))
    { 
        pre=p;
        p=p->next;
    }
    return p;
}*/

int insert_link(linkList plist,const DataType *value,int index)
{
    DLNode *p=NULL;
    int m_index=index;
    DLNode *pre=NULL;
   
    p=(struct node*)malloc(sizeof(DLNode));
    
    if(p==NULL)
    {
      printf("merroy false\n");
      return 0;
    }
    p->data=*value;
    pre=plist;
    while(m_index>0 &&pre!=NULL)
    {
       pre=pre->next;
       m_index--;
    }
    if(pre==NULL)
    {
      printf("this index is wrrong\n");
      return 0;
    }

    p->next=pre->next;
    pre->next=p;

    return 1;
}
int lenght_link(const linkList plist)
{
   DLNode *p=NULL;
   int count=0;

   p=plist->next;
   while(p!=NULL)
   {
     p=p->next;
     count++;
   }

   return count;
}
int delete_link(linkList plist,const char *number)
{
    DLNode *p=NULL;
    DLNode *pre=NULL;

    p=plist->next;
    pre=plist;   

    while(p!=NULL && (strncmp((p->data).number,number,6)!=0))
    {
       pre=p;
       p=p->next;
    }

    if(p==NULL)
    {
        return 0;
    }
    
    pre->next=p->next;
    free(p);

    return 1;
}
/*int deleteIndex(linkList plist,unsigned int index)
{
     linkList p=NULL;
     if(index<0)
     {
         return 0;
     } 
}*/
int save_link(const linkList plist)
{
   FILE *fpw=NULL;
   DLNode *p=NULL;

   if((fpw=fopen("../data/stu","w"))==NULL) 
   {
      printf("open file is false!\n");
      return 0;
   }

   p=plist->next;
   while(p!=NULL)
   {
      if(fwrite(&(p->data),sizeof(DataType),1,fpw)!=1)
      {
         //printf("write error\n");
         return 0;
       }
      p=p->next;
   }

   fclose(fpw);
   return 1;
}  

int add_link(linkList plist,const DataType *value)
{
    DLNode *p=NULL;
    DLNode *phead=plist;
       
    p=(struct node*)malloc(sizeof(DLNode));
    
    if(p==NULL)
    {
      printf("merroy false\n");
      return 0;
    }
    p->data=*value;
   
    while(phead->next!=NULL)
    {
       if(strncmp((phead->data).number,value->number,8)==0)
       {
              printf("number same\n");
              free(p);
              return 0;
        }
       phead=phead->next;
    }
    if(strncmp((phead->data).number,value->number,8)==0)
    {
        printf("number same\n");
        free(p);
        return 0;
    }

    p->next=phead->next;
    phead->next=p;

    return 1;
}

  
int read_link(linkList *plist,char *str)
{
    FILE *fp=NULL;
    DLNode *p=NULL;
    //DLNode *q=NULL;
    *plist=(struct node*)malloc(sizeof(DLNode));
    if(*plist==NULL)
    {
       printf("memrroy false\n");
       return ;
    }
    ((*plist)->data).number[0]='\0';
    ((*plist)->data).name[0]='\0';
    ((*plist)->data).password[0]='\0';
    ((*plist)->data).age=0;
    ((*plist)->data).classroom=-1;
    ((*plist)->data).score.math=0;
    ((*plist)->data).score.c_language=0;
    ((*plist)->data).score.chinese=0;
    ((*plist)->data).score.repute=0; 
    (*plist)->next=NULL;
   
    //q=(*plist)->next;
    if((fp=fopen(str,"r"))==NULL) 
    {
       printf("open file is false!\n");
       return 0;
    }
   
    while(!feof(fp))
    {
        p=(struct node*)malloc(sizeof(DLNode));
        if(p==NULL)
        {
         printf("memrroy false\n");
         return ;
        }

        if(fread(p,sizeof(DataType),1,fp)!=1)
        {
           //printf("read error\n");
           free(p);
            return ;
         }
        //printf("p=%d,p->name=%s\n",p,(p->data).name);
        p->next=(*plist)->next;
        (*plist)->next=p;
   }
   fclose(fp);
   return 1;
}
   
void print_link(linkList plist)
{
  linkList pstu=NULL;
  pstu=plist->next;
  
  printf("\t学号    姓名      密码    数学    C语言    语文   名次\n");
  while(pstu!=NULL)
  {
     printf("\t%-8s%-10s%-10s%-8d%-8d%-8d%-8d",
           (pstu->data).number,(pstu->data).name,(pstu->data).password,
		   (pstu->data).score.math,(pstu->data).score.c_language,
		   (pstu->data).score.chinese,(pstu->data).score.repute);
 
     pstu=pstu->next;
     printf("\n");
   }

   printf("\n");
} 

/*
linkList searchKey_link(linkList plist,int key)
{
   linkList phead=NULL;
   int nkey=key;
   phead=plist->next;
   
   while(nkey>=0&&phead!=NULL)
   {
      phead=phead->next;
      nkey--;
   }
   return phead;
}
*/
linkList search_name_link(linkList plist,char *name)
{
    linkList phead=NULL;
    phead=plist->next;
   
    while(phead!=NULL&&strncmp((phead->data).name,name,20))
    {
        phead=phead->next;
    }
    return phead;
}
linkList search_number_link(linkList plist,char* number)
{

    linkList phead=NULL;
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


/*linkList searchValue_link(linkList plist,const DataType* value)
{
    linkList phead=NULL;
    phead=plist->next;
   
    while(phead!=NULL&&phead->data!=*value)
    {
        phead=phead->next;
    }
    return phead;
}
   
void sortH_link(linkList plist)
{
    linkList pnew=NULL;
    linkList p=NULL;
    linkList q=NULL;
    linkList qpre=NULL;

    pnew=plist;
  
    plist=plist->next;
  
    while(plist!=NULL)
    {
        p=plist->next;
        q=pnew->next; 
        qpre=pnew;
    
        while(q!=NULL&&p!=NULL&&q->data>p->data)
        {
           qpre=q;
           q=q->next;
        }
        if(p!=NULL)
        {
           p->next=q;
           qpre->next=p;  
        }       
        plist=plist->next; 
    }
}

void sortL_link(linkList plist)
{
     linkList p=NULL;
     linkList phead=NULL;
     linkList min=NULL;
     DataType temp;
     
     phead=plist->next;
     
     
     while(phead!=NULL)
     {  
         min=phead;
         p=phead->next;
     
         while(p!=NULL)
         {
            if(min->data>p->data)
             {  
                 min=p;
              }
              p=p->next;
         }
         
         temp=phead->data;
         phead->data=min->data;
         min->data=temp;
    
         phead=phead->next;        
      }
     
}     
        
  */     



 

 
