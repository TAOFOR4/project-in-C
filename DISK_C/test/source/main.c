#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include"hz.h"
#include"loggin.h" 
#include"draw.h"
#include"drawpage.h"
#include"mouse.h" 
#include"keyboard.h" 
#include"judge.h"
#include"clear.h"
#include"self.h"
#include"happy.h"
#include"book1.h"
#include"scenery1.h"
#include"video1.h"
#include"sport.h"
#include"shijiao.h"
#include"info.h"
void main(void)
{
	int* func;
	int *func_video1;
	user *u;
	health *h;
	int *func_sport=0;
	int *func_shijiao=0;
	int drive=VGA,mode=VGAHI;
	initgraph(&drive,&mode,"c:\\borlandc\\bgi");
	*func =0;
	*func_video1=0;
	mouseinit();
	loading1();
	cleardevice();
	delay(400);
	while (1)
	{
		clrmous(MouseX,MouseY);
		newmouse(&MouseX,&MouseY,&press);
		switch (*func)
		{
			case 0:
			login(u,func);//登录 
			break;
			case 1:
			registry(u,func);//注册 
			break;
			case 2:
			forget(u,func);//找回密码 
			break; 
			case 3:
			selfcenter(u,h,func);//个人信息 
			break;
			case 4:
			center(u,func);//主页面 
			break; 
			case 5 :
			animecenter(func,func_sport);
			break;
			case 6:
			happy(u,func);//体育休闲 
			break;
			case 7:
			book_main(func);//书 
			break; 
			case 8:
			scenery_main(func);//风景
			break; 
			case 9:
			paint(func);//画画
			break; 
			case 11:
			playvideo(func,func_video1);
			break;
			case 12:
			video_1(func,func_video1);
			break;
			case 15:
			sport1_main(func,func_sport);
			break; 
			case 16:
			sport2_main(func,func_sport);
			break; 
			case 17:
			sport3_main(func,func_sport);
			break;
			case 18:
			sport4_main(func,func_sport);
			break;
			case 19:
			pecenter(func);
			break;
			case 20:
			videocenter(func,func_shijiao);
			break;
			case 21:
			shijiao1(func,func_shijiao);
			break;
			case 22:
			shijiao2(func,func_shijiao);
			break;
			case 23:
			shijiao3(func,func_shijiao);
			break;
			case 24:
			basicinfo(u,func);//基本信息 
			break;
			case 25:
			healthinfo(u,func);//健康信息
			break; 
			case 26://修改昵称
			changename(u,func);
			break; 
			case 27:
			healthdata(u,h,func);
			break;
			case 28:
			add(u,h,func);
			break;
			case 29:
			selfcenter1(u,func);
			break;
			case 30:
			jieshao(func);
			break; 
			case 31:
			healthadvice(u,func);
			/*case 8:
			book_kite(u,func);//追风筝的人 
			break;
			case 9:
			book_love(u,func);//怦然心动 
			break;
			case 10:
			book_great(u,func);//了不起的盖茨比
			break;
			case 11:
			book_agan(u,func);//阿甘正传 
			break;*/
			/*case 14:
			tianshan1(func);//天山 
			break; 
			case 15:
			buda1(func);//布达拉宫 
			break;
			case 16:
			gugong1(func);//故宫 
			break;
			case 17:
			xiangzi1(func);//巷子 
			break;
			case 18:
			huanghe1(func);//黄鹤楼 
			break;
			case 19:
			tengwang1(func);//滕王阁 
			break;
			case 20:
			taihang1(func);//太行山 
			break;*/
			
    	}
	}
}




