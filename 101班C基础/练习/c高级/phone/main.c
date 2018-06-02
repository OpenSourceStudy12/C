#include<stdio.h>
#include"phone.h"

int main()
{
#ifdef CONFIG_WIFI
	WIFI_open();
	WIFI_close();
#endif

//#ifdef CONFIG_GPRS
#if 0
	GPRS_open();
	GPRS_close();
#endif

	call();
	return 0;
}
