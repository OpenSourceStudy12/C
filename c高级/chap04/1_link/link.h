#ifndef _LINK_H
#define _LINK_H
#include <stdlib.h>

typedef struct node
{
	int data;
	char name[20];
	char sex;
	struct node *next;
}Node, *PNode;
PNode linkCreat();//以头插法创建一个链表
void linkPrint(PNode head);//打印链表的数据成员
int linkLength(PNode head);//统计一个链表的长度
PNode linkSearchByIndex(PNode head,int i);//查找链表的第i个节点，从０开始计数
PNode nodeDelete(PNode head,int i);//删除链表的第i个结点i,从0开始计数
PNode linkCreat2();//以尾插法创建一个链表
PNode nodeCreat();//创建一个新的结点
PNode nodeInsertByIndex(PNode head,int i);//在链表的第i个位置插入一个新结点i,从0开始计数
PNode searchMaxByData(PNode head);//查找链表里面data值最大的结点
PNode searchMinByData(PNode head);//查找链表里面data值最小的结点
PNode linkDelete(PNode head);//删除链表
PNode removeFromOld(PNode head,PNode pDes);
PNode addToNew(PNode head,PNode pDes);
PNode linkSort(PNode head);
PNode nodeSearchByData(PNode head,int x);
void nodeModify(PNode head,int x);

#endif
