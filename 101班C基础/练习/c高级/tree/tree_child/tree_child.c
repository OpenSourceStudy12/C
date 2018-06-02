#include"tree_child.h"

/*建立孩子树*/
PCT tree_child_creat()
{
	PCT PTree = NULL;
	//CT tree[MAX_SUM];
	int i;
	PTree = (PCT)malloc(sizeof(CT)*MAX_SUM);
	//printf("size:%d\n",sizeof(tree));
	if(PTree == NULL)
	{
		printf("malloc error!\n");
		printf("%s\n",__FILE__);
		printf("%d\n",__LINE__);
		return NULL;
	}
	else
	{
		for(i=0;i<MAX_SUM;i++)
		{
			PTree[i].ch = 'A'+i;
			PTree[i].firstchild = NULL;
		}
	}

	insert_c_link(PTree,'A','B');
	insert_c_link(PTree,'A','C');
	insert_c_link(PTree,'A','D');
	insert_c_link(PTree,'B','E');
	insert_c_link(PTree,'B','F');
	insert_c_link(PTree,'C','G');
	insert_c_link(PTree,'D','H');
	insert_c_link(PTree,'D','I');
	insert_c_link(PTree,'D','J');


	return PTree;
}

/*插入孩子链表*/

void insert_c_link(PCT tree,char parent,char child)
{
	PCNode p = NULL,tail = NULL;
	int i;
	for(i=0;i<MAX_SUM;i++)
	{
		if(tree[i].ch == parent)
		{
			if(tree[i].firstchild == NULL)
			{
				if((p = (PCNode)malloc(sizeof(CNode))) != NULL)
				{
					p->ch = child;
					tree[i].firstchild = p;
					p->next = NULL;
				}
				else
				{
					printf("malloc error!\n");
					printf("%s\n",__FILE__);
					printf("%d\n",__LINE__);
				}
			}
			else
			{
				tail = tree[i].firstchild;
				while(tail->next != NULL)
				{
					tail = tail->next;
				}
				if((p = (PCNode)malloc(sizeof(CNode))) !=NULL)
				{
					p->ch = child;
					tail->next = p;
					p->next = NULL;
				}
				else
				{
					printf("malloc error!\n");
					printf("%s\n",__FILE__);
					printf("%d\n",__LINE__);
				}
			}
		}
	
	}

}

/*打印结点数据*/
void tree_print(PCT tree)
{
	int i;
	for(i=0;i<MAX_SUM;i++)
	{
		printf("%c\n",tree[i].ch);
	}

}

/*查找结点的孩子并打印*/
void tree_child_search(PCT tree,char ch)
{
	PCNode p = NULL;
	if(tree == NULL)
		printf("no tree..\n");
	else
	{
		int i;
		for(i=0;i<MAX_SUM;i++)
		{
			if(tree[i].ch == ch)
			{
				if(tree[i].firstchild == NULL)
					printf("no child..\n");
				else
				{
					printf("%c的孩子是:\n",ch);
					p = tree[i].firstchild;
					while(p != NULL)
					{
						printf("%c\n",p->ch);
						p = p->next;
					}
				}
				return;
			}

		}
		printf("no %c data\n",ch);
	}
}



























