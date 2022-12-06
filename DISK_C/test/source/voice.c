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
#include"voice.h"
#include"sound.h"

int voice_main(int* func)
{
	SetSVGA64k();
	setbkcolor64k(-1);
	write_hz24("返回",20,5,57355);
	Readbmp64k(180,65,"pic\\4.bmp");
	Readbmp64k(544,65,"pic\\6.bmp");
	write_hz48("《菊次郎的夏天》",155,495,57355);
	write_hz48("《冰山与你》",550,495,57355);
	Barl(290,590,390,635,-50000);
	Barl(645,590,745,635,-50000);
	write_hz24("聆听",320,600,57355);
	write_hz24("聆听",675,600,57355);
	Mouse_Init();
	while(1)
	{
		 MouseShow(&mouse);
			if(MousePress(290,590,390,635,&mouse)==1)
		{
			*func=13;
			return;
		}
		if(MousePress(645,590,745,635,&mouse)==1)
		{
			*func=14;
			return;
		}
		if(MousePress(20,5,80,35,&mouse)==1)
		{
			*func=6;
			CloseSVGA();
			Init();
			return;
		}
	}
	
}
int song_summer(int* func)
{
	unsigned int Base=0;/* 声卡地址*/
	cleardevice();
	Base=DSP_check();
	setbkcolor64k(-1);
	Readbmp64k(152,145,"pic\\5.bmp");
    Readbmp64k(462,660,"pic\\OIP.bmp");
	write_hz24("返回",20,5,57355);
	Mouse_Init();
	while(1)
	{
		 MouseShow(&mouse);
		playwav("music\\Summer.wav",0,Base,func);
		if(MousePress(20,5,80,35,&mouse)==1&&*func==10)
		{
			*func=10;
			return;
		}
		if(MousePress(20,5,80,35,&mouse)==1)
		{
			*func=10;
			return;
		}
	}
}
int song_you(int* func)
{
	unsigned int Base=0;/* 声卡地址*/
	cleardevice();
	Base=DSP_check();
	setbkcolor64k(-1);
	Readbmp64k(152,145,"pic\\7.bmp");
    Readbmp64k(462,660,"pic\\OIP.bmp");
	write_hz24("返回",20,5,57355);
	Mouse_Init();
	while(1)
	{
		 MouseShow(&mouse);
		playwav("music\\you.wav",0,Base,func);
		if(MousePress(20,5,80,35,&mouse)==1&&*func==10)
		{
			*func=10;
			return;
		}
		if(MousePress(20,5,80,35,&mouse)==1)
		{
			*func=10;
			return;
		}
	}
}

int playwav (char* Filename, float delaytime,unsigned int Base,int *func)//filename 音乐路径 
{
    FILE *WAVFile;
    FILE *fp;
    WAVEDATA Voice;
	long i=0,count=0,rest=0;
	int play=0;
	MouseOff(&mouse);
	Mouse_Init();
   while(1)
   {
		 MouseShow(&mouse);
		

		if(MousePress(462,660,562,760,&mouse)==1&&play==0)//播放音乐
		  {
			MouseOff(&mouse);
			Readbmp64k(462, 660, "pic\\clo.bmp");
			play=1;
			MouseOn(&mouse);
			break;
		  }
		  if (MousePress(20,5,80,35, &mouse) == 1) //返回
		{
			*func = 6;
			return ;
		}
	}

	 /*If it can't be opened...*/
	WAVFile = fopen(Filename, "rb");
	if (WAVFile == NULL)
	{
		/*..display error message*/
		ReturnMode();
		printf("fail to find file in function playwav ,press any key to exit");
		getch();

		exit(0);
	}
	
	/*Return length of file for sound length minus 48 bytes for .WAV header
	fseek(WAVFile, 0L, SEEK_END); /*SEEK_SET==0,SEEK_CUR==1,SEEK_END==2*/
	Voice.SoundLength = ftell (WAVFile) - 44;
	fseek(WAVFile, 0L, SEEK_SET);
	
	/*Check RIFF header*/
	if (Voice.SoundLength >LOADSIZE)
	{
		 count = Voice.SoundLength / LOADSIZE; /*load进的音频分成的多少个小音频断的整数部分*/
		  rest = Voice.SoundLength % LOADSIZE;  /*小数部分*/
		 if (rest != 0)
		   {
			 count++;
		    }
		 Voice.SoundLength = LOADSIZE;
	 }
	 else
	{
		count = 1;
		rest = Voice.SoundLength>LOADSIZE?LOADSIZE: Voice.SoundLength;
	}


	/*Load wave file*/
    
    
	while(1)
	{
	   MouseSpeed(0,1)	;
	
		if (i == count -1)
		{
			Voice.SoundLength = rest;/*一个整体一个整体地播放进去，然后当到最后一部分凑不成一个整体时，用rest*/
		}
		
		if (LoadVoice(&Voice,WAVFile,i))
	{
		
		
			/*Start playback*/
			PlayBack (&Voice,count,Base);
			DelayTime((float)LOADSIZE/Voice.Frequency*60+delaytime);
			/*Stops DMA-transfer*/
			WriteDSP(0xD0,Base);
			i++;
			MouseShow(&mouse);
		if(MousePress(462,660,562,760,&mouse)==1&&play==1)//播放音乐 
		  {
		  	MouseOff(&mouse);
		  	Readbmp64k(462,660,"pic\\OIP.bmp"); 
		    play=0;
		    MouseOn(&mouse);
		    break;
		  }
		MouseShow(&mouse);
		if (MousePress(20,5,80,35, &mouse) == 1) //返回
		{
			*func = 10;
			return ;
		}
    }
 }
 
   fclose (WAVFile); 
  return ;
}
