#include<stdio.h>
#include"fun2.h"

int main()
{
	int x;
	struct ps as;//
	//plinkcreat(&as.head,&as.tail);//创建双链表
//	PNode head,L,max,min;
//	PNODE M;//循环链表头指针
//	int len,a;
//	M = linkcreat();//创建循环链表
//	head = linkcreat_from_head();
//	linkprint(head);
//	len = linklen(head);
//	printf("链表长度是:%d\n",len);

#if 0   //查找节点
	printf("请输入要查找的链表序号:\n");
	scanf("%d",&a);
	L = linksearch(head,a-1);
	printf("第%d个链表元素数据为:%d\n",a,L->num);
#endif
#if 0   //删除节点
	printf("请输入要删除的节点序号:\n");
	scanf("%d",&a);
	head = linkdel(head,a-1);
	linkprint(head);
#endif
#if 0   //插入节点
	printf("请输入要插入的的节点位置:\n");
	scanf("%d",&a);
	head = nodeadd(head,a-1);
	linkprint(head);
#endif	
#if 0   //求链表最值
	max = link_sh_max(head);
	min = link_sh_min(head);
	printf("max = %d\nmin = %d\n",max->num,min->num);
#endif
#if 0   //循环链表
	M = linkcreat();
	linkprint(M);
	len = linklen(M);
	printf("链表长度是:%d\n",len);
#endif
#if 0   //删除链表
	head = linkdel(head);
	linkprint(head);
#endif
#if 0   //显示升序排序后的链表
	printf("升序排序后:\n");
	head = linksort(head);
	linkprint(head);
#endif
#if 0   //删除链表
	head = linkdel(head);
	linkprint(head);
#endif
#if 0    //循环链表显示
	link_display(M);
#endif
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
