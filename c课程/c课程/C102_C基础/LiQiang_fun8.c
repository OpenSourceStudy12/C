���ҳ�����д���Ĵ���

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




��������±귶Χһ��Ҫ�жϡ�
���� ���Խ�磬 ����ֳ��������

���ַ����������Ļ��� �������飺
1�� ����β0��
2�� ����ռ������ �Ƿ��á�
3�� ���ʹ����ָ�룬 ���ָ��ĺϷ��ԡ�
4�� ����ʹ���ַ����Ŀ⺯����
5�� ���ɼ�����ϰ�ߣ� �����Ŀ���ַ����ռ����㣻 �Գ����������жϡ�

