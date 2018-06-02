#include <stdio.h>
int function(int a)
{
		if(a==1)
		{
				return 1;
		}
		else
		{
				a= a*function(a-1);
				return a;
		}
}

int main()
{
		int re;
		re=function(5);
		printf("%d",re);
		return 0;
}


