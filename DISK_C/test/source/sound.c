/******************************
用于播放8位单声道pcm编码的wave
http://hi.baidu.com/moonharvest/item/4a06515fad7c804c4fff2058
http://hi.baidu.com/moonharvest/item/4a06515fad7c804c4fff2058
******************************/
#include <alloc.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include"sound.h"


void ReturnMode()        
{
    union REGS in;
    in.h.ah=0;
    in.h.al=(char)0x03;
    int86(0x10,&in,&in);  /*中断*/
    return;
}

/*****************************************************************************************
利用 (inportb(0x3da)&0x08)!= 0 && action_flag == 0  循环四次 count_t计数加1准确计时的函数                                         
******************************************************************************************/
void DelayTime(float delaytime)   //看的不是很懂
{
    int action_flag = 0;
    long count_t=0;
    do
    {
		if ((inportb(0x3da)&0x08)!= 0 && action_flag == 0)
		{
			count_t++;
			if (count_t >= delaytime)
			{
				break;
			}
			action_flag = 1;
		}
		else if ((inportb(0x3da)&0x08)== 0 && action_flag == 1)
		{
			action_flag = 0;
		}	
    }while(1);
}

/****************************************************************************
** 检查声卡是否在给定的几个地址之中，                                          **
** 若存在返回1，若不存在不存在返回0                                                **
****************************************************************************/
int ResetDSP(unsigned int Test)
{
    unsigned int Base;
    /*重置 DSP*/
    outportb (Test + 0x6, 1);
    delay(10);     /*延时是必须的*/
    outportb (Test + 0x6, 0);
    delay(10);
    /*如果重置成功则检查*/
    if ((inportb(Test + 0xE) & 0x80 == 0x80) && (inportb(Test + 0xA) == 0xAA))
    {
		/*DSP was found*/
		Base = Test;
		return (Base);
	}
    else
		/*No DSP was found*/
		return (0);
}
/****************************************************************************
** DSP播放声音                                                             **
****************************************************************************/
void WriteDSP(unsigned char Value,unsigned int Base)
{
	/*Wait for the DSP to be ready to accept data*/
	while ((inportb(Base + 0xC) & 0x80) == 0x80);
	/*Send byte*/
	outportb (Base + 0xC, Value);
}
/******************************************************************************************
** 将内存中的数据读出,经过DMA信道1，放到DSP端口，此段函数借鉴wav播放技术上的中断写和DMA写**
******************************************************************************************/
void PlayBack (WAVEDATA *Wave,long count,unsigned int Base)/*i表示传入的是第几段的音频*/
{
	long          LinearAddress;
	unsigned int  Page, OffSet;
	unsigned char TimeConstant;
	TimeConstant = (65536 - (256000000 / Wave->Frequency)) >> 8;

	WriteDSP(0x40,Base);                  /*DSP-command 40h - Set sample frequency*/
	WriteDSP(TimeConstant,Base);          /*Write time constant*/

	/*Convert pointer to linear address*/
	LinearAddress = FP_SEG (Wave->Sample);
	LinearAddress = (LinearAddress << 4) + FP_OFF (Wave->Sample);

	Page = LinearAddress >> 16;      /*Calculate page*/
	OffSet = LinearAddress & 0xFFFF; /*Calculate offset in the page*/
/*
Note - this procedure only works with DMA channel 1
*/
	outportb (0x0A, 5);              /*Mask DMA channel 1*/
	outportb (0x0C, 0);              /*Clear byte pointer*/
	outportb (0x0B, 0x49);           /*Set mode*/
/*
The mode consists of the following:
0x49 = binary 01 00 10 01
|  |  |  |
|  |  |  +- DMA channel 01
|  |  +---- Read operation (the DSP reads from memory)
|  +------- Single cycle mode
+---------- Block mode
*/
	outportb (0x02, OffSet & 0x100); /*Write the offset to the DMA controller*/
	outportb (0x02, OffSet >> 8);
	outportb (0x83, Page);           /*Write the page to the DMA controller*/
	outportb (0x03, Wave->SoundLength & 0x100);
	outportb (0x03, Wave->SoundLength >> 8);
	outportb (0x0A, 1);              /*Unmask DMA channel*/
	WriteDSP(0x14,Base);                  /* DSP-command 14h - Single cycle playback*/
	WriteDSP(Wave->SoundLength & 0xFF,Base);
	WriteDSP(Wave->SoundLength >> 8,Base);
	 //if(i==count-1)  /*到达最后一段时，free掉占用的内存*/
	//{
	//farfree(Wave->Sample);/*不然有可能在这个位置上的内存被占用导致程序运行出错，这里有一个比较难调和和发现的bug*/
	//}
   /* free(Wave->Sample);不能直接加这个，否则只能load进第一段*/
}
/****************************************************************************
** 将wavfile读入内存                                                       **
** 检查wav文件是否标准                                                     **
****************************************************************************/
int LoadVoice (WAVEDATA *Voice,FILE *WAVFile,long i)/*i 表示是load进的第几段音频*/
{
    HEADER Header;
    //farfree(Voice->Sample); /*free 掉上次占用的内存*/
    //Voice->Sample = (char *)farmalloc(Voice->SoundLength+2); /*Assign memory*/
   // if (Voice->Sample==0)

   // {
    //printf("memory assignment failed,press any key to exit");
    //getch();

    //exit(0);
    //}
    if (i == 0)
    {
		/*Load the sample data*/
		fread(&Header, 46, 1, WAVFile);
		/*Check RIFF header*/
		if (Header.RIFF != 0x46464952) /*用于判断是不是PCM编码的wav文件*/
		{
			ReturnMode();
			printf("error in Check RIFF header");
			getch();

			exit(0);
		}
		
		/*Check channels*/
		if (Header.Channels != 1)
		{
			ReturnMode();
			printf("Check channels");
			getch();
			exit(0);
		}
		/*Check bit resolution*/
		if (Header.BitRes != 8)
		{
			ReturnMode();
			printf("Check bit resolution");
			getch();
			exit(0);
		}
		Voice->Frequency = Header.Frequency;
		/*Load the sample data*/
	}
    /*else fseek(WAVFile,i*(44100+2)+43,SEEK_SET);*/
    fread(Voice->Sample, Voice->SoundLength+2, 1, WAVFile);/*安装文献上所说，要在每段声音的长度上再加2byte的内存空间，这里不明白*/
    return (1);
}

