#ifndef _INCLUDE_H
#define _INCLUDE_H

//库函数
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

//用户函数
//#include"menu.h"
//#include"train.h"
//#include"user.h"
//#include"admin.h"


/*******************************宏定义*****************************/
#define STA_NAME 30 //车站名长度
#define TRA_NUM  10  //车次名长度

#define NAME_SIZE 15//用户名长度
#define PASS_NUM  7 //密码位数

#define TICKET_NUM  2 //每个车站的票数
#define TIME_LENTH  8 //到站时间与发车时间的间

#define PRICE   35.5 //每站之间的票价

/*****************************定义结构体****************************/
//日期
typedef struct date
{
	int year;
	int month;
	int day;
}Date,*PDate;

//队列(排队订票)
typedef struct queue
{
	char name[NAME_SIZE];//预订车票的用户名
	char train_num[TRA_NUM];
	char start_name[STA_NAME];//出发站
	char end_name[STA_NAME];  //到站
	Date date;//订票日期
	struct queue *next;
}Queue,*PQueue;

//车站结构体
typedef struct station
{
	char sta_name[STA_NAME];//车站名
	int arrival_hour;
	int arrival_minute;
	int departure_hour;
	int departure_minute;
	int ticket_num;
	struct station *next;//指向下一个车站结构体的指针
}Sta,*PSta;

//车次结构体
typedef struct train
{
	char train_num[TRA_NUM];//车次名
	int station_num;//每列车次的车站数
	int ticket_price;//每站之间的路费
	int total_time;//总运行时间
	//int total_;//总运行路程
	//int T_ID;
	PSta pst;//指向车站结构体的指针
	struct train *next;//指向下一个车次结构体的指针
	PQueue pqueue;//指向预订票的队列
}Tra,*PTra;

//满足站站查询的车次结构体
typedef struct tr
{
	//int cnt;
	//char train_num[TRA_NUM];
	PTra ptra;
	struct tr *next;
}Tr,*PTr;

//用户订票信息结构体
typedef struct user_info_train
{
	char train_num[TRA_NUM];
	char start_name[STA_NAME];//出发站
	char end_name[STA_NAME];  //到站
	int num;//车票序号
	int depart_hour;//发车时间(时)
	int depart_minute;//发车时间(分)
	int run_hour;//运行时间(时)
	int run_minute;//运行时间(分)
	Date date;//乘车日期
	struct user_info_train *next;
}U_i_t,*PU_i_t;

//用户信息结构体
typedef struct user
{
	int ID;
	char name[NAME_SIZE];//用户名
	char passward[PASS_NUM];
	int ticket_num;
	//char sex[3];//用户性别
	//int old;//年龄
	//char ID[15];//证件号
	//PTra num_sta;//指向所订购车次结构体的指针
	PU_i_t pu_i_t;
	struct user *next;//指向下一个用户信息结构体的指针
}User,*PUser;

//管理员信息结构体
typedef struct admin
{
	char name[NAME_SIZE];
	char passward[PASS_NUM];
}Admin,*PAdmin;

//用户信息结构体和车次结构体头指针
typedef struct info
{
	PUser Head_user;
	PTra Head_train;
	PAdmin Head_admin;
}Info,*PInfo;

 //Info info;//定义变量

#endif
