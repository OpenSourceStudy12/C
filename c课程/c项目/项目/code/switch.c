
#include <stdio.h>


int main()
{
	int x=5, y=5, z = 1, a;

	switch (x == y)
	{
		case 1:
			a = 2;
		case 2:
			switch (z)
				case 1:
					a += 1;
					break;
				case 2:
					a += 2;
				default:
					break;
		case 0:
			a *= 10;
	}

	printf("%d", a);
}





