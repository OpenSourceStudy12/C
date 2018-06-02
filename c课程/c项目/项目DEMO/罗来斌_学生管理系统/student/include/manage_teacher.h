
#ifndef _MANAGE_TEACHER_H
#define _MANAGE_TEACHER_H
#include<stdio.h>
#include<string.h>
#include"check.h"
#include"input.h"


/*struct define*/
typedef struct teacher_node
{
	char number[8];
	char name[20];
	char password[20];
	int classroom;
}teacher_info;

typedef teacher_info  TDataType;

typedef struct tea_node
{
	TDataType data;
	struct tea_node *next;
}*TlinkList,TLNode;

/*operate define*/

/*UI main*/
void print_teacher_main();

/*UI head*/
void print_teacher_head();

/*creat and initaion teacher infomation*/
void creat_teacher_info();

/*add teacher infomation*/
void add_teacher_info();

/*delete teacher infomation*/
void delete_teacher_info();

/*change teacher infomation*/
void change_teacher_info();

/*show teacher infomation*/
void show_teacher_info();

/*save teacher infomation*/
int save_teacher_info(const TlinkList plist);

/*free tlinklist*/
void  free_teacher_link(TlinkList *plist);

void print_teacher_link(TlinkList plist);

int add_teacher_link(TlinkList plist,const TDataType *value);

int read_teacher_link(TlinkList *phead,char *str);

TlinkList search_teacher_number_link(TlinkList plist,char* number);

int add_teacher_link(TlinkList plist,const TDataType *value);

#endif






