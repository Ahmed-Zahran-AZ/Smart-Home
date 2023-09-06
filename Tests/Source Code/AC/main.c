/*
 * main.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Eng Mahmoud Dardery
 */
#include <avr/io.h>
#include <avr/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "AC_TempSens.h"
#include "LCD.h"
#include "ADC.h"
#include "UART.h"
#include "UART_PROJ.h"


void main(void)
{
	DIO_VidSetPinDirection(PORT_C,PIN_4,DIO_OUTPUT);
	DIO_VidSetPinDirection(PORT_A,PIN_1,DIO_INPUT);
	DIO_VidSetPinDirection(PORT_A,PIN_0,DIO_INPUT);
	LCD_VidInit();
	ADC_VidInit();
	while(1)
	{
	//control();
	LCD_VidSendNumberPos(ADC_U16GetDigitalValue(CHANNEL_1),2,1);
	Ac_Control();
	Ldr_Control();
	}
}

