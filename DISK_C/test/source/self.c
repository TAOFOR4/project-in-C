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
#include"drawpage.h"
#include"mouse.h" 
#include"keyboard.h"
#include"judge.h"
#include"clear.h"
#include"self.h" 
#include"info.h"

/***************************************************
Function��     selfcenter

Description��  ���ڸ�����Ϣ�������ת

Input��   void
Output��  
Return:  	0�����ص�¼������
			6�����������������
Others��  
***************************************************/
int selfcenter(user* u,health* h,int* func)//������Ϣ���� 
{
	int self1=0;
	
	cleardevice();
	
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	bg_selfcenter();
	clrmous(MouseX,MouseY);
	
	while(self1==0)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      MouseS=0;	
		if(mouse_press(250,100,450,140)==2)
		  MouseS=1;	
		if(mouse_press(250,100,450,140)==1)
		{
			clrmous(MouseX,MouseY);//�ǳ������ 
			u->name[0]='\0';
			inputname(250,100,10,4,u->name);	
		}
		if(mouse_press(250,160,450,200)==2)
		  MouseS=1;	
		if(mouse_press(250,160,450,200)==1)
		{
			clrmous(MouseX,MouseY);//�������� 
			u->height[0]='\0';
			inputvisible(250,160,3,3,u->height,WHITE);
		}
		if(mouse_press(250,220,450,260)==2)
		  MouseS=1;	
		if(mouse_press(250,220,450,260)==1)
		{
			clrmous(MouseX,MouseY);//��������� 
			u->weight[0]='\0';
			h->weight[0]='\0';
			inputvisible(250,220,3,2,u->weight,WHITE);
			strcpy(h->weight,u->weight);		
		}
		if(mouse_press(180,400,260,440)==2)
		  MouseS=1;	
		if(mouse_press(180,400,260,440)==1)//ȷ�� 
		{
			clrmous(MouseX,MouseY);
			getdat(h->year,h->month,h->day);
			
			setfillstyle(1,LIGHTCYAN);
			bar(180,400,260,440);
			puthz(188,404,"ȷ��",24,22,BLACK);
			self1=1;//ȷ��  
			break;
		}
		if(mouse_press(400,400,480,440)==2)
		  MouseS=1;	
		if(mouse_press(400,400,480,440)==1)//�˳� 
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,LIGHTMAGENTA);
			bar(400,400,480,440);
			puthz(408,404,"�˳�",24,22,BLACK);
			self1=2;//�˳�
			break;
		}
		if (mouse_press(260,280,320,340) == 2)
			MouseS = 1;
		if (mouse_press(260,280,320,340) == 1)//�Ա�Ϊ�� 
		{
			u->sex = 'M';
			clrmous(MouseX, MouseY);
			draw_man2();
			draw_woman1();
		}
		if (mouse_press(380,280,440,340) == 2)
			MouseS = 1;
		if (mouse_press(380,280,440,340) == 1)//�Ա�ΪŮ 
		{
			u->sex = 'W';
			clrmous(MouseX, MouseY);
			draw_man1();
			draw_woman2();
		}
	}
		delay(200);
		clrmous(MouseX,MouseY);
		cleardevice();
		switch(self1)
		{	
		case 1://ȷ��
		input_userinfo(u);
		input_healthinfo(u,h);
		delay(200);
		cleardevice();
		mouseinit(); 
		clrmous(MouseX,MouseY);
		cleardevice();
		
		
		*func=0;
		return ;
		
		case 2://�˳�
		delay(200);
		cleardevice();
		loading();
		mouseinit(); 
		cleardevice();
		clrmous(MouseX,MouseY);
		*func=0;
		return ;
		
		
		}	
	
}


