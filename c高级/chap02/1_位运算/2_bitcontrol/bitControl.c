#include <stdio.h>
#include "bitControl.h"

int bitSet0(int x, int y)
{
	int mask;
	mask = ~(0x1<<y);
	x &= mask;
	return x;
}

int bitSet1(int x,int y)
{
	int mask;
	mask = 0x1<<y;
	x |= mask;
	return x;
}

int bitSet_f(int x, int y, int n)
{
	int mask;
	mask = (~((~0)<<n))<<y;
	return x^mask;
}

void printf_binary(int num)
{
	int mask,i;	
	mask = 1<<31;//构造一个最高位是１，其余位全是0的整数.

	for(i=0;i<32;i++)
	{
		if(num & mask)
			putchar('1');
		else
			putchar('0');
		num = num << 1;
		if((i+1)%4 == 0)
			putchar(',');
	}
	putchar('\b');
	putchar(' ');
	putchar('\n');
}
