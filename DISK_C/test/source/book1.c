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

void book_duqu(char address[10])
{
	int i=0,j=0;
	FILE* fp;
	char ch;
	char title[50]=".//TXT//book//";
	char tail[5]=".txt";
	char tranfer[400]={'\0'};
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
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
			puthz(j*22,70,tranfer,24,25,BROWN);
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

int book_main(int *func)
{
	int *book;
	cleardevice();
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	*book=0;
	bg_book();
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	while(*book==0)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      MouseS=0;	
		if(mouse_press(123,200,185,230)==2)
		  MouseS=1;
		if(mouse_press(123,200,185,230)==1)//风景名胜 
		{
			setfillstyle(1,BLUE);
			bar(123,200,185,230);
			puthz(131,204,"阅读",24,22,LIGHTRED);
			*book=1;
			break;
		}
		if(mouse_press(473,200,535,230)==2)
		  MouseS=1;
		if(mouse_press(473,200,535,230)==1)//视频赏析 
		{
			setfillstyle(1,BLUE);
			bar(473,200,535,230);
			puthz(481,204,"阅读",24,22,LIGHTRED);
			*book=2;
			break;
		}
		if(mouse_press(123,370,185,400)==2)
		  MouseS=1;
		if(mouse_press(123,370,185,400)==1)//经典阅读 
		{
			setfillstyle(1,BLUE);
			bar(123,370,185,400);
			puthz(131,374,"阅读",24,22,LIGHTRED);
			*book=3;
			break;
		}
		if(mouse_press(473,370,535,400)==2)
		  MouseS=1;
		if(mouse_press(473,370,535,400)==1)//音乐赏析
		{
			setfillstyle(1,BLUE);
			bar(473,370,535,400);
			puthz(481,374,"阅读",24,22,LIGHTRED);
			*book=4;
			break;
		}
		if(mouse_press(5,5,48,33)==2)
		  MouseS=1;
		if(mouse_press(5,5,48,33)==1)
		{
			setfillstyle(1,BLUE);
			bar(5,5,48,33);
			puthz(10,10,"返回",16,20,LIGHTRED);
			*book=5;
			break;
		}
	}
	delay(200);
	clrmous(MouseX,MouseY);
	cleardevice();
	while(1)
   {
		switch(*book)
		{
			case 1:
			delay(100);
			cleardevice(); 
			book_read(func,book);
			return;
			
			case 2:
			delay(100);
			cleardevice();
			book_read(func,book);
			return;
			
			case 3:
			delay(100);
			cleardevice();
			book_read(func,book);
			return;
			
			case 4:
			delay(100);
			cleardevice();
			book_read(func,book);
			return;
			
			case 5:
			delay(100);
			cleardevice();
			*func=6;
			return;
			
		}   
	}
}

void skip(int *book)
{
	int film1=0;
	int k;
			if(*book==1)
			{
			for(k=1;k<6;k++)
			{
				puthz(251+k,11+k,"追风筝的人",32,35,DARKGRAY); 
			 } 
			puthz(250,10,"追风筝的人",32,35,LIGHTRED);
			}
			if(*book==2)
			{
			for(k=1;k<6;k++)
			{
				puthz(251+k,11+k,"怦然心动",32,35,DARKGRAY); 
			 } 
			puthz(250,10,"怦然心动",32,35,LIGHTRED);
			}
			if(*book==3)
			{
			for(k=1;k<6;k++)
			{
				puthz(221+k,11+k,"了不起的盖茨比",32,35,DARKGRAY); 
			 } 
			puthz(220,10,"了不起的盖茨比",32,35,LIGHTRED);
			}
			if(*book==4)
			{
			for(k=1;k<6;k++)
			{
				puthz(251+k,11+k,"阿甘正传",32,35,DARKGRAY); 
			 } 
			puthz(250,10,"阿甘正传",32,35,LIGHTRED);
			}
	setfillstyle(1,LIGHTGRAY);
	bar(20,5,100,35);
	puthz(28,7,"返回",24,40,RED);
	while(film1==0)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      MouseS=0;	
		if(mouse_press(20,5,100,35)==2)
		  MouseS=1;
		if(mouse_press(20,5,100,35)==1)//返回
		{
			film1=1;
			break;
		}
	}
	delay(200);
	clrmous(MouseX,MouseY);
	cleardevice();
	switch(film1)
	{
		case 1://返回
		break;
	}
	
	
}

