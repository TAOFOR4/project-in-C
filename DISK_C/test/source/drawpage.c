
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
Function��     bg_selfcenter

Description��  

Input��    void

Output��    
***************************************************/

void bg_selfcenter()
{
	setviewport(0,0,640,480,1);
	setbkcolor(BLACK);//������ɫ 
	setfillstyle(1,WHITE);
	puthz(180,20,"������Ϣ",32,80,RED);
	setcolor(WHITE);
	bar(250,100,450,140);//�ǳ� 
	puthz(100,110,"�ǳ�",24,30,WHITE);

	bar(250,160,450,200);//���  
	puthz(100,170,"���",24,30,WHITE);
	puthz(500,170,"����",24,30,WHITE);
	
	bar(250,220,450,260);//����
	puthz(100,230,"����",24,30,WHITE);
	puthz(500,230,"ǧ��",24,30,WHITE);
	
	puthz(100,290,"�Ա�",24,30,WHITE);//�Ա� 
	
	puthz(150,350,"�����������Ϣ",24,50,RED);
	
	setfillstyle(1,DARKGRAY);
	bar(180,400,260,440);
	bar(400,400,480,440);//ȷ�Ϻͷ��� 
	
	draw_man1(); 
	draw_woman1(); 
	
	setcolor(WHITE);//ʹ����͹�Ե�Ч��
	puthz(190,410,"ȷ��",24,30,LIGHTCYAN);
	puthz(410,410,"����",24,30,LIGHTMAGENTA);
	
	
}



/*����ѡ��ͼ�꺯��*/

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

/*����ѡŮͼ�꺯��*/

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

void bg_back(void)//�����Ͻǻ����ؼ�
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
	puthz(225,40,"��������",32,50,LIGHTBLUE);
	bar(240,180,400,230);
	puthz(260,193,"����ʾ��",24,30,WHITE);
	bar(240,300,400,350);
	puthz(260,313,"��Ƶʾ��",24,30,WHITE);
	bar(500,400,580,450);
	puthz(517,414,"����",24,24,WHITE);

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
	puthz(10,10,"����",16,20,WHITE);
	puthz(82,115,"��������",24,30,WHITE);
	puthz(482,115,"���ض���",24,30,WHITE);
	puthz(98,365,"������",24,30,WHITE);
	puthz(482,365,"��������",24,30,WHITE);
}

void bg_videocenter(void)
{
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,1);	
	setfillstyle(1,BROWN);
	//puthz(220,40,"��Ƶʾ��",32,32,LIGHTBLUE);
	bar(240,120,400,170);
	puthz(278,133,"̫��ȭ",24,30,WHITE);
	bar(80,280,240,330);
	puthz(118,293,"�赸��",24,30,WHITE);
	bar(400,280,560,330);
	puthz(455,293,"�٤",24,30,WHITE);
	
	bar(500,400,580,450);
	puthz(517,414,"����",24,24,WHITE);
	
}

void bg_shijiao1(void)
{
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,1);	
	
	puthz(260,20,"̫��ȭ",32,32,LIGHTBLUE);
	puthz(20,100,"���γ̽���",16,16,LIGHTBLUE);
	puthz(20,120,"̫��ȭ�����Ҽ��������Ļ��Ų��������й���ͳ�塢����ѧ�е�̫����������֤����",16,16,LIGHTBLUE);
	puthz(20,140,"Ϊ����˼�룬���������顢ǿ���塢�����Կ��ȶ��ֹ���Ϊһ�壬�����ѧ������",16,16,LIGHTBLUE);
	puthz(20,160,"����֮�仯����ҽ����ѧ���Ŵ��ĵ��������������γɵ�һ��������ޡ���͡�����",16,16,LIGHTBLUE);
	puthz(20,180,"�����顢������õ��й���ͳȭ����",16,16,LIGHTBLUE);
	puthz(20,220,"���γ��ص�",16,16,LIGHTBLUE);
	puthz(20,240,"�������⣬������Ȼ��",16,16,LIGHTBLUE);
	puthz(20,260,"�������棬��ͻ�����",16,16,LIGHTBLUE);
	puthz(20,280,"�������Σ�Բ��������",16,16,LIGHTBLUE);
	puthz(20,300,"����Э������ʵ������",16,16,LIGHTBLUE);
	puthz(20,320,"������ţ�������ã�",16,16,LIGHTBLUE);
	setfillstyle(1,LIGHTBLUE);
	bar(260,360,380,420);
	pieslice(260,390,90,270,30);
	pieslice(380,390,270,360,30);
	pieslice(380,390,0,90,30);
	setcolor(LIGHTBLUE);
	line(260,360,260,420);
	line(380,360,380,420);
	line(380,390,410,390);
	puthz(260,375,"��ʼѧϰ",24,30,WHITE);
	bg_back();
}

