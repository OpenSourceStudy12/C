#include<stdio.h>
#include<string.h>
#define STR_MAX 30
void strrev(char *str);
void invertTo0(char s[]);
int main()
{
	char str[STR_MAX]={0};
	printf("please input:\n");
	fgets(str,STR_MAX,stdin);
	invertTo0(str);
	strrev(str);
	puts(str);
}

void strrev(char *str)
{
	int num=strlen(str);
	char temp;
	char *strat=str;
	char *end=str+num-1;

	for(;strat<=end;strat++,end--)
		{
			temp=*strat;
			*strat=*end;
			*end=temp;
		}
}

void invertTo0(char s[])
{
	int i=0;
	while(s[i]!='\0')
	{
		if(s[i]=='\n')
		{
			s[i]='\0';
		}
		i++;
	}
}