int selfcenter1(user *u,int *func)
{
	int choose=0;
	cleardevice();
	clrmous(MouseX,MouseY);
	readinfo(u);
	bg_selfcenter1(u);
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	while(choose==0)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      MouseS=0;	
		if(mouse_press(240,150,400,200)==2)
		  MouseS=1;	
		if(mouse_press(240,150,400,200)==1)//������Ϣ
		{
			setfillstyle(1,BLUE);
			bar(240,150,400,200);
		
			puthz(260,163,"������Ϣ",24,30,LIGHTRED);
			choose=1;
			break;
		}
		if(mouse_press(240,230,400,280)==2)
		  MouseS=1;	
		if(mouse_press(240,230,400,280)==1)//������Ϣ
		{
			setfillstyle(1,BLUE);
			bar(240,230,400,280);
		
			puthz(260,243,"������Ϣ",24,30,LIGHTRED);
			choose=2;
			break;
		}
		if(mouse_press(240,310,400,360)==2)
		  MouseS=1;	
		if(mouse_press(240,310,400,360)==1)//�޸��ǳ� 
		{
			setfillstyle(1,BLUE);
			bar(240,310,400,360);
		
			puthz(260,323,"�޸��ǳ�",24,30,LIGHTRED);
			choose=3;
			break;
		}
		if(mouse_press(500,400,580,450)==2)
		  MouseS=1;	
		if(mouse_press(500,400,580,450)==1)//����
		{
			setfillstyle(1,BLUE);
			bar(500,400,580,450);
		
			puthz(517,414,"����",24,24,LIGHTRED);
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
		*func=24;
		return ;
		
		case 2:
		delay(100);
		cleardevice();
		*func=25;
		return ;
		
		case 3:
		delay(100);
		cleardevice();
		*func=26;
		return ;
		
		case 4:
		delay(100);
		cleardevice();
		*func=4;
		return ;
	}   

} 


int basicinfo(user* u,int* func)
{
	int choose=0;
	int i;
	char a[5],b[5],f[3],g[3];
	int c,d,e;
	clrmous(MouseX,MouseY);
	bg_basicinfo();
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	readinfo(u);
	for(i=0;i<4;i++)
	{
		a[i]=u->day[i];
	}
	a[4]='\0';
	for(i=0;i<4;i++)
	{
		b[i]=u->day[i+4];
	}
	b[4]='\0';
	c=atoi(b);
	d=c/100;//�� 
	e=c%100;//�� 
	itoa(d,f,10);
	itoa(e,g,10);
	setcolor(LIGHTBLUE);
	outtextxy(220,118,u->name);
	if(u->sex=='M')
	{
		puthz(220,180,"��",32,32,LIGHTBLUE);
	}
	else if(u->sex=='W')
	{
		puthz(220,180,"Ů",32,32,LIGHTBLUE);
	}

	outtextxy(220,238,a);
	outtextxy(340,238,f);
	outtextxy(420,238,g);//��ʾ�ǳƣ��Ա�����
	while(choose==0)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      MouseS=0;	
		if(mouse_press(0,0,60,60)==2)
		  MouseS=1;	
	 	if(mouse_press(0,0,60,60)==1)//���� 
		{
			choose=1; 
			break;
	 	}
	}
	delay(200);
	clrmous(MouseX,MouseY);
	cleardevice();
	switch(choose)
	{
		case 1://���� 
		delay(100);
		cleardevice();
		*func=29;
		return ;
		} 
}

int healthinfo(user* u,int *func)
{
	int choose=0;
	clrmous(MouseX,MouseY);
	bg_healthinfo();
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	setcolor(LIGHTBLUE);
	outtextxy(220,118,u->height);
	outtextxy(220,178,u->weight);
	outputbmi(220,234,u);
	while(choose==0)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      MouseS=0;	
		if(mouse_press(230,300,410,360)==2)
		  MouseS=1;	
		if(mouse_press(230,300,410,360)==1)//�������� 
		{
			setfillstyle(1,LIGHTRED);
			bar(260,300,380,360);
			pieslice(260,330,90,270,30);
			pieslice(380,330,270,360,30);
			pieslice(380,330,0,90,30);
			setcolor(LIGHTRED);
			line(260,300,260,360);
			line(380,300,380,360);
			line(380,330,410,330);
			puthz(260,315,"��������",24,30,WHITE);
			choose=1; 
			break;
	 	} 
	 	if(mouse_press(390,230,470,280)==2)
		  MouseS=1;	
		if(mouse_press(390,230,470,280)==1)//�������� 
		{
			setfillstyle(1,LIGHTRED);
			bar(390,230,470,280);
			pieslice(390,255,90,270,25);
			pieslice(470,255,270,360,25);
			pieslice(470,255,0,90,25);
			setcolor(LIGHTRED);
			line(390,230,390,280);
			line(470,230,470,280);
			line(470,255,495,255);
			puthz(400,240,"����",32,32,WHITE);
			choose=2; 
			break;
	 	} 

	 	if(mouse_press(0,0,60,60)==2)
		  MouseS=1;	
	 	if(mouse_press(0,0,60,60)==1)//���� 
		{
			choose=3; 
			break;
	 	}
	}
	delay(200);
	clrmous(MouseX,MouseY);
	cleardevice();
	switch(choose)
	{
		case 1://�޸���Ϣ 
		delay(100);
		cleardevice();
		*func=27;
		return ;
		
		case 2://�������� 
		delay(100);
		cleardevice();
		*func=31;
		return ;
		
		case 3://���� 
		delay(100);
		cleardevice();
		*func=29;
		return ;
		
		}   

}

