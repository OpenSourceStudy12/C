#include <stdio.h>
/*
多重if结构：

if(表达式1)
{
		语句块1;
}
else if(表达式2)
{
		语句块2;
}
else if(表达式3)
{
		语句块3;
}
...
else
{
		语句块n;
}


注意事项：
1,除非语句块只有一条语句可以省略花括号，否则必须加上花括号

2,if后面的条件表达式后面不能加分号

3,else  可以省略

90    A
80---90  B
70---80  c
60---70  D
<60      E
*/
#include <stdio.h>


//没有多重ifde 执行效率高
int main()
{
		float score;
		printf("请输入一个成绩:\n");
		scanf("%f",&score);
		if(score <0 ||score >100)
		{
				printf("输入数据不合法\n");
		}
		if(score >=90)
		{
				printf("A\n");
		}
		if(score >=80 && score<90)
		{
				printf("B\n");
		}
		if(score>=70 && score <80)
		{
				printf("C\n");
		}
		if(score>=60&&score <70)
		{
				printf("D\n");
		}
		if(score <60&&score >0)
		{
				printf("E\n");
		}

		printf("hehehehhe\n");
}
/*
int main()
{
		float score;
		printf("请输入一个学生的成绩:\n");
		scanf("%f",&score);
		if(score<0||score>100)
		{
				printf("输入数据不合法\n");
		}
		else if(score>=90)
		{
				printf("A\n");
		}
		else if(score>=80 )
		{
				printf("B\n");
		}
		else if(score>=70)
		{
				printf("C\n");
		}
		else if(score>=60)
		{
				printf("D\n");
		}
		else if(score<60)
		{
				printf("E\n");
		}
        printf("hehehehhe\n");
		return 0;
}

*/
