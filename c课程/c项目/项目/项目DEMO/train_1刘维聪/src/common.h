#ifndef _COMMON_H
#define _COMMON_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct station//火车经过的站点结构体
{
	char name[20];//站名
	char s_time[10];
	int price;//起点站到本站的价格
	struct station *next;//下一站
}STA,*PSTA;

typedef struct waiter//定义排队信息
{
	char name[20];//排队者的姓名
	int count_flag;//排在第几位
	struct waiter *next;
}WAI,*PWAI;

typedef struct train//火车信息结构体
{
	char name[10];//车次名
	int count;//总站点数
	struct train *next;//下一趟车
	int tickets;//定义余票张数
	int waiters;//定义排队者个数
	int cancel_ticket;//定义退票张数
	PWAI my_waiter;//定义排队者的名字
	PSTA my_station;//指向本次列车经过的车站链表
}TRA,*PTRA;

typedef struct ticket//车票信息结构体
{
	int flag;//用于标记是否为排队票1为排队的票其他为正常票
	char train_name[10];//所订车票的车次
	char start_station[20];//起始站
	char start_time[10];//出发时间
	char aim_station[20];//终点站
	char aim_time[10];//到站时间
	int ticket_price;//票价
	struct ticket *next;//单用户买多张票，指向下一张票
}TIK,*PTIK;

typedef struct user//用户结构体
{
	char name[20];
	char passwd[10];
	//保存订票信息
	int tickets;
	int waiting_tickets;//排队的总票数
	PTIK my_ticket;//所购票的链表头
	struct user *next;//指向下一个用户
}USE,*PUSE;

typedef struct admin//管理员结构体
{
	char name[20];//管理员账号
	char passwd[10];//管理员密码
}ADM,*PADM;

#endif
