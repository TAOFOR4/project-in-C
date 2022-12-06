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
#include"judge.h"
#include"clear.h"
#include"self.h" 
#include"info.h"

typedef struct
{
	char account[9];
	char password[9];
	char id[9];
}USER;

/***************************************************
Function：     input_database

Description：  

Input：   char* account1   用户账号
          char* password1  用户密码
		  char* id1		   身份证后四位

Output： void   


Others：  存储新用户输入的账号和密码以及身份证后四位
***************************************************/
void input_database(char* account1, char* password1,char* id1)//存储新用户输入的账号和密码以及身份证后四位
{
	FILE* fp;
	USER* u;
	char n;
	int i;
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	setcolor(RED);
	if ((fp = fopen(".//TXT//zhuce.dat", "rb+" )) == NULL)//打开对应的文件
	{
		outtextxy(0,0,"cannot open file zhuce.dat");
		delay(3000);
		getch();
		exit(1);
	}
	if ((u = (USER*)malloc(sizeof(USER))) == NULL)//动态储存
	{
		outtextxy(0,0,"something runs wrong in text.c");
		delay(3000);
		getch();
		exit(1);
	}
    memset(u,'\0',sizeof(USER));//将u当前位置后16个字节换为'\0'
	strcpy(u->account, account1);
	strcpy(u->password, password1);
	strcpy(u->id,id1);
	fseek(fp, 0, SEEK_END);//将fp跳转至文件末尾
	fwrite(u, sizeof(USER), 1, fp);//把用户信息写入文件 
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		puthz(280,300,"无法关闭文件",24,30,RED);
		delay(3000);
		getch();
		exit(1);
	}
}
/***************************************************
Function：     judge_account

Description：  

Input：   char* account1	用户账号
         
Output：   

Return：  1:   返回注册登录信息录入界面

Others： 检验用户注册账号是否存在
***************************************************/
int judge_account(char *account1)//检验用户注册账号是否存在
{
	int len;
	int i;
	FILE* fp;
	USER* u;
	char *str;
	if ((fp = fopen(".//TXT//zhuce.dat", "rb+")) == NULL)//打开对应的文件
	{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	    setcolor(RED);
		outtextxy(0,0,"cannot open file zhuce.dat");
		delay(3000);
		getch();
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER);
	for (i = 0; i < len; i++)
	{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	    setcolor(RED);
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)//动态储存
		{
			outtextxy(0,0,"something runs wrong in text.c");
			delay(3000);
			getch();
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(u->account,account1) == 0)//用户名存在
		{
				settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
				setcolor(RED);
				outtextxy(500,110,"account exist");
                delay(2000);
				free(u);
				return 0;
				//切换界面
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	}
	if (i == len)
	{    
	    return 1;//走到最后一位
	}

	if (u != NULL)
	{
		free(u);
		u = NULL;
	}

	if (fclose(fp) != 0)
	{
		outtextxy(0,0,"\n cannot close zhuce");
		delay(3000);
		getch();
		exit(1);
	}
	return 0;
}

