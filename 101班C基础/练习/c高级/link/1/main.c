#include<stdio.h>
#include"fun.h"

int main()
{
	F_node movie;
	List head;
	list_init(&head);
	printf("please input file name:\n");
	gets(movie.name);
	while(movie.name[0] != '\0')
	{
		printf("please input rate:\n");
		scanf("%d",&movie.rate);
		while(getchar() != '\n');
		if(!list_add(&head,movie))
			break;
		printf("please input file name again:\n");
		gets(movie.name);
	}
	list_display(head);
	return 0; 
}
