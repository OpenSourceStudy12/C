/***************************************************************
*file name:
*function:双链表的操作(建立，显示)
*author:L-R-H
****************************************************************/
#include<stdio.h>
#include"fun2.h"

/*尾插法创建双链表*/
void plinkcreat(PSTU *head,PSTU *tail)
{
	PSTU p,s;
	*head = NULL;
	int num,flag = 0;
	printf("请输入学号:\n");
	scanf("%d",&num);
	while(num)
	{
		if((s = (PSTU)malloc(sizeof(STU))) == NULL)
		{
			//return NULL;
			printf("内存已满:\n");
			flag = 1;
			break;
		}
		else
		{
			if(*head == NULL)
			{
				*head = s;
				s->pre = NULL;
			}
			else
			{	
				p->next = s;
				s->pre = p;
			}
			p = s;
			p->next = NULL;

			p->num = num;
			printf("请输入姓名学号:\n");
			scanf("%s%f",p->name,&p->score);
			printf("请输入学号:\n");
			scanf("%d",&num);
		}
	}
	if(flag)
	{
		*head = NULL;
		*tail = NULL;
	}
	else
		*tail = p;
//	return head;
}

/*头插法创建双向链表*/  //by th
PSTU dlinkCreat()
{
	PSTU head = NULL,p = NULL;
	int x;
	printf("请输入学号:\n");
	scanf("%d",&x);
	while(x)
	{
		if((p = (PSTU)malloc(sizeof(STU)))!=NULL)
		{
			if(head == NULL)
			{
				p->next = NULL;
			}
			else
			{
				head->pre = p;
				p->next = head;
			}
			p->pre = NULL;
			head = p;
			p->num = x;
			printf("请输入姓名和学号\n");
			scanf("%s%f",p->name,&p->score);
			printf("请输入学号:\n");
			scanf("%d",&x);
		}
		else
		{	
			printf("malloc error!");
			return NULL;
		}
	}
	return head;
}


/*显示双链表正序*/
void plink_display_head(PSTU head)
{
	PSTU p = head;
	printf("学号\t姓名\t\t成绩:\n");
	while(p != NULL)
	{
		printf("%d\t%s\t\t%.2f\n",p->num,p->name,p->score);
		p = p->next;
	}
}

/*显示双链表逆序*/
void plink_display_tail(PSTU tail)
{
	PSTU p = tail;
	printf("学号\t姓名\t\t成绩:\n");
	while(p != NULL)
	{
		printf("%d\t%s\t\t%.2f\n",p->num,p->name,p->score);
		p = p->pre;
	}
}

/*求双链表长度*/ //从0开始计数
int plink_len(PSTU head)
{
	int cnt=0;
	PSTU p = head;
	while(p->next !=NULL)
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}

/*正反向显示双链表*/  // by th
void dlink_display(PSTU head)
{
	PSTU p = head,tail = NULL;
	printf("学号\t姓名\t\t成绩\n");
	if(head == NULL)
	{	
		printf("dlink is null\n");
		return;
	}
	while(p != NULL)
	{
		printf("%d\t%s\t\t%.2f\n",p->num,p->name,p->score);
		tail = p;
		p = p->next;
	}
	while(tail != NULL)
	{
		printf("%d\t%s\t\t%.2f\n",tail->num,tail->name,tail->score);
		tail = tail->pre;
	}

}

/*查找双链表*/ //通过序号利用头指针或尾指针查找
/*PSTU plink_search_index(PSTU head,PSTU tail,int index)
{
	int cnt = 0,len = plink_len(head);
	PSTU p = NULL;
	if(index >= 0 && index <= len/2)
	{
		p = head;
		//printf("学号\t姓名\t\t成绩:\n");
		while(p->next != NULL)
		{
			if(++cnt == index)
			{
				//printf("%d\t%s\t\t%.2f\n",p->next->num,p->next->name,p->next->score);
				return p->next;
			}
			p = p->next;
		}
	}
	else if(index > len/2 && index <= len)
	{
		p = tail;
		//printf("学号\t姓名\t\t成绩\n");
		while(p->pre != NULL)
		{
			if(++cnt == len-index)
			{
				//printf("%d\t%s\t\t%.2f\n",p->pre->num,p->pre->name,p->pre->score);
				return p->pre;
			}
			p = p->pre;
		}
	}
	else
	{
		//printf("没有该序号的成员\n");
		return NULL;
	}
}
*/

/*查找节点地址*/
PSTU plink_search_index(PSTU head,int index)
{
	int cnt = 0,len = plink_len(head);
	PSTU p = head;
	while(p->next != NULL)
	{
		if(++cnt == index)
		{
			return p->next;
		}
		p = p->next;
	}	
}



/*删除双链表节点*/  //通过序号利用头指针或位尾针删除
void p_node_del(PSTU *head,PSTU *tail,int index)
{
	int cnt = 0,len = plink_len(*head);
	PSTU p = NULL,q = NULL;
	if(index <= 0)
	{
		p = (*head);
		*head = (*head)->next;
		(*head)->pre = NULL;
		free(p);
		p = NULL;
	}
	else if(index >= len)
	{
		p = (*tail);
		(*tail) = (*tail)->pre;
		(*tail)->next = NULL;
		free(p);
		p = NULL;
	}
	else
	{
		p = (*head);
		while(p->next != NULL)
		{
			if(++cnt == index)
			{
				p->next = p->next->next;
				p->next->next->pre = p;
				free(p->next);
				break;
			}
			p = p->next;
		}
	}
}

/*建立新节点 返回节点地址*/
PSTU node_add()
{
	PSTU head = NULL;
	if((head = (PSTU)malloc(sizeof(STU))) != NULL)
	{
		printf("请输入学号姓名和成绩:\n");
		scanf("%d%s%f",&head->num,head->name,&head->score);
		head->next = NULL;
		head->pre = NULL;
	}
	else
	{	
		printf("新节点创建失败,malloc error!:\n");	
	}
	return head;
}

/*双链表中插入节点*/
PSTU plink_add(PSTU head,int index)
{
	PSTU p,q;
	int len = plink_len(head);
	q = node_add();
	if(q != NULL)
	{	
		if(head == NULL)
		{
			q->next = head;
			q->pre = NULL;
			head = q;
		}
		else
		{
			if(index == 0)
			{
				q->next = head;
				q->pre = NULL;
				head->pre = q;
				head = q;
			}
			else  
			{	
				if(index > len)
					p = plink_search_index(head,len);
				else	
					p = plink_search_index(head,index-1);
				q->next = p->next;
				q->pre = p;	
				p->next = q;
			}
		}
	}
	else
	{
		printf("malloc error!\n");
	
	}
	return head;
}

