/***************************************************
Function：     judge_password

Description：  

Input：   char* account1	用户账号
          char* password1	用户密码
		 

Output：   

Return：  1:   返回注册登录信息录入界面

Others：  确认用户账号和密码是否匹配
***************************************************/
int judge_password(char* account1, char* password1)	//确认账号和密码是否匹配
{
	int len;
	int i,j;
	FILE* fp;
	USER* u;
	if ((fp = fopen(".//TXT//zhuce.dat", "rb+")) == NULL)//打开对应的文件
	{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	    setcolor(RED);
		outtextxy(0,0,"cannot open file zhuce.dat");
		delay(3000);
		getch();
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER);
	for (i = 0; i < len; i++)
	{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	    setcolor(RED);
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)//动态储存
		{
			outtextxy(0,0,"something runs wrong in text.c");
			delay(3000);
			getch();
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(u->account,account1) == 0)//用户名匹配
		{
			if (strcmp(password1, u->password) != 0)//密码不配
			{
				for(j=0;j<3;j++)
				{
					setfillstyle(1,WHITE);
					bar(155,125,495,295);
					delay(700);
					bar(155,125,495,295);
					setcolor(GREEN);
					settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
					//outtextxy(210,190,"wrong password");
					puthz(254,192,"密码错误",32,32,LIGHTRED);
					delay(400);
				}
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				break;
			}
			else if (strcmp(password1, u->password) == 0)//密码匹配
			{
				for(j=0;j<3;j++)
				{
					setfillstyle(1,WHITE);
					bar(155,125,495,295);
					delay(700);
					bar(155,125,495,295);
					setcolor(GREEN);
					settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
					//outtextxy(210,190,"right password");
					puthz(254,192,"欢迎回来",32,32,LIGHTRED);
					delay(500);
				}
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				delay(500);
				if (fclose(fp) != 0)
				{
					printf("\n cannot close zhuce");
					delay(3000);
					getch();
					exit(1);
				}
				free(u);
				return 1;
				//切换界面
			}
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	}
	if (i == len)
	{
		for(j=0;j<3;j++)
		{
			setfillstyle(1,WHITE);
			bar(155,125,495,295);
			delay(700);
			bar(155,125,495,295);
			setcolor(GREEN);
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
			//outtextxy(210,190,"no register");
			puthz(270,192,"未注册",32,32,LIGHTRED);
			delay(500);
		}
		free(u);//走到最后一位
	}

	if (u != NULL)
	{
		free(u);
		u = NULL;
	}

	if (fclose(fp) != 0)
	{
		outtextxy(0,0," cannot close zhuce");
		delay(3000);
		getch();
		exit(1);
	}
	return 0;
}
/***************************************************
Function：     judge_id

Description：  

Input：   char* account1	用户账号
         
Output：   

Return：  1:   返回注册登录信息录入界面

Others： 检验用户注册身份证后四位是否存在
***************************************************/
int judge_id(char *id1)//检验用户注册id是否存在
{
	int len;
	int i;
	FILE* fp;
	USER* u;
	char *str;
	if ((fp = fopen(".//TXT//zhuce.dat", "rb+")) == NULL)//打开对应的文件
	{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	    setcolor(RED);
		outtextxy(0,0,"cannot open file zhuce.dat");
		delay(3000);
		getch();
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER);
	for (i = 0; i < len; i++)
	{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	    setcolor(RED);
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)//动态储存
		{
			outtextxy(0,0,"something runs wrong in text.c");
			delay(3000);
			getch();
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(u->id,id1) == 0)//用户名存在
		{
				settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
				setcolor(RED);
				outtextxy(500,270,"id exist");
                delay(2000);
				free(u);
				return 0;
				//切换界面
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	}
	if (i == len)
	{    
	    return 1;//走到最后一位
	}

	if (u != NULL)
	{
		free(u);
		u = NULL;
	}

	if (fclose(fp) != 0)
	{
		outtextxy(0,0,"\n cannot close zhuce");
		delay(3000);
		getch();
		exit(1);
	}
	return 0;
}

/***************************************************
Function：     judge_blank1

Description：  

Input：   char* str		注册登录
          int x			横轴坐标
		  int y			纵轴坐标

Output：   

Return：  1:   返回注册登录信息录入界面

Others：  检验用户注册界面信息是否输入为空
***************************************************/
int judge_blank1(char* str,int x, int y)//检验用户注册界面信息是否输入为空
{
	if (strlen(str) == 0)
	{
		setcolor(RED);
	    settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
	    outtextxy(x,y,"NO EMPTY INFORMATION");
		delay(1000);
		return 1;
	}
}
/***************************************************
Function：     judge_len

Description：  

Input：   char *account		用户账号
         
Output：   

Return：  1:   返回注册登录信息录入界面

Others： 检验用户注册账号长度是否符合最小长度要求
***************************************************/
int judge_len(char *account)
{
	if(strlen(account)<3&&strlen(account)>0)
	{
		
	    settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	    setcolor(RED);
	    outtextxy(150,360,"please limit account no less than 3");
	    delay(3000);
        return 1;
	}
}

/***************************************************
Function：     judge_len1

Description：  

Input：   char *password	用户密码
         
Output：   

Return：  1:   返回注册登录信息录入界面

Others： 检验用户注册密码长度是否符合最小长度要求
***************************************************/
int judge_len1(char *password)
{
	if(strlen(password)<3&&strlen(password)>0)
	{
		
	    settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	    setcolor(RED);
	    outtextxy(150,360,"please limit password no less than 3");
	    delay(3000);
        return 1;
	}
}

