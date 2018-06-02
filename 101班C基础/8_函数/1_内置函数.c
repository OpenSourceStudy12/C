#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
int main()
{
		int a,b;
		a=2,b=3;
		printf("a=%d,b=%d\n",a,b);
//		exit(0);
		a++;
		b++;
		printf("a=%d,b=%d\n",a,b);
        return 0;

}


/*
int main()
{
		int num[10];
		int i;
		srand(time(NULL));
		for(i=0;i<10;i++)
		{
				num[i]=rand()%100;
		}
		for(i=0;i<10;i++)
		{
				printf("%d ",num[i]);
		}
		printf("\n");
		return 0;

}
*/
/*
int main()
{
		char ch;
		ch=getchar();
//		ch=toupper(ch);
        ch=tolower(ch);
		printf("ch=%c\n",ch);
}
*/
/*
inf:   infinite的简写（无穷大）
int  main()
{
		int a;
		scanf("%d",&a);
		printf("%d的倒数是:%.2f\n",a,1.0/a);
		return 0;
}
*/
/*
NaN:not  a  number 的简写（无效数字）
int main()
{
		double x,y;
		scanf("%lf%lf",&x,&y);
        printf("%lf\n",pow(x,y));
}
*/

/*
int main()
{
		int num;
		double re;
		scanf("%d",&num);
		re=sqrt(num);//函数调用
		printf("re=%lf\n",re);
		return 0;

}
*/

