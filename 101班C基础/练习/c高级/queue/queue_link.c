#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
typedef struct node
{
    int data;
    struct node *next;
}Lnode,*linklist;

typedef struct queue
{
    linklist head;   //队列的头指针
    int length;  //队列的长队
}Queue;
//队列的初始化
Queue *Queue_init()
{
    Queue *myQueue = malloc(sizeof(Queue));
    myQueue->head = NULL;
    myQueue->length = 0;
    return myQueue;
}
//队列的入队
int InQueue(Queue  *myQueue, int data)
{
    //入参检查
    if(myQueue ==NULL)
    {
        printf("队列没有初始化\n");
        return -1;
    }
    //申请空间
    linklist s = malloc(sizeof(Lnode));
    assert(s!=NULL);
    s->data = data;
    if(myQueue->head == NULL)  //空队列
    {
        s->next = NULL;
        myQueue->head = s;
    }
    else  //非空队列入队
    {
        //找队列尾
        linklist p = myQueue->head;
        linklist tail;
        while(p!=NULL)
        {
           tail=p;
           p=p->next;
        }
        tail->next = s;
        s->next = NULL;
    }
    
    myQueue->length++;
    return 0;
}
//出队
linklist DeQueue(Queue *myQueue)
{
    if(myQueue == NULL)
    {
        printf("队列没有初始化\n");
        return NULL;
    }
    if(myQueue->length == 0)
    {
        printf("空对列\n");
        return NULL;
    }
    linklist tmp = myQueue->head;
    myQueue->head = myQueue->head->next;
    myQueue->length--;
    return tmp;

}
//销毁队列
void  Queue_destory(Queue *myQueue)
{
    if(myQueue == NULL)
        return ;
    if(myQueue->length == 0)
        free(myQueue);
    else{
        linklist p = myQueue->head,q;
        while(p!=NULL)
        {
            q = p;
            p=p->next;
            free(q);
        }
        free(myQueue);
    }
}





int main()
{
    Queue *queue = Queue_init();
    InQueue(queue,5);

    InQueue(queue,6);
    InQueue(queue,7);
    InQueue(queue,8);
    InQueue(queue,9);
    while(1)
    {
        linklist tmp = DeQueue(queue);
        if(tmp!=NULL)
            printf("tmp ===%d\n",tmp->data);
        else
            break;
    }
}
