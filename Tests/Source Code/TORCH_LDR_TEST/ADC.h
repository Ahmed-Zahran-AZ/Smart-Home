#ifndef ADC_H_
#define ADC_H_
#include "STD_TYPES.h"

#define CHANNEL_0 0
#define CHANNEL_1 1
#define CHANNEL_2 2
#define CHANNEL_3 3
#define CHANNEL_4 4
#define CHANNEL_5 5
#define CHANNEL_6 6
#define CHANNEL_7 7

#define ADC_REG  *((volatile u16*)0x24)

void ADC_VidInit(void);
u16 ADC_U16GetDigitalValue(u8 Copy_U8ChannelId);
#endif /* ADC_H_ */
