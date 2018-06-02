#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	char data;        //数据
	struct node *lchild;   //第一个孩子的指针
	struct node *brother;   //兄弟的指针
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
		//递归创建该节点的第一个子树
		CreateBtree(&((*t)->lchild));
		//递归创建该节点的兄弟
		CreateBtree(&((*t)->brother));
	}
}

int main()
{
	BTree *root=NULL;
	CreateBtree(&root);
	//root = CreateBtree2(root);
}
