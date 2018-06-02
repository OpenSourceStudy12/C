#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TREE_NODE 7
typedef struct CTNode
{ 
	char child;
	struct CTNode *next;
}*ChildPtr; 

typedef struct
{ 
	char data;
	ChildPtr firstchild;
}CTBox;
void tree_nodeInsert(CTBox *tree,char parent,char data)
{
	int i =0;
	ChildPtr s = NULL;
	if(tree == NULL)
	{
		printf("empty tree,error !\n");
		return;
	}
	for(i=0;i<TREE_NODE;i++)
	{
		if(tree->data == parent)
		{
			s=(ChildPtr)malloc(sizeof(struct CTNode));
			s->child = data;
			if(tree->firstchild == NULL)
			{
				s->next = NULL;
				tree->firstchild = s;
			}
			else
			{
				ChildPtr tail,p = tree->firstchild;
				while(p)
				{
					tail=p;
					p=p->next;
				}
				s->next=NULL;
				tail->next=s;
				
			}
		}
		tree++;
		
	}
}
int get_chlid(CTBox *tree,char parent)
{
	int i=0;
	for(i=0;i<TREE_NODE;i++)
	{
		if(tree->data == parent)
		{
			if(tree->firstchild !=NULL)
			{
				ChildPtr p=tree->firstchild;
				while(p)
				{
					printf("%c\n",p->child);
					p=p->next;
				}
			}
			else
			{
				printf("no child\n");
			}
		return 0;
		}
		tree++;
	}
	printf("not found\n");
	return -1;
	
}
CTBox * tree_create()
{
	int i;
	CTBox *tree = (CTBox *)malloc(sizeof(CTBox)*TREE_NODE);
	memset(tree, 0 ,sizeof(CTBox)*TREE_NODE);
	for(i=0;i<TREE_NODE;i++)
	{
		tree[i].data = 'A'+i;
		tree[i].firstchild=NULL;
	}
	tree_nodeInsert(tree,'A','B');
	tree_nodeInsert(tree,'A','C');
	tree_nodeInsert(tree,'B','D');
	tree_nodeInsert(tree,'B','E');
	tree_nodeInsert(tree,'B','F');
	tree_nodeInsert(tree,'E','G');
	return tree;
}
int main()
{

	CTBox *tree = tree_create();
	printf("print the child of A\n");
	get_chlid(tree,'A');
	printf("print the child of B\n");
	get_chlid(tree,'B');
	printf("print the child of E\n");
	get_chlid(tree,'E');
	printf("print the child of F\n");
	get_chlid(tree,'F');
}
