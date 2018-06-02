/*
定义一个结构体存储影片信息：片名、导演名、片长

1---------》添加影片

2---------》删除影片

3---------》修改影片

4--------》打印影片

5--------》退出

*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct film
{
		char film_name[32];
		char director[32];
		int film_len;
};

void  film_menu()
{
		printf("1,添加影片\n");
		printf("2,修改影片\n");
		printf("3,删除影片\n");
		printf("4,打印影片\n");
		printf("5,退出\n");
		printf("请输入你的选择:\n");
}

void  add_film(struct film *s)
{
		printf("请输入片名：");
		scanf("%s",s->film_name);
		getchar();
		printf("请输入导演名:");
		scanf("%s",s->director);
		printf("请输入片长:");
		scanf("%d",&s->film_len);
}

void  mod_film(struct film *s)
{
		printf("请输入片名：");
		scanf("%s",s->film_name);
		getchar();
		printf("请输入导演名:");
		scanf("%s",s->director);
		printf("请输入片长:");
		scanf("%d",&s->film_len);
}

void  del_film(struct film *s,int total_num,int num)
{
		int  i;
		for(i=num;i<total_num;i++)
		{
				s[i]=s[i+1];
		}
}

void  prin_film(struct film *s,int total_num)
{
		int i;
		printf("序号\t电影名称\t导演名\t\t片长\n");
		for(i=0;i<total_num;i++)
		{
				printf("%-2d\t%-10s\t%-10s\t%-3d\n",i+1,s[i].film_name,s[i].director,s[i].film_len);
		}
}

int main()
{
		struct film movie[100];
		int flag=1,select,total_num=0,num;
		while(flag)
		{
				system("clear");
				film_menu();
				scanf("%d",&select);
				switch(select)
				{
						case 1:
						  if(total_num>100)
						  {
								  printf("存储空间已经越界!\n");
								  sleep(2);
								  break;
						  }
                          add_film(&movie[total_num]);
						  total_num ++;
						  printf("添加成功\n");
						  sleep(2);
						  break;
						 case 2:
						   printf("请输入修改的片名序号：\n");
						   scanf("%d",&num);
						   if(num<=0||num>total_num)
						   {
								   printf("输入的片名序号已越界！\n");
								   sleep(2);
								   break;
						   }
						   mod_film(&movie[num-1]);
						   printf("修改成功\n");
						   sleep(2);
						   break;
						  case 3:
                           printf("请输入删除的片名序号：\n");
						   scanf("%d",&num);
						   if(num<=0||num>total_num)
						   {
								   printf("输入的片名序号不存在!\n");
								   sleep(2);
								   break;
						   }
						   del_film(movie,total_num,num-1);
						   total_num--;
						   printf("删除成功!\n");
					       sleep(2);
						   break;
						  case 4:
						    if(total_num==0)
							{
									printf("目前木有任何片名信息！\n");
								    sleep(2);
									break;
							}
							prin_film(movie,total_num);
						    sleep(2);
							break;
						  case 5:
						    flag=0;
							break;
						  default:
						    printf("输入有误，请重新输入！!\n");
						    sleep(2);
							break;
				}
		}
}


