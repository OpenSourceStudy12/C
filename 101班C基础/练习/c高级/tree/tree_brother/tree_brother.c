/*****************************************************************
*file name:
*function:孩子_兄弟存储型树的操作(创建，查找)
*author:
*****************************************************************/

#include<stdio.h>
#include"tree_brother.h"


PTN tree_b_c_creat(int n)
{
	PTN  head = NULL,p,q;
/*	printf("请输入孩子个数:\n");
	scanf("%d",&n);
*/
	if(!n)
		return NULL;
	else  
	{	
		head = (PTN)malloc(sizeof(TN));
		printf("请输入结点数据:\n");
		scanf("%c",&head->ch);
		head->child = NULL;
		head->brother = NULL;
		if(n == 1 && a != 1)
			return head;
		else
		{
			int i;
			p = head;
			for(i=0;i<n-1;i++)
			{
				q = (PTN)malloc(sizeof(TN));
				printf("请输入结点数据:\n");
				scanf("%c",&q->ch);
				p->brother = q;
				q->brother = NULL;
				p = q;
			}
			p = head;
			while(p != NULL)
			{
				printf("请输入%c孩子个数:\n",p->ch);
				scanf("%d",&n);
				p->child = tree_b_c_creat(n);
				p = p->brother;
			}
		}
	}
}

PTN tree_b_c_root()
{
	head = (PTN)malloc(sizeof(TN));
	printf("请输入结点数据:\n");
	scanf("%c",&head->ch);
	head->child = NULL;
	head->brother = NULL;
	return head;
}
