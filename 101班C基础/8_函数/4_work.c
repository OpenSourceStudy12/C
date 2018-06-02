/*
1,设计函数，实现浮点数从小到大的排序

2,设计函数，将所有小写字符转换成大写字符

3,设计一个函数，将一行字符序列有序的插入到另一行有序字符序列中
ads        bxz=====>abdsxz

*/

#include <stdio.h>
void fun(char a[],char b[],int a_size,int b_size)
{
		int i=0,j=0,k;
		while(b[j]!='\n')
		{
			  i=0;
			  while(1)
			  {
					  if(b[j]<=a[i]||a[i]=='\n')
					  {
					       for(k=a_size-1;k>=i;k--)
						    {
									a[k+1]=a[k];
							}
							a[i]=b[j];
							a_size ++;
							break;
					  }
					  i ++;
			  }
			  j ++;
		}
}
int main()
{
		char a[128],b[128];
		char ch;
		int i=0,j=0;
		printf("请输入一行有序字符序列：\n");
		while(1)
		{
				ch=getchar();
				a[i++]=ch;
				if(ch=='\n')
						break;
		}
		printf("请输入任意字符序列:\n");
		while(1)
		{
				ch=getchar();
				b[j++]=ch;
				if(ch=='\n')
						break;
		}
		fun(a,b,i,j);
		printf("a:");
		for(i=0;a[i]!='\n';i++)
		{
				printf("%c",a[i]);
		}
		printf("\n");
		for(i=0;b[i]!='\n';i++)
		{
				printf("%c",b[i]);
		}
		printf("\n");
		return 0;

}
/*
void  fun(char *a,int n)
{
		int i=0;
		for(i=0;i<n;i++)
		{
				if(a[i]>='a'&&a[i]<='z')
				{
						a[i]=a[i]-32;
				}
		}
}

int main()
{
		char a[10]={'a','b','c'};
		fun(a,3);
		int i=0;
		for(i=0;i<3;i++)
		{
				printf("%c",a[i]);
		}
		printf("\n");
		return 0;
}
*/
/*
void sort(float a[],int n)
{
		int i=0,j=0;
		float temp;
		for(i=0;i<n-1;i++)
		{
				for(j=0;j<n-i-1;j++)
				{
						if(a[j]>a[j+1])
						{
								temp=a[j];
								a[j]=a[j+1];
								a[j+1]=temp;
						}

				}
		}
		
}


int main()
{
		float  a[6]={1.34,55,7.8,0,9.8,2};
		sort(a,6);
		int i;
		printf("sorted:\n");
		for(i=0;i<6;i++)
		{
				printf("%.2f ",a[i]);
		}
		printf("\n");
		return 0;
}
*/
