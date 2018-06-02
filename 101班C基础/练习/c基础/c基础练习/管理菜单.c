/*
1, unsigned int,   my_pow()

2,设计函数，求一个整型和一个浮点型数的平均数

3,设计函数，求两个整型数中的最小数


4,
*/

#include <stdio.h>
void  menu()
{
		printf("1,长方形\n");
		printf("2,三角形\n");
		printf("3,圆形\n");
		printf("4,退出\n");
		printf("请输入你的选择\n");
}

float  changfang(float a,float b)
{
		return a*b;
}

float  sanjiao(float a,float b)
{
		return 1.0/2*a*b;
}

float  yuan(float r)
{
		return 3.14*r*r;
}

int main()
{
		int flag=1;
		int select;
		float a,b,re;
		while(flag)
		{
             menu();
			 scanf("%d",&select);
			 switch(select)
			 {
					 case 1:
                     printf("请输入长方形的长和宽：\n");
					 scanf("%f%f",&a,&b);
					 re=changfang(a,b);
					 printf("长方形面积为：%.2f\n",re);
					 break;
					 case 2:
                     printf("请输入三角形的底和高：\n");
					 scanf("%f%f",&a,&b);
					 re=sanjiao(a,b);
					 printf("三角形面积为：%.2f\n",re);
					 break;
					 case 3:
                     printf("请输入圆的半径：\n");
					 scanf("%f",&a);
					 re=yuan(a);
					 printf("圆形面积为：%.2f\n",re);
					 break;
					 case 4:
					 flag=0;
					 break;
                     default:
					 printf("输入有误，请重新输入:\n");
			 }
		}
}

/*
int func(int a,int b)
{
		return a>b?b:a;
}
int main()
{
		int a,b,re;
		scanf("%d%d",&a,&b);
		if(a==b)
		{
				printf("a==b\n");
		}
		else
		{
                re=func(a,b);
				printf("最小值为：%d\n",re);
		} 
		return 0;
}
*/
/*
float func(int a,float b)
{
		return (a+b)/2;
}

int main()
{
		int a;
		float b,re;
		scanf("%d,%f",&a,&b);
        re=func(a,b);
        printf("re=%f\n",re);
		return 0;
}
*/





/*
unsigned int my_pow(unsigned int x,unsigned int y)
{
		int i,re=1;
		if(x==0)
		{
               printf("无效数据！\n");
			   return 0;
		}
		if(y==0)
		{
				re=1;
		}
		else
		{
                 for(i=1;i<=y;i++)
				 {
						 re *= x;
				 }
		}
		return re;
}


int main()
{  
      unsigned  int x,y,re;
	  printf("请输入数据:\n");
	  scanf("%d%d",&x,&y);
	  re=my_pow(x,y);
	  printf("re=%d\n",re);
	  return 0;
}
*/
