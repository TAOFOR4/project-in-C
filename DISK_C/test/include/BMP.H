

#ifndef	SVGA_H
#define	SVGA_H

#define	SCR_WIDTH	1024	 //��Ļ�������� 
#define	SCR_HEIGHT	768		 //��Ļ�߶����� 
#define PI 3.141595265 //pi


/***8λbmp��ɫ����***/
typedef struct RGB_BMP_typ
{
	unsigned char b;	//��ɫ������BLUE��д
	unsigned char g;	//��ɫ������GREEN��д
	unsigned char r;	//��ɫ������ RED��д
	unsigned char reserved;		//������
}RGB_BMP;


/*24λbmpͼ��ɫ�ṹ*/
typedef struct
{
	unsigned char B;	/*��ɫ������BLUE��д*/
	unsigned char G;	/*��ɫ������GREEN��д*/
	unsigned char R;	/*��ɫ������RED��д*/
} COLORS24;



/***����SVGA��ʾģʽΪ0x105,Ϊ1024*768*256***/
void SetSVGA256(void);
/***����SVGA��ʾģʽΪ0x117,Ϊ1024*768*64k***/
void SetSVGA64k(void);
/***��ҳ����***/
void Selectpage(register char page);


/***��ʾ24λ��ѹ��bmpͼ***/
void Readbmp64k(int x, int y, char * path);
/***��ȡ����64k��bmpͼƬ***/
void Readpartbmp64k(int x,int y,int x1,int y1,int x2,int y2,char *path);

/***0x117ģʽ�»��㺯��***/
void Putpixel64k(int x, int y, unsigned int color);

/***�����κ���***/
void rectangle_svga(int x0,int y0,int x1,int y1);

/***�ر�ͼ����ʾģʽ***/
void CloseSVGA(void);
/***���ñ�����ɫ***/
void setbkcolor64k(int color);

/***24λ��ʾģʽ�»���***/
void Linel(int x1, int y1, int x2, int y2, unsigned int color);
/***�����ο麯��(24λ��***/
void Barl(int x1, int y1, int x2, int y2, unsigned int color);
/***��45��б��***/
void Linelean(int x1, int y1, int x2, int y2, unsigned int color);
/***��б��***/
void line64k(int x1, int y1, int x2, int y2, unsigned int color);
/***��ȡ��ɫ��ֵ����Ӧ����ɫ***/
unsigned int ReadColor(unsigned int x ,unsigned int y ,unsigned int z);
/***����ͼ��***/
void Saveimagetofile(int x1,int y1,int x2,int y2,const char * path);
/***����ͼ��***/
void Loadimagefromfile(int x1,int y1,int x2,int y2,const char * path);
/***��ȡ����Ƭ��1024*768��С��ͼƬ***/
void Readbmplarge (int x, int y, char * path);
/***���ٶ�ͼ***/
int bmp_fast(int y1,int y2,char * path);
/***���ư�ť��ͨ�ú���***/
void bmp_draw_button(int x1, int y1, int x2, int y2, unsigned int color);
/***���������ĺ���***/
void bmp_draw_line(int x1, int y1, int x2, int y2, unsigned int color);
/*��Բ  Բ��λ�ã��뾶����ɫ���Ƿ�ʵ��(��1��0)  �ɹ�����1��ʧ�ܷ���0*/
int drawcircle(int x, int y, int r, unsigned int color, int flag);
/*����Բ  Բ��λ�ã�x����뾶��y����뾶����ɫ���Ƿ�ʵ��(��1��0)  �ɹ�����1��ʧ�ܷ���0*/
int drawellipse(int x, int y, int a, int b, unsigned int color, int flag);
/*����*/
void arc256(int xc, int yc, int r, float stangle, float enangle, unsigned char color);
void draw_play_light(int xc, int yc); //���Ʋ��Ű�ť
//void draw_play_dark(int xc, int yc); //���Ʋ��Ű�ť
void draw_suspend_light(int xc, int yc); //������ͣ��ť
void draw_last_light(int xc, int yc); //������һ����ť
void draw_next_light(int xc, int yc); //������һ����ť
void draw_back_svga(int xc, int yc); //���Ʒ��ذ�ť
void draw_end_svga(int xc, int yc); //�����˳���ť
void draw_start_light(int y); //������ɰ�ť������
void draw_start_dark(int y); //������ɰ�ť������
int X(int i); //����յ�����꣬�������ղذ�ť
int Y(int i); //����յ�����꣬�������ղذ�ť
void button_collect_light(int x, int y); //�����ղذ�ť������
void button_collect_dark(int x, int y); //�����ղذ�ť������
void draw_clock(int x, int y); //��ʱ��
void draw_fire(int x, int y); //����
void drawxin(int x, int y, int color);//������ 
void draw_tri(int x1, int y1, int x2, int y2, int x3, int y3, int color);//�������� 

#endif

