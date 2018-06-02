#include<stdio.h>
#include"tree_parents.h"

int main()
{
	char sh;
	PTreeNode p = NULL;
	PTree H = treecreat();
	treeprint(H);
	getchar();
	printf("请输入想要查找双亲的结点数据:\n");
	scanf("%c",&sh);
	p = treeparents_find(H,sh);
	if(p == NULL)
		printf("未找到该结点的双亲:\n");
	else
	{
		printf("该结点的双亲结点数据为:%c\n",p->data);
		
	}
	return 0;
}
