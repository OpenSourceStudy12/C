/*********************************
*file name:
*function:
*author:
***********************************/

#include<stdio.h>

void main()
{
	int count = 0;
	char c;
	printf("请输入一串字符:\n");
	c = getchar();
	while(c != '\n')
	{
		if(c == ' ')
			count++;
		c = getchar();
	
	}
	printf("空格数是: %d \n",count);

}
