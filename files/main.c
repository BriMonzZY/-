/*

0	  	1		  2		  3
4	  	5		  6		  7
8	  	9	   无     无
无   清除  修改  输入

*/

#define _MAIN_C
#include "config.h"
#include "key.h"
#include "smg.h"
#include "IIC.h"
#include "main.h"
#include "led.h"
#include "app.h"



uchar key[8] = {15, 15, 0, 0, 0, 0, 0, 0};//显示
//						最左面                最右面

uchar oldkey[6] = {8, 8, 8, 8, 8, 8};//存储修改的密码以及原始密码要在程序起始将eeprom中的数值赋值到这


uchar backup[4][4] = { //初始化按键值备份
			{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};

enum estaSystem staSystem = NOMAL;		//设置初始状态staSystem为NOMAL	
uchar addr = 110;//先存最高位

			


void delay2s(void)   //误差 -0.000000000045us
{
    unsigned char a,b,c;
    for(c=131;c>0;c--)
        for(b=156;b>0;b--)
            for(a=3;a>0;a--);
}


			
void main()
{
	timer0Init();
	while(1){//循环检测 4*4 的矩阵按键
		keydriver();
		
		if(staSystem == NOMAL) {
			key[0] = 14; key[1] = 14; key[2] = 14; key[3] = 14; key[4] = 14; key[5] = 14; key[6] = 14; key[7] = 14;
		}
		
		if(staSystem == OPEN) {//当系统状态为打开时
			key[0] = 10; key[1] = 14; key[2] = 14; key[3] = 14; key[4] = 10; key[5] = 11; key[6] = 12; key[7] = 13;
			delay2s();
			staSystem = NOMAL;
		}
		
		if(staSystem == KEYIN) {//输入状态判断密码是否正确  注意潜在bug(切换模式时key数组的值)
			uchar judge = 0x00;
			uchar i;
			for(i = 0; i < 6; i++) {
				judge <<= 1;
				if(key[i + 2] == oldkey[i]) judge |= 0x01;
				else judge |= 0x00;
			}
			if(judge == 0x3f) staSystem = OPEN;//密码正确设置系统状态为OPEN
		}//if(staSystem == KEYIN)
		
	}	
}





	//bit judge = 1;//判断密码是否正确(为1时)
/*清空eeprom程序，暂时使用*/
//if(keyvalue == 15) {
//	
//	write24c02(110, 0);
//	write24c02(111, 0);
//	write24c02(112, 0);
//	write24c02(113, 0);
//	write24c02(114, 0);
//	write24c02(115, 0);
//}

//if(addr == 116) addr = 110;
//else {
//	write24c02(addr, keyvalue);
//	addr++;
//}



//for(gg = 3; gg <= 7; gg++) {//执行5次
//	key[gg - 1] = key[gg];
//}
//key[7] = read24c02(addr - 1);
	
/*
if(staSystem ==KEYIN) {
		if(addr == 116) addr = 110;
		else {
			write24c02(addr, keyvalue);
			addr++;
		}
		for(gg = 3; gg <= 7; gg++) {//执行5次
			key[gg - 1] = key[gg];
		}
		key[7] = read24c02(addr - 1);
	}
*/										
										


/*定时器中断0服务函数，处理数码管扫描，以及按键扫描*/
void timer0() interrupt 1
{
	static uchar flags;
	TH0 = 0xfc; //重新加载初值1ms
	TL0 = 0x66;
	/*数码管*/  
	flags++;
	if(flags == 2) {
		flags = 0;
		display(key[0], key[1], key[2], key[3], key[4], key[5], key[6], key[7]);
	}
	keyscan();
}