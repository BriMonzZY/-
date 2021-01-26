#include "config.h"
#include "main.h"
#include "app.h"
#include "IIC.h"

uchar gg;

void key_0(uchar keyvalue) {
	/*输入密码*/
	if(staSystem ==KEYIN) {
		key_in_judge++;
		for(gg = 3; gg <= 7; gg++) {//执行5次
			key[gg - 1] = key[gg];
		}
		key[7] = keyvalue;
	}
	/*修改密码*/
	if(staSystem == SET_KEY) {
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

void key_1(uchar keyvalue) {
	/*输入密码*/
	if(staSystem ==KEYIN) {
		key_in_judge++;
		for(gg = 3; gg <= 7; gg++) {//执行5次
			key[gg - 1] = key[gg];
		}
		key[7] = keyvalue;
	}
	/*修改密码*/
	if(staSystem == SET_KEY) {
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

void key_2(uchar keyvalue) {
	/*输入密码*/
	if(staSystem ==KEYIN) {
		key_in_judge++;
		for(gg = 3; gg <= 7; gg++) {//执行5次
			key[gg - 1] = key[gg];
		}
		key[7] = keyvalue;
	}
	/*修改密码*/
	if(staSystem == SET_KEY) {
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

void key_3(uchar keyvalue) {
	/*输入密码*/
	if(staSystem ==KEYIN) {
		key_in_judge++;
		for(gg = 3; gg <= 7; gg++) {//执行5次
			key[gg - 1] = key[gg];
		}
		key[7] = keyvalue;
	}
	/*修改密码*/
	if(staSystem == SET_KEY) {
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

void key_4(uchar keyvalue) {
	/*输入密码*/
	if(staSystem ==KEYIN) {
		key_in_judge++;
		for(gg = 3; gg <= 7; gg++) {//执行5次
			key[gg - 1] = key[gg];
		}
		key[7] = keyvalue;
	}
	/*修改密码*/
	if(staSystem == SET_KEY) {
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

void key_5(uchar keyvalue) {
	/*输入密码*/
	if(staSystem ==KEYIN) {
		key_in_judge++;
		for(gg = 3; gg <= 7; gg++) {//执行5次
			key[gg - 1] = key[gg];
		}
		key[7] = keyvalue;
	}
	/*修改密码*/
	if(staSystem == SET_KEY) {
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
void key_6(uchar keyvalue) {
	/*输入密码*/
	if(staSystem ==KEYIN) {
		key_in_judge++;
		for(gg = 3; gg <= 7; gg++) {//执行5次
			key[gg - 1] = key[gg];
		}
		key[7] = keyvalue;
	}
	/*修改密码*/
	if(staSystem == SET_KEY) {
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

void key_7(uchar keyvalue) {
	/*输入密码*/
	if(staSystem ==KEYIN) {
		key_in_judge++;
		for(gg = 3; gg <= 7; gg++) {//执行5次
			key[gg - 1] = key[gg];
		}
		key[7] = keyvalue;
	}
	/*修改密码*/
	if(staSystem == SET_KEY) {
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

void key_8(uchar keyvalue) {
	/*输入密码*/
	if(staSystem ==KEYIN) {
		key_in_judge++;
		for(gg = 3; gg <= 7; gg++) {//执行5次
			key[gg - 1] = key[gg];
		}
		key[7] = keyvalue;
	}
	/*修改密码*/
	if(staSystem == SET_KEY) {
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

void key_9(uchar keyvalue) {
	/*输入密码*/
	if(staSystem ==KEYIN) {
		key_in_judge++;
		for(gg = 3; gg <= 7; gg++) {//执行5次
			key[gg - 1] = key[gg];
		}
		key[7] = keyvalue;
	}
	/*修改密码*/
	if(staSystem == SET_KEY) {
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





/*功能键*/

void key_10() {
	
}
void key_11() {
	
}

void key_12() {
	
}

void key_13() {//清除
	if(staSystem == KEYIN) {
		uchar i;
		
		for(i = 6; i >= 2; i--) {
			key[i + 1] = key[i];
		}
		key[2] = 14;
	}
}

void key_14() {//修改
	if(staSystem == SET_KEY) {
		staSystem = OPEN;
	}
	if(staSystem == OPEN) {
		staSystem = SET_KEY;
	}
	
}

void key_15() {//输入
	if(staSystem == NOMAL) {
		staSystem = KEYIN;
	}
}



void KeyAction(uchar keyvalue) {
	switch (keyvalue)
	{
		case 0: key_0(keyvalue); keyjudge = 1; break;
		case 1: key_1(keyvalue); keyjudge = 1; break;	
		case 2: key_2(keyvalue); keyjudge = 1; break;	
		case 3: key_3(keyvalue); keyjudge = 1; break;
		case 4: key_4(keyvalue); keyjudge = 1; break;
		case 5: key_5(keyvalue); keyjudge = 1; break;
		case 6: key_6(keyvalue); keyjudge = 1; break;
		case 7: key_7(keyvalue); keyjudge = 1; break;
		case 8: key_8(keyvalue); keyjudge = 1; break;
		case 9: key_9(keyvalue); keyjudge = 1; break;
		case 10: key_10(); keyjudge = 1; break;
		case 11: key_11(); keyjudge = 1; break;
		case 12: key_12(); keyjudge = 1; break;
		case 13: key_13(); keyjudge = 1; break;
		case 14: key_14(); keyjudge = 1; break;
		case 15: key_15(); keyjudge = 1; break;		
		default: break;
	}
}