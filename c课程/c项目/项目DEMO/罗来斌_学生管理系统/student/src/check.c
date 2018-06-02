#include "check.h"
/*
* 接受用户的字符，并判断字符的长度
* 正确则返回1，否则返回0
*/


int is_int(char *line)
{
	char *p=line;
	
	while(*p!='\0')
	{
		if(*p>'9'||*p<'0')
		{
			printf("请入整数\n");
			return 0;
		}
		p++;
	}
	return 1;
}

int is_number(int min,int max)
{
	char *p;
	int number=0;
	int i=0;
	char line[4];
	
	scanf("%s",line);
	if(is_int(line)==0)
	{
		return -111;
	}
	for(p=line;*p!='\0';p++)
	{
		i=*p-48;
		number=number*10+i;
	}
	if(number>max||number<min)
	{
		printf("请输入%d~%d的整数\n",min,max);
		return -111;
	}
	return number;
}

int get_number(int min,int max)
{
	int number;
   
	number=is_number(min,max);
	while(number==-111)
	{
		number=is_number(min,max);
	}
	return number;
}





int get_password(char *line,int maxlenght)
{
	char *p=line;
	unsigned  int count=0;

	while(1)
	{
		set_keypress();	
		echo_off();	
		*p=getchar();	
		putchar('*');
		fflush(stdin);
		fflush(stdout);
	//printf("Test: getchar=%c\n", ch);
		echo_on();	
		
		count++;
          
		if(count>=maxlenght)
		{
			printf("输入的太长，长度1～%d\n",maxlenght-2);
			while(getchar()!='\n')
			{
			}
			memset(line,0,maxlenght-1);
			return 0;
		}
		if(*p=='\n')
		{
			*p='\0';
			break;
		}
		else
		{
			p++;
		}
	}
	return 1;	
}



int get_char(char *line,unsigned int maxlenght)
{
   char *p=line;
   unsigned  int count=0;

   while(1)
   {
      *p=getchar();
      count++;
          
      if(count>=maxlenght)
      {
          printf("输入的太长，长度1～%d\n",maxlenght-2);
          while(getchar()!='\n')
          {
          }
          memset(line,0,maxlenght-1);
          return 0;
      }
      if(*p=='\n')
      {
            *p='\0';
             break;
       }
      else
      {
           p++;
      }
   }
   return 1;
}











