#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include"hz.h"
#include"loggin.h" 
#include"drawpage.h"
#include"draw.h"
#include"mouse.h" 
#include"keyboard.h" 
#include"judge.h"
#include"clear.h"
#include"self.h"
#include"shijiao.h"
#include"info.h"

int login(user *u,int* func)//��½������ת
{
	int passage1=0;
	int g;
	cleardevice();
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	bg_login();
	clearaccount2(u->id);
	clearpassword2(u->password);
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	while(passage1==0)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      MouseS=0;	
		if(mouse_press(250,170,460,210)==2)
		  MouseS=1;
		if(mouse_press(250,170,460,210)==1)
		{
			clrmous(MouseX,MouseY);//�˺������ 
			inputaccount(u->id, 250, 177, 8, BLACK);		
		}
		if(mouse_press(250,220,460,260)==2)
		  MouseS=1;
		if(mouse_press(250,220,460,260)==1)
		{
			clrmous(MouseX,MouseY);//��������� 
			inputpassword(u->password,250,227,8,BLACK);		
		}
		if(mouse_press(38,350,100,380)==2)
		  MouseS=1;
		if(mouse_press(38,350,100,380)==1)//���� 
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,LIGHTCYAN);
			bar(38,350,100,380);
			puthz(46,354,"����",24,22,BLACK);
			g=judge_password(u->id,u->password);
			if(g==0)
			{
                delay(200);
                clearaccount1(u->id);
				clearpassword1(u->password);
				cleardevice( );
				* func=0;
				return ;
			}
			passage1=1;//Enter
			
			break;
		}
		if(mouse_press(135,350,215,380)==2)
		  MouseS=1;
		if(mouse_press(135,350,215,380)==1)//���û� 
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,LIGHTBLUE);
			bar(135,350,215,380);
			puthz(142,354,"���û�",24,22,BLACK);
			passage1=2;//registry
			break;
		}
		if(mouse_press(250,350,357,380)==2)
		  MouseS=1;
		if(mouse_press(250,350,357,380)==1)//�������� 
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,LIGHTBLUE);
			bar(250,350,357,380);
			puthz(257,354,"��������",24,22,BLACK);
			passage1=3;//Forget
			delay(200);
	        clrmous(MouseX,MouseY);
			cleardevice();
			break;
		}
		if(mouse_press(500,350,550,380)==2)
		  MouseS=1;
		if(mouse_press(500,350,550,380)==1)//�˳� 
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,LIGHTRED);
			bar(500,350,550,380);
			puthz(503,354,"�˳�",24,22,BLACK);
			delay(400);
			exit(0);
			break;
		}
		if(mouse_press(375,350,477,380)==2)
		  MouseS=1;
		if(mouse_press(375,350,477,380)==1)//�ο�ģʽ 
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,LIGHTBLUE);
			bar(375,350,473,380);
			puthz(379,354,"�������",24,22,BLACK);
			passage1=4;//Visiter 
			break;
		}
	}
	delay(200);
	clrmous(MouseX,MouseY);
	cleardevice();
	switch(passage1)
	{	
		case 1://Enter
		delay(200);
		cleardevice();
		bg_welcom();
		mouseinit(); 
		clrmous(MouseX,MouseY);
		cleardevice();
		 *func=4;
		return ;
		
		case 2://Newuser
		delay(200);
		cleardevice();
		loading();
		mouseinit(); 
		cleardevice();
		clrmous(MouseX,MouseY);
		bg_registry();
		* func=1;
		return ;
		
		case 3://Forget
		delay(200);
		cleardevice();
		loading();
		cleardevice();
		clrmous(MouseX,MouseY);
		 *func=2;
		return ;
			
		case 4://Visiter
		cleardevice();
		delay(200);
		cleardevice();
		/*bg_welcom();*/
		clrmous(MouseX,MouseY);
		* func=30;
		return ;
	}
}
/***************************************************
Function��     registry

Description��  ����ע�����Ľ������ת

Input��   void
Output��  
Return:  	0�����ص�¼������
			7:�����Ƽ���Ӱ������
			9������ע������������
Others��  
***************************************************/
int registry(user *u,int *func)//ע��������ת
{
	int passage2=0;
	int pass=0;
	bg_registry();
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	clearaccount(u->id);
	clearpassword(u->password);
	clearpass(u->pass);
	clearid(u->day);
	while(passage2==0)
	{
		int i,k,m;
		i=0;
		k=0;
		m=0;
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      MouseS=0;	
	      
		if(mouse_press(220,110,500,150)==2)
		  MouseS=1;
		if(mouse_press(220,110,500,150)==1)
		{
		    inputnewaccount(u->id, 220, 120, 8, BLACK);
		    k=judge_account(u->id);
			if(k==0)
			{
			   clearaccount(u->id);
			   continue;
			}
			if(judge_len(u->id)==1)
			{
				clearaccount(u->id);
				continue;
			}
			if(judge_lenaccount(u->id)==1)
			{
				clearaccount(u->id);
				continue;
			}
			if(judge_blank1(u->id,0,0)==1)
			{
				clearaccount(u->id);
				continue;
			}
		}
		if(mouse_press(220,160,500,200)==2)
		  MouseS=1;
		if(mouse_press(220,160,500,200)==1)
		{
		    inputnewaccount(u->password, 220, 170, 8, BLACK);	
			if(judge_len1(u->password)==1)
			{
				clearpassword(u->password);
				continue;
			}
			if(judge_lenpassword(u->password)==1)
			{
				clearpassword(u->password);
				continue;
			}
			 if(judge_blank1(u->password,0,0)==1)
			{
				clearpassword(u->password);
				continue;
			}
		}
		if(mouse_press(220,210,500,250)==2)
		  MouseS=1;
		if(mouse_press(220,210,500,250)==1)
		{
		    inputnewaccount(u->pass, 220, 225, 8, BLACK);
			if(judge_len1(u->pass)==1)
			{
				clearpass(u->pass);
				continue;
			}
			if(judge_lenpassword(u->pass)==1)
			{
				clearpass(u->pass);
				continue;
			}
			if(judge_blank1(u->pass,0,0)==1)
			{
				clearpass(u->pass);
				continue;
			}
		}
		if(mouse_press(220,260,500,300)==2)
		  MouseS=1;
		if(mouse_press(220,260,500,300)==1)
		{
		    inputnewaccount(u->day, 220, 270, 8, BLACK)	;
		    m=judge_id(u->day);
			if(m==0)
			{
			    clearid(u->day);
				continue;
			}//�ж�id�Ƿ��Ѿ�����
			if(judge_lenid(u->day)==1)
			{
				clearid(u->day);
				continue;
			}
			if(judge_blank1(u->day,0,0)==1)
			{
				clearid(u->day);
				continue;
			}
		}
		if(mouse_press(140,400,240,430)==2)
		  MouseS=1;
		if(mouse_press(140,400,240,430)==1)
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,GREEN);
			bar(140,400,240,430);
			puthz(160,403,"ע��",24,30,BLACK);
			clrmous(MouseX,MouseY);
			if(judge_blank1(u->id,0,0)==1)
			{
				clearaccount(u->id);
				continue;
			}
			if(judge_blank1(u->password,0,0)==1)
			{
				clearpassword(u->password);
				continue;
			}
			if(judge_blank1(u->pass,0,0)==1)
			{
				clearpass(u->pass);
				continue;
			}
			if(judge_blank1(u->day,0,0)==1)
			{
				clearid(u->day);
				continue;
			}
			if(judge_correct(u->password,u->pass)==1)
			{
				clearpassword(u->password);
				clearpass(u->pass);
				continue;
			}
			input_database(u->id,u->password,u->day);
			passage2=1;//registry
			break;
		}
		if(mouse_press(370,400,470,430)==2)
		  MouseS=1;
		if(mouse_press(370,400,470,430)==1)
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,LIGHTRED);
			bar(370,400,470,430);
			puthz(390,403,"�˳�",24,30,BLACK);
			clrmous(MouseX,MouseY);
			passage2=2;//cancel
			break;
		}
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(600,50,630,80)==1)
		{
			cleardevice();
			loading();
			cleardevice();
			*func=0;
			return ;
		}//
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(600,50,630,80)==2)
		{
			
			exit(0);
			break;
		}//������ť
	}
	delay(200);
	clrmous(MouseX,MouseY);
	switch(passage2)
	{	
		case 1://register
		clrmous(MouseX,MouseY);
		cleardevice();
		//welcom();
		*func=3;
		return ;
		
		case 2://
		clearaccount(u->id);
		clearpassword(u->password);
		clearpass(u->pass);
		clearid(u->day);
		cleardevice();	
		delay(200);
		loading();
		mouseinit(); 
		cleardevice();	
		clrmous(MouseX,MouseY);
		*func=0;
		return ;
	    
	}
}
/***************************************************
Function��     forget

Description��  ������������������ת

Input��   void
Output��  
Return:  	0�����ص�¼������
			6�����������������
Others��  
***************************************************/
int forget(user *u,int* func)//�������������ת
{
	int forget1=0;
	mouseinit(); 
	cleardevice();
	clrmous(MouseX,MouseY);
	bg_forget();
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	clearday_(u->day);
	while(forget1==0)
	{	
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      MouseS=0;	
		if(mouse_press(200,145,450,175)==2)
		  MouseS=1;
		if(mouse_press(200,145,450,175)==1)
		{
		   	inputnewaccount(u->id,200 ,150 , 8, BLACK);
		}
		if(mouse_press(200,195,450,225)==2)
		  MouseS=1;
		if(mouse_press(200,195,450,225)==1)
		{
		    inputnewaccount(u->day, 200, 200, 8, BLACK);	
		}
		if(mouse_press(150,340,240,380)==2)
		  MouseS=1;
		if(mouse_press(150,340,240,380)==1)
		{
		clrmous(MouseX,MouseY);
		    if(lookforpassword(u->id,u->day)==0)
			{
				clrmous(MouseX,MouseY);
				forget1=2;
			}
		}
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(450,340,530,380)==2)
		  MouseS=1;
		if(mouse_press(450,340,530,380)==1)
		{
			clrmous(MouseX,MouseY);
			forget1=1;//cancel
			break;
		}
	}
	delay(200);
	clrmous(MouseX,MouseY);
	cleardevice();
	switch(forget1)
	{
		case 1://cancel
		clrmous(MouseX,MouseY);
		loading();
		clrmous(MouseX,MouseY);
		cleardevice();
		*func=0;
		return ;
		
	    case 2:
	    clrmous(MouseX,MouseY);
		cleardevice();
		*func=2;
		return ;
	}
}
int  center(user *u,int*func)
{
	int choose=0;
	cleardevice();
	clrmous(MouseX,MouseY);
	bg_center();
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	while(choose==0)
	{
		
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      MouseS=0;	
	      
		if(mouse_press(80,120,200,160)==2)
		  MouseS=1;
		if(mouse_press(80,120,200,160)==1)//��������
		{
			setfillstyle(1,BLUE);
			bar(80,120,200,160);
		
			puthz(82,125,"��������",24,30,LIGHTRED);
			choose=1;
			break;
		}
		if(mouse_press(80,360,200,400)==2)
		  MouseS=1;
		if(mouse_press(80,360,200,400)==1)//��������
		{
			setfillstyle(1,BLUE);
			bar(80,360,200,400);
		
			puthz(82,365,"��������",24,30,LIGHTRED);
			choose=2;
			break;
		}
		if(mouse_press(480,120,600,160)==2)
		  MouseS=1;
		if(mouse_press(480,120,600,160)==1)//��ѧ����
		{
			setfillstyle(1,BLUE);
			bar(480,120,600,160);
			puthz(482,125,"��������",24,30,LIGHTRED);
			choose=3;
			break;
		}
		if(mouse_press(480,360,600,400)==2)
		  MouseS=1;
		if(mouse_press(480,360,600,400)==1)//��ѧ����
		{
			setfillstyle(1,BLUE);
			bar(480,360,600,400);
			puthz(482,365,"�˳���¼",24,30,LIGHTRED);
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
		*func=29;
		return ;
		
		case 2:
		delay(100);
		cleardevice();
	//	bg_nullpage();
		*func=6;
		return ;
		
		case 3:
		delay(100);
		cleardevice();
	//	bg_teachingcenter();
		*func=19;
		return ;
		
		case 4:
		delay(100);
		cleardevice();
		//bg_login1();
		clrmous(MouseX,MouseY);
		*func=0;
		return ;
	}   
}
	
	

