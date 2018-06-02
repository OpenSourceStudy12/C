#ifndef _FUN_H
#define _FUN_H

#include<stdlib.h>
#include<string.h>

#define MAX 20

typedef struct stu
{
	int num;
	char name[MAX];
	float score;
	struct stu *next;
}STU,*PStu;

PStu Listcreat_from_end();
void Listprint(PStu head);
void Listsh_name(PStu head,char *sh);
void Listsh_rate(PStu head,float a,float b);
PStu Listcreat_from_head();





#endif
