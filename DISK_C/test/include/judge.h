#ifndef _judge_h
#define _judge_h

void input_database(char* account1, char* password1,char* id1);//存储新用户输入的账号和密码
int judge_password(char* account1, char* password1);//确认账号和密码是否匹配
int judge_blank1(char* str, int x, int y);//检验用户注册界面信息是否输入为空
int judge_account(char *account1);//检验用户注册账号是否存在
int judge_id(char *id1);//检验用户注册身份证后四位是否存在
int judge_len(char *a);//检验用户注册账号长度是否符合最小长度要求
int judge_lenaccount(char *account);//检验用户注册密码账号是否符合最大长度要求
int judge_lenpassword(char *password);//检验用户注册密码长度是否符合最大长度要求
int judge_lenid(char *id);//检验用户注册身份证后四位长度是否符合四位长度要求
int judge_correct(char *account,char *password);//检验用户注册时密码与确认密码是否一致
int judge_len1(char *password);//检验用户注册密码长度是否符合最小长度要求
int judge_account(char *account1);//检验用户注册账号是否存在
int lookforpassword(char* account1,char* id1);//甯姪鐢ㄦ埛鎵惧洖瀵嗙爜
#endif
