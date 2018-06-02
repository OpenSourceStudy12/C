#include<stdio.h>
 int main()
{
	int num,age;
	float score;
	char sex;
	printf("请输入学号，年龄，性别，成绩:\n");
	scanf("%d%d",&num,&age);
	setbuf(stdin,NULL);
	scanf("%c",&sex);
	//scanf("%c",&sex);
	scanf("%f",&score);
        
	printf("学号\t年龄\t性别\t成绩\n");
	printf("%d\t%d\t%c\t%.2f\n",num,age,sex,score);
	printf("num = %d = %#o = %#x\n",num,num,num);
	
	printf("%d %c\n",num,num);
	
	printf("%c %d\n",sex,sex);
	return 1;

}
