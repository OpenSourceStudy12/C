#include <termios.h>
#include <unistd.h>
#include <stdio.h>

struct termios stored_settings;

/************************************************
function name	:set_keypress
function		:set terminal single-key input read mode
input parameter	:
return value	:
description	:
*************************************************/
void set_keypress(void)
{
	struct termios new_settings;
	tcgetattr(0,&stored_settings);
	new_settings = stored_settings;

	/*Disable canonical mode, and set buffer size to 1 byte */
	new_settings.c_lflag &= (~ICANON);
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;
	tcsetattr(0,TCSANOW,&new_settings);
}

/***************************************************
function name	:reset_keypress
function		:
input parameter	:
return value	:
description	:(set to default read key mode)function is not used
****************************************************/
void reset_keypress(void)
{
	tcsetattr(0,TCSANOW,&stored_settings);
	return;
}

/***************************************************
function name	:echo_off
function		:
input parameter	:
return value	:
description	:set terminal to no-echo mode(no remapping keyboard)
****************************************************/
void echo_off(void)
{
	struct termios new_settings;
	
	tcgetattr(0,&stored_settings);
	new_settings = stored_settings;
	new_settings.c_lflag &= (~ECHO);
	tcsetattr(0,TCSANOW,&new_settings);

	return;
}

/***************************************************
function name	:echo_on
function		:
input parameter	:
return value	:
description	:set terminal to default display mode
****************************************************/
void echo_on(void)
{
	tcsetattr(0,TCSANOW,&stored_settings);
	return;
}

int main(){
	char ch;
	int count = 0;
	char password[10] = {0};
	
	char *pstr = password;
	set_keypress();

	echo_off();
	while(1)
	{
		if(count==6){
			break;
		}
		ch = getchar();
		putchar('*');
		*pstr++ = ch;
		count++;
	}
	echo_on();
	reset_keypress();
	printf("\nTest:getchar = %s\n",password);
	return 0;
}
