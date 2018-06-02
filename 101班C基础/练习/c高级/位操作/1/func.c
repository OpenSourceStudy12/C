#include<stdio.h>
#include"func.h"

int setBit0(int x,int y)
{
	return x &= ~(1<<y);

}

int setBit1(int x,int y)
{
	return x |= 1<<y;

}

int setBit_f(int x,int y,int n)
{
	int t=0,i;
	for(i=y;i<(n+y);i++)
	{
		t += 1<<i;
	}	
	//t=(~((~0)<<n))<<y;
	return x ^= t;
}
