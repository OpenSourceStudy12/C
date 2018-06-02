/*
1,输入一个整数数判断是奇数还是偶数

2,输入一个整数判断个位是否为3

3,输入两种商品的价格，若价格总和大于50,打88折，否则不打折，输出最终价格

4，输入两个字符，判断两个字符的距离是否大于5

5,求两个浮点数的平均值，保留2位小数，判断是否四舍五入
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
		float num1,num2,ave;
		int third;
		printf("请输入两个浮点数:\n");
		scanf("%f%f",&num1,&num2);
		ave=(num1+num2)/2;
		third=(int)(ave*1000)%10;
		if(third>4)//入
		{
				printf("ru\n");
		}
		else
		{
				printf("she\n");
		}
		printf("ave=%.2f,ave=%f\n",ave,ave);
		return 0;
}
/*
int main()
{
		char ch1,ch2;
		int n;
		printf("请输入两个字符：\n");
		ch1=getchar();
		ch2=getchar();
		n=abs(ch1-ch2);
		
//		if(ch2>=ch1)
//		{
//				n=ch2-ch1;
//		}
//		else
//		{
//				n=ch1-ch2;
//		}
		
		if(n > 5)
		{
				printf("距离大于5\n");
		}
		else
		{
				printf("距离小于5\n");
		}
}
*/
/*
int main()
{
		float price1,price2,price;
		scanf("%f%f",&price1,&price2);
        price=price1+price2;
		if(price > 50)
		{
				price=price*0.88;
		}
		printf("price=%.2f\n",price);
		return 0;
}
*/
/*
int main()
{
		int num;
		printf("请输入一个整数：\n");
		scanf("%d",&num);
		if(num%10 == 3)
		{
				printf("%d  个位为3\n",num);
		}
		else
		{
				printf("%d 个位不是3\n",num);
		}
}

*/
/*
int main()
{
		int num;
		printf("请输入一个整数：\n");
		scanf("%d",&num);
		if(num%2==0)
		{
				printf("%d 是偶数\n",num);
		}
		else
		{
				printf("%d 是奇数\n",num);
		}
		return 0;
}
*/

