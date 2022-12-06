#include "bmp.h"
#include "mouse.h"		//ֻ�ǵ������е�Getpixel64k()�������
#include "hz.h"
#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include<math.h>
/**************************************
   SVGA�Ĺ��ܺ�ax˵��
   0x4f00  ��SVGA����Ϣ
   0x4f01  ����ʾģʽ��Ϣ
   0x4f02  ������ʾģʽ
   0x4f03  ����ǰ��ʾģʽ
   0x4f04  �洢��ָ�SVGA����Ƶ״̬
   0x4f05  �����ڴ�ҳ�����л�
   0x4f06  ���û��ȡ�߼�ɨ���߿���
   0x4f07  ���û��ȡ��Ƶ�ڴ�����Ļ�ĳ�ʼ��Ӧλ��
   0x4f08  ���û��ȡDAC��ԭɫ��Чλ��
   SVGA��ʾģʽ��bx��
		ģʽ��		�ֱ���		��ɫ��		��ɫλ����
		0x101		640*480		256				-
		0x103		800*600		256				-
		0x104		1024*768	16				-
		0x105		1024*768	256				-
		0x110		640*480		32K			1:5:5:5
		0x111		640*480		64K			5:6:5
		0x112		640*480		16.8M		8:8:8
		0x113		800*600		32K			1:5:5:5
		0x114		800*600		64K			5:6:5
		0x115		800*600		16.8M		8:8:8
		0x116		1024*768	32K			1:5:5:5
		0x117		1024*768	64K			5:6:5
		0x118		1024*768	16.8M		8:8:8
**************************************************/

void SetSVGA256()
{
	union REGS regs;
	regs.x.ax=0x4f02;                //����SVGA����
	regs.x.bx=0x105;                  //����SVGA��ʾģʽ
	int86(0x10,&regs,&regs);          //BIOS int 10h���ܵ���
	if (regs.x.ax != 0x004f)        //�ж��Ƿ�֧�ָù���
	{
		printf("Error in setting SVGA mode!\nError code:0x%x\n", regs.x.ax);
		delay(5000);
		exit(1);
	}
}

void SetSVGA64k()
{
	union REGS regs;
	regs.x.ax = 0x4f02;                //����SVGA����
	regs.x.bx = 0x117;                  //����SVGA��ʾģʽ
	int86(0x10, &regs, &regs);           //BIOS int 10h���ܵ���
	if (regs.x.ax != 0x004f)              //�ж��Ƿ�֧�ָù��� 
	{
		printf("Error in setting SVGA mode!\nError code:0x%x\n",regs.x.ax);
		delay(5000);
		exit(1);
	}
}

void Selectpage(register char page)
{
	union REGS regs;
	static unsigned char old_page = 0;     //��һ�ε�ҳ���,���ڼ����л����� 
	static int flag = 0;                   //��־���������ж��Ƿ��ǵ�һ�λ�ҳ
	regs.x.ax = 0x4f05;                   //���ô���ҳ����ƹ��ܺ�
	regs.x.bx = 0;
	if (flag == 0)                      //����ǵ�һ�λ�ҳ
	{
		old_page = page;
		regs.x.dx = page;
		int86(0x10, &regs, &regs);
		flag++;
	}
	else if (page != old_page)    //������ϴ�ҳ��Ų�ͬ������л�ҳ
	{
		old_page = page;
		regs.x.dx = page;
		int86(0x10, &regs, &regs);
	}
}

void Readbmp64k(int x, int y, char * path)
{
	FILE * fpbmp;                      //ָ��ͼƬ�ļ����ļ�ָ��
	COLORS24 * buffer;                    //�����ػ���ָ��
	long int width, height, linebytes;   //ͼƬ�Ŀ��ȡ��߶ȡ�һ��������ռ�ֽ��� 
	int i, j;                        //ѭ������
	unsigned int bit;                 //ͼƬλ��
	unsigned long int compression;     //ѹ������
	if ((fpbmp = fopen(path, "rb")) == NULL)   //���ļ�
	{
		printf("can not open 24bmpfile");
		delay(5000);
		exit(1);
	}
	/*��ȡλ��*/
	fseek(fpbmp, 28L, 0);
	fread(&bit, 2, 1, fpbmp);
	if (bit != 24U)  
	{
		printf("not 24bit");
		delay(5000);
		exit(1);
	}
	/*��ȡѹ������*/
	fseek(fpbmp, 30L, 0);
	fread(&compression, 4, 1, fpbmp);
	if (compression != 0UL)
	{
		printf("can not display a compressed bmp file");
		delay(5000);
		exit(1);
	}
	/*��ȡ���ȡ��߶�*/
	fseek(fpbmp, 18L, 0);
	fread(&width, 4, 1, fpbmp);
	fread(&height, 4, 1, fpbmp);
	/*���Ȼ�߶ȳ������˳�*/
	if (width > SCR_WIDTH||height>SCR_HEIGHT)
	{
		printf("24bmp too big");
		delay(5000);
		exit(1);
	}
	/*����һ������ռ�ֽ�������������Ŀ��ֽ�*/
	linebytes = (3 * width) % 4;   //24λbmpһ�����������ֽ�
	if(!linebytes)
	{
		linebytes = 3 * width;
	}
	else
	{
		linebytes = 3 * width + 4 - linebytes;
	}
	/*�������������ݶ�̬����ռ�*/
	if ((buffer = (COLORS24 *)malloc(linebytes)) == 0)
	{
		printf("not memery");
	}
	/*��ɨ����ʽ��ȡͼƬ���ݲ���ʾ*/
	fseek(fpbmp, 54L, 0);
	for (i = height - 1; i > -1; i--)
	{
		fread(buffer, linebytes, 1, fpbmp);	/*��ȡһ����������*/
		/*һ�����ص����ݴ����ͻ���*/
		for (j = 0; j < width; j++)
		{
			/*0x117ģʽ�£�ԭͼ��������8λ�ֱ����Ϊ5λ��6λ��5λ*/
			buffer[j].R >>= 3;
			buffer[j].G >>= 2;
			buffer[j].B >>= 3;
			Putpixel64k(j + x, i + y,
			((((unsigned int)buffer[j].R) << 11)
			| (((unsigned int)buffer[j].G) << 5)
			| ((unsigned int)buffer[j].B)));	/*����������ɫ���������Ӹ�λ����λ����*/
		}
	}
	free(buffer);	
	fclose(fpbmp);
}

