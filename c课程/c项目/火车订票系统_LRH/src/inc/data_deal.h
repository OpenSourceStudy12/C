#ifndef DATA_DEAL_H
#define DATA_DEAL_H

#include"include.h"

PUser user_data_read();//读取用户数据

PTra train_data_read();//读取车次数据

int user_data_save(PUser head_user);//存储用户数据

int train_data_save(PTra head_train);//存储车次数据

#endif
