#include"common.h"

                           // 跳转页面的选择
int main()
{
	int choose = 0; 
	system("clear");
	init();
	while (1)
	{
		switch(choose)
		{
			case MAIN_MENU : choose = mainChoose();       // 进入主菜单
			break;
			case LOGIN :     choose = login();            // 进入登录菜单
			break;
			case REGISTER:   choose = cregister();        // 到注册菜单
			break; 
			case CUSTOMER_MENU : choose = customer();     // 到用户菜单
			break;
			case C_INFORMATION : choose = selfCustomerInforamtion();  
						                      // 查看用户基本信息
			break;
			case C_SEARCH:   choose = selfSelectTrain();  // 查找车次
			break;
			case C_BOOK :    choose = selfBookTrain();    // 订票操作        
			break;
			case C_REFUND:   choose = selfUBookTrain();   // 退票操作         
			break;                                  

			case ADMIN_MENU : choose = admin();           // 到管理员菜单
			break;
			
			case A_C_MENU:   choose =  manCustomer();     // 管理客户信息
			break;
			case A_T_MENU:	 choose = manTrain();         // 管理车次信息
			break;	
			case A_STA:      choose =  count();           // 统计         
			break;	

			case A_C_NAME: choose = adminSearchByName();  // 旅客用户查询      
			break;
			case A_C_ALL:  choose = adminSearchAll();     // 旅客用户列表查询   
			break;
			case A_C_ADD:  choose = adminAddUser();       // 增加用户
			break;	
			case A_C_DEL:  choose = adminDeleteUser();    // 删除用户
			break;	
			case A_C_UPDATE: choose = adminUpdateUser();  // 修改用户
			break;	

			case A_T_NU:  choose = adminSearchTrainByNu(); // 列车查询
			break;				
			case A_T_ALL: choose = adminSearchAllTrain();  // 列车列表查询
			break;
			case A_T_ADD: choose = adminAddTrain();        // 增加列车
			break;
			case A_T_DEL:  choose = adminDelTrain();       // 删除列车
			break;
			case A_T_UPDATE: choose = adminUpdate();       // 更新列车
			break;
			default:
				;
	
		}		
	}
}



