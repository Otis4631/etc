//***********************************************************************
//               MSP430����ͷ�ļ�
//***********************************************************************
#include <msp430x14x.h>


void LED8Port_Init()
{
  P6SEL=0x00;                    //����IO��Ϊ��ͨI/Oģʽ
  P6DIR = 0xff;                  //����IO�ڷ���Ϊ���
  P6OUT = 0xff;                  //��ʼ����Ϊ00
}

/********************************************************************
				LEDָ��λ��ʾ����
********************************************************************/
void LED_Runing(unsigned char LED_NUM)
{
	switch(LED_NUM)
	{
        case 0:
          LED8 &= ~(1<<0);  //����D1��
          break;
        case 1:
          LED8 &= ~(1<<1);  //����D2��
          break;
        case 2:
          LED8 &= ~(1<<2);  //����D3��
          break;
        case 3:
          LED8 &= ~(1<<3);  //����D4��
          break; 
        case 4:
          LED8 &= ~(1<<4);  //����D5��
          break;
        case 5:
          LED8 &= ~(1<<5);  //����D6��
          break;
        case 6:
          LED8 &= ~(1<<6);  //����D7��
          break;
        case 7:
          LED8 &= ~(1<<7);  //����D8��
          break;				
        default:
          LED8 = 0x00;     //�������е�LED��
          break;
	}
}
/********************************************************************
				LED��ˮ��ʾ����
********************************************************************/
void LED8_Run_1Time(void)
{ 
  uchar count,i;
  count = 0x00;
  LED8Port_Init();                          //�˿ڳ�ʼ�������ڿ���IO����������
  for(i=0;i<8;i++)
  {
    LED8 = 0xFF; 
    LED_Runing(count%8);											//����һ��LED��		
    count++;
    delay_ms(2);
  }
  LED8 = 0xFF;
 
}
/********************************************************************
				LEDȫ����˸��ʾ����
********************************************************************/
void LED8_8(void)
{ 
  uchar count,i;
  count = 0x00;
  LED8Port_Init();                          //�˿ڳ�ʼ�������ڿ���IO����������
  for(i=0;i<3;i++)
  {
    LED8 = 0x00;
    delay_ms(500);
    LED8 = 0xFF;
    delay_ms(500);
  }
}

//***********************************************************************
//      2��LED��˸5�β��Գ���
//***********************************************************************
void LED_Glow3Times(void)
{ 
  uchar j;
  
  LED8Port_Init();                        //�˿ڳ�ʼ�������ڿ���IO����������
  for(j=0;j<3;j++)
  {
    LED8=0x00;                        //����LED
    delay_ms(500);
    LED8=0xff;                        //Ϩ��LED
    delay_ms(500);
  }
}