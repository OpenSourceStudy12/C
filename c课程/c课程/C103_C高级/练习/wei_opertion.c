#include <stdio.h>
#define BLUE_TEETH_FLAG 0x4
#define CAMRE_FLAG 0x8
int open_blueteeth()
{
	flag=flag|BLUE_TEETH_FLAG;
}
int close_blueteeth()
{
	flag = flag&~(BLUE_TEETH_FLAG)
}
int open_app()
{
	flag|=BLUE_TEETH_FLAG|CAMRE_FLAG;
}
int main()
{
	int flag = 0;
	return 0;
}
