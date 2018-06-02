#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#define CUSTOMER_DB "customer.db"

// 旅客节点
typedef struct _customer
{
	int c_id;          // 旅客id
	char c_name[10];   // 姓名
	char c_pwd[10];    // 密码
	char c_sex[5];     // 性别
	int c_phone;       // 联系电话
	int c_age;         // 年龄
	struct _customer *next;
}NCustomer, *PNCustomer;


/*
	函数作用 ：创建顾客(注册)
	
*/
PNCustomer createCustomer();

/*
	函数作用 ： 把输入的客户写入文件
*/
void writeOneCustomer(PNCustomer pcu);	

/*
	函数作用 ：打印一个用户信息
*/
void  printOneCustomer(PNCustomer pcustomer);

/*
	函数作用 ：根据姓名查找
	注意 ：要释放返回的数组空间
*/
PNCustomer * searchByName(char *name, PNCustomer phead, int *size);
/*
	函数作用 ： 打印所有用户信息
*/
void printAllCustomer(PNCustomer phead);
/*
	函数作用 ： 从文件中读取所有用户信息
*/
PNCustomer readAllCustomer();

/*
	函数作用 ： 将新添加的用户加入到用户链表的末尾
*/
PNCustomer insertCustomer(PNCustomer phead, PNCustomer pnew);

/*
	函数作用 ：根据用户id从用户链表中删除用户信息
	
*/
PNCustomer deleteCustomer(PNCustomer phead, int sid, int *isSuccess);

/*
	函数作用 ： 将用户链表写入文件中保存 
	
*/
void writeAllCustomer(PNCustomer phead);


/*
	函数作用 ：登录时比对信息
*/
int loginJudge(char *name, char *pwd, PNCustomer phead, PNCustomer *ppOne);

/*
	函数作用 ：根据id更新用户
*/
PNCustomer updateCustomer(PNCustomer phead, int sid, int *isSuccess);



#endif

