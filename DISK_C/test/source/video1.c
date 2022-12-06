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
#include"mouse.h" 
#include"keyboard.h" 
#include"judge.h"
#include"clear.h"
#include"self.h"
#include"happy.h"
#include"book1.h"
#include"scenery1.h"
#include"voice.h"
#include"video1.h"
void playvideo(int *func,int *func_video1)
{
	cleardevice();
	setbkcolor(BLACK);
	putbmp(10,65,".//pic//1.bmp");
	putbmp(220,65,".//pic//2.bmp");
	putbmp(430,65,".//pic//3.bmp");
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	setfillstyle(1,WHITE);
	bar(20,5,60,25);
	bar(40,375,170,405);
	bar(240,375,370,405);
	bar(400,375,620,405);
	puthz(20,5,"返回",16,20,LIGHTRED);
	puthz(45,380,"怦然心动",24,30,LIGHTRED);
	puthz(245,380,"阿甘正传",24,30,LIGHTRED);
	puthz(405,380,"了不起的盖茨比",24,30,LIGHTRED);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(20,5,60,25)==1)
		{
			delay(100);
			*func=6;
			return ;
		}
		if(mouse_press(40,375,170,405)==1)
		{
			/*Barl(120,620,240,680,26229);
			write_hz48("观看",135,625,33808);*/
			*func_video1=1;
			delay(100);
			*func=12;
			return;
		}
		
			if(mouse_press(240,375,370,405)==1)
		{
			/*Barl(440,620,560,680,26229);
			write_hz48("观看",455,625,33808);*/
			*func_video1=2;
			delay(100);
			*func=12;
			return;
		}
		if(mouse_press(400,375,620,405)==1)
		{
			/*Barl(760,620,880,680,26229);
			write_hz48("观看",775,625,33808);*/
			*func_video1=3;
			delay(100);
			*func=12;
			return;
		}
	 } 
}

void video_1(int *func,int *func_video1)
{
	int i=1;
	int space=0;
	char txt[5];
	char txt1[5];
	char text1[40];
	char text2[40];
	char text[40];
	cleardevice();
	strcpy(text1, ".//video");
	itoa(*func_video1, txt, 10);
	strcat(text1,txt);
	strcat(text1, "//");
	setbkcolor(BLACK);
	puthz(200,10,"按键盘退出键可以暂停视频",16,20,LIGHTRED);
	//draw_tri(340,640,340,730,280,685,6); 
	//draw_tri(680,640,680,730,740,685,6);
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(i<120)
		{
			itoa(i, txt1, 10);
			strcpy(text, text1);
			strcat(text,txt1);
			strcat(text,".bmp");
			//sprintf(text,"c:\\test\\video1\\%d.bmp",i);
			putbmp(0,60,text);
			++i;
			memset(text, 0, sizeof(char) * 40);
		}
		else
		{
			*func=11; 
			return;
		}
		newmouse(&MouseX,&MouseY,&press);
		if (bioskey(1))
		{
			if(bioskey(0)==0x011b)
			{
				while(1)
				{
					newmouse(&MouseX,&MouseY,&press);
					//setfillstyle(1,BROWN);
					//bar(0,5,60,30);
					puthz(5,10,"退出",16,20,LIGHTRED);
					//bar(55,5,115,30);
					puthz(60,10,"播放",16,20,LIGHTRED);
					if(mouse_press(0,5,60,30)==1)
					{
						space=1;
						clrmous(MouseX,MouseY);
						break;
					}if(mouse_press(55,5,115,30)==1)
					{
						clrmous(MouseX,MouseY);
						setfillstyle(1,BLACK);
						bar(0,5,115,30);
						space=0;
						clrmous(MouseX,MouseY);
						break;
					}
					
				}
				//continue;
			}
			if(space==1)
			{
				*func=11; 
				return;
			}
		}
	}
	space=0;
	cleardevice();
}
