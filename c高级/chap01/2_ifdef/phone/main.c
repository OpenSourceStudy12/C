#include <stdio.h>
#include "phone.h"


int main()
{
#ifdef CONFIG_GPS
	GPS_open();
#endif
#ifdef CONFIG_BLUETEETH
	BLUETEETH_open();
#endif
	Call();
	return 0;
}
