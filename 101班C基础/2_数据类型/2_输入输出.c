#include <stdio.h>
/*
&num

格式说明符：只要以%开头的全部是格式说明符

转义字符：只要以\开头的全部是转义字符

空白字符：制表符、enter键、空白键

标准输入：stdin
标准输出：stdout

*/
int main()
{
		int num;
		float num2;
		char  ch;
		scanf("%d%f",&num,&num2);
//		scanf("%c",&ch);
        setbuf(stdin,NULL);//清除输入缓冲区
		scanf("%c",&ch);
		printf("num=%d,num2=%.2f,ch=%c\n",num,num2,ch);
}




/*
int main()
{
        int num=10;
		float  num1=3.78;
        printf("&num:%p\n",&num);
        printf("\"hello  world\"\n");
		printf("%%100\n");
		printf("num1=%d\n",num1);
		printf("学号\t性别\t年龄\t成绩\n");
		return 0;
}
*/


/*
int main()
{
		char ch='a';
		printf("ch:%c\n,%d",ch,90);
}

*/
/*
int main()
{
		float f;
		f=3.14;
		printf("f=%f,f=%e\n",f,f);
        printf("f=%.2f\n",f);
		return 0;
}
*/


/*
int main()
{
		int num = 100,num1=29,num2=2,num3=1234;
		printf("num=%d\n",num);
		printf("num=%d,num=o%o,num=0x%x\n",num,num,num);
		printf("num=%d,num=%#o,num=%#x\n",num,num,num);
		printf("%3d\n",num1);
		printf("%3d\n",num2);
		printf("%3d\n",num);
		printf("%3d\n",num3);
//		printf("hello shanghai   hello xiaoqi  num\n");
        
		return 0;
}
*/
