#include"menu.h"
#include"user.h"

//头打印
void head_print()
{
	system("clear");
	//printf("\t\t\t\t************************************************************\n\n");
	printf("\t\t\t*****************************************************************\n\n");
	printf("\t\t\t****************欢 迎 来 到 火 车 订 票 系 统********************\n\n");
	printf("\t\t\t*****************************************************************\n");
	//printf("\t\t\t\t************************************************************\n");
}

//主菜单页面
void main_menu_print()
{
	head_print();
	//printf("\t\t\t\t***********主     菜    单*************\n");
	printf("\n\t\t\t\t                请 输 入 选 项");
	printf("\n\t\t\t\t     --------------------------------------\n");
	printf("\n\t\t\t\t                --1用 户 注 册--\n");
	printf("\n\t\t\t\t                --2用 户 登 录--\n");
	printf("\n\t\t\t\t                --3管 理 员 登 录--\n");
	printf("\n\t\t\t\t                --0退       出--\n");
	printf("\n\t\t\t\t     --------------------------------------\n");

}

//用户注册页面
void new_user_menu_print()
{
	//head_print();
	system("clear");
	printf("\n\t\t\t\t******************用  户  注  册********************\n\n");
}

//用户登录页面
void user_log_print()
{
	head_print();
	printf("\n\t\t\t\t***************用   户   登   录******************\n\n");
}
//用户菜单页
void user_menu_print(PUser puser)
{
	//head_print();
	system("clear");
	printf("\n\t\t\t\t*************用   户   管   理   菜   单*************\n");	
	printf("\t用户名:%s",puser->name);
	printf("\n\t\t\t\t                   请 输 入 选 项");
	printf("\n\t\t\t\t       --------------------------------------\n");
	printf("\n\t\t\t\t                  --1信 息 查 询--\n");
	printf("\n\t\t\t\t                  --2信 息 修 改--\n");
	printf("\n\t\t\t\t                  --3车 次 查 询--\n");
	printf("\n\t\t\t\t                  --4订       票--\n");
	printf("\n\t\t\t\t                  --5退       票--\n");
	printf("\n\t\t\t\t                  --6注       销--\n");
	printf("\n\t\t\t\t                  --0退       出--\n");
	printf("\n\t\t\t\t       --------------------------------------\n");
}

//管理员登录打印
void admin_log_print()
{
	head_print();
	printf("\n\t\t\t\t***************管 理 员 登 录*******************\n");
}

//管理员菜单页面
void admin_menu_print(PAdmin admin)
{
	//head_print();
	system("clear");
	printf("\n\t\t\t\t***************管   理   员   菜   单***************\n");	
	printf("\t管理员:%s\n\n",admin->name);
	printf("\n\t\t\t\t                   请 输 入 选 项");
	printf("\n\t\t\t\t       --------------------------------------\n");
	printf("\n\t\t\t\t                  --1信 息 查 询--\n");
	printf("\n\t\t\t\t                  --2信 息 修 改--\n");
	printf("\n\t\t\t\t                  --3管 理 车 次--\n");
	printf("\n\t\t\t\t                  --4管 理 用 户--\n");
	printf("\n\t\t\t\t                  --5注       销--\n");
	printf("\n\t\t\t\t                  --0退       出--\n");
	printf("\n\t\t\t\t       --------------------------------------\n");


}

//车次信息管理页面
void admin_train_menu_print()
{
	//head_print();
	//printf("\n\t\t\t\t             ************管 理 员 菜 单**************\n\n");
	system("clear");	
	printf("\n\t\t\t\t***************车   次   管   理   菜   单*************\n");
	printf("\n\t\t\t\t                   请 输 入 选 项");
	printf("\n\t\t\t\t       --------------------------------------\n");
	printf("\n\t\t\t\t                 --1查 看 车 次 信 息--\n");
	printf("\n\t\t\t\t                 --2添 加 车 次 信 息--\n");
	//printf("\n\t\t\t\t                 --3修 改 车 次 信 息--\n");
	printf("\n\t\t\t\t                 --3删 除 车 次 信 息--\n");
	printf("\n\t\t\t\t                 --0返 回 上 一 级-----\n");
	printf("\n\t\t\t\t       --------------------------------------\n");
}

//用户信息管理页面
void admin_user_menu_print()
{
	//head_print();
	//printf("\n\t\t\t\t             ***********管 理 员 菜 单***************\n\n");
	system("clear");	
	printf("\n\t\t\t\t****************用  户  管  理  菜  单***************\n");
	printf("\n\t\t\t\t                   请 输 入 选 项");
	printf("\n\t\t\t\t       --------------------------------------\n");
	printf("\n\t\t\t\t                --1查 看 用 户 信 息--\n");
	//printf("\n\t\t\t\t                --2修 改 用 户 信 息--\n");
	printf("\n\t\t\t\t                --2删 除 用 户 信 息--\n");
	printf("\n\t\t\t\t                --0返 回 上 一 级----\n");
	printf("\n\t\t\t\t       --------------------------------------\n");
}


PUser  new_user_deal(PUser user_head)
{
	new_user_menu_print();
	user_head = new_user_login(user_head);//调用新用户注册函数
	return user_head;
}

