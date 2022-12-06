#ifndef _keyboard_h
#define _keyboard_h

int putbmp(int x, int y, char *s);//ÌùÍ¼
void inputpassword(char* account, int x1, int y1, int numb, int color);
void inputaccount(char* password, int x1, int y1, int numb, int color);
void inputnewaccount(char* newaccount, int x1, int y1, int numb, int color);
int inputname(int x, int y, int max, int min, char* con);
int inputvisible(int x,int y,int max, int min, char *con,int color);
void guangbiao(int x, int y, int i, int flag);

#endif

