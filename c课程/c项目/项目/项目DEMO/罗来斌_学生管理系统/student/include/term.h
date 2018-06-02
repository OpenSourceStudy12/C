#ifndef _TERM_C_
#define _TERM_C_

#include <termios.h>
#include <unistd.h>
#include <stdio.h>
struct termios stored_settings;


void echo_on(void);

void set_keypress(void);

void reset_keypress(void);

void echo_off(void);

#endif