void Xorpixel64k(int x, int y, unsigned int color)
{
	/*�Դ�ָ�볣����ָ���Դ��׵�ַ��ָ�뱾���������޸�*/
	unsigned int far * const video_buffer = (unsigned int far *)0xa0000000L;
	unsigned char page;  //Ҫ�л���ҳ���
	unsigned long int page_dev;  //��Ӧ�Դ��ַƫ����
	/*�жϵ��Ƿ�����Ļ��Χ�ڣ����ھ��˳�*/
	if(x < 0 || x > (SCR_WIDTH - 1) || y < 0 || y > (SCR_HEIGHT - 1))
	{
		printf("out of range");
	}
	/*�����Դ��ַƫ�����Ͷ�Ӧ��ҳ��ţ�����ҳ����*/
	page_dev = ((unsigned long int)y << 10) + x;    //��<<10�������1024
	page = page_dev >> 15;	//64k����һ��ҳ������64k������㷨
	Selectpage(page);
	/*���Դ�д����ɫ����Ӧ����򻭳�*/
	video_buffer[page_dev]^= color;	
}

void Putpixel64k(int x, int y, unsigned int color)
{
	/*�Դ�ָ�볣����ָ���Դ��׵�ַ��ָ�뱾���������޸�*/
	unsigned int far * const video_buffer = (unsigned int far *)0xa0000000L;
	unsigned char page;    //Ҫ�л���ҳ���
	unsigned long int page_dev;   //��Ӧ�Դ��ַƫ����
	/*�жϵ��Ƿ�����Ļ��Χ�ڣ����ھ��˳�*/
	if(x < 0 || x > (SCR_WIDTH - 1) || y < 0 || y > (SCR_HEIGHT - 1))
	{
		 printf("out of range");		
		 delay(5000);
		 exit(1); //��Щʱ�����ᳬ������û�н�������Ȱ����ע����
	}
	/*�����Դ��ַƫ�����Ͷ�Ӧ��ҳ��ţ�����ҳ����*/
	page_dev = ((unsigned long int)y << 10) + x;
	page = page_dev >> 15;	/*32k����һ��ҳ������32k������㷨*/
	Selectpage(page);
	/*���Դ�д����ɫ����Ӧ�㻭��*/
	video_buffer[page_dev] = color;
} 

void rectangle_svga(int x0,int y0,int x1,int y1)
{
	int i,j;           //ѭ������
	for(i=y0;i<=y1;i++)
		for(j=x0;j<=x1;j++)           //�����ص�Ϊ2�ľ��ο�
		{
			if((i>=y0&&i<=y0+1)||(i>=y1-1&&i<=y1))
			{
				Putpixel64k(j,i,500);
			}
			else
			{
				Putpixel64k(x0,i,500);
				Putpixel64k(x0+1,i,500);
				Putpixel64k(x1-1,i,500);
				Putpixel64k(x1,i,500);
			}
		}
}


void CloseSVGA()        
{
    union REGS regs;
    regs.h.ah=0;
    regs.h.al=0x03;
    int86(0x10,&regs,&regs);     
}

