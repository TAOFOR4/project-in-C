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
#include"self.h"
#include"info.h"


/*画男图标函数*/

void draw_man1(void)
{
	setcolor(WHITE);
	setfillstyle(1, WHITE);
	pieslice(290, 310, 0, 360, 30);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setcolor(CYAN);                                 
	line(280, 318, 305, 293);
	line(305, 293, 305, 303);
	line(305, 293, 295, 293);
	circle(280,320,5);
}

/*画女图标函数*/

void draw_woman1(void)
{
	setcolor(WHITE);
	setfillstyle(1, WHITE);
	pieslice(410, 310, 0, 360, 30);                   
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setcolor(LIGHTMAGENTA);                           
	line(410, 305, 410, 325);
	line(400, 315, 420, 315);
	circle(410, 300, 5);
}
void loading1(void)//开机等待界面
{
	int i=150;
	int k; 
	time_t timep;
	struct tm *p;
	time(&timep);
	p = gmtime(&timep);
	//putbmp(0,0,"C:\\BORLANDC\\XTXT\\photo\\pic2.bmp");
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,BLACK);
	bar(0,0,640,480);
	setcolor(LIGHTGREEN);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(270,300,"Loading...");
	printf("%d\\%d\\%d:", (1900 + p->tm_year), (1 + p->tm_mon), p->tm_mday);
	printf("%d:%d:%d\n", p->tm_hour-4, p->tm_min, p->tm_sec);
	rectangle(150,340,500,360);
	for(k=1;k<8;k++)
	{
		puthz(101+k,135+k,"体育休闲示教",48,80,DARKGRAY); 
		puthz(216+k,225+k,"欢迎您",48,80,DARKGRAY);
	 } 
	puthz(100,135,"体育休闲示教",48,80,YELLOW);
	puthz(215,225,"欢迎您",48,80,LIGHTRED);
	if(p->tm_hour-4>=7&& p->tm_hour-4<=11)
	{
		for(k=1;k<8;k++)
		{
		puthz(215+k,50+k,"早上好",48,80,DARKGRAY); 
	 	} 
		puthz(215,50,"早上好",48,80,LIGHTCYAN);
	}
	else if(p->tm_hour-4>=12&& p->tm_hour-4<=14)
	{
		for(k=1;k<8;k++)
		{
		puthz(215+k,50+k,"中午好",48,80,DARKGRAY); 
	 	} 
		puthz(215,50,"中午好",48,80,LIGHTCYAN);
	}
	else if(p->tm_hour-4>=15&& p->tm_hour-4<=19)
	{
		for(k=1;k<8;k++)
		{
		puthz(215+k,50+k,"下午好",48,80,DARKGRAY); 
	 	} 
		puthz(215,50,"下午好",48,80,LIGHTCYAN);
	}
	else
	{
		puthz(200,70,"晚上好，注意休息",24,30,LIGHTCYAN);
	}
	setfillstyle(1,LIGHTGREEN);
	for(i=150;i<=450;i=i+30)
	{	
		bar(i,340,i+30,360);
		delay(200);
	}
	bar(480,340,500,360);
}

