#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//用链表来实现队列
typedef struct node
{
	int data;
	struct node *next;
}linklist;

typedef struct qq
{
	linklist *head;  //队列链表的头指针
	int len;//队列中元素个数
}QueueList;

//队列初始化
QueueList *queue_init()
{
	QueueList *myQueue = (QueueList*)malloc(sizeof(QueueList));
	if(myQueue == NULL)
	{
		printf("queue初始化失败\n");
		return NULL;
	}
	myQueue->head =NULL; //初始化空队列
	myQueue->len = 0;
	return myQueue;
}
//入队 成功返回０　失败返回－１
int InQueue(QueueList *queue,int data)
{
	if(queue == NULL)
	{
		printf("queue未初始化\n");
		return -1;
	}
	linklist *s = (linklist *)malloc(sizeof(linklist));
	assert(s!=NULL);
	s->data = data;
	if(queue->head == NULL)//入队第一个节点
	{
		s->next = NULL;
		queue->head = s;
	}
	else //other nodes
	{
		s->next = NULL;
		//找尾节点
		linklist *tail = NULL;
		linklist *p = queue->head;
		while(p!=NULL)
		{
			tail = p;			
			p = p->next;
		}
		tail->next = s;
	}
	queue->len++;
}

//出队
linklist *deQueue(QueueList *queue)
{
	if(queue == NULL)
	{
		printf("queue未初始化\n");
		return NULL;
	}
	if(queue->head == NULL)
	{
		printf("空队列，出队失败\n");
		return NULL;
	}
	else
	{
		linklist *tmp = queue->head;
		queue->head = queue->head->next;
		queue->len--;
		return tmp;		
	}

}

void destoryQueue(QueueList *queue)
{
	if(queue->head !=NULL)
	{
		linklist *p = queue->head,*q=NULL;
		while(p!=NULL)
		{
			q = p;
			p=p->next;
			free(q);
		}
	}	
	free(queue);
}
int main()
{
	QueueList *myQueue = queue_init();
	InQueue(myQueue, 5);
	linklist *q = deQueue(myQueue);
	free(q);
	InQueue(myQueue, 6);
	InQueue(myQueue, 7);
	q = deQueue(myQueue);
	free(q);
	InQueue(myQueue, 8);
	InQueue(myQueue, 9);
	int i;
	int len = myQueue->len;
	for(i = 0;i<len;i++)
	{
		linklist *s = deQueue(myQueue);
		
		if(s!=NULL)
		{
			printf("出队成功，值:%d\n",s->data);
		}
		else
		{
			printf("出队失败\n");
		}
		free(s);
	}
}
