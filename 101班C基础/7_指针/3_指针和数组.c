#include <stdio.h>
int main()
{
		int a[5];
		int *p=a,i=0;//p=&a[0]
		while(p<a+5)
		{
           scanf("%d",p);
		   p ++;
		}
        p = a;
		/*
		while(i<5)
		{
				printf("%d ",*(p+i));
				i ++;
		}
		*/
		while(i<5)
		{
				printf("p[%d]=%d\n",i,p[i]);
                 i ++;
		}
		p = &a[2];
		printf("p[0]=%d\n",p[0]);
		printf("p[1]=%d\n",p[1]);
		printf("\n");

}
