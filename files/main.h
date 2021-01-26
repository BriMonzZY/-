#ifndef _MAIN_H
#define _MAIN_H

extern uchar key[8];
extern uchar backup[4][4];  //将在main函数进行初始化
extern uchar addr;//先存最高位
extern bit keyjudge;
extern uchar key_in_judge;

enum estaSystem {  //枚举系统状态
	NOMAL, SET_KEY, OPEN, KEYIN
};

#ifndef _MAIN_C
extern enum estaSystem staSystem;//staSystem当前系统状态
#endif

#endif