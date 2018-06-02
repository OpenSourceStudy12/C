/*
1,输入一个员工的姓名和部门，并打印结果

2,输入一行字符串，统计有效字符个数

*/
#include <stdio.h>
int main()
{
		char a[128];
		int i=0;
		printf("请输入一行字符串：\n");
		gets(a);
		while(a[i]!='\0')
		{
				i ++;
		}
		printf("有效字符个数为:%d\n",i);
		return 0;

}

/*
int main()
{
		char *p="hello world";
		printf("p:%s\n",p);
		printf("*p:%c\n",*p);
		printf("p:%p\n",p);
		return 0;
}
*/
/*
int main()
{
		char name[32],dept[32];
		printf("请输入部门名称：");
//		scanf("%s",dept);
	    gets(dept);
		printf("请输入员工姓名：");
//		scanf("%s",name);
//		printf("dept:%s\nname:%s\n",dept,name);
        gets(name);
		puts(dept+1);
		puts(name+1);
  		return 0;
}
*/
