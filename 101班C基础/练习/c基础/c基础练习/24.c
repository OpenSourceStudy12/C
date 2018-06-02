/*******************************
*file name:
*function:
*author:L-R-H
*******************************/

#include<stdio.h>

void main()
{
	char c;
	int a=0,b=0,e=0,d=0;
	printf("输入一串字符:\n");
	c = getchar();
	while(c != '\n')
	{
		
		if(c >= 'a' && c <= 'z')
			a++;
	        else if(c >= 'A' && c <= 'Z')
			b++;
		else if(c >= '0' && c <= '9')
			e++;
		else 
			d++;	
		c = getchar();
	}
	printf("小写字符数有:%d\n",a);
	printf("大写字符数有:%d\n",b);
	printf("数字符数有:%d\n",e);
	printf("其它字符数有:%d\n",d);

}
