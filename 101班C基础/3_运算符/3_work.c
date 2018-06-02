/*
1,输入一个年份，判断是平年还是闰年
闰年的判断条件（满足条件之一）：
能被4整除且不能被100
能被400整除

2,输入一个字符，判断是否是小写字符

3,输入一个整数，判断能否被3和5整除

4,输入三种商品的价格，至少有一种商品的价格大于50或者商品的总价格大于100,那么折扣率为3%，否则没有折扣，输出最后的价格

5,输入一个五位数的整数，判断该整数是否是回文字符
12321


*/

#include <stdio.h>
int main()
{
		int num,g,s,q,w;
		printf("请输入一个5位数整数:\n");
		scanf("%d",&num);
		g=num%10;
		s=num/10%10;
		q=num/1000%10;
		w=num/10000;
		printf("g=%d,s=%d,q=%d,w=%d\n",g,s,q,w);
		if(g==w && s==q)
		{
				printf("%d 是回文字符\n",num);
		}
		else
		{
				printf("%d 不是回文字符\n",num);
		}

}

/*
int main()
{
		float price1,price2,price3,price;
		printf("请输入三种商品的价格:\n");
		scanf("%f%f%f",&price1,&price2,&price3);
		price = price1+price2+price3;
		if(price1>50||price2>50||price3>50||price>100)
		{
				printf("打折：");
				price=price-price*0.03;
		}
		else
		{
				printf("不打折：");
		}
		printf("price:%.2f\n",price);
		return 0;
}
*/

/*
int main()
{
		int num;
		scanf("%d",&num);
		if(num%3==0 && num%5==0)
		{
				printf("%d  能被3和5整除\n",num);
		}
		else
		{
				printf("%d  不能被3和5整除\n",num);
		}
}
*/
/*
int main()
{
		char ch;
		ch=getchar();
		if(ch>='a'&& ch<='z')
		{
				printf("小写字符\n");
		}
		else
		{
				printf("不是\n");
		}
}
*/

/*
int main()
{
		int year;
		printf("请输入一个年份：\n");
		scanf("%d",&year);
		if((year%4==0 &&year%100!=0) ||year%400==0)
        {
				printf("闰年\n");
		}
		else
		{
				printf("平年\n");
		}
		return 0;
}
*/
