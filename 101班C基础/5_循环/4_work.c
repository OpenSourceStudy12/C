/*
1,
*****
*****
*****
*****


2,
*
**
***
****
*****

3,
    *    
   **    1     3   2
  ***    2     2   3
 ****    3     1  
*****    

4,
*****  1     0(i-1)     5(5-i+1)
 ****  2     1     4 
  ***  3     2     3
   **  4     3     2
    *  5     4     1 

5,
  *        1    2(3-i)   1(2*i-1)
 ***       2    1   3  
*****      3    0   5 
 ***       1    1(i)   3(5-2i) 
  *        2    2   1 

6,输入一个整数，打印对应菱形，该整数一定是奇数



7,假设口袋有20元人民币，由1角、5角、1元组成，请输出所有组合


8,  打印九九乘法表


9,
*           1       1       0(i-1)
*.*.        2       2       1
*..*..*..   3       3       2
*...*...*...*...
*....*....*....*....*....
*.....*.....*.....*.....*.....*.....
*......*......*......*......*......*......*......
*/
#include <stdio.h>
int main()
{
		int i,j,k;
		for(i=1;i<=7;i++)//控制行数
		{
				for(j=1;j<=i;j++)//控制星数
				{
				     printf("*");
                     for(k=1;k<=i-1;k++)
					 {
                         printf(".");
					 }
				}
				printf("\n");

		}
}

/*
int main()
{
		int i,j;
		for(i=1;i<=9;i++)
		{
				for(j=1;j<=i;j++)
				{
						printf("%-2dx %-2d=%2d  ",j,i,i*j);
				}
				printf("\n");
		}
}
*/
/*
int main()
{
		int jiao1,jiao5,yuan1;
		printf("1角\t5角\t1元\n");
		for(yuan1=1;yuan1<=20;yuan1++)
		{
				for(jiao5=1;jiao5<=40;jiao5++)
				{
						for(jiao1=1;jiao1<=200;jiao1++)
						{
								if(jiao1+5*jiao5+10*yuan1==200)
								{
										printf("%d\t%d\t%d\n",jiao1,jiao5,yuan1);
								}
						}
				}
		}
}

*/




/*
int main()
{
		int n,i,j,k;
		printf("请输入星星的大小：\n");
		while(1)
		{
		  scanf("%d",&n);
		  if(n%2==0)
		  {
				  printf("输入应为奇数，请重新输入\n");
		  }
		  else
		  {
				  break;
		  }
		}
		for(i=1;i<=(n/2)+1;i++)
		{
				for(j=1;j<=n/2+1-i;j++)
				{
						printf(" ");
				}
				for(k=1;k<=2*i-1;k++)
				{
						printf("*");
				}
				printf("\n");
		}
		for(i=1;i<=n/2;i++)
		{
				for(j=1;j<=i;j++)
				{
						printf(" ");
				}
				for(k=1;k<=n-2*i;k++)
				{
						printf("*");
				}
				printf("\n");
		}
}
*/
/*
int main()
{
		int i,j,k;
		for(i=1;i<=3;i++)
		{
             for(j=1;j<=3-i;j++)
			 {
					 printf(" ");
			 }
			 for(k=1;k<=2*i-1;k++)
			 {
					 printf("*");
			 }
			 printf("\n");
		}
		for(i=1;i<=2;i++)
		{
				for(j=1;j<=i;j++)
				{
						printf(" ");
				}
				for(k=1;k<=5-2*i;k++)
				{
						printf("*");
				}
				printf("\n");
		}
}
*/

/*
int main()
{
		int i,j,k;
		for(i=1;i<=5;i++)
		{
				for(j=1;j<=i-1;j++)
				{
						printf(" ");
				}
				for(k=1;k<=5-i+1;k++)
				{
						printf("*");
				}
				printf("\n");
		}
}
*/
/*
int main()
{
    int i,j,k;
	for(i=0;i<5;i++)
	{
			for(j=0;j<5-i-1;j++)
			{
					printf(" ");
			}
			for(k=0;k<i;k++)
			{
					printf("*");
			}
			printf("\n");
	}
}
*/
/*
int main()
{
		int i,j,k;
		for(i=1;i<=5;i++)
		{
				for(j=1;j<=5-i;j++)
				{
						printf(" ");
				}
				for(k=1;k<=i;k++)
				{
						printf("*");
				}
				printf("\n");
		}
}
*/
/*
int main()
{
		int i,j,k;
		for(i=0;i<5;i++)
		{
				for(j=0;j<5-i-1;j++)
				{
						printf(" ");
				}
				for(k=0;k<i+1;k++)
				{
						printf("*");
				}
				printf("\n");
		}
}
*/


