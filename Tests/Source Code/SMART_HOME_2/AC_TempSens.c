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
;
	LCD_VidCLR();
	_delay_ms(3);

	Local_DigitaValue=ADC_U16GetDigitalValue(CHANNEL_0);
	/* 2560 is a refrence voltage in mili volt cause reslution of sensor in mv */
	/* UL is  unsigned long */
	Local_AnalogValue=(u16)((Local_DigitaValue*2560UL)/1024); /*calculate resolution*/
	TempValue= Local_AnalogValue/10; /*cause resolution of lm35 is 10 mv/c*/

	LCD_VidSendStringPos("TempValue=",1,1);
	LCD_VidSendNumberPos(TempValue,1,11);
	//_delay_ms(1000);
	//LCD_VidCLR();
	//_delay_ms(20);
	if(TempValue>24)
	{
		DIO_VidSetPinDirection(PORT_C,PIN_4,DIO_OUTPUT);
		DIO_VidSetPinValue(PORT_C,PIN_4,DIO_HIGH);

	}
	else
		DIO_VidSetPinValue(PORT_C,PIN_4,DIO_LOW);

	Ldr_Control();

}


void Ldr_Control(void)
{

	Local_DigitaValue_LDR=ADC_U16GetDigitalValue(CHANNEL_1);
	LCD_VidSendStringPos("LDR Read=",2,1);
	LCD_VidSendNumberPos(Local_DigitaValue_LDR,2,11);
	/*Controlling the three LEDs on C1,C2,C3*/
	if(Local_DigitaValue_LDR < 171){
		DIO_VidSetPinValue(PORT_D,PIN4,DIO_HIGH);
	}
	else{
		DIO_VidSetPinValue(PORT_D,PIN4,DIO_LOW);
	}
	_delay_ms(500);
}







