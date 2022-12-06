#ifndef _DATA_H_
#define _DATA_H_
typedef struct selfinfo
{
	char a[8];
	char id[8];
	char password[8];
	char pass[8];
	char day[9];
	char name[20];
	char height[4];
	char weight[4];
	char sex;
}user;

typedef struct healthinfo
{
	char year[5];
	char month[3];	
	char day[3];
	char weight[4];
}health;
#endif
