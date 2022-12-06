#ifndef _sound_h_
#define _sound_h_
/************************************
wav文件信息及用于存储读入的块的信息
***********************************/
#include<stdio.h>
#define LOADSIZE 18016      //每次load的音频文件大小
typedef struct WaveData {
    unsigned long SoundLength;
    unsigned int Frequency;
    char Sample[LOADSIZE];
}WAVEDATA;
typedef struct HeaderType {
    long         RIFF;      /*RIFF header*/
    char         NI1 [18];  /*not important*/
    unsigned int Channels;  /*channels 1 = mono; 2 = stereo*/
    long         Frequency; /*sample frequency*/
    char         NI2 [6];   /*not important*/
    char         BitRes;    /*bit resolution 8/16 bit*/
    char         NI3 [12];  /*not important*/
} HEADER;

void DelayTime(float delaytime);
int ResetDSP(unsigned int Test);
void WriteDSP(unsigned char Value,unsigned int Base);
void PlayBack (WAVEDATA *Wave,long count,unsigned int Base);
int LoadVoice (WAVEDATA *Voice,FILE *WAVFile,long i);
unsigned int DSP_check();
//void  playmus(char * filemame,int delaytime);/*真正播放音乐的总程序,但是总要resetdsp，所以没必要用*/
void ReturnMode();
void ReadMouse(int *mouse_x,int *mouse_y,char *mouse_butt);
#endif

