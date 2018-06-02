#include <stdio.h>
int function();
int main()
{
	int n;
	n = function();
	printf("%d\n",n);
	return 0;
}
int function()
{
	int i;
	i=0;
	while(1)
	{
		i++;
		if(i%2==1&&i%3==2&&i%4==3&&i%5==4)
		{
			break;
		}
	}
	return i;
}
