/*
注：以下练习用指针实现
1,定义一个数组存储5种商品的价格，数据从键盘输入，输出每种商品的价格

2,定义一个数组存储10个学生的成绩，找出最高分和最低分

3,定义一个数组存储6个整数，分别找出最小值和最大值的下标

4,从键盘输入一行字符序列，判断是否是回文序列

5,从键盘输入一行字符序列，反转该字符序列并输出

6,定义一个数组存储4个学生的语文、数学、英语成绩，定义一个数组指针将数据写入数组，打印外层数组每个元素的起始地址，内层数组每个元素的起始地址以及每个元素对应的数据

7,存储10个学生的成绩，按照从高到底的顺序输出
*/
#include <stdio.h>
int main()
{
		float a[10]={56,0,98,73,12,5,67,8,9,88};
		float *p=&a[0],temp;
		int i,j;
		for(i=0;i<9;i++)
		{
				for(j=0;j<10-i-1;j++)
				{
						if(*(p+j)<*(p+j+1))
						{
								temp=*(p+j);
								*(p+j)=*(p+j+1);
								*(p+j+1)=temp;
						}
				}
		}

		for(i=0;i<10;i++)
		{
				printf("%.2f ",p[i]);
		}
		printf("\n");
}
/*
int main()
{
		float a[4][3];
		int i,j;
        float (*p)[3]=a;//p=&a[0]
		for(i=0;i<4;i++)
		{
		        printf("请输入第%d个学生的成绩:\n",i+1);
				for(j=0;j<3;j++)
				{
						scanf("%f",*(p+i)+j);
				}
		}
        printf("\n\n外层数组的每个元素的起始地址:\n");
		for(i=0;i<4;i++)
		{
				printf("p+%d=%p\n",i,p+i);
		}
		printf("\n\n内层数组每个元素的起始地址:\n");
		for(i=0;i<4;i++)
		{
				for(j=0;j<3;j++)
				{
						printf("*(p+%d)+%d=%p\n",i,j,*(p+i)+j);
				}
		}
        printf("内层数组的每个元素对应的数据：\n");
		printf("学号\t语文\t数学\t英语\n");
		for(i=0;i<4;i++)
		{
				printf("%d\t",i+1);
				for(j=0;j<3;j++)
				{
                   printf("%.2f\t",a[i][j]);
				}
				printf("\n");
		}
}
*/
/*
int main()
{
		char a[128];
		char ch,*start=NULL,*end=NULL;
		int i=0,j;
		while(1)
		{
				ch=getchar();
				if(ch=='\n')
						break;
				a[i++]=ch;
		}
		for(start=a,end=a+i-1;start<end;start++,end--)
		{
				ch=*start;
				*start=*end;
				*end=ch;
		}

		for(j=0;j<i;j++)
		{
				printf("%c",a[j]);
		}
		printf("\n");
		return 0;


}
*/
/*
int main()
{
		char a[128];
		char ch;
		int i=0;
		char *start=NULL,*end=NULL;
		while(1)
		{
				ch=getchar();
				if(ch=='\n')
						break;
				a[i++]=ch;
		}
		for(start=a,end=a+i-1;start<end;start++,end--)
		{
				if(*start != *end)
						break;
		}
		if(start>=end)
		{
				printf("YES!\n");
		}
		else
		{
				printf("NO!\n");
		}
		return 0;
}
*/
/*
int main()
{
		int a[6]={1,45,0,91,189,6};
		int *p=a;
		int min_index=0,max_index=0;
        int i=0;
		while(i<6)
		{
				if(p[min_index]>p[i])
				{
						min_index=i;
				}
				if(p[max_index]<p[i])
				{
						max_index=i;
				}
				i ++;
		}
		printf("max_index=%d,min_index=%d\n",max_index,min_index);
}
*/
/*
int main()
{
		float a[10]={67,78,8,9,0,90,89,96,74,72};
		float *p=&a[0];
		float min=*p,max=*p;
		while(p<a+10)
		{
				if(min>*p)
						min=*p;
				if(max<*p)
				        max=*p;
				p++;
		}
		printf("max:%.2f,min=%.2f\n",max,min);
}
*/
/*
int main()
{
		float a[5];
		float *p=NULL;
		int i;
		p = a;//p=&a[0]
	    while(p<a+5)
		{
				scanf("%f",p);
				p ++;
		}
        for(p=a,i=0;i<5;i++)
		{
			//	printf("*(p+%d)=%.2f\n",i,*(p+i));
			printf("p[%d]=%.2f\n",i,p[i]);
		}

}
*/
