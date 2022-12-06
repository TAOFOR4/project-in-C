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


void introduce(char address[10])
{
	int i=0,j=0;
	FILE* fp;
	char ch;
	char title[50]=".//TXT//";
	char tail[5]=".txt";
	char tranfer[400]={'\0'};
	setbkcolor(BLACK);
	strcat(title,address);
	strcpy(tail,".txt");
	strcat(title,tail);
	if ((fp = fopen(title, "r")) == NULL)//打开对应的文件
	{                            
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
		setcolor(RED);
		outtextxy(0,0,"cannot open file ");
		delay(1000);
		getch();
		exit(1);
	}
	while(!feof(fp))
	{
		tranfer[i]=fgetc(fp);
		if(tranfer[i]=='1'||i==600)
		{
			tranfer[i]='\0';      //一边读取文件中的信息一边将信息输出出来             
			puthz(j*22,70,tranfer,24,25,WHITE);
			i=0;
			j++;
		}
		else
		{
			i++;
		}
	}
	fclose(fp);
	newmouse(&MouseX,&MouseY,&press);
}


void jieshao(int *func)
{
	
	char text[40];
	cleardevice();
	setfillstyle(1,WHITE);
	rectangle(20,5,100,35);
	puthz(20,5,"返回",32,40,WHITE);
	strcpy(text, "jieshao");
	introduce(text);
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);	//返回
		if(MouseS!=0)  
	      MouseS=0;	
		if(mouse_press(20,5,80,35)==2)
		  MouseS=1;	
		if(mouse_press(20,5,80,35)==1)
		{
			*func=0;
			return;
		}
		
	}
	
}