void book1_read(int *func,int *book)
{
	int i=0;
	int k; 
	FILE* fp;
	char ch;
	char text[40];
	char tranfer[600]={'\0'};
	clrmous(MouseX,MouseY);
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
			if(*book==1)
			{
			for(k=1;k<6;k++)
			{
				puthz(251+k,11+k,"追风筝的人",32,35,DARKGRAY); 
			 } 
			puthz(250,10,"追风筝的人",32,35,LIGHTRED);
			strcpy(text, ".//TXT//book//kite.txt");
			}
			if(*book==2)
			{
			for(k=1;k<6;k++)
			{
				puthz(251+k,11+k,"怦然心动",32,35,DARKGRAY); 
			 } 
			puthz(250,10,"怦然心动",32,35,LIGHTRED);
			strcpy(text, ".//TXT//book//love.txt");
			}
			if(*book==3)
			{
			for(k=1;k<6;k++)
			{
				puthz(221+k,11+k,"了不起的盖茨比",32,35,DARKGRAY); 
			 } 
			puthz(220,10,"了不起的盖茨比",32,35,LIGHTRED);
			strcpy(text, ".//TXT//book//great.txt");
			}
			if(*book==4)
			{
			for(k=1;k<6;k++)
			{
				puthz(251+k,11+k,"阿甘正传",32,35,DARKGRAY); 
			 } 
			puthz(250,10,"阿甘正传",32,35,LIGHTRED);
			strcpy(text, ".//TXT//book//agan.txt");
			}
	setfillstyle(1,LIGHTGRAY);
	bar(20,5,100,35);
	for(k=1;k<9;k++)
	{
		bar(30,7+k*40,130,40+k*40);
	}
	setcolor(WHITE);
	for(k=1;k<9;k++)
	{
		line(32,9+k*40,128,9+k*40);
		line(32,9+k*40,32,38+k*40);
	}
	setcolor(DARKGRAY);
	for(k=1;k<9;k++)
	{
		line(128,38+k*40,128,9+k*40);
		line(128,38+k*40,32,38+k*40);
	}
	puthz(28,7,"返回",24,40,RED);
	puthz(42,52,"前言",24,40,LIGHTBLUE);
	puthz(35,92,"第一章",24,30,LIGHTBLUE);
	puthz(35,132,"第二章",24,30,LIGHTBLUE);
	puthz(35,172,"第三章",24,30,LIGHTBLUE);
	puthz(35,212,"第四章",24,30,LIGHTBLUE);
	puthz(35,252,"第五章",24,30,LIGHTBLUE);
	puthz(35,292,"第六章",24,30,LIGHTBLUE);
	puthz(35,332,"第七章",24,30,LIGHTBLUE);
	if ((fp = fopen(text, "r")) == NULL)//打开对应的文件
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
			puthz(150,70,tranfer,24,22,DARKGRAY);
			i=0;
		}
		else
		{
			i++;
		}
	}
	fclose(fp);
	newmouse(&MouseX,&MouseY,&press);
}


