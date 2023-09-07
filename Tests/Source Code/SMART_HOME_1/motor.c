#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_Interface.h"
#include <avr/delay.h>
#include <avr/io.h>

#include "LCD.h"
#include "motor.h"



void Motor(void)
{
	DIO_VidSetPortDirection(PORT_A,0xf0);
  u8 k =0,j=0,p=0;

  for(j;j<1;j++)   // for starting in close mode      // for loop with one iteration cause i adjust motor step with 90 dgree per step
      	{
      	DIO_VidSetPinValue(PORT_A,PIN_4,1);
  		DIO_VidSetPinValue(PORT_A,PIN_5,0);
  		DIO_VidSetPinValue(PORT_A,PIN_6,0);
  		DIO_VidSetPinValue(PORT_A,PIN_7,1);
  		_delay_ms(20);

      	}
  LCD_VidSendStringPos("Door opening ..",2,1);
  _delay_ms(100);

	for(k;k<1;k++)    // open mode
	{
		DIO_VidSetPinValue(PORT_A,PIN_4,1);
		DIO_VidSetPinValue(PORT_A,PIN_5,1);
		DIO_VidSetPinValue(PORT_A,PIN_6,0);
		DIO_VidSetPinValue(PORT_A,PIN_7,0);
		_delay_ms(20);

	}
	LCD_VidSendStringPos("CLOSE SOON ..",2,1);

	_delay_ms(2000);

    for(p;p<1;p++)     //close mode after half second
    	{
    	DIO_VidSetPinValue(PORT_A,PIN_4,1);
		DIO_VidSetPinValue(PORT_A,PIN_5,0);
		DIO_VidSetPinValue(PORT_A,PIN_6,0);
		DIO_VidSetPinValue(PORT_A,PIN_7,1);
		_delay_ms(20);

    	}
    LCD_VidSendStringPos("Door Closed ..",2,1);



}



