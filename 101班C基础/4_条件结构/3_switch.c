/*
switch(条件表达式)
{
		case 常量1：
		语句块1；
		break;
		case 常量2：
		语句块2;
		break;
		case 常量3:
		语句块;
		break;
		...
		default:
		语句块;
		break;
}

应用场合：多条分支取决一个变量的值

注意事项：
1,case 后面必须是整型或字符类型的常量
2,每一个case后面都要加上break
3,default 位置不确定可以放在开头、中间、结尾都行，所有default最后要加break
4,分支取决于哪个变量，条件表达式里就放哪个变量



*/
#include<stdio.h>
int main()
{
		char ch;
		char ch1='a';
		printf("请输入一个字符\n");
		ch=getchar();
		switch(ch)
		{
				case  'a':
			//	printf("%c 是元音字符\n",ch);
			//	break;
				case 'o':
			//	printf("%c 是元音字符\n",ch);
			//	break;
				case 'e':
			//	printf("%c 是元音字符\n",ch);
			//	break;
				case 'i':
				default:
				printf("%c 不是元音字符\n",ch);
             //   break;
			//	printf("%c 是元音字符\n",ch);
			//	break;
				case 'u':
				printf("%c 是元音字符\n",ch);
				break;
		}
		printf("hehe\n");
}
