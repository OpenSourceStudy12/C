#include "str.h"


void strDeal(char *p)
{
	int i,j;
	int len = strlen(p);
	for(i=len,j=len;j>0;j--,i++)
	{
		p[i] = p[j-1];
	}
	p[i] = '\0';
}


