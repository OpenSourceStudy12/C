/*
1,设计一个函数，交换两个整型变量的数据

2,设计一个函数，将不及格的学生成绩存储在一个数组里，并通过参数的方式返回不及格学生的人数
int fun(float a[],int size,float b[])
void  fun(flaot a[],int size,float b[],int *count)
3,设计一个函数，求十个学生的平均成绩，最高分，以及最高分下标，通过参数的方式返回

4,设计函数，统计从键盘输入的字符序列的字符个数
int fun(char *a,int size)
void fun(char a[],int size,int *count)
5,设计函数，将从键盘输入的字符序列的所有下标为奇数的字符改成空格

6,设计函数，将从键盘输入的字符序列的所有空格删除

*/
#include <stdio.h>
void  fun(char a[],int size)
{
		int i=0,j;
		while(a[i]!='\n')
		{
				if(a[i]==' ')
				{
						j=i;
						while(a[j]!='\n')
						{
								a[j]=a[j+1];
								j ++;
						}
                        continue;
				}
				i ++;
		}
}
int main()
{
	char a[128];
	char ch;
	int i=0;
	while(1)
	{
			ch=getchar();
			a[i++]=ch;
			if(ch=='\n')
					break;
	}
	fun(a,i);
	i=0;
	while(a[i]!='\n')
	{
			putchar(a[i]);
			i ++;
	}
	putchar('\n');
}

/*
void fun(char *a,int size)
{
		int i;
		for(i=0;i<size;i++)
		{
				if(i%2!=0)
						a[i]=' ';
		}
}
int main()
{
		char a[128];
		char ch;
		int i=0,j;
		while(1)
		{
				ch=getchar();
				if(ch=='\n')
						break;
				a[i++]=ch;
		}
        fun(a,i);
		for(j=0;j<i;j++)
		{
				putchar(a[j]);
		}
		putchar('\n');
		return 0;

}
*/
/*
void fun(char a[],int size,int *count)
{
		int i=0;
		*count=0;
		while(a[i]!='\n')
		{
				(*count)++;
				i ++;
		}
		
}

int main()
{
		char a[128];
		char ch;
		int i=0;
		int count =0;
		while(1)
		{
				ch=getchar();
				a[i++]=ch;
				if(ch=='\n')
						break;
		}
		fun(a,i,&count);
        printf("字符个数为：%d\n",count);
		return 0;
}
*/

/*
void fun(float *a,int size,float *ave,float *grade,int *max_index)
{
		int i;
		*grade=a[0];
		*max_index=0;
		*ave =0;
		for(i=0;i<size;i++)
		{
		    *ave +=a[i];
            if(a[i]>a[*max_index])
			{
					*grade=a[i];
					*max_index=i;
			}
		}
		*ave /= size;
}
int main()
{
		float grade[10]={34.5,67.5,78,89,90,88,64.5,77,90,34.4};
		float ave=0,max=0;
		int max_index;
		fun(grade,10,&ave,&max,&max_index);
		printf("ave=%.2f,max=%.2f,max_index=%d\n",ave,max,max_index);
		return 0;
}
*/
/*
void fun(float a[],int size,float b[],int *count)
{

		int i,j=0;
		*count =0;
		for(i=0;i<size;i++)
		{
				if(a[i]<60)
                 {
						 b[j]=a[i];
						 j ++;
						 (*count) ++;
				 }
		}
}
int main()
{
		float a[10]={12,67,4,89,0,78,98,5,14,99};
		float b[10];
		int count=0,i;
		printf("sizeof(a)=%d\n",sizeof(a));
		fun(a,10,b,&count);
		for(i=0;i<count;i++)
		{
				printf("%.2f ",b[i]);
		}
		printf("\n不及格人数为：%d\n",count);
		return 0;
}
*/
/*
void fun(int *a,int *b)
{
		int temp;
		temp=*a;
		*a=*b;
		*b=temp;
}

int main()
{
		int a=3,b=4;
        printf("before:a=%d,b=%d\n",a,b);
		fun(&a,&b);
		printf("after:a=%d,b=%d\n",a,b);
		return 0;
}
*/
