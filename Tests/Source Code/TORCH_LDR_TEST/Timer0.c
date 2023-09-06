#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"

#include <avr/interrupt.h>
#include "Timer0.h"

static void (*TIMER0_PF_OVF)(void);
static void (*TIMER0_PF_COMP)(void);


void Timer0_VidTimer0_OVF(void)
{
	/*normal mode */
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);

	/*overflow interrupt*/
	SET_BIT(TIMSK,TOIE0);

    /*counter every rise edge */
	TCNT0=192;

	/* CLK / 8 */
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
}


void Timer0_SetCallBack(void (*Copy_VidPtr)(void))
{
 TIMER0_PF_OVF=Copy_VidPtr;

}

void Timer0_VidTimer_COMPMATCH(void)

{
	/*CTC MODE*/
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/*Enable interrupt */
	SET_BIT(TIMSK,OCIE0);

	OCR0=250;

	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);


}

void Timer0_SetCallBack_COMP(void (*Copy_VidPtr)(void))
{
	TIMER0_PF_COMP=Copy_VidPtr;

}


/*ISR(TIMER0_COMP_vect)
{

	static u16 Local_U16Counter=0;
		Local_U16Counter++;
		if(Local_U16Counter == 4000) //for 1 second
		{
			TIMER0_PF_COMP();
			Local_U16Counter=0;



		}
}*/

//******** pwm for controlling led intensity  ***************
ISR(TIMER0_COMP_vect)
{

	static u16 Local_U16Counter=0;
		Local_U16Counter++;
		/* 15 TON  5 TOFF*/
		if(Local_U16Counter == 1) //for 1 second
		{
			DIO_VidSetPinValue(PORT_B,PIN_3,DIO_HIGH);


		}
		else if(Local_U16Counter == 20)
		{
			DIO_VidSetPinValue(PORT_B,PIN_3,DIO_LOW);
			Local_U16Counter=0;
		}
}

//****************************************************

ISR(TIMER0_OVF_vect)
{
	static u16 Local_U16Counter=0;
	Local_U16Counter++;
	if(Local_U16Counter == 3907) //for 1 second
	{
		TIMER0_PF_OVF();
		Local_U16Counter=0;
		TCNT0=192;


	}
}
