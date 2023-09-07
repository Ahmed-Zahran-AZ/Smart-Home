#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <avr/io.h>
#include "UART.h"


void UART_VidInit(void)
{
	u16 Local_u16USCRC=0b10000000;
	/*Baud rate*/
	u16 LocalU16BaudRate=51;

	UBRRL=(u8)LocalU16BaudRate;
	UBRRH=(u8)(LocalU16BaudRate>>8);

	/*normal speed*/
	CLR_BIT(UCSRA,U2X);

	/*multiprocessor disable*/
	CLR_BIT(UCSRA,MPCM);

	/*enable tx   rx*/
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);


	/*Select 8 bit mode*/
	SET_BIT(Local_u16USCRC,UCSZ0);
	SET_BIT(Local_u16USCRC,UCSZ1);
	CLR_BIT(UCSRB,UCSZ2);

	/*Asynchronos*/
	CLR_BIT(Local_u16USCRC,UMSEL);

	/*PARITY MODE DISABLE*/
	CLR_BIT(Local_u16USCRC,UPM0);
	CLR_BIT(Local_u16USCRC,UPM1);

	/*STOP*/
	SET_BIT(Local_u16USCRC,USBS);

	UCSRC=Local_u16USCRC;





}





void UART_VidSendData(u16 Copy_U16Data)
{
	/*wait to empty shift register ---- datasheet*/
	while(GET_BIT(UCSRA,UDRE)==0);
	UDR=(u8)Copy_U16Data;
}



u8 UART_VidReciveData(void)
{
	/*wait TILL RECIEVE COMPLETE ---- datasheet*/
	while(GET_BIT(UCSRA,RXC)==0);
	return UDR;
}




void UART_VidSend_String(u8 *Copy_U8ptr)
{
	 u8 Local_u8Counter=0;
	for	(Local_u8Counter;Copy_U8ptr[Local_u8Counter] !='\0' ;Local_u8Counter++)
	{
		UART_VidSendData(Copy_U8ptr[Local_u8Counter]);
	}

}
