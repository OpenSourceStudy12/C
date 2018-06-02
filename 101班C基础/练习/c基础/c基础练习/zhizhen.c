#include<stdio.h>

void main()
{
	int num = 10;
	int *ptr = &num;
        printf("num = %d\n",num);	
        printf("&num = %p\n",&num);	
        printf("*ptr = %d\n",*ptr);	
        printf("ptr = %p\n",ptr);	

}
