#ifndef _TREE_PARENTS_H
#define _TREE_PARENTS_H

#include<stdlib.h>
#include<string.h>

#define MAX_NODE 100

typedef struct treenode//每个节点数据
{
	char data;   //结点数据
	int parents; //双亲位置
}TreeNode,*PTreeNode;

typedef struct tree  //树链表
{
	TreeNode ptree[MAX_NODE];
	int n; //实际结点大小
}Tree,*PTree;

PTree treecreat();//建立双亲存储的树结构
void treeprint(PTree H);//打印双亲树的结构
PTreeNode treeparents_find(PTree H,char sh);//查找指定数据结点的双亲,返回双亲结点的地址






#endif
