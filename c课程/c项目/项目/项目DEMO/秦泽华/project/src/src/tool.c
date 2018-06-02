#include"common.h"

int selectIn()
{
        int select = 0;
        int x = scanf("%d", &select);
        while (0 == x)
        {
                printf("请输入数字\n");
                while(getchar() != '\n');
                x = scanf("%d", &select);

        }
        return select;
}

void goback()
{
	printf("请输入随意数字返回上一层\n");
	selectIn();

}