void book_read(int *func,int *book)
{
	char text[40];
	int jump=0;
	cleardevice();
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	book1_read(func,book);
	if(*book==1)
	{
		strcpy(text, "kite");
	}
	if(*book==2)
	{
		strcpy(text, "love");
	}
	if(*book==3)
	{
		strcpy(text, "great");
	}
	if(*book==4)
	{
		strcpy(text, "agan");
	}
	while(1)
	{	
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      MouseS=0;	
		if(mouse_press(20,5,80,35)==2)
		  MouseS=1;
		if(mouse_press(20,5,80,35)==1)
		{
			*func=7;
			return;
		}
		//前言
		if(mouse_press(30,50,130,80)==2)
		  MouseS=1;
		if(mouse_press(30,50,130,80)==1)
		{
		clrmous(MouseX,MouseY);
		setbkcolor(WHITE);
		setfillstyle(11,YELLOW);
		bar(0,0,640,480);
		strcat(text,"0");
		book_duqu(text);
		puthz(450,40,"前言",24,35,LIGHTBLUE);
		skip(book);
		clrmous(MouseX,MouseY);
		memset(text, 0, sizeof(char) * 40);
		book_read(func,book);
		}
		newmouse(&MouseX,&MouseY,&press);//第一章
		if(mouse_press(30,90,130,120)==2)
		  MouseS=1;
		if(mouse_press(30,90,130,120)==1)
		{
		clrmous(MouseX,MouseY);
		setbkcolor(WHITE);
		setfillstyle(11,YELLOW);
		bar(0,0,640,480);
		strcat(text,"1");
		book_duqu(text);
		puthz(450,40,"第一章",24,35,LIGHTBLUE);
		skip(book);
		clrmous(MouseX,MouseY);
		memset(text, 0, sizeof(char) * 40);
		book_read(func,book);
		}
		newmouse(&MouseX,&MouseY,&press);	//第二章
		if(mouse_press(30,130,130,160)==2)
		  MouseS=1;
		if(mouse_press(30,130,130,160)==1)
		{
		clrmous(MouseX,MouseY);
		setbkcolor(WHITE);
		setfillstyle(11,YELLOW);
		bar(0,0,640,480);
		strcat(text,"2");
		book_duqu(text);
		puthz(450,40,"第二章",24,35,LIGHTBLUE);
		skip(book);
		clrmous(MouseX,MouseY);
		memset(text, 0, sizeof(char) * 40);
		book_read(func,book);
		}
		newmouse(&MouseX,&MouseY,&press);	//第三章
		if(mouse_press(30,170,130,200)==2)
		  MouseS=1;
		if(mouse_press(30,170,130,200)==1)
		{
		clrmous(MouseX,MouseY);
		setbkcolor(WHITE);
		setfillstyle(11,YELLOW);
		bar(0,0,640,480);
		strcat(text,"3");
		book_duqu(text);
		puthz(450,40,"第三章",24,35,LIGHTBLUE);
		skip(book);
		clrmous(MouseX,MouseY);
		memset(text, 0, sizeof(char) * 40);
		book_read(func,book);
		}
		newmouse(&MouseX,&MouseY,&press);//第四章
		if(mouse_press(30,210,130,240)==2)
		  MouseS=1;
		if(mouse_press(30,210,130,240)==1)
		{
		clrmous(MouseX,MouseY);
		setbkcolor(WHITE);
		setfillstyle(11,YELLOW);
		bar(0,0,640,480);
		strcat(text,"4");
		book_duqu(text);
		puthz(450,40,"第四章",24,35,LIGHTBLUE);
		skip(book);
		clrmous(MouseX,MouseY);
		memset(text, 0, sizeof(char) * 40);
		book_read(func,book);
		}
		newmouse(&MouseX,&MouseY,&press);	//第五章
		if(mouse_press(30,250,130,280)==2)
		  MouseS=1;
		if(mouse_press(30,250,130,280)==1)
		{
		clrmous(MouseX,MouseY);
		setbkcolor(WHITE);
		setfillstyle(11,YELLOW);
		bar(0,0,640,480);
		strcat(text,"5");
		book_duqu(text);
		puthz(450,40,"第五章",24,35,LIGHTBLUE);
		skip(book);
		clrmous(MouseX,MouseY);
		memset(text, 0, sizeof(char) * 40);
		book_read(func,book);
		}
		newmouse(&MouseX,&MouseY,&press);//第六章
		if(mouse_press(30,290,130,320)==2)
		  MouseS=1;
		if(mouse_press(30,290,130,320)==1)
		{
		clrmous(MouseX,MouseY);
		setbkcolor(WHITE);
		setfillstyle(11,YELLOW);
		bar(0,0,640,480);
		strcat(text,"6");
		book_duqu(text);
		puthz(450,40,"第六章",24,35,LIGHTBLUE);
		skip(book);
		clrmous(MouseX,MouseY);
		memset(text, 0, sizeof(char) * 40);
		book_read(func,book);
		}
		newmouse(&MouseX,&MouseY,&press);	//第七章
		if(mouse_press(30,330,130,360)==2)
		  MouseS=1;
		if(mouse_press(30,330,130,360)==1)
		{
		clrmous(MouseX,MouseY);
		setbkcolor(WHITE);
		setfillstyle(11,YELLOW);
		bar(0,0,640,480);
		strcat(text,"7");
		book_duqu(text);
		puthz(450,40,"第七章",24,35,LIGHTBLUE);
		skip(book);
		clrmous(MouseX,MouseY);
		memset(text, 0, sizeof(char) * 40);
		book_read(func,book);
		}
	}
}