void bg_login(void)//用户登录主界面
{
	int k;
	int v[]={530,295,545,269,575,269,590,295,575,321,545,321,530,295};
	setviewport(0,0,1000,1000,0);
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	setlinestyle(0,0,1);
	pieslice(80,315,0,90,20);
	pieslice(80,315,270,360,20);
	pieslice(80,295,270,450,40);
	setfillstyle(1,BLACK);
	pieslice(80,275,90,270,20);
	setfillstyle(1,BLACK);
	setcolor(BLACK);
	line(80,315,90,315);
	line(80,295,80,285);
	line(80,265,80,255);
	circle(80,315,10);
	floodfill(81,316,BLACK);

	setfillstyle(1,WHITE);
	setcolor(WHITE);
	circle(80,275,10);
	floodfill(81,276,WHITE);
	line(80,315,90,315);
	line(90,315,100,315);
	line(80,305,80,295);
	line(80,325,80,335);
	setfillstyle(1,BLACK);
	bar(80,314,90,315);//太极 
	setfillstyle(1,WHITE);
	bar(250,170,460,210);//账号输入框 
	bar(250,220,460,260);//密码输入框 
	setfillstyle(1,LIGHTGRAY);//对下方文字部分画框填充
	bar(148,173,218,203);//账号 
	bar(148,223,218,253);//密码 
	bar(375,350,477,380);//游客模式
	bar(250,350,357,380);//忘记密码
	bar(38,350,100,380);//进入
	bar(135,350,215,380);//新用户
	bar(500,350,550,380);//退出
	setcolor(WHITE);
	rectangle(252,172,458,208);//账号
	rectangle(252,222,458,258);//密码
	setfillstyle(1,WHITE);//对下方文字部分画框并有按钮效果 
	circle(560,295,42);
	floodfill(560,296,WHITE);
	circle(80,275,10);
	floodfill(80,276,WHITE);
	setlinestyle(0,0,3);
	setcolor(BLACK);
	drawpoly(6,v); 
	line(530,295,518,295);
	line(545,269,539,259);
	line(575,269,581,259);
	line(590,295,602,295);
	line(575,321,581,331);
	line(545,321,539,331);
	line(545,321,530,295);//足球
	setcolor(WHITE);
	setlinestyle(0,0,1);
	circle(80,295,40); 
	line(40,352,98,352);
	line(40,352,40,378);//Enter
	line(137,352,213,352);
	line(137,352,137,378);//新用户
	line(252,352,355,352);
	line(252,352,252,378);//忘记密码
	line(502,352,502,378);
	line(502,352,548,352);//Exit 退出
	line(377,352,475,352);
	line(377,352,377,378);//游客模式
	setcolor(DARKGRAY);
    line(98,378,98,352);
	line(98,378,40,378);//Enter
	line(213,378,213,352);
	line(213,378,137,378);//新用户
	line(355,378,355,352);
	line(355,378,252,378);//忘记密码
	line(548,378,502,378);
	line(548,378,548,352);//Exit 退出
	line(475,378,475,352);
	line(475,378,377,378);//游客模式
	for(k=1;k<8;k++)
	{
		puthz(101+k,65+k,"体育休闲示教",48,80,DARKGRAY); 
	 } 
	puthz(100,65,"体育休闲示教",48,80,YELLOW);
	puthz(150,175,"账号",24,40,BLACK);
	puthz(150,225,"密码",24,40,BLACK);
	puthz(46,354,"进入",24,22,LIGHTCYAN);
	puthz(142,354,"新用户",24,22,LIGHTBLUE);
	puthz(257,354,"忘记密码",24,22,LIGHTBLUE);
	puthz(383,354,"关于软件",24,22,LIGHTBLUE);
	puthz(503,354,"退出",24,22,LIGHTRED);
}
/***************************************************
Function：     bg_welcom

Description：  

Input：    void

Output：    
***************************************************/
void bg_welcom(void)//欢迎界面
{
	
	int i=150;
	setbkcolor(CYAN);
	setviewport(0,0,600,600,0);
	puthz(180,80,"欢迎使用",48,80,LIGHTCYAN);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(270,300,"Loading...");
	rectangle(150,340,500,360);
	setfillstyle(1,WHITE);
	for(i=150;i<=450;i=i+30)
	{	
		bar (i,340,i+30,360);
		delay (70);
	}
	bar (480,340,500,360);
	
}
void loading(void)//等待界面
{
	int i=150;
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(270,300,"Loading...");
	rectangle(150,340,500,360);
	setfillstyle(1,WHITE);
	for(i=150;i<=450;i=i+30)
	{	
		bar (i,340,i+30,360);
		delay (70);
	}
	bar(480,340,500,360);
}
/***************************************************
Function：     bg_registry

Description：  

Input：    void

Output：    

***************************************************/
void bg_registry(void)//注册中心界面
{
	int k;
	setbkcolor(BLACK);
	setviewport(0,0,600,600,0);

	setfillstyle(1,LIGHTGRAY);
	setcolor(YELLOW);
	for(k=0;k<7;k++)
	{
		puthz(181+k,35+k,"注册中心",48,80,LIGHTGRAY);
	}
	puthz(180,35,"注册中心",48,80,LIGHTCYAN);
	bar(220,110,500,150);
	bar(220,160,500,200);
	bar(220,210,500,250);
	bar(220,260,500,300);
	setfillstyle(1,YELLOW);
	bar(140,400,240,430);//register
	bar(370,400,470,430);//canael
	setcolor(WHITE);
	rectangle(220,110,500,150);//账号
	rectangle(220,160,500,200);//密码
	rectangle(220,210,500,250);//再次确认
	rectangle(220,260,500,300);//输入身份证后四位
	setcolor(RED);
	puthz(120,120,"账号",24,40,WHITE);
	puthz(120,170,"密码",24,40,WHITE);
	puthz(90,220,"确认密码",24,30,WHITE);
	puthz(90,270,"出生日期",24,30,WHITE);
	puthz(520,270,"八位数字",24,30,WHITE);
	puthz(200,330,"请勿输入空信息",24,30,LIGHTRED);
	rectangle(140,400,240,430);//register
	rectangle(370,400,470,430);//canael
	puthz(160,403,"注册",24,30,GREEN);
	puthz(390,403,"退出",24,30,LIGHTRED);
	
}
/***************************************************
Function：     bg_forget

Description：  

Input：    void

Output：    
***************************************************/
void bg_forget(void)//忘记密码界面
{
	setbkcolor(BLACK);
	setviewport(0,0,600,600,0);
	puthz(180,35,"忘记密码",48,80,LIGHTRED);
	setcolor(BLUE);
	setfillstyle(1,LIGHTGRAY);
	bar(150,340,240,380);
	bar(450,340,530,380);
	puthz(120,145,"账号",24,30,YELLOW);
	puthz(80,195,"出生日期",24,30,YELLOW);
	puthz(80,265,"查看密码",24,30,LIGHTMAGENTA);
	puthz(165,350,"确认",24,30,LIGHTCYAN);
	puthz(460,350,"取消",24,30,LIGHTRED);
	bar(200,270,450,290);
	setfillstyle(1,LIGHTGRAY);
	bar(200,145,450,175);
	bar(200,195,450,225);
	bar(200,270,450,290);
	setcolor(YELLOW);
	rectangle(200,145,450,175);
	rectangle(200,195,450,225);
	rectangle(200,270,450,290);
	setcolor(WHITE); 
	setlinestyle(0,0,3);
	line(150,340,240,340);
	line(150,340,150,380);//confirm
	line(450,340,530,340);//canael
	line(450,340,450,380);
	setcolor(DARKGRAY);
	line(240,380,240,340);
	line(240,380,150,380);
	line(530,380,530,340);
	line(530,380,450,380);
}