void bg_shijiao2(void)
{
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,1);	
	
	puthz(260,20,"�赸��",32,32,LIGHTBLUE);
	puthz(20,100,"���γ̽���",16,16,LIGHTBLUE);
	puthz(20,120,"����һ�θ������ֽ��е�ȫ�����������Ȳ��������β����ɣ�˦һ˦�ֱ۲������",16,16,LIGHTBLUE);
	puthz(20,140,"�ʡ�������ظ������Σ���Ҳ������������ѵ����",16,16,LIGHTBLUE);
	puthz(20,180,"��������Ⱥ",16,16,LIGHTBLUE);
	puthz(20,200,"�ʺϴ��������ѵ�����Ǻ�û����ʽ���ɶ�������С��",16,16,LIGHTBLUE);
	puthz(20,240,"����ǰ׼��",16,16,LIGHTBLUE);
	puthz(20,260,"ѵ��ǰ��Ҫ��̫�ණ�������ⱥ��״̬������ѵ���г��ָ������ʡ�",16,16,LIGHTBLUE);
	setfillstyle(1,LIGHTBLUE);
	bar(260,360,380,420);
	pieslice(260,390,90,270,30);
	pieslice(380,390,270,360,30);
	pieslice(380,390,0,90,30);
	setcolor(LIGHTBLUE);
	line(260,360,260,420);
	line(380,360,380,420);
	line(380,390,410,390);
	puthz(260,375,"��ʼѧϰ",24,30,WHITE);
	bg_back();
}

void bg_shijiao3(void)
{
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,1);	
	
	puthz(275,20,"�٤",32,32,LIGHTBLUE);
	puthz(20,100,"���γ̽���",16,16,LIGHTBLUE);
	puthz(20,120,"�٤��һ������5000����ʷ�Ĺ������塢�����Լ��������ϰ����Դ��ӡ�ȣ���Ŀ��",16,16,LIGHTBLUE);
	puthz(20,140,"�Ǹ�����������ԡ�",16,16,LIGHTBLUE);
	puthz(20,180,"���γ��ص�",16,16,LIGHTBLUE);
	puthz(20,200,"�٤�������ù��϶��������յļ��ɣ�������������������к;����������",16,16,LIGHTBLUE);
	puthz(20,220,"����һ�ִﵽ���塢�����뾫���гͳһ���˶���ʽ�������������λ������Ϣ�ĺ�",16,16,LIGHTBLUE);
	puthz(20,240,"���������ĵ�ڤ�뷨�ȣ��Դ������ĵĺ�һ��",16,16,LIGHTBLUE);
	setfillstyle(1,LIGHTBLUE);
	bar(260,360,380,420);
	pieslice(260,390,90,270,30);
	pieslice(380,390,270,360,30);
	pieslice(380,390,0,90,30);
	setcolor(LIGHTBLUE);
	line(260,360,260,420);
	line(380,360,380,420);
	line(380,390,410,390);
	puthz(260,375,"��ʼѧϰ",24,30,WHITE);
	bg_back();
}

void bg_selfcenter1(user *u)//������Ϣ���޸ģ�������Ϣϵͳ���飬�����ղ� 
{
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,1);
	setfillstyle(1,BROWN);
	setcolor(LIGHTBLUE);
	settextstyle(1,0,4);
	puthz(220,40,"��ӭ��",32,32,LIGHTBLUE);
	outtextxy(220,80,u->name);
	bar(240,150,400,200);
	puthz(260,163,"������Ϣ",24,30,WHITE);
	bar(240,230,400,280);
	puthz(260,243,"������Ϣ",24,30,WHITE);
	bar(240,310,400,360);
	puthz(260,323,"�޸��ǳ�",24,30,WHITE);
	bar(500,400,580,450);
	puthz(517,414,"����",24,24,WHITE);
}

