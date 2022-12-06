
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include"hz.h"
#include"loggin.h" 
#include"drawpage.h"
#include"mouse.h" 
#include"keyboard.h" 
#include"self.h"
#include"draw.h"
#include"info.h"
/***************************************************
Function：     bg_selfcenter

Description：  

Input：    void

Output：    
***************************************************/

void bg_selfcenter()
{
	setviewport(0,0,640,480,1);
	setbkcolor(BLACK);//背景颜色 
	setfillstyle(1,WHITE);
	puthz(180,20,"个人信息",32,80,RED);
	setcolor(WHITE);
	bar(250,100,450,140);//昵称 
	puthz(100,110,"昵称",24,30,WHITE);

	bar(250,160,450,200);//身高  
	puthz(100,170,"身高",24,30,WHITE);
	puthz(500,170,"厘米",24,30,WHITE);
	
	bar(250,220,450,260);//体重
	puthz(100,230,"体重",24,30,WHITE);
	puthz(500,230,"千克",24,30,WHITE);
	
	puthz(100,290,"性别",24,30,WHITE);//性别 
	
	puthz(150,350,"请勿输入空信息",24,50,RED);
	
	setfillstyle(1,DARKGRAY);
	bar(180,400,260,440);
	bar(400,400,480,440);//确认和返回 
	
	draw_man1(); 
	draw_woman1(); 
	
	setcolor(WHITE);//使按键凸显的效果
	puthz(190,410,"确定",24,30,LIGHTCYAN);
	puthz(410,410,"返回",24,30,LIGHTMAGENTA);
	
	
}



/*画已选男图标函数*/

void draw_man2(void)
{
	setcolor(CYAN);
	setfillstyle(1, CYAN);
	pieslice(290, 310, 0, 360, 30);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setcolor(WHITE);
	line(280, 318, 305, 293);
	line(305, 293, 305, 303);
	line(305, 293, 295, 293);
	circle(280, 320, 5);
}

/*画已选女图标函数*/

void draw_woman2(void)
{
	setcolor(LIGHTMAGENTA);
	setfillstyle(1, LIGHTMAGENTA);
	pieslice(410, 310, 0, 360, 30);                   
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setcolor(WHITE);                           
	line(410, 305, 410, 325);
	line(400, 315, 420, 315);
	circle(410, 300, 5);
}

void bg_back(void)//在左上角画返回键
{
	int back[] = { 30,10,10,30,30,50 };
	setcolor(LIGHTGRAY);
	setfillstyle(1, LIGHTGRAY);
	bar(30, 20, 50, 40);
	fillpoly(3, back);
}


void bg_pecenter(void)
{
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,1);	
	setfillstyle(1,BROWN);
	puthz(225,40,"体育中心",32,50,LIGHTBLUE);
	bar(240,180,400,230);
	puthz(260,193,"动画示教",24,30,WHITE);
	bar(240,300,400,350);
	puthz(260,313,"视频示教",24,30,WHITE);
	bar(500,400,580,450);
	puthz(517,414,"返回",24,24,WHITE);

}

void bg_animecenter(void)
{
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,1);	
	setfillstyle(1,BROWN);
	bar(80,110,200,150);
	bar(480,110,600,150);
	bar(80,360,200,400);
	bar(480,360,600,400);
	setfillstyle(1,BROWN);
	bar(5,5,48,33); 
	puthz(10,10,"返回",16,20,WHITE);
	puthz(82,115,"跳绳动画",24,30,WHITE);
	puthz(482,115,"举重动画",24,30,WHITE);
	puthz(98,365,"开合跳",24,30,WHITE);
	puthz(482,365,"仰卧起坐",24,30,WHITE);
}

void bg_videocenter(void)
{
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,1);	
	setfillstyle(1,BROWN);
	//puthz(220,40,"视频示教",32,32,LIGHTBLUE);
	bar(240,120,400,170);
	puthz(278,133,"太极拳",24,30,WHITE);
	bar(80,280,240,330);
	puthz(118,293,"舞蹈操",24,30,WHITE);
	bar(400,280,560,330);
	puthz(455,293,"瑜伽",24,30,WHITE);
	
	bar(500,400,580,450);
	puthz(517,414,"返回",24,24,WHITE);
	
}

