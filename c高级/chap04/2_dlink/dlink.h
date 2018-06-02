#ifndef _DLINK_H
#define _DLINK_H
typedef struct node
{
	int data;
	struct node *pri;
	struct node *next;
}Node,*PNode;
PNode dLinkCreat();//用头插法创建一个双向链表
void dLinkPrint(PNode head);//先正向，后反向打印一个双向链表
int dLinkLength(PNode head);


#endif