void bg_basicinfo(void)
{	
	cleardevice();
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,1);
	setcolor(LIGHTBLUE);
	puthz(230,60,"������Ϣ",32,50,LIGHTBLUE);
	puthz(120,120,"�ǳ�",32,32,LIGHTBLUE);
	puthz(120,180,"�Ա�",32,32,LIGHTBLUE);
	puthz(120,240,"����",32,32,LIGHTBLUE);
	puthz(300,240,"��",32,32,LIGHTBLUE);
	puthz(380,240,"��",32,32,LIGHTBLUE);
	puthz(460,240,"��",32,32,LIGHTBLUE);
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
	puthz(230,60,"������Ϣ",32,50,LIGHTBLUE);
	puthz(120,120,"���",32,32,LIGHTBLUE);
	puthz(400,120,"����",32,32,LIGHTBLUE);
	puthz(120,180,"����",32,32,LIGHTBLUE);
	puthz(400,180,"ǧ��",32,32,LIGHTBLUE);
	
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
	puthz(400,240,"����",32,32,WHITE);
	
	bar(260,300,380,360);
	pieslice(260,330,90,270,30);
	pieslice(380,330,270,360,30);
	pieslice(380,330,0,90,30);
	line(260,300,260,360);
	line(380,300,380,360);
	line(380,330,410,330);
	puthz(260,315,"��������",24,30,WHITE);
	bg_back();
}

void bg_changename(user *u)
{
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,1);	
	settextstyle(1,0,4);
	puthz(120,120,"ԭ�ǳ�",32,32,LIGHTBLUE);
	outtextxy(240,118,u->name);
	puthz(120,200,"���ǳ�",32,32,LIGHTBLUE);
	setfillstyle(1,WHITE);
	bar(240,200,440,240);
	puthz(210,260,"������ԭ�ǳ���ͬ��",24,24,RED);
	setfillstyle(1,LIGHTBLUE);
	bar(260,300,380,360);
	pieslice(260,330,90,270,30);
	pieslice(380,330,270,360,30);
	pieslice(380,330,0,90,30);
	setcolor(LIGHTBLUE);
	line(260,300,260,360);
	line(380,300,380,360);
	line(380,330,410,330);
	puthz(260,315,"ȷ���޸�",24,30,WHITE);
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
	puthz(120,20,"��������ָ���仯����ͼ",32,32,LIGHTBLUE);
	puthz(560,300,"����",16,16,LIGHTBLUE);
	settextstyle(1,0,3);
	
	outtextxy(10,70,"BMI");
	setfillstyle(1,LIGHTBLUE);//���� 
	bar(260,380,380,440);
	pieslice(260,410,90,270,30);
	pieslice(380,410,270,360,30);
	pieslice(380,410,0,90,30);
	setcolor(LIGHTBLUE);
	line(260,380,260,440);
	line(380,380,380,440);
	line(380,410,410,410);
	puthz(260,395,"¼������",24,30,WHITE);
	bg_back();
	puthz(544,110,"������",16,16,LIGHTBLUE);
	setfillstyle(1,LIGHTGRAY);
	pieslice(620,120,0,360,5);
	setcolor(LIGHTGRAY);
	line(620,120,625,120);
	puthz(560,140,"����",16,16,LIGHTBLUE);
	setfillstyle(1,GREEN);
	pieslice(620,150,0,360,5);
	setcolor(GREEN);
	line(620,150,625,150);
	puthz(560,170,"����",16,16,LIGHTBLUE);
	setfillstyle(1,LIGHTBLUE);
	pieslice(620,180,0,360,5);
	setcolor(LIGHTBLUE);
	line(620,180,625,180);
	puthz(560,200,"����",16,16,LIGHTBLUE);
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
	puthz(120,120,"����",32,32,LIGHTBLUE);
	puthz(300,120,"��",32,32,LIGHTBLUE);
	puthz(380,120,"��",32,32,LIGHTBLUE);
	puthz(460,120,"��",32,32,LIGHTBLUE);
	puthz(120,180,"����",32,32,LIGHTBLUE);
	puthz(420,180,"ǧ��",32,32,LIGHTBLUE);
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
	puthz(260,315,"ȷ�����",24,30,WHITE);
	bg_back();
}

void bg_healthadvice()
{
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,1);	
	puthz(230,60,"��������",32,50,LIGHTBLUE);
	puthz(100,120,"����ǰ����������ָ��Ϊ",24,24,LIGHTBLUE);
	bg_back();
}




