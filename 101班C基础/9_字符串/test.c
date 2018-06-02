#include <stdio.h>
#include <string.h>
int main()
{
		char a[]="ab";
		char b[]="abc";
		printf("%u\n",strlen(a)-strlen(b));
		if(strlen(a)-strlen(b)>0)
		{
				printf("a>b\n");
		}
		else
		{
				printf("a<=b\n");
		}
		return 0;
}
