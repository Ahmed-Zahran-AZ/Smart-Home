/*
 * main.c
 *
 * Author: Ahmed Zahran
 */
#include "LCD.h"
#include "ADC.h"
#include "DIO.h"
#include <util/delay.h>

void main(void){
	LCD_VidInit();
	ADC_VidInit();

	while(1){
		_delay_ms(3);
		LCD_VidSendString("LIGHT: ");
		LCD_VidSendNum(ADC_U16GetDigitalValue(CHANNEL_0));
		_delay_ms(100);
		LCD_VidSendCMD(LCD_CLR);
	}

}
