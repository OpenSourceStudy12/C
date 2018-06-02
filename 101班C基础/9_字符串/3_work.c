/*
1,设计函数，将一个字符串按照从小到大的顺序排序

2,设计一个函数，将一个字符串反转

3,将一个整型的数字转换成一个字符串
123------》123

4，设计一个函数，将s指向的字符串的所有下标为偶数的字符改成'*'


5,设计一个函数，将一个字符串插入到另一个字符串的最大字符后面
asfj    hjklds

*/
#include <stdio.h>
#include <string.h>
void fun6(char s1[],char s2[])
{
		int i=0,max_index=0,j;
		int len = strlen(s2);
		while(s1[i]!='\0')
		{
				if(s1[i]>s1[max_index])
						max_index=i;
				i ++;
		}
		for(j=strlen(s1);j>max_index;j--)
		{
				  s1[j+len]=s1[j];
		}
		strncpy(s1+max_index+1,s2,len);
}

void fun5(char a[])
{
		int i=0;
		while(a[i]!='\0')
		{
				if(i%2==0)
				{
						a[i]='*';
				}
				i++;
		}
}
void fun1(char a[])
{
		int i=0,j=0;
		int len;
		char ch;
		len=strlen(a);
		for(i=0;i<len-1;i++)
		{
				for(j=0;j<len-i-1;j++)
				{
						if(a[j]>a[j+1])
						{
                              ch=a[j];
							  a[j]=a[j+1];
							  a[j+1]=ch;
						}
				}
		}

}

void  fun2(char a[])
{
		int len,i=0,j;
		len=strlen(a);
		char ch;
		for(j=len-1,i=0;i<j;i++,j--)
		{
				ch=a[i];
				a[i]=a[j];
				a[j]=ch;
		}
}


void fun3(char a[],int  n)
{
		int value,i=0;
		while(n)
		{
				value=n%10;
				a[i++]=value+'0';
				n /= 10;
		}
        a[i]='\0';
		fun2(a);
}

void  fun4(char a[],int n)
{
		sprintf(a,"%d",n);
}

int main()
{
		char a[128],b[128];
		printf("请输入一行字符串：\n");
		gets(a);
		printf("请再输入一行字符串:\n");
		gets(b);
		fun6(a,b);
		printf("a:%s,b:%s\n",a,b);
		return 0;
}
