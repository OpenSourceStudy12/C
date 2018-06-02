/*文件名：train.h
*功能：车票信息管理
*作者：
*日期：
*修改记录：新建
*/

#ifndef _TRAIN_H
#define _TRAIN_H
/***********************头文件包含******************************/

#include "admin.h"
#include "user.h"
#include "common.h"

/***********************头文件包含******************************/

/***********************结构体定义 宏定义************************/

typedef struct Station//站点信息
{
	char sta[20];
	char time[7];
	struct Station *next;
}Sta,*PSta;

typedef struct wait_user//排队等候用户信息
{
	char train[7];
	char start[20];
	char des[20];
	char name[30];
	char time[6];
	struct wait_user *next;
}Wait,*PWait;

typedef struct train//车票信息
{
	char ticket[7];
	char start[20];
	char des[20];
	char start_time[7];
	char des_time[7];
	int des_num;
	int remain;
	struct train *next;
	PSta sta_head;
	PWait wait_head;
}Tr,*PTr;


/***********************结构体定义 宏定义************************/

/***********************变量的申明**************************/



/***********************变量的申明**************************/

/***********************函数的申明**************************/
PTr TrainLinkInsert(PTr head);// 车票添加
PSta StationCreat();//站点添加
void Train_print(PTr head);//列车列表打印
PTr Train_del(PTr head,char *train);//列车删除
void station_print(PTr head);//列车站点信息打印
PTr Train_searchBytrain(PTr head,char *train);//通过车次查询列车
PTr Train_searchByDes(PTr head,char *sta,char *des);//通过区域查询列车
void Train_modify(PTr head);
PTr train_order(PTr head,PUser Uhead,char *train,char *name);//订票
PTr train_unorder(PTr head,PUser Uhead,char *train,char *name);//退票
int user_waittrain_check(PTr head,PUser Uhead,char *name);//查找用户排队的车次是否有余票
PTr train_wait_del(PTr head,char *name,char *train);//车票所挂排队用户删除
void Train_Link_Write(PTr head);//列车链表信息写入文件
PTr Train_Link_Read();//列车链表信息从文件读入
/***********************函数的申明**************************/
#endif
