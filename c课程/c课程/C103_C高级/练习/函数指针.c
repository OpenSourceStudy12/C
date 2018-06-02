#include <stdio.h>

typedef struct student
{
	int num;
	char name[32];
	int age;
}STU,*p_stu; 

char* (*pfun)(char *des,const char *src);
char* my_strcpy2(char *des,const char *src)
{
}
char* my_strcpy3(char *des,const char *src)
{
}
char* my_strcpy(char *des,const char *src)
{
	while(*src!='\0')
		*des++ = *src++;
}
int main()
{	
	char str1[32];
	char str2[20]="hello world";

	if(ocurr(1))
	{
	pfun=my_strcpy;
	}
	if(ocurr(2))
	{
		pfun=my_strcpy2;
	}
	if(ocurr(3))
	{
		pfun=my_strcpy3;
	}
	pfun(str1,str2);
	puts(str1);

}
