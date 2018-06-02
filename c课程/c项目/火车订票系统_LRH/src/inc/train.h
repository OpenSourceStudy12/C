#ifndef _TRAIN_H
#define _TRAIN_H
/*
******************************文件包含****************************/
#include"include.h"
//#include"user.h"
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<unistd.h>

#define MONTH    12  //月
#define HOUR     24  //小时
#define MINUTE   60  //分钟

#define ZERO     0

/******************************函数声明******************************/
void train_num_search(const PTra head);//车次查询
void route_map_print(const PTra head);//车次路线打印
PTr station_search(const PTra head,char *start,char *end);//站站查询
void link_del(PTr head);//删除链表
PTr node_add(PTr head,PTra ch);//建立链表(满足站站查询的车次链表)
PSta end_station_search(PTra head);//查找列车最后一个站
void print(PTr head,char *start,char *end);//打印站站查询结果
void single_print(PTra head,char *start,char *end);//打印将要订票的车次信息

//根据输入的将要退票的车次，查询车次结构体地址
PTra train_address_search(const PTra head,char *ch);

//计算两车站间的时间等信息
void train_time_count(PSta pr,PSta pn,int *de_hour,int *de_min,int *run_hour,int *run_min);
//查找车次中车站的地址
PSta sta_address_search(PTra train,char *ch);

//通过车次名称查找对应的地址
//PTra train_address_search(const PTra train_head,char *train_num)

#endif
