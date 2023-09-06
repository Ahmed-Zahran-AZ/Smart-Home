/*
 * Internal_EEPROM.h
 *
 *  Created on: Sep 1, 2023
 *      Author: Eng Mahmoud Dardery
 */

#ifndef INTERNAL_EEPROM_H_
#define INTERNAL_EEPROM_H_


void EEPROM_VidWriteData(u16 Copy_u16address,u8 Copy_u8data);
u8 EEPROM_U8ReadData(u16 Copy_u16address);


#endif /* INTERNAL_EEPROM_H_ */
