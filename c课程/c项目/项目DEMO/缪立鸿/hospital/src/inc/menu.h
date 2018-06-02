#ifndef _MENU_H
#define _MENU_H

int welcome_msg();
int patient_menu();
int doctor_menu();
int nurse_menu();
int admin_menu();
void system_exit();
void confirm_exit();
int select_from_menu(int status);
int personnel_login();
int patient_menu_back();
int doctor_menu_back();
int nurse_menu_back();
int admin_menu_back();
int dispatch_from_cmd(int status);

#endif
