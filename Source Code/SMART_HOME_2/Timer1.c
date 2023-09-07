

#include <avr/io.h>
#include "BIT_MATH.h"

void TIMER1_VidInit(void){
	SET_BIT(TCCR1A,COM1B1);
	SET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);

	/*Fast PWM (10-Bit), Prescalar = 8*/
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,CS11);

}


void PWM_SetDutyCycle(uint16_t dutyCycle) {
    OCR1B = dutyCycle; // Set PWM duty cycle
}
