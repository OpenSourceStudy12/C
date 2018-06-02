#ifndef _BITTREE_H
#define _BITTREE_H

typedef struct treenode
{
	char ch;
	struct treenode *lchild;
	struct treenode *rchild;
}Treenode,*PTreenode;

//void bittree_creat(PTreenode *root);//创建二插树 通过二级指针
PTreenode bittree_creat(PTreenode p);//创建二插树 通过返回值

void bittree_print_pre(PTreenode root);//先序打印二插树 先中再左后右

void bittree_print_mid(PTreenode root);//先序打印二插树 先中再左后右

void bittree_print_tail(PTreenode root);//中序打印二插树 先左再中后右

	
#endif
