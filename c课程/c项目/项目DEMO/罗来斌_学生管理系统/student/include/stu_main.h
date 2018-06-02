/*
*   filename      :student.h
*   author        :luolaibin
*   creat  data   :2012-03-22
*   histroy       :2012-03-22
*/


#ifndef _STU_MAIN_H_
#define _STU_MAIN_H_
#include"link.h"
#include"student.h"
#include "input.h"


/* 学生主菜单*/
void  stu_main(char number[10]);

/*修改密码*/
void set_password(char number[10]);

/*check person information*/
void  print_student(char number[10]);

/*主菜单上的头部分*/
void print_head();






#endif
