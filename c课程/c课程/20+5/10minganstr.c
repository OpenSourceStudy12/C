#include <stdio.h>
#include <string.h>
void func(char string[], char point[]);
int main()
{
	char str[48]={0};
	char point[10]={0};
	gets(str);
	gets(point);
	func(str,point);
	puts(str);
	
	return 0;
}
void func(char string[], char point[])
{
	char *pstr=string;
	char *e_pstr=string;
	char *ppoint;
	int flag = 1;
	while(*pstr != '\0')
	{
		flag=1;
		ppoint=point;
		e_pstr=pstr;
		if(*e_pstr == *ppoint)
		{
			while((*e_pstr!='\0')&&(*ppoint!='\0'))
			{
				if(*e_pstr !=*ppoint)
				{
					flag = 0;
					break;
				}
				e_pstr++;
				ppoint++;
			}
			if((flag != 0)&&(*ppoint=='\0'))
			{
				while(pstr!=e_pstr)
				{
					*pstr='*';
					pstr++;
				}
				pstr--;
				
			}
		}
		
		pstr++;
	}
}