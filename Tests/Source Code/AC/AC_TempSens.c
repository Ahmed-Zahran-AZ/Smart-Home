/*
 * AC_TempSens.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Eng Mahmoud Dardery
 */

#include <avr/io.h>
#include <avr/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_Interface.h"
#include "LCD.h"
#include "ADC.h"
#include "AC_TempSens.h"

u16 Local_DigitaValue ;
u16 Local_AnalogValue ;
u16 TempValue;

u16 Local_DigitaValue_LDR ;
//u16 Local_AnalogValue_LDR ;



void Ac_Control(void)
{
	LCD_VidCLR();
	Local_DigitaValue=ADC_U16GetDigitalValue(CHANNEL_0);
	/* 5000 is a refrence voltage in mili volt cause reslution of sensor in mv */
	/* UL is  unsigned long */
	Local_AnalogValue=(u16)((Local_DigitaValue*5000UL)/1024); /*calculate resolution*/
	TempValue= Local_AnalogValue/10; /*cause resolution of lm35 is 10 mv/c*/

	LCD_VidSendStringPos("TempValue=",1,1);
	LCD_VidSendNumberPos(TempValue,1,11);

	_delay_ms(1000);
	//LCD_VidCLR();
	//_delay_ms(20);
	if(TempValue>24)
	{
		DIO_VidSetPinValue(PORT_C,PIN_4,DIO_HIGH);

	}
	else
		DIO_VidSetPinValue(PORT_C,PIN_4,DIO_LOW);


}


void Ldr_Control(void)
{
	LCD_VidSendNumberPos(ADC_U16GetDigitalValue(CHANNEL_1),2,1);
	_delay_ms(1000);
}







