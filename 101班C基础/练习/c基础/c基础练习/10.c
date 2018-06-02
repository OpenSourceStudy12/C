#include<stdio.h>

void main()
{
	float a,b,c,d;
	int e,i=0,j=0;
	printf("请输入两个小数:\n");
	scanf("%f%f",&a,&b);
	c = (a+b) / 2.0;
	d = c*100;
        printf("%f\n",c);
	do
	{
		i++;
		d = d * 10;
		e =((int)d) % 10;
		if(e<=3)
		{
			c =(int)(c*100);
			c = c/100;
			break;
		}
		if(e>=4)
		{
			if(e>=5)
			{
				c =(int)(c*100)+1;
				c = c/100;
				break;
			}	
			j++;	
		}
	}
	while((float)(int)d != d);
	if(i == j)
	{

	      c = (int)(c*100);
	      c = c/100;
	}
	printf("c平均:%f\n",c);
	printf("c平均:%.2f\n",c);


}

