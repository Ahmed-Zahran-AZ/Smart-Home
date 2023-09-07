/*
 * main.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Eng Mahmoud Dardery
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/io.h>
#include <avr/delay.h>

#include "DIO_Interface.h"

#include "LCD.h"
#include "KPD.h"
#include "I2c.h"
#include "EEPROM.h"
#include "motor.h"
#include "EXT_EE_DOOR_TEST.h"


void main()
{
	DIO_VidSetPinDirection(PORT_A,PIN_3,DIO_OUTPUT);
	DOOR_Control();
	while(1);
}
