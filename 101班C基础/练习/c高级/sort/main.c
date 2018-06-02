#include<stdio.h>
#include"sort.h"

int main()
{
	int num[1000];
	int i;
	for(i=0;i<1000;i++)
		num[i] = rand()%1000;
	//select_sort(num,1000);
	bubble_sort(num,1000);
	for(i=0;i<1000;i++)
		printf("%4d",num[i]);
	putchar('\n');
}
