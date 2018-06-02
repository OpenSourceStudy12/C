#include <stdio.h>
#include "parentTree.h"
#include <stdlib.h>


PTree treeCreat()
{
	int i;
	PTree tree = (PTree)malloc(sizeof(Tree));
	printf("请输入结点的个数");
	scanf("%d",&tree->n);
	getchar();
	for(i=0;i<tree->n;i++)
	{
		tree->treeNode[i].data = 'A'+i;
	}
	for(i=0;i<tree->n;i++)
	{
		printf("请输入%c的双亲结点的位置:",tree->treeNode[i].data);
		scanf("%d",&tree->treeNode[i].parent);
		getchar();
	}
	return tree;
}

void treePrint(PTree tree)
{
	int i;
	PTreeNode p = tree->treeNode;
	printf("位置\t数据\t双亲位置\n");
	for(i=0;i<tree->n;i++)
	{
		printf("%d\t%c\t%d\n",i,p[i].data,p[i].parent);
	}
}

