/*
重写  strlen(),strcpy(),strcat(),strcmp()

*/


#include <stdio.h>
#include <string.h>

/*
int my_strcmp(const char *s1,const char *s2)
{
		int i=0;
		while(s1[i]!='\0'&&s2[i] !='\0')
		{
				if(s1[i]>s2[i])
				{
						return 1;
				}
				else if(s1[i]<s2[i])
				{
						return -1;
				}
				i ++;
		}
		if(s1[i]=='\0'&&s2[i]!='\0')
		{
				return -1;
		}
		else if(s1[i]!='\0'&&s2[i]=='\0')
		{
				return 1;
		}
		else
		{
				return 0;
		}
}
*/
int my_strcmp(const char *s1,const char *s2)
{
		int i=0;
		while(s1[i]!='\0' || s2[i]!='\0')
		{
				if(s1[i]>s2[i])
						return 1;
				else if(s1[i]<s2[i])
						return -1;
				i ++;
		}
		return 0;
}

int main()
{
		char s1[128],s2[128];
		printf("请输入两个字符串：\n");
		gets(s1);
		gets(s2);
		printf("%d\n",my_strcmp(s1,s2));
		return 0;
}






/*
char *my_strcat(char des[],const char src[])
{
	    int i=0,j=0;
		while(des[i]!='\0')
		{
				i ++;
		}
		while(src[j]!='\0')
		{
				des[i]=src[j];
				i ++;
				j ++;
		}
		des[i]='\0';
		return des;
}
int main()
{
		char src[128],des[128];
		printf("请输入源字符串：");
		gets(src);
		printf("请输入目标字符串:");
		gets(des);
		printf("src:%s,des:%s\n",src,des);
		my_strcat(des,src);
		printf("src:%s,des:%s\n",src,des);
		return 0;
}
*/


/*
char *my_strcpy(char *des,const char *src)
{
		int i=0;
		while(src[i]!='\0')
		{
				des[i]=src[i];
				i ++;
		}
		des[i]='\0';
		return des;
}

int main()
{
		char src[128],des[128];
		printf("请输入源字符串：");
		gets(src);
		printf("请输入目标字符串：");
		gets(des);
		printf("before:src:%s,des:%s\n",src,des);
		my_strcpy(des,src+3);
		printf("after:src:%s,des:%s\n",src,des);
		return 0;

}
*/
/*
int main()
{
		char a[5]="abcd";
		char b[7]="helloo";
		printf("before:a=%s,b=%s\n",a,b);
		strcpy(a,b);
		printf("after:a=%s,b=%s\n",a,b);
        printf("a:%p,b:%p\n",a,b);
		return 0;
}
*/

/*
int my_strlen(const char *s)
{
		int i=0;
		while(s[i]!='\0')
		{
				i ++;
		}
		return i;
}

int main()
{
		char a[128];
		int size;
		printf("请输入一行字符串：");
		gets(a);
		size=my_strlen(a);
		printf("size=%d\n",size);
		return 0;

}
*/
