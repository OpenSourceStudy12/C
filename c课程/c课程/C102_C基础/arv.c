#include <stdio.h>
#define STU_NUM	5
int main()
{
 	char str[100]={0};
	char ch;
	char *p=str,*start=NULL,*end=NULL;
	int num=0,flag=0;
	while((ch=getchar())!='\n')
	{
		num++;
		*p++=ch;
	}
	start=str;
	end=str+num-1;
	while(start<=end)
	{
		if(*start!=*end)
		{
			flag=1;
			break;
		}
		start++;
		end--;
	}
	if(flag == 1)
	{
		printf("不是回文\n");
	}
	else
	{
		printf("shi hui wen\n");
	}
}