void Readpartbmp64k(int x,int y,int x1,int y1,int x2,int y2,char *path)
{
	FILE * fpbmp;                      //ָ��ͼƬ�ļ����ļ�ָ��
	COLORS24 * buffer;                    //�����ػ���ָ��
	long int width, height, linebytes;   //ͼƬ�Ŀ��ȡ��߶ȡ�һ��������ռ�ֽ��� 
	int i, j;                        //ѭ������
	unsigned int bit;                 //ͼƬλ��
	unsigned long int compression;     //ѹ������
	if ((fpbmp = fopen(path, "rb")) == NULL)   //���ļ�
	{
		printf("can not open 24bmpfile");
		delay(5000);
		exit(1);
	}
	/*��ȡλ��*/
	fseek(fpbmp, 28L, 0);
	fread(&bit, 2, 1, fpbmp);
	if (bit != 24U)  
	{
		printf("not 24bit");
		delay(5000);
		exit(1);
	}
	/*��ȡѹ������*/
	fseek(fpbmp, 30L, 0);
	fread(&compression, 4, 1, fpbmp);
	if (compression != 0UL)
	{
		printf("can not display a compressed bmp file");
		delay(5000);
		exit(1);
	}
	/*��ȡ���ȡ��߶�*/
	fseek(fpbmp, 18L, 0);
	fread(&width, 4, 1, fpbmp);
	fread(&height, 4, 1, fpbmp);
	/*���Ȼ�߶ȳ������˳�*/
	if (width > SCR_WIDTH||height>SCR_HEIGHT)
	{
		printf("24bmp too big");
		delay(5000);
		exit(1);
	}
	/*����һ������ռ�ֽ�������������Ŀ��ֽ�*/
	linebytes = (3 * width) % 4;   //24λbmpһ�����������ֽ�
	if(!linebytes)
	{
		linebytes = 3 * width;
	}
	else
	{
		linebytes = 3 * width + 4 - linebytes;
	}
	/*�������������ݶ�̬����ռ�*/
	if ((buffer = (COLORS24 *)malloc(linebytes)) == 0)
	{
		printf("not memery");
	}
	/*��ɨ����ʽ��ȡͼƬ���ݲ���ʾ*/
	fseek(fpbmp, 54L+linebytes*(height-1-y1), 0);
	for (i =y1-y2; i > -1; i--)
	{
		fread(buffer, linebytes, 1, fpbmp);	/*��ȡһ����������*/
		/*һ�����ص����ݴ����ͻ���*/
		for (j = 0; j < x2-x1; j++)
		{
			if((x1+j)>=x1&&(x1+j)<=x2)
			{
				/*0x117ģʽ�£�ԭͼ��������8λ�ֱ����Ϊ5λ��6λ��5λ*/
				buffer[j].R >>= 3;
				buffer[j].G >>= 2;
				buffer[j].B >>= 3;
				Putpixel64k(  j + x, i + y,
				((((unsigned int)buffer[j].R) << 11)
				| (((unsigned int)buffer[j].G) << 5)
				| ((unsigned int)buffer[j].B)));	/*����������ɫ���������Ӹ�λ����λ����*/
			}
		}
	}
	free(buffer);	
	fclose(fpbmp);
}

/***���ñ�����ɫ***/
void setbkcolor64k(int color)
{
	int i,j;
	for(i=0;i<SCR_WIDTH;i++)
	{
		for(j=0;j<SCR_HEIGHT;j++)
		{
			Putpixel64k(i,j,color);
		}
	}
}

/***24λ��ʾģʽ�»���***/			
void Linel(int x1, int y1, int x2, int y2, unsigned int color)
{
	int i;
	if(x1==x2)                   //��ֱֱ��
	{
		if(y1<=y2)
		{
			for(i=y1;i<=y2;i++)
			Putpixel64k(x1,i,color);
		}
		else
		{
			for(i=y2;i<=y1;i++)
			Putpixel64k(x1,i,color);
		 }
	}
	
	else  if(y1==y2)                   //ˮƽֱ��
	{
		if(x1<=x2)
		{
			for(i=x1;i<=x2;i++)
			Putpixel64k(i,y1,color);
		}
		else
		{
			for(i=x2;i<=x1;i++)
			Putpixel64k(i,y1,color);
		}
	}
}

/***24λ��ʾģʽ�»�����***/
void Barl(int x1, int y1, int x2, int y2, unsigned int color)
{
	int j;
	//getch();
	for(j=y1;j<=y2;j++)
	{
		Linel(x1,j,x2,j,color);
	}
}

/***��45��б��***/
void Linelean(int x1, int y1, int x2, int y2, unsigned int color)
{
	int i,j;
	if((x1<x2)&&(y1>y2))
	{
		j=y1-1;
		for(i=x1-1;i<x2;i++)
		{
			Putpixel64k(i,j,color);
			j=j-1;
		}
	}
	else if((x1<x2)&&(y1<y2))
	{
		j=y1-1;
		for(i=x1-1;i<x2;i++)
		{
			Putpixel64k(i,j,color);
			j=j+1;
		}
	}
	else if((x1>x2)&&(y1>y2))
	{
		j=y2-1;
		for(i=x2-1;i<x1;i++)
		{
			Putpixel64k(i,j,color);
			j=j+1;
		}
	}
	else if((x1>x2)&&(y1<y2))
	{
		j=y2-1;
		for(i=x2-1;i<x1;i++)
		{
			Putpixel64k(i,j,color);
			j=j-1;
		}
	}
}

