#include<stdio.h>
#include"tree_child.h"

int main()
{
	char sh;
	PCT tree = tree_child_creat();
	tree_print(tree);
	printf("请输入想要查找孩子的数据:\n");
	//getchar();
	scanf("%c",&sh);
	tree_child_search(tree,sh);
}
