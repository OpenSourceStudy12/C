#ifndef _FUN2_H
#define _FUN2_H

#include<stdlib.h>

#define SIZEMAX 20

typedef struct stu
{
	int num;
	char name[SIZEMAX];
	float score;
	struct stu *pre,*next;
}STU,*PSTU;

struct ps
{
	PSTU head;
	PSTU tail;
};

void plinkcreat(PSTU *head,PSTU *tail);//尾插法创建双链表
void plink_display_head(PSTU head);//正序显示双链表
void plink_display_tail(PSTU tail);//逆序显示双链表
int plink_len(PSTU head);//求双链表长度 从0开始计数
//PSTU plink_search_index(PSTU head,PSTU tail,int index);//查找双链表 通过序号
PSTU plink_search_index(PSTU head,int index);//查找节点地址 通过序号
void p_node_del(PSTU *head,PSTU *tail,int index);//删除双链表节点 通过序号利用头指针或位尾针删除
PSTU dlinkCreat();//头插法创建双向链表
void dlink_display(PSTU head);//正反向显示双链表
PSTU plink_add(PSTU head,int index);//双链表中插入节点
PSTU node_add();//建立新节点 返回节点地址


#endif
