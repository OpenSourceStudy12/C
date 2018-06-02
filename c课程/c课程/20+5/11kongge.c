#include <stdio.h>
#include <string.h>
char del_space(char *str);
int main()
{
	char str[30];
	int i;
	fgets(str,sizeof(str),stdin);
	for(i=0;i<sizeof(str);i++)
	{
		if(str[i]=='\n')
		{
			str[i]='\0';
			break;
		}
	}
	del_space(str);
	puts(str);
	printf("%d",strlen(str));
	return 0;
}
char del_space(char *str)
{
	char *p,*q;
	for(p=str;*p!='\0';p++)
	{
		if(*p==' ')
		{
         q=p;
			while(*q!='\0')
			{
				*q=*(q+1);
				q++;
			}
		}
	}
	return *str;
}
