#include <stdio.h>

int fun(char *str,int pp[])
{
	while(*str!='\0')
	{
		if((*str>='a')&&(*str<='z'))
		{
			pp[*str - 'a']++;
		}
		if((*str>='A')&&(*str<='Z'))
		{
			pp[*str-'A']++;
		}
		str++;
	}
	return 0;
}
char* merger(char *str1,char *str2)
{
	static char str[64];
	char *str3=str;
	while(*str1!='\0')
	{
		*str3 = *str1;
		str1++;
		str3++;
	}
	while(*str2!='\0')
	{
		*str3++=*str2++;
	}
	*str3='\0';
	return str;
}
void invertNto0(char *tt)
{
	while(*tt!='\0')
	{
		if(*tt == '\n')
		{
			*tt = '\0';
			break;
		}
		tt++;
	}
}
int main()
{
	char str1[32];
	char str2[32];
	char *pstr;
	fgets(str1,32,stdin);
	fgets(str2,32,stdin);
	invertNto0(str1);
	invertNto0(str2);
	pstr=merger(str1,str2);
	puts(pstr);
}

