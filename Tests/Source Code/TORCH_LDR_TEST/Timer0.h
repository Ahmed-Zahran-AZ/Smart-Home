/*
 * Timer0.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Eng Mahmoud Dardery
 */

#ifndef TIMER0_H_
#define TIMER0_H_

void Timer0_VidTimer0_OVF(void);
void Timer0_SetCallBack(void (*Copy_VidPtr)(void));
void Timer0_VidTimer_COMPMATCH(void);

#define ADC_REG  *((volatile u16*)0x24)
#endif /* TIMER0_H_ */
