#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include<avr/io.h>
#include<avr/delay.h>

#include"DIO_Interface.h"
#include"LCD.h"


void LCD_VidSendCMD(u8 Copy_U8CMD)
{
	DIO_VidSetPinValue(LCD_CMD_PORT,RS,0);
	
	DIO_VidSetPinValue(LCD_CMD_PORT,RW,0);
	
	DIO_VidSetPortValue(LCD_DATA_PORT,Copy_U8CMD);
	
	DIO_VidSetPinValue(LCD_CMD_PORT,EN,1);
	
	_delay_ms(1);
	
	DIO_VidSetPinValue(LCD_CMD_PORT,EN,0);
}



void LCD_VidSendData(u8 Copy_U8Data)
{
	DIO_VidSetPinValue(LCD_CMD_PORT,RS,1);
	
	DIO_VidSetPinValue(LCD_CMD_PORT,RW,0);
	
	DIO_VidSetPortValue(LCD_DATA_PORT,Copy_U8Data);
	
	DIO_VidSetPinValue(LCD_CMD_PORT,EN,1);
	
	_delay_ms(1);
	
	DIO_VidSetPinValue(LCD_CMD_PORT,EN,0);
}


void LCD_SendString(u8 *Copy_U8Data)
{


	DIO_VidSetPinValue(LCD_CMD_PORT,RS,1);

	DIO_VidSetPinValue(LCD_CMD_PORT,RW,0);

	for(u8 Local_Counter=0;Copy_U8Data[Local_Counter]!='\0';Local_Counter++)
		{
			LCD_VidSendData(Copy_U8Data[Local_Counter]);
		}

	DIO_VidSetPinValue(LCD_CMD_PORT,EN,1);

	_delay_ms(1);

	DIO_VidSetPinValue(LCD_CMD_PORT,EN,0);

}


void LCD_VidSendString(u8 *Copy_U8String)
{
	u8 counter = 0 ;
	while(Copy_U8String[counter] !='\0')
	{
		LCD_VidSendData(Copy_U8String[counter]);
		counter++;
	}
}








void LCD_VidInit(void)
{
	DIO_VidSetPortDirection(LCD_DATA_PORT,0xff);

	DIO_VidSetPinDirection(LCD_CMD_PORT,RS,DIO_OUTPUT);
	DIO_VidSetPinDirection(LCD_CMD_PORT,RW,DIO_OUTPUT);
	DIO_VidSetPinDirection(LCD_CMD_PORT,EN,DIO_OUTPUT);

	_delay_ms(35);
	LCD_VidSendCMD(LCD_FUNC_SET);
	_delay_ms(1);
	LCD_VidSendCMD(LCD_ONOF);
	_delay_ms(1);
	LCD_VidSendCMD(LCD_CLEAR);
	_delay_ms(1);

}

void LCD_VidCLR(void)
{

	LCD_VidSendCMD(0x01);
	_delay_ms(2);
}



void LCD_VidSendNumber(u32 Copy_u32Number)
{
	u32 Local_u32Counter=1 , Local_u32Digit=0;

	if (Copy_u32Number == 0)
		LCD_VidSendData('0');
	else
	{
		while (Copy_u32Number/Local_u32Counter != 0)
		{
			Local_u32Counter *= 10;
		}
		Local_u32Counter /=10;

		while (Local_u32Counter != 0)
		{
			Local_u32Digit = Copy_u32Number/Local_u32Counter;

			LCD_VidSendData(Local_u32Digit + '0');

			Copy_u32Number = Copy_u32Number%Local_u32Counter;

			Local_u32Counter /= 10;
		}
	}
}

void LCD_VidSendNumberPos(u32 Copy_u32Number,u8 Copy_U8Row,u8 Copy_U8Coulmn)
{
	LCD_VidSetCursorPos(Copy_U8Row,Copy_U8Coulmn);
	LCD_VidSendNumber(Copy_u32Number);
}


void LCD_VidSetCursorPos(u8 Copy_U8Row,u8 Copy_U8Coulmn)
{
	Copy_U8Coulmn -- ;
	switch (Copy_U8Row)
	{
	case ROW1 :LCD_VidSendCMD((0x80 + Copy_U8Coulmn)); break;
	case ROW2 :LCD_VidSendCMD((0xc0 + Copy_U8Coulmn)); break;
	default : ;
	}


}

void LCD_VidSendCharPos(u8 Copy_U8Char,u8 Copy_U8Row,u8 Copy_U8Coulmn)
{
	LCD_VidSetCursorPos(Copy_U8Row,Copy_U8Coulmn);
	LCD_VidSendData(Copy_U8Char);
}


void LCD_VidSendStringPos(u8 *Copy_U8String,u8 Copy_U8Row,u8 Copy_U8Coulmn)
{
	LCD_VidSetCursorPos(Copy_U8Row,Copy_U8Coulmn);
	LCD_VidSendString(Copy_U8String);
}




