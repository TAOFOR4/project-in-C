#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include"hz.h"
#include"loggin.h" 
#include"drawpage.h"
#include"draw.h"
#include"mouse.h" 
#include"keyboard.h" 
#include"judge.h"
#include"clear.h"
#include"self.h"
#include"shijiao.h"
#include"info.h"

void readinfo(user *u)
{
	FILE *fp=NULL;
	int i;
	char file[50]=".//TXT//userinfo//";
	strcat(file, u->id);
	strcat(file, ".txt");
	fp=fopen(file,"r");
	if(fp==NULL)
	{
		printf("can't open the file!\n");
		delay(1000);
	}
	else
    {
		fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%c\n",u->id,u->password,u->day,u->name,u->height,u->weight,&(u->sex));
	}	
	fclose(fp);
	fp=NULL;
}

/*函数：void input_userinfo(user *u) 
功能：将用户的信息写入文件*/

void input_userinfo(user *u)
{
	FILE *fp=NULL;
	int i;
    char file[50]=".//TXT//userinfo//";
	strcat(file, u->id);
	strcat(file, ".txt");
	if((fp= fopen(file,"wt+"))==NULL)                 
	{
		printf("can't open txt\n");
		delay(5000);
		exit(1);
	}
	fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%c\n", u->id, u->password,u->day,u->name, u->height,u->weight,u->sex);       
	fclose(fp);
	fp=NULL;
}

void input_healthinfo(user* u, health* h)
{
	FILE* fp=NULL;
	int i;
	char file[50] = ".//TXT//health//";
	strcat(file, u->id);
	strcat(file, ".txt");
	if ((fp = fopen(file, "wt+")) == NULL)
	{
		printf("can't open txt\n");
		delay(5000);
		exit(1);
	}
	fprintf(fp, "%s\t%s\t%s\t%s\n",h->year,h->month,h->day, h->weight);
	fclose(fp);
	fp=NULL;
}

void input_healthinfo1(user* u, health* h)
{
	FILE* fp=NULL;
	int i;
	char file[50] = ".//TXT//health//";
	strcat(file, u->id);
	strcat(file, ".txt");
	if ((fp = fopen(file, "at+")) == NULL)
	{
		printf("can't open txt\n");
		delay(5000);
		exit(1);
	}
	fprintf(fp, "%s\t%s\t%s\t%s\n",h->year,h->month,h->day, h->weight);
	fclose(fp);
	fp=NULL;
}

health* read_healthinfo(user* u,health* h_array)
{
	FILE* fp=NULL;
	char file[50] = ".//TXT//health//";
	int i=0;
	long len;	

	memset(h_array, '\0', 20*sizeof(health));
	
	
	strcat(file, u->id);
	strcat(file, ".txt");
	if ((fp = fopen(file, "r")) == NULL)
	{
		printf("can't open txt\n");
		delay(5000);
		exit(1);
	}
	
	fseek(fp,0,SEEK_END);
	len=ftell(fp);
	if(len>5*sizeof(health))
	{
	
		fseek(fp,(len-5*sizeof(health)),SEEK_SET);
		for(i=0;i<5;i++)
		{
			fscanf(fp,"%s\t%s\t%s\t%s\n",h_array[i].year,h_array[i].month,h_array[i].day,h_array[i].weight);
		}
		
	}
	else
	{
		fseek(fp,0,0);
		while(!feof(fp))
		{
			fscanf(fp,"%s\t%s\t%s\t%s\n",h_array[i].year,h_array[i].month,h_array[i].day,h_array[i].weight);
			i++;
		}
	}
	fclose(fp);
	fp=NULL;
	return h_array;
}



