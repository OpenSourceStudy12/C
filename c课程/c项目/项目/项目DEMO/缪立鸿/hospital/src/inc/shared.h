#ifndef _SHARED_H
#define _SHARED_H

//#include "common.h"
#include "patient.h"
#include "doctor.h"
#include "nurse.h"
#include "admin.h"


void init();
PDINFO d_doc_search_by_data(PDINFO phead, int data, int option);
PNINFO n_nurse_search_by_data(PNINFO phead, int data, int option);
PPINFO s_update_all_patient_head(PPINFO phead);
PDINFO s_update_all_doc_head(PDINFO phead);
PNINFO s_update_all_nurse_head(PNINFO phead);
PADINFO s_update_all_admin_head(PADINFO phead);
PPINFO s_get_all_patient_head();
PDINFO s_get_all_doc_head();
PNINFO s_get_all_nurse_head();
PADINFO s_get_all_admin_head();
PPINFO s_get_named_patient_head();
PDINFO s_get_named_doc_head();
PNINFO s_get_named_nurse_head();
PADINFO s_get_named_admin_head();

PPINFO s_search_patient_by_name(PPINFO phead, char *str);
PDINFO s_search_doc_by_name(PDINFO phead, char *str);
PNINFO s_search_nurse_by_name(PNINFO phead, char *str);
PADINFO s_search_admin_by_name(PADINFO phead, char *str);


PPINFO p_patient_destroy(PPINFO head);
PDINFO d_doc_destroy(PDINFO head);
PNINFO n_nurse_destroy(PNINFO head);
PADINFO ad_admin_destroy(PADINFO head);
void s_destroy_all();

#endif
