#ifndef _SELF_H_
#define _SELF_H_


int selfcenter(user *u,health *h,int* func);
int selfcenter1(user *u,int *func);
int basicinfo(user* u,int* func);
int healthinfo(user* u,int *func);
int outputbmi(int p,int q,user* u);
float bmi(user* u,int x,int record);
int changename(user* u,int* func);
void getdat(char*nian,char*yue,char*ri);
int healthdata(user *u,health *h,int *func);
int add(user *u,health *h,int *func);
int sta(user* u,health *h);
int output_date(user* u,health* h);
void output_bmi(float i,int x);
int healthadvice(user *u,int *func); 
int judge_bmi(user* u);


#endif
