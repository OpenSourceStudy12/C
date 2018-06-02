/***********************************************
*file name:
*function:求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。
*例如2+22+222+2222+22222(此时共有5个数相加)，几个数相加有键盘控制。
*author:
*************************************************/
#include<stdio.h>

void main()
{
	int sum = 0,s=0,n,a,i,j;
	printf("输入值和个数\n");
	scanf("%d%d",&a,&n);
	for(i=1;i<=n;i++)
	{
		s = s*10 +a;
		sum += s;

	}
	printf("%d + %d%d + ... = %d\n",a,a,a,sum);
}
