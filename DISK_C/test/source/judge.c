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
Function��     input_database

Description��  

Input��   char* account1   �û��˺�
          char* password1  �û�����
		  char* id1		   ���֤����λ

Output�� void   


Others��  �洢���û�������˺ź������Լ����֤����λ
***************************************************/
void input_database(char* account1, char* password1,char* id1)//�洢���û�������˺ź������Լ����֤����λ
{
	FILE* fp;
	USER* u;
	char n;
	int i;
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	setcolor(RED);
	if ((fp = fopen(".//TXT//zhuce.dat", "rb+" )) == NULL)//�򿪶�Ӧ���ļ�
	{
		outtextxy(0,0,"cannot open file zhuce.dat");
		delay(3000);
		getch();
		exit(1);
	}
	if ((u = (USER*)malloc(sizeof(USER))) == NULL)//��̬����
	{
		outtextxy(0,0,"something runs wrong in text.c");
		delay(3000);
		getch();
		exit(1);
	}
    memset(u,'\0',sizeof(USER));//��u��ǰλ�ú�16���ֽڻ�Ϊ'\0'
	strcpy(u->account, account1);
	strcpy(u->password, password1);
	strcpy(u->id,id1);
	fseek(fp, 0, SEEK_END);//��fp��ת���ļ�ĩβ
	fwrite(u, sizeof(USER), 1, fp);//���û���Ϣд���ļ� 
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		puthz(280,300,"�޷��ر��ļ�",24,30,RED);
		delay(3000);
		getch();
		exit(1);
	}
}
/***************************************************
Function��     judge_account

Description��  

Input��   char* account1	�û��˺�
         
Output��   

Return��  1:   ����ע���¼��Ϣ¼�����

Others�� �����û�ע���˺��Ƿ����
***************************************************/
int judge_account(char *account1)//�����û�ע���˺��Ƿ����
{
	int len;
	int i;
	FILE* fp;
	USER* u;
	char *str;
	if ((fp = fopen(".//TXT//zhuce.dat", "rb+")) == NULL)//�򿪶�Ӧ���ļ�
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
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)//��̬����
		{
			outtextxy(0,0,"something runs wrong in text.c");
			delay(3000);
			getch();
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(u->account,account1) == 0)//�û�������
		{
				settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
				setcolor(RED);
				outtextxy(500,110,"account exist");
                delay(2000);
				free(u);
				return 0;
				//�л�����
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	}
	if (i == len)
	{    
	    return 1;//�ߵ����һλ
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
Function��     judge_password

Description��  

Input��   char* account1	�û��˺�
          char* password1	�û�����
		 

Output��   

Return��  1:   ����ע���¼��Ϣ¼�����

Others��  ȷ���û��˺ź������Ƿ�ƥ��
***************************************************/
int judge_password(char* account1, char* password1)	//ȷ���˺ź������Ƿ�ƥ��
{
	int len;
	int i,j;
	FILE* fp;
	USER* u;
	if ((fp = fopen(".//TXT//zhuce.dat", "rb+")) == NULL)//�򿪶�Ӧ���ļ�
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
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)//��̬����
		{
			outtextxy(0,0,"something runs wrong in text.c");
			delay(3000);
			getch();
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(u->account,account1) == 0)//�û���ƥ��
		{
			if (strcmp(password1, u->password) != 0)//���벻��
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
					puthz(254,192,"�������",32,32,LIGHTRED);
					delay(400);
				}
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				break;
			}
			else if (strcmp(password1, u->password) == 0)//����ƥ��
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
					puthz(254,192,"��ӭ����",32,32,LIGHTRED);
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
				//�л�����
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
			puthz(270,192,"δע��",32,32,LIGHTRED);
			delay(500);
		}
		free(u);//�ߵ����һλ
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
Function��     judge_id

Description��  

Input��   char* account1	�û��˺�
         
Output��   

Return��  1:   ����ע���¼��Ϣ¼�����

Others�� �����û�ע�����֤����λ�Ƿ����
***************************************************/
int judge_id(char *id1)//�����û�ע��id�Ƿ����
{
	int len;
	int i;
	FILE* fp;
	USER* u;
	char *str;
	if ((fp = fopen(".//TXT//zhuce.dat", "rb+")) == NULL)//�򿪶�Ӧ���ļ�
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
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)//��̬����
		{
			outtextxy(0,0,"something runs wrong in text.c");
			delay(3000);
			getch();
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(u->id,id1) == 0)//�û�������
		{
				settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
				setcolor(RED);
				outtextxy(500,270,"id exist");
                delay(2000);
				free(u);
				return 0;
				//�л�����
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	}
	if (i == len)
	{    
	    return 1;//�ߵ����һλ
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
Function��     judge_blank1

Description��  

Input��   char* str		ע���¼
          int x			��������
		  int y			��������

Output��   

Return��  1:   ����ע���¼��Ϣ¼�����

Others��  �����û�ע�������Ϣ�Ƿ�����Ϊ��
***************************************************/
int judge_blank1(char* str,int x, int y)//�����û�ע�������Ϣ�Ƿ�����Ϊ��
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
Function��     judge_len

Description��  

Input��   char *account		�û��˺�
         
Output��   

Return��  1:   ����ע���¼��Ϣ¼�����

Others�� �����û�ע���˺ų����Ƿ������С����Ҫ��
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
Function��     judge_len1

Description��  

Input��   char *password	�û�����
         
Output��   

Return��  1:   ����ע���¼��Ϣ¼�����

Others�� �����û�ע�����볤���Ƿ������С����Ҫ��
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
Function��     judge_lenaccount

Description��  

Input��   char *account			�û��˺�
         
Output��   

Return��  1:   ����ע���¼��Ϣ¼�����

Others�� �����û�ע�������˺��Ƿ������󳤶�Ҫ��
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
Function��     judge_lenpassword

Description��  

Input��   char *password	�û�����
         
Output��   

Return��  1:   ����ע���¼��Ϣ¼�����

Others�� �����û�ע�����볤���Ƿ������󳤶�Ҫ��
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
Function��     judge_lenid

Description��  

Input��   char *id		�û����֤����λ
         
Output��   

Return��  1:   ����ע���¼��Ϣ¼�����

Others�� �����û�ע�����֤����λ�����Ƿ������λ����Ҫ��
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
Function��     judge_correct

Description��  

Input��   char *account		�û��˺�
          char *password	�û�����
		  
Output��   

Return��  1:   ����ע���¼��Ϣ¼�����

Others�� �����û�ע��ʱ������ȷ�������Ƿ�һ��
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
Function��     lookforpassword

Description��  

Input��   char* account1	�û��˺�
          char* id1			�û���������
		 

Output��   

Return��  1:   ����ע���¼��Ϣ¼�����

Others��  �����û��һ�����
***************************************************/
int lookforpassword(char* account1,char* id1)//�����û��һ�����
{
	int len;
	int i;
	FILE* fp;
	USER* u;
	char *str;
	if ((fp = fopen(".//TXT//zhuce.dat", "rb+")) == NULL)//�򿪶�Ӧ���ļ�
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
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)//��̬����
		{
			outtextxy(0,0,"something runs wrong in text.c");
			delay(3000);
			getch();
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(account1, u->account) == 0)//�û���ƥ��
		{
			if (strcmp(id1, u->id) != 0)//���֤����λ��ƥ��
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
			else if (strcmp(id1, u->id) == 0)//���֤����λƥ��
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
				//�л�����
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
		outtextxy(300,280,"no register");;//�ߵ����һλ
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


