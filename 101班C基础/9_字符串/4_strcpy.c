#include <stdio.h>
#include <string.h>
int main()
{
		char src[128],des[128];
		printf("请输入源字符串:\n");
		gets(src);
		strcpy(des,src+1);//将‘\0’一起拷贝
		printf("des:%s,src:%s\n",des,src);
		return 0;
}
