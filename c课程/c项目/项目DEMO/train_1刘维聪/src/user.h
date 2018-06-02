#ifndef _USER_H
#define _USER_H
#include "common.h"
int user();
int user_log();
int user_menu();
int search_train(PTRA train_head,PUSE user_head,PUSE now_user);
int search_station(PTRA train_head,PUSE user_head,PUSE now_user);
int user_regedit();
int new_user_log(PUSE user_head,PUSE new_user);
int personal_change(PUSE user_head,PUSE p_user);
int cancel_ticket(PUSE now_user,PTRA train_head);
int book_ticket(PUSE now_user,PTRA p_train,\
	char start_station[],char aim_station[],int book_way);
int search_the_train(PTRA train_head,PTRA *pp_train);
int wait_ticket(PUSE now_user,\
	PTRA p_train,char start_station[],char aim_station[]);
#endif