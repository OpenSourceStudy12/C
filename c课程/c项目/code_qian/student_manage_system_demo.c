#define _TEC_MENU_ 500
#include "student.h"

int menu()
{
    int status = 0;
    pstu_info ptr = NULL;
    while(1)
    {
        switch(status)
        {
            case 0:
            {
                printf("1.学生登录\n");
        	    printf("2.教师登录\n");
        	    printf("3.管理员登录\n");
        	    printf("999出\n");
                scanf("%d", &status);

                break;
            }
            case 1:
            {
                break;
            }   
            case 2:
            {
                int no;
				char password[32];
				printf("请输入序号：");
				scanf("%d", &no);
				printf("请输入密码：");
				scanf("%s", password);
				p_tec_info = tec_find_byid(no);

				if(NULL != p_tec_info && 0 == strcmp(p_tec_info->password, password))
				      status = _TEC_MENU_;
				else
				{
				      printf("序号或密码错误!\n");
					  status = 0;
				}
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            case _TEC_MEU_:
            {
                int cmd;
				printf("1.查看全部学生\n");
				printf("2.查看总分排名\n");
				printf("3.查看数学成绩排名\n");
				printf("4.查看C语言成绩排名\n");
				printf("5.查看语文成绩排名\n");
				printf("6.修改学生信息\n");
				printf("7.查看自己的信息\n");
                printf("8.修改自己的密码\n");
				printf("9.修改稿自己的姓名\n");
				printf("10.返回上一层");
                scanf("%d", &cmd);

                if(cmd < 1 || cmd >10)
				{
					printf("输入错误\n");
				    status = _TEC_MENU_;
					break;
				}

                status = _TEC_MENU_ + cmd;
				break;
            }
            case _TEC_MENU_ + 2:
            {
                stu_print_bytotal();
                status = _TEC_MENU_;
                break;
            }
            case _TEC_MENU_ + 6:
            {
                int num;
                printf("输入学号\n");
                scanf("%d", num);
                ptr = stu_find_byno(num);
                if(ptr!=NULL)
                    status = _TEC_MEU_ + _STU_CHANG_;
                else
                {
                    status = _TEC_MENU_;
                }
                break;
            }
            case _TEC_MEU_ + _STU_CHANG_
            {
                 int cmd;
                 printf("1.修改语文成绩"); 
                 printf("2.修改数学")
                 printf("3.修改C语言");
                 printf("4.返回上一层");
                 scanf("%d", &cmd);
                 status = _TEC_MEU_ + _STU_CHANG_ + cmd;
                 break;
            }
            case _TEC_MEU_ + _STU_CHANG_ + 1:
            {
                int score;char ch;
                print("输入新的语文成绩");
                scanf("%d", score);
                printf("确认修改n/y");
                while((ch=getchar())=='\n');  
                if(ch == 'y') 
                   ptr->chinese = score;
                else
                {
                   status = _TEC_MEU_ + _STU_CHANG_;
                   break;
                }  
                printf("是否保存到文件？n/y");                
                while((ch=getchar())=='\n');                
                if(ch == 'y')
                    stu_save();
                else
                {
                   status = _TEC_MEU_ + _STU_CHANG_;
                   break;
                }  
                stu_print_byid(pt->num);
                status = _TEC_MEU_ + _STU_CHANG_;
                break;
            } 
            default:
            break;
        }//switch
          if(status ==999)
          {
          break;
          }
    }//while
}
