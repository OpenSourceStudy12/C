#ifndef _ADMIN_H
#define _ADMIN_H

//#include "common.h"
#define AD_MAX_TRIAL_TIMES	3
#define AD_MAX_STRING_LEN	16

typedef struct ad_AdminInfo
{
	char ad_name[AD_MAX_STRING_LEN];
	char ad_password[AD_MAX_STRING_LEN];
	struct ad_AdminInfo *next;
}ADINFO, *PADINFO;

void ad_one_admin_print(PADINFO phead);
void ad_all_admin_print(PADINFO phead);
void admin_info_view();
int ad_write_admin_to_file(PADINFO head);
int ad_read_admin_from_file(PADINFO *head);
PADINFO ad_admin_delete(PADINFO head, PADINFO pp);
int ad_register_from_input(PADINFO s);
int ad_register_admin(PADINFO *head);
int admin_login();
int admin_self_info_man();
int admin_patient_register();
int admin_patient_info_man();
int admin_doc_info_man();
int admin_nurse_info_man();

#endif