int happy(user *u,int *func)
{
	int choose1=0;
	cleardevice();
	clrmous(MouseX,MouseY);
	bg_happy();
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	while(choose1==0)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      MouseS=0;	
		if(mouse_press(80,110,200,150)==2)
		  MouseS=1;
		if(mouse_press(80,110,200,150)==1)//风景名胜 
		{
			setfillstyle(1,BLUE);
			bar(80,110,200,150);
			puthz(82,115,"风景名胜",24,30,LIGHTRED);
			choose1=1;
			break;
		}
		if(mouse_press(80,360,200,400)==2)
		  MouseS=1;
		if(mouse_press(80,360,200,400)==1)//视频赏析 
		{
			setfillstyle(1,BLUE);
			bar(80,360,200,400);
			puthz(82,365,"视频赏析",24,30,LIGHTRED);
			choose1=2;
			break;
		}
		if(mouse_press(480,110,600,150)==2)
		  MouseS=1;
		if(mouse_press(480,110,600,150)==1)//经典阅读 
		{
			setfillstyle(1,BLUE);
			bar(480,110,600,150);
			puthz(482,115,"经典阅读",24,30,LIGHTRED);
			choose1=3;
			break;
		}
		if(mouse_press(480,360,600,400)==2)
		  MouseS=1;
		if(mouse_press(480,360,600,400)==1)//画画 
		{
			setfillstyle(1,BLUE);
			bar(480,360,600,400);
			puthz(512,365,"画画",24,30,LIGHTRED);
			choose1=4;
			break;
		}
		
		if(mouse_press(5,5,48,33)==2)
		  MouseS=1;
		if(mouse_press(5,5,48,33)==1)
		{
			setfillstyle(1,BLUE);
			bar(5,5,48,33);
			puthz(10,10,"返回",16,20,LIGHTRED);
			choose1=6;
			break;
		}
	}
	delay(200);
	clrmous(MouseX,MouseY);
	cleardevice();
	switch(choose1)
	{
		case 1:
		delay(100);
		cleardevice();
		*func=8;
		return ;
		
		case 2:
		delay(100);
		cleardevice();
		*func=11;
		return ;
		
		case 3:
		delay(100);
		cleardevice();
		*func=7;
		return ;
		
		case 4:
		delay(100);
		cleardevice();
		*func=9;
		return ;
		
		/*case 5:
		delay(100);
		cleardevice();
		*func=9;
		return ;*/
		
		case 6:
		delay(100);
		cleardevice();
		*func=4;
		return;
		
	}   
}
	
	int paint(int* func)//画画 
{
	int m=7;
	bg_paint();
	mouseinit();
	setcolor(WHITE);
	setfillstyle(1,WHITE);
	  while(1)
	 {
	  	newmouse(&MouseX,&MouseY,&press);
	  	
			if(MouseS!=0)  
	      		MouseS=0;	
			if(mouse_press(55,5,65,33)==2)
		  		MouseS=1;
			if(mouse_press(55,5,65,33)==1)
			 {
			 	setcolor(WHITE);
			 	setfillstyle(1,WHITE);
			 }
			 if(mouse_press(75,5,85,33)==2)
		  		MouseS=1;
			 if(mouse_press(75,5,85,33)==1)
			 {
			 	setcolor(LIGHTRED);
			 	setfillstyle(1,LIGHTRED);
			 }
			 if(mouse_press(95,5,105,33)==2)
		  		MouseS=1;
			 if(mouse_press(95,5,105,33)==1)
			 {
			 	setcolor(LIGHTBLUE);
			 	setfillstyle(1,LIGHTBLUE);
			 }
			 if(mouse_press(115,5,125,33)==2)
		  		MouseS=1;
			 if(mouse_press(115,5,125,33)==1)
			 {
			 	setcolor(LIGHTGREEN);
			 	setfillstyle(1,LIGHTGREEN);
			 }
			 if(mouse_press(135,5,145,33)==2)
		  		MouseS=1;
			 if(mouse_press(135,5,145,33)==1)
			 {
			 	setcolor(LIGHTCYAN);
			 	setfillstyle(1,LIGHTCYAN);
			 }
			 if(mouse_press(155,5,165,33)==2)
		  		MouseS=1;
			 if(mouse_press(155,5,165,33)==1)
			 {
			 	setcolor(LIGHTMAGENTA);
			 	setfillstyle(1,LIGHTMAGENTA);
			 }
			 if(mouse_press(175,5,185,33)==2)
		  		MouseS=1;
			 if(mouse_press(175,5,185,33)==1)
			 {
			 	setcolor(YELLOW);
			 	setfillstyle(1,YELLOW);
			 }
			 if(mouse_press(195,5,205,33)==2)
		  		MouseS=1;
			 if(mouse_press(195,5,205,33)==1)
			 {
			 	setcolor(BROWN);
			 	setfillstyle(1,BROWN);
			 }
			 if(mouse_press(215,5,233,33)==2)
		  		MouseS=1;
			 if(mouse_press(215,5,233,33)==1)
			 {
			 	setcolor(DARKGRAY);
			 	setfillstyle(1,DARKGRAY);
			 	m=0;
			 }
			 if(mouse_press(563,5,581,23)==2)
		  		MouseS=1;
			 if(mouse_press(563,5,581,23)==1)
			 {
			 	m=7;
			 }
			 if(mouse_press(590,5,608,23)==2)
		  		MouseS=1;
			 if(mouse_press(590,5,608,23)==1)
			 {
			 	m=6;
			 }
			 if(mouse_press(617,5,635,23)==2)
		  		MouseS=1;
			 if(mouse_press(617,5,635,23)==1)
			 {
			 	m=5;
			 }
		 	painting(m);
		 	if(mouse_press(5,448,48,475)==2)
		  		MouseS=1;
		 if(mouse_press(5,448,48,475)==1)
		        {
		            cleardevice();
					clrmous(MouseX,MouseY);
					bg_paint();
		        } 
			if(mouse_press(5,5,48,33)==2)
		  		MouseS=1;    
		  if(mouse_press(5,5,48,33)==1)
		  {
		  * func=6;
		  return ;
			}
	 }
 }
 
 
 void painting(int m)
 {
 	int i=2,x,y,x0,y0;
 	 if(mouse_press(5,33,640,448)==3||mouse_press(48,5,640,475)==3)
    {
    	if(m!=0)
      {
	  clrmous(MouseX,MouseY);
 		}
 		
	 while(1)
      {
       x=MouseX,y=MouseY;
       newmouse(&MouseX,&MouseY,&press); 
        y0=MouseY-y>0?MouseY-y:y-MouseY;
        x0=MouseX-x>0?MouseX-x:x-MouseX;
        if(m!=0)
      {
	  clrmous(MouseX,MouseY);
 		}
        if(x0>y0)
       {
        for(i=0;i<x0;i++)
         {
		//pieslice(x-8+(MouseX-x)/x0*i,y-8+(MouseY-y)*i/x0,0,360,3); 
		bar(x-8+(MouseX-x)/x0*i,y-8+(MouseY-y)*i/x0,x-m+(MouseX-x)/x0*i,y-m+(MouseY-y)*i/x0);
     	}
       }
       if(x0=y0)
       {
        for(i=0;i<x0;i++)
         {
		bar(x-8+(MouseX-x)/x0*i,y-8+(MouseY-y)*i/x0,x-m+(MouseX-x)/x0*i,y-m+(MouseY-y)*i/x0); 
     	}
       }
        if(x0<y0)
        {
         	for(i=0;i<y0;i++)
         	{
			 //pieslice(x-8+(MouseX-x)*i/y0,y-8+(MouseY-y)/y0*i,0,360,1);
			 bar(x-8+(MouseX-x)*i/y0,y-8+(MouseY-y)/y0*i,x-m+(MouseX-x)*i/y0,y-m+(MouseY-y)/y0*i);
			}
        }
       if(mouse_press(5,33,640,448)==1||mouse_press(48,5,640,475)==1)
       {
         clrmous(MouseX,MouseY);
         break;
        }
     }
    }
 }
