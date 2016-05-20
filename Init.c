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
void Timer2Init(void)		//1毫秒@27.000MHz
{
	AUXR |= 0x04;		//定时器时钟1T模式
	T2L = 0x88;		//设置定时初值
	T2H = 0x96;		//设置定时初值
	AUXR |= 0x10;		//定时器2开始计时
	IE2 |= 0x04;
	EA = 1;
}
void Timer0Init(void)		//20毫秒@27.000MHz
{
	AUXR &= 0x7F;		//定时器时钟12T模式
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0x38;		//设置定时初值
	TH0 = 0x50;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
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