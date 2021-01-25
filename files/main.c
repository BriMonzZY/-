

#include "config.h"
#include "key.h"
#include "smg.h"
#include "IIC.h"



uchar key[8] = {15, 15, 0, 0, 0, 0, 0, 0};//显示
//						最左面                最右面

uchar oldkey[6] = {8, 8, 8, 8, 8, 8};//存储修改的密码以及原始密码





void main()
{
	//uchar addr = 110;//先存最高位
	//bit judge = 1;//判断密码是否正确(为1时)
	uchar backup[4][4] = { //初始化按键值备份
			{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
	uchar b;
	
	


	timer0Init();
	while(1){//循环检测 4*4 的矩阵按键
		b = keydriver();
		key[7] = b;
	}

	
}





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