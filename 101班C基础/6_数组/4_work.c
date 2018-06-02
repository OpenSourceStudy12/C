/*
1,从键盘输入一行字符序列，统计有效字符个数，并将该字符序列存储于数组中输出



2,从键盘输入一行字符序列，统计'a'-'z'每个字符出现的次数，并且存储与数组b[26]
a[128]
'a'------->b[0]
'b'------->b[1]


3,从键盘输入一个字符序列，输出该字符序列的倒置
abcd  ========>dcba

*/

#include <stdio.h>
int main()
{
    char a[128],b[128];
	char ch;
	int i=0,j;
	int n;
	while(1)
	{
			ch=getchar();
			if(ch=='\n')
					break;
			a[i++]=ch;
	}
	for(j=0,n=i-1;j<i;j++,n--)
	{
            b[j]=a[n];
	}
	/*
	for(j=0,n=i-1;j<i/2;j++,n--)
	{
           ch=a[j];
		   a[j]=a[n];
		   a[n]=ch;
	}
	*/

	for(j=0;j<i;j++)
	{
			printf("%c",b[j]);
	}
	printf("\n");

}
/*
int main()
{
		char a[128];
		int b[26]={0};
		char ch;
		int i=0,j;
		while(1)
		{
				ch=getchar();
				if(ch=='\n')
				{
						break;
				}
				a[i]=ch;
				i++;
		}
		for(j=0;j<i;j++)
		{
				if(a[j]>='a'&&a[j]<='z')
                b[a[j]-'a']++;
		}

		for(j=0;j<i;j++)
		{
				printf("%c",a[j]);
		}
		for(j=0;j<26;j++)
		{
				printf("\nb[%d]=%d\n",j,b[j]);
		}

}
*/

/*
int main()
{
		char a[128];
		char ch;
		int i=0,j;
		while(1)
		{
				ch=getchar();
				if(ch=='\n')
				{
						break;
				}
				a[i++]=ch;
		}
        for(j=0;j<i;j++)
		{
				printf("%c",a[j]);
		}
		printf("\n有效个数为:%d\n",i);
		return 0;
}
*/
