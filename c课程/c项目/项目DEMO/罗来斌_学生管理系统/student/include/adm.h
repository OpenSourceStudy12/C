

#ifndef _ADM_H_
#define _ADM_H_
#include "manage_teacher.h"
#include "manager_stu.h"

typedef struct adm_node
{
	char name[20];
	char number[8];
	char password[8];
}Adm;





void print_adm_main();

void print_adm_head();
 
void show_adm_info();

void change_adm_password();

void save_adm_info();

void read_adm_info();



#endif