/***************************************************
Function：     judge_lenaccount

Description：  

Input：   char *account			用户账号
         
Output：   

Return：  1:   返回注册登录信息录入界面

Others： 检验用户注册密码账号是否符合最大长度要求
***************************************************/
int judge_lenaccount(char *account)
{
	if(strlen(account)>=8)
	{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
		setcolor(RED);
		outtextxy(150,360,"please limit account no more than 7");
		delay(3000);
		return 1;
	}
}

/***************************************************
Function：     judge_lenpassword

Description：  

Input：   char *password	用户密码
         
Output：   

Return：  1:   返回注册登录信息录入界面

Others： 检验用户注册密码长度是否符合最大长度要求
***************************************************/
int judge_lenpassword(char *password)
{
	if(strlen(password)>=8)
	{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
		setcolor(RED);
		outtextxy(150,360,"please limit password no more than 7");
		delay(3000);
		return 1;
	}
}

/***************************************************
Function：     judge_lenid

Description：  

Input：   char *id		用户身份证后四位
         
Output：   

Return：  1:   返回注册登录信息录入界面

Others： 检验用户注册身份证后四位长度是否符合四位长度要求
***************************************************/
int judge_lenid(char *id)
{
	if(strlen(id)!=8)
	{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
		setcolor(RED);
		outtextxy(120,360,"please limit birthday with 8 numbers");
		delay(3000);
		return 1;
	}
}

/***************************************************
Function：     judge_correct

Description：  

Input：   char *account		用户账号
          char *password	用户密码
		  
Output：   

Return：  1:   返回注册登录信息录入界面

Others： 检验用户注册时密码与确认密码是否一致
***************************************************/
int judge_correct(char *account,char *password)
{
	if(strcmp(account,password)!=0)
	{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	    setcolor(RED);
	    outtextxy(220,360,"please confirm your password");
		delay(3000);
		return 1;
	}
}
/***************************************************
Function：     lookforpassword

Description：  

Input：   char* account1	用户账号
          char* id1			用户健康密码
		 

Output：   

Return：  1:   返回注册登录信息录入界面

Others：  帮助用户找回密码
***************************************************/
int lookforpassword(char* account1,char* id1)//帮助用户找回密码
{
	int len;
	int i;
	FILE* fp;
	USER* u;
	char *str;
	if ((fp = fopen(".//TXT//zhuce.dat", "rb+")) == NULL)//打开对应的文件
	{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	    setcolor(RED);
		outtextxy(0,0,"cannot open file zhuce.dat");
		delay(3000);
		getch();
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER);
	for (i = 0; i < len; i++)
	{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	    setcolor(RED);
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)//动态储存
		{
			outtextxy(0,0,"something runs wrong in text.c");
			delay(3000);
			getch();
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(account1, u->account) == 0)//用户名匹配
		{
			if (strcmp(id1, u->id) != 0)//身份证后四位不匹配
			{
				outtextxy(300,300,"wrong id");
				if (u != NULL)
				{
					delay(3000);
				
				    cleardevice( );
				   return 0;
				    break;
					free(u);
					u = NULL;
			
				}
		
				
			}
			else if (strcmp(id1, u->id) == 0)//身份证后四位匹配
			{
				outtextxy(300,300,"right id");
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				//delay(1000);
				fseek(fp,i * sizeof(USER)+9, SEEK_SET);
				fread(str,9, 1, fp);
				settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
				setcolor(RED);
				
				outtextxy(250,265,str);
				if(fclose(fp)!=0)
				{
					settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
					setcolor(RED);
					outtextxy(0,0,"cannot close file zhuce.dat");
					getch();
					exit(0);
				}
				free(u);
				return 1;
				//切换界面
			}
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	}
	if (i == len)
	{
		outtextxy(300,280,"no register");;//走到最后一位
	    delay(3000);
	}

	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		outtextxy(0,0,"\n cannot close zhuce");
		delay(3000);
		getch();
		exit(1);
	}
	return 0;
}


