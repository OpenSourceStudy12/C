#ifndef _TREE_CHILD_H
#define _TREE_CHILD_H

#include<stdlib.h>
#include<stdio.h>
#define MAX_SUM 10

typedef struct cnode
{
	char ch;
	struct cnode *next;
}CNode,*PCNode;

typedef struct ct
{
	char ch;
	PCNode firstchild;
}CT,*PCT;


PCT tree_child_creat();
void insert_c_link(PCT tree,char parent,char child);
void tree_child_search(PCT tree,char ch);

void tree_print(PCT tree);
#endif