/***��б��***/
void line64k(int x1, int y1, int x2, int y2, unsigned int color)
{
    	int dx=0,dy=0;
	int x_inc=1,y_inc=1;
	int x=0,y=0;
    	int index=0,error=1;

    	x=x1;
   	 y=y1;
   	 dx=x2-x1;
    	dy=y2-y1;

		/*�ж������������Ϣ*/
   	 if(dx<0)
    	{
        	dx=-dx;
        	x_inc=-1;
  	  }
	
   	 if(dy<0)
  	  {
        	dy=-dy;
        	y_inc=-1;
  	  }

		/*���ߺ����㷨*/
    	if(dx>dy)
    	{
        	for(index=0;index<=dx;index++)
        	{
	      	 	 Putpixel64k(x,y,color);
         	 	 error+=dy;
         	 	  x+=x_inc;
          		  Putpixel64k(x,y,color);
			
            		if(error>dx)
           		 {
               			 error-=dx;
                		y+=y_inc;
              			 Putpixel64k(x,y,color);
          		  }
			
       		 }
   	 }
    else
    {
        for(index=0;index<=dy;index++)
        {
            Putpixel64k(x,y,color);
            error+=dx;
            y+=y_inc;
            Putpixel64k(x,y,color);
			
            if(error>dy)
            {
                error-=dy;
                x+=x_inc;
                Putpixel64k(x,y,color);
            }
        }
     }

}

/***��ȡ��ɫ��ֵ����Ӧ����ɫ***/
unsigned int ReadColor(unsigned int x ,unsigned int y ,unsigned int z )
{
	
	x>>=3;		//x,y,z�ֱ��ӦR,G,B
	y>>=2;
	z>>=3;
	return (((unsigned int)x<<11)|((unsigned int)y<<5)|(unsigned int)z); 		//����ֵΪ����ɫ��Ӧ��2�ֽڵ�ֵ
}

/***����ͼ��***/
void Saveimagetofile(int x1, int y1, int x2, int y2, const char * path)
{
	int wid, len, i = 0, j = 0, size = 0;		//��������ÿһ���ֽڵĸ���
	FILE * save;
	unsigned int color, *buffer;
	unsigned int far * const head = (unsigned int far *)0xa0000000L;
	save = fopen(path, "wb+");
	if (save == NULL)
	{
		puthz(200,200,"�޷��ҵ�����ͼ���ڴ���ļ�", 16, 20, WHITE);
		delay(3000);
		exit(1);
	}

	len = y2 - y1;
	wid = x2 - x1;
	size = (wid + 1) * 2;
	if ((buffer = (unsigned int*)malloc(size)) == 0)
	{
		puthz(200,200,"û���㹻�ռ�����ڴ洢������", 16, 20, WHITE);

		delay(3000);
		exit(1);
	}
	for (i = 0; i <= len; i++)
	{
		Selectpage((i + y1) / 32);
		_fmemcpy(buffer, head + (y1 + i) * 1024 + x1, size);
		fwrite(buffer, size, 1, save);
	}
	free(buffer);
	fclose(save);
}




/***����ͼ��***/
void Loadimagefromfile(int x1, int y1, int x2, int y2, const char * path)
{
	int wid, len, i = 0, j = 0, size = 0;
	FILE * fpbmp;
	unsigned int color, *buffer;
	unsigned int far * const head = (unsigned int far *)0xa0000000L;
	fpbmp = fopen(path, "rb");
	if (fpbmp == NULL)
	{
		puthz(200,200,"�޷��ҵ�����ͼ���ڴ���ļ�", 16, 20, WHITE);
		delay(3000);
		exit(1);
	}
	len = y2 - y1;
	wid = x2 - x1;
	size = (wid + 1) * 2;
	if ((buffer = (unsigned int*)malloc(size)) == 0)
	{
		puthz(200,200,"û���㹻�ռ�����ڴ洢������", 16, 20, WHITE);
		delay(3000);
		exit(1);
	}
	for (i = 0; i <= len; i++)
	{
		Selectpage((i + y1 ) / 32);
		fread(buffer, size, 1, fpbmp);
		_fmemcpy(head + (y1 + i) * 1024 + x1, buffer, size);
	}
	free(buffer);
	fclose(fpbmp);
}

