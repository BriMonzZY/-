#include <reg52.h>
#define uint unsigned int
#define uchar unsigned char
uchar code SMGduan[]= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
uchar code SMGwei[] = {0xfe, 0xfd, 0xfb};


uchar KeySta[4][4] = { //ȫ�����󰴼��ĵ�ǰ״̬
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

/*��ʱ���ж�0��ʼ������*/
void timer0Init()
{
    EA = 1;
    TMOD = 0x01; //���� T0 Ϊģʽ 1
    TH0 = 0xFC; //Ϊ T0 ����ֵ 0xFC67����ʱ 1ms
    TL0 = 0x66;
    ET0 = 1; //ʹ�� T0 �ж�
    TR0 = 1; //���� T0
}

/*��λ�������ʾ����*/
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
    uchar backup[4][4] = { //����ֵ���ݣ�����ǰһ�ε�ֵ
        {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}
    };
    timer0Init();
    while(1){//ѭ����� 4*4 �ľ��󰴼�
        for (i=0; i<4; i++){
            for (j=0; j<4; j++){
                if (backup[i][j] != KeySta[i][j]){//��ⰴ������
                    if (backup[i][j] != 0){ //��������ʱִ�ж���
                        keyvalue = i * 4 + j;
                    }
                    backup[i][j] = KeySta[i][j]; //����ǰһ�εı���ֵ
                }
            }
        }
    }
}

/*��ʱ���ж�0������*/
void timer0() interrupt 1
{
    uchar m;
    static uchar keyout = 0; //���󰴼�ɨ���������
    static uchar flags = 0;
    static uchar keybuf[4][4] = { //���󰴼�ɨ�軺����
        {0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF},
        {0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}
    };
    
    TH0 = 0xFC; //���¼��س�ֵ1ms
    TL0 = 0x66;
    
    /*�����*/
    flags++;
    if(flags == 5) {    //5ms
        flags = 0;
        display(keyvalue);    //����ܶ�̬ɨ��
    }
    
    /*���������°���״̬*/
    //��һ�е� 4 ������ֵ���뻺����
    keybuf[keyout][0] = (keybuf[keyout][0] << 1) | KEY_IN_1;
    keybuf[keyout][1] = (keybuf[keyout][1] << 1) | KEY_IN_2;
    keybuf[keyout][2] = (keybuf[keyout][2] << 1) | KEY_IN_3;
    keybuf[keyout][3] = (keybuf[keyout][3] << 1) | KEY_IN_4;
    //��������°���״̬
    for (m = 0; m < 4; m++){ //ÿ�� 4 ������������ѭ�� 4 ��
        if ((keybuf[keyout][m] & 0x0F) == 0x00){    //���� 4 ��ɨ��ֵΪ 0���� 4*4ms �ڶ��ǰ���״̬ʱ������Ϊ�������ȶ��İ���
            KeySta[keyout][m] = 0;
        }
        else if ((keybuf[keyout][m] & 0x0F) == 0x0F){    //���� 4 ��ɨ��ֵΪ 1���� 4*4ms �ڶ��ǵ���״̬ʱ������Ϊ�������ȶ��ĵ���
            KeySta[keyout][m] = 1;
        }
    }
    
    /*���о��󰴼�ɨ��*/
    //ִ����һ�ε�ɨ�����
    keyout++; //�����������
    keyout = keyout & 0x03; //����ֵ�ӵ� 4 ������
    switch (keyout){ //�����������ͷŵ�ǰ������ţ������´ε��������
        case 0: KEY_OUT_4 = 1; KEY_OUT_1 = 0; break;
        case 1: KEY_OUT_1 = 1; KEY_OUT_2 = 0; break;
        case 2: KEY_OUT_2 = 1; KEY_OUT_3 = 0; break;
        case 3: KEY_OUT_3 = 1; KEY_OUT_4 = 0; break;
        default: break;
 }
}