//用户登录处理函数
int user_login_deal(PInfo pinfo)
{
	int logout_flag = 0,exit_flag = 0;
	char ch;
	PUser puser = NULL;
	if(!user_login((*pinfo).Head_user,&puser))
	{
		adv_book_deal(pinfo->Head_train,puser);
		user_menu_print(puser);//用户菜单页面
		ch = getchar();
		while(getchar() != '\n');
		
		while(1)
		{
			switch(ch)
			{
				case USER_INFO_SEARCH:
					//system("clear");
					user_info_search(puser);//用户信息查询函数
					//sleep(1);
					break;
				case USER_INFO_CHANGE://信息修改函数
					user_info_change(puser);
					sleep(1);
					break;
				case USER_TRAIN_SEARCH:
					//车次查询函数
					train_num_search((*pinfo).Head_train);
					//sleep(1);
					break;
				case TICKET_BOOK:
					//订票函数
					//printf("\n站站查询函数\n");
					ticket_reservation(puser,(*pinfo).Head_train);
					sleep(1);
					break;
				case TICKET_REFOUND:
					//用户退票函数
					//printf("\n用户退票函数\n");
					ticket_refund(puser,(*pinfo).Head_train);
					sleep(1);
					break;
				case USER_LOGOUT:
					//注销
					logout_flag = 1;
					break;
				case EXIT://退出
					exit_flag = 1;
					break;
				default :
					printf("\n无效的输入，请重新输入\n");
					sleep(1);
					break;
			}
			if(logout_flag || exit_flag)
			{
				//flag = 0;
				break;
			}
			user_menu_print(puser);
			ch = getchar();
			while(getchar() != '\n');
		}
		if(exit_flag)
			return 1;
		else
			return 0;
	}
	return 0;
}

//管理员登录处理
int admin_login_deal(PInfo pinfo)
{
	char name[NAME_SIZE],passward[PASS_NUM];
	char ch;
	int state,logout_flag = 0,exit_flag = 0;
	
	//管理员登录打印
	admin_log_print();

	printf("\n帐  号:");
	scanf("%s",name);
	while(getchar() != '\n');
	printf("\n密  码:");
	scanf("%s",passward);
	while(getchar() != '\n');

	//校验管理员登录是否成功
	state = admin_login((*pinfo).Head_admin,name,passward);
	
	if(state == -1)
	{
		printf("\n用户名错误，请重新登录\n");
		sleep(1);
		return 0;
	}
	else if(state == 1)
	{
		printf("\n密码错误，请重新登录\n");
		sleep(1);
		return 0;
	}
	else
	{
		admin_menu_print((*pinfo).Head_admin);//管理员菜单页面
		ch = getchar();
		while(getchar() != '\n');
		while(1)//管理员登录
		{
			switch(ch)
			{

				case ADMIN_INFO_SEARCH://信息查询函数
					admin_info_look((*pinfo).Head_admin);
					break;

				case ADMIN_INFO_CHANGE://修改信息函数
					admin_info_change((*pinfo).Head_admin);
					break;

				case TRAIN_MANAGE://管理车次函数
					(*pinfo).Head_train = admin_train_manage((*pinfo).Head_train);
					break;
				case USER_MANAGE://管理用户信息函数
					(*pinfo).Head_user = admin_user_manage((*pinfo).Head_user,(*pinfo).Head_train);
					break;
				case ADMIN_LOGOUT://注销
					logout_flag = 1;
					break;
				case EXIT://退出
					exit_flag = 1;
					break;
				default :
					printf("\n无效的输入，请重新输入\n");
					sleep(1);
					break;
			}
			if(logout_flag || exit_flag)
				break;

			admin_menu_print((*pinfo).Head_admin);//管理员菜单页面
			ch = getchar();
			while(getchar() != '\n');
		}
		if(logout_flag)
			return 0;
		else
			return 1;
	}

}

PTra admin_train_manage(PTra head_train)
{
	char ch;
	int back_flag = 0;
	admin_train_menu_print();
	scanf("%c",&ch);
	while(getchar() != '\n');
	while(1)
	{	
		switch(ch)
		{
			case TRAIN_LOOK://查看车次
				train_look(head_train);
				break;
			case TRAIN_ADD://添加车次
				head_train = train_add(head_train);
				break;
		//	case TRAIN_CHANGE://修改车次
		//		train_change(head_train);
		//		break;
			case TRAIN_DEL://删除车次
				head_train = train_del(head_train);
				break;
			case BACK:
				back_flag = 1;
				break;
			default:
				printf("\n无效的输入，请重新输入\n");
				sleep(1);
				break;
			
		}
		if(back_flag)
			break;
		admin_train_menu_print();
		scanf("%c",&ch);
		while(getchar() != '\n');
	}
	return head_train;
}

PUser admin_user_manage(PUser head_user,PTra head_train)
{
	char ch;
	int back_flag = 0;
	admin_user_menu_print();
	scanf("%c",&ch);
	while(getchar() != '\n');
	while(1)
	{	
		switch(ch)
		{
			case USER_LOOK://查看用户
				user_look(head_user);
				break;
			//case USER_CHANGE://修改用户
			//	user_change();
			//	break;
			case USER_DEL:
				head_user = user_del(head_user,head_train);//删除用户
				break;
			case BACK:
				back_flag = 1;
				break;
			default:
				printf("\n无效的输入，请重新输入\n");
				sleep(1);
				break;
			
		}
		if(back_flag)
			break;
		admin_user_menu_print();
		scanf("%c",&ch);
		while(getchar() != '\n');
	}
	return head_user;
}