/***���ٶ�ȡ����Ƭ��1024*768��С��ͼƬ***/
void Readbmplarge (int x, int y, char * path)
{
	FILE * fpbmp;                      //ָ��ͼƬ�ļ����ļ�ָ��
	unsigned int  * buffer;                    //�����ػ���ָ��
	int page;		//�����Դ��ҳ��
	long int width, height,width_1, height_1, linebytes;   //ͼƬ�Ŀ��ȡ��߶ȡ�һ��������ռ�ֽ��� 
	int i, j;                        //ѭ������
	unsigned int bit;                 //ͼƬλ��
	unsigned long int compression;     //ѹ������
	unsigned int far *const head=(unsigned int far *)0xa0000000L;		//�Դ��׵�ַ
	long int bfoffbits;		
	if ((fpbmp = fopen(path, "rb")) == NULL)   //���ļ�
	{
		printf("can not open 24bmpfile");
		delay(5000);
		exit(1);
	}
	/*��ȡ���ȡ��߶�*/
	fseek(fpbmp, 18L, 0);
	fread(&width, 4, 1, fpbmp);
	fread(&height, 4, 1, fpbmp);
	/*���ÿ��ȡ��߶�*/
	width_1=1024;
	height_1=768;
	/*����һ������ռ�ֽ�������������Ŀ��ֽ�*/
	linebytes = 2 * width;   //16λbmpһ������2���ֽ�
	/*�������������ݶ�̬����ռ�*/
	if ((buffer = (unsigned int  *)malloc(1024*2)) == 0)
	{
		printf("not memery");
	}
	/*��ɨ����ʽ��ȡͼƬ���ݲ���ʾ*/
	fseek(fpbmp,0x0a,SEEK_SET);
	fread(&bfoffbits,sizeof(long),1,fpbmp);
	fseek(fpbmp,bfoffbits,SEEK_SET);
	/*fseek(fpbmp, 54L, 0);*/
	for (i = height_1-1; i > -1; i--)
	{
		page=i/32;
		Selectpage(page);
		fseek(fpbmp,bfoffbits+(height-1-y-i)*linebytes+2*x,0);
		fread(buffer, 1024, 2, fpbmp);	/*��ȡһ����������*/
		_fmemcpy(head+i*1024,buffer,1024*2);	
	}
	free(buffer);	
	fclose(fpbmp);
}

/***������ͼ***/
/*
int bmp_fast( char * path)
{
	long int bfoffbits;
	unsigned int far *const head=(unsigned int far *)0xa0000000L;
	unsigned int* buffer;
	int i,j,k;
	unsigned int width,height;
	FILE * fpbmp;
	fpbmp=fopen(path, "rb");
	if(fpbmp==NULL)
	{
		return 1;
	}
	if ((buffer = (unsigned int*)malloc(1024*2)) == 0)
	{
		return 1;
	}
	fseek(fpbmp, 18L, 0);
	fread(&width, 4, 1, fpbmp);
	fread(&height, 4, 1, fpbmp);
	fseek(fpbmp,0x0a,SEEK_SET);
	fread(&bfoffbits,sizeof(long),1,fpbmp);
	fseek(fpbmp,bfoffbits,SEEK_SET);
	for (i =24; i>0; i--)
	{
		Selectpage(i-1);
		for (j = 32; j>0; j--)
		{
			fread(buffer,1024,2, fpbmp);	
			_fmemcpy(head+((i-1)*32+j-1)*1024,buffer,1024*2);                  //1024*2��ʾһ�������ڴ�,buffer���� 
		}
	}
	free(buffer);
	fclose(fpbmp);
	return 0;
}
*/

int bmp_fast(int y1,int y2,char* path)
{
	long int bfoffbits;
	unsigned int far* head = (unsigned int far*)0xa0000000L;
	unsigned int* buffer;
	int i, j, k;
	int top, end;
	unsigned int width, height;
	FILE* fpbmp;
	fpbmp = fopen(path, "rb");
	if (fpbmp == NULL)
	{
		return 1;
	}
	if ((buffer = (unsigned int*)malloc(1024 * 2)) == 0)
	{
		return 1;
	}
	fseek(fpbmp, 18L, 0);
	fread(&width, 4, 1, fpbmp);
	fread(&height, 4, 1, fpbmp);
	fseek(fpbmp, 0x0a, SEEK_SET);
	fread(&bfoffbits, sizeof(long), 1, fpbmp);
	fseek(fpbmp, bfoffbits, SEEK_SET);
	top = y1 / 32 + (y1 % 32)/16;
	end = y2 / 32 + (y2 % 32) / 16;
	for (i = 24; i > 0; i--)
	{
		Selectpage(i - 1);
		for (j = 32; j > 0; j--)
		{
			fread(buffer, 1024, 2, fpbmp);
			if (i < end && i>top)
			{
				_fmemcpy(head + ((i - 1) * 32 + j - 1) * 1024, buffer, 1024 * 2);                  //1024*2��ʾһ�������ڴ�,buffer���� 
			}
		}
	}
	free(buffer);
	fclose(fpbmp);
	return 0;
}

/***���ư�ť��ͨ�ú���***/  
void bmp_draw_button(int x1, int y1, int x2, int y2, unsigned int color)
{
	int i, j,width,length;
	width = x2 - x1;
	length = y2 - y1;
	for (i = 0; i <= width; i++)
	{
		for (j = 0; j < length; j++)
		{
			Putpixel64k(x1+i,y1+j,color);
		}
	}
}

/***���������ĺ���***/
void bmp_draw_line(int x1, int y1, int x2, int y2, unsigned int color)
{
	int i, j;
	for (i = x1; i <= x2; i++)
	{
		Putpixel64k(i, y1, color);
		Putpixel64k(i, y1+1, color);
		Putpixel64k(i, y1+2, color);
	}
}

