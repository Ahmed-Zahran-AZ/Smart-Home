/*
 * 1- select 2.56v
 * 2- right adjustment
 * 3- disable auto-triggering
 * 4-select 64
 * 5-enable adc
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <avr/io.h>
#include "ADC.h"

void ADC_VidInit(void)
{
	/* select 5 v */
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);

	/* right adjust */
	CLR_BIT(ADMUX,ADLAR);

	/* disable auto triggering */
	CLR_BIT(ADCSRA,ADATE);

	/* prescaler */
	CLR_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);

	/*ADC Enable*/
	SET_BIT(ADCSRA,ADEN);

}


u16 ADC_U16GetDigitalValue(u8 Copy_U8ChannelId)
{
	u16 Local_U16DigitalValue;
	/*clear MUX4..0*/
	ADMUX&=0b11100000;
	/* select channel */
	ADMUX|=Copy_U8ChannelId;
	/* start conversion */
	SET_BIT(ADCSRA,ADSC);

	/*bouling for making program stuck till flag be high*/
	while(!GET_BIT(ADCSRA,ADIF));

	Local_U16DigitalValue=ADC_REG;

	return   Local_U16DigitalValue;


}





