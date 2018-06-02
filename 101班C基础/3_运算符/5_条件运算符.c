#include <stdio.h>
/*

表达式1？表达式2：表达式3
if(表达式1)
{
		表达式2;
}
else
{
		表达式3;
}


*/
int main()
{
   int a;
   int b;
   scanf("%d%d",&a,&b);
   //a>b?printf("a>b\n"):printf("a<b\n");
   if(a>b)
   {
		   printf("a>b\n");
   }
   else
   {
		   printf("a<b\n");
   }
   
   return 0;
}
