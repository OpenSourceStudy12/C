/****************************************************
*file name:
*function:
*author:
****************************************************/
#include<stdio.h>

typedef struct movie
{
	char name[20];
	char dir[20];
	float time;
//	int s;

}MOV;
//MOV moe[20];

void add(MOV *pm);
void del(MOV *pm);
void mod(MOV *pm);
void prf(MOV *pm);

int s;

int main()
{
	int k;
	MOV moe[20];
	do
	{
		printf("添加影片1、删除影片2、修改影片3、打印影片4、退出5\n");
		scanf("%d",&k);
		switch(k)
		{
			case 1:
				add(moe);
				break;
			case 2:
				del(moe);
				break;
			case 3:
				mod(moe);
				break;
			case 4:
				prf(moe);
				break;
			default:
				break; 
		}
//		getchar();
	}while(k != 5);
	return 0;
}

void add(MOV *pm)
{
	printf("请输入电影名、导演、时长\n");
	scanf("%s%s%f",pm[s].name,pm[s].dir,&pm[s].time);
	s++;
}

void del(MOV *pm)
{
	int i,j;
//	printf("序号\t电影名\t导演\t时长:\n");
//	for(i=0;i<s;i++)
//		printf("%d\t%s\t%s\t%.2f\n",i,pm[i].name,pm[i].dir,pm[i].time);

	printf("选择要删除的电影序号:\n");
	scanf("%d",&j);
	for(i=j;i<s;i++)
		pm[i]=pm[i+1];
	s--;
	//	pm[i]={};
}

void mod(MOV *pm)
{
	int i,j;
//	printf("序号\t电影名\t导演\t时长:\n");
//	for(i=0;i<s;i++)
//		printf("%d\t%s\t%s\t%.2f\n",i,pm[i].name,pm[i].dir,pm[i].time);
	
	printf("输入想要修改的电影序号:\n");
	scanf("%d",&j);
	printf("请输入要修改的信息:\n");
	scanf("%s%s%f",pm[j].name,pm[j].dir,&pm[j].time);
	
}

void prf(MOV *pm)
{
	int i;
	printf("序号\t\t电影名\t\t导演\t\t时长:\n");
	for(i=0;i<s;i++)
		printf("%d\t\t%s\t\t%s\t\t%.2f\n",i,pm[i].name,pm[i].dir,pm[i].time);
}
















