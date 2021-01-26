#include "config.h"
#include "main.h"

void delayms(int z)
{
	int x,y;
		for(x = z; x > 0; x --);
			for(y = 114; y > 0; y --);
}


void key_error() {
	unsigned long i;
	L1 = 0;
	L7 = 1;
	L8 = 1;
	for(i = 0; i < 20000; i++);
	L1 = 1;
}