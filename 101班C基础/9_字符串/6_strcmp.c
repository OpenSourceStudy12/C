#include <stdio.h>
#include <string.h>
int main()
{
		char name[128],pass[128];
		printf("请输入你的帐号：");
		gets(name);
		printf("请输入你的密码：");
		gets(pass);
		if(strncmp(name,"xiaoqi123",6)==0 && strncmp(pass,"xiaoqi123",6)==0)
		{
				printf("登录成功\n");
		}
		else
		{
				printf("帐号密码不匹配!\n");
		}
		return 0;
}

/*
int main()
{
		char s1[128],s2[128];
		int re=-2;
		printf("请输入一个字符串：");
		gets(s1);
		printf("再输入一个字符串:");
		gets(s2);
		printf("%d\n",strcmp(s1,s2));
		
		if(re==1)
		{
				printf("s1>s2\n");
		}
		else if(re==-1)
		{
				printf("s1<s2\n");
		}
		else if(re==0)
		{
				printf("s1==s2\n");
		}

}
*/

