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
void Init(void)
{
	int gd = VGA;
	int gm = VGAHI;
	initgraph(&gd, &gm, ".//BORLANDC//BGI");
	mouseinit(); 
}
void scenery_jieshuo(char address[10])
{
	int i=0,j=0;
	FILE* fp;
	char ch;
	char title[50]=".//TXT//scenery//";
	char tail[5]=".txt";
	char tranfer[400]={'\0'};
	setbkcolor(BLACK);
	strcat(title,address);
	strcpy(tail,".txt");
	strcat(title,tail);
	if ((fp = fopen(title, "r")) == NULL)//�򿪶�Ӧ���ļ�
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
			tranfer[i]='\0';      //һ�߶�ȡ�ļ��е���Ϣһ�߽���Ϣ�������             
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


int scenery_main(int* func)//�羰 
{
	int* scenery=0;
	bg_scenery();
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      MouseS=0;	
		if(mouse_press(5,5,48,33)==2)
		  MouseS=1;
		if(mouse_press(5,5,48,33)==1)
		{
			*scenery=8;
			break; 
		}//������ť
		if(mouse_press(140,185,150,195)==2)
		  MouseS=1;
		if(mouse_press(140,185,150,195)==1)//�½���ɽ
		{
			*scenery=1;
			break;
		}
		if(mouse_press(137,285,147,295)==2)
		  MouseS=1;
		if(mouse_press(137,285,147,295)==1)//��������
		{
			*scenery=2;
			break;
		}
		if(mouse_press(465,202,475,212)==2)
		  MouseS=1;
		if(mouse_press(465,202,475,212)==1)//����
		{
			*scenery=3;
			break;
		}
		if(mouse_press(305,299,315,309)==2)
		  MouseS=1;
		if(mouse_press(305,299,315,309)==1)//�Ĵ�
		{
			*scenery=4;
			break;
		}
		if(mouse_press(435,297,445,307)==2)
		  MouseS=1;
		if(mouse_press(435,297,445,307)==1)//�人
		{
			*scenery=5;
			break;
		}
		if(mouse_press(427,328,437,338)==2)
		  MouseS=1;
		if(mouse_press(427,328,437,338)==1)//۶��
		{
			*scenery=6;
			break;
		}
		if(mouse_press(406,235,416,245)==2)
		  MouseS=1;
		if(mouse_press(406,235,416,245)==1)//̫��
		{
			*scenery=7;
			break;
		}
	}
	delay(200);
	clrmous(MouseX,MouseY);
	cleardevice();
	while(1)
   {
		switch(*scenery)
		{
			case 1:
			delay(100);
			cleardevice(); 
			scenery1(func,scenery);
			return;
			
			case 2:
			delay(100);
			cleardevice();
			scenery1(func,scenery);
			return;
			
			case 3:
			delay(100);
			cleardevice();
			scenery1(func,scenery);
			return;
			
			case 4:
			delay(100);
			cleardevice();
			scenery1(func,scenery);
			return;
			
			case 5:
			delay(100);
			cleardevice();
			scenery1(func,scenery);
			return;
			
			case 6:
			delay(100);
			cleardevice();
			scenery1(func,scenery);
			return;
			
			case 7:
			delay(100);
			cleardevice();
			scenery1(func,scenery);
			return;
			
			case 8:
			delay(100);
			cleardevice();
			*func=6;
			return;
			
		}   
	}
}


