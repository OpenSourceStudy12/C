#ifndef _TICKET_H
#define _TICKET_H
#define MAX_StaName 10
#include"common.h"

// 十字链表中纵向的票下一个站点的信息
typedef struct _tickStation
{
	char tsta_name[MAX_StaName];   // 终点站
	int tsta_time;                 // 到达时间
	int tsta_mark;                 // 1代表已定，0代表未定，只有1和0
	int tsta_money;                // 价格
	struct _tickStation *next;     // 下一站
}NTStation, *PTStation;

// 车票的信息
typedef struct _ticket
{
	PTStation t_pTStation;         // 纵向链表的头结点
	int t_trainnu;                 // 车次
	int t_time;                    // 出发时间
	char t_fStation[MAX_StaName];  // 起始站
	struct _ticket *t_next;       
}NTicket, *PTicket;

// 顾客买时要用的票的信息
typedef struct _bticket
{
        char b_sstation[10];   // 起始站
        char b_tstation[10];   // 终点站
        int b_trainnu;         // 车票的车次
        int b_time;            // 到达时间
	int b_money;           // 价格
	int *isBuy;            // 与车票购买中是否该买相连 
}NBticket, *PBticket;


/*
	函数作用 ：创建一个车次车票的链表

*/
PTicket createOneTrainTicket(PNStation pShead);

/*
	函数作用 ：创建所有车次车票的链表数组
*/

PTicket* createAllTrainTicket(PNStation* pShead, int trainSize);

/*
	函数作用 ： 将用户选择的购买的车票信息与真实的车票进行转换
*/
PBticket selectToRealPBticket(PBticket *phead, int select, int ticketSize);

/*
	函数作用 ：创建一个车票内竖向查找下一个车站的链表
	
*/
PTStation createPTStationLink(PNStation pStemp2);


/*
	函数作用 ：遍历一张车次车票的链表
*/
void traverseOneTrainTicket(PTicket phead);

/*
	函数作用 ： 根据终点站，起始站查找车票
	返回值   ： 返回PBticket
	其他     ： 返回值需要判断是否为NULL，如果是NULL 就说明没有找到
*/
PBticket searchBticket(const char *start, const char *end, PTicket phead);


/*
	函数作用 ： 根据终点站，其实站站查找车票
	返回值   ： 
	
*/
PBticket* searchAllBticket(const char *start, const char *end, PTicket *pstart, int trainSize);
/*
	 函数作用 ：通过给定的购买的车票来定位子
*/

int bookTicket(PBticket pb);



/*
	函数作用 ：打印一张已购买车票的信息
*/
void printOnePBticket(PBticket pb);


/*
	函数作用 ：打印所有查询的车票信息
	返回值   ：符合车票的张数
*/
int printAllPBticket(PBticket *pb, int trainSize);
#endif

