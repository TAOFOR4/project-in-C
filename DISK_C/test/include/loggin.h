#ifndef _LOGGIN_H
#define _LOGGIN_H

#include"data.h"

int login(user *u,int* func);//登陆中心跳转
int registry(user *u,int* func);//注册中心跳转
int welcom();//欢迎中心跳转
int forget(user *u,int* func);//忘记密码界面跳转
int center(user *u,int* func);
#endif
