#include <stdio.h>

#define S(a,b) a*b
#define MIN(a,b) a<b?a:b 

int main()
{
	int min;
	int area;
	area = S(4,7);
	min = MIN(4,9);
	printf("area = %d\n",area);
	printf("min=%d\n",min);
	return 0;
}
