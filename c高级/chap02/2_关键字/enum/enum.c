#include <stdio.h>

enum FILEERROR
{
	OPEN_ERROR,
	NORMAL,
	CLOSE_ERROR,
	WRITE_ERROR,
	READ_ERROR,
};


int fileOperation(int num)
{
	if (num<10)
		return OPEN_ERROR;
	else if(num<20)
		return CLOSE_ERROR;
	else if(num<30)
		return READ_ERROR;
	else if(num<40)
		return WRITE_ERROR;
	else	
		return NORMAL;
}

int main()
{
	int num,ret;
	scanf("%d",&num);
	ret = fileOperation(num);
	if (ret == OPEN_ERROR)
		printf("open error..\n");
	else if(ret == CLOSE_ERROR)
		printf("close error..\n");
	else if(ret == WRITE_ERROR)
		printf("write error..\n");
	else if(ret == READ_ERROR)
		printf("read error..\n");
	else
		printf("be ok ...\n");
	return 0;
}
