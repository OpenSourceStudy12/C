//1

/************************************
*file name:
*function:输入某年某月某日，判断这一天是这一年的第几天？
*auhor:L-R-H
*************************************/

//#include<stdio.h>
//void main()
//{
/*	int year,month,day,days;
	int m1=31,m2=59,m3=90,m4=120,m5=151,m6=181,
	    m7=212,m8=243,m9=273,m10=304,m11=334;
	printf("请输入年月日:\n");
	scanf("%d%d%d",&year,&month,&day);
	switch(month)
	{
		case 1:
			days = day;
			break;
		case 2:
			days = m1+day;
			break;
		case 3:
			days = m2+day;
			break;
		case 4:
			days = m3+day;
			break;
		case 5:
			days = m4+day;
			break;
		case 6:
			days = m5+day;
			break;
		case 7:
			days = m6+day;
			break;
		case 8:
			days = m7+day;
			break;
		case 9:
			days = m8+day;
			break;
		case 10:
			days = m9+day;
			break;
		case 11:
			days = m10+day;
			break;
		case 12:
			days = m11+day;
			break;
		default:
			printf("error");
			break;
	
	}
	if(year%4 == 0 && year%100 != 0 ||year%400 != 0)
		printf("第%d日\n",days+1);
	else
		printf("第%d日\n",days);
*/

/*	int year,month,day,days;
	int day_arr[] = {0,31,59,90,120,151,181,212,243,273,304,334};
	printf("请输入年月日:\n");
	scanf("%d%d%d",&year,&month,&day);
	days = day_arr[month-1] + day;
	if(year%4 == 0 && year%100 != 0 ||year%400 != 0)
		days += 1;
	printf("第%d日\n",days);
*/
//}

//2
/************************************
*file name:
*function:输入某年第几日，判断这一天是那月那日？
*auhor:L-R-H
*************************************/
#include<stdio.h>
void main()
{
	int year_p[] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
	int year_r[] = {0,31,60,91,121,152,182,213,244,274,305,335,366};
	int days,month,day,year,i;
	printf("请输入年第几日\n");
	scanf("%d%d",&year,&days);
	if(year%4 == 0 && year%100 != 0 ||year%400 != 0)
	{
		for(i=0;i<=11;i++)
		{
			if(days<=year_r[i])
				break;
		}
		day = days - year_r[--i];
	}
	else
	{	for(i=0;i<=11;i++)
		{
			if(days<=year_p[i])
				break;
		}
		day = days - year_p[--i];
	}
	printf("%d月%d日\n",++i,day);


}


































