/********************************************************
*file name:
*function:字符常用函数
*author:L-R-H
*********************************************************/
#include<stdio.h>
int my_strlen(const char *p);
void my_strcpy(char *tar,const char *src);
void my_strcat(char *tar,const char *src);
int my_strcmp(const char *p,const char *q);
	
int  main()
{
	int k;
	char p[100],q[100];
	printf("请输入一行字符串p:\n");
	gets(p);
	printf("请再输入一行字符串q:\n");
	gets(q);
	printf("lenth of p :%d\n",my_strlen(p));
	printf("lenth of q :%d\n",my_strlen(q));

//	my_strcpy(p,q);
//	puts(p);
	
//	my_strcat(p,q);
//	puts(p);

	k=my_strcmp(p,q);
	printf("p,q大小:%d\n",k);
	return 0;
}

int my_strlen(const char *p)
{
	int t=0;
	while(*p != '\0')
	{
		t++;
		p++;
	}
	return t;
}

void my_strcpy(char *tar,const char *src)
{
	do
	{
		*tar=*src;
		tar++;
		src++;
	
	}while(*src != '\0');
	*tar='\0';
}

void my_strcat(char *tar,const char *src)
{
	while(*tar != '\0')
	tar++;
	while(*src != '\0')
	{
		*tar=*src;
		tar++;
		src++;	
	}
	*tar='\0';
}

int my_strcmp(const char *p,const char *q)
{
	for(;*p !='\0' || *q != '\0';p++,q++)
	{
		if(*p > *q)
			return 1;
		else if(*p < *q)
			return -1;
		else 
			continue;
	
	}
	return 0;

}