int outputbmi(int p,int q,user* u)
{
	char bmi[8]="\0";
	float height, weight;
	height=atof(u->height)/100;
	weight=atof(u->weight);
	sprintf(bmi,"%.1f",weight/height/height);
	outtextxy(p,q,bmi);
}

float bmi(user* u,int x,int record)
{
	float a=0;
	char bmi[8]="\0";
	float height, weight;
	health* h_array;
	h_array=(health*)malloc(50*sizeof(health));
	h_array=read_healthinfo(u,h_array);	
	height=atof(u->height)/100;
	weight=atof(h_array[record].weight);
	sprintf(bmi,"%.1f",weight/height/height);//���bmi�����ַ����� 
	a=atof(bmi);
	setcolor(LIGHTBLUE);
	outtextxy(x-10,255,h_array[record].weight);//��ʾ���� 
	outtextxy(x+30,255,"kg");
	outtextxy(x,78,bmi);
	return a;//����BMI��ֵ 
}


int changename(user* u,int* func)
{
	int choose=0;
	char new_name[20];
	clrmous(MouseX,MouseY);
	bg_changename(u);
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	
	while(choose==0)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      MouseS=0;	
		if(mouse_press(240,200,440,240)==2)
		  MouseS=1;	
		if(mouse_press(240,200,440,240)==1)
		{
			clrmous(MouseX,MouseY);
			new_name[0]='\0';
			inputname(240,200,10,4,new_name);
	 	} 
		if(mouse_press(260,300,380,360)==2)
		  MouseS=1;	
		if(mouse_press(260,300,380,360)==1)//ȷ���޸�
		{
			setfillstyle(1,LIGHTRED);
			bar(260,300,380,360);
			pieslice(260,330,90,270,30);
			pieslice(380,330,270,360,30);
			pieslice(380,330,0,90,30);
			setcolor(LIGHTRED);
			line(260,300,260,360);
			line(380,300,380,360);
			line(380,330,410,330);
			puthz(260,315,"ȷ���޸�",24,30,WHITE);
			strcpy(u->name,new_name);
			input_userinfo(u);
			choose=1; 
			break;
	 	} 
	 	if(mouse_press(0,0,60,60)==2)
		  MouseS=1;	
	 	if(mouse_press(0,0,60,60)==1)//���� 
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
		case 1://ȷ���޸ģ��ص�������Ϣ 
		delay(100);
		cleardevice();
		*func=29;
		return ;
		
		case 2://���� ��Ҳ�ǻص�������Ϣ 
		delay(100);
		cleardevice();
		*func=29;
		return ;
		
		}   

}

void getdat(char*nian,char*yue,char*ri)
{
	char temp[5];
	struct date sdate;
	getdate(&sdate);
	itoa(sdate.da_year,temp,10); 
	strcpy(nian,temp);
	itoa(sdate.da_mon,temp,10); 
	strcpy(yue,temp);
	itoa(sdate.da_day,temp,10); 
	strcpy(ri,temp);
}



int healthdata(user *u,health *h,int *func)
{
	int choose=0;
	bg_healthdata();
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	output_date(u,h);	
	sta(u,h);
	
	while(choose==0)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      MouseS=0;	
		if(mouse_press(260,380,380,440)==2)
		  MouseS=1;	
		 	if(mouse_press(260,380,380,440)==1)//¼������ 
			{
				setfillstyle(1,LIGHTRED);
				bar(260,380,380,440);
				pieslice(260,410,90,270,30);
				pieslice(380,410,270,360,30);
				pieslice(380,410,0,90,30);
				setcolor(LIGHTRED);
				line(260,380,260,440);
				line(380,380,380,440);
				line(380,410,410,410);
				puthz(260,395,"¼������",24,30,WHITE);
				choose=1; 
				break;
	 		} 
	 		if(mouse_press(0,0,60,60)==2)
		  	MouseS=1;	
	 		if(mouse_press(0,0,60,60)==1)//���� 
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
		case 1://¼������ 
		delay(100);
		cleardevice();
		*func=28;
		return ;
		
		case 2://���� 
		delay(100);
		cleardevice();
		*func=25;
		return ;
		
		}  
		
}

