#ifndef _judge_h
#define _judge_h

void input_database(char* account1, char* password1,char* id1);//�洢���û�������˺ź�����
int judge_password(char* account1, char* password1);//ȷ���˺ź������Ƿ�ƥ��
int judge_blank1(char* str, int x, int y);//�����û�ע�������Ϣ�Ƿ�����Ϊ��
int judge_account(char *account1);//�����û�ע���˺��Ƿ����
int judge_id(char *id1);//�����û�ע�����֤����λ�Ƿ����
int judge_len(char *a);//�����û�ע���˺ų����Ƿ������С����Ҫ��
int judge_lenaccount(char *account);//�����û�ע�������˺��Ƿ������󳤶�Ҫ��
int judge_lenpassword(char *password);//�����û�ע�����볤���Ƿ������󳤶�Ҫ��
int judge_lenid(char *id);//�����û�ע�����֤����λ�����Ƿ������λ����Ҫ��
int judge_correct(char *account,char *password);//�����û�ע��ʱ������ȷ�������Ƿ�һ��
int judge_len1(char *password);//�����û�ע�����볤���Ƿ������С����Ҫ��
int judge_account(char *account1);//�����û�ע���˺��Ƿ����
int lookforpassword(char* account1,char* id1);//帮助用户找回密码
#endif
