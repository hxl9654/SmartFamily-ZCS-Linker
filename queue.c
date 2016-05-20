#include "stc15.h"
#define QUEUEDATALENTH 50

float xdata UQueue_Data[QUEUEDATALENTH] = {0};
float xdata UQueue1_Data[10] = {0};
unsigned char UQueue_Data_Index = 0;
unsigned char UQueue1_Data_Index = 0;
void UQueue_In(float dat)
{
	UQueue_Data[UQueue_Data_Index] = dat;
	UQueue_Data_Index++;
	if(UQueue_Data_Index >= QUEUEDATALENTH)
		UQueue_Data_Index = 0;
}
float UQueue_Out()
{
    unsigned char i = 0;
	double temp = 0;
    for(i = 0; i < QUEUEDATALENTH; i++)
        temp += UQueue_Data[i];  
	
	UQueue1_Data[UQueue1_Data_Index] = temp / QUEUEDATALENTH;
	UQueue1_Data_Index++;
	if(UQueue1_Data_Index >= 10)
		UQueue1_Data_Index = 0;
	
	temp = 0;
	for(i = 0; i < 10; i++)
		if(UQueue1_Data[i] != 0)
			temp += UQueue1_Data[i];
		else return 220;
	
	return temp / 10;
}

float xdata I1Queue_Data[QUEUEDATALENTH] = {0};
unsigned char I1Queue_Data_Index = 0;
void I1Queue_In(float dat)
{
	I1Queue_Data[I1Queue_Data_Index] = dat;
	I1Queue_Data_Index++;
	if(I1Queue_Data_Index >= QUEUEDATALENTH)
		I1Queue_Data_Index = 0;
}
float I1Queue_Out()
{
    unsigned char i = 0;
	double temp = 0;
    for(i = 0; i < QUEUEDATALENTH; i++)
        temp += I1Queue_Data[i];  
	if(temp / QUEUEDATALENTH < 0.08)
		return 0;
	else return temp / QUEUEDATALENTH - 0.08;
}

float xdata I2Queue_Data[QUEUEDATALENTH] = {0};
unsigned char I2Queue_Data_Index = 0;
void I2Queue_In(float dat)
{
	I2Queue_Data[I2Queue_Data_Index] = dat;
	I2Queue_Data_Index++;
	if(I2Queue_Data_Index >= QUEUEDATALENTH)
		I2Queue_Data_Index = 0;
}
float I2Queue_Out()
{
    char i = 0;
	double temp = 0;
    for(i = 0; i < QUEUEDATALENTH; i++)
        temp += I2Queue_Data[i];  
	if(temp / QUEUEDATALENTH < 0.08)
		return 0;
	else return temp / QUEUEDATALENTH - 0.08;
}

unsigned short xdata UdQueue_Data[QUEUEDATALENTH] = {0};
unsigned char UdQueue_Data_Index = 0;
void UdQueue_In(unsigned short dat)
{
	UdQueue_Data[UdQueue_Data_Index] = dat;
	UdQueue_Data_Index++;
	if(UdQueue_Data_Index >= QUEUEDATALENTH)
		UdQueue_Data_Index = 0;
}
unsigned short UdQueue_Out()
{
    unsigned char i = 0;
	long temp = 0;
    for(i = 0; i < QUEUEDATALENTH; i++)
        temp += UdQueue_Data[i];  
	return temp / QUEUEDATALENTH;
}

unsigned short xdata I1mQueue_Data[QUEUEDATALENTH] = {0};
unsigned char I1mQueue_Data_Index = 0;
void I1mQueue_In(unsigned short dat)
{
	I1mQueue_Data[I1mQueue_Data_Index] = dat;
	I1mQueue_Data_Index++;
	if(I1mQueue_Data_Index >= QUEUEDATALENTH)
		I1mQueue_Data_Index = 0;
}
unsigned short I1mQueue_Out()
{
    unsigned char i = 0;
	long temp = 0;
    for(i = 0; i < QUEUEDATALENTH; i++)
        temp += I1mQueue_Data[i];  
	return temp / QUEUEDATALENTH;
}

unsigned short xdata I2mQueue_Data[QUEUEDATALENTH] = {0};
unsigned char I2mQueue_Data_Index = 0;
void I2mQueue_In(unsigned short dat)
{
	I2mQueue_Data[I2mQueue_Data_Index] = dat;
	I2mQueue_Data_Index++;
	if(I2mQueue_Data_Index >= QUEUEDATALENTH)
		I2mQueue_Data_Index = 0;
}
unsigned short I2mQueue_Out()
{
    char i = 0;
	long temp = 0;
    for(i = 0; i < QUEUEDATALENTH; i++)
        temp += I2mQueue_Data[i];  
	return temp / QUEUEDATALENTH;
}
void Queue_Reset()
{
	UQueue_Data_Index = 0;
	I1Queue_Data_Index = 0;
	I2Queue_Data_Index = 0;
	UdQueue_Data_Index = 0;
	I1mQueue_Data_Index = 0;
	I2mQueue_Data_Index = 0;
}