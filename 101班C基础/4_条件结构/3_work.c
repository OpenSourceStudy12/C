/*
1,编写程序，实现一个简单整数的计算器
2+3
2+3=5
2-3
2-3=-1
+ - * /  %


2,输入一个月份判断是什么季节
1,2,3====》春季 



3,输入一个年份和月份，判断该年对应的该月的天数
1,3,5,7,8,10,12====>31
4,6,9,11      =====>30
2

4,某家饭店在一个星期中每天都有特色菜：
星期一：鱼香肉丝
星期二：肉模茄子
星期三：红烧鲫鱼
星期四：酸辣土豆丝
星期五：鱼籽拌饭
星期六：红烧肉
星期七：佛跳墙
设计程序，客户选择那一天（1-7）就显示当天的特色菜


5,设计一个学生管理菜单，（增、删、改、查、退出）
*/
#include <stdio.h>
int main()
{
	    int select;
		printf("\t\t学生管理系统\n");
		printf("\t\t1,添加学生\n");
		printf("\t\t2,删除学生\n");
		printf("\t\t3,修改学生\n");
		printf("\t\t4,查询学生\n");
		printf("\t\t5,退出\n");
		printf("请输入你的选择:\n");
		scanf("%d",&select);
		switch(select)
		{
				case 1:
				printf("添加学生成功\n");
				break;
				case 2:
				printf("删除学生成功\n");
				break;
				case 3:
				printf("修改学生成功\n");
				break;
				case 4:
				printf("查询学生成功\n");
				break;
				case 5:
				printf("退出\n");
				break;
				default:
				printf("不在服务区\n");
				break;
		}
}



/*
int main()
{
		int year,month;
		printf("请输入年和月：\n");
		scanf("%d%d",&year,&month);
        switch(month)
		{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
				  printf("31天\n");
				  break;
				case 4:
				case 6:
				case 9:
				case 11:
				  printf("30天\n");
				  break;
				case 2:
				  if(year%4==0&&year%100!=0 ||year %400==0)
				  {
						  printf("29天\n");
				  }
				  else
				  {
						  printf("28天\n");
				  }
				  break;
			   default :
			     printf("不在服务区\n");
				 break;
		}
}

*/
/*
int main()
{
		int month;
		printf("请输入一个月份：\n");
		scanf("%d",&month);
		switch(month)
		{
           case 1:
		   case 2:
		   case 3:
		     printf("春季\n");
			 break;
		   case 4:
		   case 5:
		   case 6:
		     printf("夏季\n");
			 break;
		   case 7:
		   case 8:
		   case 9:
		     printf("秋季\n");
			 break;
		   case 10:
		   case 11:
		   case 12:
		     printf("冬季\n");
			 break;
		   default:
		     printf("输入有误\n");
			 break;
		}
}
*/
/*
int main()
{
    int a,b;
	char c;
	printf("请输入一个算式：\n");
	scanf("%d%c%d",&a,&c,&b);
    switch(c)
	{
			case '+':
			printf("%d + %d =%d\n",a,b,a+b);
			break;
			case '-':
			printf("%d - %d =%d\n",a,b,a-b);
			break;
			case '*':
			printf("%d * %d =%d\n",a,b,a*b);
			break;
			case '/':
			printf("%d/ %d =%d\n",a,b,a/b);
			break;
			case '%':
			printf("%d %% %d =%d\n",a,b,a%b);
			break;

	}
}
*/
