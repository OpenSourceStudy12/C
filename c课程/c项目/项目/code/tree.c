/*
** Release Info:
** Author: LiQiang
** Date: 2011/8/1
** Version: V1.0
** History:
*/

/*include files*/
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"



/* function:
** para:
** return value:
*/
void creat_bin_tree(BTree **T)
{
	char ch;

	ch = getchar();

	if (ch == ' ')
	{
		*T = NULL;
	}
	else
	{
		*T = (BTree *)malloc(sizeof(BTree));
		(*T)->data = ch;
		creat_bin_tree(&(*T)->lchild);
		creat_bin_tree(&(*T)->rchild);
	}
}


/* function:
** para:
** return value:
*/
void inorder(BTree *root)
{
	if (root == NULL)
	{
		return;
	}
	else (root != NULL)
	{
		inorder(root->lchild);
		printf("%c\n", root->data);
		inorder(root->rchild);
	}
}


/* function:
** para:
** return value:
*/
void preorder(BTree *root)
{
	if (root != NULL)
	{
		printf("%c\n", root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}


/* function:
** para:
** return value:
*/
void postorder(BTree *root)
{
	if (root != NULL)
	{
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%c\n", root->data);
	}
}

int main()
{
	BTree *Tree = NULL;

	/*creat*/
	creat_bin_tree(&Tree);
	printf("\n============Inorder============\n");
	inorder(Tree);
	printf("\n============Preorder============\n");
	preorder(Tree);
	printf("\n============Postorder============\n");
	postorder(Tree);

	return 0;
}

