#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include"hz.h"
#include"loggin.h" 
#include"draw.h"
#include"mouse.h" 
#include"keyboard.h" 
#include"clear.h"
#include"self.h" 
#include"info.h"

void clearaccount2(char *account)
{
	int i;
	setfillstyle(1,WHITE);
	bar(250,170,460,210);
	for(i=0;i<9;i++)
	{
		account[i]='\0';
	}
	
}

void clearpassword2(char *password)
{
	int i;
	setfillstyle(1,WHITE);
	bar(250,220,460,260);
	for(i=0;i<9;i++)
	{
		password[i]='\0';
	}
}
void clearaccount1(char *account)
{
	int i;
	setfillstyle(1,LIGHTGRAY);
	bar(250,170,460,210);
	for(i=0;i<9;i++)
	{
		account[i]='\0';
	}
	
}

void clearpassword1(char *password)
{
	int i;
	setfillstyle(1,LIGHTGRAY);
	bar(250,220,460,260);
	for(i=0;i<9;i++)
	{
		password[i]='\0';
	}
}
/***************************************************
Function��     clearaccount

Description��  

Input��   char *account   �û��˺�
         
Output��   void

Others�� ����û��˺���������Ϣ
***************************************************/
void clearaccount(char *account)
{
	int i;
	setfillstyle(1,LIGHTGRAY);
	bar(220,110,500,150);
	for(i=0;i<9;i++)
	{
		account[i]='\0';
	}
	setfillstyle(1,BLACK);
	bar(500,100,640,135);
	bar(140,360,640,395);
	bar(0,0,400,42);
	setcolor(WHITE);
	rectangle(220,110,500,150);
}

/***************************************************
Function��     clearpassword

Description��  

Input��   char *password  �û�����
         
Output��   void

Others�� ����û�������������Ϣ
***************************************************/
void clearpassword(char *password)
{
	int i;
	setfillstyle(1,LIGHTGRAY);
	bar(220,160,500,200);
	for(i=0;i<9;i++)
	{
		password[i]='\0';
	}
	setfillstyle(1,BLACK);
	bar(140,360,640,395);
	bar(0,0,400,42);
	setcolor(WHITE);
	rectangle(220,160,500,200);
}

/***************************************************
Function��     clearid

Description��  

Input��   char *id        �û����֤����λ
         
Output��   void

Others�� ����û���ݺ���λ��������Ϣ
***************************************************/
void clearid(char *id)
{
	int i;
	setfillstyle(1,LIGHTGRAY);
	bar(220,260,500,300);
	for(i=0;i<9;i++)
	{
		id[i]='\0';
	}
	setfillstyle(1,BLACK);
	bar(120,360,640,395);
	bar(0,0,400,42);
	//bar(500,270,640,305);
	setcolor(WHITE);
	rectangle(220,260,500,300);
}

/***************************************************
Function��     clearpass

Description��  

Input��   char *pass      �û�ȷ������
         
Output��   void

Others�� ����û�ȷ��������������Ϣ
***************************************************/
void clearpass(char *pass)
{
	int i;
	setfillstyle(1,LIGHTGRAY);
	bar(220,210,500,250);
	for(i=0;i<9;i++)
	{
		pass[i]='\0';
	}
	setfillstyle(1,BLACK);
	bar(140,360,640,395);
	bar(0,0,400,42);
	//bar(500,270,640,305);
	setcolor(WHITE);
	rectangle(220,210,500,250);
}



void clearday_(char *day)
{
	int i;
	setfillstyle(1,LIGHTGRAY);
	bar(200,195,450,225);
	for(i=0;i<9;i++)
	{
		day[i]='\0';
	}
	setcolor(YELLOW);
	rectangle(200,195,450,225);
}
