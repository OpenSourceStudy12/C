/*
1,在键盘输入一个ascii,输出该ascii对应的字符

2,输入一个字符，输出该字符的下一个字符
*/


#include <stdio.h>
//4---->整型4   ‘4’-------》字符4
int main()
{
		char ch;
		printf("请输入一个字符：\n");
		ch=getchar();
		putchar(ch+1);
		putchar('\n');
		return 0;
}

/*
int main()
{
//		char ch;
        int ch;
		printf("请输入一个Ascii码：\n");
//		ch=getchar();
        scanf("%d",&ch);
		putchar(ch);
		putchar('\n');
		return 0;
}
*/
