#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <avr/delay.h>
#include <avr/io.h>
#include "I2c.h"
#include "EEPROM.h"


void EEPROM_VidWriteByte(u16 Copy_U16ByteAddress, u8 Copy_U8Data)
{
	TWT_VidStartCondition();
	/*shift right by 8 cause a0 and a1 is in the most of byte address*/
	TWT_VidSlaveAddAddress(UNIQUE_ADDRESS | (A2<<2) | (Copy_U16ByteAddress>>8));

	TWT_VidMasterSendData((u8)Copy_U16ByteAddress);
	TWT_VidStartCondition();
	TWT_VidMasterSendData(Copy_U8Data);

	TWT_VidStopCondition();
	_delay_ms(10);



}



u8 EEPROM_VidReadByte(u16 Copy_U16ByteAddress)
{
	u8 Local_u8Data;

	    TWT_VidStartCondition();
		/*shift right by 8 cause a0 and a1 is in the most of byte address*/
		TWT_VidSlaveAddAddress(UNIQUE_ADDRESS | (A2<<2) | (Copy_U16ByteAddress>>8));

		TWT_VidMasterSendData((u8)Copy_U16ByteAddress);
		TWT_VidStartCondition();
		TWT_VidSlaveAddRead(UNIQUE_ADDRESS | (A2<<2) | (Copy_U16ByteAddress>>8));


		Local_u8Data=TWT_VidMasterReadData();

		TWT_VidStopCondition();

		return Local_u8Data;


}



