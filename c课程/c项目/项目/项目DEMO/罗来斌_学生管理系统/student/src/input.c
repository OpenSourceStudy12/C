


#include "input.h"

/*input number*/
void get_string(char number[],int n)
{ 
  char *pstr=number;
   do
   {
      while(get_char(pstr,n)==0);
   }while(strncmp(pstr,"",n)==0);
  
}

int get_interget(int low,int hight)
{
    int number;
    scanf("%d",&number); 
  
    while(number<low ||number>hight)
    {      
        printf("please input %d~%dinterget\n",low,hight);
        scanf("%d",&number);
        while(getchar()!='\n');
    }  
    return number;
}



