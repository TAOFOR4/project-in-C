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

int putbmp(int x, int y, char *s)//��ͼ
{
    FILE *fp;
    long begin, w, h;
    unsigned char k;
    unsigned char color[256], R, G, B;
    unsigned int i, j, bit;
    if ((fp = fopen(s, "rb")) == NULL)
    {
        printf("not open");
        return 1;
    }
    fseek(fp, 10l, 0);
    fread(&begin, 4, 1, fp);
    fseek(fp, 18l, 0);
    fread(&w, 4, 1, fp);
    fread(&h, 4, 1, fp);
    fseek(fp, 28l, 0);
    fread(&bit, 2, 1, fp);
    if (bit != 8)
    {
        fclose(fp);
        printf("bit:%d,not 8", bit);
        return 2;
    }
    fseek(fp, 54l, 0);
    for (i = 0; i < 256; i++)
    {
        fread(&B, 1, 1, fp);
        fread(&G, 1, 1, fp);
        fread(&R, 1, 1, fp);
        if (R < 42)
        {
            color[i] = (B > 84) + 2 * (G > 84);
        }
        else if (R < 126)
        {
            color[i] = 8 + (B > 168) + 2 * (G > 168);
        }
        else if (R < 210)
        {
            color[i] = 4 + (B > 84) + 2 * (G > 60);
        }
        else
        {
            color[i] = 12 + (B > 168) + 2 * (G > 168);
        }
        fseek(fp, 1, 1);
    }
    for (i = 0; i < h; i++)
    {
        fseek(fp, begin + (w + 3) / 4 * i * 4, 0);
        for (j = 0; j < w; j++)
        {
            fread(&k, 1, 1, fp);
            putpixel(x + j, y + h - i - 1, color[k]);
        }
		newmouse(&MouseX,&MouseY,&press);
		clrmous(MouseX,MouseY);
    }
    fclose(fp);
    return 0;
}	
void inputaccount(char* account, int x1, int y1, int numb, int color)//������ַ����������xy��������ַ����ƣ���������ɫ
{

	int i = strlen(account);
	char word;
	clrmous(MouseX, MouseY);//������
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(BLACK);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);	
	line(x1 + 10 + i * 18, y1 + 4, x1 + 10 + i * 18, y1 + 22);
	while(bioskey(1))//������ѯ�Ƿ��м�����
	{
		word = bioskey(0);//���ذ����ļ�ֵ
	}//���̻�����
	while (1)
	{
		word = bioskey(0); //��ȡ��ֵ
		if (i < numb)
		{
			if (word != 012  //����
				&& word != 015  //�س�
				&& word != ' '    //�ո�
				&& word != 033    //�ڼ��̱�����033��ʾEsc
				)
			{
				
				if (word != '\b')
				{
					*(account + i) = word;
					*(account + i + 1) = '\0';
					setfillstyle(SOLID_FILL, WHITE);
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 21); //�ڸǹ��
					outtextxy(x1 + 8 + i * 18, y1+1, account + i);//���t�ַ�(16)
					i++;
					line(x1 + 10 + i * 18, y1 + 4, x1 + 10 + i * 18, y1 + 21);
				}
				
				else if (word == '\b' && i > 0)//�˸��
				{
					setfillstyle(SOLID_FILL, WHITE);
					bar(x1 + 8 + i * 18, y1 + 3,x1 + 12 + i * 18, y1 + 21);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 21);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 4, x1 + 10 + i * 18, y1 + 21);//���ƹ��
					*(account + i) = '\0';
					*(account + i + 1) = '\0';
				}
			}
			
			else
			{
				setfillstyle(SOLID_FILL, WHITE);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 21);//�ڸǹ��
				break;
			}
		}
		else if (i >= numb)
		{
			if (word != '\n'     //����
				&& word != '\r'   //�س�
				&& word != ' '    //�ո�
				&& word != 033    //�ڼ��̱�����033��ʾEsc
				&& word != 047    //�ڼ��̱�����047��ʾ->
				&& word != 045    //�ڼ��̱�����045��ʾ->
				)
			{
				if (word == '\b' && i > 0)//�˸��
				{
					setfillstyle(SOLID_FILL, WHITE);
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 21);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 21);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 4, x1 + 10 + i * 18, y1 + 21);//���ƹ��
					*(account + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, WHITE);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 21);//�ڸǹ��  
				break;
			}
		}
	}
}