int add(user *u,health *h,int *func)
{
	int choose=0;
	int flag=0;
	clrmous(MouseX,MouseY);
	bg_add();
	
	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	setcolor(LIGHTBLUE);
	getdat(h->year,h->month,h->day);
	outtextxy(220,118,h->year);
	outtextxy(340,118,h->month);
	outtextxy(420,118,h->day);

	while(choose==0)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      	MouseS=0;	
		if(mouse_press(220,180,420,220)==2)
		  	MouseS=1;	
		 	if(mouse_press(220,180,420,220)==1)
			{
				clrmous(MouseX,MouseY);
				h->weight[0]='\0';
				flag=inputvisible(220,180,3,2,h->weight,BLACK);
				strcpy(u->weight,h->weight);
				if(flag!=0)//����Ƿ����� 
				{
					h->weight[0]='\0';
					puthz(220,230,"�������",24,24,LIGHTRED);
					delay(3000);
					setfillstyle(11,YELLOW);
					bar(220,230,320,260);
				}
			}
			if(mouse_press(260,300,380,360)==2)
		  		MouseS=1;	
			 if(mouse_press(260,300,380,360)==1)//ȷ����� 
			{
				setfillstyle(1,LIGHTRED);
				bar(260,300,380,360);
				pieslice(260,330,90,270,30);
				pieslice(380,330,270,360,30);
				pieslice(380,330,0,90,30);
				setcolor(LIGHTRED);
				line(260,300,260,360);
				line(380,300,380,360);
				line(380,330,410,330);
				puthz(260,315,"ȷ�����",24,30,WHITE);
				input_healthinfo1(u,h);
				input_userinfo(u);
				choose=1; 
				break;
	 		} 
	 		if(mouse_press(0,0,60,60)==2)
		  		MouseS=1;	
	 		if(mouse_press(0,0,60,60)==1)//���� 
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
		case 1://ȷ����� 
		
		delay(100);
		cleardevice();
		*func=27;
		return ;
		
		case 2://���� 
		delay(100);
		cleardevice();
		*func=27;
		return ;
		
		}   

}

int sta(user* u,health *h)
{
	
	int i=0,m=0;
	health* h_array;
	for(i=0;i<5;i++)
	{
		if (strcmp(h_array[i].weight, "\0") == 0)
			{
				break;
			}
		m=bmi(u,100+80*i,i);
		output_bmi(m,100+i*80);
	}
}

int output_date(user* u,health* h)
{
	health* h_array;
	int i;
	h_array=(health*)malloc(50*sizeof(health));
	h_array=read_healthinfo(u,h_array);
	setcolor(LIGHTBLUE);
	settextstyle(1,0,1);
	for(i=0;i<5;i++)
	{	
			if (strcmp(h_array[i].weight, "\0") == 0)
			{
				break;
			}
			outtextxy(80*i+100,290,h_array[i].year);
			outtextxy(80*i+100,305,h_array[i].month);
			outtextxy(80*i+100,320,h_array[i].day);
		
	}
	
}

