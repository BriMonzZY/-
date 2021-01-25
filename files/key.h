#ifndef _KEY_H
#define _KEY_H

void timer0Init();
uchar keydriver();
void keyscan();
extern uchar backup[4][4];

#endif