void inputpassword(char * password, int x1, int y1, int numb, int color)//��������
{

	int i = strlen(password);
	char word;
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(BLACK);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10 + i * 18, y1 + 4, x1 + 10 + i * 18, y1 + 21);
	while(bioskey(1))//������ѯ�Ƿ��м�����
	{
		word= bioskey(0);//���ذ����ļ�ֵ
	}//���̻�����
	while (1)
	{
		word = bioskey(0);//��ȡ��ֵ
		if (i < numb)
		{
			if (word != '\n'   //����
				&& word != '\r'   //�س�
				&& word != ' '    //�ո�
				&& word != 033    //�ڼ��̱�����033��ʾEsc
				&& word != 047    //�ڼ��̱�����047��ʾ->
				&& word != 045 )   //�ڼ��̱�����045��ʾ->
			{
				if (word != '\b')
				{
					*(password + i) = word;
					*(password + i + 1) = '\0';
					setfillstyle(SOLID_FILL, WHITE);
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 21);//�ڸǹ��
					outtextxy(x1 + 8 + i * 18, y1+1, "*");//���*�ַ�
					i++;
					line(x1 + 10 + i * 18, y1 + 4, x1 + 10 + i * 18, y1 + 21);
				}
				else if (word == '\b' && i > 0)//�˸��
				{
					setfillstyle(SOLID_FILL, WHITE);
					bar(x1 + 8 + i * 18, y1 +3, x1 + 12 + i * 18, y1 + 21);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 +3, x1 + 7 + i * 18, y1 + 21);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 4, x1 + 10 + i * 18, y1 + 21);//���ƹ��
					*(password + i) = '\0';
					*(password + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, WHITE);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 21);//�ڸǹ��
				break;
			}
		}
		else if (i >= numb)
		{
			if (word != '\n'   //����
				&& word != '\r'   //�س�
				&& word != ' '    //�ո�
				&& word != 033    //�ڼ��̱�����033��ʾEsc
				&& word != 047    //�ڼ��̱�����047��ʾ->
				&& word != 045 )   //�ڼ��̱�����045��ʾ->
			{
				if (word == '\b' && i > 0)//�˸��
				{
					setfillstyle(SOLID_FILL, WHITE);
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 21);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 21);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 4, x1 + 10 + i * 18, y1 + 21);//���ƹ��
					*(password + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, WHITE);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 21);//�ڸǹ��
				break;
			}
		}
	}
}
void inputnewaccount(char* newaccount, int x1, int y1, int numb, int color)//�������˺�
{
	
	int i = strlen(newaccount);
	char word;
	clrmous(MouseX, MouseY);//������
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(BLACK);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	line(x1 + 10 + i * 18, y1 + 4, x1 + 10 + i * 18, y1 + 14);
	while(bioskey(1))//������ѯ�Ƿ��м�����
	{
		word = bioskey(0);//���ذ����ļ�ֵ
	}//���̻�����
	while (1)
	{
	
		word = bioskey(0); //��ȡ��ֵ
		if (i < numb)
		{
			if (word != '\n'   //����
				&& word != '\r'   //�س�
				&& word != ' '    //�ո�
				&& word != 033    //�ڼ��̱�����033��ʾEsc
				&& word != 047    //�ڼ��̱�����047��ʾ->
				&& word != 045    //�ڼ��̱�����045��ʾ->
				)
			{
				if (word != '\b')//�˸�
				{
					*(newaccount + i) = word;
					*(newaccount + i + 1) = '\0';
					setfillstyle(SOLID_FILL, LIGHTGRAY);
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 19); //�ڸǹ��
					outtextxy(x1 + 8 + i * 18, y1-1, newaccount + i);//���t�ַ�(16)
					i++;
					line(x1 + 10 + i * 18, y1 + 4, x1 + 10 + i * 18, y1 + 14);
				}
				
				else if (word == '\b' && i > 0)//�˸��
				{
					setfillstyle(SOLID_FILL, LIGHTGRAY);
					bar(x1 + 8 + i * 18, y1 + 3,x1 + 12 + i * 18, y1 + 19);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 19);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 4, x1 + 10 + i * 18, y1 + 14);//���ƹ��
					*(newaccount + i) = '\0';
					*(newaccount + i + 1) = '\0';
				}
			}
			
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 19);//�ڸǹ��
				break;
			}
		}
		else if (i >= numb)
		{
			if (word != '\n'     //����
				&& word != '\r'   //�س�
				&& word != ' '    //�ո�
				&& word != 033    //�ڼ��̱�����033��ʾEsc
				&& word != 047    //�ڼ��̱�����047��ʾ->
				&& word != 045    //�ڼ��̱�����045��ʾ->
				)
			{
				if (word == '\b' && i > 0)//�˸��
				{
					setfillstyle(SOLID_FILL, LIGHTGRAY);
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 19);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 19);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 4, x1 + 10 + i * 18, y1 + 14);//���ƹ��
					*(newaccount + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 19);//�ڸǹ��  
				break;
			}
		}
	}
}




/*������void inputname(int x,int y,int max, int min, char *con)
���ܣ������ǳ�
û��ʵ������,�д��Ľ������˷���ֵ
*/

