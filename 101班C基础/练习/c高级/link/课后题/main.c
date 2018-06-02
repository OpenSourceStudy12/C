#include<stdio.h>
#include"fun.h"

int main()
{
	float a,b;
	char sh[MAX];
	PStu head =NULL;
	head = Listcreat_from_head();
	Listprint(head);
	printf("please input the name of student want to search\n");
	while(getchar() != '\n');
	gets(sh);
	Listsh_name(head,sh);
	printf("please input the score rate want to search(a,b)\n");
	scanf("%f%f",&a,&b);
	Listsh_rate(head,a,b);	
}
