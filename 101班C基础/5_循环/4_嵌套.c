#include <stdio.h>
/*
1,外层循环1次，内层循环一个周期

2,在不影响功能的情况下，尽量将循环次数少的放在外层，循环次数多的放在内层

3,在嵌套循环中，break只能跳出一层循环
*/

int main()
{
		int i,j;
		for(i=0;i<3;i++)
		{
				for(j=0;j<5;j++)
				{
						if(j==3)
						{
								//break;
								continue;
						}
					    
						printf("i=%d,j=%d\n",i,j);
						
				}
		}
		return 0;

}
