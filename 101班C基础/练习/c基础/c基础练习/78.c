/***************************************************
*file name:
*function:设计函数，将一个字符串按照从小到大的顺序排序
*author:
****************************************************/
#include<stdio.h>
void sort(char *p);
void main()
{
	char ch[100];
	printf("请输入一行字符串:\n");
	gets(ch);
	sort(ch);
	puts(ch);

}

void sort(char *p)
{
	int i,j;
	char *ch=p,temp;
	while(*ch++ != '\0');
//	i=ch - p;
	for(i=0;i<ch-p-2;i++)
	{
		for(j=0;j<ch-p-2-i;j++)
		{
			if(p[j] > p[j+1])
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;			
			}
		}
	
	}
}