void output_bmi(float i,int x)
{
	int y=0;
	
	if(i<18.5)//������ �� ��ɫ 
	{
		if(i<14)
		{
			y=240;
		}
		if(i>=14&&i<16)
		{
			y=228;
		}
		if(i>=16&&i<18.5)
		{
			y=216;
		}
		setfillstyle(1,LIGHTGRAY);
		pieslice(x+15,y,0,360,5);
		setcolor(LIGHTGRAY);
		line(x+15,y,x+20,y);

	}
	
	if(i>=18.5&&i<24)//�������� ��ɫ 
	{
		if(i>=18.5&&i<20)
		{
			y=204;
		}
		if(i>=20&&i<22)
		{
			y=192;
		}
		if(i>=22&&i<24)
		{
			y=180;
		}
		setfillstyle(1,GREEN);
		pieslice(x+15,y,0,360,5);
		setcolor(GREEN);
		line(x+15,y,x+20,y);

	}
		
	if(i>=24&&i<28)//���� //��ɫ 
	{
	
		if(i>=24&&i<26)
		{
			y=168;
		}
		if(i>=26&&i<28)
		{
			y=156;
		}
		setfillstyle(1,LIGHTBLUE);
		pieslice(x+15,y,0,360,5);
		setcolor(LIGHTBLUE);
		line(x+15,y,x+20,y);

	}
	
	if(i>=28)//���� ����ɫ 
	{
	
		if(i>=28&&i<30)
		{
			y=144;
		}
		if(i>=30&&i<32)
		{
			y=132;
		}
		if(i>32)
		{
			y=120;
		}
		setfillstyle(1,LIGHTRED);
		pieslice(x+15,y,0,360,5);
		setcolor(LIGHTRED);
		line(x+15,y,x+20,y);

	}
	
}

int healthadvice(user *u,int *func)
{
	int choose=0;
	int flag=judge_bmi(u);
	clrmous(MouseX,MouseY);
	bg_healthadvice();
	setcolor(LIGHTBLUE);
	outputbmi(380,113,u);
	switch(flag)
	{
		case 1://������ 
		puthz(100,200,"����ǰ�����ع��ᡣ",24,24,LIGHTBLUE);
		puthz(100,240,"����ָ�����Ϳ��ܻ����һ���Ľ�����",24,24,LIGHTBLUE);
		puthz(100,280,"�ա���������ǿ����������������ʡ�",24,24,LIGHTBLUE);
		break;
		case 2://���� 
		puthz(100,200,"����ǰ������ָ���������ġ�",24,24,LIGHTBLUE);
		puthz(100,240,"���ֽ��������������ڽ������ǻ�����",24,24,LIGHTBLUE);
		puthz(100,280,"����״���ķ��գ���ζ����ӽ���Ľ�",24,24,LIGHTBLUE);
		puthz(100,320,"��Ŀ�ꡣϣ�����ܹ��ٽ�������������",24,24,LIGHTBLUE);
		puthz(100,360,"�֣�",24,24,LIGHTBLUE);
		break;
		case 3://����
		puthz(100,200,"����ǰ�����س��ء�",24,24,LIGHTBLUE);
		puthz(100,240,"����ָ��������ܻ����ӻ���Ѫ�ܼ���",24,24,LIGHTBLUE);
		puthz(100,280,"�ķ��ա���Ҫ����ͨ����������ʳ�ͽ�",24,24,LIGHTBLUE);
		puthz(100,320,"�����ı����ʽ���Ը������Ľ�����",24,24,LIGHTBLUE);
		break;
		case 4://����
		puthz(100,200,"����ǰ�������ڷ��֡�",24,24,LIGHTBLUE);
		puthz(100,240,"������Ⱥ����༲���ͽ���״���ķ���",24,24,LIGHTBLUE);
		puthz(100,280,"���ӣ�������Ѫ�ܼ�������Ѫѹ������",24,24,LIGHTBLUE);
		puthz(100,320,"���򲡡���������ȡ��뾡��ͨ������",24,24,LIGHTBLUE);
		puthz(100,360,"����ʳ�ͽ������ı����ʽ���Ը���",24,24,LIGHTBLUE);
		puthz(100,400,"�������彡��������������",24,24,LIGHTBLUE);
		break;
		} 

	clrmous(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	setcolor(LIGHTBLUE);
	while(choose==0)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)  
	      MouseS=0;	
		if(mouse_press(0,0,60,60)==2)
		  MouseS=1;	
	 	if(mouse_press(0,0,60,60)==1)//���� 
		{
			choose=1; 
			break;
	 	}
	}
	delay(200);
	clrmous(MouseX,MouseY);
	cleardevice();
	switch(choose)
	{
		case 1://���� 
		delay(100);
		cleardevice();
		*func=25;
		return ;
		} 

}

int judge_bmi(user* u)
{
	float bmi;
	float height, weight;
	height=atof(u->height)/100;
	weight=atof(u->weight);
	bmi=weight/height/height;
	if(bmi<18.5)
	return 1;
	if(bmi>=18.5&&bmi<24)
	return 2;
	if(bmi>=24&&bmi<28)
	return 3;
	if(bmi>=28)
	return 4;
}



