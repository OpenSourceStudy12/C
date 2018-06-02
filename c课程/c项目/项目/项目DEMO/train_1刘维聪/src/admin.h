#ifndef _ADMIN_h
#define _ADMIN_H
#include "common.h"
#define  PRICE 32  //定义每个站之间的价格
#define TOTAL_TICKETS 2
int admin();
PTRA init_train();
PUSE init_user();
int admin_log(PADM admin_head);
int admin_menu();
int admin_manage_train_menu();
int admin_manage_train_choice(PTRA *train_head);
int admin_manage_user_menu();
int admin_manage_user_choice(PTRA *train_head,PUSE *user_head);

int add_train(PTRA *train_head);
int add_user();

void save_train(PTRA train_head);
int del_one_train(PTRA *train_head);
int del_the_train(PTRA the_train);
int print_train(PTRA train_head);
int print_user(PUSE user_head);
int change_user(PUSE *user_head);
int change_admin(PADM admin_head);
void save_user(PUSE user_head);
char my_getchar(void);
void print_the_train(PTRA the_train);
int print_the_user(PUSE the_user);
int get_new_passwd(char new_passwd[]);
void *my_malloc(size_t size);
int admin_del_user(PTRA train_head,PUSE *user_head);
int admin_cancel_user_ticket(PTRA train_head,PUSE user_head);
int check_user_rename(char name[],PUSE head);
#endif