#include "config.h"
#include "main.h"
#include "app.h"
#include "IIC.h"

uchar gg;

void key_0(uchar keyvalue) {
	/*输入密码*/
	if(staSystem ==KEYIN) {
		for(gg = 3; gg <= 7; gg++) {//执行5次
			key[gg - 1] = key[gg];
		}
		key[7] = keyvalue;
	}
	/*修改密码*/
	if(staSystem == SET_KEY) {
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
	}
}

void key_1(uchar keyvalue) {
	/*输入密码*/
	if(staSystem ==KEYIN) {
		for(gg = 3; gg <= 7; gg++) {//执行5次
			key[gg - 1] = key[gg];
		}
		key[7] = keyvalue;
	}
	/*修改密码*/
	if(staSystem == SET_KEY) {
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
	}
}

void key_2(uchar keyvalue) {
	/*输入密码*/
	if(staSystem ==KEYIN) {
		for(gg = 3; gg <= 7; gg++) {//执行5次
			key[gg - 1] = key[gg];
		}
		key[7] = keyvalue;
	}
	/*修改密码*/
	if(staSystem == SET_KEY) {
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
	}
}

void key_3(uchar keyvalue) {
	/*输入密码*/
	if(staSystem ==KEYIN) {
		for(gg = 3; gg <= 7; gg++) {//执行5次
			key[gg - 1] = key[gg];
		}
		key[7] = keyvalue;
	}
	/*修改密码*/
	if(staSystem == SET_KEY) {
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
	}
}

void key_4(uchar keyvalue) {
	/*输入密码*/
	if(staSystem ==KEYIN) {
		for(gg = 3; gg <= 7; gg++) {//执行5次
			key[gg - 1] = key[gg];
		}
		key[7] = keyvalue;
	}
	/*修改密码*/
	if(staSystem == SET_KEY) {
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
	}
}

void key_5(uchar keyvalue) {
	/*输入密码*/
	if(staSystem ==KEYIN) {
		for(gg = 3; gg <= 7; gg++) {//执行5次
			key[gg - 1] = key[gg];
		}
		key[7] = keyvalue;
	}
	/*修改密码*/
	if(staSystem == SET_KEY) {
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
	}
}
void key_6(uchar keyvalue) {
	/*输入密码*/
	if(staSystem ==KEYIN) {
		for(gg = 3; gg <= 7; gg++) {//执行5次
			key[gg - 1] = key[gg];
		}
		key[7] = keyvalue;
	}
	/*修改密码*/
	if(staSystem == SET_KEY) {
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
	}
}

void key_7(uchar keyvalue) {
	/*输入密码*/
	if(staSystem ==KEYIN) {
		for(gg = 3; gg <= 7; gg++) {//执行5次
			key[gg - 1] = key[gg];
		}
		key[7] = keyvalue;
	}
	/*修改密码*/
	if(staSystem == SET_KEY) {
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
	}
}

void key_8(uchar keyvalue) {
	/*输入密码*/
	if(staSystem ==KEYIN) {
		for(gg = 3; gg <= 7; gg++) {//执行5次
			key[gg - 1] = key[gg];
		}
		key[7] = keyvalue;
	}
	/*修改密码*/
	if(staSystem == SET_KEY) {
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
	}
}

void key_9(uchar keyvalue) {
	/*输入密码*/
	if(staSystem ==KEYIN) {
		for(gg = 3; gg <= 7; gg++) {//执行5次
			key[gg - 1] = key[gg];
		}
		key[7] = keyvalue;
	}
	/*修改密码*/
	if(staSystem == SET_KEY) {
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
	}
}






/*功能键*/

void key_10() {
	
}
void key_11() {
	
}

void key_12() {
	
}

void key_13() {
	
}

void key_14() {
	
}

void key_15() {
	if(staSystem == NOMAL) {
		staSystem = KEYIN;
	}
}



void KeyAction(uchar keyvalue) {
	switch (keyvalue)
	{
		case 0: key_0(keyvalue); break;
		case 1: key_1(keyvalue); break;	
		case 2: key_2(keyvalue); break;	
		case 3: key_3(keyvalue); break;
		case 4: key_4(keyvalue); break;
		case 5: key_5(keyvalue); break;
		case 6: key_6(keyvalue); break;
		case 7: key_7(keyvalue); break;
		case 8: key_8(keyvalue); break;
		case 9: key_9(keyvalue); break;
		case 10: key_10(); break;
		case 11: key_11(); break;
		case 12: key_12(); break;
		case 13: key_13(); break;
		case 14: key_14(); break;
		case 15: key_15(); break;		
		default: break;
	}
}