void bg_center(void) 
{
	int v[]={505,65,515,55,485,25,475,35,505,65};
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,0);
	setfillstyle(1,BROWN);
	bar(80,120,200,160);
	bar(480,120,600,160);
	bar(80,360,200,400);
	bar(480,360,600,400);
	puthz(82,125,"个人中心",24,30,WHITE);
	puthz(482,125,"体育中心",24,30,WHITE);
	puthz(82,365,"休闲中心",24,30,WHITE);
	puthz(482,365,"退出登录",24,30,WHITE);
		setcolor(LIGHTGRAY);
        circle(140,60,40);
        circle(140,50,10);
        setcolor(WHITE);
        circle(140,60,30);
		ellipse(140,85,7,173,20,20);
        setfillstyle(1,WHITE);
        floodfill(140,50,LIGHTGRAY);
        floodfill(140,85,WHITE);
		setcolor(WHITE);
		circle(140,60,40);
        circle(140,50,10);
		setfillstyle(1,LIGHTRED);
		floodfill(140,95,WHITE);
		floodfill(140,25,WHITE);
		floodfill(140,35,WHITE);
		setcolor(LIGHTRED);
        circle(140,50,10);
		circle(140,60,30);
		ellipse(140,85,7,173,20,20);//个人中心 
		
		setcolor(WHITE);
        circle(140,290,35);
        line(140,260,165,260);
        line(140,260,140,270);
        line(140,270,130,270);
        circle(130,273,3);
        line(130,276,145,276);
        circle(145,281,5);
        line(150,281,150,301);
        circle(145,301,5);
        circle(130,301,10);
        line(130,291,130,281);
        line(130,281,105,281);
	    setfillstyle(1,WHITE);
        floodfill(145,281,WHITE);
        floodfill(145,301,WHITE);
        floodfill(140,290,WHITE);
        setcolor(LIGHTGRAY);
	    circle(140,290,40);
        circle(145,281,5);
        circle(145,301,5);
		setcolor(WHITE);
		circle(140,290,40);
		circle(145,281,5);
        circle(145,301,5);
		setfillstyle(1,LIGHTRED);
		floodfill(140,320,WHITE);
		floodfill(140,326,WHITE);
		floodfill(178,290,WHITE);
		floodfill(165,261,WHITE);
		floodfill(130,301,WHITE);
		floodfill(130,273,WHITE);
		setcolor(LIGHTRED);
		circle(130,301,10);
		circle(130,273,3);
		circle(140,290,35);
		line(140,260,140,270);
		line(140,270,130,270);
		line(130,276,145,276);
		line(150,281,150,301);
		line(130,291,130,281);
        line(130,281,105,281);
		line(140,260,165,260);
		setcolor(WHITE);
		circle(145,281,5);
		circle(145,301,5);//休闲中心

		setfillstyle(1,LIGHTRED);
		setcolor(LIGHTRED);
		circle(520,65,30);
		floodfill(506,66,LIGHTRED);
		setfillstyle(1,BLUE);
		setcolor(BLUE);
		drawpoly(5,v);
		floodfill(485,35,BLUE);
		setfillstyle(1,LIGHTRED);
		setcolor(LIGHTRED);
		circle(575,85,10);
		floodfill(576,86,LIGHTRED);//体育中心
		
		
		
		setcolor(LIGHTRED);
		circle(520,277,20);
		circle(560,277,20);//画两圆
		pieslice(540,322,42,138,45);//画扇形
		floodfill(520,277,LIGHTRED);
		floodfill(560,277,LIGHTRED);
		floodfill(540,312,LIGHTRED);//画心形 
	    															
}

