/**************************************************************
File Name:		main.c
Created:			Miao Lihong
				All Rights Reserved
Creat Date:		May, 21, 2013
Last Modification:	May, 27, 2013
Latest Version:		0.1.0
Notification: 	This source code is designed for self entertainment and education use only. 
			Do not use this for business purpose.
Description:	This program is a simple project of hospital administration. Admin, patient, 
			doctor and nurse will use this for different purposes.
			If you have any idea to improve this program, pls feel free to email me:	
			lhmiao@gmail.com
**************************************************************/

#include "common.h"
#include "shared.h"
#include "menu.h"

/*********************************************************

*********************************************************/
int main()
{
	int status = 0;		//二级菜单
	init();
	//status = pmain();
	while(1)
	{
		status = select_from_menu(status);
    	//printf("status = %d\n",status);
		status = dispatch_from_cmd(status);
	}
	return 0;
}



