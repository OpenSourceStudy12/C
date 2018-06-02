#ifndef _MAINTOOL_H
#define _MAINTOOL_H

#define MAIN_MENU        0
#define LOGIN            1
#define REGISTER         2
#define CUSTOMER_MENU    11
#define C_INFORMATION    111
#define C_SEARCH         112
#define C_BOOK           113
#define C_REFUND         114
#define C_LOGOUT         115

#define ADMIN_MENU       12
#define A_C_MENU         121
#define A_C_NAME         1211
#define A_C_ALL          1212
#define A_C_ADD          1213
#define A_C_DEL          1214
#define A_C_UPDATE       1215
#define A_C_BACK         1216

#define A_T_MENU         122
#define A_T_NU           1221
#define A_T_ALL          1222
#define A_T_ADD          1223
#define A_T_DEL          1224
#define A_T_UPDATE       1225
#define A_T_BACK         1226 

#define A_STA            123
#define A_LOGOUT         124 

/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
void init();

/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
int adminSearchTrainByNu();

/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
int adminSearchAllTrain();

/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
int adminAddTrain();

/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
int adminDelTrain();

/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
int adminUpdate();

/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
int adminSearchByName();

/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
int adminSearchAll();


/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
int adminAddUser();

/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
int adminDeleteUser();

/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
int adminUpdateUser();

/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
PBticket* selectTrain(int *ticketCounts);

/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
int selfBookTrain();


/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
int selfUBookTrain();

/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
int selfSelectTrain();
/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
int selfCustomerInforamtion();
/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
int mainChoose();
/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
int cregister();


/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
int login();

/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
int customer();
/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
int admin();

/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
int manCustomer();
/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
int manTrain();


/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
void isInsertInQueues(PBticket pb, PCbuy pcb, int trainSize);


/*
	函数作用  ：
	参数      ：
	返回值    ：
*/
void hideMenu(PNCustomer pnc);



#endif