int inputname(int x, int y, int max, int min, char* con)//��ȷ����0������ȷ����1 
{
	int i = 0;
	char c;
	char k;
	int flag = 0;
	clrmous(MouseX, MouseY);
	setcolor(DARKGRAY);
	settextjustify(LEFT_TEXT, TOP_TEXT);//ǰ��׼��,�涨���뷽ʽ
	settextstyle(3, 0, 3);
	setfillstyle(1, WHITE);
	bar(x, y, x+200, y+40);
	guangbiao(x, y, i, flag);
	while (bioskey(1))
	{
		k = bioskey(0);
	}
	while (1)
	{
		c = bioskey(0);
		if (c != '\n' && c != '\r')//������س�ʱ
		{
			if (i >= max)
			{
				flag = 1;
				puthz(x+150, y + 9, "����", 24, 20, LIGHTRED);
				guangbiao(x, y, i, flag);
				break;
			}
			if (c != '\b')//�������˸��ʱ
			{
				flag = 2;
				*(con + i) = c;
				*(con + i + 1) = '\0';
				outtextxy(x + 8 + i * 16, y + 8, con + i);//����ֵ
				i++;
				guangbiao(x, y, i, flag);

			}
			else if (c == '\b' && i > 0)//�����˸��(i>0ͦ�ؼ�)
			{
				flag = 3;
				*(con + i) = '\0';
				setfillstyle(1, WHITE);
				bar(x - 8 + i * 16, y + 12, x + 8 + i * 16, y + 40);//�ڸ�����
				i--;
				guangbiao(x, y, i, flag);
			}
		}
		else if (c == '\r' || c == '\n')//����س�ʱ
		{
			flag = 4;
			if (i < min)
			{
				puthz(x+150, y + 9, "����", 24, 20, LIGHTRED);
				guangbiao(x, y, i, flag);
				break;
			}
			else
			{
				guangbiao(x, y, i, flag);
				return 0;                       //��ȷ
			}
		}
	}
	return 1;                                  //����ȷ
}

/****��Ϣ���� ********/
int inputvisible(int x,int y,int max, int min, char *con,int color)//��ȷ����0������ȷ����1 
{
	int i=0;
	char c;
    char k;
	int flag=0;
	clrmous(MouseX, MouseY);
	setcolor(DARKGRAY);
	settextjustify(LEFT_TEXT,TOP_TEXT);//ǰ��׼��,�涨���뷽ʽ
	settextstyle(3,0,3);
	setfillstyle(1, WHITE);
	bar(x, y,x+200, y+40);
	guangbiao(x, y, i, flag);
	while(bioskey(1))
	{
		k=bioskey(0);
	}
	while(1)
	{
		c=bioskey(0);
		if(c!='\n'&&c!='\r')//������س�ʱ
		{
			if(i>=max)
			{
				flag = 1;
				setfillstyle(1, WHITE);
				/*bar(479, y1, 540, y1+ 50);*/
				puthz(x+150, y+9, "����", 24, 20, LIGHTRED);
				guangbiao(x, y, i, flag);
				break;
			}
			if(c!='\b'&&(c>='0'&&c<='9'||c=='X'||c=='x'))//�������˸��ʱ
			{
				flag = 2;
				*(con+i)=c;
				*(con+i+1)='\0';
				outtextxy(x+8+i*16,y+8,con+i);//����ֵ
				i++;
				guangbiao(x, y, i, flag);
			}
			else if(c=='\b'&&i>0)//�����˸��
			{
				flag = 3;
				*(con+i)='\0';
				setfillstyle(1, WHITE);
				bar(x-8+i*16,y+12,x+8+i*16,y+36);//�ڸ�����
				i--;
				guangbiao(x, y, i, flag);
			}
			else if(c<'0'||c>'9')
			{
				continue;
			}
		}
		else if(c=='\r'||c=='\n')//����س�ʱ
		{
			flag = 4;
			if(i<min)
			{
				setfillstyle(1, color);
				/*bar(479, y1, 540, y1+ 50);*/
				puthz(x+150, y+ 9, "����", 24, 20, LIGHTRED);
				guangbiao(x, y, i, flag);
				break;
			}
			else
			{
				setfillstyle(1, WHITE);
				bar(x+140, y, x+200, y+40);
				guangbiao(x, y, i, flag);
				return 0;
			}
		}
	}
	return 1;
}


void guangbiao(int x, int y, int i, int flag)//��� 
{
	switch (flag)
	{
	case 0:
		setcolor(DARKGRAY);
		line(x + 3, y + 8, x + 3, y + 34);
		break;
	case 1:;
	case 4:
		setcolor(WHITE);
		line(x + 3+i*16, y + 8, x + 3+i*16, y + 34);
		break;
	case 2:
		setcolor(WHITE);
		line(x + 3 + (i-1) * 16, y + 8, x + 3 + (i-1) * 16, y + 34);
		setcolor(DARKGRAY);
		line(x + 3 + i * 16, y + 8, x + 3 + i * 16, y + 34);
		break;
	case 3:
		setcolor(WHITE);
		line(x + 3 + (i +1) * 16, y + 8, x + 3 + (i + 1) * 16, y + 36);
		setcolor(DARKGRAY);
		line(x + 3 + i * 16, y + 8, x + 3 + i * 16, y + 34);
		break;                                                                                            //û����ƴ�����//����������˸
	}
}





