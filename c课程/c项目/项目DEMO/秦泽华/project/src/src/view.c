#include"common.h"


void welcome()
{
	printf("\n");
	titlePrint();
	printf("*                                                       *\n");
	printf("*******************    请    选    择     ***************\n");
	printf("*                                                       *\n");
	printf("*                                                       *\n");
	printf("*                       1.用户登录                      *\n");	
	printf("*                       2.用户注册                      *\n");
	printf("*                                                       *\n");
	printf("*                                                       *\n");
	printf("*********************************************************\n");
	printf("\n");
	selectPrint();
}
void titlePrint()
{
	printf("***************欢 迎 使 用 火 车 订 票 系 统*************\n");
}

void loginWelcome()
{
	system("clear");
	titlePrint();
	printf("*                                                        *\n");
	printf("*                         用户登录                       *\n");
	printf("*                                                        *\n");
}


void selectPrint()
{
	printf(" 请 输 入 选 择 的 号 码  :\n");

}

void selectError()
{
	printf(" 输 入 错 误,请 输 入 准 确 的 数 字\n");
}


void customerWelcome()
{
	titlePrint();
	printf("*                                                       *\n");
	printf("*                      旅 客 界 面                      *\n");
	printf("*                                                       *\n");
	printf("*                1. 查 看 个 人 基 本 信 息             *\n");
	printf("*                2. 查 询 列 车                         *\n");
	printf("*                3. 订 票 操 作                         *\n");
	printf("*                4. 退 票 操 作                         *\n");
	printf("*                5. 注 销                               *\n");
	printf("*                                                       *\n");
	selectPrint();
}

void registerWelcome()
{
	system("clear");
	titlePrint();
	printf("*                                                       *\n");
	printf("*                       用户注册                        *\n");
	printf("*                                                       *\n");
}

void adminWelcome()
{
	system("clear");
	titlePrint();
	printf("*                                                       *\n");
	printf("*                     管 理 员 界 面                    *\n");
	printf("*                                                       *\n");
	printf("*                  1. 管 理 旅 客 信 息                 *\n");
	printf("*                  2. 管 理 列 车 信 息                 *\n");
	printf("*                  3. 统 计                             *\n");
	printf("*                  4. 注 销                             *\n");
	printf("*                                                       *\n");
	selectPrint();

}

void manCustomerWelcome()
{
	system("clear");
	titlePrint();
	printf("*                                                       *\n");
	printf("*                 1. 旅 客 用 户 信 息                  *\n");
	printf("*                 2. 旅 客 用 户 信 息 列 表            *\n");
	printf("*                 3. 旅 客 用 户 增 加                  *\n");
	printf("*                 4. 旅 客 用 户 删 除                  *\n");
	printf("*                 5. 旅 客 用 户 修 改                  *\n");
	printf("*                 6. 返 回 上 级 菜 单                  *\n");
	printf("*                                                       *\n");
	selectPrint();
	

}

void manTrainWelcome()
{
	system("clear");
	titlePrint();
	printf("*                                                      *\n");
	printf("*                  1. 车 次 查 询                      *\n");
	printf("*                  2. 车 次 列 表 查 询                *\n");
	printf("*                  3. 车 次 增 加                      *\n");
	printf("*                  4. 车 次 删 除                      *\n");
	printf("*                  5. 车 次 修 改                      *\n");
	printf("*                  6. 返 回 上 级 菜 单                *\n");
	printf("*                                                      *\n");
	selectPrint();

}

void title()
{
	system("clear");
	titlePrint();
	printf("*                                                       *\n");
	printf("*                                                       *\n");

}

void hideWelcome()
{
	printf("\n");
	printf("*********************************************************\n");
	printf("*                                                       *\n");
	printf("*                                                       *\n");
	printf("*                      你有新消息    !!                 *\n");
	printf("*                                                       *\n");
	printf("*               您 排 队 的 票 已 经 可 以 预 订        *\n");
	printf("*   请 您 现 在 就 去 预 订 ，如 果 不 预 定 则 作 废   *\n");
	printf("*                                                       *\n");
	printf("*                                                       *\n");
	printf("*                                                       *\n");
	printf("*********************************************************\n");
	printf("\n");
}
