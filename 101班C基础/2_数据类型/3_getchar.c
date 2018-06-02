#include <stdio.h>
/*
getchar():从终端读取一个字符，并返回该字符的ascii，如果终端木有字符会一直等待
*/
int main()
{
		char ch1,ch2,ch3;
		ch1=getchar();
		getchar();
		printf("ch1:");
		putchar(ch1);
		putchar('\n');
		ch2=getchar();
		getchar();
		printf("ch2:");
		putchar(ch2);
		putchar('\n');
		ch3=getchar();
		printf("ch3:");
		putchar(ch3);
		putchar('\n');
		return 0;
}




/*
int main()
{
        char ch;
//		printf("ch=%c,ch=%d\n",ch,ch);
        ch= getchar();
		putchar(ch);
		putchar('\n');
		printf("ch=%c\n",ch);
		return 0;
}
*/
