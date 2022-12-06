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
#include"voice.h"
#include"video1.h"
#include"sport.h"
#include"shijiao.h"
#include"info.h"
int animecenter(int *func,int *func_sport)
{
	int choose=0;
	cleardevice();
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	bg_animecenter();
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      	MouseS=0;	
		if(mouse_press(80,110,200,150)==2)
		  	MouseS=1;	
		if(mouse_press(80,110,200,150)==1)//动画1
		{
			setfillstyle(1,BLUE);
			bar(80,110,200,150);
		
			puthz(82,115,"跳绳动画",24,30,LIGHTRED);
			choose=1;
			break;
		}
		if(mouse_press(480,110,600,150)==2)
		  	MouseS=1;	
		if(mouse_press(480,110,600,150)==1)//动画2
		{
			setfillstyle(1,BLUE);
			bar(480,110,600,150);
		
			puthz(482,115,"举重动画",24,30,LIGHTRED);
			choose=2;
			break;
		}
		if(mouse_press(80,360,200,400)==2)
		  	MouseS=1;	
		if(mouse_press(80,360,200,400)==1)//动画3
		{
			setfillstyle(1,BLUE);
			bar(80,360,200,400);
		
			puthz(98,365,"开合跳",24,30,LIGHTRED);
			choose=3;
			break;
		}
		if(mouse_press(480,360,600,400)==2)
		  	MouseS=1;	
		if(mouse_press(480,360,600,400)==1)//动画4
		{
			setfillstyle(1,BLUE);
			bar(480,360,600,400);
		
			puthz(482,365,"仰卧起坐",24,30,LIGHTRED);
			choose=4;
			break;
		}
		if(mouse_press(5,5,48,33)==2)
		  	MouseS=1;	
		if(mouse_press(5,5,48,33)==1)//返回 
		{
			setfillstyle(1,BLUE);
			bar(5,5,48,33);
			puthz(10,10,"返回",16,20,LIGHTRED);
			choose=5; 
			break;
	 	}

	}
	delay(200);
	clrmous(MouseX,MouseY);
	cleardevice();
	switch(choose)
	{
		case 1:
		delay(100);
		cleardevice();
		*func_sport=4;
		*func=18;
		return ;
		
		case 2:
		delay(100);
		cleardevice();
		*func_sport=1;
		*func=15;
		return ;
		
		case 3:
		delay(100);
		cleardevice();
		*func_sport=2;
		*func=16;
		return ;
		
		case 4:
		delay(100);
		cleardevice();
		*func_sport=3;
		*func=17;
		return ;
		
		case 5:
		delay(100);
		cleardevice();
		*func=19;
		return ;
		
		}   

}

int pecenter(int *func)
{
	int choose=0;
	bg_pecenter();
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	while(choose==0)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      	MouseS=0;	
		if(mouse_press(240,180,400,230)==2)
		  	MouseS=1;	
		if(mouse_press(240,180,400,230)==1)//基本信息
		{
			setfillstyle(1,BLUE);
			bar(240,180,400,230);
		
			puthz(260,193,"动画示教",24,30,LIGHTRED);
			choose=1;
			break;
		}
		if(mouse_press(240,300,400,350)==2)
		  	MouseS=1;	
		if(mouse_press(240,300,400,350)==1)//健康信息
		{
			setfillstyle(1,BLUE);
			bar(240,300,400,350);
		
			puthz(260,313,"视频示教",24,30,LIGHTRED);
			choose=2;
			break;
		}
		if(mouse_press(500,400,580,450)==2)
		  	MouseS=1;	
		if(mouse_press(500,400,580,450)==1)//返回
		{
			setfillstyle(1,BLUE);
			bar(500,400,580,450);
		
			puthz(517,414,"返回",24,24,LIGHTRED);
			choose=3;
			break;
		}
	}
	delay(200);
	clrmous(MouseX,MouseY);
	cleardevice();
	switch(choose)
	{
		case 1:
		delay(100);
		cleardevice();
		*func=5;
		return ;
		
		case 2:
		delay(100);
		cleardevice();
		*func=20;
		return ;
		
		case 3:
		delay(100);
		cleardevice();
		*func=4;
		return ;
		
		}   
}

int videocenter(int *func,int *func_shijiao)
{
	int choose=0;
	bg_videocenter();
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	while(choose==0)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      	MouseS=0;	
		if(mouse_press(240,120,400,170)==2)
		  	MouseS=1;	
		if(mouse_press(240,120,400,170)==1)//视频1
		{
			setfillstyle(1,BLUE);
			bar(240,120,400,170);
		
			puthz(278,133,"太极拳",24,30,LIGHTRED);
			choose=1;
			break;
		}
		if(mouse_press(80,280,240,330)==2)
		  	MouseS=1;	
		if(mouse_press(80,280,240,330)==1)//视频2
		{
			setfillstyle(1,BLUE);
			bar(80,280,240,330);
		
			puthz(118,293,"舞蹈操",24,30,LIGHTRED);
			choose=2;
			break;
		}
		if(mouse_press(400,280,560,330)==2)
		  	MouseS=1;	
		if(mouse_press(400,280,560,330)==1)//视频3
		{
			setfillstyle(1,BLUE);
			bar(400,280,560,330);
		
			puthz(455,293,"瑜伽",24,30,LIGHTRED);
			choose=3;
			break;
		}
		if(mouse_press(500,400,580,450)==2)
		  	MouseS=1;	
		if(mouse_press(500,400,580,450)==1)//返回
		{
			setfillstyle(1,BLUE);
			bar(500,400,580,450);
		
			puthz(517,414,"返回",24,24,LIGHTRED);
			choose=4;
			break;
		}
	}
	delay(200);
	clrmous(MouseX,MouseY);
	cleardevice();
	switch(choose)
	{
		case 1:
		delay(100);
		cleardevice();
		*func=21;
		*func_shijiao=1;
		return ;
		
		case 2:
		delay(100);
		cleardevice();
		*func=22;
		*func_shijiao=2;
		return ;
		
		case 3:
		delay(100);
		cleardevice();
		*func_shijiao=3;
		*func=23;
		return ;

		case 4:
		delay(100);
		cleardevice();
		*func=19;
		return ;
		
		}   

}

