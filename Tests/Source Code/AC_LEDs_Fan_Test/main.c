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

#include "UART.h"
#include "UART_PROJ.h"


void main(void)
{
	while(1)
	{
	control();
	Ac_Control();
	Ldr_Control();
	}
}

