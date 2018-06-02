#ifndef _USER_H
#define _USER_H

/*******文件包含*******/
#include"include.h"
#include"train.h"
#include"menu.h"
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<unistd.h>

/***************宏定义**************/
#define PASS_MAX 20

/***************函数声明***************/
//判断用户信息链表链表是否已满
static int malloc_full_user();

//判断用户车次链表是否已满
static int malloc_full_user_info_train();

PUser user_link_creat();//尾插法建立用户信息链表

PUser new_user_login(PUser head_user);//新用户注册

int user_login(PUser head,PUser *user_head);//老用户登录

void user_info_search(const PUser head);//用户订票信息查询

void user_info_change(PUser user);//用户密码修改
//添加用户订票信息
void user_train_info_add(PTra train,PUser user_head,Date date,char *ch,char *start,char *end);

void ticket_reservation(PUser user_head,const PTra head);//火车票预订

void ticket_refund(PUser head,PTra train_head);//火车票退订

void ticket_refund_search(const PUser head);//退票查询
//检验日期
int date_check(int year,int month,int day);
//比较日期是否相等
int date_compare(PU_i_t p,Date date);
//余票检查
int ticket_left_inspect(PTra head_train,char *sta);

//火车预订票
int adv_book_ticket(PTra train,PUser user,Date date,char *tr,char *st,char *end);

//预订票处理
void adv_book_deal(PTra head_train,PUser user);

//按日期排序
void user_tic_sort_date(PUser User);

//找最晚日期的车票
PU_i_t pmax_search(PU_i_t head_tic);

//将最晚日期的车票从原链表中移除
PU_i_t pmax_remove(PU_i_t head_tic,PU_i_t pmax);

//将最晚日期的车票添加到心链表中
PU_i_t new_sort(PU_i_t new_head,PU_i_t pmax);

/*************************全局变量声明*********************/
//extern PUser Head_user;


#endif
