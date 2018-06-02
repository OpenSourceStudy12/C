#include <stdio.h>


int main()
{
	while(1)
	{
	char name[128];
	int age;
	char password[10];
	int class;
	int c_score;
	printf("input the student num:\n");
	scanf("%s",name);
	fflush(stdin);
	fflush(stdout);
	getchar();
	printf("input the student age:\n");
	scanf("%s",&age);
	printf("input the student password:\n");
	scanf("%s",password);
	printf("input the student class:\n");
	scanf("%s",&class);
	printf("input the student c_score:\n");
	scanf("%s",&c_score);
	}
	return 0;
}
