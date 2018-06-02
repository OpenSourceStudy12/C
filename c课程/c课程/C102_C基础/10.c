#include<stdio.h>

void fun(char *p1,char *p3)
{   int  i;
    char *p2;
	 char *point;
	 int flag=1;
    while(*p1!='\0')
    	 {
		p2=p1;
		point = p3;
		flag=1;
		if(*p2==*point)
		{
			while((*p2!='\0')&&(*point!='\0'))
			{
				if(*p2!=*point)
				{
					flag = 0;
					break;
				}
				p2++;
				point++;
			}
			if((flag==1)&&(*point=='\0'))
			{
				while(p1<p2)
				{
					*p1='*';
					p1++;
				}
				p1--;
			}
		}
		      	
     p1++;
             }
}
int main()
{   char string[100]={0},point[5]="abc";
    char *p1=string;char *p2=point;
    printf("输入一串字符存到string且string中含有point字符串\n");
    gets(string);
    printf("string字符串是:");
    puts(string);
    fun(string,point);

    puts(string);
}
