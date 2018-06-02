/********************************************
*file name:
*function:输入三个整数x,y,z，请把这三个数由小到大输出
*author:
********************************************/

#include<stdio.h>

void main()
{
/*	int x,y,z,t;
	printf("输入三个整数:\n");
	scanf("%d%d%d",&x,&y,&z);
	if(x>y)
	{
		t = x;
		x = y;
		y = t;
		if(x>z)
		{
			t = x;
			z = z;
			z = t;
			if(y>z)
			{
				t = y;
				y = z;
				z = t;
			
			}
		}
		else
		{
			if(y>z)
			{
				t = y;
				y = z;
				z = t;
			
			}
		
		}
	}
	else
	{
		if(x>z)
		{
			t = x;
			x = z;
			z = t;
			if(y>z)
			{
				t = y;
				y = z;
				z = t;
			
			}
		}
		else
		{
			if(y>z)
			{
				t = y;
				y = z;
				z = t;
			
			}
		
		}

		
	}
	printf("%d %d %d\n",x,y,z);
*/

/*	int x,y,z,t;
	int *px,*py,*pz;
	px = &x;
	py = &y;
	pz = &z;
	printf("输入三个整数:\n");
	scanf("%d%d%d",px,py,pz);
	if(*pz > *py)
	{
		t = *px;
		*px = *py;
		*py = t;
	}
	if(*px > *pz)
	{
		t = *px;
		*px = *pz;
		*pz = t;
	
	}
	if(*py > *pz)
	{
		t = *py;
		*py = *pz;
		*pz = t;
	
	}
	printf("\n%d %d %d\n",*px,*py,*pz);
*/

	int x,y,z;
	int *px,*py,*pz,*p;
	px = &x;
	py = &y;
	pz = &z;
	printf("输入三个整数:\n");
	scanf("%d%d%d",px,py,pz);
	if(*px > *py)
	{
		p = px;
		px = py;
		py = p;
	
	}
	if(*px > *pz)
	{
		p = px;
		px = pz;
		pz = p;
	
	}
	if(*py > *pz)
	{
		p = py;
		py = pz;
		pz = p;
	
	}
	printf("%d %d %d\n",*px,*py,*pz);




















}
