/*
** Release Info:
** Author: LiQiang
** Date: 2011/8/1
** Version: V1.0
** History:
*/

/*include files*/
#include <stdio.h>
#include <stdlib.h>


/*MACRO*/


/*structure*/
typedef struct node
{
	int data;
	struct node *next;
}LNode, *LinkList;



/*structure*/
typedef struct dnode
{
	int data;
	struct dnode *prior, *next;
}DLNode, *DLinkList;


/*interface functions*/



