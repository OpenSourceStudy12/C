
/*
*/
#include <stdio.h>
#include <stdlib.h>

/*
typedef enum state
{
	MAIN_MENU,
	STU_MAIN_MENU,
	TEA_MAIN_MENU
}SYS_STATE;
*/

#define MAIN_MENU			1
#define ADMIN_MAIN_MENU	11
							111 112  113
#define STU_MAIN_MENU		12

#define TEA_MAIN_MENU		13
                                        

#define EXIT_MENU			99

int SysExitFlag = 0;
int gSys_State = 1;
void main_operation()
{
	print_main_menu();
	scanf("%d",&select)
	if(select >0&&select <4)
		gSys_State = gSys_State*10+select;
	else if(select == 0)
		gSys_State=EXIT_MENU;
		
}
void print_main_menu()
{
	system("clear");
	printf("\n\n\n\n\n\n\n");
	printf("1. admin sys\n");
	printf("2. stu sys\n");
	printf("3. tea sys\n");
	printf("0. exit\n");
}

int stu_main()
{
	char ch;

	system("clear");
	printf("\n\n\n\n\n\n\nstudent sys\n0. return \n\n");
	ch = getchar();

	if (ch == '0')
	{
		gSys_State = MAIN_MENU;
	}

	return 1;
}



int main()
{
	char ch;

	while (1)
	{
		if (SysExitFlag)
		{
			break;
		}
	
		switch (gSys_State)
		{
			case MAIN_MENU:
					/*有menu? 有的话打印*/
					/*接收用户输入，改变页面状态值*/
					main_operation();
					break;
			case STU_MAIN_MENU:

				break;

			case TEA_MAIN_MENU:

				break;

			case EXIT_MENU:
					SysExitFlag = 1;
					break;
			default:
				break;
		}
		
	}
	
	return 0;
}




