/*
 * UART_PROJ.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Eng Mahmoud Dardery
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "avr/io.h"
#include "avr/delay.h"
#include <avr/interrupt.h>
#include "UART.h"
#include "UART_PROJ.h"
//#include "AC_TempSens.h"



u8 Local_Data_UART =9;



ISR(USART_RXC_vect){
		Local_Data_UART = UDR;
	DIO_VidSetPortDirection(PORT_C,0b00001111);

	if(Local_Data_UART != 9)
		{
		if(Local_Data_UART == 'F')
		{
			DIO_VidSetPinValue(PORT_C,PIN_0,DIO_HIGH);
			UART_VidSend_String("Fan ON");
		}
		else if(Local_Data_UART == 'f')
		{
			DIO_VidSetPinValue(PORT_C,PIN_0,DIO_LOW);
			UART_VidSend_String("Fan OFF");
		}

		else if(Local_Data_UART == '1')
		{
			DIO_VidSetPinValue(PORT_C,PIN_1,DIO_HIGH);
			DIO_VidSetPinValue(PORT_C,PIN_2,DIO_LOW);		/*<-*/
			DIO_VidSetPinValue(PORT_C,PIN_3,DIO_LOW);
		}
		else if(Local_Data_UART == '2')
		{
			DIO_VidSetPinValue(PORT_C,PIN_1,DIO_HIGH);
			DIO_VidSetPinValue(PORT_C,PIN_2,DIO_HIGH);
			DIO_VidSetPinValue(PORT_C,PIN_3,DIO_LOW);
		}
		else if(Local_Data_UART == '3')
		{
			DIO_VidSetPinValue(PORT_C,PIN_1,DIO_HIGH);
			DIO_VidSetPinValue(PORT_C,PIN_2,DIO_HIGH);
			DIO_VidSetPinValue(PORT_C,PIN_3,DIO_HIGH);

		}

		else if(Local_Data_UART == '0')
		{
			DIO_VidSetPortValue(PORT_C,0b00000000);
		}

		else
		{
			DIO_VidSetPortValue(PORT_C,0b00000000);
		}

		}
		else
		{
			DIO_VidSetPortValue(PORT_C,0b00000000);
		}



}
