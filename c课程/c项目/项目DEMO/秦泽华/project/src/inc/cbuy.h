#ifndef _CBUY_H
#define _CBUY_H
#define CBUY_DB "cbuy.db"

// 购买车票顾客的信息
typedef struct _cbuy
{
	char b_cname[10];        // 姓名
	char b_sstation[10];     // 起始站
	char b_tstation[10];     // 终点站
	int b_trainnu;           // 车次
	int b_time;              // 到达时间
	int *b_isbuy;            // 与车票信息中是否购买相连
	struct _cbuy *next;
}NCbuy, *PCbuy; 

// 未购买用户的队列
typedef struct _queue
{
        int number;              // 队列的编号
        PCbuy pfront;            // 队列中未购买用户的链表
        int isUbook;             // 是否已经退订 
}NQueue, *PQueue;



/*
	函数作用 ：创建未购买用户的队列
	参数     ：pcb 未购买用户， queueNum 队列编号
	返回值   ：队列的头指针
*/
PQueue createQueue(PCbuy pcb, int queueNum);

/*
	函数作用 ：判断用户队列数组中是否存在该队列编号的队列
	参数     ：p 队列数组， queueNum 队列编号， arr_size队列数组长度, *pos 指向队列数组中该队列的位置
	返回值   ：所查找的队列，没有返回NULL
*/
PQueue isQueueExist(PQueue* p, int queueNum, int arr_size, int *pos);


/*
	函数作用 ： 通过车次编号在车票链表数组中查找符合的车票链表
	参数     ： pstart 车票链表， trainnu 车次编号， arr_size车票链表数组长度
	返回值   ： 车票链表
*/
PTicket searchTicketByNu(PTicket *pstart, int trainnu, int arr_size);


/*
	函数作用 ： 生成未购买队列的编号
	参数     ： start 起始站， end 终点站， phead 车票链表的头指针
	返回值   ： 未购买队列的编号
*/
int searchNumToQueue(const char *start, const char *end, PTicket phead);

/*
	函数作用 ： 将未购买用加入到队列中
*/
PQueue inCbuyQueue(PQueue phead, PCbuy prear);

/*
	函数作用 ： 通过用户找到未购买车票链表
*/
PQueue searchQueuesByPCbuy(PQueue *pq, PNCustomer pnc, int queueSize);

/*
	函数作用 ： 将队列isUbook设为1
*/
void setUbookTo1(PQueue pq);

/*
	函数作用 ： 将队列isUbook设为0
*/
void setUbookTo0(PQueue pq);


/*
	函数作用 ： 出队列
*/
void outCbuyQueue(PQueue phead);


/*
	函数作用 ： 根据用户名和已购车票信息创建一个购买的用户信息
*/
PCbuy createOneCbuy(PNCustomer pc, PBticket pt);

/*
	函数作用 ： 创建一个购票客户的链表
*/
PCbuy createBuyLink(PCbuy phead);
/*
	函数作用 ：顾客订票成功，将顾客加入到已经购票链表中
*/
PCbuy insertBuyLink(PCbuy phead, PCbuy pnew);

/*
	函数作用 ：从已购票链表中删除用户节点，（退票业务）
*/
PCbuy deleteOneBuy(PCbuy phead, PCbuy pdelete);

/*
	函数作用 ： 打印出已购票用户信息
*/
void traverseBuyLink(PCbuy phead);

/*
	函数作用 ： 判断用户是否已经购买车票
*/
int judgeHadBuy(PCbuy phead, PNCustomer pc);

/*
	函数作用 ： 读取所用购买用户信息
*/
PCbuy  readAllPCbuy();

/*
	函数作用 ：将所有用户写入文件
	参数     ：
	返回值   ：
*/
void writeAllPCbuy(PCbuy phead);

/*
	函数作用 ：从购买者链表中删除购买者
	参数     ：
	返回值   ：
*/
PCbuy delOneCbuy(PCbuy phead, PCbuy pdel);

/*
	函数作用 ：通过姓名查找车票购买者
	参数     ：
	返回值   ：
*/
PCbuy searchCbuyByName(PNCustomer pnc, PCbuy phead);

/*
	函数作用 ：输出一个车票购买者
	参数     ：
	返回值   ：
*/
void printOneCbuy(PCbuy ptemp);



#endif