/*����Բ����*/
int drawellipse(int x, int y, int a, int b, unsigned int color, int flag)
{
	int i = 0, j = 0;
	float af = a, bf = b;
	if ((x - a < 0) || (x + a > 800) || (y - b < 0) || (y + b > 600))
		return 0;
	else
	{
		if (flag == 1)
		{
			for (i = 0; i <= a; i++)
			{
				j = (int)(sqrt(bf * bf - bf * bf / af / af * i * i));
				for (; j >= 0; j--)
				{
					Putpixel64k(x + i, y + j, color);
					Putpixel64k(x + i, y - j, color);
					Putpixel64k(x - i, y + j, color);
					Putpixel64k(x - i, y - j, color);
				}
			}
		}
		else
		{
			for (i = 0; i <= a; i++)
			{
				j = (int)(sqrt(bf * bf - bf * bf / af / af * i * i));
				Putpixel64k(x + i, y + j, color);
				Putpixel64k(x + i, y - j, color);
				Putpixel64k(x - i, y + j, color);
				Putpixel64k(x - i, y - j, color);
			}
			for (j = 0; j <= b; j++)
			{
				i = (int)(sqrt(af * af - af * af / bf / bf * j * j));
				Putpixel64k(x + i, y + j, color);
				Putpixel64k(x + i, y - j, color);
				Putpixel64k(x - i, y + j, color);
				Putpixel64k(x - i, y - j, color);
			}
		}
		return 1;
	}
}

/*��Բ����*/
int drawcircle(int x, int y, int r, unsigned int color, int flag)//shi xin 1,xu xin 0
{
	int i = 0, j = 0;
	if ((x - r < 0) || (x + r > 1024) || (y - r < 0) || (y + r > 768))
		return 0;
	else
	{
		if (flag == 1)
		{
			for (i = 0; i <= r; i++)
			{
				j = (int)(sqrt(r * r - i * i));
				for (; j >= 0; j--)
				{
					Putpixel64k(x + i, y + j, color);
					Putpixel64k(x + i, y - j, color);
					Putpixel64k(x - i, y + j, color);
					Putpixel64k(x - i, y - j, color);
				}
			}
		}
		else
		{
			for (i = 0; i <= r; i++)
			{
				j = (int)(sqrt(r * r - i * i));
				Putpixel64k(x + i, y + j, color);
				Putpixel64k(x + i, y - j, color);
				Putpixel64k(x - i, y + j, color);
				Putpixel64k(x - i, y - j, color);
			}
			for (j = 0; j <= r; j++)
			{
				i = (int)(sqrt(r * r - j * j));
				Putpixel64k(x + i, y + j, color);
				Putpixel64k(x + i, y - j, color);
				Putpixel64k(x - i, y + j, color);
				Putpixel64k(x - i, y - j, color);
			}
		}
		return 1;
	}
}

/*����*/
void arc256(int xc, int yc, int r, float stangle, float enangle, unsigned char color)
{
	float x, y, i;
	i = stangle;
	while (i <= enangle)
	{
		x = r * cos(i);
		y = r * sin(i);

		Putpixel64k(xc + x, yc + y, color);
		//Putpixel256(xc + x + 1, yc + y + 1, color);
		//Putpixel256(xc + x + 1, yc + y - 1, color);
		//Putpixel256(xc + x - 1, yc + y + 1, color);
		//Putpixel256(xc + x - 1, yc + y - 1, color);
		i += 0.01;
	}
}

void draw_play_light(int xc, int yc) //���Ʋ��Ű�ť
{
	int i;
	drawcircle(xc, yc, 30, -1, 1);
	for (i = 0; i < 20; i++)
	{
		Linel(xc - 10, yc - i, xc - 10 + (20 - i) * 3 / 2, yc - i, -200);
		Linel(xc - 10, yc + i, xc - 10 + (20 - i) * 3 / 2, yc + i, -200);
	}
}
/*
void draw_play_dark(int xc, int yc) //���Ʋ��Ű�ť
{
	int i;
	drawcircle(xc, yc, 30, -1, 1);
	for (i = 0; i < 20; i++)
	{
		Linel(xc - 10, yc - i, xc - 10 + (20 - i) * 3 / 2, yc - i, -200);
		Linel(xc - 10, yc + i, xc - 10 + (20 - i) * 3 / 2, yc + i, -200);
	}
}
*/
void draw_suspend_light(int xc, int yc) //������ͣ��ť
{
	int i;
	drawcircle(xc, yc, 30, -1, 1);
	for (i = 8; i < 14; i++)
	{
		Linel(xc - i, yc - 20, xc - i, yc +20, -200);
		Linel(xc + i, yc - 20, xc + i, yc + 20, -200);
	}
}

void draw_next_light(int xc, int yc) //������һ����ť
{
	int i;
	drawcircle(xc, yc, 30, -1, 1);
	for (i = 0; i < 20; i++)
	{
		Linel(xc - 16 + (20 - i) * 3 / 2, yc - i, xc - 10 + (20 - i) * 3 / 2, yc - i, -200);
		Linel(xc - 16 + (20 - i) * 3 / 2, yc + i, xc - 10 + (20 - i) * 3 / 2, yc + i, -200);
	}
}

