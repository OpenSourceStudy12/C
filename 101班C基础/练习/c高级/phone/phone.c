//#include<stdio.h>
#include"phone.h"

#ifdef CONFIG_WIFI
int WIFI_open()
{
	printf("WIFI open succes\n");
	return 0;
}

int WIFI_close()
{
	printf("WIFI close succes\n");
	return 0;
}
#endif

//#ifdef CONFIG_GPRS
//#if 0
int GPRS_open()
{
	printf("GPRS open succes\n");
	return 0;
}

int GPRS_close()
{
	printf("GPRS close succes\n");
	return 0;
}
//#endif 

int call()
{
	printf("calling...\n");
	return 0;
}





