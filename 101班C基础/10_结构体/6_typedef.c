#include <stdio.h>
/*
typedef:给已有的数据类型取一个别名
*/
typedef struct stu 
{
		char name[32];
		int score;
}STU,*P_STU;

int main()
{
		STU  s1={"xiaoqi",99};//struct stu s1;
        printf("s1.name=%s,s1.score=%d\n",s1.name,s1.score);

        P_STU p=&s1;
		printf("p->name=%s,p->score=%d\n",p->name,p->score);

        printf("sizeof(STU)=%d,sizeof(P_STU)=%d\n",sizeof(STU),sizeof(P_STU));
}
/*
typedef  int  ZM_INT;
int main()
{

		ZM_INT  a=10;
		printf("a=%d\n",a);
		return 0;

}
*/
