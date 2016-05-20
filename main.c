#include<stc15.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<uart.h>
#include<init.h>
#include<adc.h>
#include<config.h>
#include<queue.h>
#include<data.h>
volatile float _U = 0, _I1 = 0, _I2 = 0;
volatile float _I1dm = 0, _I2dm = 0;
volatile double _W1 = 0, _W2 = 0;
void UART_Action(unsigned char *dat, unsigned char len)
{	
	unsigned char str[3] = "00\n";
	unsigned char str1[20];
//UART_SendString(dat, len);
	if(len <= 1)
		return;

	if(len >= 5 && strncmp(dat, "C:S", 3) == 0)
	{
		if(dat[3] - '0')
			Relay1 = 0;
		else Relay1 = 1;
		if(dat[4] - '0')
			Relay2 = 0;
		else Relay2 = 1;
		
		UART_SendString("M:C.S:", 5);
		str[0] = '0' + (Relay1 ? 0:1);
		str[1] = '0' + (Relay2 ? 0:1);
		UART_SendString(str, 3);
	}
	else if(len >= 7 && strncmp(dat, "C:Inf.U", 7) == 0)
	{
		UART_SendString("M:C.U:", 5);
		sprintf(str1, "%.2f\n", _U);
		UART_SendString(str1, sizeof(str1));
	}
	else if(len >= 7 && strncmp(dat, "C:Inf.I", 7) == 0)
	{
		UART_SendString("M:C.I:", 5);
		sprintf(str1, "%.3f,%.3f\n", _I1, _I2);
		UART_SendString(str1, sizeof(str1));
	}
	else if(len >= 7 && strncmp(dat, "C:Inf.P", 7) == 0)
	{
		UART_SendString("M:C.P:", 5);
		sprintf(str1, "%.2f,%.2f\n", _I1 * _U, _I2 * _U);
		UART_SendString(str1, sizeof(str1));
	}
	else if(len >= 7 && strncmp(dat, "C:Inf.W", 7) == 0)
	{
		UART_SendString("M:C.W:", 5);
		sprintf(str1, "%.2f,%.2f\n", _W1, _W2);
		UART_SendString(str1, sizeof(str1));
	}
//	else if(len >= 7 && strncmp(dat, "C:Inf.D", 7) == 0)
//	{
//		UART_SendString("M:C.D:", 5);
//		sprintf(str1, "%.2f,%.2f\n", _I1dm, _I2dm);
//		UART_SendString(str1, sizeof(str1));
//	}
	else if(len >= 2 && strncmp(dat, "C:", 2) == 0)
	{
		//UART_SendString(dat, len);
		UART_SendString("N:C.SERR\n", 9);
	}
}
void main()
{
	SystemInit();
	while(1)
	{
		UART_Driver();
	}
}
void Interrupt_Timer0() interrupt 1
{
	static unsigned char Secend = 0;
	float U, I1, I2;
	unsigned short UMaxI, UMinI, I1MaxI, I1MinI, I2MaxI, I2MinI, Ud;	
	U = U_Value(&UMaxI, &UMinI);
	UQueue_In(U);
	UdQueue_In(abs(UMaxI - UMinI));
	
	I1 = I1_Value(&I1MaxI, &I1MinI);
	I1Queue_In(I1);
	I1mQueue_In(abs(I1MaxI - UMaxI));
	
	I2 = I2_Value(&I2MaxI, &I2MinI);
	I2Queue_In(I2);
	I2mQueue_In(abs(I2MaxI - UMaxI));
	
	Secend++;
	if(Secend >= 50)
	{
		Secend = 0;
		_U = UQueue_Out();
		_I1 = (_I1 + I1Queue_Out()) / 2;
		_I2 = (_I2 + I2Queue_Out()) / 2;
		Ud = UdQueue_Out();
		_I1dm = I1mQueue_Out() * 3.14 / Ud;
		if(_I1dm > 3.14)
			_I1dm -= 3.14;
		_I2dm = I2mQueue_Out() * 3.14 / Ud;
		if(_I2dm > 3.14)
			_I2dm -= 3.14;
				
		_W1 += _I1 * _U / 3600 / 1000;
		_W2 += _I2 * _U / 3600 / 1000;
	}
}
void Interrupt_Timer2() interrupt 12
{
	UART_RxMonitor(1);
}