void bg_happy()
{
	
	int v[]={140+390,200+110,120+390,220+110,130+390,230+110,150+390,210+110};
	int u[]={150+390,210+110,170+390,230+110,180+390,220+110,160+390,200+110};
	int t[]={564+390,195+110,579+390,210+110,564+390,225+110};
	
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,0);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
    setcolor(WHITE);
	circle(140,60,75);
	floodfill(135,65,LIGHTGRAY);
	setfillstyle(1,BLUE);
	pieslice(140,55,0,229,25);
	pieslice(140,55,311,360,25);
	setfillstyle(1,WHITE);
	pieslice(140,55,0,229,18);
	pieslice(140,55,311,360,18);
	setcolor(BLUE);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	line(158,55,165,55);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	line(120,80,138,75);
	line(160,80,142,75);
	setfillstyle(1,BLUE);
	bar(130,55,150,63);
	bar(138,63,142,80);
	bar(120,80,160,84);
	bar(150,77,137,83);
	bar(130,77,143,83);
	bar(135,28,145,33);//旅游 
	
	
	setcolor(LIGHTRED);
	circle(150+390,200+110,20);
	circle(150+390,200+110,10);
    drawpoly(4,v);
	drawpoly(4,u);
	setfillstyle(1,YELLOW);
	floodfill(150+390,200+110,LIGHTRED);
	setfillstyle(1,LIGHTRED);
	floodfill(140+390,190+110,LIGHTRED);
	floodfill(140+390,210+110,LIGHTRED);
	floodfill(150+390,211+110,LIGHTRED);
	floodfill(160+390,210+110,LIGHTRED);
	setfillstyle(1,YELLOW);
	floodfill(130+390,220+110,LIGHTRED);
	floodfill(170+390,220+110,LIGHTRED);
	setcolor(DARKGRAY);
	drawpoly(3,t);
	
	setcolor(BLUE);
	setfillstyle(1,BLUE);
	bar(501,84,537,34);
	pieslice(519,65,60,120,36);
	setfillstyle(11,YELLOW);
	pieslice(519,115,60,120,36);
	bar(501,84,544,115);
	arc(519,115,60,120,36);
	setfillstyle(1,BLUE);
	bar(543,84,579,34);
	pieslice(561,65,60,120,36);
	setfillstyle(11,YELLOW);
	pieslice(561,115,60,120,36);
	bar(543,84,586,115);
	arc(561,115,60,120,36);
	//图书 
	
	setcolor(BLUE);
	setlinestyle(0,0,3);
	rectangle(98,280,178,340);
	rectangle(100,278,180,338);
	rectangle(100,280,180,340);
	rectangle(100,282,180,342);
	rectangle(102,280,182,340);
	line(132,280,117,255);
	line(136,280,121,255);
	line(134,280,119,255);
	line(144,280,159,255);
	line(146,280,161,255);
	line(148,280,163,255);
	
	line(130,298,115,305);
	line(132,300,117,307);
	line(134,302,119,309);
	line(150,298,165,305);
	line(148,300,163,307);
	line(146,302,161,309);
	arc(135,320,180,360,5);
	arc(145,320,180,360,5);
	
	/*setfillstyle(1,BLUE);
	fillellipse(515,340,10,5);
	line(520,337,520,280);
	line(522,337,522,280);
	
	line(520,289,572,279);
	line(520,287,572,277);
	line(520,285,572,275);
	line(520,283,572,273);
	line(520,281,572,271);
	line(520,279,572,269);
	
	line(568,270,568,327);
	line(570,270,570,327);
	fillellipse(563,330,10,5);*/
	
	setfillstyle(1,BROWN);
	bar(80,110,200,150);
	bar(480,110,600,150);
	bar(80,360,200,400);
	bar(480,360,600,400);
	bar(5,5,48,33);
	puthz(10,10,"返回",16,20,WHITE);
	puthz(82,115,"风景名胜",24,30,WHITE);
	puthz(482,115,"经典阅读",24,30,WHITE);
	puthz(82,365,"视频欣赏",24,30,WHITE);
	puthz(512,365,"画画",24,30,WHITE);
}

