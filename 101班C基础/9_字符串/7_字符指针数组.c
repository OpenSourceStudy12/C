#include <stdio.h>
int main()
{
		char *a[5]={"apple","pears","banana","mango","lemon"};
		int i;
		for(i=0;i<5;i++)
		{
				printf("%s ",a[i]);
		}
		printf("\n");
		for(i=0;i<5;i++)
		{
				printf("a[%d]=%p\n",i,a[i]);
		}

		return 0;
}