int shijiao1(int *func,int *func_shijiao)
{
	int choose=0;
	bg_shijiao1();
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	
	while(choose==0)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      	MouseS=0;	
		if(mouse_press(260,360,380,420)==2)
		  	MouseS=1;	
		if(mouse_press(260,360,380,420)==1)
		{
			setfillstyle(1,LIGHTRED);
			bar(260,360,380,420);
			pieslice(260,390,90,270,30);
			pieslice(380,390,270,360,30);
			pieslice(380,390,0,90,30);				
			setcolor(LIGHTRED);
			line(260,360,260,420);
			line(380,360,380,420);
			line(380,390,410,390);
			puthz(260,375,"开始学习",24,30,WHITE);
			choose=1; 
			break;
	 	} 
	 	if(mouse_press(0,0,60,60)==2)
		  	MouseS=1;
	 	if(mouse_press(0,0,60,60)==1)//返回 
		{
			choose=2; 
			break;
	 	}
	}
	delay(200);
	clrmous(MouseX,MouseY);
	cleardevice();
	switch(choose)
	{
		case 1://开始学习
		delay(100);
		cleardevice();
		video_shijiao(func,func_shijiao);
		return ;
		
		case 2://返回 
		delay(100);
		cleardevice();
		*func=20;
		return ;
		}   

}

int shijiao2(int *func,int *func_shijiao)
{
	int choose=0;
	bg_shijiao2();
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	
	while(choose==0)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      	MouseS=0;	
		if(mouse_press(260,360,380,420)==2)
		  	MouseS=1;
		if(mouse_press(260,360,380,420)==1)//开始学习
		{
			setfillstyle(1,LIGHTRED);
			bar(260,360,380,420);
			pieslice(260,390,90,270,30);
			pieslice(380,390,270,360,30);
			pieslice(380,390,0,90,30);				
			setcolor(LIGHTRED);
			line(260,360,260,420);
			line(380,360,380,420);
			line(380,390,410,390);
			puthz(260,375,"开始学习",24,30,WHITE);
			choose=1; 
			break;
	 	} 
	 	if(mouse_press(0,0,60,60)==2)
		  	MouseS=1;
	 	if(mouse_press(0,0,60,60)==1)//返回 
		{
			choose=2; 
			break;
	 	}
	}
	delay(200);
	clrmous(MouseX,MouseY);
	cleardevice();
	switch(choose)
	{
		case 1://开始学习
		delay(100);
		cleardevice();
		video_shijiao(func,func_shijiao);
		return ;
		
		case 2://返回 
		delay(100);
		cleardevice();
		*func=20;
		return ;
		}   

}

int shijiao3(int *func,int *func_shijiao)
{
	int choose=0;
	bg_shijiao3();
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	
	while(choose==0)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      	MouseS=0;	
		if(mouse_press(260,360,380,420)==2)
		  	MouseS=1;
		if(mouse_press(260,360,380,420)==1)//开始学习
		{
			setfillstyle(1,LIGHTRED);
			bar(260,360,380,420);
			pieslice(260,390,90,270,30);
			pieslice(380,390,270,360,30);
			pieslice(380,390,0,90,30);				
			setcolor(LIGHTRED);
			line(260,360,260,420);
			line(380,360,380,420);
			line(380,390,410,390);
			puthz(260,375,"开始学习",24,30,WHITE);
			choose=1; 
			break;
	 	} 
	 	if(mouse_press(0,0,60,60)==2)
		  	MouseS=1;
	 	if(mouse_press(0,0,60,60)==1)//返回 
		{
			choose=2; 
			break;
	 	}
	}
	delay(200);
	clrmous(MouseX,MouseY);
	cleardevice();
	switch(choose)
	{
		case 1://开始学习
		delay(100);
		cleardevice();
		video_shijiao(func,func_shijiao);
		return ;
		
		case 2://返回 
		delay(100);
		cleardevice();
		*func=20;
		return ;
		}   

}

void video_shijiao(int *func,int *func_shijiao)
{
	int i=1;
	int space=0;
	char txt[5];
	char txt1[5];
	char text1[40];
	char text2[40];
	char text[40];
	if(*func_shijiao==1)
	{
	strcpy(text1, ".//shijiao//taiji//");
	}
	if(*func_shijiao==2)
	{
	strcpy(text1, ".//shijiao//wudao//");
	}
	if(*func_shijiao==3)
	{
	strcpy(text1, ".//shijiao//yujia//");
	}
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
				*func=20+*func_shijiao; 
				return;
			}
		}
	}
	space=0;
	cleardevice();
}
