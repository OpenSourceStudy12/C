
#include"term.h"
void set_keypress(void)
{
	struct termios new_settings;     
	tcgetattr(0,&stored_settings);     
	new_settings = stored_settings;
	/* Disable canonical mode, and set buffer size to 1 byte */     
	new_settings.c_lflag &= (~ICANON);     
	new_settings.c_cc[VTIME] = 0;     
	new_settings.c_cc[VMIN] = 1;
	tcsetattr(0,TCSANOW,&new_settings);
	return;
}
void reset_keypress(void)
{
	tcsetattr(0,TCSANOW,&stored_settings);    
	return;
}

void echo_off(void)
{
	struct termios new_settings;   
	tcgetattr(0,&stored_settings);
	new_settings = stored_settings;    
	new_settings.c_lflag &= (~ECHO);   
	tcsetattr(0,TCSANOW,&new_settings); 
	return;
}

void echo_on(void)
{
	tcsetattr(0,TCSANOW,&stored_settings);   
	return;
}
/*int main()
{
	char ch;	
	set_keypress();	
	echo_off();	
	ch = getchar();	
	putchar('*');
	//printf("Test: getchar=%c\n", ch);
	echo_on();	
	return 1;
}*/