/*void playwav (char* Filename, float delaytime,unsigned int Base )
{
    FILE *WAVFile;
    WAVEDATA Voice;
	Coord nlog;
	char mn=0;
    long i=0,count=0,rest=0;
    /*If it can't be opened...
    WAVFile = fopen(Filename, "rb");
    if (WAVFile == NULL)
    {
		/*..display error message
		ReturnMode();
		printf("fail to find file in function playwav ,press any key to exit");
		getch();

		exit(0);
    }
    /*Return length of file for sound length minus 48 bytes for .WAV header
    fseek(WAVFile, 0L, SEEK_END); /*SEEK_SET==0,SEEK_CUR==1,SEEK_END==2

    Voice.SoundLength = ftell (WAVFile) - 44;
    fseek(WAVFile, 0L, SEEK_SET);
    /*Check RIFF header
    if (Voice.SoundLength >LOADSIZE)
    {
		count = Voice.SoundLength / LOADSIZE; /*load进的音频分成的多少个小音频断的整数部分
		 rest = Voice.SoundLength % LOADSIZE;  /*小数部分
		 if (rest != 0)
		 {
			 count=count+1;
		}	
		 Voice.SoundLength = LOADSIZE;
    }
    else
    {
		count = 1;
		rest = Voice.SoundLength;//>LOADSIZE?LOADSIZE: Voice.SoundLength;
	}

    /*Load wave file
    for (i=0; i<count; i++)
    {
		if (i == count -1)
		{
			Voice.SoundLength = rest;/*一个整体一个整体地播放进去，然后当到最后一部分凑不成一个整体时，用rest
		}
		if (LoadVoice(&Voice,WAVFile,i))
		{
			/*Start playback
			PlayBack (&Voice,count,Base);
			if (i != count -1)
			{
				ReadMouse(&(nlog.x),&(nlog.y),&mn);   
				if((mn!=0))
				{
					WriteDSP(0xD0,Base);
					break;
				}	
				DelayTime((float)LOADSIZE/Voice.Frequency*60+delaytime);
				/*Stops DMA-transfer
				//WriteDSP(0xD0,Base);
			}
		}
		WriteDSP(0xD0,Base);
	}
	fclose (WAVFile); //Close the file
}*/

void  ReadMouse( int *mouse_x,int *mouse_y,char *mouse_butt )
{
    union REGS regs;
    int x_new,y_new;
    regs.x.ax=3;
    int86(51,&regs,&regs);
    x_new=regs.x.cx;
    y_new=regs.x.dx;
    *mouse_butt=regs.x.bx&0x07;

	/*-----记录下此时新的坐标---------*/
    *mouse_x=x_new;
    *mouse_y=y_new;
	
	return ;
}
unsigned int DSP_check()
{
    unsigned int Base=0;
     if ((Base=ResetDSP (0x220))!=0)
	{
    return Base;
    }
    else
    {
        if ((Base=ResetDSP (0x240))!=0)
        {
           return Base;
        }
        else
        {
            /*or none at all*/
			ReturnMode();
	    printf("failed to find dsp in funtion DSP_check");
            getch();
            exit(0);
        }
    }
}
/*void  playmus(char * filename,int delaytime)
{
    unsigned int Base=0;/* 声卡地址

	Base=DSP_check();
	playwav(filename,delaytime,Base);
}
*/



