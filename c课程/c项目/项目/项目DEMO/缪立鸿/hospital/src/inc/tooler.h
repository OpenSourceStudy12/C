#ifndef _TOOLER_H
#define _TOOLER_H

#include "patient.h"

int t_get_password(char password[]);
void t_pause(void);
int input_num_check(int min, int max);
int input_string_check(char *str, int len);
int input_doc_name(PPINFO s);
int input_nurse_name(PPINFO s);
int input_advice_doc_name(PAINFO s);
int input_advice_nurse_name(PAINFO s);

#endif