void bg_shijiao1(void)
{
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,1);	
	
	puthz(260,20,"太极拳",32,32,LIGHTBLUE);
	puthz(20,100,"·课程介绍",16,16,LIGHTBLUE);
	puthz(20,120,"太极拳，国家级非物质文化遗产，是以中国传统儒、道哲学中的太极、阴阳辩证理念",16,16,LIGHTBLUE);
	puthz(20,140,"为核心思想，集颐养性情、强身健体、技击对抗等多种功能为一体，结合易学的阴阳",16,16,LIGHTBLUE);
	puthz(20,160,"五行之变化，中医经络学，古代的导引术和吐纳术形成的一种内外兼修、柔和、缓慢",16,16,LIGHTBLUE);
	puthz(20,180,"、轻灵、刚柔相济的中国传统拳术。",16,16,LIGHTBLUE);
	puthz(20,220,"·课程特点",16,16,LIGHTBLUE);
	puthz(20,240,"静心用意，呼吸自然；",16,16,LIGHTBLUE);
	puthz(20,260,"中正安舒，柔和缓慢；",16,16,LIGHTBLUE);
	puthz(20,280,"动作弧形，圆活完整；",16,16,LIGHTBLUE);
	puthz(20,300,"连贯协调，虚实分明；",16,16,LIGHTBLUE);
	puthz(20,320,"轻灵沉着，刚柔相济；",16,16,LIGHTBLUE);
	setfillstyle(1,LIGHTBLUE);
	bar(260,360,380,420);
	pieslice(260,390,90,270,30);
	pieslice(380,390,270,360,30);
	pieslice(380,390,0,90,30);
	setcolor(LIGHTBLUE);
	line(260,360,260,420);
	line(380,360,380,420);
	line(380,390,410,390);
	puthz(260,375,"开始学习",24,30,WHITE);
	bg_back();
}

void bg_shijiao2(void)
{
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,1);	
	
	puthz(260,20,"舞蹈操",32,32,LIGHTBLUE);
	puthz(20,100,"·课程介绍",16,16,LIGHTBLUE);
	puthz(20,120,"这是一次跟着音乐进行的全身热身：包括腿部动作，臀部放松，甩一甩手臂并提高心",16,16,LIGHTBLUE);
	puthz(20,140,"率。如果你重复做几次，这也可以算是有氧训练。",16,16,LIGHTBLUE);
	puthz(20,180,"·适用人群",16,16,LIGHTBLUE);
	puthz(20,200,"适合大多数初级训练者们和没有正式规律锻炼过的小白",16,16,LIGHTBLUE);
	puthz(20,240,"·练前准备",16,16,LIGHTBLUE);
	puthz(20,260,"训练前不要吃太多东西，避免饱腹状态，以免训练中出现腹部不适。",16,16,LIGHTBLUE);
	setfillstyle(1,LIGHTBLUE);
	bar(260,360,380,420);
	pieslice(260,390,90,270,30);
	pieslice(380,390,270,360,30);
	pieslice(380,390,0,90,30);
	setcolor(LIGHTBLUE);
	line(260,360,260,420);
	line(380,360,380,420);
	line(380,390,410,390);
	puthz(260,375,"开始学习",24,30,WHITE);
	bg_back();
}

void bg_shijiao3(void)
{
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,1);	
	
	puthz(275,20,"瑜伽",32,32,LIGHTBLUE);
	puthz(20,100,"·课程介绍",16,16,LIGHTBLUE);
	puthz(20,120,"瑜伽是一项有着5000年历史的关于身体、心理以及精神的练习，起源于印度，其目的",16,16,LIGHTBLUE);
	puthz(20,140,"是改善身体和心性。",16,16,LIGHTBLUE);
	puthz(20,180,"·课程特点",16,16,LIGHTBLUE);
	puthz(20,200,"瑜伽姿势运用古老而易于掌握的技巧，改善人们生理、心理、情感和精神方面的能力",16,16,LIGHTBLUE);
	puthz(20,220,"，是一种达到身体、心灵与精神和谐统一的运动方式，包括调身的体位法、调息的呼",16,16,LIGHTBLUE);
	puthz(20,240,"吸法、调心的冥想法等，以达至身心的合一。",16,16,LIGHTBLUE);
	setfillstyle(1,LIGHTBLUE);
	bar(260,360,380,420);
	pieslice(260,390,90,270,30);
	pieslice(380,390,270,360,30);
	pieslice(380,390,0,90,30);
	setcolor(LIGHTBLUE);
	line(260,360,260,420);
	line(380,360,380,420);
	line(380,390,410,390);
	puthz(260,375,"开始学习",24,30,WHITE);
	bg_back();
}

void bg_selfcenter1(user *u)//基本信息和修改，健康信息系统建议，个人收藏 
{
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,1);
	setfillstyle(1,BROWN);
	setcolor(LIGHTBLUE);
	settextstyle(1,0,4);
	puthz(220,40,"欢迎，",32,32,LIGHTBLUE);
	outtextxy(220,80,u->name);
	bar(240,150,400,200);
	puthz(260,163,"基本信息",24,30,WHITE);
	bar(240,230,400,280);
	puthz(260,243,"健康信息",24,30,WHITE);
	bar(240,310,400,360);
	puthz(260,323,"修改昵称",24,30,WHITE);
	bar(500,400,580,450);
	puthz(517,414,"返回",24,24,WHITE);
}

void bg_basicinfo(void)
{	
	cleardevice();
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,1);
	setcolor(LIGHTBLUE);
	puthz(230,60,"基本信息",32,50,LIGHTBLUE);
	puthz(120,120,"昵称",32,32,LIGHTBLUE);
	puthz(120,180,"性别",32,32,LIGHTBLUE);
	puthz(120,240,"生日",32,32,LIGHTBLUE);
	puthz(300,240,"年",32,32,LIGHTBLUE);
	puthz(380,240,"月",32,32,LIGHTBLUE);
	puthz(460,240,"日",32,32,LIGHTBLUE);
	bg_back();
}


