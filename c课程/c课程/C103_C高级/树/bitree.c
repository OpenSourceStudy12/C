#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
	char data;
	struct tree *lchild,*rchild;
}BTree;
BTree *createBinTree(BTree *T)
{
	char ch;
	if((ch=getchar())==' ')
	{
		T=NULL;
	}
	else
	{
		T=(BTree *)malloc(sizeof(BTree));
		T->data = ch;
		T->lchild=createBinTree(T->lchild);
		T->rchild=createBinTree(T->rchild);
	}
	return T;
}
void preOrderTree(BTree *T)
{
	if(T!=NULL)
	{
		printf("%c ",T->data);
		preOrderTree(T->lchild);
		preOrderTree(T->rchild);
	}
}
/*
*函数名：getLchild
*功能：获得一个节点的左孩子
*入参：T:要找树的根节点指针，data:要查找的关键字
*返回值：找到返回左孩子的地址，未找到返回NULL;
*其他说明：无
*/
BTree *getLchild(BTree *T, char data)//获得一个节点的左孩子
{
	BTree *p_lchild=NULL,*p_rchild=NULL;
  if(T!=NULL)如果非空则查找左孩子
  {
		if(T->data==data)//找到待查找节点，返回其左孩子
		{
			return T->lchild;
		}
		else//找到待查找节点，继续在左子树，右子树种找
		{
			p_lchild=getLchild(T->lchild,data);
			if(p_lchild!=NULL)//左子树种找到则返回
				return p_lchild;
			else //左子树没有找到找右子树
			{
				p_rchild=getLchild(T->rchild,data);
				if(p_rchild!=NULL)//右子树找到
				return p_rchild;
				else //右子树未找到
				return NULL;
			}
			
		}
 	}
 	else //已经到空节点，没有找到待查找节点
 	{
		return NULL;
 	}
}
BTree *getRchild(BTree *T, char data)
{
	BTree *p_lchild=NULL,*p_rchild=NULL;
    if(T!=NULL)
     {
	if(T->data==data)
	{
		return T->rchild;
	}
	else
	{
		p_lchild=getRchild(T->lchild,data);
		if(p_lchild!=NULL)
			return p_lchild;
		else
		{
			p_rchild=getRchild(T->rchild,data);
			if(p_rchild!=NULL)
				return p_rchild;
			else 
				return NULL;
		}
			
	}
    }
    else
    {
	return NULL;
    }
}
void inOrderTree(BTree *T)
{
	if(T!=NULL)
	{
		inOrderTree(T->lchild);
		printf("%c ",T->data);
		inOrderTree(T->rchild);
	}
}
int main()
{
	BTree *root = NULL,*p_lchild=NULL;
	root = createBinTree(root);
	inOrderTree(root);
	p_lchild=getLchild(root,'C');
	if(p_lchild != NULL)
	{
		printf("左孩子为 %c\n",p_lchild->data);	
	}
	else
	{
		printf("无左孩子\n");
	}
	p_lchild=getRchild(root,'C');
	if(p_lchild != NULL)
	{
		printf("右孩子为 %c\n",p_lchild->data);	
	}
	else
	{
		printf("无右孩子\n");
	}
}
