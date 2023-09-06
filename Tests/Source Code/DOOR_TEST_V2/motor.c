#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_Interface.h"
#include <avr/delay.h>
#include <avr/io.h>

#include "motor.h"



void Motor(void)
{
	DIO_VidSetPortDirection(PORT_B,0xff);
  u8 k =0,j=0;
	for(k;k<1;k++)
	{
		DIO_VidSetPinValue(PORT_B,PIN_0,1);
		DIO_VidSetPinValue(PORT_B,PIN_1,1);
		DIO_VidSetPinValue(PORT_B,PIN_2,0);
		DIO_VidSetPinValue(PORT_B,PIN_3,0);
		_delay_ms(20);

	}

	_delay_ms(2000);

    for(j;j<1;j++)
    	{
    	DIO_VidSetPinValue(PORT_B,PIN_0,1);
		DIO_VidSetPinValue(PORT_B,PIN_1,0);
		DIO_VidSetPinValue(PORT_B,PIN_2,0);
		DIO_VidSetPinValue(PORT_B,PIN_3,1);
		_delay_ms(20);

    	}



}



