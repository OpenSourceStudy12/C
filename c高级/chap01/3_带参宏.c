#include <stdio.h>

int main()
{
	int i=1;
	int y;
	while(i<=5)
	{
		y = i++;//y = 1;
		y = y * i++;//i = 1*2;
		printf("%d\n",y);
	}
	return 0;
}
