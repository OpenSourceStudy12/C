/*
*  filename    :student.h
*  author      :luolaibin
*  creat  data :2012-03-22
*  histroy     :2012-03-22
*/
#ifndef _STUDENT_H_
#define _STUDENT_H_

/*define student score*/
typedef struct stu_score_node
{
   int math;
   int c_language;
   int chinese;
   int repute;
}stu_score;

/*define student information*/
typedef struct stu_node
{ 
   char number[8];
   char name[128];
   char password[32];
   int age;
   int classroom;
   stu_score  score;   
} stu_info;
#endif
