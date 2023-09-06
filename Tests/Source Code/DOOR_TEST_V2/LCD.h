#ifndef LCD_H_
#define LCD_H_

#define LCD_DATA_PORT	PORT_C
#define LCD_CMD_PORT	PORT_D


#define RS		PIN_5
#define RW		PIN_6
#define EN		PIN_7

#define 	LCD_FUNC_SET 			0b00111000
#define 	LCD_ONOF 				0b00001111
#define  	LCD_CLEAR 				0b00000001

#define 	LCD_U8_LINE1 			0
#define 	LCD_U8_LINE2 			1

#define ROW1     1
#define ROW2     2


void LCD_VidSendCMD(u8 Copy_U8CMD);
void LCD_VidSendData(u8 Copy_U8Data);
void LCD_VidSendString(u8 *Copy_U8String);
void LCD_VidCLR(void);
void LCD_VidSendNumber(u32 Copy_u32Number);
void LCD_VidSendCharPos(u8 Copy_U8Char,u8 Copy_U8Row,u8 Copy_U8Coulmn);
void LCD_VidSetCursorPos(u8 Copy_U8Row,u8 Copy_U8Coulmn);
void LCD_VidSendNumberPos(u32 Copy_u32Number,u8 Copy_U8Row,u8 Copy_U8Coulmn);


#endif