void draw_last_light(int xc, int yc) //������һ����ť
{
	int i;
	drawcircle(xc, yc, 30, -1, 1);
	for (i = 0; i < 20; i++)
	{
		Linel(xc + 10 - (20 - i) * 3 / 2, yc - i, xc + 16 - (20 - i) * 3 / 2, yc - i, -200);
		Linel(xc + 10 - (20 - i) * 3 / 2, yc + i, xc + 16 - (20 - i) * 3 / 2, yc + i, -200);
	}
}

void draw_back_svga(int xc, int yc) //���Ʒ��ذ�ť
{
	int i;
	for (i = 0; i < 20; i++)
	{
		Linel(xc + 10 - (20 - i) * 3 / 2, yc - i, xc + 10, yc - i, -1);
		Linel(xc + 10 - (20 - i) * 3 / 2, yc + i, xc + 10, yc + i, -1);
	}
}

void draw_end_svga(int xc, int yc) //�����˳���ť
{
	int i;
	for (i = 0; i < 5; i++)
	{
		line64k(xc - 20, yc - 20, xc + 20, yc + 20, -1);
		line64k(xc - 20, yc + 20, xc + 20, yc - 20, -1);
	}
}


void draw_start_light(int y) //������ɰ�ť������
{
	drawcircle(462,y + 25,  25, -100, 1);
	drawcircle(562,y + 25,  25, -100, 1);
	Barl(462, y, 562, y+50, -100);
	puthz(464, y+2,"��ʼ", 48,60,WHITE);
}

void draw_start_dark(int y) //������ɰ�ť������
{
	drawcircle( 462,y + 25, 25, 10000, 1);
	drawcircle( 562,y + 25,  25, 10000, 1);
	Barl(462, y, 562, y + 50, 10000);
	puthz(464, y+2,"��ʼ", 48,60,WHITE);
}

int X(int i) //����յ�����꣬�������ղذ�ť
{
	double e = 2 * PI / 10; //����Ƕ�
	if (i % 2 == 0) //ż��
		return 11 * cos((i - 1) * e + PI / 2);
	else //����
		return 18 * cos((i - 1) * e + PI / 2);
}

int Y(int i) //����յ�����꣬�������ղذ�ť
{
	double e = 2 * PI / 10; //����Ƕ�
	if (i % 2 == 0) //ż��
		return (-11) * sin((i - 1) * e + PI / 2);
	else //����
		return (-18) * sin((i - 1) * e + PI / 2);
}

void button_collect_light(int x, int y) //�����ղذ�ť������
{
	int r_max = 11;
	int r_min = 18;
	int num; //�ڼ�����
	int i,j; //���꣬ԭ��Ϊ��x,y��
	/*��һ��*/
	for (j = Y(1); j < Y(2); j++)
	{
		Linel(x + X(1) + (j - Y(1)) * (X(2) - X(1)) / (Y(2) - Y(1)), j+y, x + X(1) + (j- Y(1)) * (X(10) - X(1)) / (Y(10) - Y(1)), j+y, -1);
	}
	for(j = Y(2); j < Y(3); j++)
		Linel(x + X(2) + (j - Y(2)) * (X(2) - X(3)) / (Y(2) - Y(3)), j+y, x + X(10) + (j - Y(10)) * (X(10) - X(9)) / (Y(10) - Y(9)),j+y,-1);
	for (j = Y(3); j < Y(4); j++)
		Linel(x + X(3) + (j - Y(3)) * (X(3) - X(4)) / (Y(3) - Y(4)), j+y, x + X(9) + (j - Y(9)) * (X(9) - X(8)) / (Y(9) - Y(8)),j+y,-1);
	for (j = Y(4); j < Y(6); j++)
		Linel(x + X(4) + (j - Y(4)) * (X(4) - X(5)) / (Y(4) - Y(5)), j+y, x + X(8) + (j - Y(8)) * (X(8) - X(7)) / (Y(8) - Y(7)),j+y,-1);
	for (j = Y(6); j < Y(5); j++)
	{
		Linel(x + X(4) + (j - Y(4)) * (X(4) - X(5)) / (Y(4) - Y(5)), j+y, x + X(5) + (j - Y(5)) * (X(5) - X(6)) / (Y(5) - Y(6)), j+y,-1);
		Linel(x + X(6) + (j - Y(6)) * (X(6) - X(7)) / (Y(6) - Y(7)), j+y, x + X(7) + (j - Y(7)) * (X(7) - X(8)) / (Y(7) - Y(8)), j+y,-1);
	}
}

