/******************************************
*file name:
*function:
*author:L-R-H
********************************************/
#include<stdio.h>

void main()
{
	int yuan,jiao_5,jiao_1,count = 0;
	for(yuan = 0;yuan <= 20;yuan++)
	{
		for(jiao_5 = 0;jiao_5 <= 40;jiao_5++)
		{
			for(jiao_1 = 0;jiao_1 <= 200;jiao_1++)
				if(10*yuan + 5*jiao_5 + jiao_1 == 200)
				{
					count++;
					printf("%d个1元%d个5角%d个1角\n",
						yuan,jiao_5,jiao_1);
				}
		}
	
	}

	printf("一共有%d种组合\n",count);
}
