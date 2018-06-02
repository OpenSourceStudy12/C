#include <stdio.h>
#include "phone.h"


int flag=0;

#ifdef CONFIG_GPS
int GPS_open()//打开ＧＰＳ
{
	//...
	printf("open GPS\n");
	flag |= GPS;
	return 0;
}

int GPS_close()//关闭ＧＰＳ
{
	//..;
	printf("close GPS\n");
	flag &= ~GPS;
	return 0;
}

int GPS_status()//读取GPS的状态
{
	return flag&GPS;
}

#endif

#ifdef CONFIG_BLUETEETH
int BLUETEETH_open()//打开蓝牙
{
	//...;
	printf("open blueteeth\n");
	flag |= BLUETEETH;
	return 0;
}
int BLUETEETH_close()//关闭蓝牙
{
	//...;
	flag &= ~BLUETEETH;
	printf("close blueteeth\n");
	return 0;
}
int BLUETEETH_status()//读取蓝牙的状态
{
	return flag&BLUETEETH;
}
#endif

int CALL_open()//拨号
{
	printf("calling..\n");
	flag |= CALL;
	return 0;
}

int CALL_close()
{
	printf("call over..\n");
	flag &= ~CALL;
	return 0;
}
int CALL_status()//读取拨号的状态
{
	return flag&0x4;
}






