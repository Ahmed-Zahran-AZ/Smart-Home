/*
 * UART.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Eng Mahmoud Dardery
 */

#ifndef UART_H_
#define UART_H_

void UART_VidInit(void);
void UART_VidSendData(u16 Copy_U16Data);
u8 UART_VidReciveData(void);
void UART_VidSend_String(u8 *Copy_U8ptr);

#endif /* UART_H_ */
