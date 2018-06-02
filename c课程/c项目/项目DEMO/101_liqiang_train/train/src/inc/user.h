/*文件名：user.h
*功能：用户管理
*作者：
*日期：
*修改记录：新建
*/

#ifndef _USER_H
#define _USER_H
/***********************头文件包含******************************/

#include "common.h"

/***********************头文件包含******************************/

/***********************结构体定义 宏定义************************/

typedef struct wait_train
{
	char train[20];
	char sta[20];
	char des[20];
	struct wait_train *next;
}Wtrain,*PWtrain;

typedef struct User
{
	char name[20];
	char pswd[20];
	char ID[20];
	PWtrain buytrain_head;
	PWtrain train_head;
	struct User *next;
}User,*PUser;


/***********************结构体定义 宏定义************************/

/***********************变量的申明**************************/



/***********************变量的申明**************************/

/***********************函数的申明**************************/


PUser User_Add(PUser head);//用户添加
void User_print(PUser head);//打印所有用户
void user_modify(PUser head,char *name);//用户信息修改
PUser user_del(PUser head,char *name);//用户删除
PUser user_search(PUser head,char *name);//按用户名查找用户
int user_match(PUser head,char *name,char *pswd);//用户身份匹配,返回-1失败,返回0成功
PUser user_pswd_modify(PUser head,char *name);//用户修改密码
PUser user_wait_train_add(PUser head,char *name,char *train,char *start,char *des);//用户所排车票链表建立
PUser user_buytrain_add(PUser head,char *name,char *train,char *start,char *des);//用户已购车票链表建立	
void userinfo_print(PUser head,char *name);//用户个人信息打印
PUser user_waittrain_del(PUser head,char *name,char *train);//用户排队等候车票删除
PUser user_buytrain_del(PUser head,char *name,char *train);//用户已购车票删除	
void User_data_write(PUser head);//用户信息写入文件
PUser User_data_read();//从文件读出用户信息
/***********************函数的申明**************************/
#endif