void bg_book()
{
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setviewport(0,0,640,480,0);
	setfillstyle(1,LIGHTRED);
	pieslice(294,65,60,120,36);
	bar(276,84,312,34);
	pieslice(336,65,60,120,36);
	setfillstyle(11,YELLOW);
	pieslice(294,115,60,120,36);
	bar(276,84,319,115);
	arc(294,115,60,120,36);
	setfillstyle(1,LIGHTRED);
	bar(318,84,354,34);
	setfillstyle(11,YELLOW);
	pieslice(336,115,60,120,36);
	bar(318,84,361,115);
	arc(336,115,60,120,36);
	
	setfillstyle(1,BROWN);
	bar(5,5,48,33); 
	setcolor(BROWN);
	line(8,178,38,178);
	line(380,177,410,177);
	line(8,347,43,347);
	line(380,349,410,349);
	puthz(10,10,"返回",16,20,WHITE);
	puthz(82,115,"追风筝的人",24,30,LIGHTRED);
	puthz(72,145,"作者",16,20,BLUE);
	puthz(118,145,"卡勒德胡赛尼",16,20,BLUE);
	puthz(43,170,"被真相伤害总比被谎言欺骗的好",16,17,BROWN);
	
	puthz(442,115,"怦然心动",24,30,LIGHTRED);
	puthz(432,145,"作者",16,20,BLUE);
	puthz(478,145,"范德拉安南",16,20,BLUE);
	puthz(415,170,"斯人若彩虹",16,17,BROWN);
	puthz(510,170,"遇上方知有",16,17,BROWN);
	
	puthz(55,285,"了不起的盖茨比",24,30,LIGHTRED);
	puthz(83,315,"作者",16,20,BLUE);
	puthz(129,315,"菲茨杰拉德",16,20,BLUE);
	puthz(53,340,"所有的光鲜亮丽都敌不过时间",16,17,BROWN);
	
	puthz(442,285,"阿甘正传",24,30,LIGHTRED);
	puthz(425,315,"作者",16,20,BLUE);
	puthz(470,315,"温斯顿葛鲁姆",16,20,BLUE);
	puthz(415,340,"要往前走就得先忘掉过去",16,17,BROWN);
	
	setfillstyle(1,LIGHTGRAY);
	bar(123,200,185,230);
	setcolor(WHITE);
	line(125,202,183,202);
	line(125,202,125,228);
	setcolor(DARKGRAY);
    line(183,228,183,202);
	line(183,228,125,228);
	puthz(131,204,"阅读",24,22,LIGHTCYAN);
	
	setfillstyle(1,LIGHTGRAY);
	bar(473,200,535,230);
	setcolor(WHITE);
	line(475,202,533,202);
	line(475,202,475,228);
	setcolor(DARKGRAY);
    line(533,228,533,202);
	line(533,228,475,228);
	puthz(481,204,"阅读",24,22,LIGHTCYAN);

	setfillstyle(1,LIGHTGRAY);
	bar(123,370,185,400);
	setcolor(WHITE);
	line(125,372,183,372);
	line(125,372,125,398);
	setcolor(DARKGRAY);
    line(183,398,183,372);
	line(183,398,125,398);
	puthz(131,374,"阅读",24,22,LIGHTCYAN);
	
	setfillstyle(1,LIGHTGRAY);
	bar(473,370,535,400);
	setcolor(WHITE);
	line(475,372,533,372);
	line(475,372,475,398);
	setcolor(DARKGRAY);
    line(533,398,533,372);
	line(533,398,475,398);
	puthz(481,374,"阅读",24,22,LIGHTCYAN);
}

