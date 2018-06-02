/*****************************************************
*file name:
*function:将一个整型的数字转换成一个字符串
*author:
*********************************************************/
#include<stdio.h>
void fun1(int t,char *ch);
void fun2(char *ch);

void main()
{
	int t;
	char ch[10];
	printf("请输入一个整数:\n");
	scanf("%d",&t);
	fun1(t,ch);
	fun2(ch);
	puts(ch);
}

void fun1(int t,char *ch)
{
	int i,n;
	do
	{
		n = t%10;
		t /=10;
		*ch++ = (n+48);
	}while(t);
	*ch = '\0';

}

void fun2(char *ch)
{		  
   	char *sh,temp;		   
	int n=0;
	while(*(ch+n) != '\0')	     
 	{	     
		n++;			       
	} 
 	for(sh=ch+n-1;ch<sh;ch++,sh--)		      
	{ 
		temp=*ch;			        
    		*ch=*sh;		
    		*sh=temp;		
   	}
}

