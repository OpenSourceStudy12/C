#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
	char data;
	struct node *lchild;
	struct node *rchild;
}BTree;
BTree* CreateBinTree(BTree *T)
{
	char ch;
	if((ch=getchar())==' ')
	{
		T=NULL;
	}

	/*先序遍历递归创建二叉树法*/
	else
	{
		T=(BTree*)malloc(sizeof(BTree));
		T->data=ch;
		T->lchild=CreateBinTree(T->lchild);
		T->rchild=CreateBinTree(T->rchild);
	}
	return T;
}
BTree *search(BTree *T,char data)
{
	BTree *q=NULL;
	if(T!=NULL)
	{
		if(T->data==data)
		{
			return T;
		}
		else
		{
			q=search(T->lchild,data);
			if(q!=NULL)
			{
				return q;
			}
			else
			{
				q=search(T->rchild,data);
					return q;
			}
		}
	}
	else
	{
		return NULL;
	}
}

int main()
{
	BTree *Tree=NULL,*pnode=NULL;
	Tree=CreateBinTree(Tree);
	pnode=search(Tree,'M');
	if(pnode!=NULL)
	{
	printf("%c\n",pnode->data);
	}
	else
	{
		printf("not founded");
	}
}
