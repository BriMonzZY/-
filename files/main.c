

#include "config.h"
#include "key.h"
#include "smg.h"
#include "IIC.h"



uchar key[8] = {15, 15, 0, 0, 0, 0, 0, 0};//��ʾ
//						������                ������

uchar oldkey[6] = {8, 8, 8, 8, 8, 8};//�洢�޸ĵ������Լ�ԭʼ����





void main()
{
	//uchar addr = 110;//�ȴ����λ
	//bit judge = 1;//�ж������Ƿ���ȷ(Ϊ1ʱ)
	uchar backup[4][4] = { //��ʼ������ֵ����
			{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
	uchar b;
	
	


	timer0Init();
	while(1){//ѭ����� 4*4 �ľ��󰴼�
		b = keydriver();
		key[7] = b;
	}

	
}





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