void scenery1(int* func,int *scenery)
{
	
	int m=(*scenery*5-4);
	char text[40];
	char title[50]=".//TXT//photo//";
	char tail[5]=".bmp";
	cleardevice();
	setbkcolor(WHITE);
	strcpy(text,title);
	if(*scenery==1)
	{
	puthz(230,6,"�½���ɽ",24,40,LIGHTBLUE);
	strcat(text, "tianshan");
	}
	if(*scenery==2)
	{
	puthz(230,6,"��������",24,40,LIGHTBLUE);
	strcat(text, "buda");
	}
	if(*scenery==3)
	{
	puthz(230,6,"�����ʹ�",24,40,LIGHTBLUE);
	strcat(text, "gugong");
	}
	if(*scenery==4)
	{
	puthz(230,6,"��խ����",24,40,LIGHTBLUE);
	strcat(text, "xiangzi");
	}
	if(*scenery==5)
	{
	puthz(230,6,"�ƺ�¥",24,40,LIGHTBLUE);
	strcat(text, "huanghe");
	}
	if(*scenery==6)
	{
	puthz(230,6,"������",24,40,LIGHTBLUE);
	strcat(text, "tengwang");
	}
	if(*scenery==7)
	{
	puthz(230,6,"̫��ɽ",24,40,LIGHTBLUE);
	strcat(text, "taihang");
	}
	strcat(text, tail);
	setfillstyle(1,LIGHTCYAN);
	bar(520,5,580,35);
	puthz(520,5,"��˵",24,40,LIGHTRED);
	bar(420,5,480,35);
	puthz(420,5,"ͼƬ",24,40,LIGHTRED);
	bar(20,5,100,35);
	puthz(20,5,"����",24,40,LIGHTRED);
	putbmp(0,40,text);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      MouseS=0;	
		if(mouse_press(520,5,580,35)==2)
		  MouseS=1;	
		if(mouse_press(520,5,580,35)==1)//��˵	
		{
			clrmous(MouseX,MouseY);
			wenzi(func,scenery);
			break;
		}
		if(mouse_press(420,5,480,35)==2)
		  MouseS=1;	
		if(mouse_press(420,5,480,35)==1)
		{
			clrmous(MouseX,MouseY);
			picture_tianshan(func,m,scenery);
			break;
		}	
		if(mouse_press(20,5,80,35)==2)
		  MouseS=1;	
		if(mouse_press(20,5,80,35)==1)//����
		{
			clrmous(MouseX,MouseY);
			*func=8;
			return ;
		}
		
	}
	
}	

int wenzi(int* func,int *scenery)
{
	
	char text[40];
	cleardevice();
	setfillstyle(1,WHITE);
	rectangle(20,5,100,35);
	puthz(20,5,"����",32,40,WHITE);
	if(*scenery==1)
	{
	strcpy(text, "tianshan");
	}
	if(*scenery==2)
	{
	strcpy(text, "buda");
	}
	if(*scenery==3)
	{
	strcpy(text, "gugong");
	}
	if(*scenery==4)
	{
	strcpy(text, "xiangzi");
	}
	if(*scenery==5)
	{
	strcpy(text, "huanghe");
	}
	if(*scenery==6)
	{
	strcpy(text, "tengwang");
	}
	if(*scenery==7)
	{
	strcpy(text, "taihang");
	}
	scenery_jieshuo(text);
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);	//����
		if(MouseS!=0)  
	      MouseS=0;	
		if(mouse_press(20,5,80,35)==2)
		  MouseS=1;	
		if(mouse_press(20,5,80,35)==1)
		{
			scenery1(func,scenery);
			return;
		}
		
	}
	
}


void picture_tianshan(int* func,int m,int *scenery)
{
	char file[40]; 
	char ch[5];
	
	cleardevice();
	strcpy(file,"picture\\");
		itoa(m,ch,10);
		strcat(file,ch);
		strcat(file,".bmp");
	putbmp(0,0,file);
	puthz(5,5,"����",16,20,RED);
	puthz(520,5,"��һ��",16,20,RED);
	puthz(580,5,"��һ��",16,20,RED);
	memset(file, 0, sizeof(char) * 40);
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	while(1)
	{
		 newmouse(&MouseX,&MouseY,&press);
		 if(mouse_press(520,5,575,35)==1)
		{
			if(m!=(*scenery*5-4))
			{
				m=m-1;
				clrmous(MouseX,MouseY);
				picture_tianshan(func,m,scenery);
			}
			else
			{
				setfillstyle(1,WHITE);
				bar( 220,200, 420, 300);
				puthz(235,235,"�Ѿ��ǵ�һ����",24,20,RED);
				delay(1500);
				clrmous(MouseX,MouseY);
				picture_tianshan(func,m,scenery);
			}
			break;
		}
		 if(mouse_press(580,5,640,35)==1)
		{
			if(m!=(*scenery*5))
			{
				m=m+1;
				clrmous(MouseX,MouseY);
				picture_tianshan(func,m,scenery);
			}
			else
			{
				setfillstyle(1,WHITE);
				bar( 220,200, 420, 300);
				puthz(235,235,"�Ѿ������һ����",24,20,RED);
				delay(1500);
				clrmous(MouseX,MouseY);
				picture_tianshan(func,m,scenery);
			
			}
			break;
		}
		if(mouse_press(20,5,80,35)==1)
		{
			clrmous(MouseX,MouseY);
			scenery1(func,scenery);
			return;
		}
	}
	
}
