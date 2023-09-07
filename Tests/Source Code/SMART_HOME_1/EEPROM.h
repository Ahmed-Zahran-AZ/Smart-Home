/*
 * EEPROM.h
 *
 *  Created on: Aug 27, 2023
 *      Author: Eng Mahmoud Dardery
 */

#ifndef EEPROM_H_
#define EEPROM_H_


#define UNIQUE_ADDRESS      0b10100000      //0b10100000    //0x50

/*Select EEPROM*/
/* 0 or 1 */
#define A2     0


void EEPROM_VidWriteByte(u16 Copy_U16ByteAddress, u8 Copy_U8Data);
u8 EEPROM_VidReadByte(u16 Copy_U16ByteAddress);


#endif /* EEPROM_H_ */
