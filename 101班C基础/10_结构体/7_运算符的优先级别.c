

/*
1,  ()   []   ->   .     ====>自左向右


2, ++  --  ！ sizeof()  (强转)   *   &     ~   =======>自右向左


3,算术运算符  ======》先乘除   再加减


4,关系运算符 =======》先> >= <  <=    再 ==    !=



5,逻辑运算符 =======》先&&    再 ||


6,条件运算符======= 》？：


7,赋值运算符 ========》=   += -=


8,逗号
*/
#include <stdio.h>
int main()
{
		int a,b,c;
        c=(a=2,b=3,--a);
		printf("a=%d,b=%d,c=%d\n",a,b,c);
		return 0;
}