void bg_paint()
{
	cleardevice();
	setbkcolor(DARKGRAY); 
	setfillstyle(1,BROWN);
	bar(563,5,581,23);
	puthz(564,6,"细",16,20,WHITE);
	bar(590,5,608,23);
	puthz(591,6,"中",16,20,WHITE);
	bar(617,5,635,23);
	puthz(618,6,"粗",16,20,WHITE);
	bar(5,5,48,33); 
	puthz(10,10,"返回",16,20,WHITE);
	bar(5,475,48,448); 
	puthz(10,453,"重画",16,20,WHITE);
	puthz(245,5,"右键开始画画，左键结束画画",16,16,WHITE);
	setfillstyle(1,LIGHTRED);
	bar(75,5,85,33); 
	setfillstyle(1,LIGHTBLUE);
	bar(95,5,105,33); 
	setfillstyle(1,LIGHTGREEN);
	bar(115,5,125,33); 
	setfillstyle(1,LIGHTCYAN);
	bar(135,5,145,33); 
	setfillstyle(1,LIGHTMAGENTA);
	bar(155,5,165,33);
	setfillstyle(1,YELLOW);
	bar(175,5,185,33);
	setfillstyle(1,BROWN);
	bar(195,5,205,33);  
	setfillstyle(1,DARKGRAY);
	bar(215,5,225,33);  
	setfillstyle(1,WHITE);
	bar(55,5,65,33); 
	setcolor(WHITE);
	setlinestyle(0,0,3);
	bar(215,13,233,33);
	line(215,13,220,4);
	line(228,4,220,4);
	line(233,13,228,4);
	
}
void bg_scenery(void)//休闲中心
{
	cleardevice(); 
	putbmp(0,65,".//TXT//photo//china.bmp");
	setbkcolor(WHITE);
	setviewport(0,0,600,600,0);
	setfillstyle(1,LIGHTRED);
	setcolor(LIGHTRED);
	circle(145,190,5);
	floodfill(146,191,LIGHTRED);//新疆天山
	circle(142,290,5);
	floodfill(146,291,LIGHTRED);//布达拉宫
	circle(470,207,5);
	floodfill(471,208,LIGHTRED);//北京
	circle(310,304,5);
	floodfill(311,305,LIGHTRED);//四川
	circle(440,302,5);
	floodfill(441,303,LIGHTRED);//武汉
	circle(432,333,5);
	floodfill(433,330,LIGHTRED);//鄱阳湖
	circle(411,240,5);
	floodfill(412,241,LIGHTRED);//太行山
	
	setfillstyle(1,BROWN);
	bar(5,5,48,33); 
	puthz(10,10,"返回",16,20,WHITE);
	
	setcolor(WHITE);
	setfillstyle(1,BLUE);
	pieslice(140,55,0,229,25);
	pieslice(140,55,311,360,25);
	setfillstyle(1,WHITE);
	pieslice(140,55,0,229,18);
	pieslice(140,55,311,360,18);
	setcolor(BLUE);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	line(158,55,165,55);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	line(120,80,138,75);
	line(160,80,142,75);
	setfillstyle(1,BLUE);
	bar(130,55,150,63);
	bar(138,63,142,80);
	bar(120,80,160,84);
	bar(150,77,137,83);
	bar(130,77,143,83);
	bar(135,28,145,33);//旅游 

	line(212+20,93-36,223+20,104-36);
	line(223+20,104-36,274+20,92-36);
	line(274+20,92-36,270+20,87-36);
	line(270+20,87-36,268+20,86-36);
	line(268+20,86-36,256+20,86-36);
	line(256+20,86-36,223+20,97-36);
	line(223+20,97-36,236+20,89-36);
	line(236+20,89-36,212+20,93-36);
	line(238+20,92-36,236+20,85-36);
	line(236+20,85-36,247+20,89-36);
	line(244+20,99-36,234+20,136-36);
	line(234+20,136-36,243+20,116-36);
	line(243+20,116-36,253+20,97-36);
	puthz(130,200,"天山",16,15,LIGHTRED);
	puthz(114,300,"布达拉宫",16,15,LIGHTRED);
	puthz(455,217,"故宫",16,15,LIGHTRED);
	puthz(295,314,"重庆",16,15,LIGHTRED);
	puthz(419,309,"黄鹤楼",16,15,LIGHTRED);
	puthz(411,340,"滕王阁",16,15,LIGHTRED);
	puthz(390,251,"太行山",16,15,LIGHTRED);
}

