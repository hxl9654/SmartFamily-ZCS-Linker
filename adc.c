#include<stc15.h>
#include<data.h>
void ADC_Init()
{
    P1ASF = 0xFF;                   //设置P1口为AD口
	EADC = 1;
	EA = 1;
	PADC = 1;
    ADC_CONTR = 0x88;
}

void Interrupt_ADC() interrupt 5
{
	unsigned short ADCResult = 0;
	static unsigned char Channel = 0;
	ADCResult = (((short)ADC_RES) << 2) | ADC_RESL;
	switch(Channel)
	{
		case(0): Channel = 1; ADC_CONTR = 0x88 | Channel; I1_Insert(ADCResult); break;
		case(1): Channel = 2; ADC_CONTR = 0x88 | Channel; I2_Insert(ADCResult); break;
		case(2): Channel = 3; ADC_CONTR = 0x88 | Channel; U_Insert (ADCResult); break;
		case(3): 
		case(4): 
		case(5): 
		case(6): 
		case(7): 
		case(8): ADC_CONTR = 0x88; Channel++;   break;
		case(9): ADC_CONTR = 0x88; Channel = 0; break;		
		default: ADC_CONTR = 0x88; Channel = 0; break;
	}
}