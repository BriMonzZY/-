#ifndef _MAIN_H
#define _MAIN_H

extern uchar key[8];
extern uchar backup[4][4];  //����main�������г�ʼ��
extern uchar addr;//�ȴ����λ
extern bit keyjudge;
extern uchar key_in_judge;

enum estaSystem {  //ö��ϵͳ״̬
	NOMAL, SET_KEY, OPEN, KEYIN
};

#ifndef _MAIN_C
extern enum estaSystem staSystem;//staSystem��ǰϵͳ״̬
#endif

#endif