void bg_sport1_began()
{
		setbkcolor(WHITE);
		setfillstyle(1,BROWN);
		setcolor(BROWN);
		circle(320,120,35);
		floodfill(321,121,BROWN);
		setlinestyle(0,0,3);
		line(320-4,155,320-4,265);
		line(320-2,155,320-2,265);
		line(320,155,320,265);
		line(320+2,155,320+2,265);
		line(320+4,155,320+4,265);//身体 
		line(320-4,265-4,260-4,375);
		line(320-2,265-2,260-2,375);
		line(320,265,260,375);//左腿 
		line(260,375,245,378);
		line(260+2,375+2,245+2,378+2);
		line(260-2,375-2,245-2,378-2);//左脚 
		line(320,265,360,365);
		line(320+2,265,360+2,365+2);
		line(320+4,265,360+4,365+4);//右腿 
		line(360,365,345,373);
		line(360+2,365+2,345+2,373+2);
		line(360-2,365-2,345-2,373-2);//右脚 
		line(150,180,490,180);
		line(150,180-2,490,180-2);
		ellipse(120,180,0,360,20,30);
		ellipse(150,180,0,360,20,30);
		floodfill(121,181,BROWN);
		//ellipse(150,180,0,360,20,30);
		floodfill(161,199,BROWN);
		ellipse(490,180,0,360,20,30);
		ellipse(520,180,0,360,20,30);
		floodfill(491,181,BROWN);
		//ellipse(150,180,0,360,20,30);
		floodfill(531,199,BROWN);//哑铃 
		line(320,190,270,250);
		line(320,190-2,270,250-2);
		line(320,190+2,270,250+2);//左小臂 
		line(270,250,240,180);
		line(270-2,250-2,240-2,180-2);
		line(270+2,250+2,240+2,180+2);
		sector(240,180,20,160,15,10);//左手
		line(320,190,370,250);
		line(320,190-2,370,250-2);
		line(320,190+2,370,250+2);//右小臂 
		line(370,250,400,180);
		line(370-2,250-2,400-2,180-2);
		line(370+2,250+2,400+2,180+2);
		sector(400,180,20,160,15,10);//右手
}



