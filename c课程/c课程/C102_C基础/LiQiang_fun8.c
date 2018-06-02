请找出下面写法的错误：

void fun(char a[], char b[], int m)
{
	strncpy(b, a, m-1);
	strcat(b, a[m]);

	return;
}


void fun(char a[], char b[], int m)
{
	strcpy(b, a);
	strcpy(b[m - 1], a[m]);
}


void fun(char a[], char b[], int m)
{
	char *p = b[m];

	strcpy(b, a);
	p = b[m];
	strcpy(p, a[m + 1]);
}




对数组的下标范围一定要判断。
否则， 如果越界， 会出现程序崩溃。

对字符串做操作的话， 几个建议：
1。 想想尾0。
2。 想想空间在哪里， 是否够用。
3。 如果使用了指针， 检查指针的合法性。
4。 善于使用字符串的库函数。
5。 养成几个好习惯， 比如对目标字符串空间清零； 对程序做出错判断。

