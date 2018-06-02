/*************************************************
*file name:
*function:
*author:
**************************************************/
#include<stdio.h>
void sort(char *p,int m,char *q,int n);

void main()
{
	char ch,source[20];
	char tagetar[500]={'a','c','d','e','e','f','g',
			   'j','j','k','l','o','p','q',
			   'r','w','x','x','y','z','\0'};
	int i=0,j=0;
	printf("请输入一串字符序列:\n");
/*	while(1)
	{
		ch=getchar();
		if(ch == '\n')
			break;
		taretar[i++]=ch;
	
	}
*/
	while(tagetar[i] != '\0')
	{
		printf("%c",tagetar[i]);
		i++;
	}
	putchar('\n');

	printf("输入一串字符序列:\n");
	while(1)
	{
		ch=getchar();
		if(ch == '\n')
			break;
		source[j++]=ch;
	
	}
	
	sort(tagetar,i,source,j);
	
	printf("排序后字符序列为:\n");
	i=0;
	while(1)
	{
		printf("%c",tagetar[i]);
		if(tagetar[i] == '\0')
			break;
		i++;
	
	}
	putchar('\n');
	
}


void sort(char *p,int m,char *q,int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m++ +1;j++)
		{
			if(q[i]>=p[j] && q[i]<p[j+1]||q[i]>=p[j] && p[j+1]=='\0')
			{
				for(k=m;k>=j+1;k--)
					p[k+1] = p[k];
				p[j+1] = q[i];
				break;
			}
		
		}
	
	}

}







