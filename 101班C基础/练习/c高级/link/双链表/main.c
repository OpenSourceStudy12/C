#include<stdio.h>
#include"fun2.h"

int main()
{
	int x;
	struct ps as;
#if 0   //创建双链表
	plinkcreat(&as.head,&as.tail);
#endif
#if 0   //显示双链表
	printf("正序:\n");
	plink_display_head(as.head);
	printf("逆序:\n");
	plink_display_tail(as.tail);
#endif
#if 0   //查找双链表
	printf("请输入想要查找的成员序号:\n");
	scanf("%d",&x);
	plink_search_index(as.head,as.tail,x-1);
	//plink_display_head(as.head);
#endif
#if 0   //删除双链表中结点
	printf("请输入想要删除的节点:\n");
	scanf("%d",&x);
	p_node_del(&as.head,&as.tail,x-1);
	plink_display_head(as.head);
#endif
#if 0   //建立并显示双向链表 by th
	as.head = dlinkCreat();//头插法创建双向链表 
	dlink_display(as.head);//正反向显示双链表
#endif
#if 1   //双向链表中增加节点
	as.head = dlinkCreat();//头插法创建双向链表 
	dlink_display(as.head);//正反向显示双链表
	printf("请输入要添加节点的位置:\n");
	scanf("%d",&x);
        as.head = plink_add(as.head,x-1);//添加节点
	dlink_display(as.head);//正反向显示双链表
#endif
	return 0;
}
