#include <stdio.h>
#include "operation.h"
double operation(int a, int b)
{
#ifdef COM_A
	return 1.0/a+1.0/b;
#endif
#ifdef COM_B
	return (double)a/b+(double)b/a;
#endif
#ifdef COM_C
	return (double)a*a/b;
#endif
}
