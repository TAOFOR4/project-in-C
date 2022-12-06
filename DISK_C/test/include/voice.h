#ifndef _VOICE_H_
#define _VOICE_H_

#define LOADSIZE 18016      //每次load的音频文件大小

int voice_main(int* func);
int song_summer(int* func);
int song_you(int* func);
int playwav (char* Filename, float delaytime,unsigned int Base,int *func);//filename 音乐路径 
#endif
