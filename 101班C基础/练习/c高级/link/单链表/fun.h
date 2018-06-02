#ifndef _fun_H
#define _fun_H

#include<stdlib.h>

#define SIZEMAX 20
typedef struct node
{
	int num;
	char name[SIZEMAX];
	float score;
	struct node *next;
}Node,*PNode;

PNode linkcreat_from_end();//头插法创建链表
PNode linkcreat_from_head();//尾插法创建链表
void linkprint(const PNode head);//打印链表
int linklen(PNode head);//求链表长度
PNode linksearch(PNode head,int t);//通过序号查找链表
PNode nodedel(PNode head,int n);//删除节点
static PNode nodecreat();//创建节点
PNode nodeadd(PNode head,int n);//增加节点
PNode link_sh_max(PNode head);//求链表中最大值
PNode link_sh_min(PNode head);//求链表中最小值
PNode linkdel(PNode head);//删除链表
static PNode pmaxsearch(PNode head);//寻找链表最大值 返回最大值节点地址
static PNode node_del(PNode head,PNode pmax);//将某节点从链表移除 返回链表头指针
static PNode node_add(PNode headnew,PNode pmax);//以头插法将节点插入到新链表中
PNode linksort(PNode head);//对链表进行升序排序
static int link_full();//判断链表是否已满



#endif
