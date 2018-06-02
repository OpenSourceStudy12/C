/*
*  filename      :check.h
*  autor         :luolaibin
*  creat data    :2012-03-22
*  histroy       :2012-03-22
*/



#ifndef  _CHECK_H_
#define  _CHECK_H_

#include<stdio.h>
#include<string.h>
#include"term.h"
/*define check operate*/

/*
* 接受用户的字符，并判断字符的长度
* 正确则返回1，否则返回0
*/
int  get_char(char *line,unsigned int maxlenght);

/*
*  判断用户输入的是否是整数，
*  是:q
则返回1，否则返回0
*/

char *itoa(int value);

int get_password(char *line,int maxlenght);

//判断输入的字符是否为整数字符
int is_int(char *line);
//判断是不是你要的整数
int is_number(int min,int max);
//获取一个你要的整数
int get_number(int min,int max);




#endif




