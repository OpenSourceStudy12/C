#include <stdio.h>
/*
自动转换：

强制转换：(新类型)变量
注意：
范围小的转换成范围大的一点问题都没有
范围大的转换成范围小的会导致数据出错，或者精度不精确


*/


int main()
{
		int a=2;
		a += 1;//a=a+1
		printf("a=%d\n",a);
}
/*
int main()
{
		int a=1,b;
		//a++;//a=a+1
	//	b=a++;//b=a,a=a+1;
//	    ++a;//a= a+1
        b=++a;//a=a+1,b=a;
		printf("a=%d,b=%d\n",a,b);
}
*/


/*
int main()
{
		float num1,num2;
		scanf("%f%f",&num1,&num2);
		printf("%f %% %f= %d\n",num1,num2,num1%num2);//求模运算符两个操作数一定是整数
		return 0;

}
*/
/*
int main()
{
		int a=0x11223344;
		char ch=(char)a;
		printf("a=%#x,ch=%#x\n",a,ch);
		return  0;
}
*/
/*
int main()
{
		float a=2.3;
		printf("a=%d\n",(int)a);
		return 0;
}
*/
/*
int main()
{
		int num1,num2;
		float num3;
		printf("请输入两个操作数：\n");
		scanf("%d%f",&num1,&num3);
		printf("%d / %f =%f\n",num1,num3,num1/num3);
		num3=num1;
		printf("num3=%f\n",num3);
		return 0;
}
*/
