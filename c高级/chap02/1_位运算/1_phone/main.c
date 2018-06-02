#include <stdio.h>
#include "phone.h"


int main()
{
	int ret;
	GPS_open();
	BLUETEETH_close();
	CALL_close();

	ret = GPS_status();
	if (ret)
	{
		printf("ＧＰＳ已开启\n");
	}
	else
	{
		printf("ＧＰＳ未开启\n");
	}
	ret = BLUETEETH_status();
	if (ret)
	{
		printf("蓝颜已开启\n");
	}
	else
	{
		printf("蓝牙未开启\n");
	}
	ret = CALL_status();
	if (ret)
	{
		printf("拨号已开启\n");
	}
	else
	{
		printf("拨号未开启\n");
	}
	return 0;
}
