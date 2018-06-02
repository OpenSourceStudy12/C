#include <stdio.h>
#include <string.h>
int main()
{
		char a[128];
		int size;
		printf("请输入一行字符串：\n");
		gets(a);
		size=strlen(a);//计算字符串的长度，不包括结束符‘\0’
		printf("size=%d\n",size);
		printf("sizeof(a)=%d\n",sizeof(a));//计算数组的长度
		return 0;

}