void bg_healthinfo(void)
{	
		cleardevice();
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,1);	
	setcolor(LIGHTBLUE);
	puthz(230,60,"健康信息",32,50,LIGHTBLUE);
	puthz(120,120,"身高",32,32,LIGHTBLUE);
	puthz(400,120,"厘米",32,32,LIGHTBLUE);
	puthz(120,180,"体重",32,32,LIGHTBLUE);
	puthz(400,180,"千克",32,32,LIGHTBLUE);
	
	settextstyle(1,0,4);
	outtextxy(123,233,"BMI");
	setfillstyle(1,LIGHTBLUE);
	bar(390,230,470,280);
	pieslice(390,255,90,270,25);
	pieslice(470,255,270,360,25);
	pieslice(470,255,0,90,25);
	line(390,230,390,280);
	line(470,230,470,280);
	line(470,255,495,255);
	puthz(400,240,"建议",32,32,WHITE);
	
	bar(260,300,380,360);
	pieslice(260,330,90,270,30);
	pieslice(380,330,270,360,30);
	pieslice(380,330,0,90,30);
	line(260,300,260,360);
	line(380,300,380,360);
	line(380,330,410,330);
	puthz(260,315,"健康管理",24,30,WHITE);
	bg_back();
}

void bg_changename(user *u)
{
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,1);	
	settextstyle(1,0,4);
	puthz(120,120,"原昵称",32,32,LIGHTBLUE);
	outtextxy(240,118,u->name);
	puthz(120,200,"新昵称",32,32,LIGHTBLUE);
	setfillstyle(1,WHITE);
	bar(240,200,440,240);
	puthz(210,260,"请勿与原昵称相同！",24,24,RED);
	setfillstyle(1,LIGHTBLUE);
	bar(260,300,380,360);
	pieslice(260,330,90,270,30);
	pieslice(380,330,270,360,30);
	pieslice(380,330,0,90,30);
	setcolor(LIGHTBLUE);
	line(260,300,260,360);
	line(380,300,380,360);
	line(380,330,410,330);
	puthz(260,315,"确定修改",24,30,WHITE);
	bg_back();
}

void bg_healthdata(void)
{
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,1);	
	setcolor(LIGHTBLUE);
	line(50,100,50,280);
	line(50,280,550,280);
	puthz(120,20,"身体质量指数变化折线图",32,32,LIGHTBLUE);
	puthz(560,300,"日期",16,16,LIGHTBLUE);
	settextstyle(1,0,3);
	
	outtextxy(10,70,"BMI");
	setfillstyle(1,LIGHTBLUE);//画框 
	bar(260,380,380,440);
	pieslice(260,410,90,270,30);
	pieslice(380,410,270,360,30);
	pieslice(380,410,0,90,30);
	setcolor(LIGHTBLUE);
	line(260,380,260,440);
	line(380,380,380,440);
	line(380,410,410,410);
	puthz(260,395,"录入体重",24,30,WHITE);
	bg_back();
	puthz(544,110,"低体重",16,16,LIGHTBLUE);
	setfillstyle(1,LIGHTGRAY);
	pieslice(620,120,0,360,5);
	setcolor(LIGHTGRAY);
	line(620,120,625,120);
	puthz(560,140,"正常",16,16,LIGHTBLUE);
	setfillstyle(1,GREEN);
	pieslice(620,150,0,360,5);
	setcolor(GREEN);
	line(620,150,625,150);
	puthz(560,170,"超重",16,16,LIGHTBLUE);
	setfillstyle(1,LIGHTBLUE);
	pieslice(620,180,0,360,5);
	setcolor(LIGHTBLUE);
	line(620,180,625,180);
	puthz(560,200,"肥胖",16,16,LIGHTBLUE);
	setfillstyle(1,LIGHTRED);
	pieslice(620,210,0,360,5);
	setcolor(LIGHTRED);
	line(620,210,625,210);

}

void bg_add(void)
{
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,1);	
	setcolor(LIGHTBLUE);
	puthz(120,120,"日期",32,32,LIGHTBLUE);
	puthz(300,120,"年",32,32,LIGHTBLUE);
	puthz(380,120,"月",32,32,LIGHTBLUE);
	puthz(460,120,"日",32,32,LIGHTBLUE);
	puthz(120,180,"体重",32,32,LIGHTBLUE);
	puthz(420,180,"千克",32,32,LIGHTBLUE);
	setfillstyle(1,WHITE);
	bar(220,180,420,220);
	setfillstyle(1,LIGHTBLUE);
	bar(260,300,380,360);
	pieslice(260,330,90,270,30);
	pieslice(380,330,270,360,30);
	pieslice(380,330,0,90,30);
	line(260,300,260,360);
	line(380,300,380,360);
	line(380,330,410,330);
	puthz(260,315,"确定添加",24,30,WHITE);
	bg_back();
}

void bg_healthadvice()
{
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,1);	
	puthz(230,60,"健康建议",32,50,LIGHTBLUE);
	puthz(100,120,"您当前的身体质量指数为",24,24,LIGHTBLUE);
	bg_back();
}




