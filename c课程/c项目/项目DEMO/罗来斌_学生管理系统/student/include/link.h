/*
*   Filename       :link.h
*   Author         :luolaibin
*   Create Data    :2012-3-15
*   Histroy Data   :2012-3-16
*/




#ifndef _LINK_H_
#define _LINK_H_

#include<stdlib.h>
#include "check.h"
#include "student.h"
#include <string.h>
#include "input.h"

typedef stu_info DataType;
typedef struct node
{
  DataType data;
  struct node *next;
}DLNode,*linkList;


/*operate define*/
int creat_link(linkList *plist);  /*create linlist*/
/*delete linklist node*/
int delete_link(linkList plist,const char *number);

/*find linklist node*/
//linkList find_link(const linkList plist,const DataType //*value,DLNode *pre);

/*free merroy*/
void  free_link(linkList *plist);
/*insert link node*/
int insert_link(linkList plist,const DataType *value,int index);

int add_link(linkList plist,const DataType *value);

/*linklist lenght*/
int lenght_link(const linkList plist);
/*save linklist to file*/
int save_link(const linkList plist);
/*print linklist every node*/
void print_link(linkList plist);
/*search node in key*/
linkList searchKey_link(linkList plist,int key);

linkList search_number_link(linkList phead,char*number);

linkList search_name_link(linkList plist,char *name);
/*search node in value*/
linkList  searchValue_link(linkList plist,const DataType *value);
/*sort linklist from big to small*/
void sortH_link(linkList plist);
/*sort linklist from small to big*/
void sortL_link(linkList plist); 

int  read_link(linkList *plist,char *str);

#endif
