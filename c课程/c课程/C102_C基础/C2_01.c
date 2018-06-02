
/*
*
* C programming 2
* author: LiQiang
* date: 2010/10/14
* version: v1.1
*
*/

/*include file*/
#include <stdio.h>
#include <string.h>
#include <math.h>


/*MICRO and gloable varible*/
#define MAX_SIZE 8

/*Local function*/
int MyStrtol(char *src, unsigned int m);
int CheckStr(char *src);


void main()
{
	char source[MAX_SIZE + 1];
	int result = 0;
	int check_res = -1;


	/*Get a string from keypad input*/
	memset(source, 0, MAX_SIZE + 1);
	printf("Please input a string less than %d chars\n", MAX_SIZE);
	gets(source);
	printf("\nUser input string =%s\n", source); /*For testing*/


	/*First: check the string*/
	check_res = CheckStr(source);

	if (check_res < 0)
	{
		printf("Error input string:\n Please input a string only include 0~9, a~f, A~F\n");

		return;
	}
	else if (check_res == 1)
	{
		/* delete the "0x" or "0X" */
		strcpy(source, source + 2);
		printf("After del, the str=%s\n", source);
	}
	else
	{
	}

	result = MyStrtol(source, 16); /*change to 10 jinzhi*/
	printf("\nThe result is %d\n", result);
}


/*function: check a string's format
* paramter:
*			char *str: 
* return value:
*			1	include "0x"/"0X"
*			0	SUCESS
*			-1	FAIL
*/
int CheckStr(char *src)
{
	char *p = NULL;
	int flag_0x = 0;

	p = src;

	/*check "0x" or "0X"*/
	if ((strstr(src, "0x") == p) || (strstr(src, "0X") == p))
	{
		flag_0x = 1;
		p += 2;
	}

	/*check 0~9, a~f, A~F*/
	while (*p != '\0')
	{
		if (!(((*p >= '0') && (*p <= '9'))
			|| ((*p >= 'a') && (*p <= 'f'))
			|| ((*p >= 'A') && (*p <= 'F'))))
		{
			return -1; /*format error*/
		}

		p ++;
	}

	if (flag_0x == 1)
	{
		return 1; /*include "0x"/"0X"*/
	}
	else
	{
		return 0; /*Not include "0x"/"0X"*/
	}
}


/*function: change the string to 10 int
* paramter:
*			char *str: 
*			int m:
* return value: 
*/
int MyStrtol(char *src, unsigned int m)
{
	char *p = NULL;
	int res = 0;

	p = src + strlen(src) - 1;

	switch(m)
	{
		case 16: /**/
			break;
		case 8: /**/
			break;
		default:
			break;
	}
/*
	while (*p != '\0')
	{
		p ++;
	}
*/
	return 0;
}


/*function: Get a string from keypad
* paramter:
*			char *str: dest string, save the input string
* return value: the length of input string
*/
int MyGetString(char *str)
{
	int i = 0;
	char c;

	while ((c = getchar() != EOF))
	{
		str[i] = c;
		i ++;
	}

	str[i] = '\0';

	return i;
}


