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
			login(u,func);//��¼ 
			break;
			case 1:
			registry(u,func);//ע�� 
			break;
			case 2:
			forget(u,func);//�һ����� 
			break; 
			case 3:
			selfcenter(u,h,func);//������Ϣ 
			break;
			case 4:
			center(u,func);//��ҳ�� 
			break; 
			case 5 :
			animecenter(func,func_sport);
			break;
			case 6:
			happy(u,func);//�������� 
			break;
			case 7:
			book_main(func);//�� 
			break; 
			case 8:
			scenery_main(func);//�羰
			break; 
			case 9:
			paint(func);//����
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
			basicinfo(u,func);//������Ϣ 
			break;
			case 25:
			healthinfo(u,func);//������Ϣ
			break; 
			case 26://�޸��ǳ�
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
			book_kite(u,func);//׷���ݵ��� 
			break;
			case 9:
			book_love(u,func);//��Ȼ�Ķ� 
			break;
			case 10:
			book_great(u,func);//�˲���ĸǴı�
			break;
			case 11:
			book_agan(u,func);//�������� 
			break;*/
			/*case 14:
			tianshan1(func);//��ɽ 
			break; 
			case 15:
			buda1(func);//�������� 
			break;
			case 16:
			gugong1(func);//�ʹ� 
			break;
			case 17:
			xiangzi1(func);//���� 
			break;
			case 18:
			huanghe1(func);//�ƺ�¥ 
			break;
			case 19:
			tengwang1(func);//������ 
			break;
			case 20:
			taihang1(func);//̫��ɽ 
			break;*/
			
    	}
	}
}




