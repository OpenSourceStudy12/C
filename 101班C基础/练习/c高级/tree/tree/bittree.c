#include<stdio.h>
#include<stdlib.h>
#include"bittree.h"

/*void bittree_creat(PTreenode *root)
{
	char ch = getchar();
	if(ch == ' ')
		*root = NULL;
	else
	{
		*root = (PTreenode)malloc(sizeof(Treenode));
		(*root)->ch = ch;
		bittree_creat(&(*t)->lchild);//创建左孩子结点
		bittree_creat(&(*t)->rchild);//创建右孩子结点
	}
}
*/


PTreenode bittree_creat(PTreenode p)
{
	char ch = getchar();
	//PTreenode p = NULL;
	if(ch == ' ')
		return NULL;
	else
	{
		p = (PTreenode)malloc(sizeof(Treenode));
		p->ch = ch;
		p->lchild = bittree_creat(p->lchild);//创建左孩子结点
		p->rchild = bittree_creat(p->rchild);//创建右孩子结点
	}
	return p;

}

/*先序打印二插树 先中再左后右*/
void bittree_print_pre(PTreenode root)
{
	if(root != NULL)
	{
		printf("%c",root->ch);
		bittree_print_pre(root->lchild);
		bittree_print_pre(root->rchild);
	}
}


/*中序打印二插树 先左再中后右*/
void bittree_print_mid(PTreenode root)
{
	if(root != NULL)
	{
		bittree_print_mid(root->lchild);
		printf("%c",root->ch);
		bittree_print_mid(root->rchild);
	}
}



/*后序打印二插树 先左再右后中*/
void bittree_print_tail(PTreenode root)
{
	if(root != NULL)
	{
		bittree_print_tail(root->lchild);
		bittree_print_tail(root->rchild);
		printf("%c",root->ch);
	}
}

/*查找*/


















