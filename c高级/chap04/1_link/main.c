#include <stdio.h>
#include "link.h"


int main()
{
	int x,cnt,index;
	PNode head=NULL,FNode;
	head = linkCreat2();
	linkPrint(head);
	cnt = linkLength(head);
	printf("链表的长度是:%d\n",cnt);
#if 0	// 查找结点
	printf("请输入你想要查找的节点序号：\n");
	scanf("%d",&index);
	FNode = linkSearchByIndex(head,index-1);
	if(FNode == NULL)
		printf("can not find node..\n");
	else
		printf("result:%d\n",FNode->data);	
#endif
#if 0	//删除结点 
	printf("请输入想要删除的结点序号:\n");
	scanf("%d",&index);
	head = nodeDelete(head,index-1);
	linkPrint(head);
#endif
#if 0	//添加一个结点 
	printf("请输入想要插入的结点位置：\n");
	scanf("%d",&index);
	head = nodeInsertByIndex(head,index-1);
	linkPrint(head);
#endif
#if 0 //查找最大值.最小值 
	FNode = searchMaxByData(head);
	printf("the max is :%d\n",FNode->data);
	FNode = searchMinByData(head);
	printf("the min is :%d\n",FNode->data);
#endif
#if 0//删除链表
	head = linkDelete(head);
	linkPrint(head);
#endif 
#if 0//排序
	head = linkSort(head);
	linkPrint(head);
#endif
#if 1 //通过data找到指定成员并修改该成员的name
	printf("请输入要查找的成员的data:\n");
	scanf("%d",&x);
	nodeModify(head,x);
	linkPrint(head);
#endif
	return 0;
}
