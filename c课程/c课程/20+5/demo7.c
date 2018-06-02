#include<stdio.h>
#include<math.h>

void itoa(int inter, char string[]);

int main(void)
{
	char string[20]={0};
	int num;
	printf("please enter a number\n");
	scanf("%d", &num);
	itoa(num, string);
	puts(string);

	return 0;
}

void itoa(int inter, char string[])
{
	int i;
	int count = 1; 
	int copy = inter;
	int temp = abs(inter);
	while ((inter = abs(inter) / 10) != 0)
	{
		count ++;
	}
	
	if (copy > 0)
	{
		for (i = 0; temp != 0 && i < count; i ++)
		{
			string[count - i - 1] = temp % 10 + '0';
			temp = temp / 10;
		}
		string[count] = '\0';
	}
	else if (copy == 0)
	{
		string[0] = '0';
		string[1] = '\0';
	}
	else
	{
		string[0] = '-';
		for (i = 1; temp != 0 && i < count + 1; i ++)
		{
			string[count - i + 1] = temp % 10 + '0';
			temp = temp / 10;
		}
		string[count + 1] = '\0';
	}
}
