#include<string.h>
//#include"fun.h"

void str_deal(char *chr,char *ch)
{
	int i=0;
	char *p;
	p = chr;
	while(i < strlen(chr))
		ch[i++] = *p++;
        p--;
	do
	{
		ch[i++] = *p;	
	}while(p-- > chr);
	ch[i]='\0';

}
