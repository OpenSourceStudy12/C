#include <stdio.h>
#include <stdlib.h>

//用数组实现队列
#define QUEUE_LEN 10
typedef struct Queue
{
	int queue_arr[QUEUE_LEN];
	int n;//当前队尾位置
}myQueue;

//队列初始化
myQueue *queue_init()
{
	myQueue *queue = (myQueue*)malloc(sizeof(myQueue));
	if(queue == NULL)
	{
		printf("queue初始化失败\n");
		return NULL;
	}
	int *q = queue->queue_arr;
	int i;
	//队列的没一个元素都赋值为　０
	for(i=0;i<QUEUE_LEN;i++)
	{
		q[i]=0;
	}
	queue->n = 0;
	return queue;
}
//入队 成功返回０　失败返回－１
int InQueue(myQueue *queue, int data)
{
	if(queue == NULL)
	{
		printf("对类没有初始化\n");
		return -1;
	}
	else if(queue->n == QUEUE_LEN) //对列已满
	{
		printf("队列已满，入队失败\n");
		return -1;
	}
	else
	{
		int *q=queue->queue_arr;
		q[queue->n]=data;
		(queue->n)++;
		return 0;

	}
}
//出队 返回出队列数据
int dequeue(myQueue *queue)
{
	if(queue == NULL)
	{
		printf("队列没初始化，出队失败\n");
		return 0x5A5A;
	}
	else if(queue->n == 0)//空对列
	{
		printf("空队列，出队失败\n");
		return 0x5A5A5A5A;
	}
	else
	{
		int tmp = queue->queue_arr[0];
		int i;
		int *a = queue->queue_arr;
		int n = queue->n;
		for(i=0;i<n-1;i++)
		{
			a[i]=a[i+1];
		}
		(queue->n)--;
		return tmp;
	
	}
}
//销毁队列
void queue_destory(myQueue *queue)
{

	free(queue);
}
int main()
{
	myQueue *myqueue = queue_init();
	InQueue(myqueue,1);

	InQueue(myqueue,2);
	dequeue(myqueue);
	dequeue(myqueue);
	InQueue(myqueue,3);
	InQueue(myqueue,4);
	InQueue(myqueue,5);
	InQueue(myqueue,6);
	int i = 0;
	for(;i<10;i++)
	{
		int tmp = dequeue(myqueue);
		printf("tmp = %d\n",tmp);
	}
}
