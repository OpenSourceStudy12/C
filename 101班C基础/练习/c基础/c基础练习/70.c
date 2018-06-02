/**************************************************
*ile name:
*function:根据输入求对应的面积
*author:
***************************************************/
#include<stdio.h>
#define PI 3.14

float s_ret(float x,float y);
float s_rand(float d);
float s_san(float a,float h);

void main()
{
	int c;
	do
	{
		printf("求长方形面积1、圆的面积2、三角形的面积3、退出0:\n");
//		c = getchar();
//		getchar();
		scanf("%d",&c);
		if(c == 1)
		{
			float a,b;
			printf("请输入长方形的边长a和b:\n");
			scanf("%f%f",&a,&b);
			printf("长方形面积s=%.2f\n",s_ret(a,b));
//			getchar();	
		}
		else if(c == 2)
		{
			float d;
			printf("请输入圆的半径d:\n");
			scanf("%f",&d);
			printf("圆的面积s=%.2f\n",s_rand(d));
//			getchar();	
		}
		else if(c == 3)
		{
			float a,h;
			printf("请输入三角形的底a和高h:\n");
			scanf("%f%f",&a,&h);	
			printf("三角形的面积s=%.2f\n",s_san(a,h));
//			getchar();	
		}
		else if(c == 0)
			break;
		else
			printf("input error!\n");
	}while(1);
}

float s_ret(float x,float y)
{
	return x*y;

}

float s_rand(float d)
{
	int s;
	s = PI*d*d;
	return s;
}

float s_san(float a,float h)
{
	return a*h/2;

}












