#include <stdio.h>
#include "phone.h"


#ifdef CONFIG_GPS
int GPS_open()//打开ＧＰＳ
{
	//...
	printf("open GPS\n");
	return 0;
}

int GPS_close()//关闭ＧＰＳ
{
	//..;
	printf("close GPS\n");
	return 0;
}
#endif

#ifdef CONFIG_BLUETEETH
int BLUETEETH_open()//打开蓝牙
{
	//...;
	printf("open blueteeth\n");
	return 0;
}
int BLUETEETH_close()//关闭蓝牙
{
	//...;
	printf("close blueteeth\n");
	return 0;
}
#endif

int Call()//拨号
{
	printf("calling..\n");
	return 0;
}
