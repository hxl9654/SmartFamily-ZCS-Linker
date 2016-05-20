#ifndef _QUEUE_H_
#define _QUEUE_H_

void UQueue_In(float dat);
float UQueue_Out();

void I1Queue_In(float dat);
float I1Queue_Out();

void I2Queue_In(float dat);
float I2Queue_Out();

void UdQueue_In(unsigned short dat);
unsigned short UdQueue_Out();

void I1mQueue_In(unsigned short dat);
unsigned short I1mQueue_Out();

void I2mQueue_In(unsigned short dat);
unsigned short I2mQueue_Out();

void Queue_Reset();
#endif // _QUEUE_H_
