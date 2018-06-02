#include<stdio.h>
#include"tree_parents.h"


/*建立双亲存储的树结构*/
PTree treecreat()
{
	PTree H = NULL;
	if((H = ((PTree)malloc(sizeof(Tree)))) != NULL)
	{
		int i;
		PTreeNode p = H->ptree;
		printf("请输入要存储的结点数:\n");
		scanf("%d",&H->n);
		//getchar();
		for(i=0;i< H->n;i++,p++)
		{
		//	printf("请输入第%d个结点数据:\n",i);
		//	scanf("%d",&p->data);
			p->data = 'A'+i;
			printf("请输入第%d个结点双亲位置:\n",i);
			scanf("%d",&p->parents);
			//getchar();
		}	
	}
	else
		printf("malloc error!\n");	
	return H;
}


/*打印双亲树的结构*/
void treeprint(PTree H)
{
	int i;
	PTreeNode p = H->ptree;
	if(H != NULL)
	{
		printf("序号\t数据\t双亲结点位置:\n");
		for(i=0;i<H->n;i++)
		{
			printf("%d\t%c\t%d\n",i,p[i].data,p[i].parents);
		}
	}
	else
		printf("空树\n");
}

/*查找指定数据结点的双亲  返回双亲结点的地址*/
PTreeNode treeparents_find(PTree H,char sh)
{
	PTreeNode p = H->ptree;
	int i,parents_loc = -1;
/*	for(i=0;i<H->n;i++)
	{
		if(p[i].data == sh)
		{
			parents_loc = p[i].parents;
			//return p+parents_loc;
			break;
		}
	}
	if(parents_loc != -1)
		return p+parents_loc;
	else
		return NULL;
*/
	for(i=1;i<H->n;i++)
	{
		if(p[i].data == sh)
		{
			parents_loc = p[i].parents;
			return p+parents_loc;
			//break;
		}
	}
	//if(parents_loc != -1)
	//	return p+parents_loc;
//	else
		return NULL;
}


