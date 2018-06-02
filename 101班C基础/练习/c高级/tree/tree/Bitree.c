#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	char data;        //数据
	struct node *lchild;   //左孩子的指针
	struct node *rchild;   //右孩子的指针
}BTree;




void CreateBtree(BTree **t)
{
	char ch = getchar();
	if(ch == ' ')
	{
		*t = NULL;
	}
	else
	{
		*t=(BTree *)malloc(sizeof(BTree));	
		(*t)->data = ch;
		//递归创建该节点的左子树
		CreateBtree(&((*t)->lchild));
		//递归创建该节点的右子树
		CreateBtree(&((*t)->rchild));
	}
}
BTree * CreateBtree2(BTree *t)
{
	char ch = getchar();
	if(ch == ' ')
	{
		t = NULL;
		return t;
	}
	else
	{
		t=(BTree *)malloc(sizeof(BTree));	
		t->data = ch;
		//递归创建该节点的左子树
		t->lchild=CreateBtree2(t->lchild);
		//递归创建该节点的右子树
		t->rchild=CreateBtree2(t->rchild);
		return t;
	}
}
int main()
{
	BTree *root=NULL;
	//CreateBtree(&root);
	root = CreateBtree2(root);
}
