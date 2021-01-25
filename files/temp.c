#include <reg52.h>
#define uint unsigned int
#define uchar unsigned char
uchar code SMGduan[]= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
uchar code SMGwei[] = {0xfe, 0xfd, 0xfb};


uchar KeySta[4][4] = { //全部矩阵按键的当前状态
    {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}
};
uchar keyvalue = 0;

sbit DU = P2^6;
sbit WE = P2^7; 
sbit KEY_OUT_1 = P3^0;
sbit KEY_OUT_2 = P3^1;
sbit KEY_OUT_3 = P3^2;
sbit KEY_OUT_4 = P3^3;
sbit KEY_IN_1 = P3^4;
sbit KEY_IN_2 = P3^5;
sbit KEY_IN_3 = P3^6;
sbit KEY_IN_4 = P3^7;

/*定时器中断0初始化函数*/
void timer0Init()
{
    EA = 1;
    TMOD = 0x01; //设置 T0 为模式 1
    TH0 = 0xFC; //为 T0 赋初值 0xFC67，定时 1ms
    TL0 = 0x66;
    ET0 = 1; //使能 T0 中断
    TR0 = 1; //启动 T0
}

/*三位数码管显示函数*/
void display(uchar i)
{
    static uchar wei;         
    P0 = 0XFF;
    WE = 1;
    P0 = SMGwei[wei];
    WE = 0;
    switch(wei)
    {
        case 0: DU = 1; P0 = SMGduan[i / 100]; DU = 0; break;
        case 1: DU = 1; P0 = SMGduan[i % 100 / 10]; DU = 0; break;    
        case 2: DU = 1; P0 = SMGduan[i % 10]; DU = 0; break;        
    }
    wei++;
    if(wei == 3) {
        wei = 0;
    }
}

void main()
{
    uchar i,j;
    uchar backup[4][4] = { //按键值备份，保存前一次的值
        {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}
    };
    timer0Init();
    while(1){//循环检测 4*4 的矩阵按键
        for (i=0; i<4; i++){
            for (j=0; j<4; j++){
                if (backup[i][j] != KeySta[i][j]){//检测按键动作
                    if (backup[i][j] != 0){ //按键按下时执行动作
                        keyvalue = i * 4 + j;
                    }
                    backup[i][j] = KeySta[i][j]; //更新前一次的备份值
                }
            }
        }
    }
}

/*定时器中断0服务函数*/
void timer0() interrupt 1
{
    uchar m;
    static uchar keyout = 0; //矩阵按键扫描输出索引
    static uchar flags = 0;
    static uchar keybuf[4][4] = { //矩阵按键扫描缓冲区
        {0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF},
        {0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}
    };
    
    TH0 = 0xFC; //重新加载初值1ms
    TL0 = 0x66;
    
    /*数码管*/
    flags++;
    if(flags == 5) {    //5ms
        flags = 0;
        display(keyvalue);    //数码管动态扫描
    }
    
    /*消抖并更新按键状态*/
    //将一行的 4 个按键值移入缓冲区
    keybuf[keyout][0] = (keybuf[keyout][0] << 1) | KEY_IN_1;
    keybuf[keyout][1] = (keybuf[keyout][1] << 1) | KEY_IN_2;
    keybuf[keyout][2] = (keybuf[keyout][2] << 1) | KEY_IN_3;
    keybuf[keyout][3] = (keybuf[keyout][3] << 1) | KEY_IN_4;
    //消抖后更新按键状态
    for (m = 0; m < 4; m++){ //每行 4 个按键，所以循环 4 次
        if ((keybuf[keyout][m] & 0x0F) == 0x00){    //连续 4 次扫描值为 0，即 4*4ms 内都是按下状态时，可认为按键已稳定的按下
            KeySta[keyout][m] = 0;
        }
        else if ((keybuf[keyout][m] & 0x0F) == 0x0F){    //连续 4 次扫描值为 1，即 4*4ms 内都是弹起状态时，可认为按键已稳定的弹起
            KeySta[keyout][m] = 1;
        }
    }
    
    /*进行矩阵按键扫描*/
    //执行下一次的扫描输出
    keyout++; //输出索引递增
    keyout = keyout & 0x03; //索引值加到 4 即归零
    switch (keyout){ //根据索引，释放当前输出引脚，拉低下次的输出引脚
        case 0: KEY_OUT_4 = 1; KEY_OUT_1 = 0; break;
        case 1: KEY_OUT_1 = 1; KEY_OUT_2 = 0; break;
        case 2: KEY_OUT_2 = 1; KEY_OUT_3 = 0; break;
        case 3: KEY_OUT_3 = 1; KEY_OUT_4 = 0; break;
        default: break;
 }
}