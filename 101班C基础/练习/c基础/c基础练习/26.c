#include<stdio.h>

void main()
{
	int num=1;
	int flag_9 = 0,flag_2 = 0,flag_3 = 0,flag_4 = 0,
	    flag_5 = 0,flag_6 = 0,flag_7 = 0,flag_8 = 0;
	while(1)
	{
		if(num % 2 == 1)
			flag_2 = 1;
		if(num % 3 == 0)
			flag_3 = 1;
		if(num % 4 == 1)
			flag_4 = 1;
		if((num+1) % 5 == 0)
			flag_5 = 1;
		if(num % 6 == 3)
			flag_6 = 1;
		if(num % 7 == 0)
			flag_7 = 1;
		if(num % 8 == 1)
			flag_8 = 1;
		if(num % 9 == 0)
			flag_9 = 1;
		
		if(flag_2 && flag_3 && flag_4 && flag_5 && flag_6 &&
		   flag_7 && flag_8 && flag_9)
		{
			printf("鸡蛋有 %d 只\n",num);
			break;
		}
		flag_2 = 0;
		flag_3 = 0;
		flag_4 = 0;
		flag_5 = 0;
		flag_6 = 0;
		flag_7 = 0;
		flag_8 = 0;
		flag_9 = 0;
		num++;

	}

}
