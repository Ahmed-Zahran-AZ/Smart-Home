/*
 * Internal_EEPROM.c
 *
 *  Created on: Sep 1, 2023
 *      Author: Eng Mahmoud Dardery
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "Internal_EEPROM.h"



void EEPROM_VidWriteData(u16 Copy_u16address,u8 Copy_u8data)
{
	/*wait until EEWE Becomes 0*/
	while(GET_BIT(EECR,EEWE));
   /*wait until that bit becomes 0*/
	while(GET_BIT(SPMCR,SPMEN));

	/*Write new EEPROM address to EEAR (optional)*/
	EEARL=(u8) Copy_u16address;
	EEARH=(u8)(Copy_u16address>>8);
	/*Write new EEPROM address to EEDR (optional)*/
	EEDR=Copy_u8data;

	/* Write a logical one to the EEMWE bit while writing a zero to EEWE in EECR*/
	SET_BIT(EECR,EEMWE);

	/*start eeprom write operation*/
	SET_BIT(EECR,EEWE);



	/* Within four clock cycles after setting EEMWE, write a logical one to EEWE*/

	/*wait 4 cycles until reading finished*/
	while(GET_BIT(EECR,EEMWE));



}




u8 EEPROM_U8ReadData(u16 Copy_u16address)
{
	u8 Data=0;

	while(GET_BIT(EECR,EEWE));

	/*Write new EEPROM address to EEAR (optional)*/
	EEARL=(u8) Copy_u16address;
	EEARH=(u8)(Copy_u16address>>8);

	/*start eeprom read operation*/
	SET_BIT(EECR,EERE);

	Data = EEDR;
	return Data;

}







/*function to return value from address in eeprom */

u8 EEPROM_u8CheckValueofAddress(u16 Copy_u16Address)
{
	u8 value =0;
	value = EEPROM_U8ReadData(Copy_u16Address);
	return value;

}

