#include<stdio.h>
#include"bittree.h"


int main()
{
	PTreenode root = NULL;	
	root = bittree_creat(root);
	printf("先序:\n");
	bittree_print_pre(root);
	printf("\n中序:\n");
	bittree_print_mid(root);
	printf("\n后序:\n");
	bittree_print_tail(root);
	putchar('\n');
	
        
}
