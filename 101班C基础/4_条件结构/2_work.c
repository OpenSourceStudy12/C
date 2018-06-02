/*
1,输入一个字符，判断该字符是否元音字母
a  o  e  i  u


2,输入一个学生的成绩，判断该学生的等级
90--100  优秀
80--90   良好
70--80   中等
60--70   及格
0---60   不及格
其他     无效数字


3,输入三个数作为三角形的三条边，判断该三角形的类型
等边三角形、等腰三角形、直角三角形、等腰直角、普通三角形、不是三角形



4,输入两个整数，判断两个数之间的关系


5,输入三个整数，找出其中的最大值，并输出所有的最大值
a=20,b=30,c=40=====>max=c=40
a=20,b=20,c=20=====>max=a=b=c=20
*/

#include <stdio.h>
int main()
{
		int a,b,c;
		printf("请输入三个整数:\n");
		scanf("%d%d%d",&a,&b,&c);
		if(a>b)
		{
				if(a>c)
				{
						printf("max:a=%d\n",a);
				}
				else if(a<c)
				{
						printf("max:c=%c\n",c);
				}
				else//a=c
				{
                        printf("max:a=c=%d\n",a);
				}
		}
		else if(a<b)
		{
				if(b>c)
				{
						printf("max:b=%d\n",b);
				}
				else if(b<c)
				{
						printf("ma:c=%d\n",c);
				}
				else
				{
						printf("max:b=c=%d\n",b);
				}
		}
		else//a=b
		{
				if(a>c)
				{
						printf("max:a=b=%d\n",a);
				}
				else if(a<c)
				{
						printf("max:c=%d\n",c);
				}
				else
				{
						printf("max:a=b=c=%d\n",c);
				}
		}
}





/*
int main()
{
		int a,b;
		printf("请输入两个数\n");
		scanf("%d%d",&a,&b);
		if(a==b)
		{
				printf("a=b\n");
		}
		else
		{
				if(a>b)
				{
						printf("a>b\n");
				}
				else
				{
						printf("a<b\n");
				}
		}
}
*/
/*
int main()
{
		float a,b,c;
		int dengbian=0,dengyao=0,zhijiao=0;
		printf("请输入三角形的三条边：\n");
		scanf("%f%f%f",&a,&b,&c);
		if(a+b<=c||a+c<=b||b+c<=a)
		{
				printf("不能构成三角形\n");
		}
		else
		{
              if(a==b&&b==c)
			  {
					  dengbian=1;
			  }
			  if(a==b||b==c||a==c)
			  {
					  dengyao=1;
			  }
			  if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)
			  {
					  zhijiao=1;
			  }
			  if(dengbian)
			  {
					  printf("等边三角形\n");
			  }
			  else if(dengyao && zhijiao)
			  {
					  printf("等腰直角\n");
			  }
			  else if(dengyao)
			  {
					  printf("等腰\n");
			  }
			  else if(zhijiao)
			  {
					  printf("直角\n");
			  }
			  else
			  {
					  printf("普通三角形\n");
			  }
		}
		printf("判断完毕\n");
}
*/
/*
int main()
{
		float grade;
		printf("请输入一个学生的成绩:\n");
		scanf("%f",&grade);
		if(grade>=90&&grade <=100)
		{
				printf("优秀\n");
		}
		else if(grade >=80)
		{
				printf("良好\n");
		}
		else if(grade >= 70)
		{
				printf("中等\n");
		}
		else if(grade >= 60)
		{
				printf("及格\n");
		}
		else if(grade >=0 && grade <= 60)
		{
				printf("不及格\n");
		}
		else
		{
				printf("不合法数据\n");
		}
}

*/
/*
int main()
{
		char ch;
		ch=getchar();
		if(ch=='a'||ch=='o'||ch=='e'||ch=='i'||ch=='e')
		{
				printf("是元音\n");
		}
		else
		{
				printf("不是元音\n");
		}
}
*/
/*
int main()
{
		char ch;
		printf("请输入一个字符：\n");
		scanf("%c",&ch);
		if(ch=='a')
		{
				printf("%c  是元音字符\n",ch);
		}
        else if(ch=='o')
		{
				printf("%c 是元音字符\n",ch);
		}
        else if(ch=='e')
		{
				printf("%c 是元音字符\n",ch);
		}
        else if(ch=='i')
		{
				printf("%c 是元音字符\n",ch);
		}
        else if(ch=='u')
		{
				printf("%c 是元音字符\n",ch);
		}
		else
		{
				printf("输入的不是元音字符\n");
		}

}
*/
