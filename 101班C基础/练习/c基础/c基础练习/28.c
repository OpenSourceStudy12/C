/*********************************
*file name:
*function:
*author:L-R-H
**********************************/
 #include<stdio.h>

void main()
{
	int i,a,b,c,count = 0;
	for(i = 1;i <= 1000;i++)
	{
		a = i /100;
		b = i % 100 / 10;
		c = i % 10;
		if(a*a*a + b*b*b + c*c*c == i)
		{	
			printf("% 4d ",i);
			count++;		
		}
		if(count % 10 == 0)
			putchar('\n');
	}
	putchar('\n');

}
