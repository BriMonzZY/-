/*

0	  	1		  2		  3
4	  	5		  6		  7
8	  	9	   ��     ��
��   ���  �޸�  ����

*/

#define _MAIN_C
#include "config.h"
#include "key.h"
#include "smg.h"
#include "IIC.h"
#include "main.h"
#include "led.h"
#include "app.h"



uchar key[8] = {14, 14, 14, 14, 14, 14, 14, 14};//��ʾ
//						������                ������

uchar oldkey[6] = {8, 8, 8, 8, 8, 8};//�洢�޸ĵ������Լ�ԭʼ����Ҫ�ڳ�����ʼ��eeprom�е���ֵ��ֵ����


uchar backup[4][4] = { //��ʼ������ֵ����
			{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};

enum estaSystem staSystem = NOMAL;		//���ó�ʼ״̬staSystemΪNOMAL	
uchar addr = 110;//�ȴ����λ
bit keyjudge = 0;//�жϰ�����û�а���
uchar key_in_judge = 0;


void delay(void)   //��� -0.000000000023us
{
    unsigned char a,b;
    for(b=221;b>0;b--)
        for(a=207;a>0;a--);
}



			
void main()
{
	bit set_key_one = 1;
	
	
	/*
	write24c02(110, 8);
	write24c02(111, 8);
	write24c02(112, 8);
	write24c02(113, 8);
	write24c02(114, 8);
	write24c02(115, 8);
	*/
	
	oldkey[0] = read24c02(110);
	oldkey[1] = read24c02(111);
	oldkey[2] = read24c02(112);
	oldkey[3] = read24c02(113);
	oldkey[4] = read24c02(114);
	oldkey[5] = read24c02(115);
	
	delay();
	timer0Init();//1ms
	timer1Init();//5ms
	while(1){//ѭ����� 4*4 �ľ��󰴼�
		keydriver();
		
		if(staSystem == NOMAL) {
			key[0] = 14; key[1] = 14; key[2] = 14; key[3] = 14; key[4] = 14; key[5] = 14; key[6] = 14; key[7] = 14;
		}
		
		if(staSystem == OPEN) {//��ϵͳ״̬Ϊ��ʱ
			key[0] = 10; key[1] = 14; key[2] = 14; key[3] = 14; key[4] = 10; key[5] = 11; key[6] = 12; key[7] = 13;
			set_key_one = 1;
		}
		
		if(staSystem == KEYIN) {//����״̬�ж������Ƿ���ȷ  ע��Ǳ��bug(�л�ģʽʱkey�����ֵ)
			uchar judge = 0x00;
			uchar i;
			key[0] = 15;
			//key_in_judge = 0;//��ʼ�����������ж�λ
			for(i = 0; i < 6; i++) {
				judge <<= 1;
				if(key[i + 2] == oldkey[i]) judge |= 0x01;
				else judge |= 0x00;
			}
			if(judge == 0x3f) staSystem = OPEN;//������ȷ����ϵͳ״̬ΪOPEN
			else if(judge != 0x3f && key_in_judge == 6) {
				staSystem = NOMAL;
				key_in_judge = 0;
			}
		}//if(staSystem == KEYIN)
		
		if(staSystem == SET_KEY) {
			if(set_key_one) {//��֤����һ�Σ���Ӱ��������������
				key[0] = 16; key[1] = 14; key[2] = 14; key[3] = 14; key[4] = 14; key[5] = 14; key[6] = 14; key[7] = 14;
				set_key_one = 0;
			}
		}//if(staSystem == SET_KEY)
	}	
}





	//bit judge = 1;//�ж������Ƿ���ȷ(Ϊ1ʱ)
/*���eeprom������ʱʹ��*/
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



//for(gg = 3; gg <= 7; gg++) {//ִ��5��
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
		for(gg = 3; gg <= 7; gg++) {//ִ��5��
			key[gg - 1] = key[gg];
		}
		key[7] = read24c02(addr - 1);
	}
*/										
										


/*��ʱ���ж�0�����������������ɨ�裬�Լ�����ɨ��*/
void timer0() interrupt 1
{
	static uchar flags;
	TH0 = 0xfc; //���¼��س�ֵ1ms
	TL0 = 0x66;
	/*�����*/  
	flags++;
	if(flags == 2) {
		flags = 0;
		display(key[0], key[1], key[2], key[3], key[4], key[5], key[6], key[7]);
	}
	keyscan();
}

void timer1() interrupt 3
{
	static uchar flag;
	TH1 = 0xee;
	TL1 = 0x00;	//����5ms
	flag++;
	if(flag == 250) {//��֪��Ϊʲô������300,�޴�bug
		flag = 0;
		if(staSystem == OPEN) {
			if(keyjudge == 0) {
				staSystem = NOMAL;
			}
		}
		keyjudge = 0;
	}
}