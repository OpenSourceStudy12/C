#ifndef _PHONE_H
#define _PHONE_H
#define CONFIG_GPS
#define CONFIG_BLUETEETH

#define GPS 0x1
#define BLUETEETH 0x2
#define CALL 0x4

int GPS_open();//打开ＧＰＳ
int GPS_close();//关闭ＧＰＳ
int GPS_status();
int BLUETEETH_open();//打开蓝牙
int BLUETEETH_close();//关闭蓝牙
int BLUETEETH_status();
int CALL_open();//拨号
int CALL_close();
int CALL_status();

extern int flag;
#endif
