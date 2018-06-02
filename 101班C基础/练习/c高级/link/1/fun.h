#ifndef _FUN_H
#define _FUN_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N_SIZE  20 

enum num
{
	TRUE,
	FLASE
};

typedef struct film
{
	char name[N_SIZE];
	int rate;
	struct film *next;
}F_node,*List;

void list_init(List *L);
int list_empty(List L);
static int list_full();
int list_add(List *L,F_node node);
void list_display(const List L);
void list_del(List L);

#endif
