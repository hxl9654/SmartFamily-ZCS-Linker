#include<stc15.h>
#define DATABUFFERLENTH 450
unsigned short xdata U_Buffer[DATABUFFERLENTH] = {0};
unsigned short xdata I1_Buffer[DATABUFFERLENTH] = {0};
unsigned short xdata I2_Buffer[DATABUFFERLENTH] = {0};
unsigned short U_Index = 0;
unsigned short I1_Index = 0;
unsigned short I2_Index = 0;
void U_Insert(unsigned short dat)
{
	if(U_Index == DATABUFFERLENTH)
		return ;
	U_Buffer[U_Index] = dat;
	U_Index++;
}
void I1_Insert(unsigned short dat)
{
	if(I1_Index == DATABUFFERLENTH)
		return ;
	I1_Buffer[I1_Index] = dat;
	I1_Index++;
}
void I2_Insert(unsigned short dat)
{
	if(I2_Index == DATABUFFERLENTH)
		return ;
	I2_Buffer[I2_Index] = dat;
	I2_Index++;
}
float U_Value(unsigned short *_MaxI, unsigned short *_MinI)
{
	unsigned short i;
	unsigned short Max = 0, Min = 9999, MaxI, MinI;
	float EFF;
	if(U_Index < DATABUFFERLENTH / 2)
		return 0;
	for(i = 0; i < U_Index; i++)
	{
		if(U_Buffer[i] > Max)
		{
			Max = U_Buffer[i];
			MaxI = i;
		}
		if(U_Buffer[i] < Min)
		{
			Min = U_Buffer[i];
			MinI = i;
		}
	}
	EFF = (float)(Max - Min) * 5000 / 1024 * 234 / 2046 * 3.35;
	*_MaxI = MaxI;
	*_MinI = MinI;
	U_Index = 0;
	return EFF;
}
float I1_Value(unsigned short *_MaxI, unsigned short *_MinI)
{
	unsigned short i;
	unsigned short Max = 0, Min = 9999, MaxI, MinI;
	float EFF;
	if(I1_Index < DATABUFFERLENTH / 2)
		return 0;
	for(i = 0; i < I1_Index; i++)
	{
		if(I1_Buffer[i] > Max)
		{
			Max = I1_Buffer[i];
			MaxI = i;
		}
		if(I1_Buffer[i] < Min)
		{
			Min = I1_Buffer[i];
			MinI = i;
		}
	}
	EFF = (float)(Max - Min) * 5000 / 1024 / 100 * 0.353 * 4;

	*_MaxI = MaxI;
	*_MinI = MinI;
	I1_Index = 0;
	return EFF;
}
float I2_Value(unsigned short *_MaxI, unsigned short *_MinI)
{
	unsigned short i;
	unsigned short Max = 0, Min = 9999, MaxI, MinI;
	float EFF;
	if(I2_Index < DATABUFFERLENTH / 2)
		return 0;
	for(i = 0; i < I2_Index; i++)
	{
		if(I2_Buffer[i] > Max)
		{
			Max = I2_Buffer[i];
			MaxI = i;
		}
		if(I2_Buffer[i] < Min)
		{
			Min = I2_Buffer[i];
			MinI = i;
		}
	}
	EFF = (float)(Max - Min) * 5000 / 1024 / 100 * 0.353 * 4;
	*_MaxI = MaxI;
	*_MinI = MinI;
	I2_Index = 0;
	return EFF;
}

	