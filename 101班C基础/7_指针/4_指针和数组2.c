/*
1，指针数组
实际就是一个数组，每一个元素都是指针

2，数组指针
实际就是一个指针
（1）指向数组每一个元素的指针
（2）指向数组的指针
*/
#include <stdio.h>
int main()
{
		int a[3][2]={{1,2},{3,4},{5,6}};
		int (*p)[2]=a;
		int i=0,j=0;
		while(i<3)
		{
				printf("p+%d=%p\n",i,p+i);
		        i ++;
		}
        
        for(i=0;i<3;i++)//内层数组每一个元素的起始地址
		{
				for(j=0;j<2;j++)
				{
						printf("*(p+%d)+%d=%p\n",i,j,*(p+i)+j);
				}
		}


		for(i=0;i<3;i++)//内层数组每一个元素的数据
		{
				for(j=0;j<2;j++)
				{
						printf("*(*(p+%d)+%d)=%d\n",i,j,*(*(p+i)+j));
				}
		}
}




/*
int main()
{
		int a[5]={11,22,33,44,55};
		int (*p)[5]=NULL;
		p=&a;
		int i=0;
		while(i<5)
		{
				printf("*(*p+%d)=%d\n",i,*(*p+i));
				i ++;
		}
		printf("p=%p\n",p);
		printf("p+1=%p\n",p+1);
}
*/
/*
int main()
{
		int a[5]={1,2,3,4,5};
		int* p[5];
	    int i=0;
		while(i<5)
		{
				p[i]=a+i;//p[i]=&a[i]
				i ++;
		}
		for(i=0;i<5;i++)
		{
				(*p[i])+=5;
		}
		for(i=0;i<5;i++)
		{
				printf("*(p[%d])=%d\n",i,(*p[i]));
		}
}
*/
