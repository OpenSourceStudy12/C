#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxTreeSize 100  


typedef char DataType;

typedef struct
{ 
	char data;    //结点数据
	int parent;  //双亲指针，指示结点的双亲在数组中的位置
} PTreeNode;
typedef struct
{
	PTreeNode nodes[MaxTreeSize];
	int n;               //结点总数
}PTree;

int insert_parent(PTree *T, PTreeNode *data, int parent)
{
	if(data >(PTreeNode *)(T+1))
	{
		return -1;
	}
	data->parent = parent;
	return 0;
}
PTree * create()
{
	int i,tree_num,parent_loc;
	PTreeNode *p_tree;
	PTree *tree=malloc(sizeof(PTree));
	memset(tree,0,sizeof(PTree));
	p_tree=tree->nodes;
	printf("请输入节点个数\n");
	scanf("%d",&tree_num);
	tree->n=tree_num;
	for(i=0;i<tree_num;i++)
	{
		p_tree[i].data = 'A'+i;
	}
	for(i=0;i<tree_num;i++)
	{
		printf("请输入%c的双亲位置:\n",p_tree[i].data);
		scanf("%d",&parent_loc);
		insert_parent(tree,&p_tree[i],parent_loc);
	}
	return tree;
}
void tree_print(PTree *t)
{
	int i=0;
	PTreeNode *p = t->nodes;
	printf("数据，双亲位置\n");
	for(i=0;i<t->n;i++)
	{
		printf("%c\t %d\n",p->data,p->parent);
		p++;
	}
}
PTreeNode *find_parent(PTree *t,char data)
{
	int i=0;
	PTreeNode *pNode = t->nodes;
	int flag = 0;
	int parent_loc;
	for(i=0;i<t->n;i++)
	{
		if(pNode->data==data)
			{
				flag = 1;
				parent_loc=pNode->parent;
			}
			pNode++;
	}
	if((flag == 1)&&(parent_loc!=-1))
	{
		return t->nodes+parent_loc;
	}
	else
	{
		return NULL;
	}
}
int main()
{
	char data;
	PTree * tree=create();
	PTreeNode *parent=NULL;
	tree_print(tree);
	printf("清输入要找谁的双亲\n");
	while((data=getchar())=='\n');
	parent=find_parent(tree,data);

	if(parent != NULL)
	{
		printf("%c双亲是%c\n",data,parent->data);
	}
	else
	{
		printf("not founded\n");
	}
}
