#ifndef _COMMON_H
#define _COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <term.h>
#include <time.h>
#include <assert.h>

//#include "main.h"
//#include "patient.h"
//#include "doctor.h"
//#include "nurse.h"
//#include "admin.h"
//#include "shared.h"

#define MAIN_MENU		0
#define PATIENT_LOGIN	1
#define PERSONNEL_LOGIN	2
#define ADMIN_LOGIN		3
#define EXIT_PROGRAM	4

#define P_MENU		10
#define P_P_VIEW		11
#define P_P_MODIFY	12
#define P_A_VIEW		13
#define P_MENU_BACK	14

#define D_MENU		210
#define D_D_MODIFY	211
#define D_P_VIEW		212
#define D_A_VIEW		213
#define D_A_MODIFY	214
#define D_A_CREATE	215
#define D_MENU_BACK	216

#define N_MENU		220
#define N_N_MODIFY	221
#define N__P_VIEW	222
#define N_UA_VIEW	223
#define N_EA_VIEW	224
#define N_A_EXE		225
#define N_MENU_BACK	226

#define A_MENU		30
#define A_A_MODIFY	31
#define A_P_REG		32
#define A_P_MODIFY	33
#define A_D_MODIFY	34
#define A_N_MODIFY	35
#define A_MENU_BACK	36

#endif
