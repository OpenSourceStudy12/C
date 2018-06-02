#include <stdio.h>
#include <string.h>
int main()
{
		char src[128],des[128];
		printf("请输入源字符串：");
		gets(src);
		printf("请输入目标字符串：");
		gets(des);
		strcat(des,src+3);//‘\0’一起追加过来
		puts(des);
		puts(src);
		return 0;
}