void bg_sport2_began()
{
		setbkcolor(WHITE);
		setfillstyle(1,BROWN);
		setcolor(BROWN);
		circle(320,120,35);
		floodfill(321,121,BROWN);
		setlinestyle(0,0,3);
		line(320-4,155,320-4,265);
		line(320-2,155,320-2,265);
		line(320,155,320,265);
		line(320+2,155,320+2,265);
		line(320+4,155,320+4,265);//身体 
		line(320-4,265-4,300-4,375);
		line(320-2,265-2,300-2,375);
		line(320,265,300,375);
		ellipse(285,375,0,180,15,10);
		line(270,375,300,375);//左腿 
		line(320,265,340,375);
		line(320+2,265,340+2,375);
		line(320+4,265,340+4,375);
		line(320+6,265,340+6,375);
		ellipse(355,375,0,180,15,10);
		line(340,375,370,375);//右腿 
		line(320,180,285,290);
		line(320,180-2,285,290-2);
		line(320,180-4,285,290-4);
		fillellipse(285,290,5,5);//左胳膊
		line(320,180,355,290);
		line(320,180-2,355,290-2);
		line(320,180-4,355,290-4);
		fillellipse(355,290,5,5);//右胳膊
}


void bg_sport3_began()
{
		setbkcolor(WHITE);
		setfillstyle(1,BROWN);
		setcolor(BROWN);
		circle(200,260,35);
		floodfill(201,261,BROWN);
		setlinestyle(0,0,3);
		line(230,265-6,340,270-6);
		line(230,265-4,340,270-4);
		line(230,265-2,340,270-2);
		line(230,265,340,270);
		line(230,265+2,340,270+2);
		line(230,265+4,340,270+4);
		line(230,265+6,340,270+6);//上身体 
		line(340,270-4,384,268-4);
		line(340,270-2,384,268-2);
		line(340,270,384,268);
		line(340,270+2,384,268+2);
		line(340,270+4,384,268+4);//下身体 
		line(384,268-4,425,190-4);
		line(384,268-2,425,190-2);
		line(384,268,425,190);
		line(384,268+2,425,190+2);
		line(384,268+4,425,190+4);//
		//line(425,190-4,485,225-4);
		line(425,190-2,500,235-2);
		line(425,190,500,235);
		line(425,190+2,500,235+2);
		//line(425,190+4,485,225+4);//左腿 
		line(384,268-4,445,235-4);
		line(384,268-2,445,235-2);
		line(384,268,445,235);
		line(384,268+2,445,235+2);
		line(384,268+4,445,235+4);//
		//line(445,235-4,485,225-4);
		line(445,235-2,500,285-2);
		line(445,235,500,285);
		line(445,235+2,500,285+2);
		//line(445,235+4,485,225+4);//右腿 
		line(280,267,245,205);
		line(280-2,267,245-2,205);
		line(280+2,267,245+2,205);//左胳膊
		line(245,205,210,230);
		line(245-2,205,210-2,230);
		line(245+2,205,210+2,230);//左胳膊
		line(280,267,245,329);
		line(280-2,267,245-2,329);
		line(280+2,267,245+2,329);//左胳膊
		line(245,329,210,290);
		line(245-2,329,210-2,290);
		line(245+2,329,210+2,290);//左胳膊
}

void bg_sport4_began()
{
		setbkcolor(WHITE);
		setcolor(LIGHTRED);
		ellipse(320,230,0,180,95,5);//绳子 在后 
		setfillstyle(1,BROWN);
		setcolor(BROWN);
		circle(320,120,35);
		floodfill(321,121,BROWN);
		setlinestyle(0,0,3);
		line(320-4,155,320-4,265);
		line(320-2,155,320-2,265);
		line(320,155,320,265);
		line(320+2,155,320+2,265);
		line(320+4,155,320+4,265);//身体 
		line(320-4,265-4,300-4,375);
		line(320-2,265-2,300-2,375);
		line(320,265,300,375);
		ellipse(285,375,0,180,15,10);
		line(270,375,300,375);//左腿 
		line(320,265,340,375);
		line(320+2,265,340+2,375);
		line(320+4,265,340+4,375);
		line(320+6,265,340+6,375);
		ellipse(355,375,0,180,15,10);
		line(340,375,370,375);//右腿 
		line(320,180,225,230);
		line(320,180-2,225,230-2);
		line(320,180-4,225,230-4);
		fillellipse(225,230,5,5);//左胳膊
		line(320,180,415,230);
		line(320,180-2,415,230-2);
		line(320,180-4,415,230-4);
		fillellipse(415,230,5,5);//右胳膊

}

