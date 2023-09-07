/*
 * main.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Eng Mahmoud Dardery
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "avr/io.h"
#include "avr/delay.h"
#include "AC_TempSens.h"
#include "UART.h"
#include "UART_PROJ.h"
#include "Timer1.h"
void main(void) {
	DIO_VidSetPinDirection(PORT_D,PIN4,DIO_OUTPUT);
	TIMER1_VidInit();
	SET_BIT(SREG,7);
	SET_BIT(UCSRB,RXCIE);
	UART_VidInit();
	LCD_VidInit();
	ADC_VidInit();
	while (1) {
		Ac_Control();
		Ldr_Control();
	}
}

