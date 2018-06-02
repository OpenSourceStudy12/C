#include<stdio.h>
#include<string.h>

void main()
{
	char ch1[] = {'a','f','f',' ','e'};
	char ch2[] = {'a','f','f',' ','e','\0'};
	char ch3[6] = {'a','f','f',' ','e'};
	char ch4[6] = {'a','f','f',' ','e','\0'};
	char ch5[13] = "liao rong hui";

	printf("sizeof(ch1) is %d\n",sizeof(ch1));
	printf("sizeof(ch2) is %d\n",sizeof(ch2));
	printf("strlen(ch2) is %d\n",strlen(ch2));
        
	printf("sizeof(ch3) is %d\n",sizeof(ch3));
	printf("sizeof(ch4) is %d\n",sizeof(ch4));
	printf("sizeof(ch5) is %d\n",sizeof(ch5));
}
