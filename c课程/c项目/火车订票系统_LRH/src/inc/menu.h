#ifndef _MENU_H
#define _MENU_H

/************文件包含**********/
#include"include.h"
#include"admin.h"
#include"train.h"
#include"user.h"

/*************宏定义***********/
#define USER_INFO_SEARCH      '1'
#define USER_INFO_CHANGE      '2'
#define USER_TRAIN_SEARCH     '3'
#define TICKET_BOOK           '4'
#define TICKET_REFOUND        '5'
#define USER_LOGOUT           '6'
#define EXIT                  '0'

#define ADMIN_INFO_SEARCH     '1'
#define ADMIN_INFO_CHANGE     '2'
#define TRAIN_MANAGE          '3'
#define USER_MANAGE           '4'
#define ADMIN_LOGOUT          '5'

#define TRAIN_LOOK            '1'
#define TRAIN_ADD             '2'
//#define TRAIN_CHANGE          '3'
#define TRAIN_DEL             '3'

#define USER_LOOK             '1'   
//#define USER_CHANGE           '2'
#define USER_DEL              '2'

#define BACK                  '0'  

void head_print();//头打印
void main_menu_print();//主菜单
void new_user_menu_print();//用户注册页面
void user_log_print();//用户登录页面
void user_menu_print(PUser puser);//用户菜单页面
void admin_menu_print(PAdmin admin);//管理员菜单页面
void admin_train_menu_print();//车次管理页面
void admin_user_menu_print();//用户信息管理页面
PUser new_user_deal(PUser);//新用户注册处理函数
int user_login_deal(PInfo pinfo);//用户登录处理函数
void admin_log_print();//管理员登录页面
int admin_login_deal(PInfo pinfo);//管理员登录处理函数
PTra admin_train_manage(PTra head_train);//管理员车次管理函数
PUser admin_user_manage(PUser head_user,PTra);//管理员用户管理函数







#endif
