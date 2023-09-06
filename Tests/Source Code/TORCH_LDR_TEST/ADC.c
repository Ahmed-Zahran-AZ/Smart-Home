#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC.h"

void ADC_VidInit(void)
{
	/* select AVCC (+5V) */

	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);

	/* Right adjust*/
	CLR_BIT(ADMUX,ADLAR);

	/* Auto Trigger DIS */

	CLR_BIT(ADCSRA,ADATE);
	/*  ADC PRESSCALER 
	* By default, the successive approximation circuitry requires an input clock frequency between 50kHz and 200kHz to
	* get maximum resolution.
	*/
	CLR_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);

	/* ADC ENABLE */
	SET_BIT(ADCSRA,ADEN);
}

u16 ADC_U16GetDigitalValue(u8 Copy_U8ChannelId)

{ 
	 u16 Local_U16DigitalValue;

	/* Clear MUX4----0*/
  ADMUX&=0b11100000;

  /* select channel*/
  ADMUX|=Copy_U8ChannelId;
/* start conversion */
  SET_BIT(ADCSRA,ADSC);

  while(!GET_BIT(ADCSRA,ADIF));

  Local_U16DigitalValue=ADC_REG;
  return Local_U16DigitalValue;

}























