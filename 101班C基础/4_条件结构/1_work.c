/*
1,从键盘输入一个字符，判断该字符是数字字符、小写字符、大写字符、控制字符、还是其他字符



2,某商品正在打折，根据用户购买的数量打的折扣不同，请根据用户输入的商品单价和数量，设计程序，计算用户应付的钱
数量         折扣
<5           不打折
5<=n<10       1%
10<=n<15      2%
15<=n<20      3%
20<=n<25      4%

*/
#include <stdio.h>
int main()
{
		float price,rate;
		int num;
		printf("请输入商品的价格及用户购买数量：\n");
		scanf("%f%d",&price,&num);
		if(num <0)
		{
				printf("输入数据不合法\n");
		}
		else if(num>0 && num<5)
		{
				printf("原价:");
				rate = 1;
		}
		else if(num>=5 && num<10)
		{
				printf("99折：");
				rate=0.99;
		}
		else if(num>=10 && num<15)
		{
				printf("98折：");
				rate=0.98;
		}
		else if(num>=15 && num<20)
		{
				printf("97折：");
				rate=0.97;
		}
		else 
		{
				printf("96折：");
				rate=0.96;
		}
        price=price*num*rate;
		printf("%.2f\n",price);
		return 0;
}


/*
int main()
{
		char  ch;
		printf("请输入一个字符:\n");
		ch=getchar();
		if(ch >='0'&&ch<='9')
		{
				printf("%c  是数字字符\n",ch);
		}
		else if(ch>='a'&&ch <='z')
		{
				printf("%c 是小写字符\n",ch);
		}
		else if(ch >='A'&&ch <='Z')
		{
				printf("%c 是大写字符\n",ch);
		}
		else if(ch >= 0 && ch<=31 || ch == 127)
		{
				printf("控制字符\n");
		}
		else
		{
				printf("其他字符\n");
		}
		return 0;
}
*/

