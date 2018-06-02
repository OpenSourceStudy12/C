#include <stdio.h>
int fun(char tt[],int pp[]);
int main()
{
	int i,pp[26]={0};
	char tt[50];
	printf("请输入一组字符：");
	for(i=0;i<50;i++)
	{
		scanf("%c",&tt[i]);
		if(tt[i]=='\n')
		{
			break;
		}
        }
	fun(tt,pp);
	for(i=0;i<26;i++)
	{
		printf("%c出现的次数为:%d\n",'a'+i,pp[i]);
	}
	return 0;
}
int fun(char tt[],int pp[])
{
	int i;
	
	for(i=0;i<50;i++)
	{
		if(tt[i]>'a' && tt[i]<'z')
		{
			pp[tt[i]-'a']++;
		}
		if(tt[i]>'A' && tt[i]<'Z')
		{
			pp[tt[i]-'A']++;
		}
	}
	return 0;
}
