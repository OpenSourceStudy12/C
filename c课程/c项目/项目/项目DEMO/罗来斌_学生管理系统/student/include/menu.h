

#ifndef  _MENU_H_
#define  _MENU_H_
#include "link.h"
#include "student.h"
#include "stu_main.h"
#include "adm.h"
#include"teacher_main.h"

void print_menu();


void print_menu_head();

//判断用户名的密码跟学号是否正确
void load_stu();

//判断教室的登录
void load_teacher();
//判断管理员的登录
void load_adm();

#endif

