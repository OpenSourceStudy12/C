#include <stdio.h>
/*
1,数组名就是数组首元素的起始地址，数组名就相当于一个常量
2，数组名+n:第n+1个元素的起始地址
3,&数组名:表示数组的起始地址
*/



/*
int main()
{
		int a[5]={1,2,3,4,5};
		int i;
		for(i=0;i<5;i++)
		{
				printf("&a[%d]=%p\n",i,&a[i]);
		}
        for(i=0;i<5;i++)
		{
				printf("a+%d=%p\n",i,a+i);
		}

		printf("&a=%p\n",&a);

}

*/
/*
#define  SIZE   10
int main()
{
		int a[10]={1,2};
		int i;
		for(i=0;i<10;i++)
		{
				printf("a[%d]=%d\n",i,a[i]);
		}
}
*/


/*
int main()
{
		float a[SIZE];
		int i;
		for(i=0;i<SIZE;i++)
		{
				printf("输入第%d个学生的成绩：",i+1);
				scanf("%f",&a[i]);
		}
		for(i=0;i<SIZE;i++)
		{
				printf("a[%d]=%.2f\n",i,a[i]);
		}
}
*/
/*
int main()
{
		int a[5],i;
		for(i=0;i<5;i++)
		{
				scanf("%d",&a[i]);
		}
		for(i=0;i<5;i++)
		{
				printf("a[%d]=%d\n",i,a[i]);
		}
		return 0;
}

*/

/*
int main()
{
		float a[5];
		int i;
		for(i=0;i<=5;i++)//注意已经越界了
		{
				a[i]=i+1+(float)(i+1)/10;
		}
		for(i=0;i<=5;i++)
		{
				printf("a[%d]=%.1f\n",i,a[i]);
		}
}
*/
/*
int main()
{
		int age[5]={1,2,3,4,5};//定义一个数组，实质在内存申请20个字节空间
	//	printf("sizeof(age)=%d\n",sizeof(age));
		int i;
		for(i=0;i<5;i++)
		{
				printf("age[%d]=%d\n",i,age[i]);
		}


		return 0;
}
*/
