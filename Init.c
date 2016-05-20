#include<stc15.h>
#include<uart.h>
#include<adc.h>
#include<queue.h>
void IOPort_Init()
{
	P0M0 = 0x00; P0M1 = 0x00;
	P1M0 = 0x00; P1M1 = 0x00;
	P2M0 = 0x00; P2M1 = 0x00;
	P3M0 = 0x00; P3M1 = 0x00;
	P4M0 = 0x00; P4M1 = 0x00;
	P5M0 = 0x00; P5M1 = 0x00;
}
void Timer2Init(void)		//1����@27.000MHz
{
	AUXR |= 0x04;		//��ʱ��ʱ��1Tģʽ
	T2L = 0x88;		//���ö�ʱ��ֵ
	T2H = 0x96;		//���ö�ʱ��ֵ
	AUXR |= 0x10;		//��ʱ��2��ʼ��ʱ
	IE2 |= 0x04;
	EA = 1;
}
void Timer0Init(void)		//20����@27.000MHz
{
	AUXR &= 0x7F;		//��ʱ��ʱ��12Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TL0 = 0x38;		//���ö�ʱ��ֵ
	TH0 = 0x50;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	ET0 = 1;
	PT0 = 1;
	EA = 1;
}
void SystemInit()
{
	IOPort_Init();
	Uart_Init();
	ADC_Init();
	Timer0Init();
	Timer2Init();
	Queue_Reset();
}