/*

1,从键盘输入三种水果的价格，求出他们的平均值

2,输入一个小写字符，输出对应的大写字符

3,一本书的原价是78.9,现涨了12.4,输出现在书的价格


4,输入两个操作数，分别计算两个操作数的 + - × / %的结果
2 +  3 = 5
 
*/
#include <stdio.h>
int main()
{
		int num1,num2;
		printf("请输入两个操作数：\n");
		scanf("%d%d",&num1,&num2);
		printf("%d+%d=%d\n",num1,num2,num1+num2);
		printf("%d-%d=%d\n",num1,num2,num1-num2);
		printf("%d*%d=%d\n",num1,num2,num1*num2);
		printf("%d/%d=%d\n",num1,num2,num1/num2);
		printf("%d%%%d=%d\n",num1,num2,num1%num2);
		return 0;
}
/*
int main()
{
		float price = 78.9;
		price += 12.4;//price=price + 12.4
		printf("price=%.2f\n",price);
		return 0;
}
*/


/*
int main()
{
		char ch;
		printf("请输入一个小写字符:\n");
//		ch=getchar();
//		putchar(ch-32);
        scanf("%c",&ch);
		printf("%c",ch-32);
		putchar('\n');
		return 0;
}
*/
/*
int main()
{
		float price1,price2,price3,ave;
		printf("请输入三种水果的价格:\n");
		scanf("%f%f%f",&price1,&price2,&price3);
		ave=(price1+price2+price3)/3;
		printf("ave=%.2f\n",ave);
		return 0;
}
*/

