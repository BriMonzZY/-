#include "config.h"
#include "smg.h"
																																									//10    11   12    13     14     15
																																									//O     P     e     n     熄灭   -
uchar code SMGduan[]= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x3f, 0x73, 0x7b, 0x37, 0x00, 0x40};
uchar code SMGwei[] = {0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x7F};


void delay200us(void)   //误差 -0.347222222222us
{
    unsigned char a,b;
    for(b=1;b>0;b--)
        for(a=89;a>0;a--);
}


void delay500us(void)   //误差 -0.868055555556us
{
    unsigned char a,b;
    for(b=1;b>0;b--)
        for(a=227;a>0;a--);
}


void delay50us(void)   //误差 -0.086805555556us
{
    unsigned char a,b;
    for(b=1;b>0;b--)
        for(a=20;a>0;a--);
}



/*三位数码管显示函数*/
void display(uchar a, uchar b, uchar c, uchar d, uchar e, uchar f, uchar g, uchar h)
{
	static uchar wei; 
	P0 = 0Xff;
	WE = 1;
	P0 = SMGwei[wei];
	WE = 0;
	switch(wei)
	{
		case 0: DU = 1; P0 = SMGduan[a]; DU = 0; break;
		case 1: DU = 1; P0 = SMGduan[b]; DU = 0; break;    
		case 2: DU = 1; P0 = SMGduan[c]; DU = 0; break; 
		case 3: DU = 1; P0 = SMGduan[d]; DU = 0; break; 
		case 4: DU = 1; P0 = SMGduan[e]; DU = 0; break; 
		case 5: DU = 1; P0 = SMGduan[f]; DU = 0; break; 
		case 6: DU = 1; P0 = SMGduan[g]; DU = 0; break; 
		case 7: DU = 1; P0 = SMGduan[h]; DU = 0; break; //个位
	}
	wei++;
	if(wei == 8) {
			wei = 0;
	}
}



//void display(uint i)
//{
//    static uchar wei;         
//    P0 = 0xff;
//    WE = 1;
//    P0 = SMGwei[wei];
//    WE = 0;
//    switch(wei)
//    {
//        case 0: DU = 1; P0 = SMGduan[i / 100]; DU = 0; break;
//        case 1: DU = 1; P0 = SMGduan[i % 100 / 10]; DU = 0; break;    
//        case 2: DU = 1; P0 = SMGduan[i % 10]; DU = 0; break;        
//    }
//    wei++;
//    if(wei == 3)
//        wei = 0;
//}