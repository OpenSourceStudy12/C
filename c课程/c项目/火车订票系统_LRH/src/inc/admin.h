#ifndef _ADMIN_H
#define _ADMIN_H

#include"include.h"
#include"train.h"
#include"user.h"

#define ADMIN_NAME        "admin"
#define ADMIN_PASSWARD    "admin"


void admin_init(PAdmin *admin);//设定管理员信息
int admin_login(PAdmin admin,char *name,char *passward);//管理员登录检测

void admin_info_look(PAdmin admin);//管理员信息查看
void admin_info_change(PAdmin head_admin);//管理员信息修改

void train_look(PTra head_train);//车次查看
PTra train_add(PTra head_train);//车次添加
void train_change();//车次修改
PTra train_del(PTra head_train);//车次删除

void user_look(const PUser head_user);//查看用户
void user_change();//修改用户
PUser user_del(PUser head_user,PTra);//删除用户

//根据列车到站时间设定发车时间
void departure_time_set(int hour,int minute,int *l_hour,int * l_minute);
//检查该车次是否已添加
int train_name_check(PTra head_train,char *name);
void station_del(PTra Train);//删除车次车站
PUser user_tr_del(PUser User,PUser);//删除用户 
//查找用户地址
PUser user_search(const PUser user_head,char *name);
//删除用户的车票
void user_ticket_refund(PUser head,PTra train_head);


#endif
