#include <stdio.h>
#include "link.h"
#include <string.h>
#include <stdlib.h>



#define NAME_LEN 20

typedef struct student
{
	int num;
	char name[NAME_LEN];
	char sex;
	int cScore;
	int math;
	int chinese;
}STU;

Llink *creat_stu_link()
{
	Llink * head=link_init();
	STU *s = NULL;
	int i=0;
	for(;i<5;i++)
	{
		s=(STU*)malloc(sizeof(STU));
		memset(s,0,sizeof(STU));
		s->num = 1000+i;
		gets(s->name);
		link_insert(head,(void*)s);
	}
	return head;
}
void stu_link_print(Llink *head)
{
	int len = head->len;
	int i=1;
	linklist p=NULL;
	STU *data;
	for(;i<=len;i++)
	{
		p = link_search(head,i);
		if(p!=NULL)
		{
			data=(STU*)p->data;
			printf("学号 :%d,姓名: %s\n",data->num,data->name);
		}
	}
}
int main()
{
	Llink *head = creat_stu_link();
	printf("len = %d\n",head->len);
	stu_link_print(head);
	
}
