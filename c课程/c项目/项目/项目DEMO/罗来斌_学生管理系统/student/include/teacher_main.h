

#ifndef _TEACHER_MAIN_H_
#define _TEACHER_MAIN_H_
#include "manage_teacher.h"
#include "input.h"
#include "check.h"
#include "link.h"
#include "manager_stu.h"
/* 主菜单*/
void  print_teacher_person_main(char number[10]);

/*修改密码*/
void set_teacher_person_password(char number[10]);

/*check person information*/
void  print_teacher_person(char number[10]);

/*主菜单上的头部分*/
void print_head_teacher_person();



#endif
