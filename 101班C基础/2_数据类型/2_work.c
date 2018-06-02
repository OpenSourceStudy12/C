/*
1,一个圆柱体底面半径为 1.23,高为：4.5,输出圆柱体体积

2,输入一个圆柱体的半径和高，输出该圆柱体的体积

3,输入一个学生的基本信息：学号、年龄、性别、成绩，并输出该学生的基本信息

4,香蕉2.3元/个 ,芒果 5.8元/个，输出4跟香蕉和2个芒果的总价

5，分别输入一个香蕉和一个芒果的价格，再求出3个香蕉和4个芒果的总价
*/
#include <stdio.h>
int main()
{
		float banana,mango,price;
		printf("请输入香蕉和芒果的单价：\n");
		scanf("%f%f",&banana,&mango);
        price=3*banana+4*mango;
		printf("price=%.2f\n",price);
		return 0;
}


/*
int main()
{
		float banana=2.3,mango=5.8;
		float price;
		price=4*banana+2*mango;
		printf("price=%.2f\n",price);
		return 0;

}
*/
/*
int main()
{
		int num,age;
		char sex;
		float score;
		printf("请输入学生的学号、年龄、性别和成绩：\n");
		scanf("%d%d",&num,&age);
		setbuf(stdin,NULL);
		scanf("%c%f",&sex,&score);
		printf("学号\t年龄\t性别\t成绩\n");
		printf("%d\t%d\t%c\t%.2f\n",num,age,sex,score);
		return 0;
}
*/

/*
int main()
{
		float r,h,v;
		printf("请输入圆柱体的半径和高：\n");
		scanf("%f%f",&r,&h);
		v=3.14*r*r*h;
		printf("v=%.2f\n",v);
		return 0;
}
*/
/*
int main()
{
		float r,h,v;
		r=1.23;
		h=4.5;
        v=3.14*r*r*h;
		printf("v=%.2f\n",v);
		return 0;
}
*/
