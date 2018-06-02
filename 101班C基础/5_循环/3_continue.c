#include<stdio.h>
/*
break:跳出循环

continue:结束本次循环，继续下一次循环
*/
int main()
{
   int sum=0,i=1;
   do
   {
		   if(i%10==3)
		   {
				   continue;
		   }
		   sum += i;
		//   i ++;
   }while(i++<100);
   printf("sum=%d,i=%d\n",sum,i);

}