void button_collect_dark(int x, int y) //�����ղذ�ť������
{
	int r_max = 11;
	int r_min = 18;
	int num; //�ڼ�����
	int i, j; //���꣬ԭ��Ϊ��x,y��
	/*��һ��*/
	for (j = Y(1); j < Y(2); j++)
	{
		Linel(x + X(1) + (j - Y(1)) * (X(2) - X(1)) / (Y(2) - Y(1)), j + y, x + X(1) + (j - Y(1)) * (X(10) - X(1)) / (Y(10) - Y(1)), j + y, -500);
	}
	for (j = Y(2); j < Y(3); j++)
		Linel(x + X(2) + (j - Y(2)) * (X(2) - X(3)) / (Y(2) - Y(3)), j + y, x + X(10) + (j - Y(10)) * (X(10) - X(9)) / (Y(10) - Y(9)), j + y, -500);
	for (j = Y(3); j < Y(4); j++)
		Linel(x + X(3) + (j - Y(3)) * (X(3) - X(4)) / (Y(3) - Y(4)), j + y, x + X(9) + (j - Y(9)) * (X(9) - X(8)) / (Y(9) - Y(8)), j + y, -500);
	for (j = Y(4); j < Y(6); j++)
		Linel(x + X(4) + (j - Y(4)) * (X(4) - X(5)) / (Y(4) - Y(5)), j + y, x + X(8) + (j - Y(8)) * (X(8) - X(7)) / (Y(8) - Y(7)), j + y, -500);
	for (j = Y(6); j < Y(5); j++)
	{
		Linel(x + X(4) + (j - Y(4)) * (X(4) - X(5)) / (Y(4) - Y(5)), j + y, x + X(5) + (j - Y(5)) * (X(5) - X(6)) / (Y(5) - Y(6)), j + y, -500);
		Linel(x + X(6) + (j - Y(6)) * (X(6) - X(7)) / (Y(6) - Y(7)), j + y, x + X(7) + (j - Y(7)) * (X(7) - X(8)) / (Y(7) - Y(8)), j + y, -500);
	}
}

void draw_clock(int x,int y) //��ʱ��
{
	x += 10;
	drawcircle(x,y,13,-1,1);
	drawcircle(x, y, 13, 0, 0);
	Linel(x, y,x, y-9, 100);
	Linel(x+1, y, x+1, y - 9, 100);
	Linel(x, y, x+11, y, 100);
	drawcircle(x, y, 4, 100, 1);
}

void draw_fire(int x, int y) //����
{
	int fire[20][15] =
	{
		{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
		{0,0,1,0,0,0,1,1,1,1,0,0,0,0,0},
		{0,0,0,1,1,0,1,1,1,1,0,0,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,0,1,1,0,0},
		{0,0,0,0,1,1,1,1,1,1,1,1,1,0,0},
		{0,0,0,0,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,0,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,0,1,1,1,1,1,1,1,1,1,1,1,0,0},
		{0,0,1,1,1,1,1,1,1,1,1,1,1,0,0},
		{0,0,1,1,1,1,1,1,1,1,1,1,1,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,0,0,1,1,1,1,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	int i,j;
	for (i = 0; i < 20; i++)
	{
		for(j = 0; j < 15; j++)
		{
			if (fire[i][j] == 0)
				continue;
			Putpixel64k(x + j, y + i, -800);   
		}
	}
}

void drawxin(int x, int y, int color)    //
{
	int x0 = x, y0 = y;
	double q, p;
	double r;
	r = sqrt(125);

	drawcircle(x + 11, y, r, color, 1);
	drawcircle(x + 31, y, r, color, 1);

	line64k(x, y, x + 21, y + 25, color);
	line64k(x + 42, y, x + 21, y + 25, color);

	for (p = y; p <= y + 25; p++)
	{
		for (q = x; q <= x + 42; q++)
		{
			if (p <= y0 + 25 * (q - x0) / 21 && p <= y0 - 25 * (q - x0 - 42) / 21)
				Putpixel64k(q, p, color);
		}
	}



}

void draw_tri(int x1, int y1, int x2, int y2, int x3, int y3, int color)//��������  
{
	int i, j, a, b;

	if (x1 > x2)
	{
		a = x2; b = y2;
		x2 = x1; y2 = y1;
		x1 = a; y1 = b;
	}
	if (x1 > x3)
	{
		a = x3; b = y3;
		x3 = x1; y3 = y1;
		x1 = a; y1 = b;
	}
	if (x2 > x3)
	{
		a = x3; b = y3;
		x3 = x2; y3 = y2;
		x2 = a; y2 = b;
	}

	line64k(x1, y1, x2, y2, color);
	line64k(x2, y2, x3, y3, color);
	line64k(x3, y3, x1, y1, color);

	if (x1 == x2)
	{
		if (y1 > y2)
		{
			a = y2; y2 = y1; y1 = a;
		}
		for (j = y1; j < y2; j++)
		{
			for (i = x1; i < x3; i++)
			{
				if (i <= x1 + (j - y1) * (x3 - x1) / (y3 - y1) && i <= x2 + (j - y2) * (x3 - x2) / (y3 - y2))
					Putpixel64k(i, j, color);
			}
		}
	}


	if (x2 == x3)
	{

		if (y2 > y3)
		{
			a = y3; y3 = y2; y2 = a;
		}
		for (j = y2; j < y3; j++)
		{
			for (i = x2; i > x1; i--)
			{
				if (i >= x2 + (j - y2) * (x2 - x1) / (y2 - y1) && i >= x3 + (j - y3) * (x3 - x1) / (y3 - y1))
					Putpixel64k(i, j, color);
			}
		}
	}

}